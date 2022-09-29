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

int main() {
	sleep_for(seconds(10));

	int rand_num;
	fstream readfile;

	//read from image-service.txt for random number
	if (readfile.is_open())
		readfile.close();

	readfile.open("image-service.txt", ios::in);
	readfile >> rand_num;

	if (rand_num > 5) 
		rand_num = rand_num % 5;

	//implement using rand_num to display associated image 
	
	return 0;
}
