#include <iostream>
#include <string>
using namespace std;

class battle
{
  public:
  
  
  //Declaration of variables
  //Player input on menu
  int input;
  //HP of enemy
  int enemyHP = 100;
  //HP of player
  int playerHP = 100;
  // Damage of equipped weapon
  int damage;
  //Equipped weapon
  string currentWeapon = "shortSword";
  //Number of potions available
  int potionNo = 3;
  
  
  
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
    if (playerHP >=100)
    {
      playerHP = 100;
    }
    cout << "+-------------+" << endl;
    cout << "|Your HP: " << playerHP << " |" << endl;
    cout << "|Enemy HP: " << enemyHP << "|" << endl;
    cout << "+-------------+" << endl;
    cout << "+------------------+" << endl;
    cout << "|Will you...       |" << endl;
    cout << "|1: Fight          |" << endl;
    cout << "|2: Check inventory|" << endl;
    cout << "|3: Use an item    |" << endl;
    cout << "+------------------+" << endl;
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
  
  //Change weapon
  void changeWeapon()
  {
    int change;
    cin >> change;
    switch(change)
    {
      case 1:
      currentWeapon = "shortSword";
      cout <<"You have equipped the short sword" << endl;
      break;
      
      case 2:
      currentWeapon = "dagger";
      cout <<"You have equipped the dagger" << endl;
      break;
      
      case 3:
      currentWeapon = "greatSword";
      cout << "You have equipped the greatsword" << endl;
      break;
      
      default:
      changeWeapon();
    }
  }
  
  //fight method
  void fight(int PlayerHP, int EnemyHP)
  {
    if (currentWeapon == "shortSword")
    {
      damage = 10;
    }
    else if (currentWeapon == "dagger")
    {
      damage = 5;
    }
    else if (currentWeapon == "greatSword")
    {
      damage = 30;
    }
    //Sword art
    cout<<"   __"<<endl;
    cout<<"   ||"<<endl;
    cout<<"   ||"<<endl;
    cout<<"   ||"<<endl;
    cout<<"   ||"<<endl;
    cout<<"==++++=="<<endl;
    cout<<"  ||||"<<endl;
    cout<<"  ||||"<<endl;
    cout<<"  ||||"<<endl;
    cout<<"  ||||"<<endl;
    cout<<"  ||||"<<endl;
    cout<<"  ||||"<<endl;
    cout<<"  ||||"<<endl;
    cout<<"  ||||"<<endl;
    cout<<"  ||||"<<endl;
    cout<<"  \\  /"<<endl;
    cout<<"   \\/"<<endl;
    cout << "You strike your enemy, dealing " << damage << " damage!" << endl;
    cout << "Your enemy strikes you.  You take 5 damage" << endl;
   
    playerHP = playerHP - 5;
    enemyHP = enemyHP - damage;
    
  }
  
  
  void processInput()
  {
    switch(input)
    {
      //fight
      case 1:
      fight(playerHP, enemyHP);
      break;
      
      //check inventory
      case 2:
      cout << "+---------------------------------------------+" << endl;
      cout << "|Weapons in inventory are:                    |" << endl;
      cout << "|1: Short sword (10 DMG)                      |" << endl;
      cout << "|2: Dagger (5 DMG)                            |" << endl;
      cout << "|3: Greatsword (30 DMG)                       |" << endl;
      cout << "|Select the weapon you would like to switch to|" << endl;
      cout << "+---------------------------------------------+" << endl;
      changeWeapon();
      break;
      
      //Use an item
      case 3:
      if (potionNo < 0)
      {
        potionNo =0;
      }
      cout << "+---------------------+" << endl;
      cout << "|Available items are: |" << endl;
      cout << "|1: Potion X" << potionNo << "         |"<< endl;
      cout << "+---------------------+" << endl;
      cout << "Potions restore 10 HP.  Select a potion or press \"2\" to go back."<< endl;
      int itemAction;
      cin >> itemAction;
      switch(itemAction)
     {
       //Use potion
       case 1:
       if (potionNo > 0 && playerHP <= 90)
       {
         playerHP = playerHP + 10;
         cout << "Used 1 potion"<<endl;
         --potionNo;
         cout<< "HP restored by 10!"<<endl;
       }
       else if (playerHP > 90)
       {
         playerHP = 100;
         --potionNo;
       }
       else if (potionNo <= 0)
       {
         cout << "You are out of potions!"<<endl;
       }
       break;
       
       case 2:
       break;
       
       
     }
      
      
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
    //Displays main message
  fight.mainMessage();
  //Takes user input
  fight.setInput();
  //Runs user input through switch statement
  fight.processInput();
  }
  //Victory
  if (fight.getEnemyHP() <=0)
  {
    cout << "|\\___/\\___/\\___/\\___/\\___/\\___/\\___/\\___/\\___/\\__/|" << endl;
    cout << "|Your foe falls at your feet.  You are victorious!|" << endl;
    cout << "+-------------------------------------------------+" << endl;
  }
  //Defeat
  else if (fight.getPlayerHP() <=0)
  {
    cout << "You are defeated";
  }
  return 0;
  
}


