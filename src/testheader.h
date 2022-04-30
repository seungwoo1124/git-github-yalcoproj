#include <iostream>
#include "ncurses.h"
#include <unistd.h>

using namespace std;

int func1()
{
    initscr();
    mvprintw(1, 1, "Hello World");
    refresh();
    sleep(2);
    endwin();
    return 0;
}

void test()
{
    cout << "this is test header" << endl;
}