#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void expireCallback(const boost::system::error_code& /*e*/) {
  std::cout << "Hello from expireCallback" << std::endl;
}

void printCallback(const boost::system::error_code& /*e*/,
                   boost::asio::deadline_timer* t, int* count) {
  // Only for 5 ticks!
  if (*count < 5) {
    std::cout << "[printCallback] " << *count << std::endl;
    ++(*count);
    t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
    t->async_wait(boost::bind(printCallback,
                              boost::asio::placeholders::error,
                              t,
                              count));
  } else {
    t->async_wait(&expireCallback);
  }
}

class Printer {
 public:
  Printer(boost::asio::io_service& io)
      : timer_(io, boost::posix_time::seconds(1)),
        count_(0) {
    timer_.async_wait(boost::bind(&Printer::onTick, this));
  }

  ~Printer() {
    std::cout << "[Printer:" << this << "] final count = " << count_ << std::endl;
  }

  void onTick() {
    if (count_ < 5) {
      std::cout << "[Printer::onTick] " << count_ << std::endl;
      ++count_;
      timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
      timer_.async_wait(boost::bind(&Printer::onTick, this));
    } else {
      timer_.async_wait(boost::bind(&Printer::onExpire, this));
    }
  }

  void onExpire() {
    std::cout << "[Printer::onExpire] " << count_ << std::endl;
  }

 private:
  boost::asio::deadline_timer timer_;
  int count_;
};


int main(int argc, const char *argv[])
{
  boost::asio::io_service io;

  Printer p(io);

  io.run();
  std::cout << "Hello after calling io.run!" << std::endl;

  return 0;
}
