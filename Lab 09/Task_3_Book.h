#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(std::string t, std::string a, std::string i);

    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
};
#endif