#include <iostream> // cout
#include <string>   // string
#include <memory>   // shared_ptr
#include <sstream>  // stringstream
#include <boost/chrono.hpp>

namespace chrono = boost::chrono;

class Base
{
};

class Hello : public Base
{
  private:
    std::string _msg;
    int _age = 0;
  public:
    const int *age;
    Hello() {}
    Hello(std::string const msg, int age):_msg(msg), _age(age) {}
    ~Hello() { std::cout << "destructor..." << std::endl; }

    void say() noexcept {
      age = &_age;
      if (!_msg.empty()) {
        std::cout << get_greeting() << std::endl;
        //std::cout << _msg << " at " << *age << std::endl;
      } else {
        std::cout << "Nothing" << std::endl;
      }
    }

    std::string get_greeting() const {
      std::string msg;
      std::stringstream ss;
      ss << *age;
      msg = "Hello, " + _msg + " is " + ss.str() + " years old xD";
      return msg;
    }
};

int main(int argc, char *argv[]) {
  chrono::steady_clock::time_point start, end;
  start = chrono::steady_clock::now();
  std::shared_ptr<Hello> h = std::make_shared<Hello>("Mako", 13);
  h->say();
  end = chrono::steady_clock::now();
  chrono::duration<double> elapsed = end - start;
  std::cout << "Time Elapsed: " << elapsed.count() << " sec." << std::endl;
  return 0;
}
