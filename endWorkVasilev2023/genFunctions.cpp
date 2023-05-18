#include "genFunctions.h"
#include <iostream>
#include "globals.h"
#include "structures.h"
#include<fstream>
using namespace std;
void clearConcole() {
	system("cls");
}
void pause() {
	cin.clear();
	cin.ignore(1024, '\n');
	while (cin.get() != '\n');
}
void showError() {
	cout << "Error in the program";
}
void printDatabase(Group* firstG) {
	clearConcole();
	if (firstG == nullptr) {
		cout << "Database is null\n";
		return;
	}
	cout << "Database\n\n";
	for (Group* i = firstG; i != nullptr; i = i->next_group) {
		cout << "-------\nGroup ¹ " << i->number << "\n\n";
		if (i->first_student == nullptr) {
			cout << "no students in the group\n";
			continue;
		}
		for (Student* j = i->first_student; j != nullptr; j = j->next_student) {
			cout << "Name: " << j->name << "\nGrant: " << j->grant << "\nMarks:";
			for (int k = 0; k < COUNT_MARKS; k++) {
				cout << " " << j->marks[k];
			}
			cout << "\n\n";
		}
	}
}
void saveDatabaseToFile(Group* firstG) {
	ofstream db("databaseSave.txt");
	clearConcole();
	if (firstG == nullptr) {
		cout << "Database is null\n";
		return;
	}
	for (Group* i = firstG; i != nullptr; i = i->next_group) {
		db << i->number << "\n";
		if (i->first_student == nullptr) {
			continue;
		}
		for (Student* j = i->first_student; j != nullptr; j = j->next_student) {
			db << j->name << "\n";
			db << j->grant << "\n";
			for (int k = 0; k < 5; k++) {
				db << j->marks[k] << " ";
			}
			db << "\n";
		}
	}
	db.close();
	cout << "Database saved\n";
}