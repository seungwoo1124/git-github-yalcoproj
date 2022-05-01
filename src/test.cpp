#include <iostream>
#include <time.h>
#include <unistd.h>
#include "ncurses.h"
using namespace std;

int main()
{
    long prevTick = clock();
    long sumTick = 0;
    long secTick = 0;
    int y = 10; int x = 10;
    int maxheight = 100, maxwidth = 100;
    initscr(); // scr 초기화
    noecho(); // 입력을 보여주지 않음
    curs_set(FALSE); // 커서를 숨김
    int dy[4] = {-1, +1, 0, 0}; // up down left right
    int dx[4] = {0, 0, -1, +1}; // up down left right
    int direction = 3;

    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE); // getch의 대기시간을 0으로 만들어줌
    getmaxyx(stdscr, maxheight, maxwidth); // 윈도우의 크기
    while (sumTick < 10 * CLOCKS_PER_SEC) // 10초
    {
        long currentTick = clock();
        long deltaTick = currentTick - prevTick;
        sumTick += deltaTick;
        secTick += deltaTick;
        prevTick = currentTick;

        int input = getch();

        switch (input)
        {
            case KEY_UP: direction = 0; break;
            case KEY_DOWN: direction = 1; break;
            case KEY_LEFT: direction = 2; break;
            case KEY_RIGHT: direction = 3; break;
        }
        if (secTick >= CLOCKS_PER_SEC / 2)
        {
            y += dy[direction];
            x += dx[direction];
            secTick = 0;
        }
        clear();
        mvprintw(0, 0, "direction : %d", direction);
        mvprintw(1, 0, "x : %d, y : %d", x, y);
        mvprintw(y, x, "A");
        refresh();
    }
}