#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <sys/types.h>
#include <QString>
#include <sched.h>

class Process {
public:
    Process(const std::string& path, QString name);
    Process(const std::string& path, QString name, std::string a, std::string b, std::string n, std::string numproc);

    pid_t pid() const;
    void setPid(pid_t newPid);
    QString name() const;
    void setName(const QString &newName);
    QString state() const;
    void setState(const QString &newState);
    int priority() const;
    void setPriority(const int newPriority);
    cpu_set_t affinity() const;
    void setAffinity(cpu_set_t newAffinity);
    double cputime() const;
    void setCputime(double newCputime);

    bool isSuspended() const;

private:
    pid_t pid_;
    QString name_;
    QString state_;
    int priority_;
    cpu_set_t affinity_;
    double cputime_;
};

#endif // PROCESS_H
