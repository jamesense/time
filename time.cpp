// 10/01/2026
// Tool to check execution speed of a program

#include <windows.h>
#include <iostream>
#include <string>
#include <chrono>
#include <format>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Insufficient arguments passed. Example: time example.exe\n");
        return 0;
    }
    else if (argc > 2) {
        printf("Too many arguments passed. Example: time example.exe\n");
        return 0;
    }

    std::string sProgram = std::string(argv[1]);

    std::cout << sProgram << std::endl;

    // length of .exe is 4
    // check if .exe is there and append
    if (sProgram.length() >= 4 && sProgram.substr(sProgram.length() - 4) != ".exe") {
        sProgram.append(".exe");
    }
    
    std::chrono::high_resolution_clock::time_point TpBeforeExec = std::chrono::high_resolution_clock::now();

    // execute the program
    // some programs I tested break when using CreateProcessA so system is the bandaid solution
    system(sProgram.c_str());

    std::chrono::high_resolution_clock::time_point TpAfterExec = std::chrono::high_resolution_clock::now();
    std::chrono::seconds sDuration = std::chrono::duration_cast<std::chrono::seconds>(TpAfterExec - TpBeforeExec);
    std::cout << std::format("Duration: {}", sDuration) << std::endl; // appends a s at the end to indicate seconds because chrono likes that ig

    return 0;
}
