// Copyright jwowillo

#ifndef BOX_H_
#define BOX_H_

#include <cstddef>

// box defines container interfaces.
namespace box {

// Container only knows its length.
class Container {
 public:
  // Length of the Container.
  virtual size_t Length() const noexcept = 0;
};

// List is a Container which supports fast operations on its front and back.
template <typename T>
class List : public Container {
 public:
  // PushFront pushes to the front.
  virtual void PushFront(const T&) noexcept = 0;
  // PushBack pushes to the back.
  virtual void PushBack(const T&) noexcept = 0;
  // PopFront pops from the front.
  //
  // Raises an exception if the List is empty.
  virtual T PopFront() = 0;
  // PopBack pops from the back.
  //
  // Raises an exception if the List is empty.
  virtual T PopBack() = 0;
  // Peek at the front.
  //
  // Raises an exception if the List is empty.
  virtual T PeekFront() const = 0;
  // Peek at the back.
  //
  // Raises an exception if the List is empty.
  virtual T PeekBack() const = 0;
};

// Queue is a first-in first-out Container.
template <typename T>
class Queue : public Container {
 public:
  // Push to the back.
  virtual void Push(const T&) noexcept = 0;
  // Pop from the front.
  //
  // Raises an exception if the List is empty.
  virtual T Pop() = 0;
  // Peek at the front.
  //
  // Raises an exception if the List is empty.
  virtual T Peek() const = 0;
};

// Stack is a first-in last-out Container.
template <typename T>
class Stack : public Container {
 public:
  // Push to the top.
  virtual void Push(const T&) noexcept = 0;
  // Pop from the top.
  //
  // Raises an exception if the List is empty.
  virtual T Pop() = 0;
  // Peek at the top.
  //
  // Raises an exception if the List is empty.
  virtual T Peek() const = 0;
};

// IsEmpty returns true if the Container has no items.
bool IsEmpty(const Container& c) {
  return c.Length() == 0;
}

}  // namespace box

#include "./link.h"
#include "./standard.h"

#endif  // BOX_H_
