#include <gtest/gtest.h>
#include "Book.h"

// Тест перевіряє успішну ініціалізацію об'єкта через Init()
TEST(BookTest, InitializationSuccess) {
    Book b;
    // Очікуємо true, якщо дані коректні
    EXPECT_TRUE(b.Init("Кобзар", "Т. Шевченко", 1840));
    EXPECT_EQ(b.getYear(), 1840);
    EXPECT_EQ(b.getAuthor(), "Т. Шевченко");
}

// Тест перевіряє захист (валідацію) від некоректного року
TEST(BookTest, ValidationFailure) {
    Book b;
    // Очікуємо false, бо рік 3000 — некоректний
    EXPECT_FALSE(b.Init("Тест", "Автор", 3000));
    // Перевіряємо, що через помилку рік скинувся в 0 (як у вашому коді)
    EXPECT_EQ(b.getYear(), 0);
}

// Тест перевіряє роботу методу toString
TEST(BookTest, ToStringFormat) {
    Book b;
    b.Init("Марія", "Улас Самчук", 1934);
    std::string result = b.toString();

    // Перевіряємо, чи містить сформований рядок ім'я автора
    EXPECT_NE(result.find("Улас Самчук"), std::string::npos);
}

// Тест перевіряє окрему роботу сетера setYear
TEST(BookTest, SetYearMethod) {
    Book b;
    b.setYear(2020);
    EXPECT_EQ(b.getYear(), 2020);

    b.setYear(-5); // Некоректне значення
    EXPECT_EQ(b.getYear(), 0);
}