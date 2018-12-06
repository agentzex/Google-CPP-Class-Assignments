#include <string>
#include <iostream>
#include <map> 


using namespace std;


void decode(string obfscuated) {
	map <char, string> months = { {'A', "JAN"}, {'B', "FEB"}, {'C', "MARCH"}, {'D', "APR"}, {'E', "MAY"}, {'F', "JUNE"}, {'G', "JULY"}, {'H', "AUG"}, {'I', "SEP"}, {'J', "OCT"}, {'K', "NOV"}, {'L', "DEC"} };
	map <char, int> days;
	char dayAsChar = 'Q';
	for (int i = 0; i < 10; i++) {
		days[static_cast<char>(dayAsChar + i)] = i;
	}

	map <char, int> years;
	char yearAsChar = 'A';
	for (int i = 0, j = 1; i < 26; i++, j++) {
		years[static_cast<char>(yearAsChar + i)] = j;
	}

	char objMonth = obfscuated[0];
	char objDayDigitOne = obfscuated[1];
	char objDayDigitTwo = obfscuated[2];
	char objYear = obfscuated[3];

	cout << "The expiration date is: " << months[objMonth] << " " << days[objDayDigitOne] << days[objDayDigitTwo] << " " << 1995 + years[objYear] << endl;
}


int main()
{
	decode("ARZM");
}

