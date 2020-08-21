#pragma once

#include "stdafx.h"
#include <vector>
#include <list>
#include <iostream>


using namespace std;

template <typename T>
class CSC382Graph_Vertex
{
private:
	T data;
	list<CSC382Graph_Vertex<T>*>* connected_vertices;
public:
	CSC382Graph_Vertex()
	{
		connected_vertices = new list<CSC382Graph_Vertex<T>*>();
		data = NULL;
	}

	CSC382Graph_Vertex(T node_data)
	{
		connected_vertices = new list<CSC382Graph_Vertex<T>*>();
		data = node_data;
	}

	~CSC382Graph_Vertex()
	{
		delete connected_vertices;
	}

	//Add Edge
	void AddEdge(CSC382Graph_Vertex<T>* vertex_connection)
	{
		if (vertex_connection != this)
		{
			connected_vertices->push_back(vertex_connection);
		}
	}

	//Connecting Vertex
	bool VertexConnected(CSC382Graph_Vertex<T>* vertex_to_find)
	{
		for(CSC382Graph_Vertex<T>* i : *connected_vertices)
		{
			if(i == vertex_to_find)
			{
				return true;
			}
		}
		return false;
	}

	//Remove Edge
	void RemoveEdge(CSC382Graph_Vertex<T>* edge_to_remove)
	{
		if (edge_to_remove != nullptr)
		{
			connected_vertices->remove(edge_to_remove);
		}
	}


	T GetData()
	{
		return data;
	}


	void SetData(T data_param)
	{
		data = data_param;
	}

};


template <typename T>
class CSC382Graph_NodeBased
{
private:
	list<CSC382Graph_Vertex<T>*>* graph;

public:
	CSC382Graph_NodeBased()
	{
		graph = new list<CSC382Graph_Vertex<T>*>;
	}


	CSC382Graph_NodeBased(CSC382Graph_Vertex<T>* initial_vertex)
	{
		graph = new list<CSC382Graph_Vertex<T>*>;
		Insert(initial_vertex);
	}


	~CSC382Graph_NodeBased()
	{
		for (CSC382Graph_Vertex<T>* iter : *graph)
		{
			if (iter != nullptr && iter != NULL)
			{
				delete iter;
			}
		}
		delete graph;
	}

	//Insert Function
	CSC382Graph_Vertex<T>* Insert(CSC382Graph_Vertex<T>* vertex)
	{
		graph->push_back(vertex);
		return vertex;
	}

	//Insert for Node
	CSC382Graph_Vertex<T>* Insert(T data)
	{
		CSC382Graph_Vertex<T>* new_node = new CSC382Graph_Vertex<T>(data);
		return Insert(new_node);
	}

	//Remove Vertex
	void RemoveVertex(T data)
	{
		CSC382Graph_Vertex<T>* vertex_to_remove = FindVertex(data);
		RemoveVertex(vertex_to_remove);
	}

	//Remove Vertex
	void RemoveVertex(CSC382Graph_Vertex<T>* vertex_to_remove)
	{
		graph->remove(vertex_to_remove);
	}

	//Add Edge which is a line connecting to the vertices
	void AddEdge(CSC382Graph_Vertex<T>* start_vertex, CSC382Graph_Vertex<T>* end_vertex)
	{
		start_vertex->AddEdge(end_vertex);
	}


	void RemoveEdge(CSC382Graph_Vertex<T>* start_vertex, CSC382Graph_Vertex<T>* end_vertex)
	{
		start_vertex->RemoveEdge(end_vertex);
	}

	//Boolean
	bool IsEdge(CSC382Graph_Vertex<T>* vertex_to_search_in, CSC382Graph_Vertex<T>* edge_to_check_for)
	{
		return vertex_to_search_in->VertexConnected(edge_to_check_for);
	}


	CSC382Graph_Vertex<T>* FindVertex(T data_to_find)
	{
		for (CSC382Graph_Vertex<T>* iter : *graph)
		{
			if (iter->GetData() == data_to_find)
			{
				return iter;
			}
		}
		return nullptr;
	}

	//Find Vertex
	CSC382Graph_Vertex<T>* FindVertex(CSC382Graph_Vertex<T>* node_to_find)
	{
		for(CSC382Graph_Vertex<T>* iter : *graph)
		{
			if(iter == node_to_find)
			{
				return iter;
			}
		}
		return nullptr;
	}

	//Size of how many within.
	int Size()
	{
		return graph->size();
	}
};
