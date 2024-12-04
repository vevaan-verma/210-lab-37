// COMSC-210 | Lab 37, 38 | Vevaan Verma
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>

/* FUNCTION PROTOTYPES */
int getMenuChoice();
int gen_hash_index(string s);
int getValidatedChoice(int min, int max);

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

	map<int, list<string>> hashTable;

	while (!fin.eof()) { // while not at end of file

		string input;
		fin >> input; // read string from file

		int hashIndex = gen_hash_index(input); // generate hash index for string
		hashTable[hashIndex].push_front(input); // add string to hash table

	}

	int choice = getMenuChoice();

	while (choice != 6) { // while choice is not to exit

		string key; // create string to store key
		auto itEnd = hashTable.begin(); // create iterator to store end of hash table here due to the switch statement
		int hashIndex; // create variable to store hash index here due to the switch statement

		switch (choice) { // switch on choice

		case 1: // print first 100 entries

			advance(itEnd, 100); // advance iterator 100 elements

			for (auto it = hashTable.begin(); it != itEnd; it++) {

				cout << it->first << ": ";

				// output all elements in bucket
				for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
					cout << *it2 << " ";

				cout << endl; // output multiple blank lines for formatting purposes

			}

			cout << endl; // output blank line for formatting purposes
			break;

		case 2: // add key

			cout << "Enter the key to add: "; // prompt user to enter key
			cin >> key; // read key from user

			hashIndex = gen_hash_index(key); // generate hash index for key
			hashTable[hashIndex].push_front(key); // add key to hash table

			cout << "Key added." << endl << endl; // output success message
			break;

		case 3: // remove key

			cout << "Enter the key to remove: "; // prompt user to enter key
			cin >> key; // read key from user

			hashIndex = gen_hash_index(key); // generate hash index for key

			// this can be used to give user feedback if the key is not found
			if (hashTable[hashIndex].empty()) { // if key is not found

				cout << "Key not found." << endl; // output message
				cout << endl; // output blank line for formatting purposes
				break;

			}

			hashTable[hashIndex].remove(key); // remove key from hash table
			cout << "Key removed." << endl << endl; // output success message
			break;

		case 4: // search key

			cout << "Enter the key to search: "; // prompt user to enter key
			cin >> key; // read key from user

			hashIndex = gen_hash_index(key); // generate hash index for key

			// this can be used to give user feedback if the key is not found
			if (hashTable[hashIndex].empty()) { // if key is not found

				cout << "Key not found." << endl; // output message
				cout << endl; // output blank line for formatting purposes
				break;

			}

			cout << "Key found." << endl << endl; // output success message
			break;

		case 5: // modify key

			cout << "Enter the key to modify: "; // prompt user to enter key
			cin >> key; // read key from user

			hashIndex = gen_hash_index(key); // generate hash index for key

			// this can be used to give user feedback if the key is not found
			if (hashTable[hashIndex].empty()) { // if key is not found

				cout << "Key not found." << endl; // output message
				cout << endl; // output blank line for formatting purposes
				break;

			}

			cout << "Enter the new key: "; // prompt user to enter new key
			string newKey; // create string to store new key
			cin >> newKey; // read new key from user

			hashTable[hashIndex].remove(key); // remove old key from hash table

			hashIndex = gen_hash_index(newKey); // generate hash index for new key
			hashTable[hashIndex].push_front(newKey); // add new key to hash table

			cout << "Key modified." << endl << endl; // output success message
			break;

		}

		choice = getMenuChoice(); // get new choice from user
		cout << endl; // output blank line for formatting purposes

	}

	fin.close(); // close file
	return 0;

}

// getMenuChoice() displays the menu and gets the user's choice
// arguments: none
// returns: int - the user's choice
int getMenuChoice() {

	cout << "Menu:" << endl;
	cout << "1. Print first 100 entries" << endl;
	cout << "2. Add key" << endl;
	cout << "3. Remove key" << endl;
	cout << "4. Search for key" << endl;
	cout << "5. Modify key" << endl;
	cout << "6. Exit" << endl;

	cout << "Enter your choice: ";
	return getValidatedChoice(1, 6);

}

// gen_hash_index() generates a hash index for a given string
// arguments: string s - the string to generate a hash index for
// returns: int - the hash index of the string
int gen_hash_index(string s) {

	int asciiSum = 0;

	for (int i = 0; i < s.length(); i++)
		asciiSum += s[i]; // add ASCII value of character to asciiSum

	return asciiSum % 200371; // apply hash function to asciiSum (200,371 is a prime number which is larger than double the input size to optimize speed)

}

// getValidatedChoice() gets a validated integer choice from the user (between min and max inclusive)
// arguments: int min - the minimum value, int max - the maximum value
// returns: int - the validated integer choice
int getValidatedChoice(int min, int max) {

	int inputInt; // variable to store the input (of type int)

	while (!(cin >> inputInt) || inputInt < min || inputInt > max) { // while the input is not an integer or is not between the min and max

		cin.clear(); // clear the input stream
		cin.ignore(INT_MAX, '\n'); // ignore the invalid input
		cout << "Invalid input. Please enter a valid integer: "; // prompt the user to enter an integer

	}

	return inputInt;

}