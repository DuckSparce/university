#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <windows.h>
#include <QString>

class Process {
public:
    Process(const std::wstring& path);

    HANDLE handle() const;
    void setHandle(HANDLE newHandle);
    DWORD pid() const;
    void setPid(DWORD newPid);
    QString name() const;
    void setName(const QString &newName);
    QString state() const;
    void setState(const QString &newState);
    QString priority() const;
    void setPriority(const QString newPriority);
    DWORD_PTR affinity() const;
    void setAffinity(DWORD_PTR newAffinity);
    double cputime() const;
    void setCputime(double newCputime);
    size_t workingSet() const;
    void setWorkingSet(size_t newWorkingSet);
    size_t peakWorkingSet() const;
    void setPeakWorkingSet(size_t newPeakWorkingSet);

    bool isSuspended();


private:
    HANDLE handle_;

    DWORD pid_;
    QString name_;
    QString state_;
    QString priority_;
    DWORD_PTR affinity_;
    double cputime_;
    size_t workingSet_;
    size_t peakWorkingSet_;
};

#endif // PROCESS_H
