#include "Book.h"
#include <sstream> // Для роботи з toString

// Конструктор за замовчуванням (обнуляє поля)
Book::Book() : title(""), author(""), year(0) {}

// Реалізація сетера для року з перевіркою на коректність
void Book::setYear(int y) {
    if (y > 0 && y <= 2026) {
        year = y;
    } else {
        year = 0; // Якщо некоректно - ставимо 0
    }
}

// Сетери для тексту
void Book::setTitle(std::string t) { title = t; }
void Book::setAuthor(std::string a) { author = a; }

// Метод ініціалізації: повертає true, якщо дані пройшли перевірку
bool Book::Init(std::string t, std::string a, int y) {
    setTitle(t);
    setAuthor(a);
    if (y > 0 && y <= 2026) {
        year = y;
        return true;
    }
    year = 0; // Захист від некоректного року
    return false;
}

// Введення даних користувачем
void Book::Read() {
    std::string t, a;
    int y;
    std::cout << "Назва книги: ";
    std::cin.ignore(); // Очищуємо буфер після cin >> choice
    std::getline(std::cin, t); // Читаємо рядок з пробілами
    std::cout << "Автор: ";
    std::getline(std::cin, a);
    std::cout << "Рік видання: ";
    std::cin >> y;

    // Викликаємо Init для безпечного присвоєння
    if (!Init(t, a, y)) {
        std::cout << "[Помилка]: Рік вказано невірно!\n";
    }
}

// Виведення даних через toString
void Book::Display() const {
    std::cout << toString() << std::endl;
}

// Формування красивого рядка з даними про книгу
std::string Book::toString() const {
    std::stringstream ss;
    ss << "Книга: \"" << title << "\" | Автор: " << author << " | Рік: " << year;
    return ss.str();
}