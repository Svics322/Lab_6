#pragma once

#include<vector>

class Graph {
private:
	
	/*N  - кількість вершин графу
	 M  - кількість ребер графу*/

	size_t N, M;	
	std::vector <std::pair<unsigned int, unsigned int>> E;

	unsigned int Introduction();
	unsigned int Action();

	void Clean();
public:
	void makeAction();

	void setVerticesCount(const unsigned int& N) { this->N = N; };
	void setEdgesCount(const unsigned int& M) { this->M = M; };
	void setEdges(const std::vector <std::pair<unsigned int, unsigned int>>& E) { this->E = E; };

	Graph();

	void printIncidenceMatrix() const;
	void printAdjacencyMatrix() const;

};