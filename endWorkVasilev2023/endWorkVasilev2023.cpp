#include <iostream>
using namespace std;
#include "globals.h"
#include "structures.h"
#include "genFunctions.h"
#include "findFun.h"
#include "createFun.h"
#include "editFun.h"
#include "deleteFun.h"
#include <string> 
Group* createDatabase() {
	Group* firstGroup = nullptr;
	Group* currentGroup = nullptr;
	Group* prevGroup = nullptr;

	int currentNumber = -1;

	cout << "\n Create database\n\n";
	while (true) {
		cout << " Create new group\n Enter the number: ";
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
		currentGroup->first_student = createStudentList(firstGroup,currentNumber);
		currentGroup->next_group = nullptr;
		prevGroup = currentGroup;
		clearConcole();

	}
	clearConcole();
	return firstGroup;
}


Group* ExtraMenu(Group* firstGroup, short int actionType) {
	clearConcole();
	Group* firstG = firstGroup;
	string info[3] = { "add new","edit", "delete" };
	cout << "\n 1 - " << info[actionType] << " group\n 2 - " << info[actionType] << " student\n ";

	short int currentAction = -1;
	int number;
	char name[SIZE_NAME];
	cin >> currentAction;
	clearConcole();
	printDatabase(firstG);
	cout << "\n\n Enter the number of the group: ";
	cin >> number;
	if (!groupExist(firstGroup, number) && currentAction!=1) {
		clearConcole();
		cout << "\n Error\n The group does not exist\n ";
		pause();
		return firstG;
	}
	if (currentAction == 2) {
		cout << "\n Enter the name of the student: ";
		memset(name, 0, SIZE_NAME);
		cin.ignore();
		cin.getline(name, SIZE_NAME);
	}
	else if (currentAction != 1) {
		return firstG;
	}
	currentAction += actionType * 2;
	switch (currentAction) {
	case 1:
		firstG = createGroup(firstG, number);
		break;
	case 2:
		createStudent(firstG, number, name);
		break;
	case 3:
		editGroup(firstG, number);
		break;
	case 4:
		editStudent(firstG, number, name);
		break;
	case 5:
		firstG = deleteGroup(firstG, number);
		break;
	case 6:
		deleteStudent(firstG, number, name);
		break;
	default:
		showError();
		break;
	}
	return firstG;
}


void Menu(Group* firstGroup) {
	int action = -1;
	Group* currentGroups = firstGroup;
	bool haveData;
	while (action != 0) {
		haveData = true;
		if (currentGroups == nullptr) {
			haveData = false;
			cout << "  Coursework / Andrey Vasilev / ETU University / 2023 \n  This is a database of stream students. Select an action.\n";
			cout << "\n  Actions\n\n 1 - enter the database\n 2 - file of database\n ";
		}
		else {
			printDatabase(currentGroups);
			cout << "\n  Actions\n\n 1 - enter the database\n 2 - file of database\n 3 - print the database\n 4 - download database to file\n 5 - add new data to database\n 6 - edit info in database\n 7 - delete data from database\n 8 - delete database\n 9 - show statistics\n 0 - exit\n ";
		}
		cin >> action;
		clearConcole();
		bool b = true;
		if (haveData) {
			switch (action) {
			case 0:
				currentGroups = deleteDatabase(currentGroups);
				return;
				break;
			case 1:
				currentGroups = deleteDatabase(currentGroups);
				currentGroups = createDatabase();
				b = false;
				break;
			case 2:
				currentGroups = getDatabaseFromFile();
				b = false;
				break;
			case 3:
				printDatabase(currentGroups);
				break;
			case 4:
				saveDatabaseToFile(currentGroups);
				break;
			case 5:
				currentGroups = ExtraMenu(currentGroups, 0);
				b = false;
				break;
			case 6:
				currentGroups = ExtraMenu(currentGroups, 1);
				b = false;
				break;
			case 7:
				currentGroups = ExtraMenu(currentGroups, 2);
				b = false;
				break;
			case 8:
				currentGroups = deleteDatabase(currentGroups);
				break;
			case 9:
				showStatistics(currentGroups);
				break;
			default:
				showError();
				break;
			}
		}
		else {
			switch (action) {
			case 1:
				currentGroups = createDatabase();
				b = false;
				break;
			case 2:
				currentGroups = getDatabaseFromFile();
				b = false;
				break;
			default:
				showError();
				break;
			}
		}
		if (b) pause();
		clearConcole();
	}
	currentGroups = deleteDatabase(currentGroups);
}

int main() {
	Group* firstGroup = nullptr;
	Menu(firstGroup);

}
