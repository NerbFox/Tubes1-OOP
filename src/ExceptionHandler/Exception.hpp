#include <exception>
#include <string>
using namespace std;

class Exception : public std::exception {
  private:
    std::string message;
  public:
    Exception(std::string message);
    ~Exception();
    const char* what() const throw();
};