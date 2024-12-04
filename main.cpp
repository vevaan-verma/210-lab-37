// COMSC-210 | Lab 37 | Vevaan Verma
using namespace std;
#include <iostream>
#include <string>
#include <fstream>

/* FUNCTION PROTOTYPES */
int sum_ascii(string s);

/* CONSTANTS */
const string FILE_NAME = "lab-37-data.txt"; // file name

/* GLOBAL VARIABLES */
ifstream fin;

// main() is the entry point of the program and drives the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	fin.open(FILE_NAME); // open file

	if (!fin) { // if file does not exist

		cout << "Error: File " << FILE_NAME << " not found." << endl; // output error message
		return 1; // return error code

	}

	int asciiSum = 0;

	while (!fin.eof()) { // while not at end of file

		string input;
		fin >> input; // read input from file
		asciiSum += sum_ascii(input); // add sum of ASCII values of input to asciiSum

	}

	cout << asciiSum << endl;

	fin.close(); // close file
	return 0;

}

// sum_ascii() takes a string and returns the sum of the ASCII values of the characters in the string
// arguments: string s - the string to sum the ASCII values of
// returns: int - the sum of the ASCII values of the characters in the string
int sum_ascii(string s) {

	int sum = 0;

	for (int i = 0; i < s.length(); i++)
		sum += (int) s[i];

	return sum;

}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
