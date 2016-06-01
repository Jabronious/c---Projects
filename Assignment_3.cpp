/*
By Jarrod Merryman CS189 - Online
This program will allow the user to input a string and remove any not alphabetical 
characters then test if the phrase is a palindrome.
*/
#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include "cinNbr.h" // Allows user input for the menu to be checked

using namespace std;

void is_palindrome(string &input); // declaring the function to check if the phrase is a palindrome
string to_upper(string &input); // takes a string an only uppercases letters

int main()
{
	string user_input; // holds input from the user
	bool quit = false; // remain in the menu until completed
	int menuChoice; // holds the menu choice

	/*
	Begins the menu which allows the user
	to enter string, check for palindrome, or quit
	*/
	while (!quit)
	{
		system("cls"); // clears the console screen
		cout << "1. Enter a new string\n";
		cout << "2. Test string\n";
		cout << "3. Exit\n";
		cout << "\n Please enter your menu choice (1-3): ";
		cinNbr(menuChoice);
		switch (menuChoice)
		{
		case 1: // Accesses displayItems function
			cout << "Type your string:\n";
			getline(cin, user_input); // accepts the user's string
			cout << "Here is the filtered input: " << to_upper(user_input) << endl;
			system("pause"); // causes program to pause until user hits a key
			break;
		case 2: // Accesses addItems function
			cout << "Test for palindrome: "<< user_input << "\n";
			is_palindrome(user_input); // sends user_input to be check if its a palindrome
			system("pause"); // causes program to pause until user hits a key
			break;
		case 3: // Quits the program
			quit = true;
			cout << endl;
			break;
		default: // Tells the user there was an invalid input
			cout << endl << "Invalid menu choice. Please try again.\n\n";
			system("pause"); // causes program to pause until user hits a key
		}
		
	}
	
	cout << "Goodbye\n";
	return 0;
}

/*
This function will check the input provided by the user to see
if it is a palindrome.
*/
void is_palindrome(string &input)
{
	stack<char> s; // creates an instance of a stack
	queue<char> q; // creates an instance of a queue
	char next; // holds the next char from the string input
	string upperCase = to_upper(input); // makes input upper case and holds it
	string::iterator inPtr = upperCase.begin(); // iterator for the string upperCase
	bool failed = true; // determines if the string is a palindrome
	
	/*
	If there is no upperCase string then it tells the user to
	input a string
	*/
	if (upperCase.empty())
	{
		cout << "Please enter a string!\n";
		return;
	}

	/*
	loops through the string until the end and
	populates the queue and stack
	*/
	while (inPtr != upperCase.end())
	{

		s.push(*inPtr);
		q.push(*inPtr);
		inPtr++;
	}

	/*
	loops through the queue and stack until it
	is empty.
	*/
	while (!s.empty() && !q.empty() && failed)
	{
		// if the next letter in the stack/queue are equal
		// if not it breaks and sets failed to false
		if (s.top() == q.front())
		{
			s.pop();
			q.pop();
		}
		else
		{
			failed = false;
			break;
		}
	}

	// if failed is true sends user confirmation that input is a palindrome
	// if not tells user it is not a palindrome
	if (failed)
		cout << upperCase << "... is a palindrome\n";
	else
		cout << upperCase << "... is NOT a palindrome\n";
}

/*
This function will set the string that is sent to it to uppercase letters
and removes anything that is not a letter
*/
string to_upper(string &input)
{
	string::iterator inPtr = input.begin(); // iterator for a the input string
	string next; // holds the next letter in the string
	string upperCase; // holds the uppercase letters only

	// loops until the end of the input string
	while (inPtr != input.end())
	{
		// if the next character in teh string is a letter
		// it sets it to uppercase and appends upperCase
		if (isalpha(*inPtr))
		{
			next = toupper(*inPtr);
			upperCase.append(next);
		}
		inPtr++; // increments the iterator
	}
	return (upperCase); // returns the upperCase string
}
