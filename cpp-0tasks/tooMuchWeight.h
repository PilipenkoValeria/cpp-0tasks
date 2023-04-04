#pragma once

class tooMuchWeight :public std::exception {
    const char* message;
public:
    tooMuchWeight(const char* cmessage) : message(cmessage) { }
    const char* what() const noexcept { return message; }
};