#include "../header/avl_tree_adaptee.h"

AVLTreeAdaptee::AVLTreeAdaptee() : root_(NULL) {}

node* AVLTreeAdaptee::Search(node* cur_node, int key) {
  if (cur_node == nullptr) return nullptr;

  if (cur_node->key == key)
    return cur_node;
  else if (cur_node->key < key) {
    return Search(cur_node->right, key);
  } else {
    return Search(cur_node->left, key);
  }
}

int AVLTreeAdaptee::IsEmpty() {
  return root_ ? 0 : 1;  // 비어있으면 1, 아니면 0
}

int AVLTreeAdaptee::GetSize() {
  return size_;
}

int AVLTreeAdaptee::GetHeight() {
  return root_ ? (root_->height - 1) : -1;
}