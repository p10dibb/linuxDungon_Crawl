#include "Combat.h"

//player fighting Enemy  return 0=Enemy died -1=player died
int PlayerVsEnemyCombat(Player *player, Enemy *zed)
{
	cout << "Enemy Level: " << zed->getLevel() <<"Health: "<<zed->getHealth()<< " Position: " << player->getPosition()[0] << "," << player->getPosition()[1] << endl;

	//speed totals who ever has the higher number gets to attack
	int playerSpeedTot = player->ActualSpeed();
	int EnemySpeedTot = zed->getSpeed();

	int Damage = 0;
	int round = 1;
	int playerChoice = -1;

	sf::Font font;
	font.loadFromFile("../Fonts/Montserrat-Regular.ttf");

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Combat");

	queue<string> Logs;

	sf::Text enemyInfo(zed->getName() + " Level: " + to_string(zed->getLevel()) + " Health: " + to_string(zed->getHealth()) + "/" + to_string(zed->getMaxHealth()), font, 30);
	enemyInfo.setPosition(sf::Vector2f(10, 40));

	sf::RectangleShape EnemyPic(sf::Vector2f(100, 200));
	EnemyPic.setFillColor(sf::Color::Red);
	EnemyPic.setPosition(sf::Vector2f(10, 140));

	sf::Text playerInfo(player->getName() + " Level: " + to_string(player->getLevel()) + " Health: " + to_string(player->getHealth()) + "/" + to_string(player->getMaxHealth()), font, 30);
	playerInfo.setPosition(sf::Vector2f(10, 80));

	sf::RectangleShape PlayerPic(sf::Vector2f(100, 200));
	PlayerPic.setFillColor(sf::Color::Blue);
	PlayerPic.setPosition(sf::Vector2f(150, 140));

	sf::Text whosTurn("  Turn", font, 30);
	whosTurn.setPosition(sf::Vector2f(10, 10));

	sf::Text LogsText("", font, 15);
	LogsText.setPosition(10, 400);

	string tempLog;
	string displayLog;

	bool release = false;

	sf::Text playerOptions("[1]:attack\n[2]:" + player->getRight()->getCombatEffect().getEffectName() + "\n[3]: " + player->getLeft()->getCombatEffect().getEffectName() + "\n[4]: Run\n[5]: View inventory", font, 30);
	playerOptions.setPosition(sf::Vector2f(200, 400));

	//0=run away,1=player dies 2=enemy dies
	int exitCase = -1;

	sf::Text exitText("", font, 30);
	exitText.setPosition(200, 450);

	while (window.isOpen())
	{
		if (zed->getHealth() <= 0)
		{
			exitCase = 2;
		}
		if (player->getHealth() <= 0)
		{
			exitCase = 1;
		}

		playerInfo.setString(player->getName() + " Level: " + to_string(player->getLevel()) + " Health: " + to_string(player->getHealth()) + "/" + to_string(player->getMaxHealth()));

		enemyInfo.setString(zed->getName() + " Level: " + to_string(zed->getLevel()) + " Health: " + to_string(zed->getHealth()) + "/" + to_string(zed->getMaxHealth()));

		while (Logs.size() > 10)
		{
			Logs.pop();
		}
		tempLog = "";
		displayLog = "";
		for (int i = 0; i < Logs.size(); i++)
		{
			tempLog = Logs.front();
			Logs.pop();
			displayLog += tempLog + "\n";
			Logs.push(tempLog);
		}
		LogsText.setString(displayLog);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(enemyInfo);
		window.draw(EnemyPic);

		window.draw(playerInfo);
		window.draw(PlayerPic);
		window.draw(LogsText);

		window.draw(playerOptions);
		if (exitCase >= 0)
		{
			window.draw(exitText);
		}
		window.display();

		//Enemys turn
		if (EnemySpeedTot > playerSpeedTot && exitCase < 0)
		{

			whosTurn.setString(zed->getName() + "'s Turn");
			playerSpeedTot += player->ActualSpeed();

			Damage = player->TakeDamage(zed->getAllDamageTypes());
			tempLog = zed->getName() + " Deals " + to_string(Damage);
			Logs.push(tempLog);

			player->IncrementDamageRecieved(Damage);
			player->IncrementDamageRecieved(player->runDamageOverTimeEffects(&Logs));
			player->DecrementAllEffects();
			zed->runDamageOverTimeEffects(&Logs);
			zed->DecrementAllEffects();
		}
		else if (exitCase < 0)
		{
			whosTurn.setString(player->getName() + "'s Turn");

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				playerChoice = 1;
				release = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				playerChoice = 2;
				release = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			{
				playerChoice = 3;
				release = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				playerChoice = 4;
				release = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
			{
				playerChoice = 5;
				release = true;
			}
			else if (release)
			{

				switch (playerChoice)
				{
				case 1:
					Damage = zed->TakeDamage(player->getAllDamageTypes());
					//stats incrementer
					player->IncrementDamageDealt(Damage);
					player->RewardCheckMaxDamageDealt(Damage);
					EnemySpeedTot += zed->getSpeed();

					Logs.push(player->getName() + " deals " + to_string(Damage) + " damage");
					break;
				case 2:
					player->AddCombatEffect(player->getRight()->getCombatEffect());
					Logs.push(player->getName() + " used " + player->getRight()->getCombatEffect().getEffectName());
					EnemySpeedTot += zed->getSpeed();

					break;

				case 3:
					player->AddCombatEffect(player->getLeft()->getCombatEffect());
					Logs.push(player->getName() + " used " + player->getLeft()->getCombatEffect().getEffectName());
					EnemySpeedTot += zed->getSpeed();

					break;
				case 4:
					Damage = player->TakeDamage(zed->getAllDamageTypes());

					//stats incrementer
					player->IncrementDamageRecieved(Damage);

					Logs.push(player->getName() + " takes " + to_string(Damage) + " damage while trying to escape");

					if (player->getHealth() <= 0)
					{
						Logs.push(player->getName() + " Died while running away");
						exitCase = 1;
					}
					else
					{
						exitCase = 0;
					}

					break;

				case 5:
					player->InventoryDialogue();
					break;

				default:
					break;
				}

				release = false;
				player->IncrementDamageRecieved(player->runDamageOverTimeEffects(&Logs));
				player->DecrementAllEffects();
				zed->runDamageOverTimeEffects(&Logs);
				zed->DecrementAllEffects();
			}
		}
		else
		{
			switch (exitCase)
			{
				//run away
			case 0:
				exitText.setString(player->getName() + " has Escaped");
				playerOptions.setString("[1]: Exit");

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
				{
					playerChoice = 1;
					release = true;
				}
				else if (release)
				{
					switch (playerChoice)
					{
					case 1:
						window.close();
						break;

					default:
						break;
					}
					release = false;
				}
				break;

			case 1:
				exitText.setString(player->getName() + " has Died");
				playerOptions.setString("[1]: Exit");

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
				{
					playerChoice = 1;
					release = true;
				}
				else if (release)
				{
					switch (playerChoice)
					{
					case 1:
						window.close();
						break;

					default:
						break;
					}
					release = false;
				}
				break;

			case 2:
				exitText.setString(zed->getName() + " has Died");
				playerOptions.setString("[1]: Exit");

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
				{
					playerChoice = 1;
					release = true;
				}
				else if (release)
				{
					switch (playerChoice)
					{
					case 1:
						window.close();
						break;

					default:
						break;
					}
					release = false;
				}
				break;

			default:
				break;
			}
		}
	}

	switch (exitCase)
	{
	case 0:
		return -2;
	case 1:
		return -1;
		break;
	case 2:
		player->IncrementCreaturesKilled();
		return 0;
	default:
		return -2;
		break;
	}

}

// prompsts player for options  returns 0 for attack and 1 for run
int PlayersChoices(Player *player)
{

	string input = "-1";
	//int i=0;

	while (1)
	{
		cout << "would you like to [attack:1| " << player->getRight()->getCombatEffect().getEffectName() << ":2| " << player->getLeft()->getCombatEffect().getEffectName() << ":3| ";
		cout << "Run:4|View inventory:5]: ";
		cin >> input;

		if (input == "1")
		{ // attack
			return 0;
		}
		else if (input == "2")
		{
			player->AddCombatEffect(player->getRight()->getCombatEffect());
			cout << player->getName() << " used " << player->getRight()->getCombatEffect().getEffectName() << endl;
			return 2;
		}
		else if (input == "3")
		{
			player->AddCombatEffect(player->getLeft()->getCombatEffect());
			cout << player->getName() << " used " << player->getLeft()->getCombatEffect().getEffectName() << endl;
			return 3;
		}
		else if (input == "4")
		{ // run away
			return 1;
		}
		else if (input == "5")
		{
			player->InventoryDialogue();
		}
		else
		{
			cout << "not valid choice" << endl;
		}
	}
}
