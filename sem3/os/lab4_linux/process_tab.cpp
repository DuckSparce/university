#include <unistd.h>
#include <sys/wait.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <A> <B> <n> <Max Processes>\n";
        return 1;
    }

    double a = std::stod(argv[1]);
    double b = std::stod(argv[2]);
    int n = std::stoi(argv[3]);
    int maxProcesses = std::stoi(argv[4]);

    if (a > b) {
        std::cerr << "Invalid input" << std::endl;
        return 1;
    }

    std::string commandPath = "/home/artem/OS/Labs/Lab4/process_tab_part.exe";  // Update with the correct path to your executable
    std::vector<double> timeResults;
    std::vector<double> speedups;

    for (int currentProcessesCount = 1; currentProcessesCount <= maxProcesses; currentProcessesCount++) {
        std::cout << "------------------------------\n" << currentProcessesCount << " processes:\n";

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
                return 1;
            }
            if (pids[i] == 0) {
                // Child process: execute the target program with arguments
                std::string startArg = std::to_string(start[i]);
                std::string endArg = std::to_string(end[i]);
                std::string divArg = std::to_string(currentDivisions);

                execl(commandPath.c_str(), "process_tab_part.exe", startArg.c_str(), endArg.c_str(), divArg.c_str(), (char*)NULL);
                perror("execl failed"); // Only called if execl fails
                return 1;
            }
        }

        for (int i = 0; i < currentProcessesCount; i++) {
            int status;
            waitpid(pids[i], &status, 0);
            if (WIFEXITED(status)) {
                std::cout << "Process " << i << " finished with exit code " << WEXITSTATUS(status) << std::endl;
            } else {
                std::cerr << "Process " << i << " did not terminate normally." << std::endl;
            }
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = endTime - startTime;
        std::cout << "Launched program has finished. Time: " << duration.count() * 1000 << " ms" << std::endl;
        timeResults.push_back(duration.count() * 1000);
    }

    for (size_t i = 0; i < timeResults.size(); i++) {
        speedups.push_back(timeResults[0] / timeResults[i]);
    }

    auto maxit = std::max_element(speedups.begin(), speedups.end());
    int index = std::distance(speedups.begin(), maxit);

    std::cout << "\nMax speedup: " << *maxit << " is reached using " << index + 1 << " processes\n";
    return 0;
}
