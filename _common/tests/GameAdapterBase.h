#ifndef C4_GAMEADAPTERBASE_H
#define C4_GAMEADAPTERBASE_H

#include <gmock/gmock.h>

#include "UserInterface.h"

template <UserInterface::Color color = UserInterface::Color::RED>
struct GameAdapterBase {
    static const bool abort_with_exception = true;
    static const UserInterface::ColumnType abort_column = 0;
    static const UserInterface::Color first_player = color;
};


#endif //C4_GAMEADAPTERBASE_H
