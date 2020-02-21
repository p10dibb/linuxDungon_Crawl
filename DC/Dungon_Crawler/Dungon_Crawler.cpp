#include "Dungon_Crawler.h"

void Run()
{
	int results = 0;
	string choice = "";
	Spawner s;

	Player player;

	Floor mainFloor;

	switch (StartScreen())
	{
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
	//creates the main floor

	//runs the game
	while (1)
	{
		mainFloor = createFloor();

		//sets the player
		player.setPosition({1,1});
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
		}else if(results==-1){
			player.setHealth(player.getMaxHealth());
		}
	}
}

Player createPlayer()
{

	Player ret;

	string name;

	cout << "choose a name:" << endl;

	cin >> name;

	ret.setName(name);

	int points = 10;

	int input = 0;

	while (points != 0)
	{

		cout << "you have " << points << " remaining what would you like to upgrade?" << endl;

		ret.addSkillPoint();

		points--;
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
	char choice = '\0';
	while (1)
	{
		cout << "Welcome to Linux Dungeon Crawl!" << endl;
		cout << "1.New Character" << endl;
		cout << "2.Load Character" << endl;
		cout << "3.Exit" << endl;
		choice = getchar();
		switch (choice)
		{
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;

		default:
			break;
		}
	}
}

bool Saver(Player p)
{

	vector<string> files;
	string temp;
	ifstream infile;
	infile.open(saveLocation);
	while (getline(infile, temp))
	{
		files.push_back(temp);
	}
	cout << "Files Loaded: " << files.size() << endl;
	infile.close();
	string name;
	Document d;
	string choice = "";
	int i = 0, pos = -1;

	//loops untill name is picked
	while (1)
	{

		cout << "enter Save Name:";
		cin >> name;
		choice = -1;

		//itterates theough all the saves to compare name
		for (i = 0; i < files.size(); i++)
		{
			d.Parse(files[i].c_str());
			//checks if file under name already exists
			if (name == d["SaveName"].GetString())
			{
				while (choice != "1" && choice != "0")
				{
					cout << "thier is already a save under this name would you like to replace it? (0)No,(1)yes" << endl;
					cin >> choice;
				}
				cout << "thier is already a save under this name would you like to replace it? (0)No,(1)yes" << endl;

				//if they want to overwrite
				if (choice == "1")
				{
					pos = i;
					i = files.size();
					break;
				}
				else
				{
					break;
				}
			}
		}
		//if time to save break loop
		if (i == files.size())
		{
			break;
		}
	}

	//if new save
	SaveFile newSave = SaveFile(p, name);
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

	vector<string> files;
	string temp, choice;
	int choiceInt;
	ifstream infile;
	infile.open(saveLocation);

	while (getline(infile, temp))
	{
		files.push_back(temp);
	}
	Document d;
	for (int i = files.size() - 1; i >= 0; i--)
	{
		d.Parse(files[i].c_str());
		cout << files.size() - i << ":" << d["SaveName"].GetString() << ", " << d["CharacterName"].GetString() << ", " << d["Time"].GetString() << endl;
	}
	while (1)
	{
		cout << "which file would you like: " << endl;
		cin >> choice;
		choiceInt = stoi(choice);
		if (choiceInt > 0 && choiceInt <= files.size())
			break;
	}

	d.Parse(files[files.size() - choiceInt].c_str());

	infile.close();

	return ConvertJson2Player(d["Character"]);
}