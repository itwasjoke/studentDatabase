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
void editStudent(Group* firstGroup, int numberGroup, char studentName) {

}