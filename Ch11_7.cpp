/* By Jarrod Merryman
	Credit to C++ Book
	This program will calculate the budget for 6 different divisions 
	on a quarterly basis and show you the total for the company.
*/
#include <iostream>
#include <iomanip>
#include "divsales.h"            // For Budget class declaration
using namespace std;

// Definition of the static member of the Budget class.
double DivSales::corpBudget = 0;

int main()
{
      const int N_DIVISIONS = 6; // Sets how many divisions there are
	  const int QUARTS = 4; // Sets how many quarters there are

	  // Initializes 6 DivSales objects in a DivSales array
	  DivSales divisions[N_DIVISIONS] =
	  {
		  DivSales(),
		  DivSales(),
		  DivSales(),
		  DivSales(),
		  DivSales(),
		  DivSales()
	  };
    
	  // Get the budget request for each division on a quarterly
	  // basis.
      for (int count = 0; count < N_DIVISIONS; count++)
      {
	      double bud;
		  cout << "Enter the budget request for division ";
		  cout << (count + 1) << ": " << endl;
		  for (int i = 0; i < QUARTS; i++)
		  {
			  cout << "What is the " << i + 1 << " quarter's budget"
				  << endl;
				  cin >> bud;
			  divisions[count].setBudget(i,bud);
			  divisions[count].addBudget(bud);
		  }
      }
		
	  // Display the budget request for each division
      cout << setprecision(2);
      cout << showpoint << fixed;
      cout << "\nHere are the division budget requests:\n";
      for (int count = 0; count < N_DIVISIONS; count++)
      {
        cout << "Division " << (count + 1) << "\t$ ";
	     cout << divisions[count].getDivBudget() << endl;
      }
		
	  // Display the total budget request
      cout << "Total Budget Requests:\t$ ";
      cout << divisions[0].getCorpBudget() << endl; 
		
	  int stop = 1; // used as a flag to end do-while

	  // User is asked if they would like to see a certain quarter's budget
	  do
	  {
		  int div;
		  int quad;
		  
		  do 
		  {
			  cout << "What division would you like to see? or input -1 to quit" << endl;
			  cin >> div;
		  } while (div < -1 || div > 6);

		  if (div != -1) 
		  {
			  div--;

			  do 
			  {
				 cout << "What quarter would you like to see?" << endl;
				 cin >> quad;
			  } while (quad < 0 || quad > 5);

			  cout << "The " << div + 1 << " division's " << quad + 1 << " quarter was " << divisions[div].getIndividual(--quad) << endl;
		  }
		  else
		  {
			 stop = 0;
		  }
			
	  } while (stop == 1);
	  
		
      return 0;
}