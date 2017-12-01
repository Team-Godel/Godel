#ifndef HELP_H_INCLUDED
#define HELP_H_INCLUDED

#include <iostream>
#include <string>
#include "Constants.h"

using namespace std;


void GodelHelp(string topic);



string Meth[NB_METHODS] = {"GDL(HINSTANCE instance, LPSTR title, int x, int y, int w, int h) \n- Create a window",
                            "update() \n- Update the state of a window",
                            "showCursor(bool onOff) \n- Show or not the cursor",
                            "setCursorPosition(int x, int y) \n- Set the cursor to a defined position"};

string Func[NB_FUNCTIONS] = {"GodelHelp(string topic); \n- Show help"};

string Const[NB_CONSTANTS] = {"#define CLASS \"gdlWindow\""};


void GodelHelp(string topic)
{
    if(topic == "METHODS")   // Show all the methods
    {
        cout << "Methods" << endl << endl << endl;

        for(int iMethod = 0; iMethod < NB_METHODS; iMethod ++)
        {
          cout << Meth[iMethod] << endl << endl;

          if(iMethod == NB_METHODS - 1)
          {
            cout << endl << endl << endl;
          }
        }
    }
    else if(topic == "FUNCTIONS")  // Show all the functions
    {
        cout << "Functions" << endl << endl << endl;

        for(int iFunc = 0; iFunc < NB_FUNCTIONS; iFunc ++)
        {
          cout << Func[iFunc] << endl << endl;

          if(iFunc == NB_FUNCTIONS - 1)
          {
            cout << endl << endl << endl;
          }
        }
    }
    else if(topic == "CONSTANTS")  // Show all the constants
    {
        cout << "Constants" << endl << endl << endl;

        for(int iConst = 0; iConst < NB_CONSTANTS; iConst ++)
        {
          cout << Const[iConst] << endl << endl;

          if(iConst == NB_CONSTANTS - 1)
          {
            cout << endl << endl << endl;
          }
        }
    }
}



#endif // HELP_H_INCLUDED
