#include "Shop.h"

//sets level to 1 and money to 250-500
Shop::Shop()
{
    this->Level = 1;
    this->Money = rand() % 250 + 250;
    this->GenerateNewInventory();
    this->setPosition({5, 5});
}

//sets Level to level and money to 250-500
Shop::Shop(int level)
{
    this->Level = level;
    this->Money = rand() % 250 + 250;
    this->GenerateNewInventory();
    this->setPosition({5, 5});
}

//sets Level to level and Money to money
Shop::Shop(int level, int money)
{
    this->Level = level;
    this->Money = money;
    this->GenerateNewInventory();
    this->setPosition({5, 5});
}

//checks if money is > amount and subtracts from there and returns amount;
int Shop::GiveMoney(int amount)
{
    if (this->getMoney() > amount)
    {
        this->setMoney(this->getMoney() - amount);
        return amount;
    }
    return 0;
}

//adds amount to money;
bool Shop::RecieveMoney(int amount)
{
    if (amount > 0)
    {
        this->setMoney(this->getMoney() + amount);
        return true;
    }
    return false;
}

//getter for money
int Shop::getMoney()
{
    return this->Money;
}
//setter for money;
void Shop::setMoney(int amount)
{
    this->Money = amount;
}

//checks if room in store and adds item
bool Shop::AddItemToInventory(Item *item)
{
    //searches for "Empty Item"
    for (int i = 0; i < this->Inventory.size(); i++)
    {
        if (this->Inventory[i]->getName() == "Empty")
        {
            this->Inventory[i] = item;
            return true;
        }
    }
    // cout << "inventory full Item discarded" << endl;
    this->Inventory.push_back(item);
    return false; //failed to add to inventory
}

//removes the Item from the inventory. and returns it.
Item *Shop::RemoveItemFromInventory(int position)
{
    Item *ret;
    //checks if position is valid
    if (position >= 0 && position < this->Inventory.size())
    {
        ret = this->Inventory[position];
        this->Inventory[position] = new Item();
        return ret;
    }
    return NULL; //not valid position
}

//shows the inventory
void Shop::DisplayInventory()
{
    cout << "index\tName\tPrice" << endl;
    for (int i = 0; i < this->Inventory.size(); i++)
    {
        cout << i << "\t" << this->Inventory[i]->getName() << "\t" << this->Inventory[i]->getValue() << endl;
    }
}

//Displays all Shopping options.
void Shop::ShopDialogue(Player *player)
{
    //0:main page 1:buy 2:sell
    int mode = 0;

    int choice = 0;

    int current = 0;

    bool release;

    bool showError = false;

    Direction_enum direct = No_Direction;

    Item *toBeSold;
    int itemPrice = 0;

    sf::Font font;
    font.loadFromFile("../Fonts/Montserrat-Regular.ttf");
    sf::RenderWindow window(sf::VideoMode(800, 800), "Shop");

    sf::RectangleShape infoBox(sf::Vector2f(300, 500));
    infoBox.setFillColor(sf::Color::Blue);
    infoBox.setPosition(sf::Vector2f(450, 30));

    //name of the item
    sf::Text itemNameText("Name: ", font, 30);
    itemNameText.setPosition(sf::Vector2f(460, 60));

    //info tags of each item
    sf::Text itemInfo("", font, 20);
    itemInfo.setPosition(sf::Vector2f(460, 100));

    //values corolating to each tag
    sf::Text itemValues("", font, 20);
    itemValues.setPosition(sf::Vector2f(590, 100));

    //the description of the item
    sf::Text itemDescription("", font, 20);

    //the text for extra info
    sf::Text otherInfoText("", font, 20);

    sf::Text commands("[1]:Buy [2]:Sell [3]:Exit", font, 30);
    commands.setPosition(10, 400);

    sf::RectangleShape storeFront(sf::Vector2f(600, 400));
    storeFront.setPosition(sf::Vector2f(50, 50));
    storeFront.setFillColor(sf::Color::Red);

    sf::Text shopContents("", font, 30);
    shopContents.setPosition(sf::Vector2f(10, 40));

    string contentsString = "";

    sf::RectangleShape highlighter(sf::Vector2f(200, 30));
    highlighter.setFillColor(sf::Color::Red);
    highlighter.setPosition(sf::Vector2f(10, 40));

    sf::Text ErrorText("", font, 30);
    ErrorText.setPosition(sf::Vector2f(400, 400));

    array<sf::RectangleShape, 100> slots;

    //sets all of the item slots
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            slots[(i * 10) + j].setSize(sf::Vector2f(30, 30));
            slots[(i * 10) + j].setFillColor(sf::Color::Blue);
            slots[(i * 10) + j].setPosition(sf::Vector2f(10 + (42 * j), 50 + (42 * i)));
        }
    }

    sf::RectangleShape slotHighlighter;
    sf::Text Gold(player->getName() + ": " + to_string(player->getMoney()) + " Shop: " + to_string(this->getMoney()), font, 30);
    Gold.setPosition(sf::Vector2f(300, 300));

    slotHighlighter.setFillColor(sf::Color::Cyan);
    slotHighlighter.setSize(sf::Vector2f(40, 40));
    slotHighlighter.setPosition(sf::Vector2f(slots[current].getPosition().x - 5, slots[current].getPosition().y - 5));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(Gold);
        if (mode == 0)
        {
            window.draw(storeFront);
        }
        else if (mode == 1)
        {
            window.draw(infoBox);
            window.draw(itemNameText);
            window.draw(itemValues);
            window.draw(itemInfo);
            window.draw(itemDescription);
            window.draw(otherInfoText);
            if (this->Inventory.size() > 0)
            {
                window.draw(highlighter);
            }
            window.draw(shopContents);
            if (showError)
            {
                window.draw(ErrorText);
            }
        }
        else if (mode == 2)
        {
            window.draw(infoBox);
            window.draw(itemNameText);
            window.draw(itemValues);
            window.draw(itemInfo);
            window.draw(itemDescription);
            window.draw(otherInfoText);
            window.draw(slotHighlighter);
            for (int k = 0; k < player->getInventorySize(); k++)
            {
                window.draw(slots[k]);
            }
            if (showError)
            {
                window.draw(ErrorText);
            }
        }

        window.draw(commands);

        window.display();

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
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        {
            choice = 3;
            release = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            direct = Left_Direction;
            release = true;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            direct = Up_Direction;
            release = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            direct = Right_Direction;
            release = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            direct = Down_Direction;
            release = true;
        }
        else if (release)
        {
            if (mode == 0)
            {
                switch (choice)
                {
                case 1:
                    mode = 1;
                    commands.setString("[1]:Back [2]:Buy");
                    contentsString = "";
                    for (int i = 0; i < this->Inventory.size(); i++)
                    {
                        contentsString += to_string(this->Inventory[i]->getValue() * this->SellMerchantMultiplier) + " " + this->Inventory[i]->getName() + "\n";
                    }
                    shopContents.setString(contentsString);

                    current = 0;

                    if ((typeid(*this->Inventory[current]) == typeid(Armor)))
                    {
                        Armor *a = dynamic_cast<Armor *>(this->Inventory[current]);
                        itemNameText.setString(a->getName());
                        itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nClass:\nType:\n");
                        itemValues.setString(to_string(a->getLevel()) + "\n" + to_string(a->getTotalResistance()) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getWeight()) + "\n" + armorClass_toString(a->getClass()) + "\n" + armorType_toString(a->getType()));
                        itemDescription.setPosition(sf::Vector2f(460, 250));
                        itemDescription.setString(a->getDescription());

                        string resistances = "Resistances:\n";
                        vector<ActiveEffects> temp = a->getResistanceTypes();

                        for (int g = 0; g < temp.size(); g++)
                        {

                            if (temp[g].getResistance() > 0)
                            {
                                resistances += temp[g].getEffectName() + "\t" + to_string(temp[g].getResistance()) + "\n";
                            }
                        }

                        otherInfoText.setString(resistances);

                        otherInfoText.setPosition(sf::Vector2f(460, 280));
                    }
                    else if ((typeid(*this->Inventory[current]) == typeid(Weapon)))
                    {
                        Weapon *a = dynamic_cast<Weapon *>(this->Inventory[current]);

                        itemNameText.setString(a->getName());

                        itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nDefense:\nSpeed:\nRarity:\nEffect:\n");
                        itemValues.setString(to_string(a->getLevel()) + "\n" + to_string(a->getWeaponRank()) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getWeight()) + "\n" + to_string(a->getDefense().getResistance()) + "\n" + to_string(a->getSpeed()) + "\n" + a->getRarity_text() + "\n" + a->getCombatEffect().getEffectName());

                        itemDescription.setPosition(sf::Vector2f(460, 300));
                        itemDescription.setString(a->getDescription());

                        string damages = "Damage Types:\n";
                        vector<DamageTypes> temp = a->getDamageTypes_Weapon();

                        for (int g = 0; g < temp.size(); g++)
                        {

                            if (temp[g].getDamage() > 0)
                            {
                                damages += temp[g].getName() + "\t" + to_string(temp[g].getDamage()) + "\n";
                            }
                        }

                        otherInfoText.setString(damages);

                        otherInfoText.setPosition(sf::Vector2f(460, 330));
                    }
                    else if ((typeid(*this->Inventory[current]) == typeid(Potion)))
                    {
                        Potion *a = dynamic_cast<Potion *>(this->Inventory[current]);
                        itemNameText.setString(a->getName());

                        itemInfo.setString("Value:\nTier:\nType:");
                        itemValues.setString(to_string(a->getValue()) + "\n" + to_string(a->getTier()) + "\n" + a->getTypeName());
                        itemDescription.setPosition(sf::Vector2f(460, 200));
                        itemDescription.setString(a->getDescription());
                    }
                    else if (this->Inventory[current]->getName() == "Empty")
                    {
                        itemNameText.setString("");

                        itemInfo.setString("");
                        itemValues.setString("");
                        itemDescription.setString("");
                        otherInfoText.setString("");
                    }
                    else
                    {

                        itemNameText.setString(this->Inventory[current]->getName());
                        itemInfo.setString("");
                        itemValues.setString("");
                        itemDescription.setString("");
                        otherInfoText.setString("");
                    }

                    break;
                case 2:
                    mode = 2;
                    commands.setString("[1]:Back [2]:Sell");
                    current=0;
                    slotHighlighter.setPosition(sf::Vector2f(slots[current].getPosition().x - 5, slots[current].getPosition().y - 5));

                    if ((typeid(*player->getInventory()[current].item) == typeid(Armor)))
                    {
                        Armor *a = dynamic_cast<Armor *>(player->getInventory()[current].item);
                        itemNameText.setString(a->getName());
                        itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nClass:\nType:\n");
                        itemValues.setString(to_string(a->getLevel()) + "\n" + to_string(a->getTotalResistance()) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getWeight()) + "\n" + armorClass_toString(a->getClass()) + "\n" + armorType_toString(a->getType()));
                        itemDescription.setPosition(sf::Vector2f(460, 250));
                        itemDescription.setString(a->getDescription());

                        string resistances = "Resistances:\n";
                        vector<ActiveEffects> temp = a->getResistanceTypes();

                        for (int g = 0; g < temp.size(); g++)
                        {

                            if (temp[g].getResistance() > 0)
                            {
                                resistances += temp[g].getEffectName() + "\t" + to_string(temp[g].getResistance()) + "\n";
                            }
                        }

                        otherInfoText.setString(resistances);

                        otherInfoText.setPosition(sf::Vector2f(460, 280));
                    }
                    else if ((typeid(*player->getInventory()[current].item) == typeid(Weapon)))
                    {
                        Weapon *a = dynamic_cast<Weapon *>(player->getInventory()[current].item);
                        itemNameText.setString(a->getName());

                        itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nDefense:\nSpeed:\nRarity:\nEffect:\n");
                        itemValues.setString(to_string(a->getLevel()) + "\n" + to_string(a->getWeaponRank()) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getWeight()) + "\n" + to_string(a->getDefense().getResistance()) + "\n" + to_string(a->getSpeed()) + "\n" + a->getRarity_text() + "\n" + a->getCombatEffect().getEffectName());

                        itemDescription.setPosition(sf::Vector2f(460, 300));
                        itemDescription.setString(a->getDescription());

                        string damages = "Damage Types:\n";
                        vector<DamageTypes> temp = a->getDamageTypes_Weapon();

                        for (int g = 0; g < temp.size(); g++)
                        {

                            if (temp[g].getDamage() > 0)
                            {
                                damages += temp[g].getName() + "\t" + to_string(temp[g].getDamage()) + "\n";
                            }
                        }

                        otherInfoText.setString(damages);

                        otherInfoText.setPosition(sf::Vector2f(460, 330));
                    }
                    else if ((typeid(*player->getInventory()[current].item) == typeid(Potion)))
                    {
                        Potion *a = dynamic_cast<Potion *>(player->getInventory()[current].item);
                        itemNameText.setString(a->getName());

                        itemInfo.setString("Amount:\nValue:\nTier:\nType:");
                        itemValues.setString(to_string(player->getInventory()[current].amount) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getTier()) + "\n" + a->getTypeName());
                        itemDescription.setPosition(sf::Vector2f(460, 200));
                        itemDescription.setString(a->getDescription());
                    }
                    else if (player->getInventory()[current].item->getName() == "Empty")
                    {
                        itemNameText.setString("Empty");

                        itemInfo.setString("");
                        itemValues.setString("");
                        itemDescription.setString("");
                        otherInfoText.setString("");
                    }
                    else
                    {

                        itemNameText.setString(player->getInventory()[current].item->getName());
                        itemInfo.setString("");
                        itemValues.setString("");
                        itemDescription.setString("");
                        otherInfoText.setString("");
                        //normal item
                    }
                    break;
                case 3:
                    window.close();
                default:
                    break;
                }
            }
            else if (mode == 1)
            {
                switch (choice)
                {
                case 1:
                    mode = 0;
                    commands.setString("[1]:Buy [2]:Sell [3]:Exit");
                    showError = false;

                    break;

                case 2:
                    toBeSold = this->RemoveItemFromInventory(current);
                    itemPrice = toBeSold->getValue() * this->SellMerchantMultiplier;
                    if (current != 0)
                    {
                        current--;
                    }
                    if (player->GiveMoney(itemPrice) != 0)
                    {
                        //puts item in players inventory
                        player->addToInventory(toBeSold);
                        //gives store the money
                        this->RecieveMoney(itemPrice);
                        showError = false;
                        Gold.setString(player->getName() + ": " + to_string(player->getMoney()) + " Shop: " + to_string(this->getMoney()));
                    }
                    else
                    { // if player could not afford item
                        ErrorText.setString("not enough gold");
                        //add item back to store inventory;
                        this->AddItemToInventory(toBeSold);

                        showError = true;
                    }
                    break;

                default:
                    break;
                }
                for (int i = 0; i < this->Inventory.size(); i++)
                {
                    contentsString += to_string(this->Inventory[i]->getValue() * this->SellMerchantMultiplier) + " " + this->Inventory[i]->getName() + "\n";
                }
                shopContents.setString(contentsString);

                switch (direct)
                {
                case Up_Direction:
                    if (current == 0)
                    {
                        current = this->Inventory.size() - 1;
                    }
                    else
                    {
                        current--;
                    }
                    break;
                case Down_Direction:
                    if (current < Inventory.size() - 1)
                    {
                        current++;
                    }
                    else
                    {
                        current = 0;
                    }
                default:
                    break;
                }

                if ((typeid(*this->Inventory[current]) == typeid(Armor)))
                {
                    Armor *a = dynamic_cast<Armor *>(this->Inventory[current]);
                    itemNameText.setString(a->getName());
                    itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nClass:\nType:\n");
                    itemValues.setString(to_string(a->getLevel()) + "\n" + to_string(a->getTotalResistance()) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getWeight()) + "\n" + armorClass_toString(a->getClass()) + "\n" + armorType_toString(a->getType()));
                    itemDescription.setPosition(sf::Vector2f(460, 250));
                    itemDescription.setString(a->getDescription());

                    string resistances = "Resistances:\n";
                    vector<ActiveEffects> temp = a->getResistanceTypes();

                    for (int g = 0; g < temp.size(); g++)
                    {

                        if (temp[g].getResistance() > 0)
                        {
                            resistances += temp[g].getEffectName() + "\t" + to_string(temp[g].getResistance()) + "\n";
                        }
                    }

                    otherInfoText.setString(resistances);

                    otherInfoText.setPosition(sf::Vector2f(460, 280));
                }
                else if ((typeid(*this->Inventory[current]) == typeid(Weapon)))
                {
                    Weapon *a = dynamic_cast<Weapon *>(this->Inventory[current]);

                    itemNameText.setString(a->getName());

                    itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nDefense:\nSpeed:\nRarity:\nEffect:\n");
                    itemValues.setString(to_string(a->getLevel()) + "\n" + to_string(a->getWeaponRank()) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getWeight()) + "\n" + to_string(a->getDefense().getResistance()) + "\n" + to_string(a->getSpeed()) + "\n" + a->getRarity_text() + "\n" + a->getCombatEffect().getEffectName());

                    itemDescription.setPosition(sf::Vector2f(460, 300));
                    itemDescription.setString(a->getDescription());

                    string damages = "Damage Types:\n";
                    vector<DamageTypes> temp = a->getDamageTypes_Weapon();

                    for (int g = 0; g < temp.size(); g++)
                    {

                        if (temp[g].getDamage() > 0)
                        {
                            damages += temp[g].getName() + "\t" + to_string(temp[g].getDamage()) + "\n";
                        }
                    }

                    otherInfoText.setString(damages);

                    otherInfoText.setPosition(sf::Vector2f(460, 330));
                }
                else if ((typeid(*this->Inventory[current]) == typeid(Potion)))
                {
                    Potion *a = dynamic_cast<Potion *>(this->Inventory[current]);
                    itemNameText.setString(a->getName());

                    itemInfo.setString("Value:\nTier:\nType:");
                    itemValues.setString(to_string(a->getValue()) + "\n" + to_string(a->getTier()) + "\n" + a->getTypeName());
                    itemDescription.setPosition(sf::Vector2f(460, 200));
                    itemDescription.setString(a->getDescription());
                }
                else if (this->Inventory[current]->getName() == "Empty")
                {
                    itemNameText.setString("a->getName()");

                    itemInfo.setString("");
                    itemValues.setString("");
                    itemDescription.setString("");
                    otherInfoText.setString("");
                }
                else
                {

                    itemNameText.setString(this->Inventory[current]->getName());
                    itemInfo.setString("");
                    itemValues.setString("");
                    itemDescription.setString("");
                    otherInfoText.setString("");
                }
                contentsString = "";
                for (int i = 0; i < this->Inventory.size(); i++)
                {
                    contentsString += to_string(this->Inventory[i]->getValue() * this->SellMerchantMultiplier) + " " + this->Inventory[i]->getName() + "\n";
                }
                shopContents.setString(contentsString);

                highlighter.setPosition(10, 45 + (current * 35));
            }
            else if (mode == 2)
            {
                switch (choice)
                {
                case 1:
                    mode = 0;
                    commands.setString("[1]:Buy [2]:Sell [3]:Exit");
                    showError = false;
                    break;
                case 2: //retrieves the item to be sold from player inventory
                    toBeSold = player->RemoveItemFromInventory(current);
                    //calculates price of the item
                    itemPrice = toBeSold->getValue() * this->BuyMerchantMultiplier;
                    if (this->GiveMoney(itemPrice) != 0 || itemPrice == 0)
                    { //if store can afford

                        //adds item to store inventory
                        this->AddItemToInventory(toBeSold);
                        //gives player the money
                        player->RecieveMoney(itemPrice);
                        Gold.setString(player->getName() + ": " + to_string(player->getMoney()) + " Shop: " + to_string(this->getMoney()));
                    }
                    else
                    { //if store cant afford

                        ErrorText.setString("Store cannot afford Item");
                        //add item back to players inventory
                        player->addToInventory(toBeSold);
                    }

                default:
                    break;
                }

                //checks for moving through inventory
                if (direct == Up_Direction && current >= 10)
                {
                    current -= 10;
                }
                else if (direct == Down_Direction && current <= player->getInventorySize() - 10)
                {
                    current += 10;
                }
                else if (direct == Left_Direction && current != 0)
                {
                    current--;
                }
                else if (direct == Right_Direction && current < player->getInventorySize() - 1)
                {
                    current++;
                }

                slotHighlighter.setPosition(sf::Vector2f(slots[current].getPosition().x - 5, slots[current].getPosition().y - 5));

                if ((typeid(*player->getInventory()[current].item) == typeid(Armor)))
                {
                    Armor *a = dynamic_cast<Armor *>(player->getInventory()[current].item);
                    itemNameText.setString(a->getName());
                    itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nClass:\nType:\n");
                    itemValues.setString(to_string(a->getLevel()) + "\n" + to_string(a->getTotalResistance()) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getWeight()) + "\n" + armorClass_toString(a->getClass()) + "\n" + armorType_toString(a->getType()));
                    itemDescription.setPosition(sf::Vector2f(460, 250));
                    itemDescription.setString(a->getDescription());

                    string resistances = "Resistances:\n";
                    vector<ActiveEffects> temp = a->getResistanceTypes();

                    for (int g = 0; g < temp.size(); g++)
                    {

                        if (temp[g].getResistance() > 0)
                        {
                            resistances += temp[g].getEffectName() + "\t" + to_string(temp[g].getResistance()) + "\n";
                        }
                    }

                    otherInfoText.setString(resistances);

                    otherInfoText.setPosition(sf::Vector2f(460, 280));
                }
                else if ((typeid(*player->getInventory()[current].item) == typeid(Weapon)))
                {
                    Weapon *a = dynamic_cast<Weapon *>(player->getInventory()[current].item);
                    itemNameText.setString(a->getName());

                    itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nDefense:\nSpeed:\nRarity:\nEffect:\n");
                    itemValues.setString(to_string(a->getLevel()) + "\n" + to_string(a->getWeaponRank()) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getWeight()) + "\n" + to_string(a->getDefense().getResistance()) + "\n" + to_string(a->getSpeed()) + "\n" + a->getRarity_text() + "\n" + a->getCombatEffect().getEffectName());

                    itemDescription.setPosition(sf::Vector2f(460, 300));
                    itemDescription.setString(a->getDescription());

                    string damages = "Damage Types:\n";
                    vector<DamageTypes> temp = a->getDamageTypes_Weapon();

                    for (int g = 0; g < temp.size(); g++)
                    {

                        if (temp[g].getDamage() > 0)
                        {
                            damages += temp[g].getName() + "\t" + to_string(temp[g].getDamage()) + "\n";
                        }
                    }

                    otherInfoText.setString(damages);

                    otherInfoText.setPosition(sf::Vector2f(460, 330));
                }
                else if ((typeid(*player->getInventory()[current].item) == typeid(Potion)))
                {
                    Potion *a = dynamic_cast<Potion *>(player->getInventory()[current].item);
                    itemNameText.setString(a->getName());

                    itemInfo.setString("Amount:\nValue:\nTier:\nType:");
                    itemValues.setString(to_string(player->getInventory()[current].amount) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getTier()) + "\n" + a->getTypeName());
                    itemDescription.setPosition(sf::Vector2f(460, 200));
                    itemDescription.setString(a->getDescription());
                }
                else if (player->getInventory()[current].item->getName() == "Empty")
                {
                    itemNameText.setString("Empty");

                    itemInfo.setString("");
                    itemValues.setString("");
                    itemDescription.setString("");
                    otherInfoText.setString("");
                }
                else
                {

                    itemNameText.setString(player->getInventory()[current].item->getName());
                    itemInfo.setString("");
                    itemValues.setString("");
                    itemDescription.setString("");
                    otherInfoText.setString("");
                    //normal item
                }
            }

            choice = 0;
            direct = No_Direction;
            release = false;
        }
    }

    // string playerChoice = "";
    // cout << "welcome to the store" << endl;
    // while (playerChoice != "exit")
    // {
    //     cout << "Store Inventory:" << endl;
    //     cout << "Gold: " << this->getMoney();
    //     this->DisplayInventory();
    //     cout << "what would you like to do? [Exit|Buy|Sell|View|I(view Inventory)|E(view Equiped)]" << endl;
    //     cin >> playerChoice;
    //     playerChoice = toLower(playerChoice);

    //     if (playerChoice == "exit")
    //     {
    //         cout << "Exiting Store" << endl;
    //     }
    //     else if (playerChoice == "buy")
    //     {
    //         this->SellItem(player);
    //     }
    //     else if (playerChoice == "sell")
    //     {
    //         this->PurchaseItem(player);
    //     }
    //     else if (playerChoice == "view")
    //     {
    //         this->ViewItem();
    //     }
    //     else if (playerChoice == "i")
    //     {
    //         player->InventoryDialogue();
    //     }
    //     else if (playerChoice == "e")
    //     {
    //         player->EquipedDialogue();
    //     }
    //     else
    //     {
    //         cout << "Not Valid choice" << endl;
    //     }
    // }
}

//the shop purchases item from the player
bool Shop::PurchaseItem(Player *player)
{
    //the players input
    int playerChoice = -2;
    //the item the player is selling
    Item *toBeSold;
    //the amount the merchant cuts off the value
    double merchantMultiplier = .8;
    // the price the item is sold for
    int itemPrice = 0;

    while (1)
    {
        cout << "What item would you like to sell(-1 to cancel):" << endl;
        player->DisplayInventory();
        cin >> playerChoice;
        //if player wants to exit
        if (playerChoice == -1)
        {
            cout << "exiting transaction" << endl;
            return true; //successful transaction
        }
        //if player chooses valid inventory slot
        if (player->getInventorySize() > playerChoice && playerChoice >= 0)
        {

            //retrieves the item to be sold from player inventory
            toBeSold = player->RemoveItemFromInventory(playerChoice);
            //calculates price of the item
            itemPrice = toBeSold->getValue() * this->BuyMerchantMultiplier;

            //while valid choice is not chosen
            while (1)
            {
                cout << "you are selling " << toBeSold->getName() << "for " << itemPrice << "gold do you approve of this transaction? (yes:1,No:0)" << endl;
                cin >> playerChoice;

                if (playerChoice == 1)
                { //if player chooses yes

                    if (this->GiveMoney(itemPrice) != 0 || itemPrice == 0)
                    { //if store can afford

                        //adds item to store inventory
                        this->AddItemToInventory(toBeSold);
                        //gives player the money
                        player->RecieveMoney(itemPrice);
                        cout << player->getName() << " recieved " << itemPrice << " gold" << endl;
                        return true; //successfull transaction
                    }
                    else
                    { //if store cant afford
                        cout << "Store cannot afford Item Transaction Canceled" << endl;
                        //add item back to players inventory
                        player->addToInventory(toBeSold);
                        return false; //unsuccesful transaction
                    }
                }
                else if (playerChoice == 0)
                { //if player chooses No
                    cout << "Transaction Canceled" << endl;
                    //item added back to players inventory
                    player->addToInventory(toBeSold);
                    return false; //unsucsesful transactuon
                }
                else
                { //non valid choice
                    cout << "invalid choice" << endl;
                }
            }
        }
        else
        { //if not valid choice
            cout << "not valid choice" << endl;
        }
    }
    return false; //to make syntax happy
}

//sells item to the player
bool Shop::SellItem(Player *player)
{

    //the players input
    int playerChoice = -2;
    //the item the player is selling
    Item *toBeSold;
    //the amount the merchant adds to the value
    double merchantMultiplier = 1.2;
    // the price the item is sold for
    int itemPrice;

    while (1)
    {
        // this->DisplayInventory();
        // cout << "What item would you like to buy(-1 to cancel):" << endl;

        // cin >> playerChoice;
        // //if player wants to exit
        // if (playerChoice == -1)
        // {
        //     cout << "exiting transaction" << endl;
        //     return true; //successful transaction
        // }
        if (playerChoice >= 0 && playerChoice < this->Inventory.size())
        {
            toBeSold = this->RemoveItemFromInventory(playerChoice);
            itemPrice = toBeSold->getValue() * this->SellMerchantMultiplier;
            while (1)
            {
                cout << "would you like to buy " << toBeSold->getName() << " for " << itemPrice << " gold?(yes:1, No:0)" << endl;
                cin >> playerChoice;
                if (playerChoice == 1)
                {
                    if (player->GiveMoney(itemPrice) != 0)
                    {
                        //puts item in players inventory
                        player->addToInventory(toBeSold);
                        //gives store the money
                        this->RecieveMoney(itemPrice);
                        cout << "transaction succesfull " << player->getName() << " has reciece " << toBeSold->getName();
                        return true; //successful transaction
                    }
                    else
                    { // if player could not afford item
                        cout << player->getName() << " does not have enough gold. Transaction Canceled" << endl;
                        //add item back to store inventory;
                        this->AddItemToInventory(toBeSold);
                        return false; //unsucsesful transaction
                    }
                }
                else if (playerChoice == 0)
                { //if player chose no
                    cout << "Transaction Canceled" << endl;
                    return false; // unsuccsesful Transaction
                }
                else
                { //if not a valid choice
                    cout << "Not a valid choice" << endl;
                }
            }
        }
    }
    return false; //make syntax happy
}

//gets the specific item from the inventory;
Item *Shop::getItem(int position)
{
    if (position >= 0 && position <= 20)
    {
        return this->Inventory[position];
    }
    return NULL;
}

//getter for Level
int Shop::getLevel()
{
    return this->Level;
}
//setter for Level and generates new inventory that matches the level
void Shop::setLevel(int level)
{
    if (level < 1)
    {
        level = 1;
    }
    this->Level = level;
    this->GenerateNewInventory();
}

//will generate 10 items at "random"
void Shop::GenerateNewInventory()
{
    int i = 0;
    int randValue = 0;
    int classVal = 0;
    //sets all inventory to NULL
    // for (i = 0; i < 20; i++)
    // {
    //     this->Inventory[i] = new Item();
    // }

    for (i = 0; i < 10; i++)
    {

        randValue = rand() % 100;

        //20% chance of armour
        if (randValue < 20)
        {
            classVal = rand() % 3 + 1;
            randValue = rand() % 5;
            //20% chance of each armour type
            if (randValue == 0)
            {
                this->Inventory.push_back(this->spawner.CreateHelmet(this->getLevel(), (ArmorClass_enum)classVal));
            }
            else if (randValue == 1)
            {
                this->Inventory.push_back(this->spawner.CreateChest(this->getLevel(), (ArmorClass_enum)classVal));
            }
            else if (randValue == 2)
            {
                this->Inventory.push_back(this->spawner.CreateGloves(this->getLevel(), (ArmorClass_enum)classVal));
            }
            else if (randValue == 3)
            {
                this->Inventory.push_back(this->spawner.CreatePants(this->getLevel(), (ArmorClass_enum)classVal));
            }
            else if (randValue == 4)
            {
                this->Inventory.push_back(this->spawner.CreateBoots(this->getLevel(), (ArmorClass_enum)classVal));
            }
        }
        //30 % chance of Weapon
        else if (randValue >= 20 && randValue < 50)
        {
            //25 % chance for each weapon except claws they have 0%S
            randValue = rand() % 4;
            if (randValue == 0)
            {
                this->Inventory.push_back(this->spawner.CreateAxe(this->getLevel()));
            }
            else if (randValue == 1)
            {
                this->Inventory.push_back(this->spawner.CreateDagger(this->getLevel()));
            }
            else if (randValue == 2)
            {
                this->Inventory.push_back(this->spawner.CreateSword(this->getLevel()));
            }
            else if (randValue == 3)
            {
                this->Inventory.push_back(this->spawner.CreateShield(this->getLevel()));
            }
        }
        //50% chance of potion
        else
        {
            this->Inventory.push_back(spawner.CreateRandomPotion_MoreHealth());
        }
    }
}

void Shop::ViewItem()
{
    int playerChoice = -2;
    Item *viewable;

    while (playerChoice != -1)
    {
        this->DisplayInventory();
        cout << "which item would you like to see?(-1 to exit)" << endl;
        cin >> playerChoice;
        if (playerChoice > 0 && playerChoice <= this->Inventory.size())
        {
            viewable = this->getItem(playerChoice);

            if (viewable->getName() == "Empty")
            {
                cout << "this is an empty slot" << endl;
            }
            else if (typeid(*viewable) == typeid(Weapon))
            {

                Weapon *w = dynamic_cast<Weapon *>(viewable);
                w->DisplayDetails();
            }
            else if ((typeid(*viewable) == typeid(Armor)))
            {
                Armor *a = dynamic_cast<Armor *>(viewable);
                a->DisplayDetails();
            }
            else if ((typeid(*viewable) == typeid(Potion)))
            {
                Potion *a = dynamic_cast<Potion *>(viewable);
                a->DisplayDetails();
            }
        }
        else
        {
            cout << "not a valid choice" << endl;
        }
        getchar();
        getchar();
    }
}

//get the shops position
array<int, 2> Shop::getPosition()
{
    return this->Position;
}

//sets the shops position if out of bounds it will set shop to 5,5
void Shop::setPosition(array<int, 2> pos)
{
    if (pos[0] > 8 || pos[0] < 1)
    {
        pos[0] = 5;
    }
    if (pos[1] > 8 || pos[1] < 1)
    {
        pos[1] = 5;
    }
    this->Position = pos;
}
