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
    Book(const Book& ref)
        : price(ref.price)
    {
        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
    }
    Book& operator=(const Book& ref)
    {
        delete[] title;
        delete[] isbn;
        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
        price = ref.price;
        return *this;
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
    EBook(const EBook& ref)
        : Book(ref)
    {
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
    }
    EBook& operator=(const EBook& ref)
    {
        Book::operator=(ref);
        delete[] DRMKey;
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
        return *this;
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
    EBook ebook1("좋은 C++ eboook", "555-12345-890-1", 10000, "fds9w0i8kiw");
    EBook ebook2 = ebook1;  // 복사 생성자의 호출
    ebook2.ShowEBookInfo();
    cout << endl;
    EBook ebook3("dumy", "dumy", 0, "dumy");
    ebook3 = ebook2;    // 대입 연산자의 호출
    ebook3.ShowEBookInfo();
    return 0;
}