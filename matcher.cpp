#include <iostream>
#include <fstream>
#include <vector>

#include "matcher.h"

int matcher(std::string command) {
    /*
        std::ifstream fin("register/PROGRAM");
        // 若打开文件失败，则报错
        if (!fin) {
            std::cerr << "Errors ocurr when trying to open file \"register/PROGRAM\"..." << std::endl;
            // return -1;
        }

        std::vector<std::string> program_list; // 程序列表
        std::string line;                      // 从PROGRAM中读取的每一行

        // 逐行读取PROGRAM
        while (std::getline(fin, line)) {
            if (line.empty()) continue;   // 跳过空行
            program_list.push_back(line); // 将当前行追加到program_list末尾
        }

        // 关闭文件
        fin.close();
    */
    std::cout << std::endl;

    if (command == "help" || command == "?") {
        std::cout << "help       View the function of different commands." << std::endl;
        std::cout << "info       Display the basic information of thos program." << std::endl;
        std::cout << "applist    Print the list of installed applications." << std::endl;
        std::cout << "exit       Exit this program." << std::endl;
        std::cout << "rand       Get a random number." << std::endl;
        std::cout << "clr        Clean the screen." << std::endl;
    } else if (command == "cmd") {
        system("cmd");
    } else if (command == "clr") {
        std::cout << "\033c";
    } else if (command == "info") {
        std::cout << "VitanShell by Robert Hange" << std::endl;
        std::cout << "Insider: Build 1169\nChannel: Beta Edition" << std::endl;
        std::cout << "Current Build Date: 2025-11-08" << std::endl;
    } else if (command == "applist") {
        std::cout << "Name                         Code" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Command Prompt(System)       cmd" << std::endl;
    } else if (command == "rand") {
        std::cout << "VitanShell>>" << rand() << std::endl;
    } else if (command == "restart") {
        std::cout << "\033c";
    } else if (command == "exit") {
        return 1;
    } else {
        std::cout << "\033[31mIllegal command.\033[0m" << std::endl;
    }
    std::cout << std::endl;
}