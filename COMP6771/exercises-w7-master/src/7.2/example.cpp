#include <iostream>
#include <cstring>


// No RAII
void greetManually() {
    char* name = new char[4];          // manually allocate memory
    std::strcpy(name, "Vy");           // assign value

    std::cout << "Hello, " << name << "!\n";

    delete[] name;                     // manually free memory
}


// Has RAII
class MyString {
public:
    MyString(const char* src) {
        data = new char[std::strlen(src) + 1];
        std::strcpy(data, src);
    }

    ~MyString() {
        delete[] data;                 // memory is freed automatically
    }

    const char* get() const { return data; }

private:
    char* data;
};

void greetWithRAII() {
    MyString name("Vy");              // memory allocated in constructor
    std::cout << "Hello, " << name.get() << "!\n";
}                                      // memory freed automatically here