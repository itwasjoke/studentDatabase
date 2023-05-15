#include "editFun.h"
#include "genFunctions.h"
#include "findFun.h"
#include <iostream>
using namespace std;
void editGroup(Group* firstGroup, int numberGroup) {
	int newNumber;
	Group* editedGroup = findGroup(firstGroup, numberGroup);
	cout << "Enter the new number of group: ";
	cin >> newNumber;
	editedGroup->number = newNumber;
	printDatabase(firstGroup);
}
void printDataAboutStudent(Student* student) {
	cout << "Name: " << student->name << "\nGrant: " << student->grant << "\nMakrs: ";
	for (int i = 0; i < 5; i++) cout << student->marks[i] << " ";
	cout << "\n";
}
void editStudent(Group* firstGroup, int numberGroup, char studentName[50]) {
	clearConcole();
	Student* editedStud = findStudent(firstGroup, numberGroup, studentName);
	short int action=-1;
	while (true) {
		printDataAboutStudent(editedStud);

		cout << "\nWhat do you want to edit?\n";
		cout << "1 - edit name\n2 - edit grant\n3 - edit marks\n0 - exit\n";
		cin >> action;
		if (action == 0) break;
		clearConcole();
		printDataAboutStudent(editedStud);
		cout << "\n";
		switch (action)
		{
		case 1:
			cout << "Enter new name: ";
			char newName[50];
			cin >> newName;
			for (int i = 0; i < 50; i++) editedStud->name[i] = newName[i];
			break;
		case 2:
			cout << "Enter new grant: ";
			int newGrant;
			cin >> newGrant;
			editedStud->grant = newGrant;
			break;
		case 3:
			cout << "Enter new marks: ";
			for (int i = 0; i < 5; i++) {
				cin >> editedStud->marks[i];
			}
			break;
		default:
			break;
		}
		clearConcole();
	}
	clearConcole();
	printDatabase(firstGroup);
}