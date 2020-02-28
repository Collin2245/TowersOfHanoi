#include "Disk.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>

Disk::Disk(int size)
{
    this->size = size;
    this->nextDisk = 0;
}

int Disk::getSize()
{
    return this->size;
}

Disk* Disk::getNextDisk()
{
    return this->nextDisk;
}
        
void Disk::setNextDisk(Disk* d)
{
    this->nextDisk = d;
}

char const* Disk::display()
{
    if(!this->size)
    {
        return "fdaklsjf;lkjas;dkfj;lsakdjf;kasldfk";
    } 
    char const* size1 = "|      ##      | ";
    char const* size2 = "|     ####     | ";
    char const* size3 = "|    ######    | ";
    char const* size4 = "|   ########   | ";
    char const* size5 = "|  ##########  | ";
    char const* size6 = "| ############ | ";
    char const* size7 = "|##############| ";
    if(this->size == 1)
    {
        return size1;
    }
    if(this->size == 2)
    {
        return size2;
    }
    if(this->size == 3)
    {
        return size3;
    }
    if(this->size == 4)
    {
        return size4;
    }
    if(this->size == 5)
    {
        return size5;
    }
    if(this->size == 6)
    {
        return  size6;
    }
    if(this->size == 7)
    {
        return size7;
    }
    //std::cout<< "\n";


    // for(int i = 0; i < this->size; i++)
    // {
    //     std::cout << "=";
    // }
    // std::cout << "\n";
}

