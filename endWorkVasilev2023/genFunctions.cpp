#include "genFunctions.h"
#include <iostream>
#include "globals.h"
#include "structures.h"
#include "deleteFun.h"
#include "createFun.h"
#include "string"
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
	cout << "\n Error in the program";
}
void printDatabase(Group* firstG) {
	int count = 0;
	int maxSizeName = 0;
	clearConcole();
	cout << "  Coursework / Andrey Vasilev / ETU University / 2023 \n  This is a database of stream students\n";
	if (firstG == nullptr) {
		cout << "\n Database is null\n";
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


void showStatistics(Group* firstGroup) {
	int checksum = 0;
	int countE = 0;
	for (Group* i = firstGroup; i != nullptr; i = i->next_group) {
		if (i->first_student == nullptr) break;
		for (Student* j = i->first_student; j != nullptr; j = j->next_student) {
			checksum = 0;
			for (int k = 0; k < COUNT_MARKS; k++) {
				checksum += j->marks[k];
			}
			if (checksum == 25) {
				countE++;
			}
		}
	}
	if (countE == 0) {
		cout << "\n No honors students in the database.\n ";
		return;
	}
	printDatabase(firstGroup);
	char** excellentSt = new char* [countE];
	char currentSt[SIZE_NAME];
	countE = 0;
	char letters[SIZE_NAME];
	memset(letters, 0, 50);
	cout << "\n Enter the letters that begin with the last names of the honors students: ";
	cin.ignore();
	cin.getline(letters, SIZE_NAME);
	clearConcole();
	cout << "\n List of honors students whose last names begin with \"" << letters << "\"\n\n";
	for (Group* i = firstGroup; i != nullptr; i = i->next_group) {
		for (Student* j = i->first_student; j != nullptr; j = j->next_student) {
			checksum = 0;
			for (int k = 0; k < COUNT_MARKS; k++) {
				checksum += j->marks[k];
			}
			if (checksum == 25) {
				char* next = NULL;
				strcpy_s(currentSt, strlen(j->name) + 1, j->name);
				char* tok = strtok_s(currentSt, " ", &next);
				bool isName = true;
				if (strlen(letters)<=strlen(next)){
					for (int k = 0; k < strlen(letters); k++) {
						if (next[k] != letters[k]) {
							isName = false;
							break;
						}
					}
				}
				if (!isName) continue;
				excellentSt[countE] = new char[strlen(next) + 1];
				strcpy_s(excellentSt[countE], strlen(next) + 1, next);
				countE++;
			}
		}
	}
	if (countE == 0) {
		clearConcole();
		cout << "\n No students were found with this combination of letters.\n ";
		return;
	}
	for (int i = 0; i < countE - 1; i++) {
		for (int j = i + 1; j < countE; j++) {
			if (strcmp(excellentSt[i], excellentSt[j]) > 0)
			{
				strcpy_s(currentSt, strlen(excellentSt[i])+1, excellentSt[i]);
				strcpy_s(excellentSt[i], strlen(excellentSt[j])+1, excellentSt[j]);
				strcpy_s(excellentSt[j], strlen(currentSt)+1, currentSt);
			}
		}
	}
	for (int i = 0; i < countE; ++i)
	{
		cout << " " << i+1 << "\t" << excellentSt[i] << endl;
		delete excellentSt[i];
	}
	delete[] excellentSt;
}