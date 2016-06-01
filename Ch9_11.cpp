/* 
By Jarrod Merryman (Credit to Intro to C++ Book)
This program uses an array of objects.
The objects are instances of the Circle class.
*/

#include <iostream>
#include <iomanip>
#include "Circle.h"              // Circle class declaration file
using namespace std;

void sortArray(Circle circle[], int SIZE);

int main()
{	
	const int SIZE = 8; // Creates constant value for the size of an array
	Circle circle[SIZE] = {2.5, 4.0, 1.0, 3.0, 6.0, 5.5, 3.5, 2.0};  // Define an array of Circle objects

	// Calls the the sort array method
	sortArray(circle, SIZE);

	// Use a loop to get and print out the area of each object
	cout << fixed << showpoint << setprecision(2);
	cout << "\nHere are the areas of the " << SIZE
         << " circles.\n";
	for (int index = 0; index < SIZE; index++)
	{  cout << "circle " << (index+1) << setw(8)
           << circle[index].findArea() << endl;
	}
	return 0;
}

/*
This method uses bubble sorting to sort the array
in ascending order
*/
void sortArray(Circle circle[], int SIZE)
{
	Circle temp;
	bool swap;

	do 
	{
		swap = false;
			for (int i = 0; i < (SIZE - 1); i++)
			{
				if (circle[i].findArea() > circle[i + 1].findArea())
				{
					temp = circle[i];
					circle[i] = circle[i + 1];
					circle[i + 1] = temp;
					swap = true;
				}
			}
	} while (swap);
}
