#include "createFun.h"
#include "structures.h"
#include "genFunctions.h"
#include "findFun.h"
#include <iostream>
#include<fstream>
#include "string"
using namespace std;
Student* createStudentList() {
	Student* firstStudent = nullptr;
	Student* currentStudent = nullptr;
	Student* prevStudent = nullptr;

	char currentName[SIZE_NAME];
	int currentGrant=0;
	cout << "\nAdd the students\n";
	while (true) {
		cout << "\nName: ";
		cin.ignore();
		cin.getline(currentName, SIZE_NAME);
		if (currentName[0] == '0') {
			break;
		}
		cout << "Grant: ";
		cin >> currentGrant;

		currentStudent = new Student;
		if (firstStudent == nullptr) {
			firstStudent = currentStudent;
			firstStudent->prev_student = nullptr;
		}
		else {
			currentStudent->prev_student = prevStudent;
			prevStudent->next_student = currentStudent;
		}
		cout << "Add five marks: ";
		for (int i = 0; i < COUNT_MARKS; i++) {
			cin >> currentStudent->marks[i];
		}
		for (int i = 0; i < SIZE_NAME; i++) {
			currentStudent->name[i] = currentName[i];
		}
		currentStudent->grant = currentGrant;
		currentStudent->next_student = nullptr;
		prevStudent = currentStudent;
	}

	return firstStudent;
}
Group* createGroup(Group* firstGroup, int numberGroup) {
	Group* firstG = firstGroup;
	if (firstG == nullptr) {
		showError();
		return nullptr;
	}
	Group* newGroup = new Group;
	newGroup->number = numberGroup;
	newGroup->prev_group = nullptr;
	newGroup->next_group = firstG;
	firstG->prev_group = newGroup;
	newGroup->first_student = createStudentList();
	printDatabase(newGroup);
	return newGroup;
}

void createStudent(Group* firstGroup, int numberGroup, char nameStudent[50]) {
	int grant;
	Student* currentStudent = new Student;
	cout << "Grant: ";
	cin >> grant;
	cout << "Add five marks: ";
	for (int i = 0; i < COUNT_MARKS; i++) {
		cin >> currentStudent->marks[i];
	}
	for (int i = 0; i < SIZE_NAME; i++) {
		currentStudent->name[i] = nameStudent[i];
	}
	currentStudent->grant = grant;

	Group* groupStud = findGroup(firstGroup, numberGroup);
	Student* firstStudent = groupStud->first_student;
	firstStudent->prev_student = currentStudent;
	currentStudent->next_student = firstStudent;
	groupStud->first_student = currentStudent;

	printDatabase(firstGroup);
}
Group* getDatabaseFromFile() {
	Group* firstGroup=nullptr;
	Group* prevGroup = nullptr;
	Group* currentGroup = nullptr;
	Student* prevStudent = nullptr;
	Student* currentStudent = nullptr;
	ifstream db("databaseSave.txt");
	char name[SIZE_NAME];
	string element;
	int number;
	int grant;
	int marks[5];
	bool b=true;
	while (db) {
		getline(db, element);
		char* elem = new char[element.length() + 1];
		strcpy_s(elem, element.length() + 1, element.c_str());
		int firstLetter = elem[0] - 48;
		b = firstLetter >= 0 && firstLetter <= 9;
		if (b) {
			currentGroup = new Group;
			currentGroup->first_student = nullptr;
			currentGroup->number = atoi(elem);
			if (firstGroup == nullptr) firstGroup = currentGroup;
			if (prevGroup == nullptr) {
				prevGroup = currentGroup;
			}
			else {
				prevGroup->next_group = currentGroup;
				currentGroup->prev_group = prevGroup;
				prevGroup = currentGroup;
			}
			//cout << currentGroup->number << "\n";
		}
		else{
			currentStudent = new Student;
			for (int i = 0; i < element.length(); i++) {
				currentStudent->name[i] = elem[i];
			}
			getline(db, element);
			currentStudent->grant = stoi(element);
			getline(db, element);
			for (int i = 0; i < COUNT_MARKS; i++) {
				currentStudent->marks[i] = element[i * 2]-48;
			}
			if (currentGroup->first_student == nullptr) {
				currentGroup->first_student = currentStudent;
			}
			else {
				prevStudent->next_student = currentStudent;
				currentStudent->prev_student = prevStudent;
			}
			prevStudent = currentStudent;
		}
		delete[] elem;
	}
	db.close();
	printDatabase(firstGroup);
	return firstGroup;
}