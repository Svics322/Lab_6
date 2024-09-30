#pragma once

#include<string>
#include<vector>

std::wstring inputPath();
std::wstring inputName(std::wstring dir);
unsigned int getVerticesCount();
unsigned int getEdgesCount(unsigned int verticesCount);
std::vector<std::pair<unsigned int, unsigned int>> getEdges(unsigned int vertices, unsigned int edges);