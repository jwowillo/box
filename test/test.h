// Copyright jwowillo

#include "gtest/gtest.h"

#include "box.h"

namespace test {

template <typename T>
void ListPushFront(box::List<T>* l) {
  l->PushFront(1);
  l->PushFront(2);
  l->PushFront(3);
  EXPECT_EQ(3, l->PopFront());
  EXPECT_EQ(2, l->PopFront());
  EXPECT_EQ(1, l->PopFront());
}

template <typename T>
void ListPushBack(box::List<T>* l) {
  l->PushBack(1);
  l->PushBack(2);
  l->PushBack(3);
  EXPECT_EQ(1, l->PopFront());
  EXPECT_EQ(2, l->PopFront());
  EXPECT_EQ(3, l->PopFront());
}

template <typename T>
void ListPopFront(box::List<T>* l) {
  l->PushBack(1);
  l->PushBack(2);
  l->PushBack(3);
  int expected = l->PeekFront();
  int actual = l->PopFront();
  EXPECT_EQ(expected, actual);
  expected = l->PeekFront();
  actual = l->PopFront();
  EXPECT_EQ(expected, actual);
  expected = l->PeekFront();
  actual = l->PopFront();
  EXPECT_EQ(expected, actual);
}

template <typename T>
void ListPopBack(box::List<T>* l) {
  l->PushBack(1);
  l->PushBack(2);
  l->PushBack(3);
  int expected = l->PeekBack();
  int actual = l->PopBack();
  EXPECT_EQ(expected, actual);
  expected = l->PeekBack();
  actual = l->PopBack();
  EXPECT_EQ(expected, actual);
  expected = l->PeekBack();
  actual = l->PopBack();
  EXPECT_EQ(expected, actual);
}

template <typename T>
void ListPeekFront(box::List<T>* l) {
  l->PushFront(1);
  EXPECT_EQ(1, l->PeekFront());
  l->PushFront(2);
  EXPECT_EQ(2, l->PeekFront());
  l->PushFront(3);
  EXPECT_EQ(3, l->PeekFront());
}

template <typename T>
void ListPeekBack(box::List<T>* l) {
  l->PushBack(1);
  EXPECT_EQ(1, l->PeekBack());
  l->PushBack(2);
  EXPECT_EQ(2, l->PeekBack());
  l->PushBack(3);
  EXPECT_EQ(3, l->PeekBack());
}

template <typename T>
void ListLength(box::List<T>* l) {
  l->PushBack(1);
  l->PushBack(2);
  l->PushBack(3);
  l->PushFront(4);
  l->PushFront(5);
  l->PushFront(6);
  EXPECT_EQ(6, l->Length());
}

template <typename T>
void ListIsEmpty(box::List<T>* l) {
  EXPECT_TRUE(box::IsEmpty(*l));
  l->PushBack(1);
  EXPECT_FALSE(box::IsEmpty(*l));
}

template <typename T>
void QueuePush(box::Queue<T>* q) {
  q->Push(1);
  q->Push(2);
  q->Push(3);
  EXPECT_EQ(1, q->Pop());
  EXPECT_EQ(2, q->Pop());
  EXPECT_EQ(3, q->Pop());
}

template <typename T>
void QueuePop(box::Queue<T>* q) {
  q->Push(1);
  q->Push(2);
  q->Push(3);
  int expected = q->Peek();
  int actual = q->Pop();
  EXPECT_EQ(expected, actual);
  expected = q->Peek();
  actual = q->Pop();
  EXPECT_EQ(expected, actual);
  expected = q->Peek();
  actual = q->Pop();
  EXPECT_EQ(expected, actual);
}

template <typename T>
void QueuePeek(box::Queue<T>* q) {
  q->Push(1);
  EXPECT_EQ(1, q->Peek());
  q->Push(2);
  EXPECT_EQ(1, q->Peek());
  q->Pop();
  EXPECT_EQ(2, q->Peek());
}

template <typename T>
void QueueLength(box::Queue<T>* q) {
  q->Push(1);
  q->Push(2);
  q->Push(3);
  EXPECT_EQ(3, q->Length());
}

template <typename T>
void QueueIsEmpty(box::Queue<T>* q) {
  EXPECT_TRUE(box::IsEmpty(*q));
  q->Push(1);
  EXPECT_FALSE(box::IsEmpty(*q));
}

template <typename T>
void StackPush(box::Stack<T>* s) {
  s->Push(1);
  s->Push(2);
  s->Push(3);
  EXPECT_EQ(3, s->Pop());
  EXPECT_EQ(2, s->Pop());
  EXPECT_EQ(1, s->Pop());
}

template <typename T>
void StackPop(box::Stack<T>* s) {
  s->Push(1);
  s->Push(2);
  s->Push(3);
  int expected = s->Peek();
  int actual = s->Pop();
  EXPECT_EQ(expected, actual);
  expected = s->Peek();
  actual = s->Pop();
  EXPECT_EQ(expected, actual);
  expected = s->Peek();
  actual = s->Pop();
  EXPECT_EQ(expected, actual);
}

template <typename T>
void StackPeek(box::Stack<T>* s) {
  s->Push(1);
  EXPECT_EQ(1, s->Peek());
  s->Push(2);
  EXPECT_EQ(2, s->Peek());
  s->Pop();
  EXPECT_EQ(1, s->Peek());
}

template <typename T>
void StackLength(box::Stack<T>* s) {
  s->Push(1);
  s->Push(2);
  s->Push(3);
  EXPECT_EQ(3, s->Length());
}

template <typename T>
void StackIsEmpty(box::Stack<T>* s) {
  EXPECT_TRUE(box::IsEmpty(*s));
  s->Push(1);
  EXPECT_FALSE(box::IsEmpty(*s));
}

}  // namespace test
