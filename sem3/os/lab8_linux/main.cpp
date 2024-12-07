#include <unistd.h>
#include <sys/wait.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include <sys/stat.h>
#include <fcntl.h>

int file;

void tabulate(double a, double b, int n, int maxProcesses) {
    if (a > b) {
        std::cerr << "Invalid input" << std::endl;
        return;
    }

    std::string output = "";
    std::string commandPath = "/home/artem/OS/Labs/lab8/process_tab_part.exe";
    std::vector<double> timeResults;
    std::vector<double> speedups;

    for (int currentProcessesCount = 1; currentProcessesCount <= maxProcesses; currentProcessesCount++) {
        std::cout << "------------------------------\n" << currentProcessesCount << " processes:\n";
        output += "------------------------------\n" + std::to_string(currentProcessesCount) + " processes:\n";
        
        std::vector<double> start(currentProcessesCount);
        start[0] = a;

        double division = (b - a) / currentProcessesCount;
        int nDivided = n / currentProcessesCount;
        int remainder = n % currentProcessesCount;

        std::vector<double> end(currentProcessesCount);
        for (int i = 0; i < currentProcessesCount; i++) {
            start[i] = a + i * division;
            end[i] = start[i] + division;
        }
        end[currentProcessesCount - 1] += division / nDivided;

        std::vector<pid_t> pids(currentProcessesCount);
        auto startTime = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < currentProcessesCount; i++) {
            int currentDivisions = nDivided + (i == currentProcessesCount - 1 ? remainder : 0);
            pids[i] = fork();

            if (pids[i] < 0) {
                std::cerr << "Fork failed for process " << i << std::endl;
                return;
            }
            if (pids[i] == 0) {
                // Child process: execute the target program with arguments
                std::string startArg = std::to_string(start[i]);
                std::string endArg = std::to_string(end[i]);
                std::string divArg = std::to_string(currentDivisions);

                execl(commandPath.c_str(), "process_tab_part.exe", startArg.c_str(), endArg.c_str(), divArg.c_str(), (char*)NULL);
                perror("execl failed"); // Only called if execl fails
                return;
            }
        }

        for (int i = 0; i < currentProcessesCount; i++) {
            int status;
            waitpid(pids[i], &status, 0);
            if (!WIFEXITED(status)) {
                std::cerr << "Process " << i << " did not terminate normally." << std::endl;
            }
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = endTime - startTime;
        std::cout << "Launched program has finished. Time: " << duration.count() * 1000 << " ms" << std::endl;
        output += "Launched program has finished. Time: " + std::to_string(duration.count() * 1000) + " ms\n";
        
        timeResults.push_back(duration.count() * 1000);
    }

    for (size_t i = 0; i < timeResults.size(); i++) {
        speedups.push_back(timeResults[0] / timeResults[i]);
    }

    auto maxit = std::max_element(speedups.begin(), speedups.end());
    int index = std::distance(speedups.begin(), maxit);

    std::cout << "\nMax speedup: " << *maxit << " is reached using " << index + 1 << " processes\n";
    output += "\nMax speedup: " + std::to_string(*maxit) + " is reached using " + std::to_string(index + 1) + " processes\n";
    
    write(file, output.c_str(), output.length());
}

int main() {
    char func = 0;
    double a = 0;
    double b = 0;
    int n = 0;
    int maxProcesses = 0;

    while (func != 'e') {
        std::cout << "Enter the command: ";
        func = getchar();
        
        switch (func) {

        case 'i': {
            std::cout << "t - start tabulation function and write results to file\n"
                << "c - change file access attributes"
                << "e - exit program\n"
                << "i - info/help\n";
        }

        case 'c': {
            int mode;
            std::cout << "Enter the mode in octal int: ";
            
            std::cin >> std::oct >> mode >> std::dec;
                
            if (chmod("results.txt", mode) == -1) {
                std::cerr << "Error setting mode.\n";
            } else {
                std::cout << "Successfully changed file access rights.\n";
            }
            
            break;
        }

        case 't': {
            file = creat("results.txt", S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);

            if (file < 0) {
                std::cerr << "Failed to create or open file.";
                continue;
            }

            std::cout << "\nEnter the limits: ";
            std::cin >> a >> b >> n >> maxProcesses;
            tabulate(a, b, n, maxProcesses);
            std::cout << '\n';

            close(file);
            break;
        }

        case 'e': break;

        default: std::cout << "\nThe command is not recognized (for more info type i). Try again.\n";

        }

        getchar();
    }

    std::cout << "\nEnd of program.\n";
}
