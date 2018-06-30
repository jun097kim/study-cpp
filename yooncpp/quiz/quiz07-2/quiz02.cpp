#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char *title;    // 책의 제목
    char *isbn;     // 국제표준도서번호
    int price;      // 책의 정가

public:
    Book(char *title, char *isbn, int price)
        : price(price)
    {
        this->title = new char[strlen(title) + 1];
        this->isbn = new char[strlen(isbn) + 1];
        strcpy(this->title, title);
        strcpy(this->isbn, isbn);
    }
    void ShowBookInfo()
    {
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
    }
    ~Book()
    {
        delete[] title;
        delete[] isbn;
    }
};

class EBook : public Book
{
private:
    char *DRMKey;   // 보안관련 키
public:
    EBook(char *title, char *isbn, int price, char *drm)
        : Book(title, isbn, price)
    {
        DRMKey = new char[sizeof(drm) + 1];
        strcpy(DRMKey, drm);
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl;
    }
    ~EBook()
    {
        delete[] DRMKey;
    }
};

int main()
{
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;
    EBook ebook("좋은 C++ eboook", "555-12345-890-1", 10000, "fds9w0i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}