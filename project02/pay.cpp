#include "person.cpp"
#include <fstream>
#include <iomanip>

void readData(ifstream& ifile, Person *myarray, int size);
void writeData(ofstream& filesname, Person *myarray, int size);

int main(int argc, char * argv[])
	{	Person array[20];
		ifstream infile;
		infile.open("input.txt");
		readData(infile, array , 6);
		infile.close();
		ofstream outfile("output.txt");
		if(outfile.is_open())
		{	
		writeData(outfile, array, 6);
		}
		outfile.close();
		system("pause");
		return 0;
	}
void readData(ifstream& ifile, Person *myarray, int size)
	{	int index =0;
		string first;
		string last;
		float pay;
		float hours;
		while(ifile >> first >> last >> hours >> pay)
		{
			myarray[index].setFirstName(first);
			myarray[index].setLastName(last);
			myarray[index].setPayrate(pay);
			myarray[index].setHoursWorked(hours);
			index++;
		}
	}
void writeData(ofstream& filesname, Person *myarray, int size)
	{
		for(int i = 0; i < size; i++)
                {
                       filesname  << myarray[i].fullName()
			       << " " <<fixed << setprecision(2)
			       << myarray[i].totalPay() << endl;
                }
	}
