#ifndef POSITION
#define POSITION

class Position
{

public:
  Position();
  Position(int row,int col);
  void setPos(int row,int col);
  int getRow() const;
  int getCol() const;
protected:
  int row,col;
};

#endif
