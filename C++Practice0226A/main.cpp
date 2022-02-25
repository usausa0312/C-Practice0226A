#include <cassert>
#include <iostream>
#include <string>

#if 1

class Test {
    std::string m_name;
public:
    Test(std::string name) : m_name(name) {}
    ~Test() = default;
    std::string& getValue() {  return m_name; }
    const std::string& getValue() const { return m_name; }
};


int main(void)
{
    Test x("AAA");

    std::cout << x.getValue() << std::endl;//&

    x.getValue() = "000";

    std::cout << x.getValue() << std::endl;//&

    const Test y("BBB");

    std::cout << y.getValue() << std::endl;//const

    //y.getValue() = "111"; エラー

    return 1;
}
#else

class Test2 {
    std::string m_name;
public:
    explicit Test2(std::string name) : m_name(name) {}
    ~Test2() = default;
    std::string&& getValue()&& { return std::move(m_name); }
    const std::string& getValue() const& { return m_name; }
};


int main() {
    Test2 x("xxx");
    const Test2 y("yyy");
    x.getValue(); // const
    y.getValue(); // const 

    Test2("zzz").getValue(); //&&
    std::string p = Test2("zzz").getValue(); //&&
    std::string q = std::move(x).getValue(); //&&

    // x.getValue() = "aaa"; // エラー
   
    return 1;
}

#endif 