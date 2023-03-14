#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>
#include <iostream>
using namespace std;

class BaseException {
    public : 
        virtual string what() const = 0; 
};

class NamaPanjangException : public BaseException {
    private:
        int length;
    public:
        NamaPanjangException(int _length);
        ~NamaPanjangException();
        string what() const;
};

class NamaDuplikatException : public BaseException {
    private: 
        string nama; 
        char* msgptr;
    public:
        NamaDuplikatException(string str);
        ~NamaDuplikatException();
        string what() const;
};

class IndexOutOfBoundsException : public BaseException {
    private:
        int index;
        int batas;
    public:
        IndexOutOfBoundsException(int _index, int _batas);
        ~IndexOutOfBoundsException();
        string what() const;
};

class IndexNotValidException : public BaseException {
    private:
        int index;
    public:
        IndexNotValidException(int _index);
        ~IndexNotValidException();
        string what() const;
};


class InvalidInputException : public BaseException {
    private:
        string input;
    public:
        InvalidInputException(string _input);
        ~InvalidInputException();
        string what() const;
};

class SameIndexException : public BaseException {
    private:
        int index;
    public:
        SameIndexException(int _index);
        ~SameIndexException();
        string what() const;
};

// input not valid cause user haven't input anything
class EmptyInputException : public BaseException {
    public:
        EmptyInputException();
        ~EmptyInputException();
        string what() const;
};

#endif