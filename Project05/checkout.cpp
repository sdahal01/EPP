// Samprayash Dahal
// CPSC 301-03
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.cpp"
#include "book.cpp"

using namespace std;

void printMenu() {
    cout << "----------Library Book Rental System----------" << endl;
    cout << "1.  Book checkout" << endl;
    cout << "2.  Book return" << endl;
    cout << "3.  View all available books" << endl;
    cout << "4.  View all outstanding rentals" << endl;
    cout << "5.  View outstanding rentals for a cardholder" << endl;
    cout << "6.  Open new library card" << endl;
    cout << "7.  Close library card" << endl;
    cout << "8.  Exit system" << endl;
    cout << "Please enter a choice: ";
}

void readBooks(vector<Book *> & myBooks) {
 
 ifstream bFile("books.txt");
 int count = 0;
 int cardID;
 string bookName;
 string author;
 string category;
 string line;
 while(!bFile.eof())
{	bFile >> cardID;
	getline(bFile,line);
	getline(bFile,bookName);
	getline(bFile,author);
	getline(bFile,category);
	getline(bFile,line);
	Book list(cardID, bookName, author, category);
	myBooks.push_back(&list);
	count++;
	
 }
int bID;
cout << "Please enter the book ID:" << endl;
                cin >> bID;
                for(int i =0; i <50; i++)
                {
                        if(bID == myBooks.at(i)->getId())
                        {
                                cout << "Title: "
                                << myBooks.at(i)->getTitle() << endl;
                                cout <<"Rental Completed" << endl;
				break;
                        }
			else
			{
				cout << "Book ID not found" << endl;
				break;
			}
                }
}     
                              
void readPersons(vector<Person *> & myCardholders) {
    ifstream pFile("persons.txt");
    int count = 0;
    int cardID;
    bool status;
    string fName, lName;
    while(pFile >> cardID >> status >> fName >> lName)
    {
	Person list(cardID, status, fName, lName);
	myCardholders.push_back(&list);
	count++;
    }
    int pID;
    cout << "Please enter the card ID: " << endl;
                cin >> pID;
                for(int i = 0; i < 18; i++)
                {
                        if(pID == myCardholders.at(i)->getId())
                        {
                                cout << "Cardholder: "
                                     << myCardholders.at(i)->getFirstName()
				     <<" "
				     << myCardholders.at(i)->getLastName()
                                     << endl;
				break;
                        }
			else
			{
				cout<< "Card ID not found" << endl;
				break;

			}	
                }

}

void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders)
{
   int bookID;
   int cardID;
   int count = 0;
   Person *ptr;
   ifstream rFile("rentals.txt");
   while(rFile >> bookID >> cardID)
   {
	for(int i =0; i< 50; i++)
	{
		for(int j =0; j < 18; j++)
		{
			if(myBooks.at(i)->getId() == bookID
					&& myCardholders.at(j)->getId()
				       	== cardID)
			{
			ptr = new Person(myCardholders.at(j)->getId(),
			      myCardholders.at(j)->isActive(),
			      myCardholders.at(j)->getFirstName(),
			      myCardholders.at(j)->getLastName());
			cout << "PTR-> " << myCardholders.at(j)->getId()
                       <<" " << myCardholders.at(j)->isActive()
                       <<" " << myCardholders.at(j)->getFirstName()
                       <<" " <<  myCardholders.at(j)->getLastName() << endl;
			myBooks.at(i)->setPersonPtr(ptr);

			}
		}
	}
	count++;
   }


	cout << "Count = " << count << endl;
}

void openCard(vector<Person *> & myCardholders, int nextID) 
{

	string firstName, lastName;
	cout << "Please enter first name: ";
	cin >> firstName;
	cout << "Please enter the last name: ";
	cin >> lastName;
	for(int i = 0; i< 18; i++)
	{
		if(firstName == myCardholders.at(i)->getFirstName() 
		|| lastName == myCardholders.at(i)->getLastName())
		{
		       	if(myCardholders.at(i)->isActive())
			{
				cout << "Person already exists." << endl;
				break;
			}
		       	else
		       	{
			       	myCardholders.at(i)->setActive(1);
				 cout << "Card ID " << myCardholders.at(i)->getId() << "active" << endl;
				 break;
		       	}

		}
		else 
		{
			Person list(nextID+1, 1,firstName,lastName);
			myCardholders.push_back(&list);
			cout << "Card ID " << nextID + 1 << " active" << endl;
			break;
		}
	}
}

Book * searchBook(vector<Book *> myBooks, int id) {
	for(int i =0; i < 50; i++)
 	{
		if(id == myBooks.at(i)->getId()&& myBooks.at(i)->getPersonPtr() != nullptr)
		{ 	cout << "Book-> "<< myBooks.at(i)->getId()
		      <<" Title " << myBooks.at(i)->getTitle()
		      <<" Auth  " << myBooks.at(i)->getAuthor()
		     <<" Cat  " << myBooks.at(i)->getCategory()
		      << endl;
			return myBooks.at(i);
		}
	}		
}


int main()
{
    vector<Book *> books;
    vector<Person *> cardholders;
    int rID,id, choice;
   int nextID = 1017;
    do
    {
        // If you use cin anywhere, don't forget that you have to handle the <ENTER> key that 
        // the user pressed when entering a menu option. This is still in the input stream.
        printMenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                // Book checkout
		readPersons(cardholders);
		readBooks(books);	
                break;

            case 2:
		cout << "Please enter the book ID to return: " << endl;
		cin >> rID;
                for(int i =0; i < 50; i++)
		{
			if(rID == books.at(i)->getId())
			{
				cout <<"Title" 
					<< books.at(i)->getTitle() << endl;
				cout << "Return Complete" << endl;
				break;
			}
			else
			{
				cout << "Book ID not found" << endl;
				break;
			}
		}
                break;

            case 3:
		for(int i =0; i < 50; i++)
		{
		cout << "Book ID: " << books.at(i)->getId() << endl;
		cout << "Title: " << books.at(i)->getTitle() << endl;
		cout << "Author: " <<books.at(i)->getAuthor() << endl;
		cout << "Category: "<< books.at(i)->getCategory() <<endl;
		cout << endl;
		}
	        break;

            case 4:
                readRentals(books,cardholders);
                break;

            case 5:
		cout << "Please enter the card ID: " << endl;
		cin >> id;
               searchBook(books, id);
                break;

            case 6:
                // Open new library card
		openCard(cardholders,nextID);
                break;

            case 7:
                // Close library card
                break;
                
            case 8:
                // Must update records in files here before exiting the program
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 8);
      return 0;
}
