#include <iostream>
#include <iomanip>


class DivSales
{
private:
   static double corpBudget; // holds the total for the company
   double divBudget; // total for each division
   double divArray[4]; // array used for each object
public:
	/*
	No-Arg constructor that sets the budget to 0
	*/
	DivSales() { divBudget = 0; }

	/*
	this method accepts an int and double and adds a value to the
	array for each object as long as index is within the correct
	bounds
	*/
	void setBudget(int index, double toAdd)
	{
		if (index >= 0 && index <= 3)
		{
			divArray[index] = toAdd;
		}
	}

	/*
	this method accepts a double and adds that value to the individual
	division's budget and the company's total budget
	*/
	void addBudget(double b)
       { divBudget += b; corpBudget += divBudget; }

	/*
	accepts an int value and returns the value held in the element of 
	the array
	*/
	double getIndividual(int dollar)
	{
		return divArray[dollar];
	}

	/*
	returns the total for the division's budget
	*/
    double getDivBudget() const { return divBudget; }

	/*
	returns the total for the company's total budget
	*/
    double getCorpBudget() const { return corpBudget; }
};
