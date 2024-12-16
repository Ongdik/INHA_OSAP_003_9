#include "../header/avl_tree.h"

AVLTree::AVLTree() : root_(NULL) {}

node* AVLTree::Search(node* cur_node, int key) {
  if (cur_node == nullptr) return nullptr;

  if (cur_node->key == key)
    return cur_node;
  else if (cur_node->key < key) {
    return Search(cur_node->right, key);
  } else {
    return Search(cur_node->left, key);
  }
}

int AVLTree::GetDepth(node* n) {
  int depth = 0;
  while (n->parent != nullptr) {
    n = n->parent;
    depth++;
  }
  return depth;
}

int AVLTree::GetHeightByNode(node* n) {
  return n ? n->height : 0;
}

int AVLTree::Finding(int key) {
  node* find_node = Search(root_, key);
  if (find_node == nullptr) return 0;

  int depth = GetDepth(find_node);
  int height = GetHeightByNode(find_node) - 1;

  return depth + height;
}

int AVLTree::IsEmpty() {
  return root_ ? 0 : 1;  // 비어있으면 1, 아니면 0
}

int AVLTree::GetSize() {
  return size_;
}

int AVLTree::GetHeight() {
  return root_ ? (root_->height - 1) : -1;
}
