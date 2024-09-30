#pragma once

#include"Graph.h"
#include"GraphReadInstr.h"

#include<string>
#include<fstream>
#include<vector>

static class GraphReader {
private:
	static std::wstring openFile() { return inputFileNPath(); };

	static bool readVerticesCount(const std::wstring& line, unsigned int& value);
	static bool readEdgesCount(const std::wstring& line, unsigned int& value, unsigned int verticesCount);

	static bool readEdgeStartPoint(const std::wstring& line, unsigned int& value,
		const unsigned int edgeIndex, const unsigned int verticesCount);

	static bool readEdgeEndPoint(const std::wstring& line, unsigned int& value,
		const unsigned int edgeIndex, const unsigned int verticesCount);

	static bool readEdges(std::wifstream& file, 
		std::vector<std::pair<unsigned int, unsigned int>>& edges, const unsigned int verticesCount);

	static void initGraph(const std::wstring& path, Graph& obj);
public:
	static void ReadGraph(Graph obj);
};