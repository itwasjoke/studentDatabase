#include "createFun.h"
#include "structures.h"
#include "genFunctions.h"
#include <iostream>
using namespace std;
Student* createStudentList() {
	Student* firstStudent = nullptr;
	Student* currentStudent = nullptr;
	Student* prevStudent = nullptr;

	char currentName[SIZE_NAME];
	int currentGrant;
	cout << "\nAdd the students\n";
	while (true) {
		cout << "\nName: ";
		cin >> currentName;
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


}