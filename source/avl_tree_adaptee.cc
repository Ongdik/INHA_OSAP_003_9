#include "../header/avl_tree_adaptee.h"

AVLTreeAdaptee::AVLTreeAdaptee() : root_(NULL) {}

int AVLTreeAdaptee::IsEmpty() {
  return root_ ? 0 : 1;  // 비어있으면 0 출력
}