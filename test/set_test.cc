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

// AVLTree의 생성자 테스트
TEST_F(AVLTreeTestFixture, ConstructorTest) {
  AVLTree emptyTree;
  EXPECT_EQ(emptyTree.GetSize(), 0);
  EXPECT_EQ(emptyTree.IsEmpty(), 1);
}

// AVLTree의 Insert 함수 테스트
TEST_F(AVLTreeTestFixture, InsertTest) {
  EXPECT_EQ(tree_.GetSize(), 5);
  tree_.Inserting(15);
  EXPECT_EQ(tree_.GetSize(), 6);
  EXPECT_EQ(tree_.Finding(15), 2);
}

// AVLTree의 Erase 함수 테스트
TEST_F(AVLTreeTestFixture, EraseTest) {
  tree_.Erasing(20);
  EXPECT_EQ(tree_.GetSize(), 4);
  EXPECT_EQ(tree_.Finding(20), 0);
}

// AVLTree의 GetHeight 함수 테스트
TEST_F(AVLTreeTestFixture, GetHeightTest) {
  EXPECT_GT(tree_.GetHeight(), 0);
}

// AVLTree의 Balance 함수 테스트
TEST_F(AVLTreeTestFixture, BalanceTest) {
  tree_.Inserting(40);
  tree_.Inserting(50);
  EXPECT_GT(tree_.GetHeight(), 3);
}

// AVLTree의 GetDepth 함수 테스트
TEST_F(AVLTreeTestFixture, GetDepthTest) {
  node* foundNode = tree_.Search(tree_.GetRoot(), 10);
  EXPECT_EQ(tree_.GetDepth(foundNode), 0);
}

// AVLTree의 GetSubTreeSize 함수 테스트
TEST_F(AVLTreeTestFixture, GetSubTreeSizeTest) {
  node* foundNode = tree_.Search(tree_.GetRoot(), 10);
  EXPECT_EQ(tree_.GetSubTreeSize(foundNode), 5);
}