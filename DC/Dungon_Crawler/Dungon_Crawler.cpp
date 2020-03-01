#include "Dungon_Crawler.h"

void Run()
{
	int results = 0;
	string choice = "";
	Spawner s;

	Player player;

	Floor mainFloor;

	while (player.getName() == "")
	{
		switch (StartScreen())
		{
		case -1: return;
		case 1:
			player = createPlayer();
			break;
		case 2:
			player = Loader();
			break;
		case 3:
			return;
		default:
			break;
		}
	}
	//creates the main floor

	//runs the game
	while (1)
	{
		mainFloor = createFloor();

		//sets the player
		player.setPosition({1, 1});
		mainFloor.setPlayer(&player);

		results = mainFloor.NavigateFloor();
		if (results == -3)
		{
			while (choice != "1" || choice != "2")
			{
				cout << "would you like to save?: (1) yes, (2)No" << endl;
				cin >> choice;
				if (stoi(choice) == 1)
				{
					Saver(*mainFloor.getPlayer());
					return;
				}
				else if (stoi(choice) == 2)
				{
					return;
				}
			}
		}
		else if (results == -1)
		{
			player.setHealth(player.getMaxHealth());
		}
	}
}

Player createPlayer()
{
	Player ret;
	int points = 10;

	sf::Font font;
	font.loadFromFile("../Fonts/Montserrat-Regular.ttf");

	sf::RenderWindow window(sf::VideoMode(800, 800), "Create Character");

	sf::Text HeaderText("Create Character", font, 30);
	HeaderText.setPosition(sf::Vector2f(10, 10));

	sf::Text name_text;
	name_text.setFont(font);
	name_text.setPosition(sf::Vector2f(10, 40));
	name_text.setString("Name: ");

	sf::Text skills_text;
	skills_text.setFont(font);
	skills_text.setPosition(sf::Vector2f(10, 70));
	skills_text.setString("you have " + to_string(points) + " remaining what would you like to upgrade");

	sf::Text ExitText("press Enter to confirm stats", font, 30);
	ExitText.setPosition(sf::Vector2f(10, 100));
	int name_Entered = 0;

	string name;

	vector<sf::Text> otherText;
	otherText.push_back(HeaderText);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				ret = Player();
			}
		}

		window.clear();
		//once points are 0 then displays confirm stats text and on enter it closes the window
		if (points <= 0)
		{
			window.draw(ExitText);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				window.close();
			}
		}

		name_text.setString("Name: " + name + "\n");
		window.draw(name_text);

		//only goes after name is entered and only while points left >0
		if (points > 0 && name_Entered == 1)
		{
			ret.addSkillPoint();
			points--;
			skills_text.setString("you have " + to_string(points) + " remaining what would you like to upgrade");
		}

		//only allows skills to be edited after name has been entered
		if (name_Entered > 0)
		{
			window.draw(skills_text);
			name_Entered = 1;
		}

		window.draw(HeaderText);

		window.display();
		//gets the players name only after first itteration so starter text will display
		if (name_Entered == 0)
		{
			name = getStringSFML(&window, otherText, name_text, "Name: ");
			ret.setName(name);
			name_Entered++;
		}
	}

	return ret;
}

//randomly generates a floor
Floor createFloor()
{
	//starting floor
	Floor f;

	int i;

	int j;

	//sets the internal Rooms
	for (i = 1; i < 9; i++)
	{
		for (j = 1; j < 9; j++)
		{
			switch (rand() % 4)
			{
			case 0:
				f.setRoom(createDefaultRoom_V1(), i, j);
				break;
			case 1:
				f.setRoom(createDefaultRoom_V2(), i, j);
				break;
			case 2:
				f.setRoom(createDefaultRoom_V3(), i, j);
				break;
			case 3:
				f.setRoom(createDefaultRoom_V4(), i, j);
				break;
			default:
				break;
			}
			// f.setRoom(createDefaultRoom_V3(), i, j);
		}
	}

	//sets the Left Rooms
	for (i = 1; i < 9; i++)
	{
		f.setRoom(createLeftRoom(), i, 0);
	}

	//sets the Right rooms
	for (i = 1; i < 9; i++)
	{
		f.setRoom(createRightRoom(), i, 9);
	}

	//sets the top Rooms
	for (i = 1; i < 9; i++)
	{
		f.setRoom(createUpRoom(), 0, i);
	}

	//sets the bootom rooms
	for (i = 1; i < 9; i++)
	{
		f.setRoom(createDownRoom(), 9, i);
	}

	//sets the corner rooms
	f.setRoom(createRoom0_0(), 0, 0);
	f.setRoom(createRoom9_0(), 9, 0);
	f.setRoom(createRoom9_9(), 9, 9);
	f.setRoom(createRoom0_9(), 0, 9);
	f.setRoom(createTreasureRoom_V1(), 1, 1);
	return f;
}

//the first thing the player sees chooses between 1: new Character, 2: Load Character, 3: exit, other?
int StartScreen()
{
	sf::Font font;
	font.loadFromFile("../Fonts/Montserrat-Regular.ttf");
	sf::RenderWindow window(sf::VideoMode(500, 300), "SFML works!");

	sf::Text text;
	text.setFont(font);
	text.setPosition(sf::Vector2f(10, 10));
	text.setString("Welcome to Linux Dungeon Crawl!\n1.New Character\n2.Load Character\n3.Exit");

	text.setCharacterSize(40);

	int ret = -1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				ret = -1;
			}
		}

		window.clear();
		window.draw(text);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			window.close();

			ret = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			window.close();

			ret = 2;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			window.close();

			ret = 3;
		}

		window.display();
	}
	return ret;
}

bool Saver(Player p)
{

	sf::Font font;
	font.loadFromFile("../Fonts/Montserrat-Regular.ttf");
	sf::RenderWindow window(sf::VideoMode(500, 500), "Save");

	sf::Text headerText("Save", font, 50);
	headerText.setPosition(sf::Vector2f(10, 10));

	sf::Text saveNameText("Enter Save Name: ", font, 30);
	saveNameText.setPosition(sf::Vector2f(10, 70));

	sf::Text errorText("there is already a save under this name.\nwould you like to replace it? \n[1]:Yes\n[2]:No", font, 30);
	errorText.setPosition(sf::Vector2f(10, 110));

	//Texts tobe shown while getting the name
	vector<sf::Text> Texts;
	Texts.push_back(headerText);

	//checks if a name has been entered
	bool nameEntered = false;
	//checks if error needs to be shown
	bool showError = false;
	//checks if key is released
	bool release = false;
	//name of the save file
	string saveName = "";
	//choice for overwriting or renaming
	int choice = 0;
	//vector of all save files
	vector<string> files;
	//temp document for reading in saves
	Document d;
	//temp string for loading in saves
	string temp;
	//in file
	ifstream infile;
	//counter for loops
	int i = 0;
	//position of the save to be overwritten if any -1 if not
	int pos = -1;

	//reads in all save files
	infile.open(saveLocation);
	while (getline(infile, temp))
	{
		files.push_back(temp);
	}
	infile.close();

	//main loop
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(headerText);
		window.draw(saveNameText);

		//if a file with same name exists
		if (showError)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				choice = 1;
				release = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				choice = 2;
				release = true;
			}
			else if (release)
			{
				//if overwritting the file
				if (choice == 1)
				{
					window.close();
				}
				//if reentering name
				else if (choice == 2)
				{

					nameEntered = false;
					showError = false;
					saveNameText.setString("Enter Save Name: ");
				}

				release = false;
			}
			//checks if still needs to show the error for asthetics
			if (showError)
			{
				window.draw(errorText);
			}
		}

		window.display();

		//checks if name is entered if not then gets one
		if (!nameEntered)
		{
			saveName = getStringSFML(&window, Texts, saveNameText, "Enter Save Name: ");
			nameEntered = true;
			saveNameText.setString("Enter Save Name: " + saveName);

			//loop to check if file name already exists
			for (i = 0; i < files.size(); i++)
			{
				d.Parse(files[i].c_str());
				//checks if file under name already exists
				if (saveName == d["SaveName"].GetString())
				{
					showError = true;
					pos = i;
				}
			}
			//checks if an error occured
			if (!showError)
			{
				window.close();
			}
		}
	}

	//if new save
	SaveFile newSave = SaveFile(p, saveName);
	if (pos != -1)
	{
		cout << "erasing" << endl;
		files.erase(files.begin() + pos);
	}

	//adds new file to back
	files.push_back(ConvertSaveFile2Json(newSave));

	ofstream outfile;
	outfile.open(saveLocation);
	for (i = 0; i < files.size(); i++)
	{
		outfile << files[i] << endl;
	}

	outfile.close();
	cout << "SAVED" << endl;
}

//prompts user for loading file
Player Loader()
{
	sf::Font font;
	font.loadFromFile("../Fonts/Montserrat-Regular.ttf");

	sf::RenderWindow window(sf::VideoMode(800, 800), "Load");

	sf::Text headerText("Load Save:", font, 50);
	headerText.setPosition(sf::Vector2f(10, 10));

	//up to 11 lines tall
	sf::Text fileText("Files:\n", font, 30);
	fileText.setPosition(sf::Vector2f(10, 60));

	sf::Text instructionText("Select an option or view next/previose set using arrows", font, 30);
	fileText.setPosition(sf::Vector2f(10, 90));

	//string of all file names to be displayed
	string fileNames = "";
	//checks for key release
	bool release = 0;
	//helps keep track of which file to select
	int fileAdder = 0;
	//vector of all the files loaded
	vector<string> files;
	//string used to load saves from file
	string temp;
	//integer marking file selection
	int choiceInt;
	//counter of currently displayed files. needs to start at 10
	int counter = 10;
	//trigger to change the file display
	bool showmore = true;
	bool exit = false;

	ifstream infile;
	infile.open(saveLocation);

	//loads all the saves to files vector
	while (getline(infile, temp))
	{
		files.push_back(temp);
	}
	//sets fileAdder initially to the max size
	fileAdder = files.size();
	Document d;

	//main loop
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){

				window.close();
			exit = true;
			}
		}

		//displays save files
		if (showmore)
		{
			showmore = false;
			//checks if there are any more files to display
			if (counter == 10)
			{
				counter = 0;
				fileNames = "";
				for (int i = fileAdder - 1; (i >= fileAdder - 10 && i >= 0); i--)
				{
					d.Parse(files[i].c_str());

					fileNames += "[" + to_string(counter) + "]:" + d["SaveName"].GetString() + ", " + d["CharacterName"].GetString() + ", " + d["Time"].GetString() + "\n";
					counter++;
				}
				//sets new files text
				fileText.setString("Files:\n" + fileNames);
				//sets position based on amount of files (still a bit wonky)
				instructionText.setPosition(sf::Vector2f(10, 90 + counter * 50));
			}
		}

		//Displays window
		window.clear();
		window.draw(headerText);
		window.draw(fileText);
		window.draw(instructionText);
		window.display();

		//checks for key presses
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && counter >= 0)
		{
			choiceInt = 0;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && counter >= 1)
		{
			choiceInt = 1;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && counter >= 2)
		{
			choiceInt = 2;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && counter >= 3)
		{
			choiceInt = 3;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && counter >= 4)
		{
			choiceInt = 4;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && counter >= 5)
		{
			choiceInt = 5;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && counter >= 6)
		{
			choiceInt = 6;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && counter >= 7)
		{
			choiceInt = 7;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && counter >= 8)
		{
			choiceInt = 8;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) && counter >= 9)
		{
			choiceInt = 9;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			choiceInt = -1;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			choiceInt = -2;
			release = 1;
		}
		else if (release == 1)
		{

			if (choiceInt == -1)
			{

				if (counter == 10 && fileAdder != 10)
				{
					fileAdder -= counter;
				}
				showmore = true;
			}
			else if (choiceInt == -2)
			{

				if (fileAdder != files.size())
				{
					fileAdder += 10;
				}
				showmore = true;
			}
			else
			{
				d.Parse(files[(fileAdder - 1) - choiceInt].c_str());
				window.close();
			}

			release = 0;
		}
	}

	infile.close();
	//if the window is closed return default character
	if (exit)
	{
		return (Player());
	}
	return ConvertJson2Player(d["Character"]);
}