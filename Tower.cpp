#include "Tower.hpp"
#include <iostream>
#include <stdlib.h>

Tower::Tower(int towerNumber)
{
    this->top;
    this->count;
    this->towerNumber = towerNumber;
}

void Tower::createGame(int numOfDisks)
{
    for(int i = 0; i < numOfDisks; i++ )
    {
        this->push(new Disk(numOfDisks-i));
    }
}
int Tower::getCount()
{
    return this->count;
}
        
void Tower::push(Disk* d)
{
    if(this->top)
    {
        if(d->getSize() > this->top->getSize())
        {
            std::cout << "Error: disk size being placed is too big" << "\n";
        }
        else if(d->getSize() < this->top->getSize())
        {
            d->setNextDisk(this->top);   
            this->top = d;
            this->count++; 
        }
    }
    else
    {
        this->top = d;
        this->count++;
    }
      

}

Disk* Tower::pop()
{
    if(this->top)
    {
        Disk* diskToReturn = this->top;
        this->top = this->top->getNextDisk();
        this->count--;
        diskToReturn->setNextDisk(0);
        return diskToReturn;
    }
    return NULL;
}
        
Disk* Tower::peek()
{
    return this->top;
}

Tower * Tower::getTower(int i)
{
    if (i == this->towerNumber)
    {
        return this;
    }
    return 0;
}

Tower * Tower::pickFrom3Towers(int i, Tower* t1, Tower * t2, Tower * t3) 
{
    if(t1->getTower(i))
    {
        return t1;
    }
    else if(t2->getTower(i))
    {
        return t2;
    }
    else if(t3->getTower(i))
    {
        return t3;
    }
    else
    {
        std::cout << "input error";
        return 0;
    }   
}

void Tower::popThenPushLogic(int removeListNum, int addListNum, Tower* t1, Tower * t2, Tower * t3)
{
    Tower * towerRemove = pickFrom3Towers(removeListNum, t1, t2, t3);
    Tower * towerAdd = pickFrom3Towers(addListNum, t1, t2, t3);
    if(!towerRemove->top)
    {
        std::cout << "nothing to remove"<<"\n";
        return;
    }
    else if(!towerAdd->top)
    {
        towerAdd->push(towerRemove->pop());
        return;
    }
    else if(towerRemove->top->getSize() > towerAdd->top->getSize())
    {
        std::cout << "Can't place bigger rings over smaller" << "\n";
        return;
    }
    else
    towerAdd->push(towerRemove->pop());
}
// |      ||      |
//"|    Tower "1   |

void Tower::display()
{   
    std::cout << "|    Tower " << this->towerNumber << "   | "<<"\n"; 
    std::string size0 = "|      ||      | ";
    if (this->count == 0 )
    {
        for(int i = 0; i < 8; i++)
        {
        std::cout<<size0<<"\n";
        
        }
        std::cout <<"|______________| " << "\n";   
        return;
    }
    
    int temp = this->count;
    Disk* currDisk = this->top;
    for(int i = 0; i < 8-count; i++)
    {
        std::cout<<size0;
        std::cout<<"\n";

        //currDisk = currDisk->getNextDisk();
    }
    for(int i = 0; i < temp; i++)
    {
        currDisk->display();
        currDisk = currDisk->getNextDisk();
 
    }
    std::cout <<"|______________| " << "\n";
    // std::cout << "Tower " << this->towerNumber << "\n";
    // Disk* currDisk = this->top;
    // for(int i = 0; i < this->count; i++)
    // {
    //     currDisk->display();
    //     currDisk = currDisk->getNextDisk();
    // }
    // if (this->count == 0)
    // {
    //     std::cout << "-----------------";
    // }
    // std::cout << "\n";
}

char const* Tower::getCurLine(int end)
{
    //std::cout <<"running";
    int currNum = 0;
    char const* thingToReturn = "|      ||      | ";
    Disk*currPos;
    if(!this->top)
    {
        return thingToReturn;
    }
    int numSpaces = 7-this->count;

    while(currNum<numSpaces) //gets spaces
    {
        thingToReturn = "|      ||      | ";
        currNum ++;
    }
    if(currNum < end)
    {
        currPos = this->top;
    }

    while(currNum<end) // gets sizes
    {
        //std::cout<<"running";
         thingToReturn = currPos->display();
         currPos = currPos->getNextDisk();
         currNum++;
    }
    return thingToReturn;
}




void Tower::displayAllTowers(Tower* t1, Tower * t2, Tower * t3)
{
    std::string size0 = "|      ||      | ";
    std::cout << "|    Tower " << t1->towerNumber << "   | "<<"|    Tower " << t2->towerNumber << "   | "<<"|    Tower " << t3->towerNumber << "   | " <<"\n";
    std::cout << size0 << size0<<size0<<"\n";





    for(int i = 0; i < 8; i ++)
    {
        std::cout << t1->getCurLine(i) << t2->getCurLine(i)<<t3->getCurLine(i)<<"\n";
    }
    std::cout <<"|______________| |______________| |______________| " << "\n"<<"\n";
}