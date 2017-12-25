#ifndef FUNKTIONS_H
#define FUNKTIONS_H
#include "UserInterface.h"


class Funktions
{
public:
    Funktions();

    ~Funktions();

    bool winCheck(UserInterface::GridType board);

    bool drawCheck(UserInterface::GridType board);

protected:

private:
};

#endif // FUNKTIONS_H
