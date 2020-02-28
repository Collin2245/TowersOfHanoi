#include "Disk.hpp"
#include <string>

class Tower
{
    private:
        Disk* top;
        int count;
        int towerNumber;

    public:
        Tower(int towerNumber);
        int getCount();
        void push(Disk* d);
        Disk* pop();
        Disk* peek();
        void display();
        Tower * getTower(int i);
        void popThenPushLogic(int removeListNum, int addListNum, Tower* t1, Tower * t2, Tower * t3);
        Tower * pickFrom3Towers(int i, Tower* t1, Tower * t2, Tower * t3);
        void displayAllTowers(Tower* t1, Tower * t2, Tower * t3);
        void createGame(int numOfdisks);
        char const* getCurLine(int i);
};


//    ||    //    
//    ||    //
//    ||    //
//    ||    //
//__________//
//          //
//    ||    //
//    ||    //
//    ##    //
//   ####   //
//__________//
//          //