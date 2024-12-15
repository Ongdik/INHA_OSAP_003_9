#include "../header/avl_tree_adapter.h"

void AVLTreeAdapter::Empty() {
  int result = adaptee_.IsEmpty();
  cout << result << "\n";
}
