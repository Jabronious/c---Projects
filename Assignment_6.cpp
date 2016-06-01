/*
By Jarrod Merryman
This program will ask for a letter and a number for two intersections and then provide you the fastest way from
the first point to the second.
*/
#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
	graph Map;
	int first, second;
	while (true)
	{
#ifdef BOOK_SAMPLE // for textbook sample
		cout << "Enter 0 to quit\n";
		cout << "From Vertex (enter number from 1 to " << Map.size() << "): ";
		cin >> first;
		--first; // set actual index
#endif
#ifdef TRAFFIC // for the traffic project
		// sets value for the first vertex
		char intersection = NULL; // used to determine intersection letter
		int row; // used for interest number
		cout << "Enter 0 for the row or Q for the intersection to quit\n";
		cout << "From Intersection (enter column from A to D): ";
		cin >> intersection; 
		
		// validates the user inputs an acceptable value for intersection
		while (toupper(intersection) != 'A' && toupper(intersection) != 'B'
			&& toupper(intersection) != 'C' && toupper(intersection) != 'D' && toupper(intersection) != 'Q')
		{
			cout << "Invalid Character\n";
			cin >> intersection;
		}


		cout << "Enter Row (from 1 to 4): ";
		cin >> row;

		// validates user input for row
		while (row < 0 || row > 4)
		{
			cout << "Invalid Entry\n";
			cin >> row;
		}
		
		// ends program if conditions are met
		// or uses interesction and row to assign correct vertex
		if (row == 0 || toupper(intersection) == 'Q')
			return 0;
		else if (toupper(intersection) == 'A')
		{
			if (row == 1)
				first = 0;
			else if (row == 2)
				first = 1;
			else if (row == 3)
				first = 2;
			else if (row == 4)
				first = 3;
		}
		else if (toupper(intersection) == 'B')
		{
			if (row == 1)
				first = 4;
			else if (row == 2)
				first = 5;
			else if (row == 3)
				first = 6;
			else if (row == 4)
				first = 7;
		}
		else if (toupper(intersection) == 'C')
		{
			if (row == 1)
				first = 8;
			else if (row == 2)
				first = 9;
			else if (row == 3)
				first = 10;
			else if (row == 4)
				first = 11;
		}
		else if (toupper(intersection) == 'D')
		{
			if (row == 1)
				first = 12;
			else if (row == 2)
				first = 13;
			else if (row == 3)
				first = 14;
			else if (row == 4)
				first = 15;
		}
#endif
#ifdef EXTRA_CREDIT // for the extra credit
		// sets value for the first vertex
		char intersection = NULL; // used to determine intersection letter
		int row; // used for interest number
		cout << "Enter 0 for the row or Q for the intersection to quit\n";
		cout << "From Intersection (enter column from A to D): ";
		cin >> intersection;

		// validates the user inputs an acceptable value for intersection
		while (toupper(intersection) != 'A' && toupper(intersection) != 'B'
			&& toupper(intersection) != 'C' && toupper(intersection) != 'D' && toupper(intersection) != 'Q')
		{
			cout << "Invalid Character\n";
			cin >> intersection;
		}


		cout << "Enter Row (from 1 to 4): ";
		cin >> row;

		// validates user input for row
		while (row < 0 || row > 4)
		{
			cout << "Invalid Entry\n";
			cin >> row;
		}

		// ends program if conditions are met
		// or uses interesction and row to assign correct vertex
		if (row == 0 || toupper(intersection) == 'Q')
			return 0;
		else if (toupper(intersection) == 'A')
		{
			if (row == 1)
				first = 0;
			else if (row == 2)
				first = 1;
			else if (row == 3)
				first = 2;
			else if (row == 4)
				first = 3;
		}
		else if (toupper(intersection) == 'B')
		{
			if (row == 1)
				first = 4;
			else if (row == 2)
				first = 5;
			else if (row == 3)
				first = 6;
			else if (row == 4)
				first = 7;
		}
		else if (toupper(intersection) == 'C')
		{
			if (row == 1)
				first = 8;
			else if (row == 2)
				first = 9;
			else if (row == 3)
				first = 10;
			else if (row == 4)
				first = 11;
		}
		else if (toupper(intersection) == 'D')
		{
			if (row == 1)
				first = 12;
			else if (row == 2)
				first = 13;
			else if (row == 3)
				first = 14;
			else if (row == 4)
				first = 15;
		}
#endif
#ifdef AIRLINE_SAMPLE // for airline sample
		cout << "Enter -1 to quit\n";
		cout << "From city (enter number from 0 to " << Map.size() - 1 << "): ";
		cin >> first;
#endif
		if (first >= Map.size() || first < 0)
		{
			cout << "Illegal entry\n";
			continue;
		}
		if (first == -1)
			break;
		cout << "From " << Map.Vertex_Names[first];
#ifdef BOOK_SAMPLE // for textbook sample
		cout << " To Vertex? (from 1 to " << Map.size() << "): ";
		cin >> second;
		--second; // set actual index
#endif
#ifdef TRAFFIC // for the traffic project
		// will get the value for the second vertex
		cout << " to Intersection (enter column from A to D): ";
		cin >> intersection;
		
		// validates the user inputs an acceptable value for intersection
		while (toupper(intersection) != 'A' && toupper(intersection) != 'B'
			&& toupper(intersection) != 'C' && toupper(intersection) != 'D')
		{
			cout << "Invalid Character\n";
			cin >> intersection;
		}

		cout << "Enter Row (from 1 to 4): ";
		cin >> row;
		
		// validates user input for row
		while (row < 0 || row > 4)
		{
			cout << "Invalid Entry\n";
			cin >> row;
		}

		// ends program if conditions are met
		// or uses interesction and row to assign correct vertex
		if (row == 0)
			return 0;
		else if (toupper(intersection) == 'A')
		{
			if (row == 1)
				second = 0;
			else if (row == 2)
				second = 1;
			else if (row == 3)
				second = 2;
			else if (row == 4)
				second = 3;
		}
		else if (toupper(intersection) == 'B')
		{
			if (row == 1)
				second = 4;
			else if (row == 2)
				second = 5;
			else if (row == 3)
				second = 6;
			else if (row == 4)
				second = 7;
		}
		else if (toupper(intersection) == 'C')
		{
			if (row == 1)
				second = 8;
			else if (row == 2)
				second = 9;
			else if (row == 3)
				second = 10;
			else if (row == 4)
				second = 11;
		}
		else if (toupper(intersection) == 'D')
		{
			if (row == 1)
				second = 12;
			else if (row == 2)
				second = 13;
			else if (row == 3)
				second = 14;
			else if (row == 4)
				second = 15;
		}
#endif
#ifdef EXTRA_CREDIT // for the extra credit
		// will get the value for the second vertex
		cout << " to Intersection (enter column from A to D): ";
		cin >> intersection;

		// validates the user inputs an acceptable value for intersection
		while (toupper(intersection) != 'A' && toupper(intersection) != 'B'
			&& toupper(intersection) != 'C' && toupper(intersection) != 'D')
		{
			cout << "Invalid Character\n";
			cin >> intersection;
		}

		cout << "Enter Row (from 1 to 4): ";
		cin >> row;

		// validates user input for row
		while (row < 0 || row > 4)
		{
			cout << "Invalid Entry\n";
			cin >> row;
		}

		// ends program if conditions are met
		// or uses interesction and row to assign correct vertex
		if (row == 0)
			return 0;
		else if (toupper(intersection) == 'A')
		{
			if (row == 1)
				second = 0;
			else if (row == 2)
				second = 1;
			else if (row == 3)
				second = 2;
			else if (row == 4)
				second = 3;
		}
		else if (toupper(intersection) == 'B')
		{
			if (row == 1)
				second = 4;
			else if (row == 2)
				second = 5;
			else if (row == 3)
				second = 6;
			else if (row == 4)
				second = 7;
		}
		else if (toupper(intersection) == 'C')
		{
			if (row == 1)
				second = 8;
			else if (row == 2)
				second = 9;
			else if (row == 3)
				second = 10;
			else if (row == 4)
				second = 11;
		}
		else if (toupper(intersection) == 'D')
		{
			if (row == 1)
				second = 12;
			else if (row == 2)
				second = 13;
			else if (row == 3)
				second = 14;
			else if (row == 4)
				second = 15;
		}
#endif
#ifdef AIRLINE_SAMPLE // for airline sample
		cout << " to city? (from 0 to " << Map.size() - 1 << "): ";
		cin >> second;
#endif
		if (second >= Map.size() || second < 0)
		{
			cout << "Illegal entry\n";
			continue;
		}
		else
			cout << Map.Vertex_Names[second] << endl; // display destination
		Map.compute_itinerary(first, second);
	} // end of while loop

	system("pause");
	return 0;
}
