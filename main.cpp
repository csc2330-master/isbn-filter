#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

/**
 * Things we have learned so far
 *
 */

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::stringstream;

bool IsValidISBN(const string& isbn);
string GetISBN(const string& text);
int main() {
	ifstream isbnFile("../data/isbn_mixed_list.txt");
	if (!isbnFile.is_open()) {
		cerr << "COULD NOT OPEN Input File... DUH" << endl;
		return 1;
	}
	ofstream validIsbn("../data/valid_isbn.txt");
	if (!validIsbn.is_open()) {
		cerr << "COULD NOT OPEN Output File... DUH" << endl;
		return 1;
	}

	string str, isbn;
	while (getline(isbnFile,str)) {
		//isbn = str.substr(0, 13);
		//str.find() -- see Teams for code about parsing with find and substr
		isbn = GetISBN(str);
		if (IsValidISBN(isbn)) {
			// cout << "ISBN " << isbn << " is valid" << endl;
			validIsbn << str << endl;
		}else {
			// cout << "ISBN " << isbn << " is NOT valid" << endl;
		}

	}


	return 0;
}

bool IsValidISBN(const string& isbn) {
	if (isbn.length() != 13)
		return false;
	int currentDigit;
	int sum = 0;
	for (int i=0; i<isbn.length()-1; i++) {
		currentDigit = isbn.at(i) - 48;
		if (i % 2 == 0) {
			sum += currentDigit * 1;
		}else {
			sum += currentDigit * 3;
		}
	}
	int r = sum % 10;
	if (r == 0 && isbn.at(12) == '0')
		return true;
	int a = isbn.at(12);
	if (10 - (isbn.at(12) - 48) == r)
		return true;
	return false;
}

string GetISBN(const string& text) {
	stringstream ss(text);
	string retVal;
	getline(ss, retVal, ';');
	return retVal;
}

