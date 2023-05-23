#include "editFun.h"
#include "genFunctions.h"
#include "findFun.h"
#include "globals.h"
#include <iostream>
using namespace std;
void editGroup(Group* firstGroup, int numberGroup) {
	int newNumber;
	Group* editedGroup = findGroup(firstGroup, numberGroup);
	if (editedGroup == nullptr) {
		cout << "\n Group did not found.\n ";
		return;
	}
	cout << "\n Enter the new number of group: ";
	cin >> newNumber;
	editedGroup->number = newNumber;
}
void printDataAboutStudent(Student* student) {
	cout << "\n Name: " << student->name << "\n Grant: " << student->grant << "\n Marks: ";
	for (int i = 0; i < COUNT_MARKS; i++) cout << student->marks[i] << " ";
	cout << "\n";
}
void editStudent(Group* firstGroup, int numberGroup, char studentName[SIZE_NAME]) {
	clearConcole();
	Student* editedStud = findStudent(firstGroup, numberGroup, studentName);
	if (editedStud == nullptr) {
		cout << "\n Student did not found.\n ";
		return;
	}
	short int action=-1;
	while (true) {
		printDataAboutStudent(editedStud);

		cout << "\n What do you want to edit?\n";
		cout << " 1 - edit name\n 2 - edit grant\n 3 - edit marks\n 0 - exit\n ";
		cin >> action;
		if (action == 0) break;
		clearConcole();
		printDataAboutStudent(editedStud);
		cout << "\n";
		switch (action)
		{
		case 1:
			cout << " Enter new name: ";
			char newName[SIZE_NAME];
			memset(newName, 0, SIZE_NAME);
			cin.ignore();
			cin.getline(newName, SIZE_NAME);
			memset(editedStud->name, 0, SIZE_NAME);
			for (int i = 0; i < SIZE_NAME; i++) editedStud->name[i] = newName[i];
			break;
		case 2:
			cout << " Enter new grant: ";
			int newGrant;
			cin >> newGrant;
			editedStud->grant = newGrant;
			break;
		case 3:
			cout << " Enter new marks: ";
			for (int i = 0; i < COUNT_MARKS; i++) {
				cin >> editedStud->marks[i];
			}
			break;
		default:
			break;
		}
		clearConcole();
	}
	clearConcole();
}