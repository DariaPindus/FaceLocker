#ifndef TIMER_H
#define TIMER_H
#include <functional>

namespace utils {
namespace timer {
typedef std::function<void()> TimeOutCallBack;
typedef std::function<void()> StepCallBack;

class Timer {
  virtual void set_timeout_callback(TimeOutCallBack callback) = 0;
  virtual void set_step_callback(StepCallBack callback) = 0;
  virtual void Start(unsigned int timeout, unsigned int step_timeout) = 0;
  virtual unsigned int get_timeout() const = 0;
  virtual unsigned int get_step_timeout() const = 0;
  virtual unsigned int GetTimeLeft() const = 0;
  virtual void Stop() = 0;
};

}  // namespace timer
}  // namespace utils
#endif  // TIMER_H
