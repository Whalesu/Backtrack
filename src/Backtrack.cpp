#include "Backtrack.h"

using namespace std;

Backtrack::Backtrack(const Application& app)
{
  this->app = app;
}//constructor

bool Backtrack::tryToSolve(Position pos)
{
  bool success = false;
  Application::Iterator itr = Application::Iterator(pos);

  while(!success && !itr.atEnd())
  {
    pos = itr++;
    if(app.valid(pos))
    {
      app.record(pos);
      if(app.done(pos))
        success = true;
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
