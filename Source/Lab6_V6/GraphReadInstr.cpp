#include"GraphReadInstr.h"
#include"PathUtil.h"
#include<iostream>

#include<locale>
#include<sstream>

// ANSI-escape codes для кольорового тексту (залежить від підтримки вашої консолі)
#define RESET   L"\033[0m"
#define BOLD    L"\033[1m"
#define RED     L"\033[31m"
#define GREEN   L"\033[32m"
#define YELLOW  L"\033[33m"
#define BLUE    L"\033[34m"

std::wstring inputFileNPath() {
    std::locale::global(std::locale("uk_UA.UTF-8"));

    std::wstring path;
    while (true) {
        std::wcout << BOLD << YELLOW << L"Введіть шлях включаючи назву файлу, що містить граф з розширенням: " << RESET;
        std::getline(std::wcin, path);        
        if (!FileValidator::existFile(path)) {
            std::wcout << RED << L"Невірний шлях, файлу що містить граф немає за таким шляхом. Спробуйте ще раз.\n" << RESET;
            continue;
        }
        break;
    }
    return path;
}
