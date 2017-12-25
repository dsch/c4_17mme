GAME(main.cpp src/Console_UI.cpp src/Funktions.cpp)

include_directories(include)
TEST(TestArea.cpp src/Funktions.cpp)
UI_TEST(Console_UI src/Console_UI.cpp include/Console_UI.h)
GAME_TEST(main.cpp src/Funktions.cpp src/Console_UI.cpp ../_common/tests/GuiMock.cpp)
set_tests_properties(OfenboeckTestGame_first_full_column PROPERTIES WILL_FAIL on)
set_tests_properties(OfenboeckTestGame_second_full_column PROPERTIES WILL_FAIL on)
