/**************************
 * Liam Todd
 * CS 361 - Assignment2
 * This code file is the user interface for the microservice, will prompt the user, and write to prng-service.txt
 * ***********************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace this_thread;

int string_to_int(string text) {
	int num, temp;
	char letter;
	num = 0;	

	for (int x = 0; x < text.length(); x++) {
		letter = text[x];
		temp = letter - 48;
		if (x == 0) 
			num += temp;
		else {
			num *= 10;
			num += temp;
		}
	}
	return num;
}	

int main () {
	int ans, rand_num;
	string rand, path;
	ifstream readfile;
	ofstream writefile;
	ofstream writefile2;	

	cout << "Would you like to start the microservice? 1-yes, 0-no" << endl;
	cin >> ans;

	if (ans == 1) {
	//implement writing to prng-service.txt file the word 'run'
		if (writefile.is_open())
			writefile.close();
		writefile.open("prng-service.txt", ios::out);
		writefile << "run" << endl;
	}
	writefile.close();

	sleep_for(seconds(10));

	readfile.open("prng-service.txt", ios::in);
	getline(readfile, rand);
	rand_num = string_to_int(rand);
	readfile.close();

	//sleep_for(seconds(5));

	writefile2.open("image-service.txt", ios::out);
	writefile2 << rand_num << endl;
	writefile2.close();

	sleep_for(seconds(10));
	readfile.open("image-service.txt", ios::in);
	getline(readfile, path);
	readfile.close();

	cout << path << endl;

	return 0;
}
