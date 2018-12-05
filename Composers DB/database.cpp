#include "pch.h"
#include "database.h"
#include <map>
#include <vector>

using namespace std;

Database::Database()
{
}

Database::~Database()
{
}

shared_ptr<Composer> Database::AddComposer(string in_first_name, string in_last_name, string in_genre, int in_yob, string in_fact)
{
	if (next_slot == 100) {
		cout << "The DB has reached max space!" << endl;
		return nullptr;
	}
	shared_ptr<Composer> newComposer(new Composer(in_first_name, in_last_name, in_genre, in_yob, in_fact));
	composers[next_slot] = newComposer;
	cout << "Composer added successfully at index: " << next_slot << endl;
	next_slot++;
	return newComposer;
}

shared_ptr<Composer> Database::GetComposer(string in_last_name)
{
	for (int i = 0; i < next_slot; i++) {
		if (composers[i]->get_last_name() == in_last_name) {
			cout << "Composer found at index: " << i << endl;
			return composers[i];
		}
	}
}

shared_ptr<Composer> Database::GetComposerByIndex(int index)
{
	return composers[index];
}

void Database::DisplayAll()
{
	for (int i = 0; i < next_slot; i++) {
		cout << "*** Next composer is: *** " << endl;
		composers[i]->Display();
		cout << "***********************************" << endl;
		cout << endl;
	}
}

void Database::DisplayByRank()
{
	map<int, vector<shared_ptr<Composer>>> rank_to_composer;
	for (int i = 0; i < next_slot; i++) {
		int current_ranking = composers[i]->get_ranking();
		rank_to_composer[current_ranking].push_back(composers[i]);
	}

	for (auto& [k, v] : rank_to_composer) {
		for (auto composer : v) {
			cout << "*** Next composer is: *** " << endl;
			composer->Display();
			cout << "***********************************" << endl;
			cout << endl;
		}
	}
}

void Database::GetTotalComposers()
{
	//cout << "Total composers in DB: " << next_slot << endl;
	cout << "Total composers in DB: " << Composer::total_composers << endl;
}

void Database::deleteLastComposer()
{
	next_slot--;
	composers[next_slot] = nullptr;
	Composer::total_composers--;
}
