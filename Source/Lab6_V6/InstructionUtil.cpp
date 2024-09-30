#include "InstructionUtil.h"
#include <iostream>
#include <locale>
#include<conio.h>

// ANSI-escape codes для кольорового тексту (залежить від підтримки вашої консолі)
#define RESET   L"\033[0m"
#define BOLD    L"\033[1m"
#define RED     L"\033[31m"
#define GREEN   L"\033[32m"
#define YELLOW  L"\033[33m"
#define BLUE    L"\033[34m"
#define EQL     L"\u2264"

using namespace std;

void printInstructions() {
    wcout.imbue(locale("uk_UA.UTF-8"));
    
    wcout << BOLD << GREEN << L"Програма зчитує орієнтований граф з вхідного файлу.\n" << RESET;
    wcout << YELLOW << L"Файл має містити наступну структуру:" << RESET << endl;

    wcout << BLUE << L"-----------------------------------\n";
    wcout << L" n\t m\n";
    wcout << L" v1\t u1\n";
    wcout << L" v2\t u2\n";
    wcout << L"    ...\n";
    wcout << L" vm\t um\n";
    wcout << L"-----------------------------------" << RESET << endl;

    wcout << YELLOW << L"Де:" << RESET << endl;
    wcout << GREEN << L"n  " << RESET << L"- кількість вершин у графі (ціле число, більше нуля)\n";
    wcout << GREEN << L"m  " << RESET << L"- кількість ребер у графі (ціле число, більше нуля)\n";
    wcout << GREEN << L"v1 " << RESET << L"- початкова вершина ребра 1 (1 " << EQL << L" v1 ≤ n)\n";
    wcout << GREEN << L"u1 " << RESET << L"- кінцева вершина ребра 1 (1 ≤ u1 ≤ n)\n";
    wcout << YELLOW << L"Інші ребра слідують аналогічно." << RESET << endl;

    wcout << BLUE << L"-----------------------------------" << RESET << endl;
    wcout << YELLOW << L"Приклад вмісту файлу:" << RESET << endl;
    wcout << BLUE << L"4 5\n";
    wcout << L"1 2\n";
    wcout << L"2 3\n";
    wcout << L"3 4\n";
    wcout << L"4 1\n";
    wcout << L"2 4\n";
    wcout << L"-----------------------------------" << RESET << endl;

    wcout << BOLD << GREEN << L"Програма виведе зчитаний граф у форматі списку ребер.\n" << RESET;
}

void printUserOptions() {
    wcout.imbue(locale("uk_UA.UTF-8"));

    wcout << BOLD << BLUE << L"Можливості для користувача:\n" << RESET;
    wcout << GREEN << L"1. Створити файл графа\n" << RESET;
    wcout << GREEN << L"2. Зчитати файл графа\n" << RESET;    
    wcout << GREEN << L"3. Завершити роботу програми\n" << RESET;
    wcout << YELLOW << L"Виберіть опцію та введіть відповідний номер.\n" << RESET;
}

void printInitUserOptions() {
    wcout.imbue(locale("uk_UA.UTF-8"));

    wcout << BOLD << BLUE << L"Можливості для користувача:\n" << RESET;
    wcout << GREEN << L"1. Створити файл графа\n" << RESET;
    wcout << GREEN << L"2. Зчитати файл графа\n" << RESET;
    wcout << GREEN << L"3. Очистити зчитаний граф\n" << RESET;
    wcout << GREEN << L"4. Вивести матрицю інцидентності ініціалізованого графу\n" << RESET;
    wcout << GREEN << L"5. Вивести матрицю суміжності ініціалізованого графу\n" << RESET;
    wcout << GREEN << L"6. Вивести матриці інцидентності та суміжності ініціалізованого графу\n" << RESET;
    wcout << GREEN << L"7. Завершити роботу програми\n" << RESET;
    wcout << YELLOW << L"Виберіть опцію та введіть відповідний номер.\n" << RESET;
}

int handleUserInput() {
    while (true) {
        if (_kbhit()) {
            int key = _getch();
            switch (key) {
            case '1':
                wcout << GREEN << L"Ви обрали створити файл графа.\n" << RESET;                
                return ('1' - '0');
            case '2':
                wcout << GREEN << L"Ви обрали зчитати файл графа.\n" << RESET;                
                return ('2' - '0');
            case '3':
                wcout << GREEN << L"Ви обрали завершення роботи програми.\n" << RESET;                
                return ('3' - '0');
            default:
                wcout << RED << L"Невірний вибір. Спробуйте ще раз.\n" << RESET;
                break;
            }
        }
    }
    return ('0' - '0');
}

int handleInitUserInput() {
    while (true) {
        if (_kbhit()) {
            int key = _getch();
            switch (key) {
            case '1':
                wcout << GREEN << L"Ви обрали створити файл графа.\n" << RESET;
                return ('1' - '0');
            case '2':
                wcout << GREEN << L"Ви обрали зчитати файл графа.\n" << RESET;
                return ('2' - '0');
            case '3':
                wcout << GREEN << L"Ви обрали очистити ініціалізований граф.\n" << RESET;
                return ('3' - '0');
            case '4':
                wcout << GREEN << L"Ви обрали вивести матрицю інцидентності ініціалізованого графу.\n" << RESET;
                return ('4' - '0');
            case '5':
                wcout << GREEN << L"Ви обрали вивести матрицю суміжності ініціалізованого графу.\n" << RESET;
                return ('5' - '0');
            case '6':
                wcout << GREEN << L"Ви обрали вивести матрицю інцидентності та суміжності ініціалізованого графу.\n" << RESET;
                return ('6' - '0');
            case '7':
                wcout << GREEN << L"Ви обрали завершення роботи програми\n" << RESET;
                return ('7' - '0');
            default:
                wcout << RED << L"Невірний вибір. Спробуйте ще раз.\n" << RESET;
                break;
            }
        }
    }
    return ('0' - '0');
}