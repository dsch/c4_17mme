#include <gtest/gtest.h>
#include <stdlib.h>
#include "MockUserInterface.h"

using Color=UserInterface::Color;
using ::testing::Return;
using ::testing::Throw;
using ::testing::InSequence;
using ::testing::_;
using ::testing::AtLeast;

void print(const UserInterface::GridType &grid) {
    for (size_t row = 0; row < 6; row++) {
        for (size_t col = 0; col < 7; col++) {
            const UserInterface::Field &field = grid[row][col];
            char c = field.isEmpty() ? '_' : field.getColor() == Color::RED ? 'R' : 'Y';
            std::cout << c;
        }
        std::cout << std::endl;
    }
}

Color &operator++(Color &color) {
    if (color == Color::RED) {
        color = Color::YELLOW;
    } else {
        color = Color::RED;
    }
    return color;
}


bool operator==(const UserInterface::Field &a, const UserInterface::Field &b) {
    if (a.isEmpty() == b.isEmpty()) {
        if (a.isEmpty()) {
            return true; // both empty
        } else { // both set
            return a.getColor() == b.getColor();
        }
    } else {
        return false;
    }
}

class MoveSequencer {
public:
    MoveSequencer(Color beginner, const unsigned char (&data)[6][7])
            : in_sequence(), player(1), first_color(beginner), second_color(++beginner), data(data) {
    }

    Color color() const {
        return player == 1 ? first_color : second_color;
    }

    void nextPlayer() {
        player = (player == 1) ? 2 : 1;
    }

    void operator()(MockUserInterface &ui) {
        UserInterface::GridType grid;
        std::size_t i1 = 42;
        std::size_t i2 = 42;
        Color winner_color;
        while ((i1 > 0) || (i2 > 0)) {
            //print(grid);
            EXPECT_CALL(ui, updateBoard(grid));
            UserInterface::ColumnType col;
            if (updateGrid(grid, (player == 1) ? i1 : i2, col)) {
                EXPECT_CALL(ui, askPlayer(color())).WillOnce(Return(col));
                nextPlayer();
            } else {
                winner_color = color();
                ++winner_color;
                break;
            }
            //print(grid);
        }
        if ((i1 == 0) && (i2 == 0)) {
            EXPECT_CALL(ui, notifyDraw()).Times(1);
        } else {
            EXPECT_CALL(ui, notifyWinner(winner_color)).Times(1);
        }
    }

    bool updateGrid(UserInterface::GridType &grid, std::size_t &i, UserInterface::ColumnType &col) {
        while (i > 0) {
            i--;
            div_t ret = div(i, 7);
            std::size_t row = ret.quot;
            col = ret.rem;
            if (data[row][col] == player) {
                grid[row][col] = player == 1 ? first_color : second_color;
                return true;
            }
        }
        return false;
    }

private:
    InSequence in_sequence;
    unsigned int player;
    Color first_color;
    Color second_color;
    const unsigned char (&data)[6][7];
};


void play(unsigned char (&data)[6][7]) {
    MockUserInterface ui;
    MoveSequencer sequencer(GameAdapter::first_player, data);
    sequencer(ui);
    GameAdapter::play(ui);
}

TEST(Game, first_vertical) {
    unsigned char data[6][7] = {
            [0] = {0},
            [1] = {0},
            [2] = {0, 1},
            [3] = {0, 1, 2},
            [4] = {0, 1, 2},
            [5] = {0, 1, 2},
    };
    play(data);
}

TEST(Game, second_vertical) {
    unsigned char data[6][7] = {
            [0] = {0},
            [1] = {0},
            [2] = {0, 0, 2},
            [3] = {0, 1, 2},
            [4] = {0, 1, 2},
            [5] = {0, 1, 2, 1},
    };
    play(data);
}

TEST(Game, first_horizontal) {
    unsigned char data[6][7] = {
            [0] = {0},
            [1] = {0},
            [2] = {0},
            [3] = {0},
            [4] = {0, 0, 2, 2, 2},
            [5] = {0, 1, 1, 1, 1},
    };
    play(data);
}

TEST(Game, second_horizontal) {
    unsigned char data[6][7] = {
            [0] = {0},
            [1] = {0},
            [2] = {0},
            [3] = {0},
            [4] = {0, 0, 1, 2, 2, 2, 2},
            [5] = {0, 0, 1, 2, 1, 1, 1},
    };
    play(data);
}

TEST(Game, first_diag_up) {
    unsigned char data[6][7] = {
            [0] = {0},
            [1] = {0},
            [2] = {0, 0, 0, 0, 1},
            [3] = {0, 0, 0, 1, 2},
            [4] = {0, 0, 1, 1, 2},
            [5] = {2, 1, 2, 2, 1},
    };
    play(data);
}

TEST(Game, second_diag_up) {
    unsigned char data[6][7] = {
            [0] = {0},
            [1] = {0},
            [2] = {0, 0, 0, 1, 2},
            [3] = {0, 0, 0, 2, 2},
            [4] = {0, 0, 2, 1, 1},
            [5] = {1, 2, 1, 2, 1},
    };
    play(data);
}

TEST(Game, first_diag_down) {
    unsigned char data[6][7] = {
            [0] = {0},
            [1] = {0},
            [2] = {0, 1, 0},
            [3] = {0, 2, 1},
            [4] = {0, 2, 1, 1},
            [5] = {1, 2, 2, 2, 1},
    };
    play(data);
}

TEST(Game, second_diag_down) {
    unsigned char data[6][7] = {
            [0] = {0},
            [1] = {0},
            [2] = {0, 2, 1},
            [3] = {0, 2, 2, 1},
            [4] = {0, 2, 1, 2},
            [5] = {0, 1, 1, 1, 2},
    };
    play(data);
}

TEST(Game, draw) {
    unsigned char data[6][7] = {
            [0] = {2, 1, 1, 1, 2, 2, 2},
            [1] = {1, 2, 2, 2, 1, 1, 1},
            [2] = {2, 1, 1, 1, 2, 2, 2},
            [3] = {1, 2, 2, 2, 1, 1, 1},
            [4] = {2, 1, 1, 1, 2, 2, 2},
            [5] = {1, 2, 2, 2, 1, 1, 1},
    };
    play(data);
}

TEST(Game, first_full_column) {
    InSequence in_sequence;
    MockUserInterface ui;
    Color player = GameAdapter::first_player;
    UserInterface::GridType grid;
    for (std::size_t i = 0; i < 6; i++) {
        EXPECT_CALL(ui, updateBoard(grid));
        EXPECT_CALL(ui, askPlayer(player)).WillOnce(Return(0));
        grid[5 - i][0] = player;
        ++player;
    }
    EXPECT_CALL(ui, updateBoard(grid));
    EXPECT_CALL(ui, askPlayer(player)).WillOnce(Return(0));
    EXPECT_CALL(ui, updateBoard(grid)).Times(AtLeast(0));
    EXPECT_CALL(ui, askPlayer(player)).WillOnce(Return(0));
    EXPECT_CALL(ui, updateBoard(grid)).Times(AtLeast(0));
    EXPECT_CALL(ui, askPlayer(player)).WillOnce(Return(1));
    grid[5][1] = player;
    ++player;
    EXPECT_CALL(ui, updateBoard(grid));

    EXPECT_CALL(ui, askPlayer(player)).WillOnce(Throw(UserInterface::Abort()));
    try {
        GameAdapter::play(ui);
    } catch (const UserInterface::Abort &abort) {
    }
}

TEST(Game, second_full_column) {
    InSequence in_sequence;
    MockUserInterface ui;
    Color player = GameAdapter::first_player;
    UserInterface::GridType grid;

    EXPECT_CALL(ui, updateBoard(grid));
    EXPECT_CALL(ui, askPlayer(player)).WillOnce(Return(2));
    grid[5][2] = player;
    ++player;
    //print(grid);

    for (std::size_t i = 0; i < 6; i++) {
        EXPECT_CALL(ui, updateBoard(grid));
        EXPECT_CALL(ui, askPlayer(player)).WillOnce(Return(0));
        grid[5 - i][0] = player;
        ++player;
        //print(grid);
    }
    EXPECT_CALL(ui, updateBoard(grid));
    EXPECT_CALL(ui, askPlayer(player)).WillOnce(Return(0));
    EXPECT_CALL(ui, updateBoard(grid)).Times(AtLeast(0));
    EXPECT_CALL(ui, askPlayer(player)).WillOnce(Return(0));
    EXPECT_CALL(ui, updateBoard(grid)).Times(AtLeast(0));
    EXPECT_CALL(ui, askPlayer(player)).WillOnce(Return(1));
    grid[5][1] = player;
    ++player;
    EXPECT_CALL(ui, updateBoard(grid));

    EXPECT_CALL(ui, askPlayer(player)).WillOnce(Throw(UserInterface::Abort()));
    try {
        GameAdapter::play(ui);
    } catch (const UserInterface::Abort &abort) {
    }
}

TEST(Game, abort) {
    InSequence in_sequence;
    MockUserInterface ui;
    Color player = GameAdapter::first_player;
    UserInterface::GridType grid;
    EXPECT_CALL(ui, updateBoard(grid));
    if (GameAdapter::abort_with_exception) {
        EXPECT_CALL(ui, askPlayer(player)).WillOnce(Throw(UserInterface::Abort()));
    } else {
        EXPECT_CALL(ui, askPlayer(player)).WillOnce(Return(GameAdapter::abort_column));
    }
    GameAdapter::play(ui);
}
