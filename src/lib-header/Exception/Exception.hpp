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
    }