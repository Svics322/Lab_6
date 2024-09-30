#include"Graph.h"

#include"GraphAdding.h"
#include"GraphReader.h"
#include"InstructionUtil.h"
#include<iostream>
#include<iomanip>
#include<thread>
#include<chrono>

#define RESET   L"\033[0m"
#define BOLD    L"\033[1m"
#define RED     L"\033[31m"
#define GREEN   L"\033[32m"
#define YELLOW  L"\033[33m"
#define BLUE    L"\033[34m"

// Private

unsigned int Graph::Introduction() {
	printInstructions();
	printUserOptions();
	return handleUserInput();
}

unsigned int Graph::Action() {
	printInstructions();
	printInitUserOptions();
	return handleInitUserInput();
}

void Graph::Clean(){
	this->N = 0;
	this->M = 0;
	this->E.clear();
}
// Public

void Graph::makeAction() {
	if (this->N == 0) {
		unsigned int action = this->Introduction();
		switch (action) {
		case 1:
			return CreateGraph::Create(*this);
			break;
		case 2:
			return GraphReader::ReadGraph(*this);
			break;
		case 3:
			return;
		}
	}
	else {
		unsigned int action = this->Action();
		switch (action) {
		case 1:
			return CreateGraph::Create(*this);
			break;
		case 2:
			this->Clean();
			return GraphReader::ReadGraph(*this);
			break;
		case 3:
			this->Clean();
			return this->makeAction();
			break;
		case 4:
			this->printIncidenceMatrix();
			std::this_thread::sleep_for(std::chrono::milliseconds(10'000));
			return this->makeAction();
			break;
		case 5:
			this->printAdjacencyMatrix();
			std::this_thread::sleep_for(std::chrono::milliseconds(10'000));
			return this->makeAction();
			break;
		case 6:
			this->printIncidenceMatrix();
			std::this_thread::sleep_for(std::chrono::milliseconds(10'000));
			this->printAdjacencyMatrix();
			std::this_thread::sleep_for(std::chrono::milliseconds(10'000));
			return this->makeAction();
			break;
		case 7:
			return;
		}
	}
}

void Graph::printIncidenceMatrix() const {
	std::vector<std::vector<int>> incidenceMatrix(N, std::vector<int>(E.size(), 0));

	for (size_t i = 0; i < E.size(); ++i) {
		unsigned int u = E[i].first - 1;
		unsigned int v = E[i].second - 1;

		if (u == v) {
			incidenceMatrix[u][i] = 2;
		}
		else {
			incidenceMatrix[u][i] = -1;
			incidenceMatrix[v][i] = 1;
		}
	}
	
	std::wcout << GREEN << L"Матриця інцидентності:" << RESET << std::endl;

	std::wcout << std::setw(6) << L" "; 
	for (size_t i = 0; i < E.size(); ++i) {
		std::wcout << BLUE << std::setw(6) << L"e" << (i + 1) << RESET;
	}
	std::wcout << std::endl;
	
	std::wcout << RED << std::wstring(6, '-') << std::wstring(7 * E.size(), '-') << RESET << std::endl;
	
	for (size_t i = 0; i < N; ++i) {
		std::wcout << RED << std::setw(4) << L"v" << i + 1 << L"|" << RESET;
		for (size_t j = 0; j < E.size(); ++j) {
			if (incidenceMatrix[i][j] == 0) {
				std::wcout << BLUE << std::setw(7) << incidenceMatrix[i][j] << RESET;
			}
			else {
				std::wcout << YELLOW << std::setw(7) << incidenceMatrix[i][j] << RESET;
			}
		}
		std::wcout << std::endl;
	}
}

void Graph::printAdjacencyMatrix() const {
	std::vector<std::vector<int>> adjacencyMatrix(N, std::vector<int>(N, 0));

	for (const auto& edge : E) {
		unsigned int u = edge.first - 1;
		unsigned int v = edge.second - 1;

		adjacencyMatrix[u][v] = 1;
	}

	std::wcout << GREEN << L"Матриця суміжності:" << RESET << std::endl;

	std::wcout << std::setw(5) << " ";
	for (size_t i = 0; i < N; ++i) {
		std::wcout << BLUE << std::setw(4) << L"v" << (i + 1);
	}
	std::wcout << RESET << std::endl;

	std::wcout << RED << std::wstring(5, '-') << std::wstring(5 * N, '-') << RESET << std::endl;

	for (size_t i = 0; i < N; ++i) {
		std::wcout << RED << std::setw(3) << L"v" << i + 1 << "|" << RESET;
		for (size_t j = 0; j < N; ++j) {
			if (adjacencyMatrix[i][j] == 0) {
				std::wcout << BLUE << std::setw(5) << adjacencyMatrix[i][j] << RESET;
			}
			else {
				std::wcout << YELLOW << std::setw(5) << adjacencyMatrix[i][j] << RESET;
			}
		}
		std::wcout << std::endl;
	}
}

// Constructor

Graph::Graph() : N(0), M(0){
	this->makeAction();
}