// GraphTutorial.cpp : Creates a directed, unweighted graph.
//

#include "stdafx.h"
#include "CSC382Graph_NodeBased.h"
#include "CSC382Graph_AdjacencyList.h"
#include <iostream>

using namespace std;

bool Testing_NodeBased()
{
	bool Testing = true;
	int value = 0;
	int valueNode = 0;
	// Test CSC382Graph_NodeBased Constructor(s)
	cout << "This is the default constructors in integers.";
	//Requires both the Graph_Vertex and NodeBased Class
	CSC382Graph_Vertex<int> gVertex1(1);
	CSC382Graph_Vertex<int> gVertex2(2);
	CSC382Graph_Vertex<int> gVertex3(3);
	CSC382Graph_NodeBased<int> nBased;

	cout << "\n\nUsing the functions from the Node Based Class";
	// Test functions of the CSC382Graph_NodeBased class and affiliated classes
	cout << "\nVertex Data: " << gVertex1.GetData() << endl;
	cout << "Set the new data to 5." << endl;
	gVertex1.SetData(5);
	cout << "\nVertex Data: " << gVertex1.GetData();

	//Add Edge
	cout << "\nAdding Edges" << endl;
	nBased.AddEdge(&gVertex1, &gVertex2);
	nBased.AddEdge(&gVertex1, &gVertex3);
	nBased.RemoveEdge(&gVertex1, &gVertex2);
	nBased.RemoveEdge(&gVertex1, &gVertex3);

	//Remove Vertices test

	nBased.RemoveVertex(&gVertex1);
	nBased.RemoveVertex(&gVertex2);
	cout << "Enter to continue." << endl;
	system("pause");
	while (Testing)
	{
		cout << "\nEnter the number that contains the data and hit 10 to finish: ";
		cin >> value;
		if (value != 10)
		{
			if (nBased.FindVertex(value) == nullptr)
			{
				nBased.Insert(value);
			}
			else
			{
				cout << "\nEnter a new value.";
			}
		}
		else
		{
			Testing = false;
		}
	}
	//How many Nodes based on the graph size.
	cout << "\nNodes: " << nBased.Size() << endl;

	cout << "Test functions are done." << endl;
	cout << "Enter to continue." << endl;
	system("pause");
	// Test creating lots of nodes and edges
	cout << "\nPutting lots of Nodes and Edges for the remaining size" << endl;
	CSC382Graph_Vertex<int>* tempVertex = nullptr;
	
	for (int i = 1; i < 20; i++)
	{
		//Temp pointer equals to Insert
		CSC382Graph_Vertex<int>* temp = nBased.Insert(i);
		if (tempVertex != nullptr)
		{
			nBased.AddEdge(temp, tempVertex);
		}
		//Connect them as an edge
		tempVertex = temp;
		//Counts how many nodes in a graph
		cout << "Nodes: " << nBased.Size() << endl;
	}
	return false;
}
//Testing AdjacencyList
bool Testing_AdjacencyList()
{
	// Test CSC382Graph_AdjacencyList Constructor(s)
	CSC382Graph_AdjacencyList<int> AL1;

	// Test functions of the CSC382Graph_AdjacencyList class
	//Adding Vertices and Edges
	AL1.AddVertex(1);
	AL1.AddVertex(2);
	AL1.AddVertex(3);
	AL1.AddVertex(4);
	AL1.AddVertex(5);
	AL1.AddVertex(6);
	AL1.AddVertex(7);
	AL1.AddVertex(8);
	AL1.AddVertex(9);
	AL1.AddVertex(10);
	AL1.AddVertex(11);
	AL1.AddVertex(12);
	AL1.AddVertex(13);
	AL1.AddVertex(14);
	AL1.AddVertex(15);
	AL1.AddVertex(16);
	AL1.AddVertex(17);
	AL1.AddVertex(18);
	AL1.AddVertex(19);
	AL1.AddVertex(20);
	AL1.AddEdge(AL1.FindVertex(1), AL1.FindVertex(2));
	AL1.AddEdge(AL1.FindVertex(2), AL1.FindVertex(1));
	AL1.AddEdge(AL1.FindVertex(3), AL1.FindVertex(2));
	AL1.AddEdge(AL1.FindVertex(4), AL1.FindVertex(3));
	AL1.AddEdge(AL1.FindVertex(5), AL1.FindVertex(1));
	AL1.AddEdge(AL1.FindVertex(7), AL1.FindVertex(5));
	AL1.AddEdge(AL1.FindVertex(8), AL1.FindVertex(12));
	AL1.AddEdge(AL1.FindVertex(9), AL1.FindVertex(5));
	AL1.AddEdge(AL1.FindVertex(20), AL1.FindVertex(12));
	AL1.AddEdge(AL1.FindVertex(12), AL1.FindVertex(11));
	AL1.AddEdge(AL1.FindVertex(3), AL1.FindVertex(19));
	AL1.AddEdge(AL1.FindVertex(14), AL1.FindVertex(13));
	AL1.AddEdge(AL1.FindVertex(11), AL1.FindVertex(14));
	AL1.AddEdge(AL1.FindVertex(19), AL1.FindVertex(20));
	AL1.AddEdge(AL1.FindVertex(18), AL1.FindVertex(12));
	AL1.AddEdge(AL1.FindVertex(17), AL1.FindVertex(16));
	// Test creating lots of nodes and edges
	cout << "\nPutting lots of Nodes and Edges" << endl;
	AL1.PrintAdjacencyList();
	cout << "\nNumber of Edges: " << AL1.NumberOfEdges(1);
	cout << "\nGraph Size: " << AL1.GraphSize();
	return false;
}

int main()
{
	// Call testing functions
	//Initial is choice 
	int choice = 0;
	int value = 0;
	do
	{
		cout << "\n**************\n";
		cout << "\n1. Do the Graph Vertex Node Based";
		cout << "\n2. Do Adjacency List";
		cout << "\n3. Exit";
		cout << "\n\nPlease enter the # listed above: ";
		cin >> choice;
		switch (choice)
		{
			//Find function
			case 1:
			{
				Testing_NodeBased();
				break;
			}
			case 2:
			{
				Testing_AdjacencyList();
				break;
			}
		}
	}
	//While choosing five.
	while (choice != 3);
	system("pause");
	return 0;
}

