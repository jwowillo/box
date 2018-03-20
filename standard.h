// Copyright jwowillo

#ifndef STANDARD_H_
#define STANDARD_H_

#include <list>
#include <memory>
#include <stdexcept>

namespace box {
// standard has standard-library using box::Container implementations.
namespace standard {

// List implemented with the standard-library.
template <typename T>
class List : public box::List<T> {
 public:
  void PushFront(const T&) noexcept override;
  void PushBack(const T&) noexcept override;
  T PopFront() override;
  T PopBack() override;
  T PeekFront() const override;
  T PeekBack() const override;
  size_t Length() const noexcept override;

 private:
  // list to implement container.
  std::list<T> list;
};

// Queue implemented with the standard-library.
template <typename T>
class Queue : public box::Queue<T> {
 public:
  Queue() noexcept;
  void Push(const T&) noexcept override;
  T Pop() override;
  T Peek() const override;
  size_t Length() const noexcept override;

 private:
  // list used to implement the Queue.
  const std::unique_ptr<box::List<T>> list;
};

// Stack implemented with the standard-library.
template <typename T>
class Stack : public box::Stack<T> {
 public:
  Stack() noexcept;
  void Push(const T&) noexcept override;
  T Pop() override;
  T Peek() const override;
  size_t Length() const noexcept override;

 private:
  // list used to implement the Queue.
  const std::unique_ptr<box::List<T>> list;
};


template <typename T>
void List<T>::PushFront(const T& x) noexcept {
  list.push_front(x);
}

template <typename T>
void List<T>::PushBack(const T& x) noexcept {
  list.push_back(x);
}

template <typename T>
T List<T>::PopFront() {
  if (list.size() == 0) {
    throw std::logic_error("peek in empty list");
  }
  auto x = list.front();
  list.pop_front();
  return x;
}

template <typename T>
T List<T>::PopBack() {
  if (list.size() == 0) {
    throw std::logic_error("peek in empty list");
  }
  auto x = list.back();
  list.pop_back();
  return x;
}

template <typename T>
T List<T>::PeekFront() const {
  if (list.size() == 0) {
    throw std::logic_error("peek in empty list");
  }
  return list.front();
}

template <typename T>
T List<T>::PeekBack() const {
  if (list.size() == 0) {
    throw std::logic_error("peek in empty list");
  }
  return list.back();
}

template <typename T>
size_t List<T>::Length() const noexcept {
  return list.size();
}

template <typename T>
Queue<T>::Queue() noexcept : list(std::make_unique<standard::List<T>>()) {}

template <typename T>
void Queue<T>::Push(const T& x) noexcept {
  list->PushBack(x);
}

template <typename T>
T Queue<T>::Pop() {
  return list->PopFront();
}

template <typename T>
T Queue<T>::Peek() const {
  return list->PeekFront();
}

template <typename T>
size_t Queue<T>::Length() const noexcept {
  return list->Length();
}

template <typename T>
Stack<T>::Stack() noexcept : list(std::make_unique<standard::List<T>>()) {}

template <typename T>
void Stack<T>::Push(const T& x) noexcept {
  list->PushBack(x);
}

template <typename T>
T Stack<T>::Pop() {
  return list->PopBack();
}

template <typename T>
T Stack<T>::Peek() const {
  return list->PeekBack();
}

template <typename T>
size_t Stack<T>::Length() const noexcept {
  return list->Length();
}

}  // namespace standard
}  // namespace box

#endif  // STANDARD_H_
