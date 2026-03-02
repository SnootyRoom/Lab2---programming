#include <iostream>

using namespace std;

struct Book {
    string title;
    string author;
};

struct Library {
    int date[5];
};

void printBook(Book book){
    cout<<endl;
    cout<<"Title: "<<book.title<<endl;
    cout<<"Author: "<<book.author<<endl;
}

Book searchBookByAuthor(Book *books, const int N, string author) {

    for (int i = 0; i < N; i++) {
        if(books[i].author == author) return books[i];
    }
    return {};
}

int getIndex(Book *books, const int N, Book book) {
    for (int i = 0; i < N; i++) {
        if(books[i].title == book.title && books[i].author == book.author) return i;
    }
    return -1;
}


int main(int, char**){
    const int N = 5;
    Book book;
    Book *books = new Book[N];
    Library library;
    string title, author;

    for (int i = 0; i < N; i++){
        cout<<endl<<"Input info about "<<i + 1<<" book"<<endl;
        cout<<"Input title of book"<<endl;
        cin>>title;
        book.title = title;
        cout<<"Input author of book"<<endl;
        cin>>author;
        book.author = author;
        cout<<"Input date of book"<<endl;
        cin>>library.date[i];
        
        books[i] = book;
    }

    cout<<"Info about books"<<endl;
    for(int i = 0; i < N; i++){
        cout<<"Book "<<i + 1<<endl;
        printBook(books[i]);
        cout<<"Date: "<<library.date[i]<<endl;
    }

    cout<<endl<<"Input author of book what you want to search"<<endl;
    cin>>author;
    book = searchBookByAuthor(books, N, author);
    cout<<"Info about book what you search"<<endl;
    printBook(book);
    cout<<"Date: "<<library.date[getIndex(books, N, book)]<<endl;

    delete books;
    delete library.date;

    return 0;
}
