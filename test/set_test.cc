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

// AVLTree의 UpdateHeight, RotateLeft, RotateRight 함수 테스트
TEST_F(AVLTreeTestFixture, RotateFunctionsTest) {
  tree_.Inserting(40);
  tree_.Inserting(50);
  node* rootNode = tree_.Search(tree_.GetRoot(), 30);
  EXPECT_GT(rootNode->height, 0);
}

// 매개변수화된 AVLTree의 Finding 함수 테스트
class AVLTreeParameterizedTest
    : public ::testing::TestWithParam<std::tuple<int, int>> {
 protected:
  AVLTree tree_;

  void SetUp() override {
    tree_.Inserting(10);
    tree_.Inserting(20);
    tree_.Inserting(30);
    tree_.Inserting(5);
    tree_.Inserting(25);
  }
};

INSTANTIATE_TEST_CASE_P(
    AVLTreeFindingTests, AVLTreeParameterizedTest,
    ::testing::Values(std::make_tuple(10, 0), std::make_tuple(20, 1),
                      std::make_tuple(30, 2), std::make_tuple(5, 1),
                      std::make_tuple(25, 2), std::make_tuple(50, 0)));

TEST_P(AVLTreeParameterizedTest, FindingTest) {
  auto [key, expected] = GetParam();
  EXPECT_EQ(tree_.Finding(key), expected);
}

// SetAdapter의 테스트를 위한 Fixture
class SetAdapterTestFixture : public ::testing::Test {
 public:
  SetAdapterTestFixture() : adapter_(AVLTree()) {}
  ~SetAdapterTestFixture() override = default;

 protected:
  SetAdapter adapter_;

  void SetUp() override {
    adapter_.Insert(10);
    adapter_.Insert(20);
    adapter_.Insert(30);
    adapter_.Insert(5);
    adapter_.Insert(25);
  }

  void TearDown() override {
    // 테스트가 끝난 후 호출됨
  }
};

// SetAdapter의 Insert 함수 테스트
TEST_F(SetAdapterTestFixture, InsertTest) {
  adapter_.Insert(15);
  EXPECT_EQ(adapter_.GetAdaptee().GetSize(), 6);
  EXPECT_EQ(adapter_.GetAdaptee().Finding(15), 2);
}

// SetAdapter의 Erase 함수 테스트
TEST_F(SetAdapterTestFixture, EraseTest) {
  adapter_.Erase(20);
  EXPECT_EQ(adapter_.GetAdaptee().GetSize(), 4);
  EXPECT_EQ(adapter_.GetAdaptee().Finding(20), 0);
}

// SetAdapter의 Empty 함수 테스트
TEST_F(SetAdapterTestFixture, EmptyTest) {
  EXPECT_EQ(adapter_.GetAdaptee().IsEmpty(), 0);
}

// SetAdapter의 Size 함수 테스트
TEST_F(SetAdapterTestFixture, SizeTest) {
  EXPECT_EQ(adapter_.GetAdaptee().GetSize(), 5);
}

// SetAdapter의 Height 함수 테스트
TEST_F(SetAdapterTestFixture, HeightTest) {
  EXPECT_GT(adapter_.GetAdaptee().GetHeight(), 0);
}

// SetAdapter의 Ancestor 함수 테스트
TEST_F(SetAdapterTestFixture, AncestorTest) {
  testing::internal::CaptureStdout();
  adapter_.Ancestor(25);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_FALSE(output.empty());
}

// SetAdapter의 Average 함수 테스트
TEST_F(SetAdapterTestFixture, AverageTest) {
  testing::internal::CaptureStdout();
  adapter_.Average(10);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_FALSE(output.empty());
}

// SetAdapter의 Rank 함수 테스트
TEST_F(SetAdapterTestFixture, RankTest) {
  testing::internal::CaptureStdout();
  adapter_.Rank(30);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_FALSE(output.empty());
}
