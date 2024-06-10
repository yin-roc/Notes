# day1

## 1、Python 软件（PyCharm）

安装：[在 Linux 环境下安装 Pycharm](https://blog.csdn.net/CNjcdyl/article/details/125158395)

插件：[汉化](https://blog.csdn.net/2301_76161259/article/details/135145727)、[翻译](https://blog.csdn.net/m0_57081622/article/details/127332289)

[设置字体大小](https://blog.csdn.net/jq_98/article/details/125266510)

常用快捷键：

- ctrl + alt + s ：打开软件设置
- ctrl + d ：复制当前行代码
- shift + alt + 上\下 ：将当前行代码上移或下移
- crtl + shift + f10 ：运行当前代码文件
- shift + f6 ：重命名文件
- ctrl + a ：全选
- ctrl + c\v\x ：复制、粘贴、剪切
- ctrl + f ：搜索



## 2、Python 流程：

![image-20240609140337326](Python.assets/image-20240609140337326.png)



# 正式开始：

## 1、字面量

字面量：在代码中，被写下来的固定的值，称之为字面量。

Python中常用的有6种值（数据）的类型：

![image-20240609142226265](Python.assets/image-20240609142226265.png)

字面量的输出程序：

```python
print(66)
print(13.14)
print("黑马程序员")
```



## 2、注释

注释：在程序代码中对程序代码进行解释说明的文字。

注释的分类

- 单行注释：以 # 开头，# 右边 的所有文字当作说明，而不是真正要执行的程序，起辅助说明作用。

	示例：

	```python
	# 写一个整数字面量
	```

	

- 多行注释：以 一对三个双引号 引起来（"""注释内容"""）来解释说明一段代码的作用使用方法.

	一般用于解释：整个PYTHON代码文件、类和方法

	示例：

	```python
	"""
	本代码演示了：
	- 各类字面量的写法
	- 通过 print 语句输出各类字面量
	"""
	```



示例程序：

```python
"""
本代码演示了：
- 各类字面量的写法
- 通过 print 语句输出各类字面量
"""

# 写一个整数字面量
666
# 写一个浮点数字面量
13.14
# 写一个字符串字面量
"黑马程序员"

# 通过 print 语句输出各类字面量
print(66)
print(13.14)
print("黑马程序员")
```



## 3、变量

变量：在程序运行时，能储存计算结果或能表示值的抽象概念。

<img src="Python.assets/image-20240609151528848.png" alt="image-20240609151528848" style="zoom:50%;" />

示例：

```python
"""
本代码演示了：
- Python中变量的相关操作
"""

# 定义了一个变量，用来记录钱包余额
money = 50
# 通过 print 语句，输出变量记录的内容
print("钱包还有：", money)

# 买了一个冰淇淋，花费10元
money = money - 10
print("买了冰淇淋花费10元，还剩余：", money, "元")

# 假设，每隔一小时，输出一下钱包的余额
# ctrl+d 快速复制
print("现在是下午1点，钱包余额剩余:", money)
print("现在是下午2点，钱包余额剩余:", money)
print("现在是下午3点，钱包余额剩余:", money)
print("现在是下午4点，钱包余额剩余:", money)
```

==tips==：ctrl+d 快速复制



## 4、数据类型

我们可以通过 type() 语句来得到数据的类型

### type() 语句的使用方式

<img src="Python.assets/image-20240609154642774.png" alt="image-20240609154642774" style="zoom: 67%;" />

我们通过 type(变量) 可以输出类型，这==查看的是变量存储的数据的类型==。因为，变量无类型，但是它存储的数据有。

示例程序：

```python
# 方式1：使用 print 直接输出类型信息
print(type("heimachengxuyuan"))
print(type(666))
print(type(13.14))

# 方式2：使用变量存储 type() 语句的结果
string_type = type("heimachengxuyuan")
int_type = type(666)
float_type = type(13.14)
print(string_type)
print(int_type)
print(float_type)

# 方法3：使用 type() 语句，查看变量中存储的数据类型信息
name = "heimachengxuyuan"
name_type = type(name)
print(name_type)
```



### 字符串类型的三种定义方式

<img src="Python.assets/image-20240609161054522.png" alt="image-20240609161054522" style="zoom:67%;" />



## 5、数据类型转换

==类型转换注意事项==

类型转换不是万能的，毕竟强扭的瓜不会甜，我们需要注意:

1. 任何类型，都可以通过str()，转换成字符串；
2. 字符串内必须真的是数字，才可以将字符串转换为数字；
3. 浮点数转为整数会丢失精度，向下丢失。

示例：

```python
# 将数字类型转换成字符串
num_str = str(11)
print(type(num_str), num_str)

float_str = str(11.345)
print(type(float_str), float_str)

# 将字符串转换成数字
num = int("11")
print(type(num), num)

num2 = float("11.345")
print(type(num2), num2)

# error
# num3 = int("heimachengxuyuan")
# print(type(num3), num3)

# 整数转浮点数
float_num = float(11)
print(type(float_num), float_num)

# 浮点数转整数
int_num = int(11.345)
print(type(int_num), int_num)
```



## 6、标识符

在 Python 程序中，我们可以给很多东西起名字，比如:

- 变量的名字
- 方法的名字
- 类的名字，等等

这些名字，我们把它统一的称之为标识符，用来做内容的标识。所以，标识符：是用户在编程的时候所使用的一系列名字，用于给变量、类、方法等命名。

### 标识符命名规则

Python中，标识符命名的规则主要有3类:

- 内容限定
- 大小写敏感
- 不可使用关键字

#### 标识符命名规则——内容限定

标识符命名中，只允许出现:

- 英文
- 中文
- 数字
- 下划线(_)

这四类元素。其余任何内容都不被允许。

==tips==：

1. 不推荐使用中文
2. 数字不可以用在开头



#### 标识符命名规则—大小写敏感

以定义变量为例：

Andy=“安迪1”；

andy=“安迪2”；

字母a的大写和小写，是完全能够区分的。



#### 标识符命名规则—不可使用关键字

Python 中有一系列单词，称之为关键字关键字；

在 Puthon 中都有特定用途，我们不可以使用它们作为标识符。



示例程序：

```python
# 规则1：内容限定，限定只能使用：中文、英文、数字、下划线，注意：不能以数字作为开头
# error
# 1_name = "张三"
# name_! = "张三"
name_ = "zhangsan"
_name = "zhangsan"
name_1 = "zhangsan"

# 规则2：大小写敏感
Itheima = "黑马"
itheima = "黑马"
print(Itheima)
print(itheima)

# 规则3：不可使用关键字
# error，错误的使用了关键字
# class = 1
# def = 1
Class = 1
Def = 1
```



### 变量命名规范

学完了标识符(变量、类、方法)的命名规则后，我们在来学习标识符的命名规范

- 变量名
- 类名
- 方法名

不同的标识符，有不同的规范。



我们目前只接触到了：变量。所以，目前学习:变量的命名规范。

- 见名知意
- 下划线命名法
- 英文字母全小写

#### 变量命名规范—见名知意

变量的命名要做到:

- 明了：尽量做到，看到名字，就知道是什么意思；
- 简洁：尽量在确保“明了”的前提下，减少名字的长度。



#### 变量命名规范—下划线命名法

多个单词组合变量名，要使用下划线做分隔。



#### 变量命名规范——英文字母全小写

命名变量中的英文字母，应全部小写。



## 7、运算符

### 算数（数学）运算符

<img src="Python.assets/image-20240609171419019.png" alt="image-20240609171419019" style="zoom: 67%;" />

示例：

```python
"""
演示Python的各类运算符
"""
# 算术（数学）运算符
print("1 + 1 = ", 1+1)
print("2 - 1 = ", 2-1)
print("3 * 3 = ", 3*3)
print("4 / 2 = ", 4/2)
print("11 // 2 = ", 11//2)
print("9 % 2 = ", 9%2)
print("2 ** 2 = ", 2**2)
```



### 赋值运算符

![image-20240609171957624](Python.assets/image-20240609171957624.png)



### 复合赋值运算符

![image-20240609172015201](Python.assets/image-20240609172015201.png)



示例程序：

```python
"""
演示Python的各类运算符
"""
# 算术（数学）运算符
print("1 + 1 = ", 1+1)
print("2 - 1 = ", 2-1)
print("3 * 3 = ", 3*3)
print("4 / 2 = ", 4/2)
print("11 // 2 = ", 11//2)
print("9 % 2 = ", 9%2)
print("2 ** 2 = ", 2**2)

# 赋值运算符
num = 1 + 2 + 3
# 复合复制运算符
# +=
num = 1
num += 1
print("num += 1:", num)

num -= 1
print("num -= 1:", num)

num *= 4
print("num *= 4:", num)

num /= 2
print("num /= 2:", num)

num = 3
num %= 2
print("num %= 2:", num)

num **= 2
print("num **= 2:", num)

num = 9
num //= 2
print("num //= 2:", num)
```





# day2

## 8、字符串的三种定义方式

### 字符串在Python中有多种定义形式

1. 单引号定义法：

	```python
	name = '黑马程序员'
	```

2. 双引号定义法：

	```python
	name = "黑马程序员"
	```

3. 三引号定义法：

	```python
	name = """黑马程序员"""
	```

三引号定义法，和多行注释的写法一样，同样支持换行操作。

**使用变量接收它，它就是字符串；**

**不使用变量接收它，就可以作为多行注释使用。**

```python
"""
演示字符串的三种定义方式：
- 单引号定义法
- 双引号定义法
- 三引号定义法
"""

# 单引号定义法
name = 'heima'
print(type(name))

# 双引号定义法
name = "heimachengxuyuan"
print(type(name))

# 三引号定义法，写法和多行注释是一样的
name = """
wo
shi
heima
"""
print(type(name))
```



### 字符串的引号嵌套

思考：如果我想要定义的字符串本身，是包含：单引号、双引号自身呢？如何写？

- 单引号定义法，可以内含双引号；
- 双引号定义法，可以内含单引号；
- 可以使用转移字符 \ 来将引号解除效用，变成普通字符串示例。

示例：

```python
# 在字符串内，包含双引号
name = '"heima"'
print(name)
# 在字符串内，包含单引号
name = "'chengxuyuan'"
print(name)
# 使用转义字符 \ 解除引号的作用
name = "\"heimachengxuyuan"
print(name)
name = '\'heima\''
print(name)
```



## 9、字符串的拼接

如果我们有两个字符串（文本）字面量，可以将其拼接成一个字符串，通过 + 号即可完成，如：

```python
print("学IT来黑马"+"月薪过万")
```

输出结果：学IT来黑马月薪过万

不过一般，单纯的2个字符串字面量进行拼接显得很呆，一般，==字面量和变量或变量和变量之间会使用拼接==，如：

```python
name ="黑马程序员"
print("我的名字是:"+ name +"，我可以教大家IT技能")
```

输出结果：我的名字是：黑马程序员，我可以教大家IT技能。

示例：

```python
# 字符串字面量之间的拼接
print("hello " + "world")

# 字符串字面量和字符串变量的拼接
name = "hello world"
address = "111111"
tel = 4008208820
print(name + address)
# error: can only concatenate str (not "int") to str
# print(name + address + tel)
```



## 10、字符串格式化

我们会发现，这个拼接字符串也不好用啊，==变量过多==，拼接起来实在是太麻烦了，==字符串无法和数字或其它类型完成拼接==。

我们可以通过如下语法，完成字符串和变量的快速拼接。

```python
name ="黑马程序员"
message ="学IT就来:%s" % name
print(message)
```

其中的，%s 中 % 表示：我要占位，s 表示：将==变量变成字符串==放入占位的地方，所以，综合起来的意思就是：我先占个位置，等一会有个变量过来，我把它变成字符串放到占位的位置。

那，数字类型呢?可以不可以占位?

那必须可以，我们来尝试如下代码:

```python
class_num = 57
avg_salary = 16781
message ="Python大数据学科，北京%s期，毕业平均工资:%s" %(class_num，avg_salary)
print(message)
```

输出结果：Python大数据学科，北京57期，毕业平均工资：16781

==tips==：

1. 多个变量占位
2. 变量要用括号括起来
3. 并按照占位的顺序填入



Python中，其实支持非常多的数据类型占位：

<img src="Python.assets/image-20240610153515537.png" alt="image-20240610153515537" style="zoom:67%;" />



示例程序：

```python
# 通过占位的形式，完成拼接
name = "heima"
message = "hello: %s" % name
print(message)

# 通过占位的形式，完成数字和字符串的拼接
class_num = 57
avg_salary = 16781
message = "Python大数据学科，北京 %s 期，毕业平均工资: %s " % (class_num, avg_salary)
print(message)

name = "传智伯克"
setup_year = 1990
stock_price = 99.90
message = "%s, 成立于：%d, 今天的股价是：%f" % (name, setup_year, stock_price)
print(message)
```

输出：

```python
hello: heima
Python大数据学科，北京 57 期，毕业平均工资: 16781 
传智伯克, 成立于：1990, 今天的股价是：99.900000
```



## 11、格式化的精度控制

我们可以使用辅助符号"m.n"来控制数据的宽度和精度

- m，控制宽度，要求是数字(==很少使用==)，==设置的宽度小于数字自身，不生效==
- .n，控制小数点精度，要求是数字，会进行小数的四舍五入

==tips==：格式化字符串时的宽度限制（如 %5d 或 %5.3f）是指整个字段的宽度，包括数字、小数点和任何其他字符。

%5d：表示将整数的宽度控制在5位，如数字11，被设置为5d，就会变成：\[空格\]\[空格\]\[空格]11，用三个空格补足宽度。 

%5.2f：表示将宽度控制为5，将小数点精度设置为2 小数点和小数部分也算入宽度计算。如，对11.345设置了%7.2f后，结果是：\[空格\]\[空格\]11.35。2个空格补足宽度小数部分限制 2 位精度后，四舍五入为 .35

%.2f：表示不限制宽度，只设置小数点精度为2，如 11.345 设置 %.2f 后，结果是11.35

示例：

```python
num1 = 11
num2 = 11.345
print("数字11宽度限制为5，结果是：%5d " % num1)
print("数字11宽度限制为1，结果是：%1d " % num1)
print("数字11.345宽度限制为7，小数精度2，结果是：%7.2f " % num2)
print("数字11.345宽度限制为7，小数精度2，结果是：%.2f " % num2)
```

输出结果：

```python
数字11宽度限制为5，结果是：   11 
数字11宽度限制为1，结果是：11 
数字11.345宽度限制为7，小数精度2，结果是：  11.35 
数字11.345宽度限制为7，小数精度2，结果是：11.35 
```



## 12、字符串格式化的方式2

字符串格式化快速写法：

通过语法：`f"内容{变量}"` 的格式来快速格式化。

==tips==:

1. 这种写法不做精度控制
2. 也不理会类型
3. 适用于快速格式化字符串

示例：

```python
"""
演示第二种字符串格式化的方式：f"{占位}"
"""
name = "传智伯克"
setup_year = 1990
stock_price = 99.90
print(f"我是{name}，我成立于：{setup_year}年，我今天的股价是：{stock_price}")
```

输出结果：

```python
我是传智伯克，我成立于：1990年，我今天的股价是：99.9
```



## 13、对表达式进行格式化

表达式就是一个具有明确结果的代码语句，如1+1、type(“字符串”)、3*5等在变量定义的时候，如 age=11+11，等号右侧的就是表达式，也就是有具体的结果，将结果赋值给了等号左侧的变量。

如何格式化表达式?

1、`f"{表达式}"`

2、`"%s \ %d \ %f" % (表达式、表达式、表达式)`

在无需使用变量进行数据存储的时候，可以直接格式化表达式。

示例：

```python
"""
演示对表达式进行字符串格式化
"""
print("1*1 的结果是：%d" % (1*1))
print(f"1*2 的结果是：{1*2}")
print("字符串在 Python 中的类型名是：%s" % type("字符串"))
```

输出结果：

```python
1*1 的结果是：1
1*2 的结果是：2
字符串在 Python 中的类型名是：<class 'str'>
```



## 14、字符串格式化的课后练习题

![image-20240610170918689](Python.assets/image-20240610170918689.png)

示例程序：

```python
name = "chuanzhiboke"
stock_price = 19.99
stock_code = "003032"
stock_price_growth_factor = 1.2
growth_days = 7
print(f"公司：{name}，股票代码：{stock_code}，当前股价：{stock_price}")
print("每日增长系数：%2.1f, 经过 %d 天的增长,股价达到了：%5.2f" % (stock_price_growth_factor, growth_days, stock_price*(1.2**7)))
```



## 15、数据输入（ input 语句）

### input 语句（函数）

在Python中，print语句(函数)，可以完成将内容（字面量、变量等）输出到屏幕上，与之对应的还有一个input语句，用来获取键盘输入。

- 数据输出：print
- 数据输入：input

使用上也非常简单：

- 使用 input() 语句可以从键盘获取输入；
- 使用一个变量接收(存储) input 语句获取的键盘输入数据即可。

示例：

```python
"""
演示 python 中的input语句
获取键盘的输入信息
"""
print("请告诉我你是谁？")
name = input()
print("我知道了，你是: %s" % name)
```

输出结果：（绿色的为输入内容）

<img src="Python.assets/image-20240610173526765.png" alt="image-20240610173526765" style="zoom:80%;" />



input()语句其实是可以在要求使用者输入内容前，输出提示内容的，方式如下:

```python
name = input("请告诉我你是谁？")
print("我知道了，你是: %s" % name)
```

输出结果：(绿色的为输入内容)

<img src="Python.assets/image-20240610173351266.png" alt="image-20240610173351266" style="zoom: 80%;" />



### input语句获取的数据类型

如果我们输入数字类型或其它类型，结果会如何?

可以看到，无论键盘输入何种类型的数据==最终的结果都是：字符串类型的数据==，如果需要==转换成其他类型，需要进行强制类型转换==。

示例程序：

```python
# 输入数字类型
num = input("请告诉我你的银行卡密码：")
print(type(num))
# 数据类型转换
num = int(num)
print("你的银行卡密码的类型是: ", type(num))
```

输出结果：

<img src="Python.assets/image-20240610173330326.png" alt="image-20240610173330326" style="zoom:80%;" />



## 16、布尔类型和比较运算符

布尔类型的字面量：

- True 表示真(是、肯定)
- False 表示假(否、否定)

定义变量存储布尔类型数据：变量名称 = 布尔类型字面量

布尔类型不仅可以==自行定义==，同时也可以通过计算的来（也就是==使用比较运算符进行比较运算得到布尔类型的结果==。）

比较运算符：

<img src="Python.assets/image-20240610200127294.png" alt="image-20240610200127294" style="zoom:80%;" />

示例：

```python
"""
演示布尔类型的定义
以及比较运算符的应用
"""
# 定义变量存储布尔类型的数据
bool_1 = True
bool_2 = False
print(f"bool_1变量的内容是:{bool_1}，类型是：{type(bool_1)}")
print(f"bool_2变量的内容是:{bool_2}，类型是：{type(bool_2)}")

# 比较运算符的使用
# ==, !=, >, <, >=, <=
# 演示进行内容的相等比较
num1 = 10
num2 = 10
print(f"10 == 10的结果是：{num1 == num2}")

num1 = 10
num2 = 15
print(f"10 != 15的结果是：{num1 != num2}")

name1 = "itcast"
name2 = "itheima"
print(f"itcast == itheima的结果是：{name1 != name2}")

# 演示大于小于，大于等于，小于等于的比较运算
num1 = 10
num2 = 5
print(f"10 > 5 的结果是：{num1 > num2}")
print(f"10 < 5 的结果是：{num1 < num2}")

num1 = 10
num2 = 11
print(f"10 >= 11的结果是：{num1 >= num2}")
print(f"10 <= 11的结果是：{num1 <= num2}")

# 数字 1 与字符串 '1' 进行比较
print(f"1 == '1'的结果是：{1 == '1'}")
```

输出结果：

<img src="Python.assets/image-20240610200434060.png" alt="image-20240610200434060" style="zoom:80%;" />





## 17、if 语句的基本格式

程序中的判断

```python
if 要判断的条件:
	条件成立时，要做的事情
```

判断语句的==结果==，==必须是布尔类型True或False==

- True会执行if内的代码语句
- False则不会执行

if 语句的==注意事项==：

- 判断条件的结果一定要是布尔类型
- 不要忘记判断条件后的： 引号
- 归属于if语句的代码块，需在前方填充4个空格缩进

示例程序：

```python
"""
演示 python 判断语句：if语句的基本格式应用
"""
age = 30
if age >= 18:
    print("我已经成年了")
    print("即将步入成年生活")
print("时间过的真快阿")

age = 10
if age >= 18:
    print("我已经成年了")
    print("即将步入成年生活")
print("时间过的真快阿")
```

输出结果：

![image-20240610201752449](Python.assets/image-20240610201752449.png)
