// COMSC-210 | Lab 37 | Vevaan Verma
using namespace std;
#include <iostream>
#include <string>

/* FUNCTION PROTOTYPES */
int sum_ascii(string s);

// main() is the entry point of the program and drives the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	cout << sum_ascii("COMSC-210") << endl;
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
