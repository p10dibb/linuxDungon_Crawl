#include "Shop.h"

//sets level to 1 and money to 250-500
Shop::Shop(){
    this->Level=1;
    this->Money=rand()%250 +250;
    this->GenerateNewInventory();
    this->setPosition({5,5});
}

//sets Level to level and money to 250-500
Shop::Shop(int level){
    this->Level=level;
    this->Money=rand()%250 +250;
    this->GenerateNewInventory();
    this->setPosition({5,5});
}

//sets Level to level and Money to money
Shop::Shop(int level, int money){
    this->Level=level;
    this->Money=money;
    this->GenerateNewInventory();
    this->setPosition({5,5});
}

//checks if money is > amount and subtracts from there and returns amount;
int Shop::GiveMoney(int amount){
    if (this->getMoney()>amount){
        this->setMoney(this->getMoney()-amount);
        return amount;
    }
    return 0;
}

//adds amount to money;
bool Shop::RecieveMoney(int amount){
    if (amount>0){
        this->setMoney(this->getMoney()+amount);
        return true;
    }
    return false;
}

//getter for money
int Shop::getMoney(){
    return this->Money;
}
//setter for money;
void Shop::setMoney(int amount){
    this->Money=amount;
}

//checks if room in store and adds item
bool Shop::AddItemToInventory(Item *item){
    //searches for "Empty Item"
    for(int i=0;i<this->InventorySize;i++){
        if (this->Inventory[i]->getName()=="Empty"){
            this->Inventory[i]=item;
            return true;
        }
    }
    cout<<"inventory full Item discarded"<<endl;
    return false;//failed to add to inventory

}

//removes the Item from the inventory. and returns it.
Item* Shop::RemoveItemFromInventory(int position){
    Item *ret;
    //checks if position is valid
    if (position>=0 &&position<this->InventorySize){
        ret=this->Inventory[position];
        this->Inventory[position]=new Item();
        return ret;
    }
    return NULL;//not valid position
}

//shows the inventory
void Shop::DisplayInventory(){
    cout<<"index\tName\tPrice"<<endl;
    for(int i=0;i<this->InventorySize;i++){
        cout<<i<<"\t"<<this->Inventory[i]->getName()<<"\t"<<this->Inventory[i]->getValue()<<endl;        
    }

}

//Displays all Shopping options.
void Shop::ShopDialogue(Player *player){

    string playerChoice="";
    cout<<"welcome to the store"<<endl;
    while (playerChoice!="exit"){
        cout<<"Store Inventory:"<<endl;
        cout<<"Gold: "<<this->getMoney();
        this->DisplayInventory();
        cout<<"what would you like to do? [Exit|Buy|Sell|View|I(view Inventory)|E(view Equiped)]"<<endl;
        cin>>playerChoice;
        playerChoice=toLower(playerChoice);
        
        if (playerChoice=="exit"){
            cout<<"Exiting Store"<<endl;
        }else if (playerChoice=="buy"){
            this->SellItem(player);
        }else if(playerChoice=="sell"){
            this->PurchaseItem(player);
        }else if(playerChoice=="view"){
            this->ViewItem();
        }else if(playerChoice=="i"){
            player->InventoryDialogue();
        }else if(playerChoice=="e"){
            player->EquipedDialogue();
        }else{
            cout<<"Not Valid choice"<<endl;
        }
       
    }
}

//the shop purchases item from the player
bool Shop::PurchaseItem(Player *player){
    //the players input
    int playerChoice=-2;
    //the item the player is selling
    Item* toBeSold;
    //the amount the merchant cuts off the value
    double merchantMultiplier=.8;
    // the price the item is sold for
    int itemPrice=0;


    while(1){
        cout<<"What item would you like to sell(-1 to cancel):"<<endl;
        player->DisplayInventory();
        cin>>playerChoice;
        //if player wants to exit
        if(playerChoice==-1){
            cout<<"exiting transaction"<<endl;
            return true; //successful transaction
        }
        //if player chooses valid inventory slot
        if(player->getInventorySize()>playerChoice&&playerChoice>=0){

            //retrieves the item to be sold from player inventory
            toBeSold=player->RemoveItemFromInventory(playerChoice);
            //calculates price of the item
            itemPrice=toBeSold->getValue()*merchantMultiplier;

            //while valid choice is not chosen
            while(1){
                cout<<"you are selling "<<toBeSold->getName()<<"for "<<itemPrice<<"gold do you approve of this transaction? (yes:1,No:0)"<<endl;
                cin>>playerChoice;

                if(playerChoice==1){  //if player chooses yes
                    
                    if(this->GiveMoney(itemPrice) !=0 || itemPrice==0){ //if store can afford

                        //adds item to store inventory
                        this->AddItemToInventory(toBeSold);
                        //gives player the money
                        player->RecieveMoney(itemPrice);
                        cout<<player->getName()<<" recieved "<<itemPrice<<" gold"<<endl;
                        return true;//successfull transaction
                    } 
                    else{ //if store cant afford
                    cout<<"Store cannot afford Item Transaction Canceled"<<endl;
                    //add item back to players inventory
                    player->addToInventory(toBeSold);
                    return false;//unsuccesful transaction
                    }              
                    
                }else if(playerChoice==0){ //if player chooses No
                    cout<<"Transaction Canceled"<<endl;
                    //item added back to players inventory
                    player->addToInventory(toBeSold);
                    return false;//unsucsesful transactuon
                }
                else{ //non valid choice
                    cout<<"invalid choice"<<endl;
                }              
            }
        
        }else{//if not valid choice
            cout<<"not valid choice"<<endl;
        }  
    }
    return false; //to make syntax happy

}

//sells item to the player
bool Shop::SellItem(Player *player){

  
    //the players input
    int playerChoice=-2;
    //the item the player is selling
    Item* toBeSold;
    //the amount the merchant adds to the value
    double merchantMultiplier=1.2;
    // the price the item is sold for
    int itemPrice;

    while(1){
            this->DisplayInventory();
            cout<<"What item would you like to buy(-1 to cancel):"<<endl;
           
            cin>>playerChoice;
            //if player wants to exit
            if(playerChoice==-1){
                cout<<"exiting transaction"<<endl;
                return true; //successful transaction
            }
            if(playerChoice>=0&&playerChoice<this->InventorySize){
                toBeSold=this->RemoveItemFromInventory(playerChoice);
                itemPrice=toBeSold->getValue()*merchantMultiplier;
                while(1){
                    cout<<"would you like to buy "<<toBeSold->getName()<<" for "<<itemPrice<<" gold?(yes:1, No:0)"<<endl;
                    cin>>playerChoice;
                    if(playerChoice==1){
                        if(player->GiveMoney(itemPrice)!=0){
                            //puts item in players inventory
                            player->addToInventory(toBeSold);
                            //gives store the money
                            this->RecieveMoney(itemPrice);
                            cout<<"transaction succesfull "<<player->getName()<<" has reciece "<<toBeSold->getName();
                            return true;//successful transaction
                        }
                        else{// if player could not afford item
                            cout<<player->getName()<<" does not have enough gold. Transaction Canceled"<<endl;
                            //add item back to store inventory;
                            this->AddItemToInventory(toBeSold);
                            return false;//unsucsesful transaction
                        }
                    }else if(playerChoice ==0){ //if player chose no
                        cout<< "Transaction Canceled"<<endl;
                        return false;// unsuccsesful Transaction
                    }
                    else{//if not a valid choice
                        cout<<"Not a valid choice"<<endl;
                    }
                }   
            }

        
    }
    return false;//make syntax happy


}

//gets the specific item from the inventory;
Item* Shop::getItem(int position){
    if (position>=0 &&position<=20){
        return this->Inventory[position];
    }
    return NULL;
}

//getter for Level
int Shop::getLevel(){
    return this->Level;
}
//setter for Level and generates new inventory that matches the level
void Shop::setLevel(int level){
    if (level<1){
        level=1;
    }
    this->Level=level;
    this->GenerateNewInventory();
}

//will generate 10 items at "random"
void Shop::GenerateNewInventory(){
    int i=0;
    int randValue=0;
    int classVal=0;
    //sets all inventory to NULL
    for( i=0;i<20;i++){
        this->Inventory[i]=new Item();
    }

    for (i=0; i<10; i++){
        
        randValue=rand()%100;
        
        //20% chance of armour
        if (randValue<20){
            classVal=rand()%3 +1;
            randValue=rand()%5;
            //20% chance of each armour type
            if(randValue==0){
                this->Inventory[i]=this->spawner.CreateHelmet(this->getLevel(),(ArmorClass_enum)classVal);
            } else if(randValue==1){
                this->Inventory[i]=this->spawner.CreateChest(this->getLevel(),(ArmorClass_enum)classVal);
            } else if(randValue==2){
                this->Inventory[i]=this->spawner.CreateGloves(this->getLevel(),(ArmorClass_enum)classVal);
            }else if(randValue==3){
                this->Inventory[i]=this->spawner.CreatePants(this->getLevel(),(ArmorClass_enum)classVal);
            }else if(randValue==4){
                this->Inventory[i]=this->spawner.CreateBoots(this->getLevel(),(ArmorClass_enum)classVal);
            }
        }
        //30 % chance of Weapon
        else if(randValue>=20 &&randValue<50){
            //25 % chance for each weapon except claws they have 0%S
            randValue=rand()%4;
            if (randValue==0){
                this->Inventory[i]=this->spawner.CreateAxe(this->getLevel());
            } else if(randValue ==1){
                this->Inventory[i]=this->spawner.CreateDagger(this->getLevel());
            } else if(randValue ==2){
                this->Inventory[i]=this->spawner.CreateSword(this->getLevel());
            }else if(randValue ==3){
                this->Inventory[i]=this->spawner.CreateShield(this->getLevel());
            }
        }
        //50% chance of potion
        else {
            this->Inventory[i]=spawner.CreateRandomPotion_MoreHealth();
        }

    }


}

void Shop::ViewItem(){
    int playerChoice=-2;
    Item* viewable;

    while(playerChoice!=-1){
        this->DisplayInventory();
        cout<<"which item would you like to see?(-1 to exit)"<<endl;
        cin>>playerChoice;
        if(playerChoice>0 &&playerChoice<=this->InventorySize){
            viewable=this->getItem(playerChoice);

            if(viewable->getName()=="Empty"){
                cout<<"this is an empty slot"<<endl;
            }
            else if (typeid(*viewable) == typeid(Weapon)) {

                Weapon* w = dynamic_cast<Weapon*>(viewable);
                w->DisplayDetails();
		    }
		    else if ((typeid(*viewable) == typeid(Armor))) {
                Armor* a = dynamic_cast<Armor*>(viewable);
                a->DisplayDetails();
		    }
		    else if ((typeid(*viewable) == typeid(Potion))) {
                Potion* a = dynamic_cast<Potion*>(viewable);
                a->DisplayDetails();
		    }

        }else{
            cout<<"not a valid choice"<<endl;
        }
        getchar();
		getchar();

    }
}

//get the shops position
array<int,2> Shop::getPosition(){
    return this->Position;
}

//sets the shops position if out of bounds it will set shop to 5,5
void Shop::setPosition(array<int,2>pos){
    if (pos[0]>8 ||pos[0]<1){
        pos[0]=5;
    }
    if (pos[1]>8 ||pos[1]<1){
        pos[1]=5;
    }
    this->Position=pos;

}
