/* 
 * Samprayash Dahal
 * CPSC 301-03
 */
#include "person.cpp"
#include <fstream>
#include <iomanip>
#include <vector>
void readData(ifstream& ifile, vector<Person>& myList, int size);
void writeData(ofstream& filesname,vector<Person>& myList, int size);

int main(int argc, char * argv[])
	{	vector <Person> personList; 
		ifstream infile;
		infile.open("input.txt");
		ofstream outfile("output.txt");
		readData(infile, personList , 6);
		writeData(outfile, personList, 6);
		infile.close();
		outfile.close();
		return 0;
	}
void readData(ifstream& ifile, vector<Person>& myList, int size)
	{	int index =0;
		string first;
		string last;
		float pay;
		float hours;
		Person person;
		while(ifile >> first >> last >> hours >> pay)
		{
			person.setFirstName(first);
			person.setLastName(last);
			person.setPayrate(pay);
			person.setHoursWorked(hours);
			myList.emplace_back(person);
			index++;
		}
	}
void writeData(ofstream& filesname,vector<Person>& myList, int size)
	{
		for(int i = 0; i < myList.size(); i++)
                {
                       filesname  << myList[i].fullName()
			       << " " <<fixed << setprecision(2)
			       << myList[i].totalPay() << endl;
                }
	}
