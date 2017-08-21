#include <iostream>
#include <string>
using namespace std;

class battle
{
  public:
  //Declaration of variables
  int input;
  int enemyHP = 100;
  int playerHP = 100;
  string weapon = "short-sword";
  
  
  //Get player HP
  int getPlayerHP()
  {
    return playerHP;
  }
  
  //get enemy HP
  int getEnemyHP()
  {
    return enemyHP;
  }
  
  //display main message
  void mainMessage()
  {
    //Displays player and enemy HP, then lists actions
    cout << "Your HP: " << playerHP << endl;
    cout << "Enemy HP: " << enemyHP << endl;
    cout << "Will you..." << endl;
    cout << "1: Fight" << endl;
    cout << "2: Check inventory" << endl;
    cout << "3: use an item" << endl;
  }
  
  //set input
  void setInput()
  {
    cin >> input;
  }
  
  //get input
  int getInput()
  {
    return input;
  }
  //fight method
  void fight(int PlayerHP, int EnemyHP)
  {
    cout << "You strike your enemy, dealing 10 damage!" << endl;
    cout << "Your enemy strikes you.  You take 5 damage" << endl;
    playerHP = playerHP - 5;
    enemyHP = enemyHP - 10;
  }
  void processInput()
  {
    switch(input)
    {
      //fight
      case 1:
      fight(playerHP, enemyHP);
      break;
      
      
      
    }
  }
};

int main()
{
  //Initial description
  cout << "After entering through an unchecked window in the Eastern wall of the castle, you begin to walk down the dimly candle-lit hallway." << endl;
  cout << "Your path is blocked by a large knight, clad in armour as dark as night!" << endl;
  battle fight;
  while(fight.getPlayerHP() > 0 && fight.getEnemyHP()>0)
  {
  fight.mainMessage();
  fight.setInput();
  fight.processInput();
  }
  if (fight.getEnemyHP() <=0)
  {
    cout << "Your foe falls at your feet.  You are victorious!"  << endl;
  }
  else if (fight.getPlayerHP() <=0)
  {
    cout << "You are defeated";
  }
  return 0;
  
}


