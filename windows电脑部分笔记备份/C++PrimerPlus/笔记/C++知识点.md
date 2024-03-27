[TOC]

## 1、构造结构体完毕时，需要在大括号后面加上分号。

## 2、指针指向变量前，一定要给指针赋初值。

## 3、用一个指向数组的指针，输出数组元素的值，可以是：

```c++
int arr[10] = {0};
int * pt = arr;
//-------means 1-----//
cout << *pt << " " << *(pt + 9) << endl;
//-------means 2-----//
cout << pt[0] << " " << pt[9] << endl;
```



## 4、结构体中定义了一个数组，用指针赋值时不能直接赋予字符串的值，会导致报错。

​	需要使用strcpy函数或者C++中的string
​	比如：
​	//以下结果会报错
​	15.cpp:15:13: error: incompatible types in assignment of ‘const char [11]’ to ‘char [20]’
​		ps->kind = "==goldenfish==";
​	strncpy(ps->kind, "goldenfish", sizeof(ps->kind));

```c++
 #include <iostream>
  
int main()
{
     using namespace std; 
     struct fish
     {
         char kind[20];
         int weight;
         double length;
     };
      fish * ps = new fish;
     ps->kind = "goldenfish";
     ps->weight = 1;
     ps->length = 1.2;
    
     cout << (*ps).kind << endl;
     delete ps;
 
     return 0;
}
```


## 5、在指定结构成员时，搞不清楚何时应使用句点运算符，何时应使用箭头运算符，规则如下：

​	如果结构标识符是结构名，则使用句点运算符；
​	如果结构标识符是指向结构的指针，则使用箭头运算符。

## 6、getline用法

​	exp1:数组

```c++
int data[20];
cin.getline(data，20);
```

​	exp2:
​		结构体
​		1、new动态分配内存

```c++
struct struction 
{
	char name [20];
};
struction *pt = new struction;
cin.getline(pt->name, 20);
```

​		exp 3：	用string类，而非数组

```c++
	#include <string>
	string str1;
	getline(cin,str1);
```

## 7、在代码编写中，常量可以用常变量代替更为高效。

​	比如：

```c++
		const int size = 20; 
		char arr[size] = {0};
```

​	比

```c++
char arr[20];
```

​	更加便于代码管理。

## 8、strcpy函数

```c++
char *strcpy(char *dest, const char *src)
```

​	将src字符串内容复制到dest字符串中

## 9、strcat函数

```c++
char *strcat(char *dest, const char *src)
```

​	参数
​	dest -- 指向目标数组，该数组包含了一个 C 字符串，且足够容纳追加后的字符串。
​	src -- 指向要追加的字符串，该字符串不会覆盖目标字符串。
​	返回值
​	该函数返回一个指向最终的目标字符串 dest 的指针。
​	--->简单来说，给dest追加一个src指向的内容。

## 10、new一定要与delete配合使用！！！

​	若是int * pt = new int [3]，则delete [] pt

## 11、数组元素是结构体与数组元素是结构体指针的区别：

​	exp：
​	struct Pizza 
​	{
​		char name[20];
​		float diameter;
​		float weight;
​	}
​	

```c++
Pizza * pt = new Pizza [3];
strcpyp(pt[0].name,"hello world");
strcpyp((pt+1)->name,"hello world");

//变量pt被声明为一个Pizza结构体数组，而不是一个指向单个Pizza结构体的指针。
//因此，您需要使用数组索引语法pt[index]来访问数组中的每个单独元素
//指针访问结构体成员的标准方式是使用箭头运算符->，而数组访问结构体成员的方式是使用点运算符.
//pt指向的是数组，而非结构体，故用.
//pt是指向数组第一个元素的指针，(pt+1)是指向数组第二个元素的指针，而非指向结构体
```

## 12、字符串常量不能直接进行赋值，需要使用strcpy函数

## 13、for(int i = 0;i < 5; i++)//该变量i只在for循环语句中生效

## 14、string类的size()可以获得字符串中的字符数；

​	string对象定义的一个变量可以当成一个数组来使用。
​	exp:
​		string str1;
​		cin >> str1;
​		//str1的长度为：str1.size()
​		

	str1[i]:
	//可以打印出字符串的第i个字符

## 15、运算符优先级（*与前缀++、后缀++）

​	1）* 优先级等于 前缀++和前缀--； 但都低于后缀++和后缀--。
​	exp1：
​			*++pt：指针先加1，再进行解应用。
​		

​	exp2：
​		++*pt：先取得pt指向的值，然后将这个值加1。
​	
​	exp3:
​		(*pt)++:首先对指针进行解引用，再将这个值进行递增加1。
​	
​	exp4：
​		*pt++：后缀运算符的优先级更高。所以先用于pt指针，再进行解应用。
​		但此处后缀++是先对当前值进行操作再进行加1.（因为后缀++是先用，再加1）
​		即：先用完pt指针，再去调整其位置。
​		先解引用，再将指针所指的地址加1。

​	2）关系运算符的优先级比算术优先级低
​		<,<=,>,>=,==,!=

## 16、strcmp()函数

```c++
	int strcmp(const char *str1, const char *str2)
```

​	参数
​	str1 -- 要进行比较的第一个字符串。
​	str2 -- 要进行比较的第二个字符串。
​	返回值
​	该函数返回值如下：

	如果返回值小于 0，则表示 str1 小于 str2。
	如果返回值大于 0，则表示 str1 大于 str2。
	如果返回值等于 0，则表示 str1 等于 str2。
	
	按照排列顺序(ASCII码)，大写字母将位于小写字母之前。

## 17、将一个字符串赋给数组，记得要留一个数组元素位置给"\0"。

## 18、string word = "?ate";中的word可以看作数组名。

​	word可以看作是一个字符数组的名称。
​	在某些编程语言中，字符串就是字符数组，因此它们可以被看作字符数组的名称。
​	每一个字符串都是由许多字符组成的，并且字符串的第一个字符的位置是从0开始的。
​	因此，如果存在字符串 "?ate"，那么它可以看作是字符数组。
​	

## 19、for与while

​	知道循环次数-------->for
​	不知道循环次数------>while
​	

## 20、clock()函数和clock_t数据类型

​	clock() 函数是 C 编程语言中的标准库函数，它返回自程序启动以来所经过的时钟滴答数。
​	它可以用来测量代码段执行所需的时间。

	clock_t 是一种数据类型，它代表时钟滴答数。
	我们定义了两个 clock_t 类型的变量 start_time 和 end_time，用来存储代码执行的起始时间和结束时间。
	它们一起使用，可以确定代码执行所需的实际时间：
	double total_time = (double)(end_time - start_time) /CLOCKS_PER_SEC;
	请注意，clock() 的返回值是平台相关的，可能不等于实际的墙上时钟时间。
	在某些平台上，当达到特定的最大值时，值可能会回绕。
	您应该始终将 clock() 与 CLOCKS_PER_SEC 一起使用以确定秒为单位的实际经过时间。

## 21、C++建立别名的两种方式：

​	1)使用预处理器：

```c++
#define BYTE char
```

​		BYTE成为char的别名
​	2)用关键字typedef来创建别名：

```c++
typedef typename aliasName;
```

​		exp: 

```c++
typedef char * byte_pointer;
```

​		#define 的缺陷：声明一系列变量时，这种方法不适用。

​		exp：

```c++
	#define FLOAT_POINTER float *
	FLOAT_POINTER pa,pb;
	预处理器置换该声明为：
	float *pa, pb;//与原先想法不一样。
```

## 22、cin、cin.get()、while(cin)

​	1)cin 读取时是否会省略空格与读取的数据类型无关。
​		cin 默认读取输入的字符流直到遇到空格、换行符或到达文件结尾，将读取到的字符转换为指定类型并存储在指定的变量中。
​		因此，不论您读取的是什么类型，都会自动忽略空格。
​	

2)关于cin.get(ch)可能出现的歧义：
	当使用 cin.get(ch) 读取一个字符到变量 ch 时，此操作会修改该变量的值。
	具体来说，cin.get(ch) 将读取输入流中的下一个字符，并将该字符存储到变量 ch 中。
	如果读取成功，则 cin.get(ch) 返回 cin 的引用；如果读取失败，则返回一个空的 istream 对象。
	因此，当您使用 cin.get(ch) 读取一个字符时，如果读取成功，则变量 ch 的值将更改为读取到的字符。
	请注意，与 cin 相比，cin.get(ch) 可读取空格字符和换行符，并且不会忽略读取到的任何字符，
	因此如果需要读取带有空格的字符串，则通常使用 cin.get(ch) 而不是 cin。

3)c语言函数中的参数默认是通过值传递的，这意味着在函数内部对参数的任何更改都不会影响到原始变量。
	可以用指针变量作为形参来解决这个问题。

4)cin 的函数重载
	在c语言中，如果函数接受char指针和int参数，则使用该函数时，不能只传递一个函数。
	但在C++中，允许使用函数重载创建多个同名函数，条件是它们的参数列表不同。
	在 C++ 中，cin.get(name, ArSize)，cin.get(ch) 和 cin.get() 有以下区别：
		cin.get(name, ArSize)：它读取输入流中的整个字符串，直到遇到换行符或缓冲区的大小达到了 ArSize-1，
	将读取到的字符串存储在 name 中。
	cin.get(ch)：它读取输入流中的单个字符，并将其存储在 ch 中。
	cin.get()：它读取输入流中的单个字符，并返回该字符的值。
	因此，如果需要读取整个字符串，则使用 cin.get(name, ArSize)；
	如果需要读取单个字符，则使用 cin.get(ch) 或 cin.get()。

5)==while(cin)==

`while(cin)` 用于检测输入流是否还有可用的数据。

如果输入流还有可用数据，则表达式 `cin` 的值为 `true`，否则为 `false`。

因此，当用户输入一个空行时，`cin.get(input, ArSize);` 读取到空字符串，这会使 `cin` 变为 `false`，从而导致循环退出。

## 23、"\t"可以将不对齐的几行，设置到下一个制表位重新对齐开始。

## 24、C++中各运算符的优先级是从高到低排列如下：

	1）一元运算符 (例如 ++, --, !, &, * 等)
	2）关系运算符 (例如 <, >, <=, >=, ==, !=)
	3）逻辑运算符 (例如 &&, ||)
	4）三目运算符 (例如 a ? b : c)
	5）赋值运算符 (例如 =, +=, -=, *=, /=, %= 等)
	6）逗号运算符 (例如 a, b)

## 25、"\a" 在代码中的作用是发出警报音，通常用于提醒程序运行中的某个特定事件或状态。

## 26、cctype函数是C/C++标准库中的一个函数集合，用于对字符进行分类和转换。

​	以下是cctype函数的一些常见函数：

	isalpha(char)：判断字符是否为字母（a-z或A-Z）。
	isdigit(char)：判断字符是否为数字（0-9）。
	isalnum(char)：判断字符是否为字母或数字。
	isblank(char)：判断字符是否为空格或制表符。
	isspace(char)：判断字符是否为空格、制表符、换行符、回车符、换页符或垂直制表符。
	islower(char)：判断字符是否为小写字母（a-z）。
	isupper(char)：判断字符是否为大写字母（A-Z）。
	isprint(char)：判断字符是否为可打印字符，即ASCII码值在32-126之间。
	ispunct(char)：判断字符是否为标点符号（不包括空格字符）。
	tolower(char)：将大写字母转换为小写字母。
	toupper(char)：将小写字母转换为大写字母。
	这些函数都需要传入一个字符作为参数，并返回一个非零值表示满足条件，返回零表示不满足条件。
	另外，这些函数只对ASCII字符集有效，对于非ASCII字符集可能会得到不准确的结果

## 27、如果避免输入错误时，导致的系统崩溃。

​	#include <iostream>

```c++
using namespace std;

//当输入不是数字时，发生了类型不匹配
int main(void)
{
	int num1, num2;
	cout << "First number: ";
	cin >> num1;

	//改进2:重置错误标记，恢复cin的功能
	cin.clear();
```


```c++
	//改进1；避免对num1输入xyz，直接跳过num2输入的情况
	while(cin.get() != '\n');  
	//但仅仅只有改进1，会导致系统进入死循环，不能够给后续的num2赋值
	//原因在于第一个cin>>num1输入错误时会产生一个错误的标记，导致cin捕获字符的功能被禁用
	//故陷入死循环。
```


```c++
	cout << "Last number: ";
	cin >> num2;

	cout << "num1 = " << num1 << ", num2 = " << num2 << endl;

	return 0;
}
```

## 28、while(cin.get() != '\n') continue; 和 while(cin.get() != '\n'); 的区别

​			区别：在于分号的有无。虽然这个区别非常微小，但却十分重要。

	在第一个语句中，分号位于 continue 语句之前，表示 while 循环体是一个单独的语句，
	该语句每次循环时会执行 continue 语句，并立即进入下一次循环。这种写法可以用于清空输入缓冲区中的残留字符。
	
	而在第二个语句中，分号位于 while 条件语句的末尾，表示 while 循环体是一个空语句，
	即每次循环时不执行任何语句。这种写法可能会导致程序陷入死循环，因为条件表达式一直为真，而循环体没有任何执行语句。
	因此，为了避免程序陷入死循环，应该使用带有 continue 语句的第一种写法，而不是只有条件表达式的第二种写法。

## 29、inFile

​	

```c++
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
const int SIZE = 60;
int main()
{
	char filename[SIZE];
	//1、输入文件，读取内容
	ifstream inFile;
	cout << "Enter name of data file: ";
	cin.getline(filename, SIZE);
	
	//2、打开一个名为filename的文件，并建立其与输入流对象之间的关系
	inFile.open(filename);

	//3、判断是否成功打开
	//如果成功打开返回true；否则返回false
	if(!inFile.is_open())
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		
		//"exit(EXIT_FAILURE);" 则是一个代码行，它通常出现在程序中表示程序出现错误时需要结束运行并返回错误代码。
		//在这里，"EXIT_FAILURE" 是一个预定义的宏，它表示程序的退出状态，
		// 用于表明程序在运行过程中遇到了错误或异常情况，退出时返回一个非零值。
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0;
	int count = 0;

	//4、输入一个值，类比于cin>>value
	inFile >> value;
	
	//5、表示在 inFile 流对象读取数据的过程中，只要流对象没有遇到任何错误，就会继续循环。
	//这个循环可以用来读取文件中的所有数据，直到文件结束或者出现错误为止。
	//所以，在读取文件时，通常需要在循环内部加入读取数据的语句，并在读取完成后检查是否已经到达文件结尾。
	while(inFile.good())
	{
		++count;
		sum += value;
		inFile >> value;
	}

	//6、
	//在C++中，eof()是一个istream类的成员函数，用于检测流的结束标志。
	// 当文件读取到末尾时，文件指针会指向文件结束符，eof()函数会返回true，表示已经到达了文件的末尾。
	// 因此，当出现 if(inFile.eof()) 时，表示程序读取文件时已经到达文件末尾。
	// 这通常被用于文件读取循环中的判断条件，以确保在读取完整个文件后退出循环。但需要注意的是，eof()函数的返回值并不一定可靠，因为有时候文件结束符可能会被错误地处理或忽略掉。因此，有些情况下可能需要采用其他的方法来判断文件是否已经结束
	if(inFile.eof())
		cout << "End of file reached.\n";
	else if(inFile.fail())
		cout << "Input terminated by data mismatch.\n";
	else 
		cout << "Input terminated for unknown reason.\n";
	if(0 == count)
		cout << "No data processed.\n";
	else
	{
		cout << "Items read: " << count << endl;
		cout << "Sum: " << sum << endl;
		cout << "Average: " << sum / count << endl;
	}
	
	//关闭文件
	inFile.close();
	return 0;
}
```

## 30、outFile

​	//写入到文本文件


```c++
//1、头文件的引用
#include <fstream>
//2、创建一个ofstream对象
ofstream outFile;

//3、将该ofstream对象同一个文件关联起来
outFile.open("carinfo.txt");

//4、像使用cout那样使用ofstream对象
outFile << "hello world";

//5、关闭 
outFile.close();
```

## 31、cout << fixed

```c++
cout << fixed;//以小数形式显示，不使用科学计数法
cout.precision(2);//精度，小数点后两位

cout.setf(ios_base::showpoint);//一定要显示小数点后两位，即使是整数。exp：0->0.00
```

## 32、inFile

```c++
//读取文本文件
//1、头文件引用
#include <fstream>
//2、创建一个ifstream对象
ifstream inFile;

//3、将该ifstream对象同一个文件关联起来
inFile.open(filename);

//4、判断是否成功打开文件,成功打开inFile.is_open()返回true
if(!inFile.is_open())
{
	//提示发生错误
	cout << "Could not open the file " << filename << endl;
	cout << "Program terminating.\n";
	
	exit(EXIT_FAILURE);//包含在头文件cstdlib，退出程序
}

//5、读取值
inFile >> value;

//6、输入流是否处于良好状态，也就是是否可以继续读取数据（也就是没有到达文件末尾）
while(inFile.good())
{
	...
	...
	inFile >> value;
}

//7、判断是否到达文件末尾 
if(inFile.eof())
	cout << "End of file reached.\n";
else if(inFile.fail())//返回true，则代表读取失败
	cout << "Input terminated by data mismatch.\n";
else
	cout << "Input terminated for unknown reason.\n";
```

## 33、ch是小写字母或大写字母，直接定义char型变量，写成'a','Z',不需要转化成65-90，97-122

## 34、当输入不是数字，而是其他字符时，容易发生类型不匹配

```c++
int choice;
cin >>  choice;
switch(choice)
//当输入不是数字，而是其他字符时，容易发生类型不匹配
//而换成
char choice;
//可以避免这种错误，但switch里面的case 1就要换成case '1'
```

## 35、toupper和tolower

​	toupper：将小写字母转换成大写
​	tolower：将大写字母转换成小写

## 36、程序遇到非数字输入时将结束输入

```c++
	//程序遇到非数字输入时将结束输入
	while(cin >> num)
	// int num
```

## 37、对于程序开头有大量提示信息，可以使用showmeun()来包含提示部分

​	//对于程序开头有大量提示信息，可以使用showmeun()来包含提示部分
​	// \t可以用来对位
​	

## 38、如果结构体定义的全局变量，那么函数内部可以直接使用，不需要传参。

## 39、cin >> word;

```c++
	cin >> word;
	//碰到空格视为结束
	//故可以使用此方法一次读取一个单词
```

## 40、	const int *pt; // == int const *pt;

```c++
const int *pt; // == int const *pt;
//可以修改pt指针的指向，但不能通过指针修改其所指向的值
```

```c++
int * const pt;
//可以通过pt指针修改其指向的值，pt指针指向这一个变量，不能指向其他对象

//看const修饰在 *前还是 *后
// const *pt 代表 *pt不可变
// * const pt 代表 pt不可变
```

## 41、禁止将const地址赋给非const指针

```c++
//禁止将const地址赋给非const指针
//一级间接关系，将非const指针赋给const指针是可以的
//二级间接关系，与一级间接关系一样将const和非const混合的指针赋值方式将不再安全
```

​	

## 42、while(ch)
```c++
//当ch=0时退出循环，注意事项
```

```c++
while(ch)
//当ch=0时退出循环，需要注意的是，当ch为char型，"\0"的ASCII码值等于0，故循环也会退出
```

​	

## 43、char * wail = "ululate";发生警告

```
	warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
     char *wail = "ululate";
```

```c++
//原因：在 C++ 中，字符串常量是以只读存储区的方式存储的，因此将其赋值给一个非 const 修饰的指针会导致潜在的内存错误。
//如果程序试图修改这个指针指向的字符串常量，就会发生未定义的行为。

//修改如下：
const char * wail = "ululate";
```

## 44、函数返回结构与返回数组的区别：

```c++
//函数可以返回结构。与数组名就是数组第一个元素的地址不同的是，
//结构名只是结构的名称，要获得结构的地址，必须使用地址运算符&
```



## 45、引用

### 按引用传递：直接操作实参，而非副本

### 引用应该是对一个变量的引用，所以实参应该是一个变量，下面的代码不合理：

```c++
double refcube(double a);
double z = refcube(x + 3.0);
```

如果实参与引用参数不匹配，C++将生成临时变量。

当前，仅当参数为const引用时，C++才允许这样做。

如果引用参数时const，则编译器将在下面两种情况下生成临时变量：

- 实参的类型正确，但不是左值；

- 实参的类型不正确，但可以转化为正确的类型。

    左值就是可以被引用的数据对象，例如：变量、数组元素、结构成员、引用和解除引用的指针都是左值

    非左值包括字面常量（用引号括起的字符串除外，他们由地址表示）

==但也有例外：==

比如：字符串"****"

我们知道，引用一般是对变量的引用，但是这里却是一个字符串常量，我们可以使用const string &s1，这里const必将其存放于临时变量，再进行引用。

那么这里的疑问：==程序怎么能接受将char指针赋给string引用呢？==（C++PrimerPlus的P222页）

两点原因：

1. string类定义了一种从char * 到string的转换功能，这使得可以使用C-风格字符串来初始化string 对象
2. 其次则是const引用的形参的一个属性。

### 引用必须在声明引用就进行初始化，而不能像指针那样，先声明，再赋值

```c++
int rat;
int & rodent;
rodent = rat;//err,No, you can't do this.
```

实际上：

```c++
int & rodents = rats;
```

是下列代码的伪装表示：

```c++
int * const pr = &rats;
```

这里的指针pr被const修饰，也就是说：不能改变其所指的对象，但可以改变对象的值。

### 将引用参数声明为常量数据的引用的理由有三个：

#### 使用 const 可以避免无意中修改数据的编程错误：

```c++
//理由1：使用 const 可以避免无意中修改数据的编程错误 
#include <iostream>
using namespace std;
double cube(double);
double refcube(double &ra);
int main()
{
    double x = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);
    cout << " = cube of " << x << endl;
    return 0;
}

double cube(double a)
{
    a *= a * a;
    return a;
}

double refcube(double &ra)
{
    ra *= ra * ra;
    return ra;
}
```

结果如图：

![45-4.1](E:\2笔记\C++PrimerPlus\笔记\C++遇到的问题其中的图片\45-4.1.png)



不难发现，x被修改了；

然而使用const可以避免这一情况：

```c++
double refcube(const double &ra)//比上一函数多加了const
{
    ra *= ra * ra;
    return ra;
}
```

则系统自动提示：

```
使用const理由1.cpp: In function 'double refcube(const double&)':
使用const理由1.cpp:29:16: error: assignment of read-only reference 'ra'
     ra *= ra * ra;
```

#### 使用const使函数能够处理const和非const实参，否则将只能接受非const数据

##### 函数的形参为const引用，传入了非const数据y:

```c++
//理由2：使用const使函数能够处理const和非const实参，否则将只能接受非const数据 

#include <iostream>

using namespace std;

double cube(double);
double refcube(const double &ra);

int main()
{
    double x = 3.0;
    double y = 5.0;
    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(y);//变化点
    cout << " = cube of " << y << endl;
    return 0;
}

double cube(double a)
{
    a *= a * a;
    return a;
}

double refcube(const double &ra)//关注点
{
    return ra * ra * ra;
}
```

结果如图所示：

![45-4.2](E:\2笔记\C++PrimerPlus\笔记\C++遇到的问题其中的图片\45-4.2.png)



##### 函数的形参为const引用，传入了const数据y:

```c++
//理由2：使用const使函数能够处理const和非const实参，否则将只能接受非const数据 

#include <iostream>

using namespace std;

double cube(double);
double refcube(const double &ra);

int main()
{
    double x = 3.0;
    const double y = 5.0;
    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(y);//变化点，传入了const参数
    cout << " = cube of " << y << endl;
    return 0;
}

double cube(double a)
{
    a *= a * a;
    return a;
}

double refcube(const double &ra)
{
    return ra * ra * ra;
}
```

结果如图所示：

![45-4.2.2](E:\2笔记\C++PrimerPlus\笔记\C++遇到的问题其中的图片\45-4.2.2.png)

##### 函数的形参为非const引用，传入了const数据y:

```c++
//理由2：使用const使函数能够处理const和非const实参，否则将只能接受非const数据 

#include <iostream>

using namespace std;

double cube(double);
double refcube(const double &ra);

int main()
{
    double x = 3.0;
    const double y = 5.0;//关注点
    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(y);
    cout << " = cube of " << y << endl;
    return 0;
}

double cube(double a)
{
    a *= a * a;
    return a;
}

double refcube(double &ra)//关注点
{
    return ra * ra * ra;
}
```

结果报错如下：

```
C:\Users\yin\AppData\Local\Temp\ccrXSzAm.o: In function `main':
E:\code\C++\chapter8\exp/使用const理由1.cpp:16: undefined reference to `refcube(double const&)'
collect2.exe: error: ld returned 1 exit status
```

#### 使用const引用使函数能够正确生成并使用临时变量

```c++
//理由3：使用const引用使函数能够正确生成并使用临时变量 

#include <iostream>

using namespace std;

double cube(double);
double refcube(const double &ra);

int main()
{
    double x = 3.0;
    // const double y = 5.0;
    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(7.0);//变化点
    cout << " = cube of " << 7.0 << endl;
    return 0;
}

double cube(double a)
{
    a *= a * a;
    return a;
}

double refcube(const double &ra)//关注点
{
    return ra * ra * ra;
}
```

结果如图：

![45-4.3](E:\2笔记\C++PrimerPlus\笔记\C++遇到的问题其中的图片\45-4.3.png)

示例2：

```c++
//理由3：使用const引用使函数能够正确生成并使用临时变量 

#include <iostream>

using namespace std;

double cube(double);
double refcube(const double &ra);

int main()
{
    double x = 3.0;
    const double y = 5.0;
    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(7.0 + y);//变化点
    cout << " = cube of " << 7.0 + y << endl;
    return 0;
}

double cube(double a)
{
    a *= a * a;
    return a;
}

double refcube(const double &ra)//关注点
{
    return ra * ra * ra;
}
```

结果如下：能够正常运行

![45-4.4](E:\2笔记\C++PrimerPlus\笔记\C++遇到的问题其中的图片\45-4.4.png)

## 46、如果在函数内部使用new开辟了动态存储，那么函数调用结束后，还能够访问动态分配的值吗

​		  一般情况下，在函数内部使用`new`开辟动态存储，函数调用结束后，动态分配的内存空间仍然存在，但是对于该内存空间的访问取决于所分配的内存的作用域和所有权。

如果在函数内部动态分配的内存是通过返回指针或引用的方式返回到函数外部，那么在函数调用结束后，该内存空间仍然存在并且可以被访问。

​          但是如果在函数内部动态分配的内存是存储在函数内部的局部变量中，并且没有被返回到函数外部，那么在函数调用结束后，该内存空间将被释放，并且任何尝试访问该内存空间的行为都将导致未定义的行为。因此，在函数内部使用`new`动态分配内存时，必须确保所分配的内存的作用域和所有权符合程序逻辑和需求。

## 47、空格、空字符和字符0的区别

空格：		空格键产生的字符，[ASCII码](https://so.csdn.net/so/search?q=ascii码&spm=1001.2101.3001.7020)十进制：32

空字符：字符串结束标志‘\0’，为被动添加，ascii码十进制：0

字符0：	ascii码十进制：48

## 48、char * arr[]  与  char * arr

首先，char *arr[]表示一个指向字符型指针的数组，也可以写成==char **arr==，而char * arr则表示一个指向字符型数据的指针类型。如果将char *arr[]作为参数传递给函数，则在函数内部使用该参数时需要使用下标操作符（[]）来访问其中的元素，例如arr[0]、arr[1]等。

而如果将char * arr作为参数传递给函数，则在函数内部使用该参数时不需要使用下标操作符。因为在C语言中，数组名作为函数参数时会自动转换为指向数组首元素的指针类型。因此，可以直接使用arr来访问数组中的元素，例如arr[0]、arr[1]等。

需要注意的是，在这种情况下，虽然char *arr[]和char * arr的语法不同，但它们在指向数组的特性上是相同的。因为数组名本身就是一个指向数组首元素的指针。

char * arr[4]表示这是一个指针数组，一共有四个元素，每个元素都是char * []型

## 49、隐式实例化、显式实例化和显式具体化的区别

隐式实例化：在程序中使用模板时，编译器会自动将模板实例化为相应的代码，这个过程被称为隐式实例化。例如：

```c++
template<typename T>
void foo(T t) {
  // ...
}

int main() {
  foo(123);  // 隐式实例化为 foo<int>(123);
  return 0;
}
```

这里的 `foo` 是一个函数模板，调用 `foo(123)` 会隐式实例化为 `foo<int>(123)`，即将 `T` 替换为 `int` 后实例化生成的函数。

显式实例化：在某些情况下，我们希望在编译时不仅实例化模板，还生成并存储它的代码，以便后续的使用，这个过程被称为显式实例化。显式实例化可以使用 `template class` 或 `template struct` 关键字进行声明，例如：

```c++
template<typename T>
void foo(T t) {
  // ...
}

template void foo<int>(int t);  // 显式实例化为 foo<int>(int t);
```

这里的 `foo` 是一个函数模板，使用 `template void foo<int>(int t);` 进行显式实例化会生成代码，并存储在目标文件中。

显式具体化：在某些情况下，我们希望特化部分模板中的某些类型，以便更好地满足程序的需求，这个过程被称为显式具体化。或者当函数重载模板无法定义某种重载函数时，用显式具体化来对特定的数据类型作特殊处理。显式具体化可以使用 `template <>` 关键字进行定义，例如：

```c++
template<typename T>
void foo(T t) {
  // ...
}

template <>
void foo<int>(int t) {
  // ...
}
```

这里的 `foo` 是一个函数模板，使用 `template <>` 进行显式具体化会生成针对特定类型 `int` 的代码实现。

在代码中，我们可以通过关键字来区分隐式实例化、显式实例化和显式具体化。此外，它们的使用场景也不同：隐式实例化自动完成，显式实例化用于显式声明并生成代码，显式具体化用于特化模板以满足特定需求。举例如下：

```c++
#include <iostream>

template<typename T>
void foo(T t) {
  std::cout << "foo(T t)" << std::endl;
}

template void foo<int>(int t);//显示实例化

template<>
void foo<const char *>(const char *t) {
  std::cout << "foo<const char *>(const char *t)" << std::endl;
}

int main() {
  foo(123);           // 隐式实例化为 foo<int>(123);
  foo("hello world"); // 显式具体化为 foo<const char *>("hello world");
  return 0;
}
```

这里的 `foo` 函数模板同时进行了隐式实例化、显式实例化和显式具体化，通过输出来区分不同的调用。

总结：

具体化：vip通道

显式实例化：不论调不调用，先生成定义。（给熟人留位置）

## 50、static静态变量

```c++
static int num
```

声明了一个静态变量 `num`，它的类型是整型（int）。

1. 静态变量被分配在程序的数据区，==它们只会被初始化一次==，即在程序运行期间保持不变。
2. 在函数中声明的静态变量可以在函数调用之间维持其值。相反，未使用 static 关键字声明的变量是自动变量，并被存储在堆栈中，当函数调用结束时，它们将被销毁。因此，在上下文中，`static int num` 表示该变量是一个静态变量，==它将在整个程序的执行期间保持存在，并且在函数调用之间保持其值==
3. ==它可以在该函数中被修改。==

## 51、使用new创建动态内存分配的新方法

```c++
type_name *pointer_name = new type_name[size];
```

其中，type_name是分配内存空间的类型，pointer_name是指向分配的内存空间的指针，size是要分配的内存空间的大小。

```c++
sty.str = new char[sty.ct];
```

对于这段代码中的 `sty.str = new char[sty.ct];` ，它分配了一个大小为 `sty.ct` 的字符数组，并将数组的首地址赋值给 `sty.str`。这里的 `new char[sty.ct]` 分配了一块 `sty.ct` 个字符大小的连续内存空间，并返回该空间的首地址，类型为 `char*`，所以需要使用 `char*` 类型的指针来接收它。

exp：

```c++
void set(stringy & sty, char *st)
{
    sty.ct = strlen(st);
    sty.str = new char[sty.ct];
    strcpy(sty.str, st);
}
```

sty是一个结构体变量，里面有两个成员：ct和str；通过strlen()函数得出字符串的长度，并使用new开辟动态内存分配给字符串(字符串长度为sty.ct)

## 52、字符串常量赋值给char *数组触发警告

报错可以使用string代替char*数组

如果涉及到计算字符串的长度，char*型的数组可以使用：strlen

string类型可以使用：

```c++
string str[] = {"hello", "world", "Typora"};
str[i].size();
```

## 53、左值和右值概念辨析

### 左值

左值是可以放在赋值运算符左边的表达式，它们具有持久的存储位置，可以在内存中寻址，因此可以修改其值。一般来说，左值指代的是==变量==或者==对象==，但也可能是==数组==或==结构体==等==可以修改其内部值的表达式==。比如：

```c++
int a = 10;
int b = a; // a是左值
int* p = &a; // a是左值
```

### 右值

右值则是指==那些不可以放在赋值运算符左边的表达式==，它们不具有持久的存储位置，不能在内存中寻址，因此不能修改其值。一般来说，右值指代的是==字面量==、==临时对象==或者==表达式结果==等无法修改的值。比如：

```c++
int c = 5 + 3; // 5+3是右值
int* q = &c + 1; // &c是左值，&c+1是右值
```

需要注意的是，有些表达式既可以作为左值，也可以作为右值，例如数组名和函数名：

```C++
int arr[10];
int& x = arr[0]; // arr[0]是左值
int (*pf)() = main; // main是右值
```

### 区别

1. 左值可以取地址，右值不可以取地址

2. ```c++
    int &c = a;
    ```

    左值引用，赋值运算符的左侧一定要是一个左值。

    但

    ```c++
    const int &d = 10;
    const int &d = (a + b);
    ```

    却可以，原因是这两者因为const修饰，所以是一个常引用，==原则上不行，但与临时变量产生了关系==，故而可以通过编译。

3. 开创了右值引用标准

    ```c++
    int && x = 10;
    int && y = (a + b);
    ```

## 54、何时使用引用，何时使用指针？

对于使用传递的值而不作修改的函数：

1. 如果数据对象很小，如内置数据类型或小型结构，则按值传递
2. 如果数据对象是数组，则使用指针，因为这是唯一的选择，并将指针声明为指向const的指针
3. 如果数据对象是较大的结构，则使用const指针或const引用
4. 如果数据对象是类对象，则使用const引用

对于修改调用函数中数据的函数：

1. 如果数据对象是内置数据类型，则使用指针
2. 如果数据对象是数组，则==只==能使用指针
3. 如果数据对象是结构，则使用引用或者指针
4. 如果数据对象是类对象，则使用引用

## 55、默认参数

对于带参数列表的函数，必须从右向左添加默认值。也就是说，如果要为某个参数设置默认值，则必须为它右边的所有参数提供默认值。

## 56、decltype关键字

### 创建其的根本原因：

```c++
template<class T1, class T2>
void f1(T1 x, T2 y)
{
	...
	?type? xpy = x + y;
	...
}
```

这里面的T1和T2类型不一样，如果T1为short，T2为int，两者相加后，xpy类型为int；如果T1为int，T2为double，两者相加后，xpy类型为double。

故不能够声明xpy的类型。因此引入了decltype关键字。

​		  关键字`decltype`是C++11中引入的，用于推断表达式的类型并返回其类型。`decltype`关键字接受一个表达式作为参数，可以推断出该表达式的类型，而不需要实际计算该表达式。`decltype`通常用于模板元编程、泛型编程和一些需要类型推导的场景。

例如，假设有一个函数`foo`，它接受一个整数参数`x`，并返回`x`与`1`的和，可以使用`decltype`推断出`foo`函数的返回类型：

```C++
int foo(int x) {
    return x + 1;
}

int main() {
    int a = 1;
    decltype(foo(a)) b = foo(a); // 推导出 b 的类型为 int
    return 0;
}

```

上面的例子中，`decltype(foo(a))`推导出`foo(a)`的返回类型为`int`，因此变量`b`的类型为`int`。

### 以下是 `decltype` 关键字的用法和示例：

| 用法                    | 示例                                     | 描述                                                         |
| ----------------------- | ---------------------------------------- | ------------------------------------------------------------ |
| 1. 推导变量类型         | `decltype(variable) name;`               | 根据变量 `variable` 的类型，推导出变量 `name` 的类型。       |
| 2. 推导表达式类型       | `decltype(expression)`                   | 根据表达式 `expression` 的类型，推导出表达式的类型。         |
| 3. 推导返回值类型       | `decltype(function(args))`               | 根据函数调用的返回值类型，推导出函数的返回值类型。           |
| 4. 推导Lambda表达式类型 | `[](int x) -> decltype(x) { return x; }` | 根据 Lambda 表达式的返回值类型，推导出 Lambda 表达式的类型。 |

下面是一些具体的例子：

1、推导变量类型：

```c++
int x = 42;
decltype(x) y = x;  // 推导出 y 的类型为 int
```

2、推导表达式类型：

```c++
int x = 42;
decltype(x + 0.5) y = x + 0.5;  // 推导出 y 的类型为 double
```

3、推导返回值类型：

```c++
int foo(int x, int y)
{
  return x + y;
}

decltype(foo(1, 2)) z = foo(1, 2);  // 推导出 z 的类型为 int
```

4、推导Lambda表达式类型：

```c++
auto lambda = [](int x) -> decltype(x) 
{
  return x;
};
int y = lambda(42);  // 推导出 lambda 的类型为 int (由于返回类型与参数类型相同)
```

### 有时候还会遇到这样的问题：

```c++
template<class T1, class T2>
?type? gt(T1 x, T2 y)
{
	...
	return x + y;
	...
}
```

此处函数的返回类型好像可以设置为decltype(x + y),但此时还未声明x和y，他们不在作用域内（也就是说编辑器看不到它们，也无法使用它们）。

对于原型：

```c++
double h(int x, float y);
```

利用新增的语法：

```c++
auto h(int x, float y) -> double;
```

这将返回类型移到了参数声明后面。->double被称为后置返回类型，auto是一个占位符，表示后置返回类型提供的类型。

那么随上述的模板问题可以解决如下：

```c++
template<class T1, class T2>
auto gt(T1 x, T2 y) --> decltype(x + y)
{
	...
	return x + y;
	...
}
```

## 57、atan2函数

```c++
double atan2(double y, double x)
```

- **x** -- 代表 x 轴坐标的浮点值。
- **y** -- 代表 y 轴坐标的浮点值。

## 返回值

该函数返回以弧度表示的 y/x 的反正切，弧度区间为 [-pi,+pi]。

返回以弧度表示的 **y/x** 的反正切。y 和 x 的值的符号决定了正确的象限。

## 58、强制转换char型数组名，从而输出地址

```c++
char buffer[5];
cout << (void *) buffer << endl;
```

没有括号内的内容进行强制性转换，相当于直接打印字符串内容，而非地址。

## 59、delete释放定位new？

delete只能释放常规new定义的动态内存，不能够释放使用定位new运算符分配的静态内存

## 

## 60、局部变量和全局变量

在许多编程语言中，包括C和C++，全局变量和静态变量没有被显式初始化时默认为0，而自动变量（局部变量）没有被显式初始化时其值是未定义的（通常是随机的，但也可能是其他未定义的值）。

## 61、使用引用实现动态内存分配的例子

例子1：使用引用作为函数参数，实现对动态分配的数组进行操作。

```c++
void foo(int*& arr, int size)
{
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

int main()
{
    int* arr;
    foo(arr, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
```

在这个例子中，我们定义了一个名为foo的函数，它接受一个指向整型指针的引用，和一个整型参数size。函数中，我们使用new关键字动态分配了一个大小为size的整型数组，并通过引用将其指针赋值给了函数参数arr。在主函数中，我们调用foo函数，并传递一个指向整型指针的指针变量arr。foo函数内部对arr进行操作，并返回了一个指向动态分配内存的指针。在主函数中，我们使用for循环遍历arr指向的整型数组，并输出其中的元素值。最后，我们使用delete[]关键字释放了动态分配的内存。

例子2：使用引用作为函数返回值，实现动态分配对象的创建和使用。

```c++
class Foo
{
public:
    Foo() {
        std::cout << "Foo created." << std::endl;
    }
    ~Foo() {
        std::cout << "Foo destroyed." << std::endl;
    }
};

Foo& createFoo() 
{
    Foo* ptr = new Foo();
    return *ptr;
}

int main() 
{
    Foo& foo = createFoo();
    // 使用foo对象
    delete &foo;
    return 0;
}
```

在这个例子中，我们定义了一个名为createFoo的函数，它返回一个指向Foo对象的引用。函数中，我们使用new关键字动态分配了一个Foo对象，并将其指针返回给函数调用者。在主函数中，我们使用createFoo函数创建了一个指向Foo对象的引用foo，并使用foo对象进行操作。最后，我们使用delete关键字释放了动态分配的内存。注意，这里需要使用delete关键字删除的是对象的地址，而不是对象本身。因此，我们需要在delete关键字后面加上取地址符&，以表示删除的是对象的地址。

## 62、关于return

关于程序编写中的return，我们在函数中需要返回值时需要使用到return，==需要注意：在return之后应该没有语句==，因为函数运行到return，就默认程序结束了，故不会再接着运行。





# 第九章：内存模型和名称空间

## 1、尖括号<>与双引号“”的区别

如果文件名包含在尖括号中，则编译器去文件系统中查找；

如果文件名包含在双引号中，则编译器首先查找当前的工作目录或源代码目录。



## 2、头文件常包含的内容

1. 函数原型
2. ==使用#define或const定义的符号常量==
3. 结构声明
4. 类声明
5. 模板声明
6. 内联函数



## 3、C++的存储特性

C++ 中的存储区域主要有以下几种：

1. 自动存储区域（automatic storage area）：这是默认的存储区域，用于存储局部变量。这些变量在函数调用时创建，在函数返回时销毁。
2. 静态存储区域（static storage area）：这个存储区域用于存储静态变量，即在函数内部用 static 关键字定义的变量，或在函数外定义的全局变量。这些变量在程序运行期间一直存在，直到程序结束才被销毁。
3. 动态存储区域（dynamic storage area）：这个存储区域用于存储动态分配的内存，即使用 new 运算符分配的内存。这些内存块在程序员手动释放或者程序结束时被自动释放。
4. 堆栈存储区域（heap storage area）：这个存储区域用于存储由 malloc() 或 calloc() 等函数分配的内存。这些内存块同样需要由程序员手动释放，否则可能会导致内存泄漏。
5. 寄存器存储区域（register storage area）：这个存储区域用于存储频繁使用的变量，编译器通常会将这些变量存储在寄存器中，以提高程序的运行效率。

==栈区==一般用于==存放函数调用时的参数、局部变量和函数返回值==等数据。栈是一种后进先出（LIFO）的数据结构，数据在栈中的存储顺序是后进先出的。

在C++中，==类对象也可以存储在栈区中==，这些对象的生命周期与函数调用相关。栈上分配的对象在函数返回时会自动调用其析构函数，以释放它们所占用的资源。



==堆区==（Heap）一般用于==存储动态分配==的数据，即程序运行时由开发者手动分配和释放的内存。

堆区一般用于存储以下类型的数据：

1. ==动态分配的数组==，例如使用new运算符在堆区中分配的数组；
2. ==动态分配的对象==，例如使用new运算符在堆区中分配的对象；
3. 其他需要==动态分配内存的数据结构==，例如链表、树等。



## 4、内部变量和外部变量

内部变量是在一个函数内部声明的变量，只能在该函数内部使用。当函数执行完毕时，这些变量就会被销毁，无法在其他函数中使用。

### 关键字extern

`extern`声明变量为外部变量时，通常指的是定义在==其他文件==中的全局变量

### 关键字static

用static限定符用于作用域为整个文件的变量时，该变量的链接性将为内部的。

1. 在函数内部使用`static`关键字声明一个局部变量，可以将该变量的作用域限制在该函数内部，即该变量只能在该函数中使用，而不能在其他函数中使用。同时，该变量的生命周期也==被限制在程序的整个运行期间==，而不是只在函数调用时存在。
2. 在C语言中，使用`static`关键字声明一个全局函数，可以将该函数的作用域限制在当前文件内部，即其他文件无法调用该函数。
3. static修饰的变量==只被初始化一次==，后续无论如何调用几次函数，也不会重新初始化，可以用来累加次数。

### Tips：

1. 在函数内部一般定义的变量是内部变量，但如果用extern修饰，也可以将其声明为外部变量。
2. 如果函数内部和函数外部都定义了同一个变量名，那么一般情况下，执行该函数时，函数内部变量的值会覆盖外部变量的值，但是可以使用作用域解析运算符::，来在函数内部，强制使用该变量在函数外部的值。



## 5、new运算符初始化

### 为内置的标量类型（如 int 或 double ）分配存储空间并初始化

在类型名后面加上初始值，并将其用括号括起

```c++
int *pi = new int (6);	//	*pi被设置为6
double * pd = new double (99.99); 	//	*pd被设置为99.99
```

### 初始化常规结构和数组

需要使用大括号的列表初始化

```c++
struct where (double x; double y; double z;);
where * one = new where {2.5, 5.3, 7.2};
int * ar = new int [4] {2, 4, 6, 7};
```



## 6、定位new运算符

### 要使用定位new特性，首先要包含头文件new

### new的四种用法

```c++
#include <new>
struct chaff
{
    char dross[20];
    int slag;
};
int main()
{
    chaff *p1, *p2;
    int *p3, *p4;
    //第一种：常规用法
    p1 = new chaff;		//存放于堆区
    p3 = new int [20];	//存放于堆区
    
    //第二种：使用定位运算符
    p2 = new (buffer1) chaff;		//存放于缓冲区buffer1
    p4 = new (buffer2) int [20];	//存放于缓冲区buffer2
}
```

1. 使用定位运算符两次向同一内存块写入数据，第二次写入的内容通常会覆盖第一次写入的内容。
2. 如果第二次向同一内存块写入的内容比第一次少，那么在读取内存块时可能会看到之前写入的数据和剩余的旧数据混合在一起

delete只能释放动态区域，不能释放静态区域，即不能用来释放定位运算符分配的内存。



## 7、强制转换字符数组名为地址

```C++
char buffer[20];
//情形1：
cout << buffer << endl;
//情形2：
cout << (void *) buffer << endl;
```

使用（void *）对buffer进行强制转换的原因，为了得到数组的地址，如果不这样做，cout将显示一个字符串



## 8、作用域解析运算符::

访问给定名称空间中的名称，可以使用作用域解析运算符来限定该名称。

使用全局变量：

```c++
cin >> ::fetch;
```



## 9、using编译指令和using声明之比较

using编译指令是全部导入；

using声明是单个导入需要的。

### 未命名的名称空间

潜在作用域为，从声明点到该声明区域末尾，这一点与全局变量类似。

由于该名称空间没有名称，因此不能显式的使用using编译指令或using声明来在其他位置使用。



## 10、特征标一样，不能用函数重载



## 11、比较字符串

1. char型数据，用strcmp（）函数
2. string型数据，直接用“ == ”





# 10、第十章：对象和类

## 1、类的基础知识

1. 类设计的关键字：class

2. 类名的首字母要大写

3. 类名+对象

    ```c++
    Stock sally；//类名：Stock
    ```

    可以类比：

    ```c++
    int  num;
    ```

    那么对象，实例sally可以看成“变量”。

4. 关键字：private和public

    ==一般情况下，private可以省略。==

    使用类对象的程序都可以直接访问公有部分，但只能通过公有成员函数（或友元函数）来访问对象的私有成员。

    数据项通常放在私有部分，成员函数一般放在公有部分。

5. 类和结构

    结构体的默认访问类型是public，而类是private

    只有数据 ---> 结构体

    不仅有数据，还有方法 ----> 类

6. 内联方法：定义位于类声明中的函数将自动成为内联函数，也就是说，在类中，不仅有函数名，还有具体的函数内容。即，定义仍在“.h”文件中。

    需要加 ==inline== 限定符。

    ==内联函数名在类声明中，具体定义在类声明外，但在“.h”文件中。==

    例如：

    ```c++
    inline void Stock::set_tot()
    {
    	total_val = shares * share_val;class MyClass {
    public:
      void doSomething();
    };
    
    inline void MyClass::doSomething() {
      // function body
    }
    
    }
    ```




## 2、类的成员函数里面可以直接访问私有变量，而不用加作用域解析运算符::来标识函数所属的类



## 3、类构造函数

### （1）专门用于构造新对象、将值赋给它们的数据成员。

### （2）构造函数的原型和函数头有一个有趣的特征——————==既没有返回值，又没有被声明为void类型==，即构造函数没有声明类型。

### （3）==构造函数的参数==表示的不是类成员，而是赋给成员的值，因此，==参数名不能与类成员相同==，否则会产生混乱。为了避免这种混乱，常见的做法是：在数据成员名中使用“==m_==”前缀；另一种常见的做法是，在成员中使用后缀“==_==”。

### （4）使用构造函数

#### 1.区分==显式==和==隐式调用==的区别

​		区别==是否有等号=的出现==

#### 2.显式地调用构造函数：

```c++
//Stock是个类构造函数，有三个参数
Stock food = Stock("World Cabbage", 250, 1.25);
```

#### 3.隐式地调用构造函数

```c++
Stock garment("Furry Mason", 50, 2.5);
```

#### 4.构造函数与new一起使用

```c++
Stock *pstock = new Stock("Electroshock", 18, 19.0);
```

对象没有名称，但可以用指针来管理该对象。

与常见的new创建动态内存一样，但是多了一个赋初值操作。

### （5）默认构造函数

#### 1.Stock是一个类

```c++
//形如：
Stock fluffy_the_cat;
```

#### 2.默认构造函数可以如下：

```c++
Stock::Stock()
{

}
```

#### 3.==默认构造函数==与==非默认构造函数==的区别

区别在于：==有无参数列表==。

#### 4.当且仅当没有定义任何构造函数时，编译器才会提供默认构造函数；

如果提供了非默认构造函数，那么程序员必须提供默认构造函数，才能去调用非默认构造函数，否则将报错。因为，没有默认构造函数，而用户自己定义的构造函数，又需要传入参数，故报错。

#### 5.定义默认构造函数有两种方式：

1. 给已有构造函数的所有参数提供默认值：

    ```c++
    Stock（const string & co = "Error", int n = 0, double pr = 0.0）;
    ```

2. 通过函数重载来定义另一个构造函数————一个没有参数的构造函数

    ```c++
    Stock();
    ```

### （6）已有自定义构造函数，需不需要再定义一个默认构造函数？

如果在C++类中已经有了自定义构造函数，则编译器不会为该类自动生成默认构造函数。如果需要使用默认构造函数，则需要显式定义一个没有参数的构造函数。

需要注意的是，如果一个类在某些情况下需要使用默认构造函数，那么应该将自定义构造函数定义为可以使用默认参数或者提供缺省值的形式，这样可以同时兼顾类的灵活性和易用性。

另外，如果一个类的对象是作为成员变量被其他类的对象所包含，那么在这种情况下，建议为该类定义一个无参数的默认构造函数，以便于其他类的对象可以顺利地创建该类的对象。



## 4、析构函数

1. 析构函数是一种特殊的函数，它在对象被销毁时自动调用，用于清理对象所占用的资源，例如释放动态分配的内存、关闭打开的文件等。

2. 如果构造函数用new来分配内存，则析构函数将使用delete来释放这些内存。

3. 析构函数的名称也很特殊：

    ```c++
    //在类名前面加上~
    //比如Stock类的析构函数为~Stock()
    ```

4. 类对象存放于栈区中，所以，如果析构函数里面有要输出的内容，并且这个内容在变化，要注意栈区规则是先进后出。

5. 每个类==只能有一个==析构函数。

6. 如果构造函数使用了new，则必须提供使用delete的析构函数

    

## 5、初始化与赋值效率相比

如果既可以通过初始化，也可以通过赋值来设置对象的值，则应采取初始化方式。

赋值操作是先创建一个临时变量，再传给变量

例如：

```c++
Stock stock2 = Stock("Boffo Objects", 2, 2.0);
stock1 = Stock("Nifty Foods", 10, 50.0);
```

第一条语句是初始化，它创建有指定值的对象，可能会创建临时对象（也可能不会）。

第二条语句是赋值语句，像这样在赋值语句中使用构造函数==总==会导致在赋值前创建一个临时对象。赋值时先创建一个临时变量，再传给stock1。



## 6、this指针

### （1）隐式访问和显式访问

```c++
const Stock & topval(const Stock & s) const;
```

因为这个对象作为函数参数传递，所以显式访问；括号中的const表明，该函数不会修改被显式访问的对象。

因为这个对象调用成员函数，所以隐式访问；括号后的const表明，该函数不会修改被隐式访问的对象。

### （2）this指针的由来

```c++
const Stock & Stock::topval(const Stock & s) const
{
    if(s.total_val > total_val)
    	return s;
    else
        return ?????;
}
```

如果想要返回上一点的隐式对象，因为没有具体对象名，而无法称呼，故使用this指针来指向调用成员函数的对象（this被作为隐藏参数传递方法）；

```c++
total_val相当于this->total_val;
```

有了this指针就可以使用

```c++
return *this;
```

this指针指向调用对象。如果方法需要引用整个调用对象，则可以使用表达式*this。

注：this是指针，也是地址，地址是整个类，自然使用要进行解引用。



## 7、对象数组

### （1）声明对象数组的方法与声明标准类型数组相同

```c++
Stock mystuff[4];
```



## 8、类作用域

### （1）在类中声明一个常变量

常见的方法，比如：

```c++
class Bakery
{
    private:
    	const int Months = 12;
    	double costs[Months];
````
}

==这是行不通的==，因为声明类只是描述了对象的形式，并没有创建对象。因此，在创建对象前，将没有用于存储值的空间。

有两种方法可以实现：

#### 1.在类中声明一个枚举

```c++
class Bakery
{
    private:
    	enum {Months = 12};
    	double costs[Months];
}
```



#### 2.使用关键字static

```c++
class Bakery
{
    private:
		static const int Months = 12;
    	double costs[Months];
}
```





## 9、抽象数据类型

简称ADT



## 10、初始化数组操作

```c++
  char name[Len] = {'\0'};
```

通过将数组元素初始化为 NULL 字符，确保了数组的第一个字符就是 NULL 字符，从而表示这是一个空字符串。这样的初始化有助于避免在处理字符串时出现未定义的行为。



# 第十一章：使用类

## 1、运算符重载

运算符函数的格式如下：

```c++
operatorop(argument-list);//关键字operator加上需要重载的运算符op
//op必须是有效的C++运算符
//例如：重载加法运算符
Time operator+(const Time & t) const;

```

## 2、运算符重载示例

### （1）不要返回指向局部变量或临时对象的引用

​				局部变量和临时对象会在函数结束时被删除。

### （2）重载加法运算符两种使用理解如下：

重载函数定义如下：

```c++
Time Time::operator+(const Time & t) const;
```

#### 使用方法一：函数表示法，即当作类的方法来调用

```c++
//coding是一个Time对象，fixing也是Time对象
total = coding.operator+(fixing);
```

#### 使用方法二：运算符表示法，即使用运算符表示法

```c++
total = coding + fixing;
```

两个Time对象直接相加，原理上不能，但使用了运算符重载函数就可以实现这一功能。

### （2）运算符重载是为了两个类对象能直接进行运算

### （3）大多数运算符都可以通过成员函数或非成员函数进行重载

举例：

```c++
//通过成员函数来进行重载
Time Time::operator+(const Time & t) const;

//通过非成员函数来进行重载
Time operator+(const Time & t);
```

==tips==：

1. 非成员函数是没有在函数声明末尾加上const这种写法的，可以用于判断是成员函数还是非成员函数。
2. 非成员函数使用类中声明的变量时，要注意把private改为public，不过一般不这样。



## 3、友元

友元分为友元函数、友元类、友元成员函数。

==为类重载二元运算符时（带两个参数的运算符）常常需要友元。也就是实现数与类的运算==

比如：Time对象乘以实数就属于这种情况。

```c++
//函数原型：
Time Time::operator*(double mult) const;
A = B * 2.75;
//会被转化为下面的成员函数调用
A = B.operator*(2.75);
```

而

```c++
A = 2.75 * B;
```

不对应于成员函数，故编译器不会调用成员函数来替换该表达式。

因为左侧的操作数应该是调用对象，而2.75不是调用对象，无法调用相应函数。

解决这个难题有两种方式：

1. 告诉每个人，按照编译器的理解方式来编写函数，但不符合OOP准则。

2. 使用非成员函数。

    对于非成员重载运算符函数来说，运算符表达式==左边操作数==对应于运算符函数的==第一个参数==，运算符表达式==右边的操作数==对应于运算符函数的==第二个参数==

```c++
Time operator*(double m, const Time & t);//Time：类
```

但引发了一个问题：

==非成员函数不能直接访问类的私有数据==，至少常规非成员函数不能访问。然而，==有一类特殊的非成员函数可以访问类的私有成员，它们被称为友元函数==。

### （1）创建友元

#### 1.将原型放在类声明中，并在原型声明前加上关键字friend

1. 虽然友元函数是在类声明中声明的，但它不是成员函数，因此不能使用成员运算符来调用。
2. 虽然友元函数不是成员函数，但它与成员函数的访问权限相同

#### 2.编写函数定义

1. 因为他不是成员函数，所以==不需要使用Time::限定符==。
2. ==不要==在==定义中==使用==关键字friend==

有了友元函数（如下），那么

```c++
Time operator*(double m, const Time & t)
{
    Time result;
    long totalminutes = t.hours * m * 60 + t.minutes * m;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}
```

### (2)区分友元还是非友元

例如：

```c++
Time operator*(double m, const Time & t)
{
    return t * m;
}

/////////////////////////////////////////////////
void operator<<(ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
}
```

区分方式是:	是将对象作为整体使用（非友元），还是直接访问对象的私有成员（友元）



### （3）定义运算符函数时，如果要使用其==第一个操作数====不==是类对象，则==必须使用==友元函数



## 4、重载运算符：作为成员函数还是非成员函数

非成员版本的重载运算符函数所需的形参数目与运算符使用的操作数数目相同；

而成员函数所需的参数数目少一个，因为其中的一个操作数是被隐式地传递的调用对象。

==原因==在于：对于成员函数版本来说，一个操作数通过==this指针隐式==地传递，另一个操作数作为==函数参数显式地传递==；

对于友元版本来说，==两个操作数都作为参数来传递==。



## 5、再谈重载：一个矢量类

友元函数可以访问类中变量，但需加类名作为前缀。

假设shove是一个Vector对象，有以下代码：

```c++
//1、使用reset函数
shove.reset(100, 300);

//2、使用构造函数
shove = Vector(100, 300);
```

方法reset（）直接修改了shove的内容，而使用构造函数将增加额外的步骤：创建一个临时对象，然后将其赋给shove。

### （1）友元函数使用类的私有数据

要==注意加上类名限定符==！！！

### （2）如果方法通过==计算==得到一个==新的类对象==，则应考虑是否可以使用==类构造函数==来完成这种工作

举例说明：

例如第十一章课后习题，复习题的第一题：

使用成员函数为Stonewt类重载乘法运算符，该运算符将数据成员与double类型的值相乘。注意，用英石和磅表示，需要进位。也就是说，将10英石8磅乘以2等于21英石2磅。

头文件Stonewt.h

```c++
#ifndef STONEWT_H__
#define STONEWT_H__

class Stonewt
{
    private:
        enum {Lbs_per_stn = 14};
        int stone;
        double pds_left;
        double pounds;
    public:
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt();
        ~Stonewt();
        void show_lbs() const;
        void show_stn() const;
};

#endif
```



stonewt.cpp文件==部分代码==：

```c++
#include <iostream>
using std::cout;
#include "stonewt.h"

Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;   
}

```



原本的思路：

头文件：

```c++
#ifndef STONEWT_H__
#define STONEWT_H__

class Stonewt
{
    private:
        enum {Lbs_per_stn = 14};
        int stone;
        double pds_left;
        double pounds;
    public:
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt();
        ~Stonewt();
        void show_lbs() const;
        void show_stn() const;
    	Stonewt operator*(double n) const;
};

#endif
```

函数实现代码：

```c++
#include <iostream>
using std::cout;
#include "stonewt.h"

Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;   
}

Stonewt Stonewt::operator*(double n) const
{
    Stonewt st;
    st.stones = n * stones + (n * pounds) / stone_to_pounds;
    st.pounds = (n * pounds) % stone_to_pounds;
    return st;
}
```



切入正题：利用类构造函数来实现：

```c++
#include <iostream>
using std::cout;
#include "stonewt.h"

Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;   
}

Stonewt Stonewt::operator*(double n) const
{

}
```



### （3）

### （4）

##### 1. 解读 srand(time(0))

1. ==time(0)==函数会返回当前时间，以==自 1970 年 1 月 1 日 0 点 0 分 0 秒==以来==经过的秒数==作为时间戳。当我们将 `time(0)` 作为参数传递给 `srand` 函数时，实际上是将当前时间作为随机数生成器的种子值。
2. 当我们将 ==time(0)==作为参数传递给 `srand` 函数时，实际上是将当前时间作为随机数生成器的种子值。因此，==srand(time(0))== 将随机数生成器的种子设置为当前时间，使得程序生成的随机数序列更加不可预测和多样化。

#### 2. direction = rand() % 360;

​		生成0 ~ 359的随机数

#### 3.在主函数中，向类的方法传入参数时，如果使用到类声明中的数据

1. 首先要将该数据设置为public
2. 其次，要对该数据加上类限定符。

## 6、类的自动转换和强制类型转换

### （1）自动转换

#### 1.C++中，接收==一个参数==的==构造函数==为将==类型与该参数相同的值==转换为==类==提供了蓝图。

例如：有以下构造函数（英石与磅的转换关系）

```c++
Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;   
}
```

自动转换：

```c++
Stonewt myCat;
myCat = 19.6;
```

使用构造函数Stonewt(double)来创建一个临时的Dtonewt对象，并将19.6作为初始化值。随后，采用逐成员赋值方式将该临时变量的内容复制到myCat。这一过程称为隐式转换，因为它是自动进行的，而不需要显示强制类型转换。



#### 2.只有接受一个参数的构造函数才能作为转换函数。

例如，下面的构造函数有两个参数，因此==不能用来转换类型==：

```c++
Stonewt(int stn, double lbs)
```

然而，如果给第二个参数提供默认值，他便可以用于转换int：

```c++
Stonewt(int stn, double lbs = 0)
```



#### 3.新增explicit用于关闭这种自动特性

声明构造函数时，加上关键字：explicit，关闭了隐式转换

例如：

```c++
explicit Stonewt::Stonewt(double lbs)
```

==但==，显示转换仍然允许，即显示强制类型转换：

```c++
Stonewt myCat;
myCat = 19.6;//不合法
myCat = Stonewt(19.6);
myCat = (Stonewt) 19.6;
```

#### 4.如何区分类的隐式转换与显示转换

显示转换和隐式转换的==区别==在于==是否明确地指定了转换类型==。显示转换是程序员明确地指定要进行的转换类型，例如使用==强制类型转换运算符== `(type)` 或者使用 C++ 的类型转换运算符 `static_cast<type>`、`dynamic_cast<type>` 等。而==隐式转换==是==编译器自动进行==的，不需要程序员明确指定。

例如，下面的代码中，`double x = 3;` 是一个隐式转换，因为整数 `3` 被自动转换为 `double` 类型。而 `int y = (int) 3.14;` 是一个显示转换，因为程序员使用了强制类型转换运算符 `(int)` 来明确指定了要将 `3.14` 转换为 `int` 类型。

```c++
double x = 3; // 隐式转换
int y = (int) 3.14; // 显示转换
```

对于==类==类型，区分隐式转换和显示转换的方法与基本类型相同。如果程序员==明确指定了要进行的转换类型==，那么这是一个==显示转换==。否则，如果编译器自动进行了转换，那么这是一个隐式转换。

例如，假设我们有一个名为 `Stonewt` 的类，它有一个接受 `double` 类型参数的构造函数。下面的代码中，`Stonewt myCat = 19.6;` 是一个隐式转换，因为编译器会自动调用接受 `double` 类型参数的构造函数来将 `19.6` 转换为 `Stonewt` 类型的对象。而 `Stonewt myDog = Stonewt(50);` 是一个显示转换，因为程序员明确调用了构造函数来进行转换。

```c++
Stonewt myCat = 19.6; // 隐式转换
Stonewt myDog = Stonewt(50); // 显示转换
```

此外，在类定义中，可以使用 `explicit` 关键字来防止构造函数被用于隐式转换。例如，如果我们在上面的例子中将构造函数定义为 `explicit Stonewt(double);`，那么 `Stonewt myCat = 19.6;` 这一行代码将会导致编译错误，因为编译器不再能够自动进行隐式转换。



### （3）转换函数：将==类==转换成==其他数据类型==

构造函数只用于从某种类型到类类型的转换，而要进行相反的转换，必须使用转换函数。

#### 1.转换函数的形式

```c++
operator typename();
```

tips：

1. 转换函数必须是类方法
2. 转换函数不能指定返回类型
3. 转换函数不能有参数

例如，转换为double类型的函数原型如下：

```c++
operator double();
```

typename(这里指的是double)指出了要转换成的类型，因此不需要指定返回类型；

转换函数是类方法意味着：它需要通过类对象来调动，从而告知函数要转换的值。



#### 2.double类型数据转换成int型（四舍五入法）

可以使用

```c++
int (double + 0.5);//double这里指double类型的数据
```



#### 3.取消隐式转换

1. 方法一：使用 关键字：explicit

```c++
explicit operator int () const;
explicit operator double () const;
```

2.方法2：

用一个功能相同的非转换函数替换该函数



## 7、习题

### 编程练习3：想要求N次测试中的的最高、最低和平均步数

1. 首先，要求N次测试中，那么这个N肯定是已知的，所以可以优先使用for循环

2. 其次，使用三目运算符来比较时，初始值min为0，所以无论怎么比都是选择的初始值，因此，需要进行以下处理：

    ```c++
    max = (max > steps) ? max : steps;
    if(min == 0)
        min = max;
    else
    	min = (min < steps) ? min : steps;
    ```

3. 这里还有一个细节：求取平均步数时，如何来计算，走的总步数 / 走的总次数？

    ==错误==

    这里的sum/steps只能得出整数，不够精确

    因此：

    ```c++
    average = (double) sum / steps;
    ```

    

# 第十二章：类和动态内存分配

## 1、	动态内存和类

### 1.1复习示例和静态类成员

#### （1）	static int num	与	static const int num	的区别

- `static int num` 是一个静态变量，可以修改其值，并且具有在函数调用之间保持值的特性。
- `static const int num` 是一个静态常量，不能修改其值，并且在编译时就已确定其值。
- 静态变量的初始化是在方法文件中，也就是.cpp文件中，如果在类声明文件中进行初始化，将会出现多个初始化语句副本，从而引发错误
- 而，如果静态成员是const整数类型或枚举类型，则可以在类声明中初始化，也就是静态常量可以在类声明文件中初始化。

#### （2）何时系统自动调用析构函数

析构函数（Destructor）是在对象生命周期结束时被调用的特殊成员函数。它用于清理对象分配的资源和执行其他清理操作。析构函数的调用时机如下：

1. 当**对象离开其作用域**：如果一个**对象**是在一个**函数内部声明**的，当函数执行结束并离开对象的作用域时，析构函数将被调用。
2. 当**对象被显式地删除**：如果在程序中使用了 `delete`运算符来显式地销毁一个动态分配的对象，析构函数将在 `delete` 语句执行时被调用。
3. 当**对象作为另一个对象的成员**，而该对象的析构函数被调用：当包含该对象的父对象被销毁时，它的析构函数将被调用。
4. 当**对象作为容器中的元素**，而容器被销毁时：如果对象是容器（如数组、列表、向量等）中的元素，当容器被销毁时，会调用每个元素对象的析构函数。

需要注意的是，如果一个对象是通过 `new` 运算符动态分配的，并且没有被显式地释放，那么它的析构函数将不会被调用，从而导致内存泄漏。为了避免内存泄漏，应该在适当的时候使用 `delete` 运算符来销毁动态分配的对象。

需要注意的是，析构函数的调用顺序与对象创建的顺序相反。也就是说，先创建的对象的析构函数会后调用，后创建的对象的析构函数会先调用。这确保了对象的销毁按照相反的顺序进行。

总之，析构函数在对象生命周期结束时被调用，用于对象的清理和资源释放。

### const值与非const值能不能相互赋值？非const引用和const引用呢？

在C++中，const值和非const值之间不能直接相互赋值。这是因为const值被设计为不可修改的，而非const值可以被修改。如果允许将const值直接赋给非const变量，就会破坏const的不可修改性。

下面是一个示例来说明这一点：

```c++
#include <iostream>

int main() {
    const int constValue = 10;
    int nonConstValue = 20;

    nonConstValue = constValue;  // 错误，将const值赋给非const变量

    return 0;
}

```

在上面的例子中，我们定义了一个const值 constValue 和一个非const变量 nonConstValue。然后，我们试图将const值赋给非const变量，即 nonConstValue = constValue;。这样的赋值是错误的，会导致编译错误，因为const值不能被修改。

然而，非const值可以赋给const变量或const引用，因为const变量和const引用都保持了对被引用对象的只读性，而不会修改它们。这样做是安全的，并且符合const的语义。

下面是一个示例来说明非const值赋给const变量和const引用：

```c++
#include <iostream>

int main() {
    int nonConstValue = 20;
    const int constValue1 = nonConstValue;  // 非const值赋给const变量
    const int& constRef = nonConstValue;    // 非const值赋给const引用

    std::cout << "constValue1: " << constValue1 << std::endl;
    std::cout << "constRef: " << constRef << std::endl;

    return 0;
}
```

在上面的例子中，我们将非const值 nonConstValue 分别赋给了const变量 constValue1 和const引用 constRef。这是合法的，因为const变量和const引用只是对被引用对象的只读访问，并不会修改它们的值。

因此，==const值和非const值之间不能相互赋值，但非const值可以赋给const变量和const引用，符合const的语义==。



# 第十三章 类继承

类继承：能够从已有的类派生出新的类，而派生类继承了原有类（称为基类）的特征，包括方法。

string类提供了默认的复制构造函数，会处理所有必要的内存分配和字符复制。

