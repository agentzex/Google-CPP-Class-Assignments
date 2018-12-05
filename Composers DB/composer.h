// composer.h, Maggie Johnson
// Description: The class for a Composer record.
// The default ranking is 10 which is the lowest possible.
// Notice we use const in C++ instead of #define.
#pragma once
#include <iostream>
#include <string>

using namespace std;

const int kDefaultRanking = 10;

class Composer {
public:
	// Constructor
	Composer();
	Composer(string in_first_name, string in_last_name, string in_genre, int in_yob, string in_fact);
	// Here is the destructor which has the same name as the class
	// and is preceded by ~. It is called when an object is destroyed
	// either by deletion, or when the object is on the stack and
	// the method ends.
	~Composer();

	// Accessors and Mutators
	static int total_composers;

	void set_first_name(string in_first_name);
	string get_first_name();
	void set_last_name(string in_last_name);
	string get_last_name();
	void set_composer_yob(int in_composer_yob);
	int get_composer_yob();
	void set_composer_genre(string in_composer_genre);
	string get_composer_genre();
	void set_ranking(int in_ranking);
	int get_ranking();
	void set_fact(string in_fact);
	string get_fact();

	// Methods
	// This method increases a composer's rank by increment.
	void Promote(int increment);
	// This method decreases a composer's rank by decrement.
	void Demote(int decrement);
	// This method displays all the attributes of a composer.
	void Display();

private:

	string first_name;
	string last_name;
	int composer_yob; // year of birth
	string composer_genre; // baroque, classical, romantic, etc.
	string fact;
	int ranking;
};

