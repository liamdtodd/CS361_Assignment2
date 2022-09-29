/*******************************
 * Liam Todd
 * CS 361 - Assignment 2
 * This code file will read from a text file and generate a random number that will be written to a seperate text file
 * *****************************/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstring>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace this_thread;

int main() {
	sleep_for(seconds(3));

	srand(time(NULL));

	fstream readfile;
	fstream writefile;
	int rand_num;

	if (readfile.is_open())
		readfile.close();

	readfile.open("prng-service.txt", ios::in);
	string ident = "run";
	string text;				

	getline(readfile, text);		//reading from prng-service.txt

	if (text == ident) 
		rand_num = rand() % 100 + 1;
	readfile.close();			//random number from 1-100
	
	readfile.open("prng-service.txt", ios::out | ios::trunc);
	readfile.close();			//deleting 'run' from prng-service.txt

	sleep_for(seconds(3));

	if (writefile.is_open())
		writefile.close();

	writefile.open("prng-service.txt", ios::out);
	writefile << rand_num << endl;
	writefile.close();
	
	
	return 0;
}
