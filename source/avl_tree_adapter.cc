#include "../header/avl_tree_adapter.h"

void AVLTreeAdapter::Empty() {
  int result = adaptee_.IsEmpty();
  cout << result << "\n";
}

void AVLTreeAdapter::Size() {
  cout << adaptee_.GetSize() << "\n";
}

void AVLTreeAdapter::Height() {
  cout << adaptee_.GetHeight() << "\n";
}