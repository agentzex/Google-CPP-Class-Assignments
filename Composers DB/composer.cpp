#include "pch.h"
#include "composer.h"


int Composer::total_composers = 0;

Composer::Composer() {
	this->ranking = kDefaultRanking;
	this->composer_yob = 0;
	Composer::total_composers++;

}

Composer::Composer(string in_first_name, string in_last_name, string in_genre, int in_yob, string in_fact) {
	this->first_name = in_first_name;
	this->last_name = in_last_name;
	this->composer_yob = in_yob;
	this->composer_genre = in_genre;
	this->fact = in_fact;
	this->ranking = kDefaultRanking;
	Composer::total_composers++;

}


Composer::~Composer() {
	Composer::total_composers--;


}


void Composer::set_first_name(string in_first_name) {
	this->first_name = in_first_name;
}

string Composer::get_first_name()
{
	return this->first_name;
}

void Composer::set_last_name(string in_last_name)
{
	this->last_name = in_last_name;
}

string Composer::get_last_name()
{
	return this->last_name;
}

void Composer::set_composer_yob(int in_composer_yob)
{
	this->composer_yob = in_composer_yob;

}

int Composer::get_composer_yob()
{
	return this->composer_yob;
}

void Composer::set_composer_genre(string in_composer_genre)
{
	this->composer_genre = in_composer_genre;

}

string Composer::get_composer_genre()
{
	return this->composer_genre;
}

void Composer::set_ranking(int in_ranking)
{
	if (in_ranking > 10 || in_ranking < 1) {
		cout << "Ranking must be between 1-10" << endl;
		return;
	}
	this->ranking = in_ranking;
	cout << "Ranking for this composer successfully changed. Current ranking for this composer is: " << this->ranking << endl;
}

int Composer::get_ranking()
{
	return this->ranking;
}

void Composer::set_fact(string in_fact)
{
	this->fact = in_fact;

}

string Composer::get_fact()
{
	return this->fact;
}


void Composer::Promote(int increment)
{
	cout << "Current ranking for " << this->first_name << " " << this->last_name << " is: " << this->ranking << endl;
	int temp = this->ranking - increment;
	if (temp < 1) {
		cout << "The value you asked to increment is beyond what possible (ranking is between 1-10)" << endl;
		return;
	}
	this->ranking -= increment;
	cout << "Ranking for this composer successfully changed. Current ranking for " << this->first_name << " " << this->last_name << " is: " << this->ranking << endl;

}

void Composer::Demote(int decrement)
{
	cout << "Current ranking for " << this->first_name << " " << this->last_name << " is: " << this->ranking << endl;
	int temp = this->ranking + decrement;
	if (temp > 10) {
		cout << "The value you asked to increment is beyond what possible (ranking is between 1-10)" << endl;
		return;
	}
	this->ranking += decrement;
	cout << "Ranking for this composer successfully changed. Current ranking for " << this->first_name << " " << this->last_name << " is: " << this->ranking << endl;

}

void Composer::Display()
{
	cout << "Composer name: " << this->first_name << " " << this->last_name << endl;
	cout << "Composer year of birth: " << this->composer_yob << endl;
	cout << "Composer genere: " << this->composer_genre << endl;
	cout << "Composer fact : " << this->fact << endl;
	cout << "Composer ranking: " << this->ranking << endl;

}
