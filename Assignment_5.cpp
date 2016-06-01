/*
This program will first output string based on the priority queue being max/min heap and then
it will show a priorty list of ducments to be printed based on high/low priority
*/

#include <iostream>
#include <queue> // to use STL priority queue
#include <functional> // Provide greater...
#include <string>
#include <iomanip>
#include "Document.h" // for the document class

using namespace std;


//#define MINHEAP // to sort in Ascending order (min Heap)

void do_string_pq(); // prints the priority queue for the strings
void do_doc_pq(); // prints the priority queue for the documents


int main()
{
	system("pause");
	do_string_pq(); // prints the priority queue for the strings
	system("pause");
	do_doc_pq(); // prints the priority queue for the documents
	return 0;
}

/*
This function will create a priority queue and push strings 
from an array into the queue then print them (either max/min heap)
*/
void do_string_pq()
{
#ifndef MINHEAP
	priority_queue<string> pq; // default descending order (max Heap)
#else
	priority_queue<string, vector<string>, greater<string> > pq; // min Heap
#endif
	string stringArr[] = {"1st String","2nd String","3rd String","4th String","5th String","6th String"};
	cout << "Here are the Strings" << endl;
	
	for (int i = 0; i < sizeof(stringArr) / sizeof(string); i++)
	{
		pq.push(stringArr[i]);
	}

	while (!pq.empty())
	{
		cout << pq.top() << "\n"; // Print highest priority integer
		pq.pop(); // Remove highest priority integer
	}
	cout << "<-----END OF STRINGS----->" << endl;
}

/*
This function will create a priority queue and push Documents
from an array into the queue then print them (either max/min heap)
*/
void do_doc_pq()
{
#ifndef MINHEAP
	priority_queue<Document> pq; // default descending order (max Heap)
#else
	priority_queue<Document, vector<Document>, greater<Document> > pq; // min Heap
#endif
	Document pinter[] = { Document (3, "first", low), Document(4, "second", high), Document(7, "third", high), Document(2, "fourth", low),
		Document(3, "first", low), Document(12, "fifth", high), Document(20, "sixth", low) };
	
	cout << "Here are the Documents" << endl;

	for (int i = 0; i < sizeof(pinter) / sizeof(Document); i++)
	{
		pq.push(pinter[i]);
	}

	while (!pq.empty())
	{
		Document temp = pq.top();
		cout << temp;
		pq.pop();
	}
}
