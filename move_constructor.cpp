#include <iostream>
#include <memory>
#include <vector>

class Test {
public:
  // コンストラクタ
  explicit Test(int a) {
    a_ = a;
    std::cout << "constructor: " << a << std::endl;
  }
  // デフォルトコンストラクタ削除
  Test() = delete;

  // ムーブコンストラクタ
  Test(Test &&a) noexcept { std::cout << "move constructor " << std::endl; }
  // できるだけnoexceptを付ける．コンテナなどで利用するときにnoexceptが付いているかどうかで，move
  // constructorを呼ぶかどうかを決めるものがある
  // noexpectが付いていない場合は，moveではなく別の処理で対応しようとして，思った動作にならない

  // ムーブ代入オペレータ
  Test &operator=(Test &&other) noexcept {
    std::cout << "move operator" << std::endl;
    if (this != &other) {
      other.a_ = a_;
      other.p = std::move_if_noexcept(p);
      other.v = std::move_if_noexcept(v);
    }
    return *this;
  }
  // ディストラクタ
  ~Test() {
    std::cout << "Destructor " << a_ << std::endl;
    a_ = 0;
  }
  void print() { std::cout << "print: " << a_ << std::endl; }

private:
  int a_;
  std::unique_ptr<std::vector<float>> p;
  std::vector<int> v;
};

Test getTest(int init_val) {
  Test hoge{init_val};
  return std::move(hoge);
}

int main(void) {
  Test test1{1};
  Test test2 =
      Test(2); // コピー初期化はcopy constructorではなくconstructorが呼ばれる

  Test test3 = getTest(3); // Destrictorが呼ばれていることに注意する
  test3.print();

  Test test4{4};
  Test test5{6};
  test4.print();
  test5 = std::move(test4);
  test4.print();
}