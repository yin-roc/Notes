[TOC]



## 1、按值传递与按引用传递、返回类型为引用和返回常规类型的区别

（1）按值传递与按引用传递的区别：

1. 按值传递（Pass by Value）：

    - 当你将参数按值传递给一个函数时，函数接收的是参数的副本，而不是参数本身。
    - 任何在函数内部对参数的修改不会影响原始参数的值。
    - 按值传递适用于基本数据类型，如整数、浮点数、字符等。
    - 通常比较简单，不容易产生副作用。

    示例（C++）：

    ```c++
    cppCopy codevoid modifyValue(int x) {
        x = 10;
    }
    
    int main() {
        int num = 5;
        modifyValue(num);
        // 此时num仍然为5，没有改变
        return 0;
    }
    ```

2. 按引用传递（Pass by Reference）：

    - 当你将参数按引用传递给一个函数时，函数接收的是参数的引用或地址，对参数的任何修改都会直接影响原始参数的值。
    - 按引用传递适用于对象、数组、结构等大型数据类型，以避免复制大量数据。
    - 它通常用于实现函数内的修改，而不仅仅是传递数据。

    示例（C++）：

    ```c++
    cppCopy codevoid modifyReference(int &x) {
        x = 10;
    }
    
    int main() {
        int num = 5;
        modifyReference(num);
        // 此时num的值已经被修改为10
        return 0;
    }
    ```

（2）关于返回类型的区别：

1. 返回类型为引用：

    - 如果函数的返回类型是引用，那么它返回的是对已经存在的变量的引用，而不是返回一个新的副本。
    - 这允许在函数外部直接修改函数返回的值。
    - 通常用于避免不必要的数据复制，提高性能。

    示例（C++）：

    ```c++
    cppCopy codeint &returnReference(int &x) {
        x = 10;
        return x;
    }
    
    int main() {
        int num = 5;
        int &result = returnReference(num);
        result = 20;
        // 此时num的值已经被修改为20
        return 0;
    }
    ```

2. 返回常规类型：

    - 如果函数的返回类型是常规类型（非引用），则它会返回一个新的副本，而不会影响原始数据。
    - 修改函数返回的值不会对原始数据产生影响。

    示例（C++）：

    ```c++
    cppCopy codeint returnValue(int x) {
        x = 10;
        return x;
    }
    
    int main() {
        int num = 5;
        int result = returnValue(num);
        result = 20;
        // 此时num仍然为5，没有改变
        return 0;
    }
    ```



## 2、函数模板

例如：交换模板

```c++
template <typename AnyType>
void Swap(AnyType &a, AnyType &b)
{
    ......
}
```

关键字template 与 typename 是必须的，除非使用关键字 class 代替 typename



## 3、模板类 vector 、模板类array和模板类valarray

1、模板类vector：

1. 单独头文件：vector

2. ```c++
    //形如：
    vector<typename> vt(n_elem);
    //参数n_elem可以是整型常量，也可以是整型变量
    
    vector<int> vi;
    //长度为0的int型数组
    
    vector<double> vd(n);
    //长度为n的double型数组
    ```

3. 可在运行阶段设置 vector 对象的长度，可在末尾添加新的数据，还可以在中间插入新数据

2、模板类array：

```c++
//形如：
array<typeName, n_elem> arr;
//与 vetor 不同的是，n_elem必须是常量
```

### vector、array和数组的区别

1. array 对象和数组存储在相同的区域中（即栈中），而 vector 对象存储在另一个区域（自由存储区或堆）中
2. vector 和 array对象除了使用数组的中括号[]索引表示方法，还可以使用其成员函数 at()，使用 at() 时，将在运行期间捕获非法索引，而程序默认将中断。而中括号索引方法即使越界，比如 a1 是 vector 对象，a1[-2]，也不会报错

3、模板类valarray

1. valarray对象可以创建长度为0的空数组、指定长度的空数组、所有元素被初始化为指定值的数组、用常规数组中的值进行初始化的数组

2. 示例：

    ```c++
    double gpa[5] = {3.1, 3.5, 3.8, 2.9, 3.3};
    valarray<double> v1;//double型0数组
    valarray<int> v2(8);//int型8元素数组
    valarray<int> v3(10,8);//int型8元素数组，每个值都赋为10
    valarray<double> v4(gpa, 4);//double型4元素数组，从数组gpa中赋值前四个元素
    valarray<int> v5 = {20, 32, 17, 9};
    ```

3. 方法

    ```c++
    operator[]():访问各个元素
    size():返回包含的元素数
    sum():返回所有元素的总和
    max():返回最大的元素
    min():返回最小的元素
    ```

    

## 4、虚函数与纯虚函数的区别

构造函数不能是虚函数；

析构函数应当是虚函数；

只有成员函数才能是虚函数，特别注意友元函数不是虚函数。

1. 定义和实现：
    - 虚函数：虚函数是在基类中声明并可以在派生类中被重新定义。它有一个默认实现，但可以被派生类覆盖。
    - 纯虚函数：纯虚函数是在基类中声明，但没有默认实现。它要求派生类提供自己的实现。
2. 使用方法：
    - 虚函数：虚函数可以有默认实现，但也可以在派生类中重写。使用虚函数时，基类中的实现提供了一种默认行为，派生类可以根据需要选择是否重写该函数。
    - 纯虚函数：纯虚函数必须在派生类中提供具体的实现，否则派生类也会成为抽象类，无法实例化。
3. 调用方式：
    - 虚函数：虚函数可以被基类指针或引用调用，并在运行时根据对象的实际类型调用相应的派生类函数。
    - 纯虚函数：纯虚函数不能被实例化，但可以通过基类指针或引用调用派生类中的实现。这样可以实现多态性，但必须确保派生类提供了具体实现。
4. 作用：
    - 虚函数：虚函数用于实现运行时多态性，允许不同派生类对象以相同的接口调用函数，但根据对象的实际类型执行不同的操作。
    - 纯虚函数：纯虚函数用于定义接口规范，强制派生类提供自己的实现，以确保派生类能够满足特定的接口要求。

在C++中，定义纯虚函数的语法是在函数声明后加上"= 0"，例如：

```c++
class Base {
public:
    virtual void virtualFunction() {
        // 可选的默认实现
    }
    
    virtual void pureVirtualFunction() = 0; // 纯虚函数
};
```

