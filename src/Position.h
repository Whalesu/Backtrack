#ifndef POSITION
#define POSITION

class Position
{

public:
  Position();
  Position(int row,int col);
  void setPos(int row,int col);
  int getRow();
  int getCol();
protected:
  int row,col;
};

#endif
