#ifndef OSAP_HEADER_SET_ADAPTER_H_
#define OSAP_HEADER_SET_ADAPTER_H_

#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>
#include <queue>

#include "avl_tree.h"
#include "set.h"
using namespace std;

class SetAdapter : public Set {
 public:
  // 생성자
  SetAdapter(AVLTree adaptee);

  // 멤버 함수들
  void Find(int x) override;
  void Insert(int x) override;
  void Empty() override;
  void Size() override;
  void Height() override;
  void Ancestor(int x) override;
  void Average(int x) override;
  void Rank(int x) override;
  void Erase(int x) override;

  // 테스트 위한 Getter
  AVLTree GetAdaptee();

 private:
  AVLTree adaptee_;  // 내부적으로 사용할 AVLTree 객체
};

#endif
