#include <iostream>

class Test {
public:
  explicit Test(int a) {
    a_ = a;
    std::cout << a << std::endl;
  }
  Test() = delete;
  void print() { std::cout << "print:" << a_ << std::endl; }

private:
  int a_;
};

int main(void) {
  Test test1{1};
  // Test test2 = 2;    // 暗黙的型変換を含む変更はNG
  Test test3 = Test(3);          //コピー初期化はOK
  Test test4 = std::move(test3); // moveもできる
  test4.print();
}