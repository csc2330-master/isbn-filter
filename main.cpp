#include <iostream>
#include <string>
#include <fstream>

/**
 * Things we have learned so far
 *
 */

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;

bool IsValidISBN(const string& isbn);

int main() {
	ifstream isbnFile("../data/isbn_mixed_list.txt");
	if (!isbnFile.is_open()) {
		cerr << "COULD NOT OPEN... DUH" << endl;
		return 1;
	}
	string str, isbn;
	while (getline(isbnFile,str)) {
		isbn = str.substr(0, 13);
		if (IsValidISBN(isbn)) {
			cout << "ISBN " << isbn << " is valid" << endl;
		}else {
			cout << "ISBN " << isbn << " is NOT valid" << endl;
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


