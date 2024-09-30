#pragma once

#include<string>
#include<vector>
#include<filesystem>

static class FileValidator {
public:
	static bool existDir(std::wstring dir);
	static bool existFile(const std::wstring& filePath) { return std::filesystem::exists(filePath) && std::filesystem::is_regular_file(filePath); };
	static bool isValidFileName(std::wstring name, std::wstring dir);		
};