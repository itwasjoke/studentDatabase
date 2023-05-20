#include "genFunctions.h"
#include <iostream>
#include "globals.h"
#include "structures.h"
#include "deleteFun.h"
#include "createFun.h"
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
	int count = 0;
	int maxSizeName = 0;
	clearConcole();
	if (firstG == nullptr) {
		cout << "Database is null\n";
		return;
	}
	cout << "\n  Database\n\n";
	for (Group* i = firstG; i != nullptr; i = i->next_group) {
		if (i->first_student == nullptr) {
			continue;
		}
		for (Student* j = i->first_student; j != nullptr; j = j->next_student) {
			int sizeName = 0;
			for (auto U : j->name) {
				if (U) sizeName++;
			}
			sizeName = sizeName;
			sizeName = sizeName / 8;
			if (maxSizeName == 0 || maxSizeName < sizeName) maxSizeName = sizeName;
		}
	}
	maxSizeName += 2;
	cout << " #" << "\tGroup\tName";
	for (int i = 0; i < maxSizeName-1;i++) {
		cout << "\t";
	}
	cout << "Grant\t Marks\n";
	for (Group* i = firstG; i != nullptr; i = i->next_group) {
		if (i->first_student == nullptr) {
			count++;
			cout <<" " << count << "\t" << i->number;
			continue;
		}
		for (Student* j = i->first_student; j != nullptr; j = j->next_student) {
			count++;
			int sizeName = 0;
			for (auto i : j->name) {
				if (i) sizeName++;
			}
			sizeName = sizeName;
			sizeName /= 8;
			sizeName = maxSizeName - sizeName-1;
			cout <<" " << count << "\t" << i->number << "\t" << j->name;
			for (int k = 0; k < sizeName; k++) {
				cout << "\t";
			}
			cout << j->grant << "\t";

			for (int k = 0; k < COUNT_MARKS; k++) {
				cout << " " << j->marks[k];
			}
			cout << "\n";
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