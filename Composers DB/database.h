// database.h, Maggie Johnson
// Description: Class for a database of Composer records.
#pragma once
#include  <iostream>
#include "composer.h"

// Our database holds 100 composers, and no more.
const int kMaxComposers = 100;

class Database {
public:
	Database();
	~Database();

	// Add a new composer using operations in the Composer class.
	// For convenience, we return a reference (pointer) to the new record.
	shared_ptr<Composer> AddComposer(string in_first_name, string in_last_name, string in_genre, int in_yob, string in_fact);
	// Search for a composer based on last name. Return a reference to the
	// found record.
	shared_ptr<Composer> GetComposer(string in_last_name);
	shared_ptr<Composer> GetComposerByIndex(int index);

	// Display all composers in the database.
	void DisplayAll();
	// Sort database records by rank and then display all.
	void DisplayByRank();
	void GetTotalComposers();
	void deleteLastComposer();

private:
	// Store the individual records in an array.
	shared_ptr<Composer> composers[kMaxComposers];
	// Track the next slot in the array to place a new record.
	int next_slot = 0;
};