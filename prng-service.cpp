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

using namespace std;

int main() {
	srand(time(NULL));

	fstream readfile;
	fstream writefile;
	int rand_num;

	if (readfile.is_open())
		readfile.close();

	readfile.open("prng-service.txt", ios::in);
	string ident = "run";
	string text;

	getline(readfile, text);

	if (text == ident) 
		rand_num = rand() % 5 + 1;
	readfile.close();
	
	readfile.open("prng-service.txt", ios::out | ios::trunc);
	readfile.close();

	if (writefile.is_open())
		writefile.close();

	writefile.open("image-service.txt", ios::out);
	writefile << rand_num << endl;
	writefile.close();
	
	
	return 0;
}
