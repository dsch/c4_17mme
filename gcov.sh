#!/usr/bin/env bash

find -name "*.gcda" -delete
cd cmake-build-debug
ctest -R "Test$"
cd ..

gcov -fmb cmake-build-debug/Abdellaoui/CMakeFiles/AbdellaouiTest.dir/Game.cpp.gcno | grep -A 5 "Game::checkBoard"

gcov -fmb cmake-build-debug/Barza/CMakeFiles/BarzaTest.dir/Game.cpp.gcno | grep -A 5 "Game::checkBoard"

gcov -fmb cmake-build-debug/Ceribas/CMakeFiles/CeribasTest.dir/Game.cpp.gcno | grep -A 5 "Game::checkBoard"

gcov -fmb cmake-build-debug/Dely/CMakeFiles/DelyTest.dir/Spiel.cpp.gcno | grep -A 5 "Spiel::Gewonnen"

gcov -fmb cmake-build-debug/Maurer/CMakeFiles/MaurerTest.dir/Game.cpp.gcno | grep -A 5 "Game::Gewonnen"

gcov -fmb cmake-build-debug/Ofenboeck/CMakeFiles/OfenboeckTest.dir/src/Funktions.cpp.gcno | grep -A 5 "Funktions::winCheck"

gcov -fmb cmake-build-debug/Putz/CMakeFiles/PutzTest.dir/src/main/GameLogic.cpp.gcno | grep -A 5 "GameLogic::CheckForWinner"

gcov -fmb cmake-build-debug/Sallachner/CMakeFiles/SallachnerTest.dir/Logic.cpp.gcno | grep -A 5 "Logic::WinCheck"

gcov -fmb cmake-build-debug/Scheiblauer/CMakeFiles/ScheiblauerTest.dir/src/Funktions.cpp.gcno | grep -A 5 "Funktions::winCheck"

gcov -fmb cmake-build-debug/Stefan/CMakeFiles/StefanTest.dir/Game.cpp.gcno | grep -A 5 "Game::GewinnErmittlung"

gcov -fmb cmake-build-debug/Viljoen/CMakeFiles/ViljoenTest.dir/src/GameLogic.cpp.gcno | grep -A 5 "GameLogic::"

gcov -fmb cmake-build-debug/Wagner/CMakeFiles/WagnerTest.dir/Game.cpp.gcno | grep -A 5 "Game::check"

gcov -fmb cmake-build-debug/Weissmann/CMakeFiles/WeissmannTest.dir/GameLogik.cpp.gcno | grep -A 5 "GameLogik::isWin"

gcov -fmb cmake-build-debug/Wimmer/CMakeFiles/WimmerTest.dir/Game.cpp.gcno | grep -A 5 "Game::Gewonnen"

