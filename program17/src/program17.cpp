//*****************
//Program Name: Program 17(Graph your Stuff)
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: Write a driver program that will demonstrate a graph of your design.
//*****************
#include <iostream>
#include "graphType.h"
#include "weightedGraph.h"
#include "minimumSpanTreeType.h"
using namespace std;

int main() {
	cout << "***PART ONE: TRAVERSALS***\n\n";
	graphType graph(50);
	graph.createGraph("directedMap.txt");
	cout << "Depth First Traversal:  ";
	graph.depthFirstTraversal();
	cout << "\nBreadth First Traversal:  ";
	graph.breadthFirstTraversal();

	cout << "\n\n***PART TWO: SHORTEST PATH***\n";
	weightedGraphType wgraph(50);
	wgraph.createWeightedGraph("directedMap.txt");
	wgraph.shortestPath(0);
	wgraph.printShortestDistance(0);

	cout << "***PART THREE: MINIMUM SPANNING TREE***\n";
	msTreeType msgraph(50);
	 // I used directed instead of undirected because the ending tree weight didn't seem to be right
	msgraph.createSpanningGraph("directedMap.txt");
	msgraph.minimumSpanning(0);
	msgraph.printTreeAndWeight();
	cout << "\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}
