#include"Position.h"

using namespace std;

Position::Position():row(0),col(0){}//default constuctor
Position::Position(int row,int col)
{
  this->row = row;this->col = col;
}

void Position::setPos(int row,int col)
{
  this->row = row;this->col = col;
}

/*explanation
The objects in the std::set are stored as const StudentT. So when you try to call getId() with the const object the compiler detects a problem, mainly you're calling a non-const member function on const object which is not allowed because non-const member functions make NO PROMISE not to modify the object; so the compiler is going to make a safe assumption that getId() might attempt to modify the object but at the same time, it also notices that the object is const; so any attempt to modify the const object should be an error. Hence compiler generates an error message.
*/
int Position::getRow() const
{
  return row;
}

int Position::getCol() const
{
  return col;
}
