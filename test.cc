// Copyright jwowillo

#include "./test.h"

#include <memory>

TEST(box_link_List, PushFront) {
  test::ListPushFront(std::make_unique<box::link::List<int>>().get());
}

TEST(box_link_List, PushBack) {
  test::ListPushBack(std::make_unique<box::link::List<int>>().get());
}

TEST(box_link_List, PopFront) {
  test::ListPopFront(std::make_unique<box::link::List<int>>().get());
}

TEST(box_link_List, PopBack) {
  test::ListPopBack(std::make_unique<box::link::List<int>>().get());
}

TEST(box_link_List, PeekFront) {
  test::ListPeekFront(std::make_unique<box::link::List<int>>().get());
}

TEST(box_link_List, PeekBack) {
  test::ListPeekBack(std::make_unique<box::link::List<int>>().get());
}

TEST(box_link_List, Length) {
  test::ListLength(std::make_unique<box::link::List<int>>().get());
}

TEST(box_link_List, IsEmpty) {
  test::ListIsEmpty(std::make_unique<box::link::List<int>>().get());
}

TEST(box_standard_List, PushFront) {
  test::ListPushFront(std::make_unique<box::standard::List<int>>().get());
}

TEST(box_standard_List, PushBack) {
  test::ListPushBack(std::make_unique<box::standard::List<int>>().get());
}

TEST(box_standard_List, PopFront) {
  test::ListPopFront(std::make_unique<box::standard::List<int>>().get());
}

TEST(box_standard_List, PopBack) {
  test::ListPopBack(std::make_unique<box::standard::List<int>>().get());
}

TEST(box_standard_List, PeekFront) {
  test::ListPeekFront(std::make_unique<box::standard::List<int>>().get());
}

TEST(box_standard_List, PeekBack) {
  test::ListPeekBack(std::make_unique<box::standard::List<int>>().get());
}

TEST(box_standard_List, Length) {
  test::ListLength(std::make_unique<box::standard::List<int>>().get());
}

TEST(box_standard_List, IsEmpty) {
  test::ListIsEmpty(std::make_unique<box::standard::List<int>>().get());
}

TEST(box_standard_Queue, Push) {
  test::QueuePush(std::make_unique<box::standard::Queue<int>>().get());
}

TEST(box_standard_Queue, Pop) {
  test::QueuePop(std::make_unique<box::standard::Queue<int>>().get());
}

TEST(box_standard_Queue, Peek) {
  test::QueuePeek(std::make_unique<box::standard::Queue<int>>().get());
}

TEST(box_standard_Queue, Length) {
  test::QueueLength(std::make_unique<box::standard::Queue<int>>().get());
}

TEST(box_standard_Queue, IsEmpty) {
  test::QueueIsEmpty(std::make_unique<box::standard::Queue<int>>().get());
}

TEST(box_standard_Stack, Push) {
  test::StackPush(std::make_unique<box::standard::Stack<int>>().get());
}

TEST(box_standard_Stack, Pop) {
  test::StackPop(std::make_unique<box::standard::Stack<int>>().get());
}

TEST(box_standard_Stack, Peek) {
  test::StackPeek(std::make_unique<box::standard::Stack<int>>().get());
}

TEST(box_standard_Stack, Length) {
  test::StackLength(std::make_unique<box::standard::Stack<int>>().get());
}

TEST(box_standard_Stack, IsEmpty) {
  test::StackIsEmpty(std::make_unique<box::standard::Stack<int>>().get());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
