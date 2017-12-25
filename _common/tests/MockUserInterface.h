#ifndef C4_MOCKUSERINTERFACE_H
#define C4_MOCKUSERINTERFACE_H

#include "gmock/gmock.h"  // Brings in Google Mock.
#include "UserInterface.h"

class MockUserInterface : public UserInterface {
public:
    MOCK_METHOD1(askPlayer, ColumnType(Color
            color));

    MOCK_METHOD1(updateBoard, void(
            const GridType &grid));

    MOCK_METHOD1(notifyWinner, void(Color
            color));

    MOCK_METHOD0(notifyDraw, void());

private:
};


#endif //C4_MOCKUSERINTERFACE_H
