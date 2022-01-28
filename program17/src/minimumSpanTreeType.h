#ifndef H_msTree
#define H_msTree
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cfloat>
#include "graphType.h"
using namespace std;

/*
-----------------------------------
			msTreeType
-----------------------------------
# source : int
# weights : double **
# edges : int *
# edgeWeights : double *
-----------------------------------
+ msTreeType(int size)
+ ~msTreeType()
+ void createSpanningGraph(string) : void
+ void minimumSpanning(int sVertex) : void
+ printTreeAndWeight() : void
-----------------------------------
*/
class msTreeType: public graphType{
	protected:
		int source;
		double **weights;
		int *edges;
		double *edgeWeights;
	public:
		msTreeType(int size = 0);
		~msTreeType();

		void createSpanningGraph(string);
		  //Function to create the graph and the weight matrix.
		  //Postcondition: The graph using adjacency lists and
		  //    its weight matrix is created.

		void minimumSpanning(int sVertex);
		  //Function to create a minimum spanning tree with
		  //root as sVertex.
		  // Postcondition: A minimum spanning tree is created.
		  //     The weight of the edges is also saved in the array
		  //     edgeWeights.

		void printTreeAndWeight();
		  //Function to output the edges of the minimum spanning tree
		  //and the weight of the minimum spanning tree.
		  //Postcondition: The edges of a minimum spanning tree
		  //    and their weights are printed.
};

//createSpanningGraph(): reads file to create spanning graph
//Arguments: fn(string) | Returns: void
void msTreeType::createSpanningGraph(string fn){
    ifstream infile(fn);
    if (!infile){
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
    int weight;

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

//minimumSpanning(): calculates minimum spanning
//Arguments: sVertex(int) | Returns: void
void msTreeType::minimumSpanning(int sVertex){
    int startVertex, endVertex;
    double minWeight;
    source = sVertex;
    bool *mstv;
    mstv = new bool[gSize];

    for (int j = 0; j < gSize; j++){
        mstv[j] = false;
        edges[j] = source;
        edgeWeights[j] = weights[source][j];
    }
    mstv[source] = true;
    edgeWeights[source] = 0;

    for (int i = 0; i < gSize - 1; i++){
        minWeight = DBL_MAX;
        for (int j = 0; j < gSize; j++)
            if (mstv[j])
                for (int k = 0; k < gSize; k++)
                    if (!mstv[k] && weights[j][k] < minWeight){
                        endVertex = k;
                        startVertex = j;
                        minWeight = weights[j][k];
                    }
        mstv[endVertex] = true;
        edges[endVertex] = startVertex;
        edgeWeights[endVertex] = minWeight;
    }
}

//printTreeAndWeight(): printing minimum spanning tree weight
//Arguments: N/A | Returns: void
void msTreeType::printTreeAndWeight(){
    double treeWeight = 0;
    cout << "Source Vertex: " << source << endl;
    cout << "Edges    Weight" << endl;

    for (int j = 0; j < gSize; j++){
        if (edges[j] != j){
            treeWeight = treeWeight + edgeWeights[j];
            cout << "("<<edges[j] << ", " << j << ")    "<< edgeWeights[j] << endl;
        }
    }

    cout << endl;
    cout << "Minimum spanning tree weight: " << treeWeight << endl;
}

//msTreeType(): constructor
//Arguments: size(int) | Returns: N/A
msTreeType::msTreeType(int size):graphType(size){
    weights = new double*[size];
    for (int i = 0; i < size; i++)
        weights[i] = new double[size];
    edges  = new int[size];
    edgeWeights = new double[size];
}

//~msTreeType(): destructor
//Arguments: N/A | Returns: N/A
msTreeType::~msTreeType(){
    for (int i = 0; i < gSize; i++)
       delete [] weights[i];
    delete [] weights;
    delete [] edges;
    delete edgeWeights;
}

#endif
