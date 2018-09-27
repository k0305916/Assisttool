#include <functional>
#include <iostream>
 
struct Foo {
    Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout << num_+i << '\n'; }
    int num_;
};
 
void print_num(int i)
{
    std::cout << i << '\n';
}
 
struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};
 
int main()
{
    // // 存储自由函数---这个应该一般不会用。。。毕竟直接调用就可以了。。。为什么还这样搞一次
    // std::function<void(int)> f_display = print_num;
    // f_display(-9);
 
    // // 存储 lambda---这个还很容易理解
    // std::function<void()> f_display_42 = []() { print_num(42); };
    // f_display_42();
 
    // // 存储到 std::bind 调用的结果----这个感觉在某些时刻会有用吧。
    // std::function<void()> f_display_31337 = std::bind(print_num, 31337);
    // f_display_31337();
 
    // // 存储到成员函数的调用
    // std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    // const Foo foo(314161);
    // //f_add_display(foo, 1);
    // //为什么314159会是一个foo对象呢？
    // //解答：这个314159会调用foo的构造函数，然后构造一个const foo临时对象出来
    // f_add_display(314159, 1);
 
    // // 存储到数据成员访问器的调用
    // std::function<int(Foo const&)> f_num = &Foo::num_;
    // const Foo foo1(314161);
    // std::cout << "num_: " << f_num(foo1) << '\n';
 
    // // 存储到成员函数及对象的调用
    // using std::placeholders::_1;
    // const Foo foo2(314161);
    // std::function<void(int)> f_add_display2 = std::bind( &Foo::print_add, foo2, _1 );
    // f_add_display2(2);
 
    // // 存储到成员函数和对象指针的调用//感觉跟上面的一样，只是用地址来获取对象。。。免得构造函数的调用
    // using std::placeholders::_1;
    // const Foo foo3(314161);
    // std::function<void(int)> f_add_display3 = std::bind( &Foo::print_add, &foo3, _1 );
    // f_add_display3(3);
 
    // 存储到函数对象的调用
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18);
    getchar();
}