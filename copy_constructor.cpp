#include <iostream>

class Test {
public:
  // コンストラクタ
  explicit Test(int a) {
    a_ = a;
    std::cout << "constructor: " << a << std::endl;
  }
  // コピーコンストラクタ
  Test(const Test &other) { std::cout << "copy constructor" << std::endl; };
  // デフォルトコンストラクタ削除
  Test() = delete;
  
  // コピー代入オペレータ
  Test &operator=(const Test &obj) {
    std::cout << "copy operator" << std::endl;
    return *this;
  }
  void print() { std::cout << "print: " << a_ << std::endl; }

private:
  int a_;
};

Test getTest(int init_val) {
  Test hoge{init_val};
  return hoge;
}

int main(void) {
  Test test1{1};
  Test test2 =
      Test(3); // コピー初期化はcopy constructorではなくconstructorが呼ばれる
  Test test3 = test2; // 右辺値ではなく左辺値からのコピーなので，copy
                      // constructorが呼ばれる．

  // オペレータの明示的オーバーライドの必要性
  test1 = getTest(3);
  // この実装の場合copy constructorが2回呼ばれてコピーを実行するはずだか，コンパイラが最適化してしまう．（思った動作にならない）
  // 正しくコピーを実行させるためにはオペレータが必要になる
}