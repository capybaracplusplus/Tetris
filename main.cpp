#include <iostream>
#include <stdint.h> // для int32_t
#include <conio.h> // для считывания нажатий
#include <map>
#include <thread>
int32_t main () {
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
        exit;
    }
    enum class rotation {
        up,
        down,
        right,
        left,
    };
    enum class figures {
        emptiness,      // пустое поле         "::"
        falling_shape, //  падающая форма      "░░"
        static_shape  //   статическая фигура  "██"
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
    int r;  // положение всей фигуры
    int v; // вид самой фигуры
    };
    std::thread th1([] () {
        while(true) {
            break;
        }
    });
}
