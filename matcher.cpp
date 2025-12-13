#include <iostream>
#include <fstream>
#include <vector>

#include "matcher.h"

int matcher(std::string command) {
    std::ifstream fin("PROGRAM");
    // 若打开文件失败，则报错
    if (!fin) {
        std::cerr << "\033[33mErrors ocurr when trying to open file \"PROGRAM\"...\033[0m" << std::endl;
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

    std::cout << std::endl;
    bool is_command_matched = false;

    // 优先读取系统命令
    if (is_command_matched == false) {
        if (command == "help" || command == "?") {
            is_command_matched = true;
            std::cout << "help       View the function of different commands." << std::endl;
            std::cout << "info       Display the basic information of thos program." << std::endl;
            std::cout << "applist    Print the list of installed applications." << std::endl;
            std::cout << "exit       Exit this program." << std::endl;
            std::cout << "rand       Get a random number." << std::endl;
            std::cout << "clr        Clean the screen." << std::endl;
        } else if (command == "cmd") {
            is_command_matched = true;
            system("cmd");
        } else if (command == "clr") {
            is_command_matched = true;
            std::cout << "\033c";
        } else if (command == "info") {
            is_command_matched = true;
            std::cout << "VitanShell by Robert Hange" << std::endl;
            std::cout << "Insider Version: Build " << BUILD_NUMBER << std::endl;
            std::cout << "Channel: Early Development" << std::endl;
            std::cout << "Current Build Date: " << BUILD_DATE << std::endl;
        } else if (command == "applist") {
            is_command_matched = true;
            std::cout << "Name                         Code" << std::endl;
            std::cout << "----------------------------------------" << std::endl;
            std::cout << "Command Prompt(System)       cmd" << std::endl;
        } else if (command == "rand") {
            is_command_matched = true;
            std::cout << "VitanShell>> " << rand() << std::endl;
        } else if (command == "restart") {
            is_command_matched = true;
            std::cout << "\033c";
        } else if (command == "exit") {
            is_command_matched = true;
            return 1;
        }
    }

    // 然后再在program_list中搜寻
    if (is_command_matched == false) {
        for (auto p : program_list) {
            if (command == p) {
                is_command_matched = true;
                std::cout << "Successfully detect program \"" << p << "\"(pre-registered). Trying to load..." << std::endl;
                std::cout << std::endl;
                std::cout << p << ">> ";
            }
        }
    }

    if (is_command_matched == false) { std::cout << "\033[31mIllegal command.\033[0m" << std::endl; }

    std::cout << std::endl;
}