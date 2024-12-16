#include "../header/set_adapter.h"

void SetAdapter::Find(int key) {
  cout << adaptee_.Finding(key) << "\n";
}

void SetAdapter::Empty() {
  cout << adaptee_.IsEmpty() << "\n";
}

void SetAdapter::Size() {
  cout << adaptee_.GetSize() << "\n";
}

void SetAdapter::Height() {
  cout << adaptee_.GetHeight() << "\n";
}

void SetAdapter::Insert(int x) {
  cout << adaptee_.Inserting(x) << endl;
}

void SetAdapter::Erase(int x) {
  adaptee_.Erasing(x);
}

