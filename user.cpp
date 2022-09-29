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

int main () {
	int ans, rand_num;
	fstream file;
	
	cout << "Would you like to start the microservice? 1-yes, 0-no" << endl;
	cin >> ans;

	if (ans == 1) {
	//implement writing to prng-service.txt file the word 'run'
		if (file.is_open())
			file.close();
		file.open("prng-service.txt", ios::out);
		file << "run" << endl;
	}
	file.close();

	sleep_for(seconds(5));

	file.open("prng-service.txt", ios::in);
	file >> rand_num;
	file.close();

	sleep_for(seconds(5));

	file.open("image-service.txt", ios::out);
	file << rand_num << endl;
	file.close();

	return 0;
}
