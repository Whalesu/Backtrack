#include "Backtrack.h"

using namespace std;

Backtrack::Backtrack(const Application& app)
{
  this->app = app;
}//constructor

bool Backtrack::tryToSolve(Position pos)
{
  bool success = false;
  Position::Iterator itr = pos.begin();
  while(!success && itr != pos.end())
  {
    pos = itr++;
    if(app.valid(pos))
    {
      app.record(pos);
      if(app.done(pos))
        success = True;
      else
      {
        success = tryToSolve(pos);
        if(!success)
          app.undo(pos);
      }//cancel
    }// a valid pos
  }
  return success;
}
