/*******************************
 * Liam Todd
 * CS 361 - Assignment 2
 * This code file will read from a text file and generate a random number that will be written to a seperate text file
 * *****************************/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	//read 'run' from prng-service.txt

	srand(time(NULL));
	
	int rand_num = rand() % 5 + 1;
	
	//write rand_num to image-service.txt

	return 0;
}
