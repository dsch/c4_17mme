#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED
#include"UserInterface.h"
#include"Console.h"
class Logic
{
public:
    Logic();
    ~Logic();

    bool WinCheck(UserInterface::GridType board);

};

#endif // LOGIC_H_INCLUDED
