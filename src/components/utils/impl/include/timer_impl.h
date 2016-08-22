#ifndef TIMER_IMPL_H
#define TIMER_IMPL_H
#include <functional>
#include <thread>
#include "utils/timer.h"

namespace utils {
namespace timer {
typedef std::function<void()> CallBack;

class TimerImpl: public Timer {
    /**
  /** * @brief set_timeout_callback calls when timeout happens
  /** * @param callback
  /** */
public:
  TimerImpl(int timeout, CallBack func);
//  void set_callback(CallBack callback) override;
//  unsigned int GetTimeLeft() const override;
  void Start() override;
//  void Stop() override;
  void Terminate() override;

private:
  std::thread timer_thread_;
  std::mutex timer_mutex_;
  std::condition_variable cv_;
  CallBack timer_callback_;
  int timeout_;

  void MainThread() override;
  void DelayedCall(int timeout,CallBack func);

};

}  // namespace timer
}  // namespace utils
#endif  // TIMER_H