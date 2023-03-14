#include "../lib-header/Exception/Exception.hpp"

NamaPanjangException::NamaPanjangException(int _length) : length(_length) {}

NamaPanjangException::~NamaPanjangException(){}

const char* NamaPanjangException::what() const throw() {
  string msg = "NamaPanjangException : Karakter berjumlah : " + to_string(length) + ", seharusnya karakter berjumlah kurang dari 20.";
  return msg.c_str();
}

NamaDuplikatException::NamaDuplikatException(string str) : nama(str) {}

NamaDuplikatException::~NamaDuplikatException(){}

const char* NamaDuplikatException::what() const throw() {
  string msg = "NamaDuplikatException : Nama \"" + nama + "\" telah digunakan, silahkan gunakan nama lain" ;
  return msg.c_str();
}

IndexOutOfBoundsException::IndexOutOfBoundsException(int _index) : index(_index) {}

IndexOutOfBoundsException::~IndexOutOfBoundsException(){}

const char* IndexOutOfBoundsException::what() const throw() {
  string msg = "IndexOutOfBoundsException : Index " + to_string(index) + " tidak valid, index harus berada diantara 1 dan 7";
  return msg.c_str();
}

IndexNotValidException::IndexNotValidException(int _index) : index(_index) {}

IndexNotValidException::~IndexNotValidException(){}

const char* IndexNotValidException::what() const throw() {
  string msg = "IndexNotValidException : Index " + to_string(index) + " tidak valid, index tidak boleh diri sendiri";
  return msg.c_str();
}