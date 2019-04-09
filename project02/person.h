#ifndef PERSON_H_
#define PERSON_H_
#include<string>
using namespace std;
class Person{
        private:
                string lastName;
                string firstName;
                float payRate;
                float hoursWorked;
        public:
                Person(string fName, string lName, float rate, float worked);
		Person();
                void setLastName(string lName);
                string getLastName();
                void setFirstName(string fName);
                string getFirstName();
                void setPayrate(float rate);
                float getPayRate();
                void setHoursWorked(float hours);
                float getHoursWorked();
                float totalPay();
                string fullName();

};      

#endif

