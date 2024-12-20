#include <gtest/gtest.h>

#include "../header/avl_tree.h"
#include "../header/set_adapter.h"

// AVLTree의 테스트를 위한 Fixture
class AVLTreeTestFixture : public ::testing::Test {
 public:
  AVLTreeTestFixture() = default;
  ~AVLTreeTestFixture() override = default;

 protected:
  AVLTree tree_;

  void SetUp() override {
    // 초기화 - 테스트를 시작하기 전에 호출됨
    tree_.Inserting(10);
    tree_.Inserting(20);
    tree_.Inserting(30);
    tree_.Inserting(5);
    tree_.Inserting(25);
  }

  void TearDown() override {
    // 테스트가 끝난 후 호출됨
  }
};