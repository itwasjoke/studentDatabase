#include <iostream>
using namespace std;
#include "globals.h"
#include "structures.h"
#include "genFunctions.h"
#include "findFun.h"
#include "createFun.h"
#include "editFun.h"
#include "deleteFun.h"


Group* createDatabase() {
	Group* firstGroup = nullptr;
	Group* currentGroup = nullptr;
	Group* prevGroup = nullptr;

	int currentNumber = -1;

	cout << "Create database\n\n";
	while (true) {
		cout << "Create new group\nEnter the number: ";
		cin >> currentNumber;
		if (currentNumber == 0) {
			break;
		}
		currentGroup = new Group;
		if (firstGroup == nullptr) {
			firstGroup = currentGroup;
		}
		else {
			currentGroup->prev_group = prevGroup;
			prevGroup->next_group = currentGroup;
		}
		currentGroup->number = currentNumber;
		currentGroup->first_student = createStudentList();
		currentGroup->next_group = nullptr;
		prevGroup = currentGroup;
		clearConcole();

	}
	clearConcole();
	return firstGroup;
}

Group* deleteDatabase(Group* firstGroup) {
	return nullptr;
}

Group* ExtraMenu(Group* firstGroup, short int actionType) {
	clearConcole();
	Group* firstG = firstGroup;
	string info[3] = { "add new","edit", "delete" };
	cout << "1 - " << info[actionType] << " group\n2 - " << info[actionType] << " student\n";

	short int currentAction = -1;
	int number;
	char name[50];
	cin >> currentAction;
	clearConcole();
	cout << "Enter the number of the group: ";
	cin >> number;
	if (currentAction == 2) {
		cout << "Enter the name of the student: ";
		cin >> name;
	}
	else if (currentAction != 1) {
		return firstGroup;
	}
	currentAction += actionType * 2;
	switch (currentAction) {
	case 1:
		firstG = createGroup(firstGroup, number);
		break;
	case 2:
		createStudent(firstGroup, number, name);
		break;
	case 3:
		editGroup(firstGroup, number);
		break;
	case 4:
		editStudent(firstGroup, number, name);
		break;
	case 5:
		firstG = deleteGroup(firstGroup, number);
		break;
	case 6:
		break;
	default:
		showError();
		break;
	}
	return firstG;
}

void mainMenu(Group* firstGroup) {
	int action = -1;
	Group* currentGroups = firstGroup;
	bool haveData;
	while (action != 0) {
		haveData = true;
		if (currentGroups == nullptr) {
			haveData = false;
			cout << "1 - enter the database\n2 - file of database\n";
		}
		else {
			cout << "1 - enter the database\n2 - file of database\n3 - print the database\n4 - download database to file\n5 - add new data to database\n6 - edit info in database\n7 - delete data from database\n";
		}
		cin >> action;
		clearConcole();
		if (haveData) {
			switch (action) {
			case 1:
				currentGroups = deleteDatabase(currentGroups);
				currentGroups = createDatabase();
				printDatabase(currentGroups);
				break;
			case 2:
				break;
			case 3:
				printDatabase(currentGroups);
				break;
			case 4:
				break;
			case 5:
				currentGroups = ExtraMenu(currentGroups, 0);
				break;
			case 6:
				currentGroups = ExtraMenu(currentGroups, 1);
				break;
			case 7:
				currentGroups = ExtraMenu(currentGroups, 2);
			default:
				showError();
				break;
			}
		}
		else {
			switch (action) {
			case 1:
				currentGroups = createDatabase();
				printDatabase(currentGroups);
				break;
			case 2:
				break;
			default:
				showError();
				break;
			}
		}
		pause();
		clearConcole();
	}
}

int main() {
	Group* firstGroup = nullptr;
	mainMenu(firstGroup);
}
