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
	int available;
};

struct member {
	char firstName[30];
	char lastName[50];
	int number;
	char nationalCode[10];
};

struct lend {
	int number;
	int shabak;
	char date[11];
	char returnDate[11];
};



void manageBook();
bool existBook(int shabak);
bool existBook(int shabak, char name[50]);
book getBook(int shabak);
book getBook(int shabak, char name[50]);
void getBooks();

void printBook(book book);
void printBookHeader();
void printBooks(book books[1000], int size);
void addBook();
void onEditBook();
void editBook(int shabak, book b);
void editBooks(book books[1000], int size);
void searchBook();
void searchBookByName();
void searchBookByWriter();
void searchBookByShabak();

void manageMembers();
void getMembers();
void addMember();
bool existMember(int number);
void searchMember();
void searchMemberByName();
void searchMemberByNumber();
void searchMemberByNationalCode();

void printMemberHeader();
void printMember(member member);
void printMembers(member members[], int size);

void lendBook();
void returnBook();
bool existLendBook(int number, int shabak);
lend getLendBook(int number, int shabak);
void deleteLendBook(lend lendBook);
int getLendBookCount(int studNumber);

bool equals(char str[], char key[], int size);
int isSubstring(char s1[], char s2[], int size);




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
		cout << "\t\t4: return book" << endl;
		cout << "\t\t5 to exit" << endl;
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
			returnBook();
			break;
		case 5:
			exit(1);
		default:
			break;
		}
	}
}


#pragma region مدیریت کتاب ها

void manageBook() {

	bool back = false;
	do
	{
		int step;
		cout << "step4: ****************************manage books****************************" << endl;
		cout << "\t\t1: list book: " << endl;
		cout << "\t\t2: add book: " << endl;
		cout << "\t\t3: edit book:" << endl;
		cout << "\t\t4: search book: " << endl;
		cout << "\t\t5: back" << endl;
		cout << "step3: **************************select a item**************************" << endl;
		cout << "\t\tplease enter a number: ";
		cin >> step;
		switch (step)
		{
		case 1:
			getBooks();
			break;
		case 2:
			addBook();
			break;
		case 3:
			onEditBook();
			break;
		case 4:
			searchBook();
			break;
		case 5:
			back = true;
			break;
		default:

			break;
		}

	} while (!back);
}

void getBooks() {
	cout << "step4: ****************************list books****************************" << endl;

	ifstream inputFile("Books.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}
	book books[MAXSIZE];
	int count = 0;

	for (int i = 0; i < MAXSIZE; i++)
	{

		inputFile >> books[i].shabak >> books[i].name >> books[i].writer >> books[i].year >> books[i].count >> books[i].available;
		//this method check end of file 
		if (inputFile.eof()) {
			count = i;
			break;
		}
	}
	printBookHeader();
	printBooks(books, count);
}

void printBookHeader() {
	cout << "\t\t" << "shabak" << "\t" << "name" << "\t" << "writer" << "\t" << "year" << "\t" << "count" << "\t" << "available" << endl;
}

void printBook(book book) {
	cout << "\t\t" << book.shabak << "\t" << book.name << "\t" << book.writer << "\t" << book.year << "\t" << book.count << "\t" << book.available << endl;
}

void printBooks(book books[1000], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "\t\t" << books[i].shabak << "\t" << books[i].name << "\t" << books[i].writer << "\t" << books[i].year << "\t" << books[i].count << "\t" << books[i].available << endl;
	}
}

book getBook(int shabak) {

	ifstream inputFile("Books.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	book book;
	int count = 0;

	for (int i = 0; i < MAXSIZE && inputFile; i++)
	{

		inputFile >> book.shabak >> book.name >> book.writer >> book.year >> book.count >> book.available;
		if (book.shabak == shabak)
			return book;
		//this method check end of file 
		if (inputFile.eof()) {
			count = i;
			break;
		}
	}
}

book getBook(int shabak, char name[50]) {

	ifstream inputFile("Books.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	book book;
	int count = 0;

	for (int i = 0; i < MAXSIZE && inputFile; i++)
	{

		inputFile >> book.shabak >> book.name >> book.writer >> book.year >> book.count >> book.available;
		if (book.shabak == shabak)
			return book;
		//this method check end of file 
		if (inputFile.eof()) {
			count = i;
			break;
		}
	}
}

bool existBook(int shabak) {

	ifstream inputFile("Books.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	book book;
	int count = 0;

	for (int i = 0; i < MAXSIZE && inputFile; i++)
	{

		inputFile >> book.shabak >> book.name >> book.writer >> book.year >> book.count >> book.available;
		if (book.shabak == shabak)
			return true;
		//this method check end of file 
		if (inputFile.eof()) {
			count = i;
			break;
		}
	}
	return false;
}

bool existBook(int shabak, char name[50]) {

	ifstream inputFile("Books.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	book book;
	int count = 0;

	for (int i = 0; i < MAXSIZE && inputFile; i++)
	{

		inputFile >> book.shabak >> book.name >> book.writer >> book.year >> book.count >> book.available;
		if (book.shabak == shabak)
			return true;
		//this method check end of file 
		if (inputFile.eof()) {
			count = i;
			break;
		}
	}
	return false;
}

int getBookCount() {
	ifstream inputFile("Books.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	book books[100];
	int count = 0;

	for (int i = 0; i < MAXSIZE && inputFile; i++)
	{

		inputFile >> books[i].shabak >> books[i].name >> books[i].writer >> books[i].year >> books[i].count >> books[i].available;
		if (inputFile.eof()) {
			count = i;
			break;
		}
	}

	return count;
}

void addBook() {
	ofstream outputFile("Books.dat", ios::app);

	if (!outputFile) {
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	book newBook;
	cout << "enter shabak: ";
	cin >> newBook.shabak;
	cout << "enter name: ";
	cin >> newBook.name;
	cout << "enter writer: ";
	cin >> newBook.writer;
	cout << "enter year: ";
	cin >> newBook.year;

	if (existBook(newBook.shabak, newBook.name)) {
		book b = getBook(newBook.shabak, newBook.name);
		b.count += 1;
		b.available += 1;
		editBook(newBook.shabak, b);

		return;
	}
	newBook.count = 1;
	newBook.available = 1;
	outputFile << newBook.shabak << " " << newBook.name << " " << newBook.writer << " " << newBook.year << " " << newBook.count << " " << newBook.available << endl;

}

void onEditBook() {
	int shabak;
	cout << "you must be found book by shabak." << endl;
	cout << "please enter shabak: ";
	cin >> shabak;
	char name[50] = "";
	if (!existBook(shabak, name)) {
		cout << "book not found." << endl;
		return;
	}
	book b = getBook(shabak, name);
	printBookHeader();
	printBook(b);
	//editBook()

	book bookForUpdate;
	bookForUpdate.shabak = b.shabak;
	bookForUpdate.count = b.count;
	bookForUpdate.available = b.available;
	cout << "please enter book new information." << endl;
	cout << "enter name: ";
	cin >> bookForUpdate.name;
	cout << "enter writer: ";
	cin >> bookForUpdate.writer;
	cout << "enter year: ";
	cin >> bookForUpdate.year;

	editBook(shabak, bookForUpdate);
}

void editBook(int shabak, book b) {
	ifstream inputFile("Books.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}
	book books[MAXSIZE];
	int size = 0;

	for (int i = 0; i < MAXSIZE; i++)
	{
		inputFile >> books[i].shabak >> books[i].name >> books[i].writer >> books[i].year >> books[i].count >> books[i].available;
		//this method check end of file 
		if (books[i].shabak == shabak) {
			books[i] = b;
		}
		if (inputFile.eof()) {
			size = i;
			break;
		}
	}

	editBooks(books, size);
}

void editBooks(book books[MAXSIZE], int size) {
	ofstream outputFile("Books.dat", ios::out);

	if (!outputFile) {
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	for (int i = 0; i < size; i++)
	{
		outputFile << books[i].shabak << " " << books[i].name << " " << books[i].writer << " " << books[i].year << " " << books[i].count << " " << books[i].available << endl;
	}
}

void searchBook() {
	bool back = false;
	do
	{
		int step1;
		cout << "step4: ****************************search book****************************" << endl;
		cout << "\t\t1: search book with name   : " << endl;
		cout << "\t\t2: search book with writer : " << endl;
		cout << "\t\t3: search book with shabak :" << endl;
		cout << "\t\t4: back" << endl;
		cout << "step3: **************************select a item**************************" << endl;
		cout << "\t\tplease enter a number: ";
		cin >> step1;
		switch (step1) {
		case 1:
			searchBookByName();
			break;
		case 2:
			searchBookByWriter();
			break;
		case 3:
			searchBookByShabak();
			break;
		case 4:
			back = true;
			break;
		default:
			break;
		}
	} while (!back);
}

void searchBookByName() {
	ifstream inputFile("Books.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	char name[50];
	book book;
	cout << "please enter book name for search: ";
	cin >> name;
	int count = 0;
	printBookHeader();

	for (int i = 0; i < MAXSIZE; i++)
	{
		inputFile >> book.shabak >> book.name >> book.writer >> book.year >> book.count >> book.available;

		if (isSubstring(name, book.name, sizeof(book.name)) != -1) {
			printBook(book);
			count++;
		}

		//this method check end of file 
		if (inputFile.eof()) {
			break;
		}
	}
	if (count == 0)
		cout << "book not found." << endl;
}

void searchBookByWriter() {
	ifstream inputFile("Books.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	char name[50];
	book book;
	cout << "please enter book writer for search: ";
	cin >> name;
	int count = 0;
	printBookHeader();

	for (int i = 0; i < MAXSIZE; i++)
	{
		inputFile >> book.shabak >> book.name >> book.writer >> book.year >> book.count >> book.available;

		if (isSubstring(name, book.writer, sizeof(book.name)) != -1) {
			printBook(book);
			count++;
		}

		//this method check end of file 
		if (inputFile.eof()) {
			break;
		}
	}
	if (count == 0)
		cout << "book not found." << endl;
}

void searchBookByShabak() {
	ifstream inputFile("Books.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	int shabak;
	book book;
	cout << "please enter book shabak for search: ";
	cin >> shabak;
	int count = 0;
	printBookHeader();
	for (int i = 0; i < MAXSIZE && inputFile; i++)
	{
		inputFile >> book.shabak >> book.name >> book.writer >> book.year >> book.count >> book.available;
		if (book.shabak == shabak)
		{
			count++;
			printBook(book);
			break;
		}
		//this method check end of file 
		if (inputFile.eof()) {
			break;
		}
	}
	if (count == 0)
		cout << "book not found." << endl;
}

#pragma endregion

#pragma region مدیریت اعضای کتابخانه

void manageMembers() {

	bool back = false;
	do
	{
		int step;
		cout << "step4: ****************************manage members****************************" << endl;
		cout << "\t\t1: list members: " << endl;
		cout << "\t\t2: add member: " << endl;
		cout << "\t\t3: search member: " << endl;
		cout << "\t\t4: back" << endl;
		cout << "step3: **************************select a item**************************" << endl;
		cout << "\t\tplease enter a number: ";
		cin >> step;
		switch (step)
		{
		case 1:
			getMembers();
			break;
		case 2:
			addMember();
			break;
		case 3:
			searchMember();
			break;
		case 4:
			back = true;
			break;
		default:
			break;
		}

	} while (!back);
}

void getMembers() {
	cout << "step4: ****************************list members****************************" << endl;

	ifstream inputFile("Members.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}
	member members[MAXSIZE];
	int count = 0;

	for (int i = 0; i < MAXSIZE; i++)
	{
		inputFile >> members[i].firstName >> members[i].lastName >> members[i].number >> members[i].nationalCode;
		//this method check end of file 
		if (inputFile.eof()) {
			count = i;
			break;
		}
	}
	printMemberHeader();
	printMembers(members, count);
}

void addMember() {
	ofstream outputFile("Members.dat", ios::app);

	if (!outputFile) {
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	member newMember;
	cout << "enter first name: ";
	cin >> newMember.firstName;
	cout << "enter last name: ";
	cin >> newMember.lastName;
	cout << "enter student number: ";
	cin >> newMember.number;
	cout << "enter nationalCode: ";
	cin >> newMember.nationalCode;

	if (existMember(newMember.number)) {
		cout << "student is duplicate..." << endl;
		return;
	}

	outputFile << newMember.firstName << " " << newMember.lastName << " " << newMember.number << " " << newMember.nationalCode << endl;

}

bool existMember(int number) {

	ifstream inputFile("Members.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	member current;
	int count = 0;

	for (int i = 0; i < MAXSIZE && inputFile; i++)
	{

		inputFile >> current.firstName >> current.lastName >> current.number >> current.nationalCode;
		if (current.number == number)
			return true;
		//this method check end of file 
		if (inputFile.eof()) {
			count = i;
			break;
		}
	}
	return false;
}

void searchMember() {
	bool back = false;
	do
	{
		int step1;
		cout << "step4: ****************************search member****************************" << endl;
		cout << "\t\t1: search member with name   : " << endl;
		cout << "\t\t2: search member with number : " << endl;
		cout << "\t\t3: search member with nationalcode :" << endl;
		cout << "\t\t4: back" << endl;
		cout << "step3: **************************select a item**************************" << endl;
		cout << "\t\tplease enter a number: ";
		cin >> step1;
		switch (step1) {
		case 1:
			searchMemberByName();
			break;
		case 2:
			searchMemberByNumber();
			break;
		case 3:
			searchMemberByNationalCode();
			break;
		case 4:
			back = true;
			break;
		default:
			break;
		}
	} while (!back);
}

void searchMemberByName() {
	ifstream inputFile("Members.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	char name[50];
	member member;
	cout << "please enter member name for search: ";
	cin >> name;
	int count = 0;
	printMemberHeader();

	for (int i = 0; i < MAXSIZE; i++)
	{
		inputFile >> member.firstName >> member.lastName >> member.number >> member.nationalCode;

		if (isSubstring(name, member.firstName, sizeof(member.firstName)) != -1 || isSubstring(name, member.lastName, sizeof(member.lastName)) != -1) {
			printMember(member);
			count++;
		}

		//this method check end of file 
		if (inputFile.eof()) {
			break;
		}
	}
	if (count == 0)
		cout << "member not found." << endl;
}

void searchMemberByNumber() {
	ifstream inputFile("Members.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	int number;
	member member;
	cout << "please enter member number for search: ";
	cin >> number;
	int count = 0;
	printMemberHeader();
	for (int i = 0; i < MAXSIZE && inputFile; i++)
	{
		inputFile >> member.firstName >> member.lastName >> member.number >> member.nationalCode;
		if (member.number == number)
		{
			count++;
			printMember(member);
			break;
		}
		//this method check end of file 
		if (inputFile.eof()) {
			break;
		}
	}
	if (count == 0)
		cout << "member not found." << endl;
}

void searchMemberByNationalCode() {
	ifstream inputFile("Members.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	char nationalcode[11];
	member member;
	cout << "please enter member nationalcode for search: ";
	cin >> nationalcode;
	int count = 0;
	printMemberHeader();


	for (int i = 0; i < MAXSIZE; i++)
	{
		inputFile >> member.firstName >> member.lastName >> member.number >> member.nationalCode;

		if (isSubstring(nationalcode, member.nationalCode, sizeof(member.nationalCode)) != -1) {
			printMember(member);
			count++;
		}

		//this method check end of file 
		if (inputFile.eof()) {
			break;
		}
	}
	if (count == 0)
		cout << "member not found." << endl;
}

void printMemberHeader() {
	cout << "\t\t" << "first name" << "\t" << "last name" << "\t" << "number" << "\t\t" << "nationalCode" << endl;
}

void printMember(member member) {
	cout << "\t\t" << member.firstName << "\t\t" << member.lastName << "\t" << member.number << "\t" << member.nationalCode << endl;
}

void printMembers(member members[MAXSIZE], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "\t\t" << members[i].firstName << "\t\t" << members[i].lastName << "\t" << members[i].number << "\t" << members[i].nationalCode << endl;
	}
}

#pragma endregion

#pragma region امانت کتاب

void lendBook() {
	ofstream outputFile("LendBooks.dat", ios::app);

	if (!outputFile) {
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	lend lendBook;
	cout << "enter student number: ";
	cin >> lendBook.number;

	if (!existMember(lendBook.number)) {
		cout << "This student is not a member of library." << endl;
		return;
	}
	int lendCount = getLendBookCount(lendBook.number);
	if (lendCount >= 3)
	{
		cout << "you have already lend 3 books.";
		return;
	}

	cout << "enter book shabak: ";
	cin >> lendBook.shabak;
	if (!existBook(lendBook.shabak)) {
		cout << "book not found." << endl;
		return;
	}
	book book = getBook(lendBook.shabak);
	if (book.available == 0) {
		cout << "this book is not available." << endl;
		return;
	}
	
	cout << "enter lend date: ";
	cin >> lendBook.date;
	cout << "enter return date: ";
	cin >> lendBook.returnDate;
	outputFile << lendBook.number << " " << lendBook.shabak << " " << lendBook.date << " " << lendBook.returnDate << endl;

	book.available--;
	editBook(lendBook.shabak, book);
}

void returnBook() {
	ofstream outputFile("LendBooks.dat", ios::app);

	if (!outputFile) {
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	lend lendBook;
	cout << "enter student number: ";
	cin >> lendBook.number;
	cout << "enter book shabak: ";
	cin >> lendBook.shabak;
	cout << "enter today date: ";
	cin >> lendBook.returnDate;

	if (!existLendBook(lendBook.number, lendBook.shabak)) {
		cout << "This book has not been lended by this student." << endl;
		return;
	}
	lend current = getLendBook(lendBook.number, lendBook.shabak);
	if (!equals(current.returnDate, lendBook.returnDate, 11)) {
		cout << "you were late." << endl;
	}
	
	deleteLendBook(lendBook);

	book book = getBook(lendBook.shabak);
	book.available++;
	editBook(lendBook.shabak, book);
}

bool existLendBook(int number, int shabak) {
	ifstream inputFile("LendBooks.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	lend lendBook;

	for (int i = 0; i < MAXSIZE && inputFile; i++)
	{
		inputFile >> lendBook.number >> lendBook.shabak >> lendBook.date >> lendBook.returnDate;
		if (lendBook.number == number && lendBook.shabak == shabak)
			return true;
		//this method check end of file 
		if (inputFile.eof()) {
			break;
		}
	}
	return false;
}

lend getLendBook(int number, int shabak) {
	ifstream inputFile("LendBooks.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	lend lendBook;
	int count = 0;

	for (int i = 0; i < MAXSIZE && inputFile; i++)
	{
		inputFile >> lendBook.number >> lendBook.shabak >> lendBook.date >> lendBook.returnDate;
		if (lendBook.number == number && lendBook.shabak == shabak)
			return lendBook;
		//this method check end of file 
		if (inputFile.eof()) {
			count = i;
			break;
		}
	}
}

void deleteLendBook(lend lendBook) {

	ifstream inputFile("LendBooks.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}
	lend lendBooks[MAXSIZE];
	int count = 0;
	for (int i = 0; i < MAXSIZE && inputFile; i++)
	{
		inputFile >> lendBooks[i].number >> lendBooks[i].shabak >> lendBooks[i].date >> lendBooks[i].returnDate;
		
		if (inputFile.eof()) {
			count = i;
			break;
		}
	}

	ofstream outputFile("LendBooks.dat", ios::out);

	if (!outputFile) {
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	for (int i = 0; i < count; i++)
	{
		if (lendBooks[i].number == lendBook.number && lendBooks[i].shabak == lendBook.shabak) {
			continue;
		}
		outputFile << lendBooks[i].number << " " << lendBooks[i].shabak << " " << lendBooks[i].date << " " << lendBooks[i].returnDate << endl;
	}
}

int getLendBookCount(int studNumber) {
	ifstream inputFile("LendBooks.dat", ios::in);

	if (!inputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}

	lend lends[100];
	
	int count = 0;

	for (int i = 0; i < MAXSIZE && inputFile; i++)
	{
		inputFile >> lends[i].number >> lends[i].shabak >> lends[i].date >> lends[i].returnDate;
		if (lends[i].number == studNumber) {
			count++;
		}
		if (inputFile.eof()) {
			break;
		}
	}
	return count;
}

#pragma endregion

#pragma region متدهای عمومی

bool equals(char str[], char key[], int size) {
	int size1 = 0, size2 = 0;
	for (int i = 0; i < size; i++, size1++)
	{
		if (str[i] == '\0')
			break;
	}
	for (int i = 0; i < size; i++, size2++)
	{
		if (key[i] == '\0')
			break;
	}
	if (size1 != size2)
	{
		return false;
	}
	for (int i = 0; i < size1; i++)
	{
		if (str[i] != key[i])
			return false;
	}
	return true;
}

// Returns true if s1 is substring of s2 
int isSubstring(char key[], char str[], int size)
{
	int size1 = 0, size2 = 0;
	for (int i = 0; i < size; i++, size1++)
	{
		if (key[i] == '\0')
			break;
	}
	for (int i = 0; i < size; i++, size2++)
	{
		if (str[i] == '\0')
			break;
	}
	int M = size1;
	int N = size2;

	/* A loop to slide pat[] one by one */
	for (int i = 0; i <= N - M; i++) {
		int j;

		/* For current index i, check for pattern match */
		for (j = 0; j < M; j++)
			if (str[i + j] != key[j])
				break;

		if (j == M)
			return i;
	}

	return -1;
}

#pragma endregion

