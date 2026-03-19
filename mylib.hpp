#pragma once
#include <string_view>
#include <iosfwd>

#if defined(_WIN32)
#    define SYMBOL_EXPORT __declspec(dllexport)
#    define SYMBOL_IMPORT __declspec(dllimport)
#else
#    define SYMBOL_EXPORT __attribute__((__visibility__("default")))
#    define SYMBOL_IMPORT __attribute__((__visibility__("default")))
#endif

#if BUILDING_MYLIB
#   define MYLIB_API SYMBOL_EXPORT
#else
#   define MYLIB_API SYMBOL_IMPORT
#endif

class MYLIB_API Writer {
public:
    virtual ~Writer();
    virtual void writeInt(int) = 0;
    virtual void writeString(std::string_view) = 0;
};

class MYLIB_API StreamOwner {
public:
    StreamOwner(std::ostream&);
    StreamOwner(const StreamOwner&) = delete;
    StreamOwner& operator=(const StreamOwner&) = delete;
    ~StreamOwner();

    std::ostream& getStream() const {
        return stream;
    }

private:
    std::ostream& stream;
};

class MYLIB_API SimpleWriter : virtual public Writer, public StreamOwner {
public:
    using StreamOwner::StreamOwner;
    virtual ~SimpleWriter();
    virtual void writeInt(int) override;
    virtual void writeString(std::string_view) override;
};
