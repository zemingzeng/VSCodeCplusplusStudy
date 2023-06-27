#include "CplusplusStudy.hpp"
#include <iostream>
#include <cstring>
#include <string>

namespace ming
{
    inline namespace ming1
    {
        int intA = 10;
        inline namespace ming2
        {
            int intA = 100;
        }
    }

}

#include <compare>
#include <charconv>
#include <format.h>

auto autoMethod(auto &context)
{
    context.begin();
    return "i am auto method!!!";
}

using namespace std;
using mingzz::Util;
using stringView = std::string_view;
class Apple
{
public:
    Apple() = default;
    Apple(const Apple &apple)
    {
        Util::LOGI("Apple's copy method copied price:%d!!", apple.price);
    };
    Apple(Apple &&apple)
    {
        Util::LOGI("Apple's move method moved price:%d!!", apple.price);
    }
    int price{0};
    Apple(int price_)
    {
        price = price_;
    }
    void begin()
    {
    }
    ~Apple()
    {
        Apple::begin();
        Util::LOGI("Apple's price:%d destructor!", price);
    }
};

void tempTest();

#include <numbers>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

void *operator new(size_t size, int blockType, const char *filename, int lineNumber);

#ifndef DBG_NEW
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
// #define new DBG_NEW
#endif

#include <memory>

class Water
{
public:
    Apple apply{1994};
    Water()
    {
    }
    ~Water()
    {
        Util::LOGI("Water's destructor!");
    }

public:
    static Apple *const apple;
    // const static int * intNum = nullptr;
    const static int intNum = 0;
};

Apple *const Water::apple = nullptr;

class PersonB; // 类的前向声明，用于解决循环依赖问题
class PersonA
{
public:
    weak_ptr<PersonB> smPPersonB;
    ~PersonA()
    {
        Util::LOGI("PersonA's destructor!");
    }
};
class PersonB
{
public:
    shared_ptr<PersonA> smPPersonA;
    ~PersonB()
    {
        Util::LOGI("PersonB's destructor!");
    }
};

Apple createApple();

#include <chrono>

void CplusplusStudy::study()
{
    Util::LOGI("\nStart-----------------------------------------------------------------------");
    Util::LOGI("this c++ study program!!!!!");

    Util::LOGI("\n-----------------20230308----------------------");
    Util::LOGI("<=> study:");
    string str1{"ghd"};
    string str2{"dfd"};
    Util::LOGI("str1-->%s", str1.c_str());
    Util::LOGI("str2-->%s", str2.c_str());
    auto result{str1 <=> str2};
    if (is_gt(result))
        Util::LOGI("str1 greater than str2");
    if (is_lt(result))
        Util::LOGI("str1 less than str2");
    if (is_eq(result))
        Util::LOGI("str1  equal  str2");

    Util::LOGI("\n-----------------20230309----------------------");
    auto str3{"hello world"};  // 解释为const char*
    auto str4{"hello world"s}; // 解释为string
    Util::LOGI("str3:%s  str4:%s", str3, str4.c_str());
    // using namespace ming::ming2;
    // ming::ming1::intA causes ambiguous
    Util::LOGI("inline namespace intA : %d", ming::ming1::ming2::intA);
    long double number1{3.143333333};
    string numberStr{to_string(number1)};
    Util::LOGI("numberStr : %s", numberStr.c_str());
    string str5(20, 'x');
    auto result1{to_chars(str5.data(), str5.data() + 5, 12345)};
    Util::LOGI("size str5:%d result1.ec:%d str5:%s", str5.size(), result1.ec, str5.c_str());
    // Using structured bindings
    /**struct to_chars_result
        {
          char* ptr;
          errc ec;
        }
     *
     */
    auto [ptr, ec] = to_chars(str5.data(), str5.data() + 5, 12345);
    Util::LOGI("struct bindings ptr:%s ec:%d", ptr, ec);

    Util::LOGI("\n-----------------20230311----------------------");
    int number2 = 1;
    // int number3 = (number2++) + (number2++); 未定义的行为
    // int number3 = (++number2) + number2;  未定义的行为
    int number3 = (++number2) + 1;
    Util::LOGI("number3:%d", number3);

    Util::LOGI("\n-----------------20230312----------------------");
    /**
     * 列表初始化有一些优点：
       1.列表初始化可以防止窄化转换（narrowing conversion）。例如，如果你试图使用一个浮点数来初始化一个整数，列表初始化会报错，而圆括号初始化不会。
       2.列表初始化可以用来初始化聚合类型（aggregate type），例如数组和结构体。这在圆括号初始化中是不可能的。
       3.列表初始化语法更加统一，可以用来初始化几乎所有类型的对象。
     *
     */
    Util::LOGI("C++11 引入的列表初始化（list initialization）语法，可替代圆括号初始化（parentheses initialization）");
    Apple apple1{1};
    Apple apple2 = Apple(1);
    Apple apple3 = Apple{1};
    Util::LOGI("使用各种方式初始化对象：Apple apple1{1}-->price:%d Apple apple2 = Apple(1)-->price:%d Apple apple3 = Apple{1}-->price:%d",
               apple1.price, apple2.price, apple3.price);
    Apple *pApple1 = new Apple{1};
    Apple *pApple2 = new Apple(1);
    Apple *pApple3{new Apple{2}};
    Util::LOGI("使用各种方式初始化对象指针：Apple *pApple1 = new Apple{1}-->price:%d Apple *pApple2 = new Apple(1)-->price:%d Apple *pApple3{new Apple{2}}-->price:%d",
               pApple1->price, pApple2->price, pApple3->price);
    delete pApple1;
    delete pApple2;
    delete pApple3;

    string string1{"hello"};
    string string2{string1};
    Util::LOGI("string1 addr:%p,string2 addr:%p", &string1, &string2);

    string string4{"the shy"};
    stringView string_view1 = string4;
    Util::LOGI("string4修改前的string_view length:%d", string_view1.length());
    string4 += " is MVP";
    // 在使用string_view时一定要确保它的有效性，比如它所指的string可能已经经过重新分配内存的操作了
    // 这样它就可能变得无效（即使它的data还能使用，但是还是得避免使用它，因为可能出现未定义的行为）
    Util::LOGI("string4修改后的string_view length:%d", string_view1.length());
    string_view1 = string4;
    Util::LOGI("最后的string_view length:%d", string_view1.length());

    Util::LOGI("\n-----------------20230313----------------------");
    string string5{"123"};
    stringView string_view2{string5 + "456"}; // 最好不能这么使用string_view这样会造成dangling pointer
    Util::LOGI("string_view2 data:%s", string_view2.data());
    auto string_view3{"Ni hao"sv};
    Util::LOGI(R"(sv 限定符,用auto推断会推断成string_view: auto string_view3{"Ni hao"sv})");
    Util::LOGI("size of wchar_t:%d", sizeof(wchar_t));
    // auto formatType = fmt::format("使用format来输出int=5的二进制:{:b}", 5);
    Util::LOGI("使用format来输出int=5的二进制:%s", fmt::format("{:b}", 5).data());

    Util::LOGI("\n-----------------20230314----------------------");
    string string6{"xxxxx"};
    stringView string_view4{string6};
    string string7{string_view4};
    Apple autoMethodParam{1};
    Util::LOGI(autoMethod(autoMethodParam));
    Util::LOGI("std::numbers中定义的常量pi:%.18f", numbers::pi);
    // memory
    int **ppInt{nullptr};
    ppInt = new int *;
    *ppInt = new int(5);
    Util::LOGI("当前的系统的指针占用内存字节:%d", sizeof(int *));
    Util::LOGI("指针也可以分配在free store内存中比如:\nint **ppInt{nullptr};ppInt = new int *;*ppInt = new int;\nppInt在stack区:%p,*ppInt在free store区:%p,最后的new int也在free store区:%p",
               &ppInt, ppInt, *ppInt);
    delete *ppInt;
    *ppInt = nullptr;
    delete ppInt;
    ppInt = nullptr;
    Util::LOGI("释放二级指针的顺序应该是:1. delete *ppInt; 2. *ppInt = nullptr; 3. delete ppInt; 4. ppInt = nullptr;");
    int *pInt1 = new (nothrow) int;
    if (nullptr == pInt1)
    {
        // 分配失败
    }
    delete pInt1;
    pInt1 = nullptr;
    Util::LOGI("一般情况下用new分配内存,分配失败则会抛异常,但是用int* p = new(nothorw) int;分配内存时分配失败则会返回空指针!");
    Apple *apple4{new Apple[2]{Apple(3), Apple(4)}};
    delete[] apple4;
    apple4 = nullptr;
    int(*ppInt1)[2] = {new int[2][2]}; // 数组指针
    delete[] pInt1;
    /**
     在C和C++中，当数组作为函数参数时，它会退化为指向数组第一个元素的指针。
     所以 void arrayMethod(int arr[4])、void arrayMethod(int *arr)、
     void arrayMethod(int arr[]) 和 void arrayMethod(int arr[n]) 都是等价的。
     的看传进来的参数是什么。
     然而void arrayMethod(int (&arr)[4])；此函数就必须传int[4]的参数
     当你试图访问指针外的地址时，可能会发生越界访问。越界访问可能会导致程序崩溃，也可能不会。
     这取决于操作系统如何处理这种情况。在某些情况下，操作系统可能会检测到越界访问并终止程序运行；
     在其他情况下，程序可能会继续运行，但其行为将变得不可预测。因此，应该避免越界访问。
     比如”int* p{new int}; (p+12)=10;“像这种就是未定义的行为
     */
    // int &arra[5]; c++中不能定义引用数组，因为引用是别名，没内存，数组所以无法分配内存

    Util::LOGI("\n-----------------20230315----------------------");
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    int *pInt2 = DBG_NEW int(4);
    delete pInt2;
    pInt2 = nullptr;
    auto smPInt1 = make_unique<int>();

    Util::LOGI("\n-----------------20230316----------------------");
    auto smPInt2 = make_unique<int>(7);
    smPInt2.reset(); // free res and set nullptr
    Util::LOGI("unique_ptr reset will free res and set nullptr,smPInt2 after reset status:%s",
               nullptr == smPInt2.get() ? "nullptr" : "not nullptr");
    auto smPInt3 = make_unique<int>(6);
    int *pInt3 = smPInt3.release();
    Util::LOGI("unique_ptr release will give up the pointer's ownership,smPInt3 after reset status:%s",
               nullptr == smPInt3.get() ? "nullptr" : "not nullptr");
    Util::LOGI("unique_ptr reset是释放持有的指针,并且设置新的指针资源,而release则是单纯释放指针资源的所有权,但不会delete指针,需要手动接收其返回值,然后delete");
    delete pInt3;
    pInt3 = nullptr;
    // Lamda表达式
    int captureInt = 99;
    []()
    { Util::LOGI("这是个Lamda表达式的匿名函数,并且调用了它:[](){}()"); }();
    [captureInt]() mutable -> void
    { Util::LOGI("这是个Lamda表达式的闭包,因为捕获列表不为空,并且调用了它:[captureInt](){}(),capture:%d", ++captureInt); }();
    Util::LOGI("按值捕获后外部的captureInt:%d", captureInt);
    [&captureInt]() -> void
    { Util::LOGI("这是个Lamda表达式的闭包,因为捕获列表不为空,并且调用了它:[&captureInt](){}(),capture:%d", ++captureInt); }();
    Util::LOGI("按引用捕获后的外部的captureInt:%d", captureInt);
    auto lamdaFunc1 = [](int param1) -> int
    { return param1; };
    Util::LOGI("Lamda表达式的函数也可以被赋值给变量,auto lamdaFunc1 = [](int param1) -> int{ return param1; };然后调用lamdaFunc1(76),返回值:%d",
               lamdaFunc1(76));
    Util::LOGI("Note:其实无捕获列表的Lamda匿名函数,可隐士转化成函数指针！");

    Util::LOGI("\n-----------------20230317----------------------");
    auto smPInt4 = make_shared<int>();
    auto smPInt5{smPInt4};
    Util::LOGI("smPInt4,smPInt5的reference count:%d,%d", smPInt4.use_count(), smPInt5.use_count());
    smPInt4.reset();
    Util::LOGI("after reset smPInt4,smPInt5的reference count:%d,%d", smPInt4.use_count(), smPInt5.use_count());
    Util::LOGI("after reset smPInt4 smPInt4.get()的state:%s", smPInt4.get() == nullptr ? "nullptr" : "not null");

    int number4 = 89;
    auto smPApple = make_shared<Apple>(234);
    auto smPIntApple{shared_ptr<int>{smPApple, &number4}};
    Util::LOGI("smPApple,smPIntApple reference count:%d,%d", smPApple.use_count(), smPIntApple.use_count());
    smPApple.reset();
    Util::LOGI("after smPApple reset,smPApple and smPIntApple reference count:%d,%d",
               smPApple.use_count(), smPIntApple.use_count());
    /**
      shared_ptr<int>{smPApple(这是控制块指针), &number4(这是存储指针)}，get()是返回存储指针，销毁时释放的是控制块指针，
      一般没用别名构造函数时，存储指针和控制块指针指向同一块内存
    */
    Util::LOGI("智能指针的别名构造函数构造的smPIntApple:auto smPIntApple{shared_ptr<int>{smPApple, &number4}};,其中smPIntApple指向的是int,但是有Apple的所有权及参与引用计数,smPIntApple值:%d",
               *(smPIntApple.get()));
    Water *pWater = new Water();
    Util::LOGI("当delete water pointer时看看water调用析构函数的时候是否会自动销毁成员变量apple,看看apple的构造函数有没有被调用-->");
    delete pWater;
    pWater = nullptr;
    /**
      循环引用，得用weak_ptr来解决!
      weak_ptr可以和shared_ptr共享指向的内存，但是它不增加引用计数.也可判断他是否被释放了
      有两种办法来使用weak_ptr:
      1.lock(),的到一个shared_ptr
      2.
     */
    auto smpPersionA = make_shared<PersonA>();
    auto smpPersionB = make_shared<PersonB>();
    smpPersionA->smPPersonB = smpPersionB;
    smpPersionB->smPPersonA = smpPersionA;
    // smpPersionA->smPPersonB.reset(); //不会影响shared_ptr的reference count,但是获取到的reference count和shared_ptr是一致的
    Util::LOGI("smpPersionA->smPPersonB expired:%s", (smpPersionA->smPPersonB.expired() ? "true" : "false"));
    Util::LOGI("smpPersionA->smPPersonB reference count:%d", smpPersionA->smPPersonB.use_count());
    shared_ptr<PersonB> smptr{
        smpPersionA->smPPersonB};
    Util::LOGI("shared_ptr smptr reference count:%d,smpPersionA->smPPersonB reference count:%d,smpPersionB reference count:%d",
               smptr.use_count(), smpPersionA->smPPersonB.use_count(), smpPersionB.use_count());

    Apple apple5 = createApple(); // 没打印应该触发了NRVO
    auto apple6 = move(apple5);   // 触发移动构造函数

    Util::LOGI("\n-----------------20230320----------------------");
    const char *pChar = "amazing";
    int count1 = 0;
    while (pChar[count1] != '\0')
    {
        count1++;
    }
    Util::LOGI(R"('\n' char in chars "amazing" char index is:%d)", count1);
    const int intNumber1 = 90;
    auto intNumber2 = intNumber1;
    const int &intNumberRef1 = intNumber1;
    auto intNumberRef2 = intNumberRef1;
    int *pInt4[3] = {0, 0, 0};
    int *(*pInt5)[3] = &pInt4;
    int *(*(*pInt6))[3] = &pInt5;
    Util::LOGI("int *pInt4[3];  int *(*pInt5)[3] = &pInt4;   int *(*(*pInt6))[3] = &pInt5;  pInt5:%p,pInt5+1:%p,pInt6:%p,pInt6+1:%p", pInt5, pInt5 + 1, pInt6, pInt6 + 1);
    Apple apple7; // default constructor will be called

    Util::LOGI("\n-----------------20230327----------------------");
    // 当前时间，单位us
    chrono::system_clock::time_point time_now = chrono::system_clock::now();
    chrono::system_clock::duration time_now_duration = time_now.time_since_epoch();
    time_t time_now_us = chrono::duration_cast<chrono::microseconds>(time_now_duration).count();
    Util::LOGI("now time is :%lld us", time_now_us);

    // temp test
    tempTest();
    Util::LOGI("\nEnd----------------------------------------------------------------------------------------");
}

Apple createApple()
{
    return Apple(556);
}

void *operator new(size_t size, int blockType, const char *filename, int lineNumber)
{
    void *ptr = _malloc_dbg(size, blockType, filename, lineNumber);
    return ptr;
}

void arrayMethod(int arr[4])
{
    *(arr) = 10;
    Util::LOGI("\narrayMethod arr指向的地址值是:%d", *arr);
}

typedef void FUNCTION1();     // 函数类型
typedef void (*PFUNCTION1)(); // 定义一个函数指针
void (*pFunc2)();             // 定义一个函数指针变量

void function1()
{
    Util::LOGI("this is function1!");
}

void funcTypeParamMethod(FUNCTION1 func) // 函数参数的函数类型会被转换成函数指针类型
{
    func();
}
FUNCTION1 func3; // 等价于void func3();

void myDeleter(int *p)
{
    delete p;
    p = nullptr;
    Util::LOGI("my uniqie_ptr deleter!!");
};

struct AppleST
{
public: // 结构体默认访问权限是public
    int price;
} appleST1;

#include <math.h>

class Sun
{
public:
    virtual void run()
    {
        Util::LOGI("Sun::run");
    }
    void start()
    {
        Sun::run();
        run();
    }
    virtual void life() = 0;

protected:
    int temperature = 199;

private:
    int distance = 0;
};

class Sun1 : public Sun
{
public:
    void run() override
    {
        Util::LOGI("Sun1::run");
    }

    void life() override
    {
    }
    static void hot()
    {
        Util::LOGI("sun1 hot");
    }
};

#include "demuxThread.h"
#include "safequeue.h"

enum class CharNumber : char
{
    A = 1,
    B,

};

auto traillingFunc() -> double
{
    Util::LOGI("tailling return type function");
    return 0.999;
}

#define SUNHOT Sun1::hot;

class Pear
{
public:
    int price = 0;
    int *pInt = nullptr;
    Sun1 *sun;
    Pear()
    {
        Util::LOGI("Pear()!");
    }
    Pear(int price)
    {
        this->price = price;
        Util::LOGI("Pear(int price)!");
    }
    Pear &operator=(const Pear &) // copy assignment operator
    {
        Util::LOGI("Pear &operator=(const Pear &)!");
        return *this;
    }
    Pear(const Pear &) // copy constructor
    {
        Util::LOGI("Pear(const Pear &)!");
    }
    Pear(Pear &&) // move constructor
    {
        Util::LOGI("Pear(Pear&&)!");
    }
    Pear &operator=(Pear &&src) // move assignment operator > copy assignment operator
    {
        this->sun = src.sun;
        src.sun = nullptr;
        Util::LOGI("Pear &operator=(Pear &&src)! this price:%d,src price:%d", this->price, src.price);
        return *this;
    }

    ~Pear()
    {
        Util::LOGI(" ~Pear()! price--->%d", price);
    }
};

class Watermelon
{

private:
    int count = 9;

protected:
    int weight = 10;

public:
    int price = 0;
    Pear pear1;
    Pear pear2;
    friend void iamFriendMethod(const Watermelon &);
    // 不要把自己的声明成友元来获取访问权限，这种打破了类的安全性和封装性
    // friend class Watermelon;
    Watermelon() : price{price == 0 ? 100 : 99}
    {
        pear1 = pear2;
        Util::LOGI("Watermelon price--->%d", price);
    };
    Watermelon(const Watermelon &)
    {
        Util::LOGI("Watermelon copy constructor! (only occurs initialize)");
    }
    Watermelon &
    operator=(const Watermelon &)
    {
        Util::LOGI("Watermelon assign operator!");
        return *this;
    }
};

void iamFriendMethod(const Watermelon &watermelon)
{
    Util::LOGI("iamFriendMethod of the class Watermelon,Its private count->%d,protected weight->% d,public price->% d ",
               watermelon.count,
               watermelon.weight,
               watermelon.price);
}

#include <utility>
#include <typeinfo.h>

void test20230605()
{
    Pear A, B;
    Pear &&C = Pear{};
    A = C;                      // 调用copy函数
    B = Pear{};                 // 如果有move assignment operator函数就调用move函数，如果没有就调用copy assignment operator函数
    Pear D = std::move(Pear{}); // 如果有move函数，则调用move构造函数，如果没得即调用copy构造函数
}

void func4(int &&);
void func5(int &&);

class Me
{
public:
    Pear pear;
    Me() : pear{Pear(5)}
    {
        Pear pear1 = Pear{3};
        pear = pear1;   // 调用的copy assignment operator
        pear = Pear{3}; // 调用的是move assignment operator不是copy assignment operator,
                        //  因为Pear{3}是个临时变量，可被当作右值引用
        Pear &&rfPear1 = Pear{9};
        rfPear1.sun = new Sun1();
        Util::LOGI("rfPear1 origin rfPear1 sun:%p", rfPear1.sun);
        pear = std::move(rfPear1); // 调用的是move assignment operator
                                   // 编译器默认生成的move函数并不会置空指针变量，需要自己实现
        Util::LOGI("after 'move assignment operator' rfPear1 sun:%p", rfPear1.sun);
        Util::LOGI("after 'move assignment operator' pear sun:%p", pear.sun);
        pear = rfPear1;                  // 调用的copy assignment operator
        Pear pear2 = rfPear1;            // 调用的copy constructor
        Pear pear3 = std::move(rfPear1); // 调用的move constructor
        Util::LOGI(" Me()! end!");
    }
};

class MutableStudy
{
public:
    mutable int counts = 99; // mutable 此关键字标记的成员可以const方法中被改变
    int counts1 = 10;
    void modify() const
    {
        counts++;
        Util::LOGI("void modify() const modify member counts->%d", counts);
        // counts1++; error
    }
};
class RefMethod
{
public:
    int nonTempGetInt() const &
    {
        Util::LOGI("int nonTempGetInt() &!");
        return 0;
    }
    int tempGetInt() &&
    {
        Util::LOGI("int tempGetInt() &&!");
        return 0;
    }
    int play() const
    {
        nonTempGetInt();
        return 0;
    }
};

void test20230606()
{
    RefMethod refMethod;
    refMethod.nonTempGetInt();
    // refMethod.tempGetInt(); error
    std::move(refMethod).tempGetInt();
    RefMethod{}.tempGetInt();
    // std::move(refMethod).nonTempGetInt(); error
    const RefMethod refMethod1;
    refMethod1.play();
    RefMethod refMethod2;
    refMethod2.play();
}

class ConstOverloadClass
{

public:
    void constOverloadFunc() const
    {
        Util::LOGI("void constOverloadFunc() const!");
    }
    void constOverloadFunc()
    {
        Util::LOGI("void constOverloadFunc()!");
    }
};

// #define mingzzLog(...) Util::LOGI(const char *__format, ...);

void test20230607()
{
    const ConstOverloadClass constConstOverloadClass;
    ConstOverloadClass nonConstconstOverloadClass;
    Util::LOGI("constConstOverloadClass.constOverloadFunc()-->");
    constConstOverloadClass.constOverloadFunc();
    Util::LOGI("nonConstconstOverloadClass.constOverloadFunc()-->");
    nonConstconstOverloadClass.constOverloadFunc();
    // 打印信息：
    // constConstOverloadClass.constOverloadFunc()-->
    // void constOverloadFunc() const!
    // nonConstconstOverloadClass.constOverloadFunc()-->
    // void constOverloadFunc()!
}

class StaticMemberClass
{
public:
    int nonStaticNumber = 12;
    static int staticNumber;
    const static int constStaticNumber = 89;
    const static int constStaticNumber1;
    // const static float constStaticNumber2=1.0f; // error: 'constexpr' needed for in-class initialization of static data member
    //'const float StaticMemberClass::constStaticNumber2' of non-integral type [-fpermissive]
    const int constNumber;
    StaticMemberClass() : constNumber(0), nonStaticNumber(12)
    {
    }
};
int StaticMemberClass::staticNumber = 345;
const int StaticMemberClass::constStaticNumber1 = 678;
void test20230608()
{
    StaticMemberClass staticMemberClass;
    Util::LOGI("staticMemberClass nonStaticNumber->%d,staticNumber->%d,constStaticNumber->%d,constNumber->%d,constStaticNumber1->%d",
               staticMemberClass.nonStaticNumber,
               StaticMemberClass::staticNumber,
               StaticMemberClass::constStaticNumber,
               staticMemberClass.constNumber,
               StaticMemberClass::constStaticNumber1);
    // 打印信息
    // staticMemberClass nonStaticNumber->12,staticNumber->345,constStaticNumber->89,constNumber->0,constStaticNumber1->678
}

class InlineStaticMemberClass
{
public:
    static inline int staticInlineNumber = 19;
    const int number;
    InlineStaticMemberClass() : number{777}
    {
        Util::LOGI("InlineStaticMemberClass() : number{7}!");
    }
    InlineStaticMemberClass(int number) : number(number)
    {
        Util::LOGI("InlineStaticMemberClass(int number)!");
        // this->number = number;
    }
    InlineStaticMemberClass(const InlineStaticMemberClass &) : InlineStaticMemberClass()
    {
        Util::LOGI("InlineStaticMemberClass(const InlineStaticMemberClass &) : InlineStaticMemberClass()!");
    }
};

class OuterClass
{
public:
    int OuterClassPublicNumber;
    class InnerClass
    {
    public:
        void test(const OuterClass &outerClass)
        {
            // 内部类可以访问外部类的private protected成员
            int addPrivateAndProtected = outerClass.outerClassPrivateNumber + outerClass.outerClassProtectedNumber;
            Util::LOGI("InnerClass addPrivateAndProtected->%d", addPrivateAndProtected);
        }
        int innerClassPublicNumber;

    private:
        int innerClassPrivateNumber;

    protected:
        int innerClassProtectedNumber;
    };
    void test(const InnerClass &innerClass)
    {
        // 外部类只能访问内部类的public成员
        Util::LOGI("InnerClass innerClassPublicNumber->%d", innerClass.innerClassPublicNumber);
        // innerClass.innerClassPrivateNumber; //error
        // innerClass.innerClassProtectedNumber; //error

        // 外部类里面可以访问private和protected的内部类
        OuterClass::InnerPrivateClass innerPrivateClass;     // ok
        OuterClass::InnerProtectedClass InnerProtectedClass; // ok
    }

private:
    class InnerPrivateClass
    {
    };
    int outerClassPrivateNumber;

protected:
    class InnerProtectedClass
    {
    };
    int outerClassProtectedNumber;
};

class OverloadOperatorClass
{
public:
    void operator()()
    {
        Util::LOGI("OverloadOperatorClass void operator()()!");
    }
    void operator-()
    {
        Util::LOGI("OverloadOperatorClass void operator-()!");
    }
    operator int() // operator <type> 隐式转换函数重载
    {
        Util::LOGI("OverloadOperatorClass operator int()!");
        return 1;
    }
    operator double() // operator <type> 隐式转换函数重载
    {
        Util::LOGI("OverloadOperatorClass operator double()!");
        return 1.0f;
    }
    operator Apple() // operator <type> 隐式转换函数重载
    {
        Util::LOGI("OverrideOperatorClass operator Apple()!");
        return Apple{};
    }
};

void test20230609()
{
    InlineStaticMemberClass inlineStaticMemberClass(200);
    Util::LOGI("inlineStaticMemberClass staticInlineNumber->%d,const int number->%d",
               InlineStaticMemberClass::staticInlineNumber, inlineStaticMemberClass.number);
    InlineStaticMemberClass inlineStaticMemberClass1 = inlineStaticMemberClass;
    Util::LOGI("inlineStaticMemberClass1 number->%d", inlineStaticMemberClass1.number);
    // 打印信息:
    // InlineStaticMemberClass(int number)!
    // inlineStaticMemberClass staticInlineNumber->19,const int number->200
    // InlineStaticMemberClass() : number{7}!
    // InlineStaticMemberClass(const InlineStaticMemberClass &) : InlineStaticMemberClass()!
    // inlineStaticMemberClass1 number->777
    OuterClass outerClass;
    OuterClass::InnerClass innerClass;
    outerClass.test(innerClass);
    innerClass.test(outerClass);
    // 外部类外面只能访问public声明的内部类
    //  OuterClass::InnerPrivateClass;//error
    //  OuterClass::InnerProtectedClass;//error

    OverloadOperatorClass overloadOperatorClass;
    overloadOperatorClass.operator()(); // 全名调用
    overloadOperatorClass();            // 省略调用
    overloadOperatorClass.operator-();  // 全名调用
    // overrideOperatorClass-; //error 不能这么调用，可能需要一个参数
    // 打印信息：
    // OverrideOperatorClass void operator()()!
    // OverrideOperatorClass void operator()()!
    // OverrideOperatorClass void operator-()!

    // 隐式调用的常见的几种方式如下：
    Apple apple = overloadOperatorClass.operator Apple(); // operator Apple() :全名称调用
    Apple apple1 = overloadOperatorClass;
    Apple apple2 = static_cast<Apple>(overloadOperatorClass); // 显示转换也会调用隐式转换重载（如果存在）
    int number = overloadOperatorClass;                       // operator int()
    double number1 = overloadOperatorClass;                   // operator double()
    // 打印信息：
    // OverrideOperatorClass operator Apple()!
    // OverrideOperatorClass operator Apple()!
    // OverrideOperatorClass operator Apple()!
    // OverloadOperatorClass operator int()!
    // OverloadOperatorClass operator double()!
}

class GlobalOperatorOverloadClass
{
public:
    void operator+(const GlobalOperatorOverloadClass &r)
    {
        Util::LOGI("void operator+(const GlobalOperatorOverloadClass&r)!");
    }
    void operator+()
    {
        Util::LOGI("void operator+()!");
    }
    // void operator+(const GlobalOperatorOverloadClass &l,const GlobalOperatorOverloadClass &r); //在类内部重载操作运算符只能有<=1的参数个数
};
GlobalOperatorOverloadClass operator-(const GlobalOperatorOverloadClass &l, const GlobalOperatorOverloadClass &r)
{
    Util::LOGI("GlobalOperatorOverloadClass operator+(const GlobalOperatorOverloadClass &l,const GlobalOperatorOverloadClass &r)!");
    return GlobalOperatorOverloadClass{};
}

void test20230612()
{
    GlobalOperatorOverloadClass GlobalOperatorOverloadClass1, GlobalOperatorOverloadClass2, GlobalOperatorOverloadClass3;
    GlobalOperatorOverloadClass1.operator+();
    GlobalOperatorOverloadClass1.operator+(GlobalOperatorOverloadClass2);
    // 全局的operator重载可以最多有2个参数 ，但是在类中定义的操作符重载方法最多只能有一个参数
    GlobalOperatorOverloadClass3 = GlobalOperatorOverloadClass1 - GlobalOperatorOverloadClass2;
    GlobalOperatorOverloadClass1 + GlobalOperatorOverloadClass2;
    // 打印信息：
    // void operator+()!
    // void operator+(const GlobalOperatorOverloadClass&r)!
    // GlobalOperatorOverloadClass operator+(const GlobalOperatorOverloadClass &l,const GlobalOperatorOverloadClass &r)!
    // void operator+(const GlobalOperatorOverloadClass&r)!
}

class BaseClass
{
public:
    virtual void BaseClassVirtualMethod()
    {
        Util::LOGI("virtual void BaseClassVirtualMethod()!");
    }

protected:
    int BaseClassProtectednumber = 1;

private:
    int BaseClassPrivatenumber = 2;

public:
    int BaseClassPublicnumber = 3;
};

class PublicDerivedClass : public BaseClass
{

public:
    void BaseClassVirtualMethod() override
    {
        Util::LOGI("PublicDerivedClass void BaseClassVirtualMethod() override!");
    }
    void showBaseClassMember()
    {
        // BaseClassPrivatenumber; //error 派生类不能访问基类的private member
        // 可以访问protected member,而且只能在类内部,public member没有访问限制
        Util::LOGI("void showBaseClassMember(): BaseClassProtectednumber->%d,BaseClassPublicnumber->%d", BaseClassProtectednumber, BaseClassPublicnumber);
    }
};

class ProtectedDerivedClass : protected BaseClass
{
};

class PrivateDerivedClass : private BaseClass
{
};

void test20230613()
{
    BaseClass baseClass;
    PublicDerivedClass publicDerivedClass;
    publicDerivedClass.showBaseClassMember();
    BaseClass *pBaseClass = &publicDerivedClass;
    pBaseClass->BaseClassVirtualMethod(); // 虽然是BaseClass指针，但是由于多态，BaseClass指针指向的是DerivedClass，所以调用的是DerivedClass重写的方法
    pBaseClass = &baseClass;
    pBaseClass->BaseClassVirtualMethod();
    // 打印信息：
    // void showBaseClassMember(): BaseClassProtectednumber->1,BaseClassPublicnumber->3
    // DerivedClass void BaseClassVirtualMethod() override!
    // virtual void BaseClassVirtualMethod()!

    ProtectedDerivedClass protectedDerivedClass;
    // protectedDerivedClass.BaseClassPublicnumber; // error protected继承,基类的public member在派生类中变为protected member
    // pBaseClass = &protectedDerivedClass; // protected继承 不能通过基类指针指向父类,可能因为基类成员最高访问权限是protected
    PrivateDerivedClass privateDerivedClass;
    // privateDerivedClass.BaseClassPublicnumber; // error private继承,基类的public,protected member在派生类中变为private member
    // pBaseClass = &privateDerivedClass; // private继承 不能通过基类指针指向父类,可能因为基类成员最高访问权限是private
}

class BaseClass1
{
public:
    BaseClass1()
    {
        Util::LOGI("BaseClass1()!");
    }
    virtual ~BaseClass1()
    {
        Util::LOGI("~BaseClass1()!");
    }
};
class DerivedClass1 : public BaseClass1
{
public:
    DerivedClass1()
    {
        Util::LOGI("DerivedClass1()!");
    }
    ~DerivedClass1()
    {
        Util::LOGI("~DerivedClass1()!");
    }
};
class DerivedClass2 : public DerivedClass1
{
public:
    DerivedClass2()
    {
        Util::LOGI("DerivedClass2()!");
    }
    ~DerivedClass2()
    {
        Util::LOGI("~DerivedClass2()!");
    }
};
void test20230614()
{
    PublicDerivedClass publicDerivedClass;
    BaseClass &rBaseClass = publicDerivedClass;  // 基类引用refer to 派生类
    BaseClass *pBaseClass = &publicDerivedClass; // 基类指针指向派生类
    rBaseClass.BaseClassVirtualMethod();         // 和指针一样同样可以产生多态行为
    pBaseClass->BaseClassVirtualMethod();
    // 打印信息：
    // PublicDerivedClass void BaseClassVirtualMethod() override!
    // PublicDerivedClass void BaseClassVirtualMethod() override!

    BaseClass1 *pBaseClass1 = new DerivedClass1();
    delete pBaseClass1;
    // 打印信息（当基类的析构函数不是virtual的时候，可以看到发生多态时派生类的析构没有被调用）：
    // BaseClass1()!
    // DerivedClass1()!
    // ~BaseClass1()!
    //////////////////////////当一个类可以被继承时应该把析构函数声明成virtual的////////////////
    // 打印信息（当基类的析构函数是virtual的时候，可以看到发生多态时,派生类的析构就能被调用）：
    // BaseClass1()!
    // DerivedClass1()!
    // ~DerivedClass1()!
    // ~BaseClass1()!
    DerivedClass1 *pDerivedClass1 = new DerivedClass2();
    delete pDerivedClass1;
    // 打印信息（当基类的析构函数是virtual的时候，其子类的析构函数也是virtual的）：
    // BaseClass1()!
    // DerivedClass1()!
    // DerivedClass2()!
    // ~DerivedClass2()!
    // ~DerivedClass1()!
    // ~BaseClass1()!
}

class Book
{
public:
    virtual int getPrice()
    {
        Util::LOGI("Book virtual int getPrice()!");
        return 0;
    }
};
class Math : public Book
{
public:
    int getPrice() override
    {
        Util::LOGI("Math int getPrice() override!");
        return 1;
    }
};

class Calculus : public Math
{
public:
    void buy()
    {
        Util::LOGI("Calculus void buy()!");
        getPrice();
    }
};

void test20230616()
{
    Calculus Calculus1;
    // 如果多重继承，基类有个virtual方法，派生类都实现(除了调用该方法的派生类)，
    // 如果在派生类中调用该方法，则会从继承关系从下往上找到该方法的实现，而不是直接调用最顶层的基类的方法
    Calculus1.buy();
    // 打印信息：
    // Calculus void buy()!
    // Math int getPrice() override!

    // Calculus Calculus2=Math();//error no implicit casting
    Math Math1 = Calculus1; // slicing upcasting

    Book &Book1 = Calculus1;
}

class Animal
{
public:
    Animal()
    {
        Util::LOGI("Animal()!");
    }
    Animal(const Animal &)
    {
        Util::LOGI("Animal(const Animal&)!");
    }
    string getName()
    {
        Util::LOGI("Animal string getName()!");
        return "Animal";
    }
};

class Cat : virtual public Animal
{
public:
    Cat()
    {
        Util::LOGI("Cat()!");
    }
    void eat()
    {
        Util::LOGI("Cat void eat()!");
    }
    // string getName()
    // {
    //     Util::LOGI("Cat string getName()!");
    //     return "Cat";
    // }
};
class Dog : virtual public Animal
{
public:
    Dog()
    {
        Util::LOGI("Dog()!");
    }
    void eat()
    {
        Util::LOGI("Dog void eat()!");
    }
};
class DogCat : public Cat, public Dog
{
public:
    DogCat()
    {
        Util::LOGI("DogCat()!");
    }
    // using Cat::eat; // using Cat::eat version
    using Dog::eat; // avoid ambigous when invoke DogCat1.eat(). using Dog::eat version
    void eat1()
    {
        eat();      // ambigous when without using 'BaseClass'::eat
        Dog::eat(); // using Dog::eat version
        Cat::eat(); // using Cat::eat version
        // Dog::getName();
        // InsightC++ 对应上面4个方法:
        // /* static_cast<Dog *>(this)-> */ eat();
        // /* static_cast<Dog *>(this)-> */ eat();
        // /* static_cast<Cat *>(this)-> */ eat();
        // /* static_cast<Animal *>(static_cast<Dog *>(this))-> */ getName();
    }
};

void test20230619()
{
    // Animal Animal1 = Animal(); // 构造函数
    // DogCat DogCat1;
    // DogCat1.Cat::eat(); // 居然还可以这样调用方法

    // 2 ways to avoid ambigous when two base class both has same method :
    // using XXX::xx or 直接在调用XXX::xx
    DogCat DogCat1;
    DogCat1.eat();
    DogCat1.eat1();
    // 打印信息：
    // Animal()!
    // Cat()!
    // Animal()!
    // Dog()!
    // DogCat()!
    // Dog void eat()!
    // Dog void eat()!
    // Dog void eat()!
    // Cat void eat()!

    DogCat DogCat3; // 菱形继承会实例化两个基类
    // error：菱形继承会实例化两个基类所以会产生 ambigous for base class Animal,即使using Dog::getName也同样ambigous，
    // 因为Dog没有getName方法定义也是派生来的,所以他会static_cast<Animal *>(this)->getName()(根据c++ insight);
    // 但是内存模型中有两个Animal的实例,编译器不知道调用哪个Animal的方法
    // getName();
    // 打印信息：
    // Animal()!
    // Cat()!
    // Animal()!
    // Dog()!
    // DogCat()!

    // 1.可以使用虚拟继承来解决此问题，2.当然也可以把方法声明成纯虚函数，即基类是抽象类不能被实例化
    // DogCat3.Animal::getName();
    Dog Dog1;
    Dog1.getName();
    DogCat3.getName();
    // 打印信息：
    //  Animal string getName()!
    //  Animal string getName()!
}

class Tree
{
public:
    Tree() = default;
    Tree(bool canWhat)
    {
        Util::LOGI("Tree(bool canWhat)!");
    }
    virtual void getHeight(bool)
    {
        Util::LOGI("Tree virtual void getHeight(bool)!");
    }
    void getHeight()
    {
        Util::LOGI("Tree void getHeight()!");
    }
};
class CherryTree : public Tree
{
public:
    using Tree::getHeight;
    CherryTree(bool)
    {
        Util::LOGI("CherryTree(bool)!");
    }
    void getHeight(bool) override
    {
        Util::LOGI("CherryTree void getHeight(bool) override!");
    }
};
void test20230620()
{
    CherryTree CherryTree1(true);

    CherryTree1.getHeight(false);
    // error: 当从基类override或者overload某个方法，此时基类的同名方法都会被hide,
    // 无论给什么参数都会走派生类的override或者overload的方法,除非使用using或者override或者overload所有其他参数版本的此方法
    // CherryTree1.getHeight();
    Tree &rTree = CherryTree1;
    rTree.getHeight(true);
    rTree.getHeight(); // 通过基类引用可以正确调用次方法
    // 打印信息：
    // CherryTree(bool)!
    // CherryTree void getHeight(bool) override!
    // CherryTree void getHeight(bool) override!
    // Tree void getHeight()!
}

class Computer
{
public:
    int price;
    virtual void playGame(int hours = 2) const
    {
        Util::LOGI("Computer virtual void playGame(int hours = 2) const! param hours->%d", hours);
    }
    virtual void listenMusic()
    {
        Util::LOGI("Computer virtual void listenMusic()!");
    }
    virtual void netChat()
    {
        Util::LOGI("Computer virtual void netChat()!");
    }

protected:
    void programming()
    {
        Util::LOGI("Computer protected void programming()!");
    }
};
class NoteBook : public Computer
{
public:
    using Computer::programming;
    // 基类virtual方法为public,private..,派生类为private,public..都视为override,
    // 但是如果基类为const，则派生类必须为const,否则视为overload
    void playGame(int hours = 4) const override
    {
        Util::LOGI("NoteBook void playGame(int hours = 4) const override! param hours->%d", hours);
    }

protected:
    void listenMusic() override
    {
        Util::LOGI("NoteBook protected void listenMusic() override!");
    }

private:
    void netChat() override
    {
        Util::LOGI("NoteBook private void netChat() override!");
    }

public:
    void callAnotherPrivateProtectedMethod(NoteBook &NoteBook1)
    {
        Util::LOGI("void callAnotherPrivateNetChat(NoteBook& NoteBook1)!");
        NoteBook1.netChat();
        NoteBook1.listenMusic();
    }
    friend void callAnother(NoteBook &NoteBook1);
};
void callAnother(NoteBook &NoteBook1)
{
    NoteBook1.netChat();     // private
    NoteBook1.listenMusic(); // protected
}
void test20230621()
{
    Computer Computer1;
    NoteBook NoteBook1;
    Computer &rComputer = NoteBook1;
    Computer *pComputer = &NoteBook1;
    Computer1.playGame();
    NoteBook1.playGame();
    rComputer.playGame();
    pComputer->playGame();
    // 打印信息：当基类引用或者指针调用有默认参数的方法时，如果指向派生类，则调用的是派生类的方法，但是参数默认值是基类的
    // Computer virtual void playGame(int hours = 2) const! param hours->2
    // NoteBook void playGame(int hours = 4) const override! param hours->4
    // NoteBook void playGame(int hours = 4) const override! param hours->2
    // NoteBook void playGame(int hours = 4) const override! param hours->2

    // NoteBook1.listenMusic(); // error can not access protected method!!
    pComputer->listenMusic();
    pComputer->netChat();
    rComputer.listenMusic();
    rComputer.netChat();
    // 打印信息: 虽然基类public virtual方法被派生类重写时,改成protected或者private,但是基类指针和引用当指向派生类时，也能调用派生类此重写方法
    // NoteBook protected void listenMusic() override!
    // NoteBook private void netChat() override!
    // NoteBook protected void listenMusic() override!
    // NoteBook private void netChat() override!

    NoteBook1.programming(); // 通过public using BaseClass::xx,可改变派生类中继承自基类protected方法，改变为public

    NoteBook NoteBook2;
    NoteBook NoteBook3;
    NoteBook3.callAnotherPrivateProtectedMethod(NoteBook2);
    // 打印信息：在类方法成员中另一个实例化的对象也可以调用private protected成员,相当于同类的方法互为friend方法
    // void callAnotherPrivateNetChat(NoteBook& NoteBook1)!
    // NoteBook private void netChat() override!
    // NoteBook protected void listenMusic() override!

    callAnother(NoteBook3);
    // 打印信息：
    // NoteBook private void netChat() override!
    // NoteBook protected void listenMusic() override!
}

class Phone
{
public:
    virtual void call()
    {
        Util::LOGI("Phone virtual void call()");
    }
};
class XiaoMi : public Phone
{
};

void test20230625()
{
    XiaoMi XiaoMi1;
    Phone &Phone1 = XiaoMi1;
    Util::LOGI("typeid(Phone1)->%s,typeid(XiaoMi)->%s", typeid(Phone1).name(), typeid(XiaoMi).name());
    if (typeid(Phone1) == typeid(XiaoMi))
    {
        Util::LOGI("typeid(Phone1) == typeid(XiaoMi) is true!");
    }
    // typeid用来判断对象类型，如果是多态类型，基类至少有一个virtual方法，typeid返回的则是动态类型类型信息.
    // 需要的头文件是<typeinfo>
    // 打印信息：
    // typeid(Phone1)->6XiaoMi,typeid(XiaoMi)->6XiaoMi
    // typeid(Phone1) == typeid(XiaoMi) is true!
}

class Car
{
};
class AirPlane
{
};
class SUVCar : public Car
{
public:
    using PMethod = void (*)();
    SUVCar() = default;
    SUVCar(SUVCar &&)
    {
        Util::LOGI("SUVCar(SUVCar &&)!");
    }
    SUVCar(const SUVCar &)
    {
        Util::LOGI("SUVCar(const SUVCar&)!");
    }

    static void method()
    {
        Util::LOGI("void method()!");
    }
    operator PMethod()
    {
        Util::LOGI("operator PMethod()!");
        return method;
    }
    SUVCar &operator=(const SUVCar &) = default;
};
void test20230626()
{
    SUVCar SUVCar1;
    SUVCar SUVCar2 = SUVCar1;            // copy constructor
    SUVCar SUVCar3 = std::move(SUVCar1); // move constructor
    // 信息打印：
    // SUVCar(const SUVCar&)!
    // SUVCar(SUVCar &&)!

    const string &rStr = "12344444444";
    string &rStr1 = const_cast<string &>(rStr);
    Util::LOGI("before const string &rStr-->%s,string &rStr1-->%s", rStr.c_str(), rStr1.c_str());
    rStr1 = "3333333333333333";
    Util::LOGI("after const string &rStr-->%s,string &rStr1-->%s", rStr.c_str(), rStr1.c_str());
    // 打印信息：//const_cast；1.只能用于指针或者引用 2.不能转换为其他类型，只是去掉const限定符
    // before const string &rStr-->12344444444,string &rStr1-->12344444444
    // after const string &rStr-->3333333333333333,string &rStr1-->3333333333333333

    SUVCar::PMethod PMethod1 = SUVCar3; // 调用类型转换函数
    PMethod1();
    // 打印信息：
    // operator PMethod()!
    // void method()!

    int intNumber = 0;
    // static_cast使用基本等价于隐式转换
    // 用于低风险的转换,一般只要编译器能自己进行隐式转换的都是低风险转换，一般平等转换和提升转换都是低风险的转换
    // 等价于double doubleNumber =static_cast<double>(intNumber)(c++insight中也是这样展开的);
    double doubleNumber = intNumber;
    // 可用于派生类指针转换成基类指针，基类指针转化成子类指针
    // 下面均编译ok
    SUVCar *pSUVCar = nullptr;
    Car *pCar = nullptr;
    pSUVCar = static_cast<SUVCar *>(pCar);
    SUVCar *pSUVCar1 = nullptr;
    pCar = static_cast<Car *>(pSUVCar1);
    SUVCar SUVCar4;
    Car Car1;
    SUVCar &rSUVCar = SUVCar4;
    Car &rCar = Car1;
    rSUVCar = static_cast<SUVCar &>(rCar);
    SUVCar &rSUVCar1 = SUVCar4;
    rCar = static_cast<Car &>(rSUVCar1);
    Car1 = static_cast<Car>(SUVCar4); // ok
    // SUVCar4 = static_cast<SUVCar>(Car1); // error
    // Car1 = reinterpret_cast<Car>(SUVCar4); // error

    // 强制转换，不同类型，引用的指针转换，指针和long long之类的转换,不能不同对象之前的转换
    Car *Car2 = nullptr;
    AirPlane *AirPlane1 = nullptr;
    Car2 = reinterpret_cast<Car *>(AirPlane1);
    Car *Car3 = nullptr;
    AirPlane1 = reinterpret_cast<AirPlane *>(Car3);
    Util::LOGI("long size->%d,int size->%d,long int size->%d,long long size->%d", sizeof(long), sizeof(int), sizeof(long int), sizeof(long long));
    // 打印信息:
    // long size->4,int size->4,long int size->4,long long size->8
    long long intCar = reinterpret_cast<long long>(Car3);
}

void externalMethod(); // external link
// multiple definition of `externalMethod()'
//  void externalMethod(){
//      Util::LOGI("CplusplusStudy.cpp void externalMethod()!");
//  }
void staticExternalMethod(); // static method is internal link only same source file can access it
void anonymousNameSpaceMethod();
void test20230627()
{
    externalMethod();
    // 打印信息：// 全局方法若只有声明没有定义，则是外部链接，即在其他文件中找实现
    //  External.cpp void externalMethod()!

    // external static method is internal link only same source file can access it
    // staticExternalMethod(); //error

    // error anonymous NameSpace下的external method is also internal link the same as external static method
    // anonymousNameSpaceMethod(); //error internal link can not access it in different file
}
void tempTest()
{
    Util::LOGI("\n\n\n-----------------tempTest:20230314----------------------");
    int temp = 9;
    // int *arrayInt{new int[4]};
    int *arrayInt = &temp;
    // 其实接收的一个指针
    arrayMethod(arrayInt);

    Util::LOGI("\n-----------------tempTest:20230316----------------------");
    // PFUNCTION1 pFunc1 = function1; //both are ok!
    PFUNCTION1 pFunc1 = &function1;
    pFunc1();
    FUNCTION1 *func1 = &function1;
    func1();
    pFunc2 = function1;
    pFunc2();
    func3();
    funcTypeParamMethod(pFunc1);
    // Util::LOGI("typeid(decltype(function1)).name():%s", typeid(decltype(function1)).name());
    // Util::LOGI("typeid(decltype(&function1)).name():%s", typeid(decltype(&function1)).name());
    auto smPInt1 = unique_ptr<int, decltype(&myDeleter)>{new int(7), myDeleter};
    auto smPInt2 = shared_ptr<int>{new int(7), myDeleter};

    Util::LOGI("\n-----------------tempTest:20230330----------------------");
    Sun1 sun1;
    Sun *pSun = &sun1;
    pSun->Sun::run();
    pSun->start();

    Util::LOGI("\n-----------------tempTest:20230331----------------------");
    // thread
    std::thread::id threadId = this_thread::get_id();
    cout << "Current thread id:" << threadId << endl;
    int returnNumber = [&](int number) -> int
    {
        Util::LOGI("Lamda method! return number:%d", number);
        return number;
    }(1);
    DemuxThread demuxThread;
    demuxThread.init();
    demuxThread.start();
    // demuxThread.detach();
    demuxThread.join();

    Util::LOGI("\n-----------------tempTest:20230403----------------------");
    // safe queue
    // SafeQueue<int> safeQueue;
    // safeQueue.abort();

    Util::LOGI("\n-----------------tempTest:20230404----------------------");
    CharNumber enumChar = CharNumber::A;

    Util::LOGI("\n-----------------tempTest:20230406----------------------");
    // std::this_thread::sleep_for(std::chrono::milliseconds(8000));
    // pthread_exit(nullptr);
    Util::LOGI("temp test 1.......");
    traillingFunc();

    Util::LOGI("\n-----------------tempTest:20230407----------------------");
    Sun1::hot();
    // SUNHOT();
    int number1 = 800;
    int *pNumber2 = &number1;
    int *pNumber1 = nullptr;
    int **ppNumber1 = &pNumber1;
    *ppNumber1 = pNumber2;
    Util::LOGI("pNumber1 : %d", *pNumber1);

    Util::LOGI("\n-----------------tempTest:20230526----------------------");
    Watermelon watermelon1;
    // watermelon1 = watermelon2;

    Util::LOGI("\n-----------------tempTest:20230529----------------------");
    // 初始化列表是用来初始化的，构造函数体内是用来赋值的

    Util::LOGI("\n-----------------tempTest:20230530----------------------");
    iamFriendMethod(watermelon1);

    Util::LOGI("\n-----------------tempTest:20230531----------------------");
    // 符号优先级：（） > [](从左到右结合) > *(从右到左结合) 比如int(*a)[2]
    //()优先级高，所以代表a是一个指针，然后是[],代表这个指针指向一个数组，int表示数组的元素类型
    // 即代表a是数组指针，指向int[2]
    int array[2][2] = {0};
    int(*pArray)[2] = &array[0]; // 数组指针，&array[0]不是代表元素的双重指针，
                                 // 虽然array[0]代表的是int*,但是&array[0]不代表双重指针
    int array1[2] = {0};
    int(*pArray1)[2] = &array1;   // 数组指针
    int *pInt = new int[2];       // new 返回的都是地址，和数组声明不一样
    int **pArray2 = new int *[2]; // 所以双重指针就可以用来表示二维数组
    pArray2[0] = new int[3];
    int(*pArray3)[2] = new int[2][2]; // new int[2][2]返回的int（*）[2]而不是int* ,需要注意下！！

    Util::LOGI("\n-----------------tempTest:20230601----------------------");
    int number2 = 10;
    int number3 = 19;
    Util::LOGI("before swap:number2--->%d,number3--->%d", number2, number3);
    std::swap(number2, number3);
    Util::LOGI("after swap:number2--->%d,number3--->%d", number2, number3);
    Pear pear1, pear2;
    pear1.pInt = new int(1);
    Util::LOGI("before swap:pear1--->%p,pear2--->%p", pear1, pear2);
    std::swap(pear1, pear2);
    Util::LOGI("after swap:pear1--->%p,pear2--->%p", pear1, pear2);
    func4(2023);
    Util::LOGI("Me me1....................................");
    Me me1;

    Util::LOGI("\n-----------------tempTest:20230602----------------------");

    Util::LOGI("\n-----------------tempTest:20230605----------------------");
    int number4 = 8, number5 = 9;
    Util::LOGI("before exchange:number4->%d,number5->%d", number4, number5);
    int number6 = exchange(number4, number5); // 这个函数可以帮助更好实现move函数。
    Util::LOGI("after exchange:number4->%d,number5->%d,return value->%d", number4, number5, number6);

    Util::LOGI("\n-----------------tempTest:20230606----------------------");
    MutableStudy mutableStudy;
    mutableStudy.modify();
    test20230606();

    Util::LOGI("\n-----------------tempTest:20230607----------------------");
    test20230607();

    Util::LOGI("\n-----------------tempTest:20230608----------------------");
    test20230608();

    Util::LOGI("\n-----------------tempTest:20230609----------------------");
    test20230609();

    Util::LOGI("\n-----------------tempTest:20230612----------------------");
    test20230612();

    Util::LOGI("\n-----------------tempTest:20230613----------------------");
    test20230613();

    Util::LOGI("\n-----------------tempTest:20230614----------------------");
    test20230614();

    Util::LOGI("\n-----------------tempTest:20230616----------------------");
    test20230616();

    Util::LOGI("\n-----------------tempTest:20230619----------------------");
    test20230619();

    Util::LOGI("\n-----------------tempTest:20230620----------------------");
    test20230620();

    Util::LOGI("\n-----------------tempTest:20230621----------------------");
    test20230621();

    Util::LOGI("\n-----------------tempTest:20230625----------------------");
    test20230625();

    Util::LOGI("\n-----------------tempTest:20230626----------------------");
    test20230626();

    Util::LOGI("\n-----------------tempTest:20230627----------------------");
    test20230627();
}

class SingleTon
{
public:
    static void instance()
    {
        Util::LOGI("SingleTon instance!!");
    }
    SingleTon()
    {
    }
};

#define SingleInstace SingleTon::instance;

void func3()
{
    Util::LOGI("this is FUNCTION1 func3!!!");
    // SingleInstace();
};

void func4(int &&rInt)
{
    rInt = 9; // 此时rInt其实是个左值了
              // 右值引用和左值引用都是左值！！！
              // 右值引用可扩展右值的生命周期和用于移动语义操作
    // int *p = &std::move(rInt); //error! 右值不可以取地址
    int *pInt = &rInt;
    func5(std::move(rInt)); // move将左值转化成右值引用从而触发移动语义，
                            // 实现资源的高效转移而不进行深层的复制
                            // 被move后对象，不应该使用，因为可能造成未定义的行为
}
void func5(int &&rInt)
{
}