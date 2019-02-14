
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
void display(Person* myArray, int num);	// displays all records in array myArray
void findRichest(Person* myArray, int num);	// dispalys the name of the customer with maximum balance
void deposit(const string& s, Person* myArray, int num); // allows customer to deposit money in hiis/her account
void newCopy(ostream& outFile, Person* myArray, int num); // copies array myArray in the same file
int main()
{
	int count = 0;
	string fName;
	string lName;
	string name;
	float bal;
	ifstream infile;
	infile.open("data.txt");
	Person person[6];

	while (infile >> fName >> lName >> bal)
	{

		// fName read string frist name from a text file
		// lName  read string last name from a text file
		//bal read float balance from a text file
		name = fName + " " + lName;	 // concatnate the two string with space in between and store is in new string
		person[count].Balance = bal; // store the balacne in specific index

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

	display(person, 6);
	findRichest(person, 6);
	string find;
	cout << "Enter your name to deposit money: " << endl;
	getline(cin, find);
	deposit(find,person, 6);
	ofstream out("data.txt");
	if (out.is_open())
	{
		newCopy(out, person, 6);
	}

	 cout << endl;
	infile.close();
	system("Pause");
	return 0;
}
void display(Person* myArray, int num)
{
	cout << "\t Name \t\tBalance" << endl;
	cout << "\t-----------------------------" << endl;
	for (int i = 0; i < num; i++) {
		cout <<"\t" << fixed << setprecision(2) 
			<< myArray[i].Name <<"    "
		    << myArray[i].Balance << endl;
	}
	cout << endl;
}
void findRichest(Person* myArray, int num)
{
	float m = 0;
	for (int i = 0; i < num; i++)
	{
		if (myArray[i].Balance > m)
		{
			m = myArray[i].Balance;
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (myArray[i].Balance == m)
			cout << "The customer with maximum balance is "
			<< myArray[i].Name << endl;
	}
	cout << endl;
}
void deposit(const string& s, Person* myArray, int num)
{
	float dpst = 0.0;
	string str[6];					// create a string array to store the names 
	for (int i = 0; i < num; i++)	// for loop to store names into str array from myarray.Name
	{
		str[i] = myArray[i].Name;
	}
	for(int i = 0; i < num; i++) // use for loop to compare strings and if its a match ask for deposit amnt
	{

		if (s == str[i])
		{
			cout << "Enter the amount you would like to deposit: " << endl;
			cin >> dpst;
			myArray[i].Balance += dpst;
			cout << "Now your new balance is: " << fixed << setprecision(2)
				<< myArray[i].Balance << endl;
		}
	}
}

void newCopy(ostream& outFile , Person* myArray, int num)
{

	for (int i = 0; i < num; i++) {
		outFile << fixed << setprecision(2)
			<< myArray[i].Name <<"\t"
			<< myArray[i].Balance << endl;
	}
	cout << endl;
}