// Samprayash Dahal
// CPSC 301-03

#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<iomanip>

using namespace std;

struct Person {
	char Name[20];
	float Balance;
};
void display(Person myArray[], int num);	// displays all records in array myArray
void findRichest(Person myArray[], int num);	// dispalys the name of the customer with maximum balance
void deposit(Person myArray[], int num, const string& s, float amount); // allows customer to deposit money in hiis/her account
void newCopy(ostream& outFile, Person myArray[], int num); // copies array myArray in the same file
Person * readData(int & N);
void printMenu();
int main()
{
	int len = 6;
	Person *person;
	person = new Person[len];
	person = readData(len);
	int choice;
	string firstN;
	string lastN;
	string fullN;
	float amt = 0.0;
	ofstream out("data.txt");
	do 
	{
		printMenu();
		cin >> choice;
		switch (choice)
		{
		case 1: 
			display(person, 6);
			break;
		case 2: 
		cout << "Enter the first name: " << endl;
		cin >> firstN;
		cout << "Enter the last name: " << endl;
		cin >> lastN;
		fullN = firstN + " " + lastN;
		cout << "Enter the amount: " << endl;
		cin >> amt;
		deposit(person, 6, fullN, amt);
		break;
		
		case 3: 
			findRichest(person, 6);
			break;
		case 4: 
			newCopy(out, person, 6);
			break;

		case 5:
			newCopy(out, person, 6);
			break;
		default:
			cout << "Invalid entry" << endl;
			break;
		}
		cout << endl;
	} while (choice != 5);
	
	
	
	delete[] person;
	cout << endl;
	system("Pause");
	return 0;
}

Person * readData(int & N)
{
	static Person person[6];
	ifstream infile;
	infile.open("data.txt");
	int count = 0;
	string fName;
	string lName;
	string name;
	while (count < 6)
	{
		infile >> fName >> lName >> person[count].Balance;
		// fName read string frist name from a text file
		// lName  read string last name from a text file
		//bal read float balance from a text file
		name = fName + " " + lName;	 // concatnate the two string with space in between and store is in new string 
		int n = name.length(); // get the length of string name
		char a[20]; // assign the size to to char array
		name.copy(a, name.size() + 1); // use this fuction to copy string name and store it in a char array things form the string name to char array a.
		a[name.size()] = '\0'; // put "\0" at the end
		for (int i = 0; i < n + 1; i++) // for loop to store item from the char a to the struct person
		{
			 person[count].Name[i] = a[i];
		}
		count++; // count to keep track of number of person
	}
	return person;
}
void display(Person myArray[], int num)
{
	cout << "\t Name \t\tBalance" << endl;
	cout << "\t-----------------------------" << endl;
	for (int i = 0; i < num; i++) {
		cout << "\t" << fixed << setprecision(2)
			<< myArray[i].Name << "    "
			<< myArray[i].Balance << endl;
	}
	cout << endl;
}
void findRichest(Person myArray[], int num)
{
	float m = 0.0;
	for (int i = 0; i < 6; i++)
	{
		if (myArray[i].Balance > m)
		{
			m = myArray[i].Balance;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (myArray[i].Balance == m)
			cout << "The customer with maximum balance is "
			<< myArray[i].Name << endl;
	}
	cout << endl;
}
void deposit(Person myArray[], int num, const string& s, float amount)
{
	string str[6];					// create a string array to store the names 
	
	for (int i = 0; i < num; i++)	// for loop to store names into str array from myarray.Name
	{
		str[i] = myArray[i].Name;
	}
	for (int i = 0; i < num; i++) // use for loop to compare strings and if its a match ask for deposit amnt
	{

		if (s == str[i])
		{
			myArray[i].Balance += amount;
			cout << "Now your new balance is: " << fixed << setprecision(2)
				<< myArray[i].Balance << endl;
		}
	
	}
}
void newCopy(ostream& outFile, Person myArray[], int num)
{
	for (int i = 0; i < num; i++) {
		outFile << fixed << setprecision(2)
			<< myArray[i].Name << "\t"
			<< myArray[i].Balance << endl;
	}
	cout << endl;
}
void printMenu()
{
	cout << "Please enter a choice:" << endl;
	cout << "1. Display records" << endl;
	cout << "2. Deposit funds" << endl;
	cout << "3. Find Highest Balance" << endl;
	cout << "4. Update records" << endl;
	cout << "5. Exit the program" << endl;

}
