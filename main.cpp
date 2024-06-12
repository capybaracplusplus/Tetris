#include <iostream>
#include <stdint.h> // для int32_t
#include <conio.h> // для считывания нажатий
#include <map>
#include <thread>
#include <windows.h>
#include <vector>


void gotoxy(int xpos, int ypos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
};
enum class rotation {
    up,
    down,
    right,
    left,
};
enum class figures {
    emptiness,      // пустое поле
    falling_shape, //  падающая фигура
    static_shape  //   статическая фигура
};
std::map<figures, std::string> map_figures = {
        {figures::emptiness, "::"},
        {figures::falling_shape, "░░"},
        {figures::static_shape, "██"},
};


struct Position {
    int x;
    int y;
};
struct figur : Position {
    int turning_option;  // положение всей фигуры
    int version;        // вид самой фигуры
};


int main () {

    char replay_play;
    while(true) {
        std::cout << "you want to start the game (y/n) ";
        std::cin >> replay_play;
        std::cin.ignore(32767,'\n');
        std::cout << std::endl;
        if(replay_play == 'n' || replay_play == 'y')
            break;
    }
    if (replay_play == 'n') {
        std::cout << "bye";
        std::exit(0);
    }

    std::vector<std::vector<figures>> render(20, std::vector<figures> (10));

    std::thread th1([] () {
        while(true) {
            break;
        }
    });
    th1.join();
}
