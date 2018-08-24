#include<iostream>
#include"Position.h"

using namespace std;

const int WALL = 0;
const int CORRIDOR = 1;
const int PATH = 9;
const int TRIED = 2;
const int ROWS = 7;
const int COLS = 13;

struct itrFields
{
  int row,col,drc
};

int grid[ROWS][COLS]=
{
  {1,1,1,0,1,1,0,0,0,1,1,1,1},
  {1,0,1,1,1,0,1,1,1,1,1,0,1},
  {1,0,0,0,1,0,1,0,1,0,1,0,1},
  {1,0,0,0,1,1,1,0,1,0,1,1,1},
  {1,1,1,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,1,1,1,1,1,1,1,1,1},
};//grid

Position start,finish;
Position Application::genInitialState(int row = 0,int col = 0)
{
  const string START_PROMPT =
  "Please enter the finish row and start col";
  const string FINISH_PROMPT =
  "Please enter the end row and end col";

  int row,col;

  cout<<START_PROMPT;
  cin >> row >> col;
  start.setPos(row,col);
  cout<<FINISH_PROMPT;
  cin >> row >> col;
  cin.get();
  finish.setPos(row,col);

  return start;
}

bool Application::valid(Position& pos)
{
  (pos.getRow() >= 0 && pos.getRow() < ROWS &&
   pos.getCol() >= 0 && pos.getCol() < COLS &&
   grid[pos.getRow()][pos.getCol()] == CORRIDOR)? True : False;
}

void Positiion::record(const Position& pos)
{
  grid[pos.getRow()][pos.getCol()] = PATH;
}

bool Position::done(const Position& pos)
{
  return (pos.getRow() == finish.getRow() && pos.getCol() == finish.getCol());
}

void Position::undo(const Position& pos)
{
  grid[pos.getRow()][pos.getCol()] = TRIED;
}

ostream& operator<< (ostream& stream,Application& app)
{
  cout<<endl;
  for(int row = 0;row < ROWS;row++)
  {
    for(int col = 0;col < COLS;col++)
      cout<<grid[row][column]<<' ';
    cout<<endl;
  }

  return stream;
}

Application::Iterator(Position& pos)
{
  itrFields* itrPtr = new itrFields;
  itrPtr->row = pos.getRow();
  itrPtr->col = pos.getCol();
  itrPrt->drc = 0;
  fieldPtr = itrPtr;
}

Position Application::Iterator::operator++(int)
{
  itrFields* itrPtr = (itrField*)fieldPtr;
  int nextRow = itrPtr->row,nextCol = itrPtr->col;

  switch(itrPtr->direction++)
  {
    case 0:nextRow = itrPtr->row - 1;
          break;
    case 1:nextCol = itrPtr->col + 1;
          break;
    case 2:nextRow = itrPtr->row + 1;
          break;
    case 3:nextCol = itrPtr->col - 1;
  }

  Position next(nextRow,nextCol);
  return next;

}

bool Application::Iterator::atEnd()
{
  return ((itrFields*)fieldPtr -> drc >= 3);
}

