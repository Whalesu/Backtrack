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

int Position::getRow()
{
  return row;
}

int Position::getCol()
{
  return col;
}
