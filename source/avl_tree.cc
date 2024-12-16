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

void AVLTree::UpdateHeight(node* n) {
  if (n) {
    n->height = 1 + max(GetHeightByNode(n->left), GetHeightByNode(n->right));
  }
}

node* AVLTree::RotateRight(node* y) {
  node* x = y->left;
  node* T2 = x->right;

  x->right = y;
  y->left = T2;

  if (T2) T2->parent = y;
  x->parent = y->parent;
  y->parent = x;

  UpdateHeight(y);
  UpdateHeight(x);
  UpdateSubTreeSize(y);
  UpdateSubTreeSize(x);

  return x;
}

node* AVLTree::RotateLeft(node* x) {
  node* y = x->right;
  node* T2 = y->left;

  y->left = x;
  x->right = T2;

  if (T2) T2->parent = x;
  y->parent = x->parent;
  x->parent = y;

  UpdateHeight(x);
  UpdateHeight(y);
  UpdateSubTreeSize(x);
  UpdateSubTreeSize(y);

  return y;
}

node* AVLTree::Balance(node* n) {
  UpdateHeight(n);
  UpdateSubTreeSize(n);
  int balance_factor = GetBalance(n);

  if (balance_factor > 1 && GetBalance(n->left) >= 0)
    return RotateRight(n);

  if (balance_factor > 1 && GetBalance(n->left) < 0) {
    n->left = RotateLeft(n->left);
    return RotateRight(n);
  }

  if (balance_factor < -1 && GetBalance(n->right) <= 0) {
    return RotateLeft(n);
  }

  if (balance_factor < -1 && GetBalance(n->right) > 0) {
    n->right = RotateRight(n->right);
    return RotateLeft(n);
  }

  return n;
}

int AVLTree::Inserting(int x) {
  node* new_node = new node(x);
  size_++;
  if (root_ == nullptr) {
    root_ = new_node;
    return 0;
  }

  node* cur_node = root_;
  node* par_node = nullptr;

  while (cur_node != nullptr) {
    par_node = cur_node;
    if (cur_node->key < x) {
      cur_node = cur_node->right;
    } else {
      cur_node = cur_node->left;
    }
  }

  new_node->parent = par_node;
  if (par_node->key < x) {
    par_node->right = new_node;
  } else {
    par_node->left = new_node;
  }

  node* tmp = new_node;
  while (tmp != nullptr) {
    tmp = Balance(tmp);
    tmp = tmp->parent;
  }

  while (root_->parent != nullptr) {
    root_ = root_->parent;
  }

  return Finding(x);
}

int AVLTree::GetSubTreeSize(node* n) {
  return n ? n->size : 0;
}

void AVLTree::UpdateSubTreeSize(node* n) {
  n->size = 1 + GetSubTreeSize(n->left) + GetSubTreeSize(n->right);
}
