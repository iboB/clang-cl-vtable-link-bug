#include "mylib.hpp"
#include <iostream>

Writer::~Writer() = default;

StreamOwner::StreamOwner(std::ostream& stream) : stream(stream) {}
StreamOwner::~StreamOwner() = default;

SimpleWriter::~SimpleWriter() = default;

void SimpleWriter::writeInt(int value) {
    getStream() << "Int: " << value << std::endl;
}

void SimpleWriter::writeString(std::string_view value) {
    getStream() << "String: " << value << std::endl;
}
