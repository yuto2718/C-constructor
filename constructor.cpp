#include <iostream>

class Test {
public:
  Test(int a) { std::cout << a << std::endl; }
};

int main(void) {
  Test test1{1};
  Test test2 = 2;
  Test test3 = Test(3);
}

// Test test1{1}以外の呼び方，暗黙的に利用されたくない場合は次のように書く必要がある

// class Test {
// public:
//   explicit Test(int a) { std::cout << a << std::endl; }
//   Test() = delete;
//   Test(const Test &other) = delete;
//   Test(const Test &&other) = delete;
//   Test &operator=(const Test &obj) = delete;
//   Test &&operator=(const Test &&obj) = delete;
// };