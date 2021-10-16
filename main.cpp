#include <iostream>

enum PlayerType
{
  PowerPlayer,
  SkillfulPlayer,
  RagePlayer,
};

// Interface for Player classes
class BasePlayer{
protected:
  int playerHealth;
  int playerDamage;
  int additionalDamage;
  int healingCapacity;
  int maxHealth;
  PlayerType player;

public:
  virtual PlayerType const GetPlayerType() = 0;
  virtual int const GetPlayerHealth() = 0;
  virtual void SetPlayerHealth(int value) = 0;
  virtual int const GetPlayerDamage() = 0;
  virtual void SetPlayerDamage(int value) = 0;
  virtual int const GetAdditionalDamage() = 0;
  virtual void SetAdditionalDamage(int value) = 0;
  virtual int const GetHealingCapacity() = 0;
  virtual void SetHealingCapacity(int value) = 0;
  virtual int const GetMaxHealth() = 0;

  virtual void TakeDamage(int damage) = 0;
  virtual void HealPlayer(int health) = 0;
  virtual int const GetTotalDamage() = 0;

  virtual void RandomizeAdditionalDamage() = 0;
  virtual void RandomizeHealingCapacity() = 0;

  virtual void ApplyDamage(BasePlayer *otherPlayer) = 0;
  virtual void ApplyHealing(BasePlayer *otherPlayer) = 0;
  virtual void MaximumHealthCheck() = 0;

  virtual ~BasePlayer() = 0;
};

BasePlayer:: ~BasePlayer(){}


// Implementation of interface // Base for different player class
class Player : public BasePlayer{
public:
  Player(int playerHealth, int playerDamage, int additionalDamage, int healingCapacity, PlayerType player)
  {
    this->playerHealth = playerHealth;
    this->playerDamage = playerDamage;
    this->additionalDamage = additionalDamage;
    this->healingCapacity = healingCapacity;
    this->maxHealth = playerHealth;
    this->player = player;
  }

  PlayerType const GetPlayerType()
  {
    return player;
  }

  int const GetPlayerHealth()
  {
    return playerHealth;
  }

  void SetPlayerHealth(int value)
  {
    playerHealth = value;
  }

  int const GetPlayerDamage()
  {
    return playerDamage;
  }

  void SetPlayerDamage(int value)
  {
    playerDamage = value;
  }

  int const GetAdditionalDamage()
  {
    return additionalDamage;
  }

  void SetAdditionalDamage(int value)
  {
    additionalDamage = value;
  }

  int const GetHealingCapacity()
  {
    return healingCapacity;
  }

  void SetHealingCapacity(int value)
  {
    healingCapacity =  value;
  }

  int const GetMaxHealth()
  {
    return maxHealth;
  }

  void TakeDamage(int damage) 
  {
    playerHealth -= damage;
  }

  void HealPlayer(int health) 
  {
    playerHealth += health;
  }

  int const GetTotalDamage() 
  {
    return playerDamage + additionalDamage;
  }

  virtual void RandomizeAdditionalDamage()
  {
    SetAdditionalDamage(5 + (rand() % 10));
  }

  virtual void RandomizeHealingCapacity()
  {
    SetHealingCapacity(5 + (rand() % 5));
  }

  void ApplyDamage(BasePlayer *otherPlayer);
  void ApplyHealing(BasePlayer *otherPlayer);
  void MaximumHealthCheck();

};


// Creating player types by inheriting properties from player class 
class PoweredPlayer : public Player{
public:
  PoweredPlayer(int playerHealth, int playerDamage, int additionalDamage, int healingCapacity) : Player(playerHealth, playerDamage, additionalDamage, healingCapacity, PlayerType::PowerPlayer){}

  void RandomizeAdditionalDamage()
  {
    SetAdditionalDamage(4 + (rand() % 10));
  }

  void RandomizeHealingCapacity()
  {
    SetHealingCapacity(5 + (rand() % 5));
  }

};

class SkilledPlayer : public Player{
public:
  SkilledPlayer(int playerHealth, int playerDamage, int additionalDamage, int healingCapacity) : Player(playerHealth, playerDamage, additionalDamage, healingCapacity, PlayerType::SkillfulPlayer) {}

  void RandomizeAdditionalDamage()
  {
    SetAdditionalDamage(6 + (rand() % 10));
  }

  void RandomizeHealingCapacity()
  {
    SetHealingCapacity(10 + (rand() % 10));
  }

};

class RagedPlayer : public Player{
public:
  RagedPlayer(int playerHealth, int playerDamage, int additionalDamage, int healingCapacity) : Player(playerHealth, playerDamage, additionalDamage, healingCapacity, PlayerType::RagePlayer) {}

  void RandomizeAdditionalDamage()
  {
    SetAdditionalDamage(8 + (rand() % 10));
  }

  void RandomizeHealingCapacity()
  {
    SetHealingCapacity(15 + (rand() % 10));
  }
};


void ShowInstructions()
{
  std::cout << std::endl << std::endl;
  std::cout << "!! Welcome To 2-Player-Battle-Adventure Game !!" << std::endl << std::endl<< std::endl;

  std::cout << "Instructions :" << std::endl;
  std::cout << "1) Each player has one choice at a time." << std::endl;
  std::cout << "2) The player can either attack or heal." << std::endl;
  std::cout << "3) The player who's health goes below 0, will die and loose the game." << std::endl;
  std::cout << "4) Press 'H' to heal and 'A' to attack." << std::endl;
  std::cout << "5) Each special ability has 20% probability." << std::endl << std::endl << std::endl;

  std::cout << "Player types :" << std::endl << std::endl ;

  std::cout << "1) Power Player    - High Health, Low Heal, Low Base Damage, Low Additional Damage" << std::endl;
  std::cout << "   Special Ability - Huge Heal" << std::endl;
  std::cout << "                   - Double Attack" << std::endl << std::endl;

  std::cout << "2) Skillful Player - Average Health, High Heal, Average Base Damage, Average Additional Damage" << std::endl;
  std::cout << "   Special Ability - Attack Blocker" << std::endl;
  std::cout << "                   - Heal + Damage in single turn" << std::endl << std::endl;

  std::cout << "3) Rage Player     - Low Health, Very High Heal, High Base Damage, High Additional Damage" << std::endl;
  std::cout << "   Special Ability - Rage (Damage increases when close to death)" << std::endl;
  std::cout << "                   - Critical Hit" << std::endl;

  std::cout << std::endl << std::endl;
} 


void ShowInitialPlayerStats(BasePlayer* player, int index)
{
  switch(index)
  {
    case 1:
      std::cout << "Power Player - Whatever Tt Takes !" << std::endl;
      break;
    case 2:
      std::cout << "Skillful Player - Ready For All !" << std::endl;
      break;
    case 3:
      std::cout << "Rage Player - Till My Last Breath !" << std::endl;
      break;
  }

  std::cout << "Player health : ";
  std::cout << player->GetPlayerHealth() << std::endl;

  std::cout << "Base Damage : ";
  std::cout << player->GetPlayerDamage() << std::endl;

  switch(index)
  {
    case 1:
      std::cout << "Additional Damage : 4 - 14" << std::endl;
      std::cout << "Healing Capacity : 5 - 10" << std::endl << std::endl;
      break;
    case 2:
      std::cout << "Additional Damage : 6 - 16" << std::endl;
      std::cout << "Healing Capacity : 10 - 20" << std::endl << std::endl;
      break;
    case 3:
      std::cout << "Additional Damage : 8 - 18" << std::endl;
      std::cout << "Healing Capacity : 20 - 30" << std::endl << std::endl;
      break;
  }
}


void ShowPlayerStats(BasePlayer* player1, BasePlayer* player2)
{
  std::cout << "Player 1 : Health = " << player1->GetPlayerHealth() << std::endl;
  std::cout << "Player 2 : Health = " << player2->GetPlayerHealth() << std::endl << std::endl << std::endl;
}


BasePlayer* CreatePlayerOfType(int value)
{
  switch(value)
  {
    case 1:
      {
        BasePlayer* powerPlayer = new PoweredPlayer(200, 10, 0, 0);
        ShowInitialPlayerStats(powerPlayer, 1);
        return powerPlayer;
      }
      break;
  
    case 2:
      {
        BasePlayer* skilledPlayer = new SkilledPlayer(150, 20, 0, 0);
        ShowInitialPlayerStats(skilledPlayer, 2);
        return skilledPlayer;
      }
      break;

    case 3:
      {
        BasePlayer* ragedPlayer = new RagedPlayer(100, 30, 10, 0);
        ShowInitialPlayerStats(ragedPlayer, 3);
        return ragedPlayer;
      }
      break;

    Default:
    return nullptr;
    break;
  } 
  return nullptr;
}


BasePlayer* SelectPlayerType(int value)
{
  int playerChoice = 0;

  std::cout << std::endl;
  std::cout << "Player " << value << " : Select player type (1, 2, 3)" << std::endl;
  std::cout << "Player Type : " ;

  while(true)
  {
    std::cin >> playerChoice;
    std::cout << std::endl ;
    // std::cout<<"\e[2J\e[H";

    if(!std::cin || !(playerChoice == 1 || playerChoice == 2 || playerChoice == 3))
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::cout << "Please select correct player type" << std::endl;
      std::cout << "Player Type : " ;
      continue;
    }
    else 
    {     
      break;
    }
  }
  return CreatePlayerOfType(playerChoice);  
}


void CallFunction(BasePlayer* player1, BasePlayer* player2)
{
  char playerInput;

  std::cin >> playerInput;

  if(playerInput == 'a' || playerInput == 'A')
      {
        player2->ApplyDamage(player1);
      }

  else if(playerInput == 'h' || playerInput == 'H')
  {
    if(!(player1->GetPlayerHealth() >= player1->GetMaxHealth()))
    {
      player1->ApplyHealing(player2);
      std::cout << "Total heal = " << player1->GetHealingCapacity() << std::endl;
    }
    else
    {
      std::cout << "Your health is full. Turn Wasted." << std::endl;
    }   
  }
}


void GameStart(BasePlayer* player1, BasePlayer* player2)
{
  int playerIndex = 1;

  std::cout << "! Let The Battle Begin !" << std::endl;

  while(true)
  {

    if(player1->GetPlayerHealth() <= 0)
    {
      std::cout << "!! Player 2 won !!" << std::endl << std::endl;
      break;
    }
    else if(player2->GetPlayerHealth() <= 0)
    {
      std::cout << "!! Player 1 won !!" << std::endl << std::endl;
      break;
    }

    std::cout << "Player " << playerIndex << " : Enter 'A' To Attack or 'H' To Heal " << std::endl;
    std::cout << "Player " << playerIndex << " : ";

    if(playerIndex == 1)
    {
      CallFunction(player1, player2);
      ShowPlayerStats(player1, player2);
      playerIndex++;
    }

    else
    {   
      CallFunction(player2, player1);
      ShowPlayerStats(player1, player2);
      playerIndex--;
    }    
  }

}


void Player::ApplyDamage(BasePlayer *otherPlayer)
{
  otherPlayer->RandomizeAdditionalDamage(); // To randomize additional damage

  switch(otherPlayer->GetPlayerType())
  {
    case PowerPlayer:
      if( (GetPlayerType() == SkillfulPlayer) && (rand() % 4 == 0))
      {
        std::cout << "Special Ability Used By Opponent - Attack Blocker" << std::endl;
        std::cout << "Damage given = 0" << std::endl;
        break;
      }

      if(rand() % 4 == 0)
      {
        otherPlayer->SetAdditionalDamage( 2 * otherPlayer->GetAdditionalDamage());
        otherPlayer->SetPlayerDamage( 2 * otherPlayer->GetPlayerDamage());
        TakeDamage(otherPlayer->GetTotalDamage());

        std::cout << "Special Ability Used - Double Attack" << std::endl;
        std::cout << "Damage given = " << otherPlayer->GetTotalDamage() << std::endl;

        otherPlayer->SetPlayerDamage(otherPlayer->GetPlayerDamage() / 2);
        break;
      }
      else
      {
        TakeDamage(otherPlayer->GetTotalDamage());
        std::cout << "Damage given = " << otherPlayer->GetTotalDamage() << std::endl;
      }
      break;


    case SkillfulPlayer:
      if(rand() % 4 == 0)
      {
        std::cout << "Special Ability Used - Heal + Damage" << std::endl;

        otherPlayer->ApplyHealing(otherPlayer);
        TakeDamage(otherPlayer->GetTotalDamage());

        std::cout << "Damage given = " << otherPlayer->GetTotalDamage() << std::endl;
        std::cout << "Total heal = " << otherPlayer->GetHealingCapacity() << std::endl;
      }

      else
      {
        TakeDamage(otherPlayer->GetTotalDamage());
        std::cout << "Damage given = " << otherPlayer->GetTotalDamage() << std::endl;
      }
      break;


    case RagePlayer:
      if( (GetPlayerType() == SkillfulPlayer) && (rand() % 4 == 0))
      {
        std::cout << "Special Ability Used By Opponent - Attack Blocker" << std::endl;
        std::cout << "Damage given = 0" << std::endl;
        break;
      }

      if( (GetPlayerHealth() <= 0.3 * GetMaxHealth()))
      {
        otherPlayer->SetPlayerDamage( (otherPlayer->GetPlayerDamage() + 100/(otherPlayer->GetPlayerHealth())) );
        std::cout << "Special Ability Used - Rage" << std::endl;

          if((rand() % 4 == 0))
          {
            otherPlayer->SetAdditionalDamage( 1.5 * otherPlayer->GetAdditionalDamage());
            otherPlayer->SetPlayerDamage( 1.5 * otherPlayer->GetPlayerDamage());
            TakeDamage(otherPlayer->GetTotalDamage());

            std::cout << "Special Ability Used - Critical Hit" << std::endl;
            std::cout << "Damage given = " << otherPlayer->GetTotalDamage() << std::endl;

            otherPlayer->SetPlayerDamage(otherPlayer-> GetPlayerDamage() / 2);
            break;
          }
          else
          {
            TakeDamage(otherPlayer->GetTotalDamage());
            std::cout << "Damage given = " << otherPlayer->GetTotalDamage() << std::endl;
          }   
      }

      else
      {
        TakeDamage(otherPlayer->GetTotalDamage());
        std::cout << "Damage given = " << otherPlayer->GetTotalDamage() << std::endl;
      }
      break;
  }


  if(GetPlayerHealth() <= 0)
  {
    SetPlayerHealth(0);
  }
}


void Player::ApplyHealing(BasePlayer* otherPlayer)
{
  RandomizeHealingCapacity(); // To randomize healing capacity

  switch(GetPlayerType())
  {
    case PowerPlayer:
      if(rand() % 4 == 0)
      {
        std::cout << "Special Ability Used - Huge Heal" << std::endl;
        SetHealingCapacity(2 * GetHealingCapacity());
        MaximumHealthCheck();
      }
      else
      {
        MaximumHealthCheck();
      }
      break;

    case SkillfulPlayer:
      MaximumHealthCheck();
      break;

    case RagePlayer:
      MaximumHealthCheck();
      break;
  } 
}

void Player::MaximumHealthCheck()
{
  if(GetPlayerHealth() + GetHealingCapacity() > GetMaxHealth())
    {
      SetHealingCapacity(GetMaxHealth() - GetPlayerHealth());
      SetPlayerHealth(GetPlayerHealth() + GetHealingCapacity());
    }
    else
    {
      SetPlayerHealth(GetPlayerHealth() + GetHealingCapacity());
    }  
}



int main() 
{
  char restart;

  while(true)
  {
    ShowInstructions();

    BasePlayer* player1 = SelectPlayerType(1);
    BasePlayer* player2 = SelectPlayerType(2);

    GameStart(player1, player2);

    delete player1;
    delete player2;

    std::cout << "Press 'P' To Play Again" << std::endl;
    std::cin >> restart;

    if(!(restart == 'P' || restart == 'p'))
    {
      break;
    }
  }

}