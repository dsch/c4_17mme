//
// Created by david on 27.12.17.
//

#ifndef C4_WINDOWS_H
#define C4_WINDOWS_H

typedef long HANDLE;
#define STD_OUTPUT_HANDLE 0

inline HANDLE GetStdHandle(int i) {
    return 0;
}

inline void SetConsoleTextAttribute(HANDLE handle, int color)
{

}

#endif //C4_WINDOWS_H
