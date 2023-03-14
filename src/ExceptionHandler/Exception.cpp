#include "../lib-header/Exception/Exception.hpp"
#include <cstring>

using namespace std;

NamaPanjangException::NamaPanjangException(int _length) : length(_length) {}

NamaPanjangException::~NamaPanjangException(){}

string NamaPanjangException::what() const{
  string msg = "NamaPanjangException : Karakter berjumlah : " + to_string(length) + ", kurangi karakter supaya berjumlah kurang dari 20\n";
  return msg;
}

NamaDuplikatException::NamaDuplikatException(string str) : nama(str) {}

NamaDuplikatException::~NamaDuplikatException(){}

string NamaDuplikatException::what() const{
  string msg = "NamaDuplikatException : Nama \"" + nama + "\" telah digunakan, silahkan gunakan nama lain\n" ;
  return msg;
}

// return msg.c_str();
IndexOutOfBoundsException::IndexOutOfBoundsException(int _index, int _batas) : index(_index), batas(_batas) {}

IndexOutOfBoundsException::~IndexOutOfBoundsException(){}

string IndexOutOfBoundsException::what() const{
  string msg = "IndexOutOfBoundsException : Index " + to_string(index) + " tidak valid, index harus berada diantara 1 dan " + to_string(batas);
  return msg;
}

IndexNotValidException::IndexNotValidException(int _index) : index(_index) {}

IndexNotValidException::~IndexNotValidException(){}

string IndexNotValidException::what() const{
  string msg = "IndexNotValidException : Index " + to_string(index) + " tidak valid, index tidak boleh diri sendiri";
  return msg;
}

InvalidInputException::InvalidInputException(string _input) : input(_input) {}

InvalidInputException::~InvalidInputException(){}

string InvalidInputException::what() const {
  string msg = "InvalidInputException : Input tidak valid, " + input;
  return msg;
}

SameIndexException::SameIndexException(int _index) : index(_index) {}

SameIndexException::~SameIndexException(){}

string SameIndexException::what() const{
  string msg = "SameIndexException : Index " + to_string(index) + " tidak valid, index tidak boleh sama";
  return msg;
}

EmptyInputException::EmptyInputException() {}

EmptyInputException::~EmptyInputException(){}

string EmptyInputException::what() const{
  string msg = "EmptyInputException : Input tidak valid, input tidak boleh kosong";
  return msg;
}
