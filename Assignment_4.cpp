/*
By Jarrod Merryman
cs189
This program will create a user inputted AVL Tree then search for a certain value and show you the amount of node, leaf nodes, and full nodes 
in the tree
*/

// FILE: Driver.cpp
#include "AVLtree.h"
#include "cinNbr.h"

// FUNCTION PROTOTYPES:

// enter a number from keyboard (templatized for numeric types):
template <typename T>
void cinNbr(T&);

// function to setup console window:
void SetWindow(const int Width, const int Height);

int countNodes(AvlTree T);
int countLeaves(AvlTree T);
int countFullNodes(AvlTree T);

// Retrieve the data from AvlTree in a two-dimensional vector.
// Only used with small amount of data:
void Generate_Display(AvlTree T, vector< vector<int> > & Display, const int nbrLines, const int nbrColumns);

// Display tree containing small amount of data:
void display(const AvlTree T);

int main()
{
	HWND consoleWindow = GetConsoleWindow(); // set the console position at 0 , 50
	SetWindowPos(consoleWindow, 0, 0, 50, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	const int ConsoleWidth = 205;
	const int ConsoleHeight = 50;
	SetWindow(ConsoleWidth, ConsoleHeight); //This sets the size of the console

	AvlTree T;
	T = ClearTree(NULL); // set T to NULL
	cout << "Enter the original number of elements to be stored (1 to "
		<< MAX_COUNT << ", display tree with up to " << MAX_DISPLAY << "): ";
	cinNbr(ctrElements);
	size_t max_var;
	if (ctrElements > MAX_COUNT)
		ctrElements = MAX_COUNT;
	if (ctrElements <= MAX_DISPLAY)
		max_var = MAX_DISPLAY; // for display limitations only;
	else
		max_var = MAX_COUNT;

	int* Numbers; // pointer to dynamic array
	try // check if memory allocation OK
	{
		Numbers = new int[ctrElements];
	}
	// if memory allocation failed:
	catch (...) // executes in case of exception (error)
	{
		cout << "Error encountered... quitting, sorry!\n";
		system("pause");
		exit(EXIT_FAILURE); // quit
	}

	// ******** experiment with the 2 different ways to populate the tree *******
	// by commenting or uncommenting the statement below:
	//#define ASCENDING // ************ to be commented for exercise 4 ***********

/*
#ifdef ASCENDING
	 populate complete AVL tree at once (ascending)
	for (size_t i = 0; i < ctrElements; i++) // create array of numbers
		Numbers[i] = i + 1;
	
#else
	// by selecting an original number of elements = 16 and no additional values,
	// the following sequences recreate the example from our textbook:
	// populate lower half of AVL tree (ascending)
	for (size_t i = 0; i < (ctrElements - 1) / 2; i++)
		Numbers[i] = i + 1;
	// populate higher half of AVL tree (descending)
	for (size_t j = (ctrElements - 1) / 2; j < ctrElements; j++)
		Numbers[j] = ctrElements + (((ctrElements - 1) / 2) - j);
#endif
	// **************************************************************************
	

	if (ctrElements <= MAX_DISPLAY)
	{
		cout << "Original values:\n";
		for (size_t i = 0; i < ctrElements; i++) // display numbers
		{
			cout.fill(' ');
			if (i % 40 == 0 && i != 0)
				cout << endl;
			cout << setw(3) << Numbers[i] << " ";
		}
		cout << endl;
	}

	// populate AVL tree:
	for (size_t ctr = 0; ctr < ctrElements; ctr++)
		Insert(Numbers[ctr], T);
*/
	if (ctrElements < max_var) // add more values?
	{
		if (max_var <= MAX_DISPLAY)
			cout << "\nInsert more integers (between -99 and 99 for display limitations)?\n";
		else
			cout << "\nInsert more integers (between " << MININT << " and " << MAXINT << ")?\n";
		cout << "Separate entries by a space, \"c\" to continue: ";
		int val = 0;
		while (ctrElements < max_var) // and while valid integer is entered
		{
			cin >> val;
			if (cin.fail() == false)
			{
				Insert(val, T);
				ctrElements++;
			}
			else
				break; // invalid input
		}
		cin.clear(); // clear and ignore bad input
		cin.ignore(80, '\n');
	} // end of adding more values

	if (ctrElements >= max_var)
		cout << "\nMaximum of " << max_var << " values has been reached!\n";

	if (max_var <= MAX_DISPLAY)
	{
		cout << "\nFinal values stored on tree:\n";
		inorder_print(T);
		cout << endl;
	}

	display(T); // display statistics and tree if not too large

	Position found = NULL;
	int calls = 0;
	cout << "Enter a value to be searched: ";
	int target; // experiment with different cases
	cinNbr(target);

	found = Find(target, T, calls);
	if (found != NULL)
		cout << target << " found at Height " << found->Height << endl;
	else
		cout << target << " not found\n";
	double log2 = log10(ctrElements) / log10(2); // convert to log base 2
	cout << "AVL Tree, number of elements (n): " << ctrElements << "	calls: " << calls <<
		"	log base 2 of n: " << log2 << endl << endl;

	// EXERCISE 4: ******************************************************************
	cout << "EXERCISE 4:\n";
	int ctrNodes = 0;
	cout << "Counting nodes result: " << countNodes(T) << endl;
	ctrNodes = 0;
	cout << "Counting leaves result: " << countLeaves(T) << endl;
	ctrNodes = 0;
	cout << "Counting full nodes result: " << countFullNodes(T) << endl << endl;
	//**************************************************************************

	delete[] Numbers; // release array from the freestore
	ClearTree(T); // release memory on the freestore and set T to NULL
	system("pause");
	return 0;
}

/*
// enter a number from keyboard (templatized for numeric types):
template<typename T>
void cinNbr(T& var)
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
*/

// function to setup console window:
void SetWindow(const int Width, const int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);  	// Get Handle
	SetConsoleScreenBufferSize(Handle, coord);        	// Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);        	// Set Window Size
}

// Retrieve the data from AvlTree in a two-dimensional vector.
// Only used with small amount of data:
void Generate_Display(AvlTree T, vector< vector<int> > & Display, const int nbrLines, const int nbrColumns)
{
	AdjustHeights(T); // will move the nodes as high as possible
	static int ColumnCtr[7] = { 0 }; // keep track of last value for each line (max. 7 lines)
	if (T != NULL)
	{
		int line = nbrLines - T->Height - 1;
		int increment = nbrColumns / (int)pow(2, line); // 64 for line 0, 2 for lines 5 & 6
		int nextIndex = (increment / 2) + (ColumnCtr[line]++ * increment);
		if (nextIndex < nbrColumns)
			Display[line][nextIndex] = (T->data); // save data on corresponding line

		if (T->Left != NULL) // next left node present
			Generate_Display(T->Left, Display, nbrLines, nbrColumns);
		else if (line < nbrLines - 1) // save empty (9999) on left children if applicable
		{
			int tmpIncrement = increment / 2;
			int tmpLine = line + 1;
			int tmpIndex = (tmpIncrement / 2) + (ColumnCtr[tmpLine]++ * tmpIncrement);
			if (tmpIndex < nbrColumns)
				Display[tmpLine][tmpIndex] = 9999; // save empty (9999) on left
			if (tmpLine < nbrLines - 1)
			{
				tmpLine++;
				tmpIncrement /= 2; // 64 for line 0, 1 for line 6
				tmpIndex = (tmpIncrement / 2) + (ColumnCtr[tmpLine]++ * tmpIncrement);
				if (tmpIndex < nbrColumns)
					Display[tmpLine][tmpIndex] = 9999; // save empty (9999) on left
				tmpIndex = (tmpIncrement / 2) + (ColumnCtr[tmpLine]++ * tmpIncrement);
				if (tmpIndex < nbrColumns)
					Display[tmpLine][tmpIndex] = 9999; // save empty (9999) on right
			}
		}

		if (T->Right != NULL) // next right node present
			Generate_Display(T->Right, Display, nbrLines, nbrColumns);
		else if (line < nbrLines - 1) // save empty (9999) on right children if applicable
		{
			int tmpIncrement = increment / 2;
			int tmpLine = line + 1;
			int tmpIndex = (tmpIncrement / 2) + (ColumnCtr[tmpLine]++ * tmpIncrement);
			if (tmpIndex < nbrColumns)
				Display[tmpLine][tmpIndex] = 9999; // save empty (9999) on right
			if (tmpLine < nbrLines - 1)
			{
				tmpLine++;
				tmpIncrement /= 2; // 64 for line 0, 1 for line 6
				tmpIndex = (tmpIncrement / 2) + (ColumnCtr[tmpLine]++ * tmpIncrement);
				if (tmpIndex < nbrColumns)
					Display[tmpLine][tmpIndex] = 9999; // save empty (9999) on left
				tmpIndex = (tmpIncrement / 2) + (ColumnCtr[tmpLine]++ * tmpIncrement);
				if (tmpIndex < nbrColumns)
					Display[tmpLine][tmpIndex] = 9999; // save empty (9999) on right
			}
		}
	}
}

// Display tree containing small amount of data:
void display(const AvlTree T)
{
	int min = Retrieve(FindMin(T));
	cout << "\nMin is " << min << "   ";
	int max = Retrieve(FindMax(T));
	cout << "Max is " << max << endl;
	cout << "Total number of values is " << ctrElements << endl << endl;

	// only used with small amount of data:
	if (ctrElements <= MAX_DISPLAY)
	{
		const int nbrLines = (T->Height) + 1;
		const int nbrColumns = 64;
		// vector of vectors of int with value set to empty (9999):
		vector< vector<int> > Display(nbrLines, vector<int>(nbrColumns, 9999));
		Generate_Display(T, Display, nbrLines, nbrColumns);
		HANDLE console_handle;
		console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
		int Current_Row = 20; // defines which line the display resumes
		int Current_Column = 0;
		COORD cursor_coord;
		cursor_coord.X = 0;
		cursor_coord.Y = Current_Row;

		for (int i = 0; i < nbrLines; i++)
		{
			Current_Row += 2;
			cursor_coord.Y = Current_Row;
			cursor_coord.X = 0;
			SetConsoleCursorPosition(console_handle, cursor_coord);
			cout << "Height " << nbrLines - 1 - i << ": ";
			if (i == nbrLines - 1) // last row
				cout << " ";
			for (int j = 0; j < nbrColumns; j++)
			{
				if (Display[i][j] == 9999) // empty element
					cout << "   ";
				else
					cout << setw(3) << setfill(' ') << Display[i][j];
			}
			cout << endl;
		}
		cout << "\n\n";
	}
}

/* 
This function will count all the nodes in the AVL Tree
*/
int countNodes(AvlTree T)
{
	if (T == NULL) // Tree is empty
		return 0;
	else // Node and continue left and right
		return 1 + countNodes(T->Left) + countNodes(T->Right);

}

/*
This function will count all the leaf nodes in the AVL Tree
*/
int countLeaves(AvlTree T)
{
	if (T == NULL) // Tree is empty
		return 0;
	else if ((T->Left == NULL) && (T->Right == NULL)) // Leaf
		return 1;
	else // Next Node Left and Right
		return (countLeaves(T->Left) + countLeaves(T->Right));
}

/*
This function will count all the full nodes in the AVL Tree
*/
int countFullNodes(AvlTree T)
{
	if (T == NULL) // Tree is empty
		return 0;
	else if ((T->Left == NULL) && (T->Right == NULL)) // Leaf
		return 0;
	else if ((T->Left != NULL) && (T->Right != NULL)) //Full Node
		return 1 + countFullNodes(T->Left) + countFullNodes(T->Right);
	else if ((T->Left == NULL) && (T->Right != NULL)) // Left node empty
		return countFullNodes(T->Right);
	else if ((T->Left != NULL) && (T->Right == NULL)) // Right node empty
		return countFullNodes(T->Left);
}
