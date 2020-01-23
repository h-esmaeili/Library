#include <iostream>
#include <fstream>
#define MAXSIZE 1000

using namespace std;

struct book {
	int shabak;
	char name[50];
	char writer[30];
	int	 year;
	int count;
};

struct member {
	char firstName[30];
	char lastName[50];
	int number;
	char nationalCode[10];
};

struct lendBook {
	int shabak;
	int number;
	char date[10];
};

void manageBook();
void manageMembers();
void lendBook();

int main()
{
	cout << "step1: **************************start program**************************" << endl;
	int step;
	while (true)
	{
		cout << "step2: *******************************MENU******************************" << endl;

		cout << "\t\t1: manage books" << endl;
		cout << "\t\t2: members" << endl;
		cout << "\t\t3: lend book" << endl;
		cout << "\t\t4 to exit" << endl;
		cout << "step3: **************************select a item**************************" << endl;
		cout << "\t\tplease enter a number: ";

		cin >> step;
		switch (step)
		{
		case 1:
			manageBook();
			break;
		case 2:
			manageMembers();
			break;
		case 3:
			lendBook();
			break;
		case 4:
			exit(1);
		default:
			break;
		}
	}
}

void manageBook() {

}

void manageMembers() {

}

void lendBook() {

}