#include <iostream>
#include <conio.h> // для считывания нажатий
#include <map>
#include <thread>
#include <windows.h>
#include <vector>
#include <random>

void gotoxy(int xpos, int ypos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
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
        {figures::emptiness,     "::"},
        {figures::falling_shape, "░░"},
        {figures::static_shape,  "██"},
};

struct Position {
    int x;
    int y;
};
struct figur : Position {
    int turning_option;  // положение всей фигуры
    int shape;          // вид самой фигуры
    std::vector<std::vector<figures>> v;
};
struct player {
    std::string name{"player_1"};
    bool life{true};
    int lvl{0};
    int points{0};
    int time_hour{0};
    int time_minutes{0};
    int time_seconds{0};
    bool dynamic;        // падает ли фигура да или нет
};

// генерю рандомное число
// генерю фигурку по числу
// вызываю функцию которая создает вектор v с этой фигуркой
// вывожу если могу, если нет, то проиграл
// заставляю её падать

int random(void) {
    std::random_device rd;
    std::mt19937 random_int(rd());
    return random_int() % 28; // 7*4
}

std::vector<std::vector<figures>> figure_0() {
    // yellow cube 2x2
    std::vector<std::vector<figures>> array(2, std::vector<figures>(2, figures::falling_shape));
    return array;
}

std::vector<std::vector<figures>> figure_1() {
    // orange figure
    std::vector<std::vector<figures>> array(3, std::vector<figures>(3, figures::emptiness));
    array[0][0] = figures::falling_shape;
    array[1][0] = figures::falling_shape;
    array[2][0] = figures::falling_shape;
    array[2][1] = figures::falling_shape;
    return array;
}

std::vector<std::vector<figures>>  figure_2() {
    // dark blue figure
    std::vector<std::vector<figures>> array(3, std::vector<figures>(3, figures::emptiness));
    array[0][2] = figures::falling_shape;
    array[1][2] = figures::falling_shape;
    array[2][2] = figures::falling_shape;
    array[2][1] = figures::falling_shape;
    return array;
}

std::vector<std::vector<figures>>  figure_3() {
    // light blue figure
    std::vector<std::vector<figures>> array(4, std::vector<figures>(4, figures::emptiness));
    array[0][0] = figures::falling_shape;
    array[1][0] = figures::falling_shape;
    array[2][0] = figures::falling_shape;
    array[3][0] = figures::falling_shape;
    return array;
}

std::vector<std::vector<figures>>  figure_4() {
    // green figure
    std::vector<std::vector<figures>> array(3, std::vector<figures>(3, figures::emptiness));
    array[1][2] = figures::falling_shape;
    array[1][1] = figures::falling_shape;
    array[2][1] = figures::falling_shape;
    array[2][0] = figures::falling_shape;
    return array;
}

std::vector<std::vector<figures>>  figure_5(){
    // red figure
    std::vector<std::vector<figures>> array(3, std::vector<figures>(3, figures::emptiness));
    array[1][0] = figures::falling_shape;
    array[1][1] = figures::falling_shape;
    array[2][1] = figures::falling_shape;
    array[2][2] = figures::falling_shape;
    return array;
}

std::vector<std::vector<figures>>  figure_6(){
    // pink figure
    std::vector<std::vector<figures>> array(3, std::vector<figures>(3, figures::emptiness));
    array[0][0] = figures::falling_shape;
    array[0][1] = figures::falling_shape;
    array[0][2] = figures::falling_shape;
    array[1][1] = figures::falling_shape;
    return array;
}

using figure_array = std::vector<std::vector<figures>>  (*)();

figure_array transform_figure(int random_number) {
    // create pattern figure by random number
    switch (random_number % 7) {
        case 0:
            return figure_0;
            /*
        case 1:
            return figure_1;
        case 2:
            return figure_2;
        case 3:
            return figure_3;
        case 4:
            return figure_4;
        case 5:
            return figure_5;
        case 6:
            return figure_6;
            */
    }
}

auto figure_generation(void) {
    return transform_figure(random());
}


int main() {

    char replay_play;
    while (true) {
        std::cout << "you want to start the game (y/n) ";
        std::cin >> replay_play;
        std::cin.ignore(32767, '\n');
        std::cout << std::endl;
        if (replay_play == 'n' || replay_play == 'y')
            break;
    }
    if (replay_play == 'n') {
        std::cout << "bye";
        std::exit(0);
    }

    std::vector<std::vector<figures>> render(20, std::vector<figures>(10, figures::emptiness));

    while (true) {
        for (int i{0}; i < 20; i++) {
            for (int j{0}; j < 10; j++) {
                std::cout << map_figures[render[i][j]];
            }
            std::cout << std::endl;
        }


        break;
    }





    std::thread th1([]() {
        while (true) {
            // собирать нажатия клавиш
            break;
        }
    });
    th1.join();
}
