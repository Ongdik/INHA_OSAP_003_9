#include "../header/set_adapter.h"

void AVLTreeAdapter::Find(int key) {
  cout << adaptee_.Finding(key) << "\n";
}

void AVLTreeAdapter::Empty() {
  cout << adaptee_.IsEmpty() << "\n";
}

void AVLTreeAdapter::Size() {
  cout << adaptee_.GetSize() << "\n";
}

void AVLTreeAdapter::Height() {
  cout << adaptee_.GetHeight() << "\n";
}
