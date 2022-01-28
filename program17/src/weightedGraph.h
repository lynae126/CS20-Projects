#ifndef H_weightedGraph
#define H_weightedGraph
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cfloat>
#include "graphType.h"
using namespace std;

/*
-----------------------------------
		weightedGraphType
-----------------------------------
# weights : double **
# smallestWeight : double *
-----------------------------------
+ weightedGraphType(int size = 0)
+ ~weightedGraphType()
+ createWeightedGraph(string) : void
+ shortestPath(int vertex) : void
+ printShortestDistance(int vertex) : void
-----------------------------------
*/
class weightedGraphType: public graphType{
	protected:
		double **weights;   //pointer to create weight matrix
		double *smallestWeight; //pointer to create the array to store the smallest weight from source to vertices
	public:
		weightedGraphType(int size = 0);
		  //Constructor
		  //Postcondition: gSize = 0; maxSize = size;
		  //    graph is an array of pointers to linked lists.
		  //    weights is a two-dimensional array to store the weights
		  //       of the edges.
		  //    smallestWeight is an array to store the smallest weight
		  //       from source to vertices.

		~weightedGraphType();
		  //Destructor
		  //The storage occupied by the vertices and the arrays
		  //weights and smallestWeight is deallocated.
		void createWeightedGraph(string);
		  //Function to create the graph and the weight matrix.
		  //Postcondition: The graph using adjacency lists and
		  //    its weight matrix is created.

		void shortestPath(int vertex);
		  //Function to determine the weight of a shortest path
		  //from vertex, that is, source, to every other vertex
		  //in the graph.
		  //Postcondition: The weight of the shortest path from vertex
		  //    to every other vertex in the graph is determined.

		void printShortestDistance(int vertex);
		  //Function to print the shortest weight from the vertex
		  //specified by the parameter vertex to every other vertex in
		  //the graph.
		  //Postcondition: The weight of the shortest path from vertex
		  //    to every other vertex in the graph is printed.
};

//createWeightedGraph(): creates graph from input file
//Arguments: fn(string) | Returns: void
void weightedGraphType::createWeightedGraph(string fn){
    ifstream infile(fn);
    if (!infile) {
        cout << "Cannot open input file." << endl;
        return;
    }

    int vertex;
    int adjacentVertex;
    infile >> gSize;

    for (int index = 0; index < gSize; index++){
        infile >> vertex;
        infile >> adjacentVertex;
        while (adjacentVertex != -999){
            graph[vertex].insertLast(adjacentVertex);
            infile >> adjacentVertex;
        }
    }

    for (int i = 0; i < gSize; i++)
        for (int j = 0; j < gSize; j++)
            weights[i][j] = DBL_MAX;

    double weight;
    infile >> vertex;
    while (infile){
        infile >> adjacentVertex;
        while (adjacentVertex != -999){
            infile >> weight;
            weights[vertex][adjacentVertex] = weight;
            infile >> adjacentVertex;
        }
        infile >> vertex;
    }
    infile.close();
}

//shortestPath(): calculates the shortest path according to shortest distance
//Arguments: vertex(int) | Returns: void
void weightedGraphType::shortestPath(int vertex){
    for (int j = 0; j < gSize; j++)
        smallestWeight[j] = weights[vertex][j];
    bool *weightFound;
    weightFound = new bool[gSize];
    for (int j = 0; j < gSize; j++)
        weightFound[j] = false;
    weightFound[vertex] = true;
    smallestWeight[vertex] = 0;

    for (int i = 0; i < gSize - 1; i++){
        double minWeight = DBL_MAX;
        int v;

        for (int j = 0; j < gSize; j++)
            if (!weightFound[j])
                if (smallestWeight[j] < minWeight){
                    v = j;
                    minWeight = smallestWeight[v];
                }
        weightFound[v] = true;
        for (int j = 0; j < gSize; j++)
            if (!weightFound[j])
                if (minWeight + weights[v][j] < smallestWeight[j])
                    smallestWeight[j] = minWeight + weights[v][j];
    }
}

//printShortestDistance(): prints the shortest distance for given graph
//Arguments: vertex(int) | Returns: void
void weightedGraphType::printShortestDistance(int vertex){
    cout << "Source Vertex: " << vertex << endl;
    cout << "Shortest distance from source to each vertex." << endl;
    cout << "Vertex  Shortest_Distance" << endl;
    for (int j = 0; j < gSize; j++)
        cout << setw(4) << j << setw(12) << smallestWeight[j] << endl;
    cout << endl;
}

//weightedGraphType(): constructor
//Arguments: size(int) | Returns: N/A
weightedGraphType::weightedGraphType(int size):graphType(size){
    weights = new double*[size];
    for (int i = 0; i < size; i++)
        weights[i] = new double[size];
    smallestWeight = new double[size];
}

//~weightedGraphType(): destructor
//Arguments: N/A | Returns: N/A
weightedGraphType::~weightedGraphType(){
    for (int i = 0; i < gSize; i++)
       delete [] weights[i];
    delete [] weights;
    delete smallestWeight;
}
#endif
