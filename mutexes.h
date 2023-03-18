#pragma once

#include <stdexcept>
#include <pthread.h>
#include <cstdint>
#include <vector>

// 1. Task
void thread_safe_increment(int& value);

// 2.Task
struct context_t {
  pthread_cond_t cond;
  pthread_mutex_t mtx;
  int shared_value;
  bool is_provided;
};

void provide(context_t& ctx, int value);

int consume(context_t& ctx);

// 3. Task
class stack {
public:
  stack() {
    pthread_mutex_init(&m_mutex, nullptr);
  }

  ~stack() {
    pthread_mutex_destroy(&m_mutex);
  }

  void push(int value);

  int pop();

private:
  std::vector<int> m_stack;
  pthread_mutex_t m_mutex;
};

// 4. Task
void merge_sort(std::vector<int>& values);
