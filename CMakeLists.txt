cmake_minimum_required(VERSION 3.5)
project(C4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Warray-bounds -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage -lgcov")
#add_definitions(-D_GLIBCXX_DEBUG)

add_custom_target(cppcheck)

set(common_dir ${CMAKE_SOURCE_DIR}/_common)

enable_testing()

add_library(gui
        ${common_dir}/gui/Gui.cpp
        ${common_dir}/gui/GuiSetting.cpp
        ${common_dir}/gui/ImageResource.cpp
        ${common_dir}/gui/ResourceManager.cpp
        )
target_link_libraries(gui SDL2)

macro(GAME)
    include_directories(${common_dir})
    get_filename_component(name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    add_executable(${name}Game ${ARGN})
    target_link_libraries(${name}Game gui)

    add_custom_target(${name}CppCheck
            COMMAND cppcheck --std=c++11
            -I ${common_dir}
            -I /usr/include
            -D __GNUC__
            --enable=warning,performance
            --verbose
            --quiet
            ${ARGN}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            )
    add_dependencies(cppcheck ${name}CppCheck)
endmacro()

macro(TEST)
    get_filename_component(name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    add_executable(${name}Test ${ARGN})
    target_link_libraries(${name}Test gtest gtest_main pthread)
    add_test(NAME ${name}Test COMMAND ${name}Test)
endmacro()

macro(UI_TEST ClassName SrcFile IncFile)
    get_filename_component(name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    include_directories(.)
    add_executable(${name}TestConsoleUi ${common_dir}/tests/TestConsoleUi.cpp ${SrcFile})
    set_target_properties(${name}TestConsoleUi PROPERTIES
            COMPILE_DEFINITIONS UI_CLASS=${ClassName})
    set_target_properties(${name}TestConsoleUi PROPERTIES COMPILE_FLAGS "-include ${IncFile}")
endmacro()

set(game_tests
        first_vertical
        second_vertical
        first_horizontal
        second_horizontal
        first_diag_up
        second_diag_up
        first_diag_down
        second_diag_down
        draw
        first_full_column
        second_full_column
        abort
        )

macro(GAME_TEST)
    get_filename_component(name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    include_directories(.)
    include_directories(${common_dir}/tests)
    add_executable(${name}TestGame ${common_dir}/tests/TestGame.cpp ${ARGN})
    target_link_libraries(${name}TestGame gtest gtest_main gmock pthread)
    set_target_properties(${name}TestGame PROPERTIES COMPILE_FLAGS "-include ${name}GameAdapter.h")
    target_compile_definitions(${name}TestGame PUBLIC -Dmain=main2)
    foreach (test ${game_tests})
        add_test(NAME ${name}TestGame_${test} COMMAND ${name}TestGame --gtest_filter=Game.${test})
        set_tests_properties(${name}TestGame_${test} PROPERTIES TIMEOUT 1)
    endforeach ()
endmacro()

file(COPY _common/images DESTINATION images)

add_subdirectory(Abdellaoui)
add_subdirectory(Barza)
add_subdirectory(Ceribas)
add_subdirectory(Dely)
add_subdirectory(Maurer)
add_subdirectory(Neubauer)
add_subdirectory(Ofenboeck)
add_subdirectory(Putz)
add_subdirectory(Sallachner)
add_subdirectory(Scheiblauer)
add_subdirectory(Stefan)
add_subdirectory(Sulzbacher)
add_subdirectory(Viljoen)
add_subdirectory(Wagner)
add_subdirectory(Weissmann)
add_subdirectory(Wenzl)
add_subdirectory(Wimmer)
