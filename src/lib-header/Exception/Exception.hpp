#include <exception>
#include <string>
#include <iostream>
using namespace std;

class NamaPanjangException : public exception {
  private:
    int length;
  public:
    NamaPanjangException(int _length);
    ~NamaPanjangException();
    const char* what() const throw();
};

class NamaDuplikatException : public exception {
    private: 
        string nama; 
    public:
        NamaDuplikatException(string str);
        ~NamaDuplikatException();
        const char* what() const throw();
};

class IndexOutOfBoundsException : public exception {
    private:
        int index;
        int batas;
    public:
        IndexOutOfBoundsException(int _index, int _batas);
        ~IndexOutOfBoundsException();
        const char* what() const throw();
};

class IndexNotValidException : public exception {
    private:
        int index;
    public:
        IndexNotValidException(int _index);
        ~IndexNotValidException();
        const char* what() const throw();
};


template <class T>
class InvalidInputException : public exception {
    private:
        T input;
    public:
        InvalidInputException(T _input);
        ~InvalidInputException();
        const char* what() const throw();
};

class SameIndexException : public exception {
    private:
        int index;
    public:
        SameIndexException(int _index);
        ~SameIndexException();
        const char* what() const throw();
};