GAME(main.cpp Console_UI.cpp Game.cpp)
TEST(test.cpp Game.cpp Console_UI.cpp)
CONFIGURE_FILE(teststate.txt teststate.txt COPYONLY)
UI_TEST(Console_UI Console_UI.cpp Console_UI.h)
GAME_TEST(Game.cpp)
set_tests_properties(CeribasTestGame_draw PROPERTIES WILL_FAIL on)
set_tests_properties(CeribasTestGame_first_full_column PROPERTIES WILL_FAIL on)
set_tests_properties(CeribasTestGame_second_full_column PROPERTIES WILL_FAIL on)

