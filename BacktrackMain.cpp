#include<iostream>
#include<string>
#include"Backtrack.h"
#include"Application.h"
#include"Position.h"

using namespace std;

int main()
{
  const string INITIAL_STATE = "The inital state is as follows:\n";
  const string SUCCESS = "\n\nA solution has been found:";
  const string FAILURE = "\n\nThere is no solution:";
  const string CLOSE_WINDOW_PROMPT = "Please press the enter key to close this output window:";

  Application app;
  BackTrack b(app);

  cout<<INITAL_STATE;
  Position start = app.genInitialState();
  cout<<app;

  if(!app.Valid(start))
    cout<<FAILURE<<endl;
  else
  {
    app.record(start);
    if(app.done(start)||b.tryToSolve(start))
      cout<<SUCCESS<<endl<<app;
    else
    {
      app.undo(start);
      cout<<FAILURE<<endl;
    }//Failure
  }//Valid Start

  cout<<"\n\n"<<CLOSE_WINDOW_PROMPT;
  cin.get();

  return 0;
}//
