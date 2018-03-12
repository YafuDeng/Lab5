//Yafu Deng
//CPSC 121 Lab 5
//3/11/2018
#include<iostream>
#include<cstdlib>
using namespace std;

/*
Using Arrays

Create a program that:
1.  Prompts the user to input values for an array of five integers
2.  Displays a menu, where the user may choose
a)  Sum - Calculates and displays the sum of numbers in the array
b)  Mean - Calculates and displays the average of numbers in the array. Should not round.
Should not be an integer!
c)  Display - Displays the current values held in the array
d)  Sequencing - Displays the difference between each adjacent set of values
Ie if we had 3 5 2 9 0, we would get the output
2 -3 7 -9
This just needs to be printed, not saved
e)  Search - Indicate whether the user¡¯s chosen value is contained in the array, or not (boolean result should be returned, ie function).
f)  Edit - The user is re-prompted for input into the array (all elements)
g)  Exit - terminate the program
3.  Loop back to step 2
There should be at least 4 functions used in this program. The argument should be the array itself in most of these functions.

You should probably use a global const int for array size. Do not use global variables unless they¡¯re constants!
*/

const int SIZE = 5;

//sum
void sumCalculator(int[]);
//mean
void meanCalculator(int[]);
//display
void displayArray(int[]);
//sequencing
void sequancing(int[]);
//search
bool search(int[], int);
//edit
void editArray(int[]);

int main()
{
	//set up variables
	char choice = 'z';
	int myArray[SIZE];
	bool searchArray = 0;
	bool doAgain = 1;
	int searchInt = 0;
	//Prompts the user to input values for an array of five integers
	cout << "Please enter the 5 integer you want to put into the array:" << endl;
	for (int i = 0; i < SIZE; i++)
		cin >> myArray[i];

	do
	{
		//Displays a menu, where the user may choose
		cout << "Please enter the character in fron of each menu choose:" << endl;
		cout << "a) Sum" << endl;
		cout << "b) Mean" << endl;
		cout << "c) Display" << endl;
		cout << "d) Sequencing" << endl;
		cout << "e) Search" << endl;
		cout << "f) Edit" << endl;
		cout << "g) Exit" << endl;
		//get choice from user
		cin >> choice;
		//operate based on the choice
		switch (choice)
		{
		case 'a':
			sumCalculator(myArray);
			break;
		case 'b':
			meanCalculator(myArray);
			break;
		case 'c':
			displayArray(myArray);
			break;
		case 'd':
			sequancing(myArray);
			break;
		case 'e':
		{
			cout << "Please enter the interger you want to search: " << endl;
			cin >> searchInt;
			searchArray = search(myArray, searchInt);
			//output result by case
			if (searchArray)
				cout << "The integer you are looking for is in the array." << endl;
			else
				cout << "The integer you are looking for is not in the array." << endl;
			break;
		}
		case 'f':
			editArray(myArray);
			break;
		case 'g':
			exit(0);
			break;
		}
		//pause the program for checking
		system("pause");
		//clear everything
		system("cls");
		//3.  Loop back to step 2
	} while (doAgain);

	
	system("pause");
	return 0;
}

//sum
void sumCalculator(int myArray[])
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
		sum += myArray[i];
	cout << "The sum of the array is: " << sum << endl;;
}
//mean
void meanCalculator(int myArray[])
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
		sum += myArray[i];
	cout << "The mean of the array is: " << sum / SIZE << endl;
}
//display
void displayArray(int myArray[])
{
	for (int i = 0; i < SIZE; i++)
		cout << myArray[i] << " ";
	cout << endl;
}
//sequencing
void sequancing(int myArray[])
{
	for (int i = 1; i < SIZE; i++)
		cout << myArray[i] - myArray[i - 1] << " ";
	cout << endl;
}
//search
bool search(int myArray[], int searchInt)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (myArray[i] == searchInt)
			return 1;
		return 0;
	}
}
//edit
void editArray(int myArray[])
{
	cout << "Please enter all 5 new elemets of the array: " << endl;
	for (int i = 0; i < SIZE; i++)
		cin >> myArray[i]; 
}
