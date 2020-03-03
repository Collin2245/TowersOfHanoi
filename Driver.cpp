#include "Tower.hpp"
#include <iostream>

int main()
{
    // Tower* t1 = new Tower(1);
    //ll
    Tower* t1 = new Tower(1);
    Tower* t2 = new Tower(2);
    Tower* t3 = new Tower(3);
    

    std::cout << "Please enter how many disks you would like play with (less than 8): " << "\n";
    int ringAmount;
    std::cin >> ringAmount;

    while(ringAmount>7 && ringAmount <= 0)
    {
        std::cout << "Please enter how many disks you would like play with (less than 8): " << "\n";
        std::cin >> ringAmount;
    }
   
    
    t1->createGame(ringAmount);
    
    // t1->push(new Disk(3))
    // t1->push(new Disk(2));
    // t1->push(new Disk(1));
    
    t1->displayAllTowers(t1,t2,t3);
    int winCondition = t1->getCount()-1;

    while(t3->getCount() <= winCondition)

    {
        std::cout << "Enter the stack that you want to remove the top (1-3): " << "\n";
        int numRemoved;
        std::cin >> numRemoved;
        while(numRemoved>3 || numRemoved<=0)
        {
            std::cout << "Please enter 1-3: (enter letters to kill)" << "\n";
            std::cin >> numRemoved;
        }
        std::cout << "Enter the stack that you want to add the removed top (1-3): " << "\n"<<"\n";
        int numToAdd;
        std::cin >> numToAdd;
        while(numToAdd>3 || numToAdd<=0)
        {
            std::cout << "Please enter 1-3: (enter letters to kill)" << "\n";
            std::cin >> numToAdd;
        }

        t1->popThenPushLogic(numRemoved,numToAdd,t1,t2,t3);
        t1->displayAllTowers(t1,t2,t3);
    }
    std::cout << "YOU WIN!"<< "\n";
    return 0;



}