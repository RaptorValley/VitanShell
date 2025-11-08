#include <iostream>
#include <fstream>
#include <vector>

#include "matcher.h"

int matcher(std::string command) {
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

    if (command == "help") {
        std::cout << "Welcom to VitaOS!" << std::endl;
        std::cout << "Here are some common codes." << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "help       Ask for helps." << std::endl;
        std::cout << "info       Know something about this program." << std::endl;
        std::cout << "applist    Look up available applications." << std::endl;
        std::cout << "exit       Exit this program." << std::endl;
        std::cout << "rand       Get a random number." << std::endl;
        std::cout << "clr        Clean the screen." << std::endl;
    } else if (command == "exit") {
        return 1;
    }
}