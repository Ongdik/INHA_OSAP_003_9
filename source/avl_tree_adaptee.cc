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

int AVLTreeAdaptee::GetDepth(node* n) {
  int depth = 0;
  while (n->parent != nullptr) {
    n = n->parent;
    depth++;
  }
  return depth;
}

int AVLTreeAdaptee::GetHeightByNode(node* n) {
  return n ? n->height : 0;
}

int AVLTreeAdaptee::Finding(int key) {
  node* find_node = Search(root_, key);
  if (find_node == nullptr) return 0;

  int depth = GetDepth(find_node);
  int height = GetHeightByNode(find_node) - 1;

  return depth + height;
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