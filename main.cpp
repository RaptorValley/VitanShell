#include <iostream>
#include <ctime>
#include <conio.h>

inline void sleep(int time) {
    clock_t head = clock();
    while (clock() - head <= time) {}
}

inline void clear() {
    std::cout << "\x1B[2J\x1B[H";
}

void init() {
    std::cout << "===========================================================================================" << std::endl;
    std::cout << "| __      __  _   _                      _____   _              _   _                     |" << std::endl;
    std::cout << "| \\ \\    / / (_) | |                    / ____| | |            | | | |                    |" << std::endl;
    std::cout << "|  \\ \\  / /   _  | |_    __ _   _ __   | (___   | |__     ___  | | | |                    |" << std::endl;
    std::cout << "|   \\ \\/ /   | | | __|  / _` | | '_ \\   \\___ \\  | '_ \\   / _ \\ | | | |                    |" << std::endl;
    std::cout << "|    \\  /    | | | |_  | (_| | | | | |  ____) | | | | | |  __/ | | | |                    |" << std::endl;
    std::cout << "|     \\/     |_|  \\__|  \\__,_| |_| |_| |_____/  |_| |_|  \\___| |_| |_| by Robert Hange    |" << std::endl;
    std::cout << "|                                                                                         |" << std::endl;
    std::cout << "===========================================================================================" << std::endl;
    sleep(1000);
    std::cout << "Press any key to continue..." << std::endl;
    getch();
    clear();
}

int main() {
    init();

    std::string command;
    while (true) {
        std::cout << "VitanShell>> ";
        std::cin >> command;
        if (command == "exit")
            return 0;
    }
}