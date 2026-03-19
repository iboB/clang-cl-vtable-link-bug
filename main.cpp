#include "mylib.hpp"
#include <iostream>

int main() {
    SimpleWriter writer(std::cout);
    writer.writeInt(42);
    writer.writeString("Hello, World!");
    return 0;
}
