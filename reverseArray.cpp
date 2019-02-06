#include<iostream>
using namespace std;


void reverseArray(int *myArray, int size) {
	cout << "After: ";
	for (int i = size-1; i >= 0; i--) {
	
		cout << myArray[i] <<" ";
	}
	cout << endl;

}
int main() {
	int array[4] = { 1,2,3,4 };
	cout << "Before: ";
	for (int i = 0; i < 4; i++) {
	
		cout << array[i] << " ";
	}
	cout << endl;
	reverseArray(array, 4);
	

	system("pause");
	return 0;
}