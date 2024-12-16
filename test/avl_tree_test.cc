#include "../header/avl_tree.h"

#include <gtest/gtest.h>

// 테스트 위한 AVLTree의 추상 메서드
class MockAVLTree : public Set {
 public:
  void Find(int x) override {}
  void Insert(int x) override {}
  void Empty() override {}
  void Size() override {}
  void Height() override {}
  void Ancestor(int x) override {}
  void Average(int x) override {}
  void Rank(int x) override {}
  void Erase(int x) override {}
};

// 초기화 테스트
TEST(AVLTreeTest, Initialization) {
  MockAVLTree tree;
  SUCCEED();
}
