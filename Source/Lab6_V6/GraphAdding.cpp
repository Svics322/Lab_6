#include"GraphAdding.h"
#include"GraphAddInstr.h"

#include<fstream>
#include<filesystem>
#include<iostream>

#include<thread>
#include<chrono>

#define RESET   L"\033[0m"
#define RED     L"\033[31m"
#define GREEN   L"\033[32m"

void CreateGraph::createFile() {
	std::wstring dir = inputPath();
	std::wstring name = inputName(dir);
	unsigned int verticesCount = getVerticesCount();
	uint64_t edgesCount = getEdgesCount(verticesCount);
	std::vector<std::pair<unsigned int, unsigned int>> edges;
	
	edges = getEdges(verticesCount, edgesCount);

	std::wstring filePath = dir + L"/" + name + L".txt";
	std::ofstream outFile(filePath);
	
	if (!outFile) {
		std::wcerr << "Не вдалося відкрити файл для запису: " << filePath<< std::endl;
		return;
	}
	outFile << verticesCount << ", " << edgesCount << std::endl;

	for (const auto& edge : edges) {
		outFile << edge.first << ", " << edge.second << std::endl;
	}

	outFile.close();

	std::wcout << GREEN << L"Файл графу за розташуванням: " << filePath;
	std::wcout << L" успішно збережено!" << RESET << std::endl;
}

void CreateGraph::Create(Graph obj) {
	createFile();

	std::this_thread::sleep_for(std::chrono::milliseconds(10'000));
	return obj.makeAction();
}