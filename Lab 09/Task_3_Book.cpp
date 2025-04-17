#include <iostream>
#include "Task_3_Book.h"

Book::Book(std::string t, std::string a, std::string i)
    : title(t), author(a), isbn(i) {}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return isbn;
}

int main() {
    Book myBook("2002", "Shahnawaz Khuwaja", "12312312109");

    std::cout << "Book Title: " << myBook.getTitle() << std::endl;
    std::cout << "Author: " << myBook.getAuthor() << std::endl;
    std::cout << "ISBN: " << myBook.getISBN() << std::endl;

return 0;
}