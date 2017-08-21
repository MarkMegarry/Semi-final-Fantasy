#include <iostream>
using namespace std;

int main()
{
 
  public:
  //Decalaration of variables
  //What the user wants to do
  string action;
  
  //Displays main message to user
  void mainPrompt()
  {
    cout << "What would you like to do?  Type \"help\" for a list of available actions" << endl;
  }
  //Sets action variable
  void setAction()
  {
    cin >> action
  }
  //Gets action variable
  string getAction()
  {
    return action;
  }
  
}
