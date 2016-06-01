/*
By Jarrod Merryman
Assignment_1 for cs189 Online
This program will create a virutal Piggy Bank that will hold ten coins. The user
can withdraw, deposit, or see totals of the Piggy Bank.
*/
#include "Container.h"
#include <iostream>
using namespace std;

enum coin { cent = 1, nickel = 5, dime = 10, quarter = 25 }; // enumarated data type for coins
template <typename T> // templatized function prototype
void cinNbr(T&); // enter a number from console

void displayItems(Container<coin>&);
void addItems(Container<coin>&);
void removeItem(Container<coin>&);


int main()
{
	Container<coin> c1; // Creates a container opject
	int menuChoice = 0; // used for the menu
	bool quit = false; // used to end program
	while (!quit)
	{
		system("cls"); // clears the console screen
		cout << "1. Show Piggy Bank contents\n";
		cout << "2. Add coins to your Piggy Bank\n";
		cout << "3. Withdraw coins from your Piggy Bank\n";
		cout << "4. Exit the program\n\n";
		cout << "What would you like to do? Select a number (1 - 4), then press Enter: ";
		cinNbr(menuChoice); // checks user input
		
		// Decides which function to use
		switch (menuChoice)
		{
		case 1:
			displayItems(c1);
			system("pause"); // causes program to pause until user hits a key
			break;
		case 2:
			cout << endl << "You chose to add coin(s) to your Piggy Bank 1.\n";
			addItems(c1);
			system("pause"); // causes program to pause until user hits a key
			break;
		case 3:
			cout << endl << "You chose to remove coins from your Piggy Bank.\n";
			removeItem(c1);
			system("pause"); // causes program to pause until user hits a key
			break;
		case 4:
			quit = true;
			cout << endl;
			break;
		default:
			cout << endl << "Invalid menu choice. Please try again.\n\n";
			system("pause"); // causes program to pause until user hits a key
		}
	}
	cout << "Closing...\n";
	return 0;
}

/*
This function will check user input and ask for a correct number
*/
template<typename T>
void cinNbr(T& var) // enter a number from keyboard
{
	cin >> var;
	while (cin.fail() || cin.get() != '\n') // if error encountered
	{
		cout << "Invalid entry!  Please re-enter value: ";
		cin.clear(); // clears any error flag
		cin.ignore(80, '\n'); // clears input buffer
		cin >> var;
	}
	cin.clear();
}

/*
This function will display the items in the Piggy Bank
and tell you how many coins you have and how much $$$
*/
void displayItems(Container<coin>& integers)
{
	double total = 0; // used to hold total dollar amount

	cout << "The Piggy Bank Contains:\n";

	// Output if there are zero coins in Piggy Bank
	// or output totals
	if (integers.size() == 0)
	{
		cout << "0 Cents\n";
		cout << "0 Nickels\n";
		cout << "0 Dimes\n";
		cout << "0 Quarters\n";
		cout << "The Piggy Bank contains a total of " << integers.size() << " coins\n";
		cout << "for a total balance of $0.00" << endl;
	}
	else
	{
		// Goes through the array of coins to get totals
		for (size_t i = 0; i < integers.size(); i++)
		{
			if (integers.getValue(i) == 1)
			{
				total += .01;
			}
			else if (integers.getValue(i) == 5)
			{
				total += .05;
			}
			else if (integers.getValue(i) == 10)
			{
				total += .10;
			}
			else
			{
				total += .25;
			}
		}

		cout << integers.count(cent) << " Cents\n";
		cout << integers.count(nickel) << " Nickles\n";
		cout << integers.count(dime) << " Dimes\n";
		cout << integers.count(quarter) << " Quarters\n";
		cout << "The Piggy Bank contains a total of " << integers.size() << " coins\n";
		cout << "for a total balance of $" << total << endl;
		cout << "\b\b  \n"; // delete last space and comma
	}
}

/*
This function will allow you to add coins to your Piggy Bank
unless it is full
*/
void addItems(Container<coin>& integers)
{
	int itemInput; // User Input
	
	if (integers.size() == CAPACITY) // Checks if Piggy Bank is full 
	{
		cout << "PIGGY BANK IS FULL!\n";
		return;
	}

	cout << "You have decided to save some money (good idea!). Please"
		<< " enter the number of coins to deposit as integers greater than or equal to zero.\n\n";
	
	// Cents Input
	cout << "How many cents would you like to deposit?\n";
	cinNbr(itemInput);
	
	// Checks for invalid input
	while (itemInput < 0)
	{
		cout << "Invalid Number. Try again!\n";
		cin >> itemInput;
	}

	// checks if inputted amount is 0 or if it was great than 0
	if (itemInput == 0)
		cout << "0 cents added\n";
	else if (itemInput > 0 && integers.size() != CAPACITY)
	{
		while (itemInput > 0 && integers.size() <= CAPACITY)
		{
			integers.addValue(cent);
			itemInput--;
		}

		// if the piggy bank is full it will return to main
		if (integers.size() == CAPACITY)
		{
			cout << "PIGGY BANK IS FULL!\n";
			return;
		}
	}
	//Nickel Input
	cout << "How many nickles would you like to deposit?\n";
	cinNbr(itemInput);

	// Checks for invalid input
	while (itemInput < 0)
	{
		cout << "Invalid Number. Try again!\n";
		cin >> itemInput;
	}

	// checks if inputted amount is 0 or if it was great than 0
	if (itemInput == 0)
		cout << "0 nickels added\n";
	else if (itemInput > 0 && integers.size() != CAPACITY)
	{
		while (itemInput > 0 && integers.size() <= CAPACITY)
		{
			integers.addValue(nickel);
			itemInput--;
		}

		// if the piggy bank is full it will return to main
		if (integers.size() == CAPACITY)
		{
			cout << "PIGGY BANK IS FULL!\n";
			return;
		}
	}
	// Dime Input
	cout << "How many dimes would you like to deposit?\n";
	cinNbr(itemInput);

	// Checks for invalid input
	while (itemInput < 0)
	{
		cout << "Invalid Number. Try again!\n";
		cin >> itemInput;
	}

	// checks if inputted amount is 0 or if it was great than 0
	if (itemInput == 0)
		cout << "0 dimes added\n";
	else if (itemInput > 0 && integers.size() != CAPACITY)
	{
		while (itemInput > 0 && integers.size() <= CAPACITY)
		{
			integers.addValue(dime);
			itemInput--;
		}

		// if the piggy bank is full it will return to main
		if (integers.size() == CAPACITY)
		{
			cout << "PIGGY BANK IS FULL!\n";
			return;
		}
	}
	// Quarter Input
	cout << "How many quarters would you like to deposit?\n";
	cinNbr(itemInput);

	// Checks for invalid input
	while (itemInput < 0)
	{
		cout << "Invalid Number. Try again!\n";
		cin >> itemInput;
	}

	// checks if inputted amount is 0 or if it was great than 0
	if (itemInput == 0)
		cout << "0 quarters added\n";
	else if (itemInput > 0 && integers.size() != CAPACITY)
	{
		while (itemInput > 0 && integers.size() <= CAPACITY)
		{
			integers.addValue(quarter);
			itemInput--;
		}

		// if the piggy bank is full it will return to main
		if (integers.size() == CAPACITY)
		{
			cout << "PIGGY BANK IS FULL!\n";
			return;
		}
	}
}

/*
This function will allow you to remove coins from
your Piggy Bank unless it is empty
*/
void removeItem(Container<coin>& integers)
{
	int itemInput; // used for user input
	int temp = 0; // used for counting coins removed

	// checks for an empty piggy bank and if it has coins
	// it will total each type and ask if the user wants
	// to remove any.
	if (integers.size() == 0)
	{
		cout << "There is nothing here but dust :(\n";
		return;
	}
	else
	{
		// checks if there are 0 cents
		if (integers.count(cent) == 0)
		{
			cout << "There are no cents in your Piggy Bank\n";
		}
		// asks how many coins they wish to withdraw
		else
		{
			cout << "How many cents do you wish to withdraw?\n";
			cinNbr(itemInput);

			// checks user input
			while (itemInput < 0)
			{
				cout << "Invalid Number. Try again!\n";
				cin >> itemInput;
			}

			// removes coin type until input or coin type is 0
			while (itemInput > 0 && integers.count(cent) !=0)
			{
				integers.eraseOne(cent);
				itemInput--;
				temp++;
			}
			cout << temp << " cents have been removed\n";
			// tells user if coin type is depleted
			if (integers.count(cent) == 0)
				cout << "There are no more cents\n";
		}

		// checks if there are 0 nickels
		if (integers.count(nickel) == 0)
		{
			cout << "There are no nickels in your Piggy Bank\n";
		}
		// asks how many coins they wish to withdraw
		else
		{
			temp = 0;
			cout << "How many nickels do you wish to withdraw?\n";
			cinNbr(itemInput);

			// checks user input
			while (itemInput < 0)
			{
				cout << "Invalid Number. Try again!\n";
				cin >> itemInput;
			}

			// removes coin type until input or coin type is 0
			while (itemInput > 0 && integers.count(nickel) != 0)
			{
				integers.eraseOne(nickel);
				itemInput--;
				temp++;
			}
			cout << temp << " nickels have been removed\n";
			// tells user if coin type is depleted
			if (integers.count(nickel) == 0)
				cout << "There are no more nickels\n";
		}

		// checks if there are 0 dimes
		if (integers.count(dime) == 0)
		{
			cout << "There are no dimes in your Piggy Bank\n";
		}
		// asks how many coins they wish to withdraw
		else
		{
			temp = 0;
			cout << "How many dimes do you wish to withdraw?\n";
			cinNbr(itemInput);

			// checks user input
			while (itemInput < 0)
			{
				cout << "Invalid Number. Try again!\n";
				cin >> itemInput;
			}

			// removes coin type until input or coin type is 0
			while (itemInput > 0 && integers.count(dime) != 0)
			{
				integers.eraseOne(dime);
				itemInput--;
				temp++;
			}
			cout << temp << " dimes have been removed\n";
			// tells user if coin type is depleted
			if (integers.count(dime) == 0)
				cout << "There are no more dimes\n";
		}

		// checks if there are 0 nickels
		if (integers.count(quarter) == 0)
		{
			cout << "There are no quarters in your Piggy Bank\n";
		}
		// asks how many coins they wish to withdraw
		else
		{
			temp = 0;
			cout << "How many quarters do you wish to withdraw?\n";
			cinNbr(itemInput);

			// checks user input
			while (itemInput < 0)
			{
				cout << "Invalid Number. Try again!\n";
				cin >> itemInput;
			}

			// removes coin type until input or coin type is 0
			while (itemInput > 0 && integers.count(quarter) != 0)
			{
				integers.eraseOne(quarter);
				itemInput--;
				temp++;
			}
			cout << temp << " quarters have been removed\n";
			// tells user if coin type is depleted
			if (integers.count(quarter) == 0)
				cout << "There are no more quarters\n";
		}
	}
}
