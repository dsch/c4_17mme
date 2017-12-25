GAME(main.cpp src/Console_UI.cpp src/Funktions.cpp)

include_directories(include)
TEST(TestArea.cpp src/Funktions.cpp)
UI_TEST(Console_UI src/Console_UI.cpp include/Console_UI.h)
GAME_TEST(main.cpp src/Console_UI.cpp src/Funktions.cpp ../_common/tests/GuiMock.cpp)
