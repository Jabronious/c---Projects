/*
By Jarrod Merryman
This program asks for rainfall stats and then analyzes the info
and outputs the statistics
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;


void getData(double rain[]);
double totalRainfall(double rain[]);
double averageRainfall(double rain[]);
int driestMonth(double rain[]);
int wettestMonth(double rain[]);
void displayReport(double rain[], int lowest, int highest);

int main()
{
	const int MONTHS = 12; // sets an int constant to 12 for 12 months
	double rain[MONTHS]; // creates an array with length MONTHS
	int lowest, // Creates an int to hold the lowest value
		highest; // Creates an int value to hold the highest value
	
	// Calls the get rain method
	getData(rain);

	// Shows stats output of the rain data
	cout << "2010 Rain Report for Neversnows County" << endl;
	cout << "Total Rainfall: " << totalRainfall(rain) 
		<< " inches" << endl;
	cout << "Average Monthly Rainfall: " << averageRainfall(rain)
		<< " inches" << endl;
	
	// Sets the driest and wettest months
	lowest = driestMonth(rain);
	highest = wettestMonth(rain);

	// Calls the display report method
	displayReport(rain, lowest, highest);

	return 0;
}

/*
This method accepts the rain array and initializes the values
that are inside the array
*/
void getData(double rain[])
{
	int num = 12;
	for (int i = 0; i < num; i++)
	{
			cout << "How much rainfall did you receive in the "
				<< i + 1 << " month." << endl;
			cin >> rain[i];
	}
}

/*
This method accepts the rain array and calculates 
the total rainfall
*/
double totalRainfall(double rain[])
{
	int num = 12;
	double tempRain = 0;
	for (int i = 0; i < num; i++)
	{
		tempRain += rain[i];
	}
	return tempRain;
}

/*
This method accepts the rain array and calculates the 
average rainfall
*/
double averageRainfall(double rain[])
{
	double avg;
	return avg = totalRainfall(rain) / 12;
}


/*
This method accepts the rain array and determines 
the driest month
*/
int driestMonth(double rain[])
{
	double min = 1000000000;
	int monthNum,
		num = 12;
	for (int i = 0; i < num; i++)
	{
		if (rain[i] < min)
		{
			monthNum = i;
			min = rain[i];
		}
	}
	return monthNum;
}

/*
This method accepts the rain array and determisn
the wettest month
*/
int wettestMonth(double rain[])
{
	double max = -1;
	int monthNum;
		int num = 12;
	for (int i = 0; i < num; i++)
	{
		if (rain[i] > max)
		{
			monthNum = i;
			max = rain[i];
		}
	}
	return monthNum;
}

/*
This method accepts the rain array and the lowest and highest int values
to output the the months that had the lowest/highest rainfall
*/
void displayReport(double rain[], int lowest, int highest)
{
	switch (lowest)
	{
	case 0:
		cout << "The least rain fell in January with " 
			<< rain[lowest] << " inches.";
		break;

	case 1:
		cout << "The least rain fell in February with "
			<< rain[lowest] << " inches.";
		break;

	case 2:
		cout << "The least rain fell in March with "
			<< rain[lowest] << " inches.";
		break;

	case 3:
	    cout << "The least rain fell in April with "
			<< rain[lowest] << " inches.";
		break;
	
	case 4:
		cout << "The least rain fell in May with "
			<< rain[lowest] << " inches.";
		break;

	case 5:
		cout << "The least rain fell in June with "
			<< rain[lowest] << " inches.";
		break;

	case 6:
		cout << "The least rain fell in July with "
			<< rain[lowest] << " inches.";
		break;

	case 7:
		cout << "The least rain fell in August with "
			<< rain[lowest] << " inches.";
		break;
	
	case 8:
		cout << "The least rain fell in September with "
			<< rain[lowest] << " inches.";
		break;

	case 9:
		cout << "The least rain fell in October with "
			<< rain[lowest] << " inches.";
		break;

	case 10:
		cout << "The least rain fell in November with "
			<< rain[lowest] << " inches.";
		break;

	case 11:
		cout << "The least rain fell in December with "
			<< rain[lowest] << " inches.";
		break;
	}
	cout << "\n";

	switch (highest)
	{
	case 0:
		cout << "The most rain fell in January with "
			<< rain[highest] << " inches.";
		break;

	case 1:
		cout << "The most rain fell in February with "
			<< rain[highest] << " inches.";
		break;

	case 2:
		cout << "The most rain fell in March with "
			<< rain[highest] << " inches.";
		break;

	case 3:
		cout << "The most rain fell in April with "
			<< rain[highest] << " inches.";
		break;

	case 4:
		cout << "The most rain fell in May with "
			<< rain[highest] << " inches.";
		break;

	case 5:
		cout << "The most rain fell in June with "
			<< rain[highest] << " inches.";
		break;

	case 6:
		cout << "The most rain fell in July with "
			<< rain[highest] << " inches.";
		break;

	case 7:
		cout << "The most rain fell in August with "
			<< rain[highest] << " inches.";
		break;

	case 8:
		cout << "The most rain fell in September with "
			<< rain[highest] << " inches.";
		break;

	case 9:
		cout << "The most rain fell in October with "
			<< rain[highest] << " inches.";
		break;

	case 10:
		cout << "The most rain fell in November with "
			<< rain[highest] << " inches.";
		break;

	case 11:
		cout << "The most rain fell in December with "
			<< rain[highest] << " inches.";
		break;
	}
	cout << "\n";
}

