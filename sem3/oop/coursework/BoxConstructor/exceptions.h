#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <QGridLayout>
#include <QMessageBox>
#include <QSpacerItem>
#include <string>

class NoSelectedException {
public:
    explicit NoSelectedException(const std::string& message)
        : errorMsg(message) {}

    const char* what() const noexcept {
        return errorMsg.c_str();
    }

private:
    std::string errorMsg;
};

class InvalidMaterialException {
public:
    explicit InvalidMaterialException(const std::string& message)
        : errorMsg(message) {}

    const char* what() const noexcept {
        return errorMsg.c_str();
    }

private:
    std::string errorMsg;
};

class WrongFormatException {
public:
    explicit WrongFormatException(const std::string& message)
        : errorMsg(message) {}

    const char* what() const noexcept {
        return errorMsg.c_str();
    }

private:
    std::string errorMsg;
};

#endif // EXCEPTIONS_H
