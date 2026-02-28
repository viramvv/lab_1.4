#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

// Функція для зміни розміру масиву (якщо книги закінчилися)
// Book*& arr — передаємо покажчик за посиланням, щоб змінити його адресу
void resizeArray(Book*& arr, int& capacity) {
    int newCapacity = capacity * 2; // Збільшуємо місткість вдвічі
    Book* newArr = new Book[newCapacity]; // Створюємо новий, більший масив

    // Копіюємо всі книги зі старого масиву в новий
    for (int i = 0; i < capacity; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;    // Видаляємо старий маленький масив
    arr = newArr;    // Тепер 'library' вказує на новий великий масив
    capacity = newCapacity;
    cout << "(Система: Пам'ять розширено до " << capacity << " місць)\n";
}

// Класична бульбашка для сортування
void sortBooks(Book* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].getYear() > arr[j + 1].getYear()) {
                Book temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int capacity = 2; // Почнемо з маленького розміру, щоб перевірити розширення
    int count = 0;
    Book* library = new Book[capacity]; // Початковий динамічний масив

    int choice;
    do {
        cout << "\n--- ДОМАШНЯ БІБЛІОТЕКА (Варіант 14*) ---\n";
        cout << "1. Додати книгу\n";
        cout << "2. Видалити книгу (за номером)\n";
        cout << "3. Список усіх книг\n";
        cout << "4. Пошук за автором\n";
        cout << "5. Сортувати за роком\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            // Перевірка: якщо масив заповнений, розширюємо його
            if (count == capacity) {
                resizeArray(library, capacity);
            }
            library[count].Read();
            count++;
        }
        else if (choice == 2) {
            if (count > 0) {
                int index;
                cout << "Введіть номер книги для видалення (1-" << count << "): ";
                cin >> index;
                if (index >= 1 && index <= count) {
                    // Зсуваємо всі книги після видаленої вліво
                    for (int i = index - 1; i < count - 1; i++) {
                        library[i] = library[i + 1];
                    }
                    count--;
                    cout << "Книгу видалено.\n";
                } else cout << "Невірний номер!\n";
            } else cout << "Бібліотека порожня.\n";
        }
        else if (choice == 3) {
            for (int i = 0; i < count; i++) {
                cout << i + 1 << ". ";
                library[i].Display();
            }
        }
        else if (choice == 4) {
            string author;
            cout << "Введіть автора: ";
            cin.ignore();
            getline(cin, author);
            for (int i = 0; i < count; i++) {
                if (library[i].getAuthor() == author) library[i].Display();
            }
        }
        else if (choice == 5) {
            sortBooks(library, count);
            cout << "Відсортовано.\n";
        }

    } while (choice != 0);

    delete[] library; // Звільнення пам'яті
    return 0;
}