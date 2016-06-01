// FILE: Driver.cpp
#include <typeinfo>
#include <iostream>
#include <string>
#include "List.h"
#include "Employee.h"
using namespace std;
 
 
void displayItems(const List<Employee>&);
void addItems(List<Employee>&);
void searchItem(List<Employee>&);
void removeItem(List<Employee>&);
 
int main()
{
    List<Employee> employees; // Creates an empty list of Employees
    int menuChoice = 0; //sets the menu choice to 0
    bool quit = false; // sets quit to false and will become true when you quit the program
 
    // Displays menu options while "quit" is still false
    while (!quit)
    {
        system("cls"); // clears the console screen
        cout << "1. Show the Employee List contents\n";
        cout << "2. Add item(s) to the List\n";
        cout << "3. Search for an item in the List\n";
        cout << "4. Withdraw single item from the List\n";
        cout << "5. Exit the program\n\n";
        cout << "What would you like to do? Select a number (1 - 6), then press Enter: ";
        cinNbr(menuChoice);
        switch (menuChoice)
        {
        case 1: // Accesses displayItems function
            displayItems(employees);
            system("pause"); // causes program to pause until user hits a key
            break;
        case 2: // Accesses addItems function
            cout << endl << "You chose to add an Employee to the List.\n";
            cout << "Type the double(s) that will be stored,\n";
            addItems(employees);
            system("pause"); // causes program to pause until user hits a key
            break;
        case 3: // Access searchItem
            cout << endl << "You chose to search for an Employee in the List.\n";
            cout << "Type the Employee ID # to be searched:\n";
            searchItem(employees);
            system("pause"); // causes program to pause until user hits a key
            break;
        case 4: // Access removeItem
            cout << endl << "You chose to remove an Employee from the List,\n";
            cout << "Type the Employee ID # to be removed from the List:\n";
            removeItem(employees);
            system("pause"); // causes program to pause until user hits a key
            break;
        case 5: // Quits the program
            quit = true;
            cout << endl;
            break;
        default: // Tells the user there was an invalid input
            cout << endl << "Invalid menu choice. Please try again.\n\n";
            system("pause"); // causes program to pause until user hits a key
        }
    }
    cout << "Closing...\n";
    return 0;
}
 
/*
This function will accept the list of employees and
output each employee name, id, and salary
*/
void displayItems(const List<Employee>& doubles)
{
    if (doubles.size() == 0)
        cout << "List empty!\n";
    else if (doubles.size() > 100)
    {
        cout << "List too long to be displayed!\n";
        cout << "List size: " << doubles.size() << endl << endl;
    }
    else
    {
        cout << "Here are the contents:\n";
        for (List<Employee>::const_iterator iLoc = doubles.begin(); iLoc != doubles.end(); iLoc++)
            cout << *iLoc;
        cout << "\b\b  \n"; // delete last space and comma
        cout << "List size: " << doubles.size() << endl << endl;
    }
}
 
/*
This function will accept the list of employees and
allow you to add employees to your list
*/
void addItems(List<Employee>& doubles)
{
    cout << "Press \"q\" when you are done:\n";
    bool cont = true; // used to continue the loop until told to break from user
    string input; // used for input on whether the user is done or not
    Employee another; // creates a new instance of an employee
   
    // This loop will continue as long as the user requires
    while (cont == true)
    {
            another.setEmployee(); // accesses the setEmployee function
            doubles.push_back(another); // adds the employee to the list
            cout << "Enter another Employee? (y/n)\n";
            getline(cin, input);
           
            // loops if the input is not y or n
            while (input != "y" && input != "n")
            {
                cout << "Invalid Entry: Enter another Employee? (y/n)\n";
                getline(cin, input);
            }
           
            // if user use n it will set cont to false
            if (input == "n")
                cont = false;
    }
   
}
 
/*
This function will accept the list of employees and
search for an employee based on their ID number. Also,
it will automatically move that person found to the top of the list
*/
void searchItem(List<Employee>& doubles)
{
    // if the list is empty inform user or continue to search
    if (doubles.size() == 0)
        cout << "List empty!\n";
    else
    {
        size_t id; // used for holding the id of employee being searched
        cinNbr(id); // checks for valid input
        size_t index = 0; // sets index to 0
        List<Employee>::iterator iLoc = doubles.begin(); // set iterator iLoc to the beginning of the list
 
        // as long as iLoc is not equal continue searching for ID
        while (iLoc != doubles.end())
        {
            // if the ID being searched for is found on an employee
            // display information and move employee to the top
            if ((*iLoc).getID() == id)
            {
                cout << "Value " << id << " found at node # " << index << endl;  
                cout << *iLoc << endl;
                doubles.push_front(*iLoc); // put a copy of that employee at the top of the list
                doubles.erase(iLoc); // removes that employee from previous location
                break;
            }
            index++;
            iLoc++;
           
        }
 
        // Informs user if the ID was not found
        if (iLoc == doubles.end())
            cout << "Value " << id << " not found!\n";
    }
}
 
/*
This function will accept the list of employees and
remove an employee based on the ID inputted
*/
void removeItem(List<Employee>& doubles)
{
    // if the list is empty inform user or continue to search
    if (doubles.size() == 0)
        cout << "List empty!\n";
    else
    {
        size_t id; // used for holding the id of employee being searched
        cinNbr(id); // checks for valid input
        size_t index = 0; // sets index to 0
        List<Employee>::iterator iLoc = doubles.begin(); // set iterator iLoc to the beginning of the list
       
        // as long as iLoc is not equal continue searching for ID
        while (iLoc != doubles.end())
        {
            // if the ID being searched for is found on an employee
            // display information and move employee to the top
            if ((*iLoc).getID() == id)
            {
                cout << "Value " << id << " removed from node # " << index << endl;
                cout << *iLoc << endl;
                doubles.erase(iLoc); // removes the employee at that location
                break;
            }
            index++;
            iLoc++;
        }
       
        // Informs user if the ID was not found
        if (iLoc == doubles.end())
            cout << "Value " << id << " not found!\n";
    }
}