/***************************
 * Liam Todd
 * CS 361 - Assignment 2
 * This code file will read a random number from image-service.txt and use that random number to access the associated image
 * *************************/

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

int main() {
	sleep_for(seconds(6));

	int rand_num;
	string rand;
	fstream readfile;
	fstream writefile;

	//read from image-service.txt for random number
	if (readfile.is_open())
		readfile.close();

	readfile.open("image-service.txt", ios::in);
	getline(readfile, rand);
	rand_num = string_to_int(rand);
	readfile.close();
	cout << rand_num << endl;

	if (rand_num > 5) 
		rand_num = rand_num % 5;

	writefile.open("image-service.txt", ios::out | ios::trunc);
	writefile.close();

	writefile.open("image-service.txt", ios::out);

	for (int x = 0; x < 5; x++) {
		if (x == rand_num) 
			writefile << "./images/image" << rand_num << ".jpg" << endl;
	}
	
	writefile.close();
	//implement using rand_num to display associated image 

	
	
	return 0;
}
