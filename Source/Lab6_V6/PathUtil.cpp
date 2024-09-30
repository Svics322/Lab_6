#include"PathUtil.h"
#include"GraphAddInstr.h"

#include<fstream>
#include<iostream>

#include<thread>
#include<chrono>

#define RESET   L"\033[0m"
#define RED     L"\033[31m"
#define GREEN   L"\033[32m"

bool FileValidator::existDir(std::wstring dir) {
	return std::filesystem::exists(dir) && std::filesystem::is_directory(dir);
}

bool FileValidator::isValidFileName(std::wstring name, std::wstring dir) {
	const std::wstring invalidChars = L"<>:\"/\\|?*";
	const std::filesystem::path filePath = std::filesystem::path(dir) / (name + L".txt");
	if (std::filesystem::exists(filePath)) {
		std::wcout << RED << L"‘айл з такою назвою уже ≥снуЇ.\n" << RESET;
		return false;
	}
	return name.find_first_of(invalidChars) == std::wstring::npos;
}