#include"GraphAddInstr.h"
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

std::wstring inputPath() {
    std::locale::global(std::locale("uk_UA.UTF-8"));

    std::wstring path;
    while (true) {
        std::wcout << BOLD << YELLOW << L"Введіть шлях до каталогу: " << RESET;
        std::getline(std::wcin, path);                
        if (!FileValidator::existDir(path)) {
            std::wcout << RED << L"Невірний шлях. Спробуйте ще раз.\n" << RESET;
            continue;
        }
        break;
    }
    return path;
}

std::wstring inputName(std::wstring dir) {
    std::locale::global(std::locale("uk_UA.UTF-8"));

    std::wstring name;
    while (true) {
        std::wcout << BOLD << YELLOW << L"Введіть назву файлу де буде зберігатись граф, без розширення: " << RESET;
        std::getline(std::wcin, name);        
        if (!FileValidator::isValidFileName(name, dir)) {
            std::wcout << RED << L"Невірна назва файлу. Спробуйте ще раз.\n" << RESET;
            continue;
        }
        break;
    }
    return name;
}

unsigned int getVerticesCount() {
    std::wstring input;
    unsigned int numVertices;
    while (true) {
        std::wcout << BOLD << YELLOW << L"Введіть кількість вершин графу (як мінімум 1): " << RESET;
        std::getline(std::wcin, input);        
        std::wstringstream ss(input);
        long tempVertices;
        if (!(ss >> tempVertices) || tempVertices < 1 || tempVertices > std::numeric_limits<unsigned int>::max()) {
            std::wcout << RED << L"Невірна кількість вершин. Спробуйте ще раз.\n" << RESET;
            continue;
        }
        numVertices = static_cast<unsigned int>(tempVertices);
        break;
    }
    return numVertices;
}

unsigned int getEdgesCount(unsigned int verticesCount) {
    std::wstring input;
    unsigned int numEdges;
    uint64_t maxEdges = verticesCount * verticesCount;
    while (true) {
        std::wcout << BOLD << YELLOW << L"Введіть кількість ребер графу (як мінімум 1 і не більше " << maxEdges << L"): " << RESET;
        std::getline(std::wcin, input);
        
        std::wstringstream ss(input);
        long tempEdges;
        if (!(ss >> tempEdges) || tempEdges < 1 || tempEdges > maxEdges) {
            std::wcout << RED << L"Невірна кількість ребер. Спробуйте ще раз.\n" << RESET;
            continue;
        }

        numEdges = static_cast<unsigned int>(tempEdges);
        break;
    }
    return numEdges;
}

std::vector<std::pair<unsigned int, unsigned int>> getEdges(unsigned int vertices, unsigned int edges) {
    std::vector<std::pair<unsigned int, unsigned int>> edgeList;
    std::wstring input;
    unsigned int u, v;

    for (long i = 0; i < edges; ++i) {
        while (true) {
            std::wcout << BOLD << YELLOW << L"Введіть ребро " << i + 1 << L" у форматі 'u v': " << RESET;
            std::getline(std::wcin, input);
            std::wstringstream ss(input);
            if (!(ss >> u >> v) || u < 1 || u > vertices || v < 1 || v > vertices) {
                std::wcout << RED << L"Невірне ребро. Спробуйте ще раз.\n" << RESET;
                continue;
            }
            if (auto it = std::find(edgeList.begin(), edgeList.end(), std::make_pair(u, v)); it != edgeList.end()) {
                size_t index = std::distance(edgeList.begin(), it) + 1;
                std::wcerr << RED << L"Помилка у структурі графу у файлі." << std::endl;
                std::wcerr << L"Ребра не повинні повторюватись." << std::endl;
                std::wcerr << L"Виявлено повторне значення ребра під індексом - " << index;
                std::wcerr << L" та " << (i + 1) << std::endl << L"Змініть структуру графа у файлі або виберіть ";
                std::wcerr << L"інший коректний файл графа!" << RESET << std::endl;
                continue;
            }
            edgeList.emplace_back(u, v);
            break;
        }
    }

    return edgeList;
}