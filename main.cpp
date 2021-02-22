#include <iostream>
#include <string.h>
using namespace std;

class State {
public:
  virtual int GetNo () = 0;
  virtual string GetTtile () = 0;
  virtual string GetAuthor () = 0;
  virtual ~State(){};
};

class Book1 : public State {
private:
  int No = 1;
  string Title = "How to use UML";
  string Author = "Jhon";
public:
  int GetNo() { return No; }
  string GetTtile() { return Title; }
  string GetAuthor() { return Author; }
};

class Book2 : public State {
private:
  int No = 2;
  string Title = "C++ programming";
  string Author = "Alan";
public:
  int GetNo() { return No; }
  string GetTtile() { return Title; }
  string GetAuthor() { return Author; }
};

class BookViewer {
  State *book_m = nullptr;
public:
  BookViewer (State *book) : book_m(book) {}
  void SetBook (State *book){ book_m = book; }
  void PrintNo (){ cout << "No: " << book_m->GetNo() << endl; }
  void PrintTitle (){ cout << "Title: " <<  book_m->GetTtile() << endl; }
  void PrintAuthor (){ cout <<  "Authro: " << book_m->GetAuthor() << endl; }
  void PrintAll (){
    PrintNo();
    PrintTitle();
    PrintAuthor();
  }
};

int main() {
  Book1 *b1 = new Book1();
  Book2 *b2 = new Book2();
  BookViewer bv(b1);
  cout << "Book1's states" << endl;
  bv.PrintAll();
  bv.SetBook(b2);
  cout << endl << "Book2's states" << endl;
  bv.PrintAll();

  return 0;
}
