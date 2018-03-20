// Copyright jwowillo

#ifndef LINK_H_
#define LINK_H_

#include <memory>
#include <stdexcept>

namespace box {
// link has linked box::Container implementations.
namespace link {

// List which is linked.
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
  // Node in the linked-structure.
  class Node {
   public:
    // next and previous Nodes in the List.
    std::shared_ptr<Node> next, previous;
    // Value at the Node.
    T value;
  };
  // head and tail of the List.
  std::shared_ptr<Node> head, tail;
  // length of the List.
  size_t length;
};

// Queue which is linked.
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

// Stack which is linked.
template <typename T>
class Stack : public box::Stack<T> {
 public:
  Stack() noexcept;
  void Push(const T&) noexcept override;
  T Pop() override;
  T Peek() const override;
  size_t Length() const noexcept override;

 private:
  // list used to implement the Stack.
  const std::unique_ptr<box::List<T>> list;
};

template <typename T>
void List<T>::PushFront(const T& x) noexcept {
  length++;
  if (head == nullptr) {
    head = std::make_shared<Node>();
    head->value = x;
    tail = head;
    return;
  }
  auto n = std::make_shared<Node>();
  n->value = x;
  n->next = head;
  head->previous = n;
  head = n;
}

template <typename T>
void List<T>::PushBack(const T& x) noexcept {
  length++;
  if (tail == nullptr) {
    tail = std::make_shared<Node>();
    tail->value = x;
    head = tail;
    return;
  }
  auto n = std::make_shared<Node>();
  n->value = x;
  n->previous = tail;
  tail->next = n;
  tail = n;
}

template <typename T>
T List<T>::PopFront() {
  if (head == nullptr) {
    throw std::logic_error("pop from empty list");
  }
  length--;
  auto x = head->value;
  if (head == tail) {
    head = nullptr;
    tail = nullptr;
  } else {
    head = head->next;
    head->previous = nullptr;
  }
  return x;
}

template <typename T>
T List<T>::PopBack() {
  if (tail == nullptr) {
    throw std::logic_error("pop from empty list");
  }
  length--;
  T x = tail->value;
  if (head == tail) {
    head = nullptr;
    tail = nullptr;
  } else {
    tail = tail->previous;
    tail->next = nullptr;
  }
  return x;
}

template <typename T>
T List<T>::PeekFront() const {
  if (head == nullptr) {
    throw std::logic_error("peek in empty list");
  }
  return head->value;
}

template <typename T>
T List<T>::PeekBack() const {
  if (tail == nullptr) {
    throw std::logic_error("peek in empty list");
  }
  return tail->value;
}

template <typename T>
size_t List<T>::Length() const noexcept {
  return length;
}

template <typename T>
Queue<T>::Queue() noexcept : list(std::make_unique<link::List<T>>()) {}

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
Stack<T>::Stack() noexcept : list(std::make_unique<link::List<T>>()) {}

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

}  // namespace link
}  // namespace box

#endif  // LINK_H_
