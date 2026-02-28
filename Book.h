#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
private:
    // Закриті поля (інкапсуляція) - доступ до них лише через методи класу
    std::string title;  // Назва книги
    std::string author; // Автор
    int year;           // Рік видання

public:
    // Конструктори (створення об'єкта)
    Book();
    Book(std::string t, std::string a, int y);

    // Методи доступу (getters - для читання, setters - для запису)
    std::string getTitle() const { return title; }
    void setTitle(std::string t);

    std::string getAuthor() const { return author; }
    void setAuthor(std::string a);

    int getYear() const { return year; }
    void setYear(int y);


    // Метод ініціалізації: перевіряє дані та встановлює значення
    bool Init(std::string t, std::string a, int y);

    // Метод введення з клавіатури
    void Read();

    // Метод виведення на екран
    void Display() const;

    // Метод перетворення даних у рядок
    std::string toString() const;
};

#endif