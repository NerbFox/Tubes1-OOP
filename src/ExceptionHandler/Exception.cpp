#include "../lib-header/Exception/Exception.hpp"
#include <cstring>

using namespace std;

NamaPanjangException::NamaPanjangException(int _length) : length(_length) {}

NamaPanjangException::~NamaPanjangException(){}

const char* NamaPanjangException::what() const throw() {
  string msg = "NamaPanjangException : Karakter berjumlah : " + to_string(length) + ", kurangi karakter supaya berjumlah kurang dari 20\n";
  return msg.c_str();
}

NamaDuplikatException::NamaDuplikatException(string str) : nama(str) {}

NamaDuplikatException::~NamaDuplikatException(){
  delete[] msgptr;
}

const char* NamaDuplikatException::what() const throw() {
  string msg = "NamaDuplikatException : Nama \"" + nama + "\" telah digunakan, silahkan gunakan nama lain\n" ;
  msgptr = new char[msg.length() + 1];
  // Copy the message string to the allocated memory
  strcpy(msgptr, msg.c_str());
  // Return the pointer to the allocated memory
  return msgptr;
}

// return msg.c_str();
IndexOutOfBoundsException::IndexOutOfBoundsException(int _index, int _batas) : index(_index), batas(_batas) {}

IndexOutOfBoundsException::~IndexOutOfBoundsException(){}

const char* IndexOutOfBoundsException::what() const throw() {
  string msg = "IndexOutOfBoundsException : Index " + to_string(index) + " tidak valid, index harus berada diantara 1 dan " + to_string(batas);
  return msg.c_str();
}

IndexNotValidException::IndexNotValidException(int _index) : index(_index) {}

IndexNotValidException::~IndexNotValidException(){}

const char* IndexNotValidException::what() const throw() {
  string msg = "IndexNotValidException : Index " + to_string(index) + " tidak valid, index tidak boleh diri sendiri";
  return msg.c_str();
}

InvalidInputException::InvalidInputException(string _input) : input(_input) {}

InvalidInputException::~InvalidInputException(){}

const char* InvalidInputException::what() const throw() {
  string msg = "InvalidInputException : Input tidak valid, " + input;
  return msg.c_str();
}

SameIndexException::SameIndexException(int _index) : index(_index) {}

SameIndexException::~SameIndexException(){}

const char* SameIndexException::what() const throw() {
  string msg = "SameIndexException : Index " + to_string(index) + " tidak valid, index tidak boleh sama";
  return msg.c_str();
}
