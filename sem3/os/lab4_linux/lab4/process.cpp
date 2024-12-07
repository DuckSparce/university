#include "process.h"
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sched.h>
#include <iostream>

Process::Process(const std::string& path, QString name) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execl(path.c_str(), name.toStdString().c_str(), NULL);
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        pid_ = pid;
        name_ = name;
        state_ = QString("Running");

        priority_ = getpriority(PRIO_PROCESS, pid_);

        cpu_set_t mask;
        CPU_ZERO(&mask);
        sched_getaffinity(pid_, sizeof(cpu_set_t), &mask);
        affinity_ = mask;

        // CPU time
        struct timeval tv;
        gettimeofday(&tv, NULL);
        cputime_ = tv.tv_sec + tv.tv_usec / 1000000.0;
    } else {
        std::cerr << "Fork failed\n";
    }
}

Process::Process(const std::string &path, QString name, std::string a, std::string b, std::string n, std::string numproc) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execl(path.c_str(), name.toStdString().c_str(), a.c_str(), b.c_str(), n.c_str(), numproc.c_str(), NULL);
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        pid_ = pid;
        name_ = name;
        state_ = QString("Running");

        priority_ = getpriority(PRIO_PROCESS, pid_);

        cpu_set_t mask;
        CPU_ZERO(&mask);
        sched_getaffinity(pid_, sizeof(cpu_set_t), &mask);
        affinity_ = mask;

        // CPU time
        struct timeval tv;
        gettimeofday(&tv, NULL);
        cputime_ = tv.tv_sec + tv.tv_usec / 1000000.0;
    } else {
        std::cerr << "Fork failed\n";
    }
}

pid_t Process::pid() const {
    return pid_;
}

void Process::setPid(pid_t newPid) {
    pid_ = newPid;
}

QString Process::name() const {
    return name_;
}

void Process::setName(const QString &newName) {
    name_ = newName;
}

QString Process::state() const {
    return state_;
}

void Process::setState(const QString &newState) {
    state_ = newState;
}

int Process::priority() const {
    return priority_;
}

void Process::setPriority(const int newPriority) {
    priority_ = newPriority;
}

cpu_set_t Process::affinity() const {
    return affinity_;
}

void Process::setAffinity(cpu_set_t newAffinity) {
    affinity_ = newAffinity;
}

double Process::cputime() const {
    return cputime_;
}

void Process::setCputime(double newCputime) {
    cputime_ = newCputime;
}

bool Process::isSuspended() const {
    int status;
    waitpid(pid_, &status, WNOHANG); // Non-blocking check

    if (WIFSTOPPED(status)) {
        return true;
    }

    return false;
}
