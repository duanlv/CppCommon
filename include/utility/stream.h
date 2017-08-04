/*!
    \file stream.h
    \brief Stream helpers definition
    \author Ivan Shynkarenka
    \date 04.08.2017
    \copyright MIT License
*/

#ifndef CPPCOMMON_UTILITY_STREAM_H
#define CPPCOMMON_UTILITY_STREAM_H

#include <iostream>

namespace CppCommon {

//! Write character stream manipulator
class WriteChar
{
public:
    explicit WriteChar(char ch) : _ch(ch) {}

    friend std::ostream& operator<<(std::ostream& stream, const WriteChar& writer)
    {
        return stream << '\'' << writer._ch << '\'';
    }

private:
    char _ch;
};

//! Write string stream manipulator
class WriteString
{
public:
    template <size_t N>
    explicit WriteString(const char (&str)[N]) : _str(str), _size(N) {}

    friend std::ostream& operator<<(std::ostream& stream, const WriteString& writer)
    {
        stream << '"';
        stream.write(writer._str, writer._size);
        stream << '"';
        return stream;
    }

private:
    const char* _str;
    size_t _size;
};

} // namespace CppCommon

#endif // CPPCOMMON_UTILITY_STREAM_H
