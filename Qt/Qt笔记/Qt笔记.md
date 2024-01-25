# Qt学习目录

[TOC]

## 快捷键

1、ctrl + sapce：在函数的括号内，快速查看该函数的各个参数定义；

2、fn+F1：在函数名中间按下该快捷键，快速打开帮助文件查看定义



## 1、Qt的几个名词和概念

Qt：一个==跨平台==的C++==图形用户界面应用程序框架==，支持Win、Mac和Unix。

Qt Creator：IDE，集成开发环境，类似于Visual Studio，包括C++编辑器、项目生成管理工具、图形界面的调试器等

Qt Designer：专门用来设计图形界面的。包含在Qt Creator里面。



## 2、视频02：创建一个Qt工程helloworld

1、选择创建 Qt Widgets Application：窗体小部件；并选择项目位置；

![image-20231209171506603](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231209171506603.png)

![image-20231209171539853](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231209171539853.png)

![image-20231209171629153](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231209171629153.png)



2、定义类信息

Dialog：对话框

生成的自定义类名为HelloDialog，是从基类QDialog派生而来。

![image-20231209170207406](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231209170207406.png)



3、项目的汇总信息：

![image-20231209170510048](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231209170510048.png)



4、项目创建完成：

helloworld.pro：整个项目的工程文件，包含了项目的基本信息；

hellodialog.h、hellodialog.cpp、main.cpp：自定义类的一些C++文件；

hellodialog.ui：设计的界面文件

![image-20231209170628598](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231209170628598.png)



## 3、视频03：项目运行发布和设置图标

### 1、配置电脑Qt环境

1、问题：编译好的exe文件打开不了？

![image-20231210173051294](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231210173051294.png)

2、原因：Qt的一些ddl环境没有加入电脑环境

3、解决方法：

我的电脑$\rightarrow$属性$\rightarrow$高级系统设置$\rightarrow$环境变量$\rightarrow$系统变量$\rightarrow$Path$\rightarrow$编辑$\rightarrow$新建$\rightarrow$浏览$\rightarrow$Qt安装位置里面的bin

设置好环境变量之后，便可以打开helloworld.exe文件

### 2、release版本与Debug版本

Debug版本：helloworld.exe占据1Mb

Release版本：helloworld.exe占据25kb

左下角选择版本为Release版本。

![image-20231211112122963](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231211112122963.png)

### 3、问题：文件打包给别人，却因为没有Qt后者没有加入相关环境而导致无法打开



因为电脑的环境变量已设置（如第一点），直接使用windeployqt.exe

使用Qt 5.6 for Desktop 打开如下：

![image-20231211113524066](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231211113524066.png)

使用Qt的工具windeployqt给可执行文件helloworld.exe添加动态链接库（动态编译、动态链接的方式）

格式：

```
windeployqt 可执行文件所在的文件路径
```

![image-20231211113253735](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231211113253735.png)

效果如下：

![image-20231211113830652](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231211113830652.png)

效果如下：

![image-20231211113910484](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231211113910484.png)



### 4、添加自动图标

1、图表样式如下图所示（要将图标放入helloworld工程里面，而不是Debug/Release版本）：

![image-20231211114606234](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231211114606234.png)

2、重新打开工程文件并在helloworld.pro文件里面添加如下所示代码：

```
RC_ICONS = myico.ico
```

![image-20231211114736078](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231211114736078.png)

3、重新运行，发现图标都变样了：

![image-20231211114854965](C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20231211114854965.png)

![image-20231211114951964](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231211114951964.png)

![image-20231211115053817](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231211115053817.png)



## 4、视频04：项目文件组成及分析

### 1、QWidget

​		可视界面的基类

### 2、MyFirst_Widget.pro

​		文件代码内容：

```
QT       += core gui 
// 核心图形用户界面，如果是基于控制台/命令的则不需要这行代码
// 如果有对话框，则自动添加

//QT		 += sql //如果用到数据库，则将对应模块添加

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
// 条件执行语句，如果当前QT的版本大于4，当前项目加入 widgets 模块，QT4之前用的更多的是GUI，为了兼容之前版本

TARGET = MyFirst_Widget
// 生成的可执行文件名称

TEMPLATE = app
// 生成出一般的应用程序

SOURCES += main.cpp\
        widget.cpp
        // 源文件

HEADERS  += widget.h
// 头文件

FORMS    += widget.ui
// ui文件

```



### 3、信号与槽

给对话框添加一个按钮，右下角改名为：Close，点击Close则退出当前对话框：widget

![image-20231211144030138](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231211144030138.png)



### 4、main文件解析

```
#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Qt的标准应用程序类，任何Qt Widget程序都要有一个 QApplication 对象
    
    Widget w;
    // 创建一个窗体对象
    
    w.show();
	// 展示窗体
	
    return a.exec();
    // 启动应用程序的执行
}

```



### 5、Widget.h文件解析

```
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}
// 定义了一个名称空间 Ui，在里面使用一个类

// --------------------------------------
// 上述 Widget 类与下方的 Widget 并非同一个类
// --------------------------------------

// -------------此处 Widget 为自定义类------
// 来自于 QWidget 类
class Widget : public QWidget
{
    Q_OBJECT
    // QT中使用了信号与槽都需要使用这个宏

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    // 这里的 ui 指针是在 Ui 命名空间里面的 Widget类的指针
};

#endif // WIDGET_H
```



解释Ui里面 Widget 类的由来

1、下图所示 ui_widget.h 并没有出现在工程目录当中，只出现在文件夹里面

![image-20231211145120415](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231211145120415.png)

2、打开ui_widget.h

![image-20231211145353444](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231211145353444.png)

3、Ui里面Widget的来源如上图所示

4、设置的按钮操作也会显示在这里：

![image-20231211151840526](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231211151840526.png)

### 6、widget.cpp文件解析

1、代码

```
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
    // 初始化列表，派生类的初始化要先初始化基类QWidget
{
    ui->setupUi(this);
    // setupUi用来设置窗口各种控件的属性，（在ui_widget.h文件里面）
}

Widget::~Widget()
{
    delete ui;
    // 构造函数出现了 new
}
```



ui创建了一个label和PushButton，都会出现在Ui_Widget类里面

![image-20231211150647525](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231211150647525.png)



### 7、Widget.ui文件

编译Ui界面时，会自动生成出相应代码，无需手动敲入代码



## 5、视频05：代码化UI设计

纯代码设计

### 1、创建项目工程

1)修改处1：

![image-20231212105730920](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231212105702925.png)

1-1）修改处2：

![image-20231212145637033](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231212145637033.png)

2）编写代码时借助用户帮助手册，如图所示路径：

![image-20231212110330522](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231212110330522.png)

具体操作如图所示，搜索QLabel，右边可以看到其头文件、父类为QFrame

![image-20231212110805512](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231212110805512.png)



QFrame的父类为QWidget

![image-20231212110943961](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231212110943961.png)

QFrame又是从QObject继承而来

![image-20231212111049543](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231212111049543.png)





### 2、代码编写

```c++
#include "widget.h"
#include <QLabel>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
//    QLabel * label = new QLabel;
    QLabel * label = new QLabel(this); // 3.修改代码，代替注释1和2
    label->setText("I love you, Rock!"); // 标签内容填写
    label->move(150, 100); // 6.设置标签在框内的出现位置

    QPushButton * button = new QPushButton(this);
    button->setText("Close");
    button->move(150, 180);

//    label->show();  // 1.展示新建标签
//    label->setParent(this); // 2.设置标签的从属关系，防止各自成户
//    resize(400, 300); // 4.预设了大小，但是鼠标可以修改大小
    setFixedSize(400, 300); // 5.锁定大小
    setWindowTitle("My first NO UI"); // 7.修改框体名称

}

Widget::~Widget()
{
}
```



### 3、代码化UI与可视化UI的区别

1. 纯代码化UI不如可视化UI直接，效率低、过程繁琐，但是无所不能。
2. 有些组件无法在可视化UI中设计



### 4、Qt里面的Qt助手

使用命令行输入：assistant



## 6、视频06：对象树

### 1、问题：出现new却没有delete

![image-20231214124735551](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214124735551.png)

### 2、原因

QObjects使用对象树来进行管理。

![](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214124018865.png)

**[QObject](qobject.html)[s](qobject.html) organize themselves in object trees. When you create a [QObject](qobject.html) with another object as parent, it's added to the parent's [children()](qobject.html#children) list, and is deleted when the parent is. It turns out that this approach fits the needs of GUI objects very well. For example, a [QShortcut](../qtwidgets/qshortcut.html) (keyboard shortcut) is a child of the relevant window, so when the user closes that window, the shortcut is deleted too.**

当你创建一个QObject并指定另一个对象为其父对象时，这个QObject会被添加到父对象的children()列表中，并在父对象被删除时一并删除。这种方法非常适用于GUI对象的需求。举例来说，一个QShortcut（键盘快捷键）是相关窗口的子对象，因此当用户关闭该窗口时，快捷键也会被删除。



[QQuickItem](../qtquick/qquickitem.html), the basic visual element of the Qt Quick module, inherits from [QObject](qobject.html), but has a concept of the *visual parent* which differs from that of the [*QObject*](qobject.html) *parent*. An item's visual parent may not necessarily be the same as its object parent. See [Concepts - Visual Parent in Qt Quick](../qtquick/qtquick-visualcanvas-visualparent.html) for more details.



**[QWidget](../qtwidgets/qwidget.html), the fundamental class of the Qt Widgets module, extends the parent-child relationship. A child normally also becomes a child widget, i.e. it is displayed in its parent's coordinate system and is graphically clipped by its parent's boundaries. For example, when the application deletes a message box after it has been closed, the message box's buttons and label are also deleted, just as we'd want, because the buttons and label are children of the message box.**

QWidget则是Qt Widgets模块的基础类，它扩展了父子关系。一个子对象通常也成为一个子窗口部件，即以其父窗口部件的坐标系进行显示，并在图形上受到其父窗口部件边界的裁剪。例如，当应用程序在消息框关闭后删除它时，消息框的按钮和标签也会被删除，这正是我们期望的，因为按钮和标签是消息框的子对象。



You can also delete child objects yourself, and they will remove themselves from their parents. For example, when the user removes a toolbar it may lead to the application deleting one of its [QToolBar](../qtwidgets/qtoolbar.html) objects, in which case the tool bar's [QMainWindow](../qtwidgets/qmainwindow.html) parent would detect the change and reconfigure its screen space accordingly.

The debugging functions [QObject](qobject.html#dumpObjectTree)[::dumpObjectTree](qobject.html#dumpObjectTree)() and [QObject](qobject.html#dumpObjectInfo)[::dumpObjectInfo](qobject.html#dumpObjectInfo)() are often useful when an application looks or acts strangely. 



### 3、代码验证

1）添加一个C++类，看关闭窗体会不会自动销毁new开辟的内存

![image-20231214125351172](C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20231214125351172.png)

![image-20231214130202158](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214125510747.png)

![image-20231214130552450](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214130552450.png)

2）添加部分代码

qmyclass.h:

![image-20231214130713630](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214130713630.png)

qmyclass.cpp:

![image-20231214130813960](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214130813960.png)

![image-20231214131950813](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214131950813.png)

widget.cpp:

![image-20231214132112189](C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20231214132112189.png)

3)输出

![image-20231214132727772](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214132727772.png)

![image-20231214132613262](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214132613262.png)

### 4、QDebug

1）介绍

QDebug 是 Qt 框架提供的一个调试输出类，用于在调试过程中输出信息。它类似于 C++ 的 `std::cout` 或者 `printf`，但提供了更多的功能和灵活性。QDebug 可以输出各种数据类型，如字符串、整数、浮点数、对象等，并且可以方便地输出 Qt 特有的数据类型，比如 QString、QList 等。

![image-20231214131031084](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214131031084.png)



2）输出形式

![image-20231214131532399](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214131532399.png)



### 5、结论

窗体上只需new，而不用使用delete

1、析构函数会自动释放new开辟的内存空间，自动delete；

2、在这个窗体上开发的其他组件，析构函数会自动调用





## 7、视频07：信号与槽

### 1、概念

两者通过connect函数相关联

![image-20231214203033967](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214203033967.png)

![image-20231214203341183](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214203341183.png)

### 2、代码分析

1) widget.h文件：

这里的指针ui指向的是窗体Widget

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214204310212.png" alt="image-20231214204310212" style="zoom:50%;" />

2）widget.cpp文件

这里的connect对应connect函数的格式理解；

这里的函数都是系统自带的函数，已经封装实现。

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214205040413.png" alt="image-20231214205040413" style="zoom:50%;" />

那么，想要自定义信号和槽，用一个类的信号去触发另一个类的槽

3）在现有工程中添加一个类MyClass1，作为信号，并添加

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214205522880.png" alt="image-20231214205522880" style="zoom:50%;" />

有信号和槽，要加Q_OBJECT，自定义信号，只写原型，不写实现：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214214436427.png" alt="image-20231214214436427" style="zoom:50%;" />

4）在现有工程添加类：MyClass2，作为槽：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214214314753.png" alt="image-20231214214314753" style="zoom:50%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214214824875.png" alt="image-20231214214824875" style="zoom:50%;" />

槽需要定义函数的实现：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214215115788.png" alt="image-20231214215115788" style="zoom:50%;" />

实现两者的关联，仿照ui指针的写法：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214215311002.png" alt="image-20231214215311002" style="zoom:50%;" />

5）==问题==：实例化对象，链接信号与槽后，发现控制台没有输出，说明没有执行析构函数，说明没有执行第二个connect！

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214215743094.png" alt="image-20231214215743094" style="zoom:50%;" />

==原因==：因为没有触发信号，所以需要新增一按钮，点击一次触发一次信号

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214220325192.png" alt="image-20231214220325192" style="zoom:50%;" />

6）解决方案：设置按钮的触发形式为单击

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214220358165.png" alt="image-20231214220358165" style="zoom:50%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214220441986.png" alt="image-20231214220441986" style="zoom:50%;" />



6-1）添加后出现如图所示，自动出现按钮单击代码框架：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214220630081.png" alt="image-20231214220630081" style="zoom:50%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214220822487.png" alt="image-20231214220822487" style="zoom:50%;" />

6-2）添加代码作为验证按钮是否被单击，信号能否跳到这个槽：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214221110554.png" style="zoom:50%;" />



验证发现，控制台能够输出槽：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214221312825.png" alt="image-20231214221312825" style="zoom:50%;" />

7）想要显示点击的次数，修改部分代码：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214221527996.png" alt="image-20231214221527996" style="zoom:50%;" />



<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214221601148.png" alt="image-20231214221601148" style="zoom:50%;" />



<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214222149686.png" alt="image-20231214222149686" style="zoom:50%;" />



<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214221712075.png" alt="image-20231214221712075" style="zoom:50%;" />



<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214221740687.png" alt="image-20231214221740687" style="zoom:50%;" />

最终结果如图所示：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231214222910581.png" alt="image-20231214222910581" style="zoom:50%;" />



## 8、视频08：信号与槽补充

视频7所用的方法为：通过新增一个按钮，通过点击按钮，触发与之绑定的槽函数，槽函数中存有信号1的触发函数。进而触发MySlot槽。

即：按钮点击信号$\Rightarrow$按钮槽函数$\Rightarrow$信号1$\Rightarrow$槽（MySlot）



本届新介绍的一个方法：

​												信号1$\Rightarrow$信号2$\Rightarrow$槽

其中，信号1：按钮按下的那个信号。

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231216164523987.png" alt="image-20231216164523987" style="zoom:50%;" />

结果发现：应用程序有输出。



至此，信号1$\Rightarrow$信号2$\Rightarrow$槽的实现完成；接下来则是一个信号出发多个槽：例如：信号1触发槽1和槽2。

如下所示：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231216165404116.png" alt="image-20231216165404116" style="zoom:50%;" />



同样，还有取消两者的关联，例如：取消pushButton_3的关联

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231216165915959.png" alt="image-20231216165915959" style="zoom:50%;" />



## 9、视频09：QMainWindow菜单栏和工具栏

### 1、介绍

<img src="C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20231216173049549.png" alt="image-20231216173049549" style="zoom:50%;" />

QMainWindow框架：菜单栏、工具栏、悬浮窗口、中心部件和状态栏

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231216173154075.png" alt="image-20231216173154075" style="zoom:50%;" />

### 2、代码实现

这里采用纯代码实现

1)创建工程项目

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231216173814878.png" alt="image-20231216173814878" style="zoom:50%;" />

2）配置菜单栏

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231216192725508.png" alt="image-20231216192725508" style="zoom:50%;" />

3）配置工具栏

菜单栏只有一个，所以用setMenuBar，而工具栏可以有多个，所以用addToolBar

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231216193552747.png" alt="image-20231216193552747" style="zoom:50%;" />

4）分隔符设置

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231216194409756.png" alt="image-20231216194409756" style="zoom:50%;" />





## 10、视频10：QMainWindow状态栏\_停靠窗口\_中心组件

### 1、状态栏

头文件：

```
#include <QStatusBar>
#include <QLabel>
```

代码：

一般只有一个状态栏，所以用set

```c++
// QStatusBar 状态栏
    QStatusBar *stbar = new QStatusBar(this);
    setStatusBar(stbar);
    QLabel * label = new QLabel(this);
    label->setText("状态栏");
    stbar->addWidget(label);
```



### 2、浮动窗口

1、头文件：

```
#include <QDockWidget>
```

2、代码：

一般可以拥有多个中心组件，所以用add

```
// QDockWidget 浮动窗口
    //    QDockWidget *dockwidget = new QDockWidget(this);
    QDockWidget *dockwidget = new QDockWidget("小窗口",this); // 给停靠窗口加个名称

    // 放在中心部件的左(Left)/右(Right)/上(Top)/下(Buttom)位置，但是若没有中心部件则无论如何规划DockWidget的位置，都无法体现出方位
    addDockWidget(Qt::LeftDockWidgetArea, dockwidget);
```



### 3、中心组件

1、头文件：

```
#include <QTextEdit>
```

2、代码：

一般只有一个中心部件，所以用set

```
 // Central Widget 中心组件
    QTextEdit * edit = new QTextEdit(this);
    setCentralWidget(edit);
```





## 11、视频11：Ui方式创建QMainWindow_添加资源文件

### 1、Ui方式创建QMainWindow窗口

#### 1.1添加菜单栏

直接输入文字；

通过在文本框类似于（&F）的格式，直接绑定快捷键。

tips：如果输入不了中文，可在右侧绿色title处修改为中文

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231225215855352.png" alt="image-20231225215855352" style="zoom:50%;" />

![image-20231225220003650](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231225220003650.png)

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231225220519021.png" alt="image-20231225220519021" style="zoom:50%;" />

#### 1.2添加工具栏

右击MainWindow添加工具栏

![image-20231225220656054](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231225220656054.png)

如有需要，可以直接从下方拖拽相应部件加入工具栏：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231225220759945.png" alt="image-20231225220759945" style="zoom:60%;" />



#### 1.3浮动窗口

在左侧各种部件中加入Dock Widget（浮动窗口）

![image-20231225221031378](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231225221031378.png)

右下角的allowedAreas可以选择浮动窗口可以停靠的部位：

![image-20231225221057469](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231225221057469.png)

#### 1.4中心部件

同样在左侧选择中心部件为文本编辑，可以自由编辑大小

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231225221306553.png" alt="image-20231225221306553" style="zoom:60%;" />

#### 1.5运行效果图

运行后的界面如图所示：

![image-20231225221536575](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231225221536575.png)





### 2、添加资源文件

#### 2.1将相应图标文件加入源代码文件

​		这里的是Images

配置界面过程中，Ui界面可以看到图标，而运行起来没有相应图标；

一开始出现问题，Ui设计界面有图标，但运行后的界面没有图标显示：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231225222257338.png" alt="image-20231225222257338" style="zoom:50%;" />



<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231225222317493.png" alt="image-20231225222317493" style="zoom:50%;" />



#### 2.2解决措施

取消左侧项目栏中的Shadow build，但这会导致源码文件和编译文件混合在一起，这也就是Shadow build勾选的作用

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231225222508687.png" alt="image-20231225222508687" style="zoom:50%;" />



也可以采用不使用Ui界面设计，使用纯代码设计。

恢复刚开始的无图标Ui：删除该图标，可以选择最右侧的键位

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231225222739642.png" alt="image-20231225222739642" style="zoom:50%;" />



#### 2.3纯代码设计：

```c++
ui->action_N->setIcon(QIcon("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/08_QMainWindows_Ui/QMainWindows_Ui/Images/new.png"));
ui->action_O->setIcon(QIcon("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/08_QMainWindows_Ui/QMainWindows_Ui/Images/open.png"));
```

#### 2.4资源文件

但这个也带来问题，这段程序使用的照片是本电脑的路径，移植到另一台电脑则不会显示，因此需要使用资源文件这个方法

（1）新建源文件：

<img src="C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20231225225015708.png" alt="image-20231225225015708" style="zoom:50%;" />

（2）路径放在原代码中，命名为resource，会生成resource.qrc文件



（3）创建完毕之后，右击resource.qrc选择Open in Editor

<img src="C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20231225225138795.png" alt="image-20231225225138795" style="zoom:50%;" />

（4）添加前缀为/Image后，选择为此前缀添加文件：

<img src="C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20231225225351043.png" alt="image-20231225225351043" style="zoom:50%;" />



（5）修改相应代码：

```C++
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 可以用但也比较麻烦，换台电脑可能就实现不了，需要添加相应的资源文件
//    ui->action_N->setIcon(QIcon("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/08_QMainWindows_Ui/QMainWindows_Ui/Images/new.png"));
//    ui->action_O->setIcon(QIcon("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/08_QMainWindows_Ui/QMainWindows_Ui/Images/open.png"));

    //加载资源路径
    // 添加Qt资源文件是使用格式    "：+前缀+文件名"
    ui->action_N->setIcon(QIcon(":/Image/Images/new.png"));
    ui->action_O->setIcon(QIcon(":/Image/Images/open.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
```

（6）运行结果图

<img src="C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20231225230907457.png" alt="image-20231225230907457" style="zoom:50%;" />





## 12、视频12：模态和非模态对话框

### 1、Qt自带的标准对话框：

1. 颜色对话框
2. 文件对话框
3. 字体对话框
4. 输入对话框
5. 消息对话框
6. 进度对话框
7. 错误信息对话框
8. 向导对话框



### 2、模态和非模态对话框

模态对话框：在没有被关闭之前，用户不能与同一个应用程序的其他窗口进行交互，直到该对话框关闭。
非模态对话框：当被打开时，用户既可选择和该对话框进行交互，也可以选择同应用程序的其他窗口交互。

#### 2.1非模态对话框

代码：

```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDialog * dialog = new QDialog(this);
    dialog->resize(200, 100);
    dialog->show();     // 非模态对话框

    //加载资源路径
    // 添加Qt资源文件是使用格式    "：+前缀+文件名"
    ui->action_N->setIcon(QIcon(":/Image/Images/new.png"));
    ui->action_O->setIcon(QIcon(":/Image/Images/open.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
```

效果：可以在不关闭模态对话框的情况下，于mainWindow里编辑文字

![image-20231226113138419](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231226113138419.png)



####  2.2模态对话框

方式1：调用阻塞函数exec()，==关掉该窗口才会出现主窗口==。

```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDialog * dialog = new QDialog(this);
    dialog->resize(200, 100);
//    dialog->show();     // 非模态对话框

    dialog->exec(); // exec是一个阻塞函数，关掉该窗口才会出现主窗口 // 模态对话框 方式1

    //加载资源路径
    // 添加Qt资源文件是使用格式    "：+前缀+文件名"
    ui->action_N->setIcon(QIcon(":/Image/Images/new.png"));
    ui->action_O->setIcon(QIcon(":/Image/Images/open.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
```

方式2：==关掉该窗口才能在MainWindow里面编辑文字==

```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDialog * dialog = new QDialog(this);
    dialog->resize(200, 100);
//    dialog->show();     // 非模态对话框

//    dialog->exec(); // exec是一个阻塞函数，关掉该窗口才会出现主窗口 // 模态对话框 方式1

    dialog->setModal(true); // 模态对话框 方式2
    dialog->show();

    //加载资源路径
    // 添加Qt资源文件是使用格式    "：+前缀+文件名"
    ui->action_N->setIcon(QIcon(":/Image/Images/new.png"));
    ui->action_O->setIcon(QIcon(":/Image/Images/open.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
```

问题：new开辟的不需要显式的使用delete，因为窗口MainWindow一关闭就会自动调用相应的内存释放函数    但极端情况下，出现模态的模态的......，内存总会占满，此时只能等到最后一个窗口关闭才能释放内存，因此需要改进措施

解决措施：

```
dialog->setAttribute(Qt::WA_DeleteOnClose); // 只要模态窗口被关闭，就是释放内存
```





## 13、视频13：标准对话框_1

### 1、本节内容

共有四种文本框：

1. 颜色对话框
2. 文件对话框
3. 字体对话框
4. 输入对话框
5. 

### 2、Ui界面

建立在上一视频基础之上，设计如下图所示四个文本框：

<img src="C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20231226213005750.png" alt="image-20231226213005750" style="zoom:50%;" />

并将它们与槽关联，关联信号为单击。



### 3、颜色文本框

#### 3.1头文件

```
#include <QColorDialog> // 颜色对话框
```

#### 3.2代码

使用静态成员函数来实现，即通过类名来调用相关的函数，不用再费劲创建指针来调用相关函数。

```c++
void MainWindow::on_pushButton_clicked()
{
//    QColorDialog dialog(this);

//    换一种方式来实现
    QColor color = QColorDialog::getColor(Qt::red, this);
    qDebug() << "color: " << color;
}
```



### 4、文件对话框

#### 4.1头文件

```
#include <QFileDialog>
```

#### 4.2代码

```c++
void MainWindow::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File", "/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/10_Standard_dialog_1/QMainWindows_Ui");
    
    QString filename = QFileDialog::getOpenFileName(this, "Open File", "/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/10_Standard_dialog_1/QMainWindows_Ui", "图片文件(*.png *.jpg)");
    qDebug() << "filename: " << filename;
}
```

```
QFileDialog::getOpenFileName()
```

1. 参数1：父对象；
2. 参数2：对话框标题；
3. 参数3：具体地址；
4. 参数4：要检索的文件名称+文件格式

#### 4.3运行结果

![image-20231226215307662](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231226215307662.png)



### 5、字体对话框

#### 5.1头文件

```
#include <QFontDialog>
```

#### 5.2代码

```c++
void MainWindow::on_pushButton_3_clicked()
{
    bool ok;

    QFont font = QFontDialog::getFont(&ok, this);
    if(ok)
    {
        ui->pushButton_3->setFont(font);
    }
    else
    {
        qDebug() << "没有选择任何字体" << endl;
    }
}
```



#### 5.3运行结果

对比发现，字体按钮的文字发生改变。

![image-20231226215814457](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231226215814457.png)



<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231226215744061.png" alt="image-20231226215744061" style="zoom:50%;" />



### 6、输入对话框

#### 6.1头文件

```
#include <QInputDialog>
```

#### 6.2代码

```c++
void MainWindow::on_pushButton_4_clicked()
{
    bool ok;
    QString string = QInputDialog::getText(this, "输入字符串对话框", "请输入用户名", QLineEdit::Normal, "Hello world", &ok);
//    QLineEdit::Password 在输入密码时，显示的字符是平台依赖的密码掩码字符，而不是用户实际输入的字符
    if(ok)
        qDebug() << "string: " << string;

    int value = QInputDialog::getInt(this, "输入整数对话框", "请输入0～100的整数", 0, 0, 100, 1, &ok);
    if(ok)
        qDebug() << "Value = " << value;
}
```

函数1：

```
QInputDialog::getText()
```

1. 参数1：父对象
2. 参数2：对话框标题
3. 参数3：对话框标签
4. 参数4：对话框编辑格式分为四种QLineEdit::Normal、QLineEdit::NoEcho、QLineEdit::Password和QLineEdit::PasswordEchoOnEdit
5. 参数5：输入框内的默认字符串
6. 参数6：布尔值

函数2：

```
QInputDialog::getInt（）
```

1. 参数1：父对象
2. 参数2：对话框标题
3. 参数3：对话框标签
4. 参数4：输入框内的默认值
5. 参数5：输入框内的允许的最小值
6. 参数6：输入框内允许的最大值
7. 参数7：输入框内的数字步长
8. 参数8：布尔值

#### 6.3运行结果

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231226220506410.png" alt="image-20231226220506410" style="zoom:50%;" />

![image-20231226220545403](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231226220545403.png)



应用程序输出：

![image-20231226220447200](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231226220447200.png)





## 14、视频14：标准对话框_2

### 1、本节内容

1. 消息对话框
2. 进度对话框

### 2、消息对话框

#### 2.1头文件

```
#include <QMessageBox>
```

#### 2.2代码

对应运行结果各个参数的意思

```c++
void MainWindow::on_pushButton_5_clicked()
{
    // 问题对话框
    int ret1 = QMessageBox::question(this, "问题对话框", "你是否使用Qt", QMessageBox::Yes, QMessageBox::No);
    if(ret1 == QMessageBox::Yes)
        qDebug() << "Great";

    // 提示对话框
    QMessageBox::information(this, "提示对话框", "你最好使用Qt", QMessageBox::Ok);

    // 警告对话框
    QMessageBox::warning(this, "警告对话框", "请停止使用其他GUI", QMessageBox::Ok);

    // 错误对话框
    QMessageBox::critical(this, "错误对话框", "重大错误", QMessageBox::Retry);

    // 关于对话框
    QMessageBox::about(this, "关于对话框", "我爱Rick");

}
```

#### 2.3运行结果

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231227145730367.png" alt="image-20231227145730367" style="zoom:50%;" />



### 3、进度对话框

#### 3.1头文件

```
#include <QProgressDialog>
```

#### 3.2代码

```c++
void MainWindow::on_pushButton_6_clicked()
{
//    QProgressDialog * prodlg = new QProgressDialog(); // 指针存放在栈区，只要主窗口不关闭，随时可用
    QProgressDialog prodlg("复制内容", "取消", 0, 1000000, this); // 直接创建类对象，对象存放在堆，函数结束就会释放内存
    prodlg.setWindowTitle("复制文件");
    prodlg.setWindowModality(Qt::WindowModal); // 设置该进度窗口为模态，中途不可打断
    prodlg.show();

    for(int i = 0; i < 1000000; i++)
    {
        prodlg.setValue(i);

        QCoreApplication::processEvents();

        if(prodlg.wasCanceled())
            break;
    }
    prodlg.setValue(1000000); // 范围是0～49999，可能显示不了50000
    qDebug() << "拷贝完成";

}
```



```
QCoreApplication::processEvents()
```

目的是允许在进度对话框更新进度条的同时，也能够响应其他用户事件，以保持界面的交互性。



```
prodlg.setValue(i)
```

这个函数用于设置进度对话框中的进度值，即更新进度条的当前值。通过在循环中调用这个函数，并传递适当的值，可以实时更新进度条的状态，让用户了解到操作的进展情况。



#### 3.3运行结果

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231227151058531.png" alt="image-20231227151058531" style="zoom:50%;" />





## 15、视频15：标准对话框_3

### 1、本节概要

1. 错误消息对话框
2. 向导对话框



### 2、错误对话框

#### 2.1头文件

```
#include <QErrorMessage>
```

#### 2.2代码

```c++
// 错误信息对话框(经常用消息对话框显示)
void MainWindow::on_pushButton_7_clicked()
{
//    QErrorMessage errordlg(this);
//    问题1：即便勾选了don't show again，下次还会再次显现出来，因为重新开始是一个新的对象
//    解决1：开辟一个内存空间，创建一个变量，共用该变量

//    但问题2：每点一次按钮，也会new新开辟一段内存
//    QErrorMessage * errordlg = new QErrorMessage(this);
//    解决2：将 QErrorMessage * errordlg = new QErrorMessage(this); 放在主窗口里面

//    但问题3：本函数想要使用的errordlg变量却在主窗口函数里面，MainWindow函数结束后，该变量便失去了作用,其他函数不能够调用本函数
//    解决3：定义为全局变量，将新建的变量放在类里面，在MainWindow函数里面分配内存，在槽函数里面进行具体操作
    errordlg->setWindowTitle("错误");
    errordlg->showMessage("危险");
    errordlg->exec();
}
```

#### 2.3运行结果

问题1：即使去掉了勾选Show this message again，下面界面关掉重新打开之后，依旧会自动被重新勾选

<img src="C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20231227172706120.png" alt="image-20231227172706120" style="zoom:50%;" />

改正后的结果：取消勾选之后重新运行也不会再被勾选。

### 3、向导对话框

#### 3.1头文件

```
#include <QWizard>
```

#### 3.2代码

```c++
//向导对话框

QWizardPage* createPage1(void)
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("第一步操作");
    return page;
}

QWizardPage* createPage2(void)
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("第二步操作");
    return page;
}

void MainWindow::on_pushButton_8_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle("向导对话框");
    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.exec();
}
```

#### 3.3运行结果

![image-20231227173055846](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231227173055846.png)

![image-20231227173147834](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231227173147834.png)





## 16、视频16：按钮控件组

### 1、Tool Button

#### 1.1 介绍

用于工具栏、工具箱或其他工具集的小部件，它可以显示文本、图像或两者结合。

#### 1.2 测试案例

1、插入Tool Button按钮

![image-20231228211507491](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228211507491.png)

2、插入资源文件小悟空照片

<img src="C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20231228211835749.png" alt="image-20231228211835749" style="zoom:50%;" />

![image-20231228211858648](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228211858648.png)

右击resources.qrc选择Open in Editor，添加前缀、添加文件：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228211941483.png" alt="image-20231228211941483" style="zoom:50%;" />

![image-20231228212035271](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228212035271.png)

添加资源文件：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228212206344.png" alt="image-20231228212206344" style="zoom:50%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228212324630.png" alt="image-20231228212324630" style="zoom:50%;" />

一个突出对比度，一个使文字和图片同时出现：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228214720737.png" alt="image-20231228214720737" style="zoom:50%;" />

3、运行结果示意图

![image-20231228214754960](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228214754960.png)



### 2、RadioButton

#### 2.1 介绍

QRadioButton 用于创建单选按钮。多个单选按钮可以分组在一起，形成一个单选按钮组。

#### 2.2 测试案例

1、插入按钮Radio Button

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228215055937.png" alt="image-20231228215055937" style="zoom:50%;" />

2、但一开始没有选择默认按钮，如下代码，默认选择按钮2：

```
ui->radioButton_2->setChecked(true);
```

3、运行结果

![image-20231228215528379](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228215528379.png)

4、但是多添加了一组成绩按钮，发现点击成绩栏后，原先默认选择的二年级按钮不再显示选中：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228215843603.png" alt="image-20231228215843603" style="zoom:50%;" />

5、使用Group Box解决，但注意是将Tool Button移入Group Box，而不是简单用Group Box包住所有Tool Button，结果如下：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228220227428.png" alt="image-20231228220227428" style="zoom:50%;" />

6、设计一个提示框，当分数低于60时，输出：失败

如图所示，使用connect函数连接：

<img src="C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20231228230955292.png" alt="image-20231228230955292" style="zoom:67%;" />

7、创建一个类：MyClass，并添加槽函数：void MySlot(void)

<img src="C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20231228231947997.png" alt="image-20231228231947997" style="zoom:67%;" />

8、connect函数

```
connect(senderObject, &SenderClass::signalName, receiverObject, &ReceiverClass::slotName);
```

- `senderObject`：是发送信号的对象，即 `ui->radioButton_5`，一个 `QRadioButton` 实例。
- `SenderClass::signalName`：代表信号的名称和类型。这里使用了新的信号与槽语法，使用 `&QRadioButton::clicked` 表示 `QRadioButton` 类的 `clicked` 信号。
- `receiverObject`：接收信号的对象，即 `mc`，一个 `MyClass` 实例。
- `ReceiverClass::slotName`：槽函数的名称。在这里，`&MyClass::MySlot` 是 `MyClass` 类中的名为 `MySlot` 的槽函数。



例子：

```
connect(ui->radioButton_5, &QRadioButton::clicked, mc, &MyClass::MySlot);
```

9、运行结果

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228234504820.png" alt="image-20231228234504820" style="zoom:67%;" />

### 3、Check Box

#### 3.1 介绍

在Qt中，QCheckBox是一个复选框部件，允许用户在两种状态之间切换，通常用于启用或禁用一个选项。

#### 3.2 测试案例

1、插入按钮check box，并选择三模态按钮：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228233116488.png" alt="image-20231228233116488" style="zoom:67%;" />

2、运行结果

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231228233326148.png" alt="image-20231228233326148" style="zoom:67%;" />





## 17、视频17：List Widget控件

### 1、介绍

在Qt中，List Widget是一个用于显示和管理项目列表的组件。它允许你以列表的形式显示项目，并且可以对这些项目进行操作和管理。List Widget提供了一个灵活的界面，可以用来展示文本、图像等项目，并支持用户交互。

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231229112501607.png" alt="image-20231229112501607" style="zoom: 67%;" />

### 2、代码

```c++
ui->listWidget->addItem("Hello world");
ui->listWidget->addItem("good morning");

QListWidgetItem * listitem = new QListWidgetItem("I love you, Rick!");
ui->listWidget->addItem(listitem);
listitem->setTextAlignment(Qt::AlignHCenter); // 居中显示

QStringList list2; // 字符串容器
list2 << "ABCD" << "EFGH" << "IJKL" << "LMNO";
ui->listWidget_2->addItems(list2);
```

### 3、运行结果

![image-20231229112631204](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20231229112631204.png)





## 18、视频18：Tree Widget控件

### 1、介绍

Tree widget控件通常用于在用户界面中==显示层次结构数据==，类似于==树状图==。它允许用户展开和折叠节点，以便查看和管理复杂的数据结构。

### 2、代码

```c++
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QStringList list; // 创建一个对象
//    list << "Name" << "Address";
//    ui->treeWidget->setHeaderLabels(list); // 添加一级分支

    ui->treeWidget->setHeaderLabels(QStringList() << "Name" << "Address"); // 使用构造函数创建出一个匿名的对象

    QTreeWidgetItem * treeitem1 = new QTreeWidgetItem(QStringList("Bookmarks Toolbar"));
    ui->treeWidget->addTopLevelItem(treeitem1);
    QTreeWidgetItem * treeitem2 = new QTreeWidgetItem(QStringList("Bookmarks Menu"));
    ui->treeWidget->addTopLevelItem(treeitem2);

    treeitem1->setIcon(0, QIcon(":/Image/Images/folder.png")); // 列数从第0列开始
    treeitem2->setIcon(0, QIcon(":/Image/Images/folder.png"));

    QTreeWidgetItem * childitem1 = new QTreeWidgetItem(QStringList() << "QWidget" << "Page10");
    treeitem1->addChild(childitem1);

    QTreeWidgetItem * childitem2 = new QTreeWidgetItem(QStringList() << "QMainWindow" << "Page20");
    treeitem1->addChild(childitem2);

    QTreeWidgetItem * childitem3 = new QTreeWidgetItem(QStringList() << "QPushButton" << "Page30");
    treeitem2->addChild(childitem3);

    QTreeWidgetItem * childitem4 = new QTreeWidgetItem(QStringList() << "QLabel" << "Page40");
    treeitem2->addChild(childitem4);
}

Widget::~Widget()
{
    delete ui;
}
```

### 3、运行结果

![image-20240101170325814](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240101170325814.png)

### 4、具体步骤

4.1	Ui界面添加Tree Widget

在ui界面添加相应的Tree Widget

![image-20240101170716690](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240101170716690.png)



4.2	双击该控件添加相应的内容

列为标签，项目为该列下的一级标题：

![image-20240101170933546](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240101170933546.png)



4.3	运行结果如图所示

![image-20240101171132149](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240101171132149.png)



4.4	代码实现Tree Widget

方法1：创建QStringList类的对象（list），QStringList 是 Qt 框架中常用的数据类型，用于存储字符串列表。它是 QString 类的一个特殊容器，能够有效地管理和操作字符串列表。

![image-20240101172005169](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240101172005169.png)



方法2：使用流操作符赋值

使用了 C++ 中的流操作符 `<<` 来向 `QStringList` 中添加元素。在这个上下文中，`QStringList() << "Name" << "Address"` 使用了流式操作符 `<<` 将字符串 "Name" 和 "Address" 依次添加到 `QStringList` ，结果如下所示，在Name列下添加两项：Bookmarks Toolbar、Bookmarks Menu

![image-20240101173413434](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240101173413434.png)



4.5	在标签前添加图标

列数从第0列开始，如下图所示：

![image-20240101174415119](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240101174415119.png)



4.6	给一级分支下添加二级分支

![image-20240101175302147](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240101175302147.png)





##  19、视频19：Table Widget控件

### 1、介绍

QTableWidget 是 Qt 框架提供的一个用于显示和编辑表格数据的控件。它是基于 QTableView 的高级封装，提供了更简单的接口和功能。

### 2、代码

```c++
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(3);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Sex" << "Age");

    //ui->tableWidget->setItem(0, 0, new QTableWidgetItem("Rick")); // 逐行添加太过麻烦

    QStringList NameList;
    NameList << "Rick" << "Jack" << "Nichael";

    QStringList SexList;
    SexList << "Male" << "Male" << "Male";

    QStringList AgeList;
    AgeList << "Rick" << "Jack" << "Nichael";


    for(int row = 0; row < 3; row++)
    {
        int col = 0;
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem(NameList[row]));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem(SexList[row]));
        ui->tableWidget->setItem(row, col, new QTableWidgetItem(QString::number(20))); // int --> string，单纯int类型在里面是
    }
}

Widget::~Widget()
{
    delete ui;
}
```

3、运行结果

![image-20240102124640735](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102124640735.png)

### 4、具体步骤

4.1	在Ui界面添加相应控件，设置Table的 行数与列数，并添加各自标题

![image-20240102130032065](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102130032065.png)



4.2	在第一行第一列添加姓名

注意是从0开始计数，但这样计算效率太低：

![image-20240102130808488](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102130808488.png)



4.3	另一种添加信息的方式

![image-20240102131526641](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102131526641.png)



4.4	使用循环与字符串列表填充表格信息

```
QTableWidgetItem(QString::number(20))
// 不能直接填写整形数据，里面对整型数据的定义是type，使用相应的函数将整型转为字符串类型
```

9![image-20240102132149716](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102132149716.png)





## 20、视频20：Containers控件

### 1、Group Box控件

视频16的按钮控件组第三个控件Check Box已经介绍过

### 2、Scroll Area控件

#### 2.1	简介

在Qt中，QScrollArea是用于显示超出可视区域的内容的小部件。它允许用户在一个小部件中查看另一个小部件的全部内容，并通过滚动条来滚动显示区域。

#### 2.2	具体介绍

如图所示，可以选择垂直排列或水平排列

![image-20240102211424781](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102211424781.png)

#### 2.3	运行结果

![image-20240102211625836](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102211625836.png)



### 3、Tool Box控件

#### 3.1	简介

在Qt中，QToolBox是一个可以容纳多个可折叠项（可折叠小部件）的容器部件。它通常用于创建具有多个页面或选项卡的用户界面，允许用户在其中选择并显示不同的内容或工具。

#### 3.2	具体介绍

插入页：

![image-20240102211723468](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102211723468.png)

修改当前项的标签名：

![image-20240102212347588](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102212347588.png)

#### 3.3	运行结果

![image-20240102212415816](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102212415816.png)



### 4、Tab Widget控件

#### 4.1	简介

在Qt中，QTabWidget是一个用于创建具有选项卡式界面的小部件。它允许用户在同一区域中查看和切换多个相关页面或面板，每个页面都与选项卡关联。

#### 4.2	具体介绍

插入页的操作和Tool Box操作一样

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102213656826.png" alt="image-20240102213656826" style="zoom:67%;" />

#### 4.3	运行结果

![image-20240102213642221](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102213642221.png)



### 5、Stacked Widget控件

#### 5.1	简介

在Qt中，QStackedWidget是一个小部件容器，可以同时容纳多个子部件，但只显示其中一个子部件。它类似于QTabWidget，但不使用选项卡切换，而是使用索引来管理和显示子部件。

#### 5.2	具体介绍

1、通过右上角的符号可以切换当前界面：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102214106171.png" alt="image-20240102214106171" style="zoom: 67%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102214120196.png" style="zoom: 67%;" />

2、但是程序运行却没有可以切换的按钮

<img src="C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20240102214323594.png" alt="image-20240102214323594" style="zoom:50%;" />

3、解决方法：刚才的是编辑界面，因此在程序运行后无法切换屏幕。于是设计三个按钮，点击不同而按钮从而切换到不同的界面，如图所示并修改按键文本名称和对象名称；以此类推。

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102214810942.png" alt="image-20240102214810942" style="zoom:50%;" />

4、测试功能，C++11的标准

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102215408458.png" alt="image-20240102215408458" style="zoom:50%;" />

5、正式构建两者的连接

发现可以通过点击不同的按钮跳到不同的界面：

```c++
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    // 一开始弹出默认的界面
    ui->stackedWidget->setCurrentIndex(2);

//    connect(ui->pB_ScrollArea, &QPushButton::clicked, this, [](){qDebug() << "Hello World!";});
//这段代码使用了 C++11 中的 Lambda 表达式。在这里，[](){qDebug() << "Hello World!";} 是一个匿名函数，也称为 Lambda 函数。
//Lambda 表达式的一般结构是 [] (parameters) -> return_type { body }，在这个例子中，它没有参数和返回值，所以[]()是一个空的参数列表，qDebug() << "Hello World!";是函数体。

    connect(ui->pB_ScrollArea, &QPushButton::clicked, this, [&](){ui->stackedWidget->setCurrentIndex(0);});
    connect(ui->pB_ToolBox, &QPushButton::clicked, this, [&](){ui->stackedWidget->setCurrentIndex(1);});
    connect(ui->pB_TabWidget, &QPushButton::clicked, this, [&](){ui->stackedWidget->setCurrentIndex(2);});
        
//	& 表示通过引用捕获外部变量，这里意味着 Lambda 函数可以访问并修改当前作用域（可能是该类的成员函数）中的所有变量。=y
//	() 是空的参数列表，表示这个 Lambda 函数不接受任何参数。
//	{} 中是函数体，包含了要执行的操作：ui->stackedWidget->setCurrentIndex(1); 这行代码用于将 QStackedWidget 中当前显示的页面设置为索引为 1 的页面（通常是第二个页面，索引从 0 开始计数）。

}

Widget::~Widget()
{
    delete ui;
}
```





<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240102215714927.png" alt="image-20240102215714927" style="zoom:50%;" />

6、设置一开始弹出的默认界面

```c++
    // 一开始弹出默认的界面
    ui->stackedWidget->setCurrentIndex(2);
```





## 21、视频21：Input Widget控件

### 1、Combo Box

Ui界面：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240103211754770.png" style="zoom:80%;" />

添加下拉菜单选项：

<img src="C:\Users\yin\AppData\Roaming\Typora\typora-user-images\image-20240103212028301.png" alt="image-20240103212028301" style="zoom:67%;" />

### 2、Font Combo Box

Ui界面介绍：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240103212157150.png" style="zoom:60%;" />

设想：下拉菜单中选择字体，点击确认健，标签页中的字体会发生相应的改变：

![image-20240103213224862](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240103213224862.png)

```c++
connect(ui->pushButton, &QPushButton::clicked, this, [&](){ui->label->setFont(ui->fontComboBox->currentFont());});
```

运行结果：

![image-20240103213751454](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240103213751454.png)

### 3、Time Edit和Date/Time Edit

Ui界面介绍：

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240103213948722.png" style="zoom:80%;" />

```c++
QDateTime curDateTime = QDateTime::currentDateTime(); // curDateTime里面既有日期也有时间
ui->timeEdit->setTime(curDateTime.time()); // 单独列出时间
ui->dateTimeEdit->setDateTime(curDateTime);
```

运行结果;

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240103214437272.png" style="zoom:67%;" />





## 22、视频22：自定义控件

1、新建Qt设计师界面类

（==此处应该是类名为My_Custom_Controller，这里打成了My_CUstom_Widget，导致后面类名不一致，他两实际上是同一个东西==）

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104121915779.png" alt="image-20240104121915779" style="zoom:80%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104122058344.png" alt="image-20240104122058344" style="zoom:80%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104122148081.png" alt="image-20240104122148081" style="zoom:80%;" />

2、编辑my_custom_widget.ui界面

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104122500225.png" alt="image-20240104122500225" style="zoom:80%;" />

3、在widget.ui界面里面新建Widget

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104122806680.png" alt="image-20240104122806680" style="zoom:80%;" />

4、将自定义的my_custom_widget.ui界面与widget.ui界面相关联

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104122947917.png" alt="image-20240104122947917" style="zoom:80%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104123029340.png" alt="image-20240104123029340" style="zoom:80%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104123108239.png" alt="image-20240104123108239" style="zoom:80%;" />

5、运行当前程序，发现自定义的my_custom_widget.ui界面相关内容已经在widget.ui界面里面显现，但此时两个控件是独立的，两者互不影响。

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104123311601.png" alt="image-20240104123311601" style="zoom: 67%;" />



6、使用connect函数，用spinBox控制horizontalSlider，如下图所示，使用assistant帮助手册来寻找信号Signals的函数表现形式，得到如下两个形式，仔细观察发现是重载函数，暂不确定选择哪一个，继续connect函数的填写

```c++
void valueChanged(const QString &text)
void valueChanged(int i)
```

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104124314512.png" alt="image-20240104124314512" style="zoom: 50%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104124418302.png" alt="image-20240104124418302" style="zoom:50%;" />

7、继续填写connect函数，寻找ui->horizontalSlider对应的槽函数（slot），搜索了HorizontalSlider和QHorizontalSlider，都没有发现有这个类，于是尝试寻找QSlider类，发现存在该类，但在Contents中并未找到Slots，于是从基类QAbstractSlider中寻找。

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104125047330.png" alt="image-20240104125047330" style="zoom: 67%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104125113616.png" alt="image-20240104125113616" style="zoom:67%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104125228411.png" alt="image-20240104125228411" style="zoom: 50%;" />

8、在QAbstractSlider类中找到了Public Slots，有如下图所示几个函数，结合QSpinBox类中的valueChanged()函数，最终选择void setValue\(int\)，并反推QSpinBox的信号重载函数选择：void valueChanged(int i)

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104125620006.png" alt="image-20240104125620006" style="zoom:67%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104125713522.png" alt="image-20240104125713522" style="zoom:67%;" />

9、QSlider类是QAbstractSlider类的派生类，所以可以继承其公有函数setValue，又因为取函数的地址只要函数名即可，不能添加具体重载函数区分，因此创建函数指针sbp来代替

```c++
void (QSpinBox:: *sbp)(int) = &QSpinBox::valueChanged;
connect(ui->spinBox, sbp, ui->horizontalSlider, &QSlider::setValue);
```

10、运行结果如图所示，可以通过调节spinBox来调整horizontalSlider，但反过来仍不行，因为还没有构建两者的连接（即配置connect函数）

![image-20240104131304979](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104131304979.png)

11、如图所示，horizontalSlider的valueChanged函数并没有重载，故可以直接用常规方法使用，QSpinBox的Slots函数同理。

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104131206457.png" alt="image-20240104131206457" style="zoom: 50%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104131638977.png" alt="image-20240104131638977" style="zoom:67%;" />

12、运行结果如图所示

![image-20240104131857396](E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104131857396.png)

13、新想法：将当前的数值输出，设想：通过点击按钮，输出当前的数值结果到控制台

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104132108128.png" alt="image-20240104132108128" style="zoom:67%;" />

14、在my_custom_controller类中声明并添加函数定义（==自这里起，已将my_custom_widget全部替换为my_custom_controller==）

```c++
// 函数声明
int get_Current_Value();    

// 函数定义
int My_Custom_Controller::get_Current_Value()
{
    return ui->spinBox->value();
}
```

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104132529154.png" alt="image-20240104132529154" style="zoom: 67%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104132549190.png" alt="image-20240104132549190" style="zoom: 67%;" />

15、使用connect函数设置Ui界面的按钮（这里的按钮是在widget.ui界面添加的，因此要在widget.cpp文件里面实现）

**==Tip==**：这里的widget是一个小控件，小写的widget，而不是代表整个界面的大写Widget，如图所示，当初第3步，将my_custom_controller.ui界面作为一个widget.ui界面的一个控件Widget插入，其objectName也是小写的widget，所以==代码输出的是小写widget的当前值，若是大写的则报错==。

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104133232238.png" alt="image-20240104133232238" style="zoom:67%;" />

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104133403366.png" alt="image-20240104133403366" style="zoom: 50%;" />

16、运行结果：如图所示，应用程序有相应的正确输出

<img src="E:\2笔记\1-Notes\Qt\Qt笔记\图片\image-20240104134100919.png" alt="image-20240104134100919" style="zoom:67%;" />





## 23、视频23：Label控件

### 1、简介

在Qt中，QLabel 是用于显示文本或图像的控件。它是Qt中常用的部件之一，可以用来展示静态文本、HTML文本或者图像。QLabel 可以包含丰富的文本格式和样式，也支持基本的图像显示。

### 2、文本展示

<img src="Qt笔记.assets/image-20240104203239237.png" alt="image-20240104203239237" style="zoom:67%;" />

### 3、图像展示

#### 3.1	加载资源文件

#### 3.2	插入静态图片并自动调整图片大小

```c++
ui->label_2->setPixmap(QPixmap(":/Image/Image/1.jpeg")); // 插入图片
ui->label_2->setScaledContents(true);
```

<img src="Qt笔记.assets/image-20240104204257307.png" alt="image-20240104204257307" style="zoom:67%;" />



#### 3.3	插入动态GIF图片并自动调整图片大小

```
ui->label_3->setPixmap(QPixmap(":/Image/Image/2.gif"));
ui->label_3->setScaledContents(true);
```

但是最终结果显示的是静态图片，要想显示GIF：

```c++
QMovie *mv = new QMovie(":/Image/Image/2.gif");
ui->label_3->setMovie(mv); // 插入动图GIF
ui->label_3->setScaledContents(true); // 改变动图大小
mv->start(); // 显示GIF
```

![](Qt笔记.assets/视频22动图.gif)





## 24、视频24：Qt事件处理——鼠标事件_1

应用程序（QApplication）对象（a）中的exec()函数检测是否有事件发生，一有事件发生，Qt会使用应用程序对象调用notify()函数，将事件发到指定的窗口中去。

捕获事件是否产生、触发，可在其中设置事件过滤、时间分发和事件处理 

事件过滤：QObject里面的eventFilter()函数

事件分发：QWidget里面的事件分发器Events有具体分类，分发给对应的事件处理函数 

事件处理：处理相应事件（可以给相应函数重新定义）（==唯一关注点==）

==只需要修改相应的事件处理函数==

### 1、widget.h文件

```c++
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
```

### 2、widget.cpp文件

```c++
#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug() << "Left Button is pressed.";
//        qDebug() << "x = " << event->x() << ", y = " << event->y(); // 在当前界面的局部位置
        qDebug() << "x = " << event->globalX() << ", y = " << event->globalY(); // 全局位置

    }
    else if(Qt::RightButton)
    {
        qDebug() << "Right Button is pressed.";
        qDebug() << "x = " << event->x() << ", y = " << event->y();
    }
}
```

### 3、运行结果

![](Qt笔记.assets/image-20240105162313004-17044429941472.png)





## 25、视频25：Qt事件处理——鼠标事件_2

### 1、概要

- 自定义鼠标释放事件

- 鼠标双击事件

- 鼠标移动事件

- 鼠标滚轮事件

    

### 2、自定义鼠标释放事件

QWidget下的Events

2.1	头文件

```c++
void mouseReleaseEvent(QMouseEvent *event);
```

2.2	源文件

```c++
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Button is released";
}
```

2.3	运行结果

![image-20240108170700494](Qt笔记.assets/image-20240108170700494-17047048219011.png)



### 3、鼠标双击事件

QWidget 下的Events

3.1	头文件

```c++
void mouseDoubleClickEvent(QMouseEvent *event);
```

3.3	源文件

```c++
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Button is released";
}


void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(windowState() != Qt::WindowFullScreen)
        {
            setWindowState(Qt::WindowFullScreen);
        }
        else
        {
            setWindowState(Qt::WindowNoState);
        }
    }
}
```



### 4、鼠标移动事件

4.1	头文件

```c++
//添加私有变量
QPoint pos;


void mouseMoveEvent(QMouseEvent *event);
```

4.2	源文件

```c++
void Widget::mouseMoveEvent(QMouseEvent *event) // 在窗体范围内，一点一拖动，窗体出现在鼠标点击的位置
{
    if(event->buttons() & Qt::LeftButton) // Button和Buttons的区别
    {
        QPoint temp;

        temp = event->globalPos() - pos; // 鼠标当前的位置 - 当前窗体的位置 = 移动了多少

        move(temp);
    }
}
```



### 5、鼠标滚轮事件

5.1	头文件

```c++
void wheelEvent(QWheelEvent *event);
```

5.2	源文件

```c++
void Widget::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0)
    {
        ui->textEdit->zoomIn(); // 上滚变大
    }
    else
        ui->textEdit->zoomOut(); // 下滚变小
}
```





## 26、视频26：定时器

### 1、方法1

1.1	头文件

```c++
#include <QTimer>
```

1.2	源文件

```c++
#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 方法一：
    QTimer * timer = new QTimer(this);
    timer->start(1000);
    connect(timer, &QTimer::timeout, [&](){
        static int num = 1; // 如果不是static静态类型，那么会一直初始化 num 为1
        ui->label->setText(QString::number(num++)); // QString 里面的方法，将数字转换成字符串
    });
}

Widget::~Widget()
{
    delete ui;
}
```



### 2、方法2

2.1	简介	

使用timerEvent事件处理函数来处理定时器事件

2.2	头文件

```c++
void timerEvent(QTimerEvent *event);
```

2.3	源文件

```c++
#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 方法1
    QTimer * timer = new QTimer(this);
    timer->start(1000);
    connect(timer, &QTimer::timeout, [&](){
        static int num = 1;
        ui->label->setText(QString::number(num++));
    });

    // 方法2
    startTimer(500);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::timerEvent(QTimerEvent *event)
{
    static int num = 1;
    ui->label_2->setText(QString::number(num++));
}
```

2.4	问题

方法一可以通过创建多个指针来实现多个定时器，但目前的方法二不可以

2.5	解决措施

startTimer原型：

```c++
int QObject::startTimer(int *interval*, [Qt::TimerType](qt.html#TimerType-enum) *timerType* = Qt::CoarseTimer)
```

2.6	头文件

添加了两个私有成员变量：timer_id1,timer_id2

==tips:在类中定义过就不用在主函数再次定义了，只需要赋值。==

如下述，会引发冲突！

```c++
//类中定义
int timer_id1;
int timer_id2;

//函数中定义
timer_id1 = startTimer(500); // 参数1：定时周期500ms
timer_id2 = startTimer(2000);
```

```c++
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    // 重载定时器事件处理函数
    void timerEvent(QTimerEvent *event);

private:
    Ui::Widget *ui;
    int timer_id1;
    int timer_id2;
};
#endif // WIDGET_H

```

2.7	源文件

```c++
#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 方法一：
    QTimer * timer = new QTimer(this);
    timer->start(1000);
    connect(timer, &QTimer::timeout, [&](){
        static int num = 1; // 如果不是static静态类型，那么会一直初始化 num 为1
        ui->label->setText(QString::number(num++)); // QString 里面的方法，将数字转换成字符串
    });

    // 方法二：
    timer_id1 = startTimer(500); // 参数1：定时周期500ms
    timer_id2 = startTimer(2000);

    // 使用timer_id1, timer_id2进行区分，

}

Widget::~Widget()
{
    delete ui;
}


void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == timer_id1) // 因为该函数中得不到WIdget函数中局部变量的值，所以将该函数的值放在类的成员中
    {
        static int num = 1;
        ui->label_2->setText(QString::number(num++));
    }
    if(event->timerId() == timer_id2)
    {
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }

}

```



2.8	运行结果：

![image-20240109133835822](Qt笔记.assets/image-20240109133835822-17047787169482.png)

2.9	补充

给文本框添加边框以达到区分效果。

![image-20240109133641705](Qt笔记.assets/image-20240109133641705-17047786036951.png)

### 3、结论

==两种方法更推荐方法一！！！==





## 27、视频27：事件分发器

借助的之前所讲的Mouse事件

1、头文件

```c++
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    bool event(QEvent *event); // 添加函数，位于 QWidget 中 Reimplemented Protected Functions 的 virtual bool event(QEvent *event) override

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    Ui::Widget *ui;
    QPoint pos;
};
#endif // WIDGET_H
```

2、源文件

第一个`return true;`的作用是告诉程序该事件已经在这个函数中被处理了，不需要再传递给其他地方处理；而第二个`return QWidget::event(event);`的作用是将其他类型的事件传递给父类的事件处理函数，以便父类处理那些没有在这个函数中被处理的事件。

```c++
#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


bool Widget::event(QEvent *event) // 之前的鼠标功能全部失效
{
    if(event->type() == QEvent::MouseButtonPress) // 设置鼠标被按下时的操作，下方的全部被打断
    {
        qDebug() << "鼠标按键被按下";
        return true;
    }
    return QWidget::event(event); // 其余事件交给父类事件分发函数处理
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug() << "Left Button is pressed.";
//        qDebug() << "x = " << event->x() << ", y = " << event->y(); // 在当前界面的局部位置
        qDebug() << "x = " << event->globalX() << ", y = " << event->globalY(); // 全局位置

    }
    else if(Qt::RightButton)
    {
        qDebug() << "Right Button is pressed.";
        qDebug() << "x = " << event->x() << ", y = " << event->y();
    }
}


void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Button is released";
}


void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(windowState() != Qt::WindowFullScreen)
        {
            setWindowState(Qt::WindowFullScreen);
        }
        else
        {
            setWindowState(Qt::WindowNoState);
        }
    }
}


void Widget::mouseMoveEvent(QMouseEvent *event) // 在窗体范围内，一点一拖动，窗体出现在鼠标点击的位置
{
    if(event->buttons() & Qt::LeftButton) // Button和Buttons的区别
    {
        QPoint temp;

        temp = event->globalPos() - pos; // 鼠标当前的位置 - 当前窗体的位置 = 移动了多少

        move(temp);
    }
}


void Widget::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0)
    {
        ui->textEdit->zoomIn(); // 上滚变大
    }
    else
        ui->textEdit->zoomOut(); // 下滚变小
}
```





## 28、视频28：串口调试助手项目_01：自动识别串口号

### 1、项目需求

希望创建一个串口调试助手项目，要求能够显示当前的已接串口端口号。

![image-20240113201032988](Qt笔记.assets/image-20240113201032988-17051478340011.png)

### 2、具体步骤

#### 2.1	前期准备

运行窗口大小显示、窗口标题显示

```c++
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(800, 600);
    setWindowTitle("串口调试助手");
    
}

Widget::~Widget()
{
    delete ui;
}
```

运行结果如图所示：

![image-20240113201436537](Qt笔记.assets/image-20240113201436537-17051480778942.png)



#### 2.2	定时器

需要不断扫描是否接入了外部设备，这就需要定时不断扫描接入状态。

1、创建定时器变量

```c++
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>   // 1

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QTimer * timer;     // 2
};
#endif // WIDGET_H
```



2、创建自定义定时器处理函数

头文件：

```c++
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>  

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QTimer * timer; 
    
private slots:
    void TimerEvent_1();	// 3
};
#endif // WIDGET_H
```

源文件：

```c++
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(800, 600);
    setWindowTitle("串口调试助手");

    timer = new QTimer(this);	// 1
    timer->start(500);	//	2
    connect(timer, &QTimer::timeout, this, &Widget::TimerEvent_1);	//	3
}

Widget::~Widget()
{
    delete ui;
}


void Widget::TimerEvent_1()
{

}
```



3、添加串口头文件并添加依赖

添加头文件：

```c++
#include <QSerialPortInfo>
#include <QSerialPort>
```



添加依赖：

![image-20240113203638362](Qt笔记.assets/image-20240113203638362.png)



4、使用foreach函数遍历已有串口

```c++
foreach (variable, container) 
```



5、QSerialPortInfo和QSerialPort的区别

5.1	QSerialPortInfo:

- **作用：** 提供关于系统中可用串口的信息。
- **功能：** 允许你获取有关每个可用串口的详细信息，如串口名、描述、制造商、支持的波特率等。
- **用途：** 主要用于列举系统中的串口，以便用户可以选择要与之通信的串口。

```c++
#include <QtSerialPort/QSerialPortInfo>
```

5.2	QSerialPort:

- **作用：** 提供串口的访问和控制。
- **功能：** 允许打开、关闭串口，设置串口参数（如波特率、数据位、停止位、校验位等），读写串口数据等。
- **用途：** 用于实际的串口通信，发送和接收数据。

```c++
#include <QtSerialPort/QSerialPort>
```

5.3	**简要区别：**

- `QSerialPortInfo` 主要用于获取系统中可用串口的信息，而 `QSerialPort` 用于实际的串口通信。
- `QSerialPortInfo` 是一个用于检测串口的工具类，而 `QSerialPort` 是一个用于串口通信的类。

在使用串口进行通信时，通常的做法是使用 `QSerialPortInfo` 枚举可用串口，然后用户选择一个串口，最后使用 `QSerialPort` 打开选定的串口进行通信。



6、文件汇总内容

头文件

```c++
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QSerialPortInfo>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    

private:
    Ui::Widget *ui;
    QTimer * timer;
    QStringList portStringList; // 1

private slots:
    void TimerEvent_1();
};
#endif // WIDGET_H
```



源文件：

```c++
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(800, 600);
    setWindowTitle("串口调试助手");

    timer = new QTimer(this);
    timer->start(500);
    connect(timer, &QTimer::timeout, this, &Widget::TimerEvent_1);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::TimerEvent_1()
{
    
    QStringList newPortStringList;

    newPortStringList.clear(); // 4 清空操作，否则每次都在增加

    foreach (const QSerialPortInfo & info, QSerialPortInfo::availablePorts()) {
        newPortStringList += info.portName();
    }

    if(newPortStringList.size() != portStringList.size()) // 1 如果不加该判断，会每0.5秒加入所有串口，而没有清空之前语句
    {
        portStringList = newPortStringList; // 2 更新当前容器
        ui->comboBox->clear();  // 3 清空
        ui->comboBox->addItems(newPortStringList);
    }
}
```



### 3、运行结果

![image-20240113204325807](Qt笔记.assets/image-20240113204325807-17051498068163.png)





## 29、视频29：串口调试助手项目_02：设置串口参数

### 1、项目需求

在串口调试助手项目的基础上，要求能够显示当前的已接串口端口号。

可以设置串口调试助手的参数并打开串口

### 2、具体步骤

2.1	设置 Ui 界面

![image-20240115143606238](Qt笔记.assets/image-20240115143606238-17053005672741.png)



2.2	创建QSerialPort类指针

用于用于设置和控制串口的各种属性，以及执行串口的打开和关闭操作

Qt助手中搜索：QSerialPort，查看Public Functions函数

2.3	设置各个参数

1、判断是否点击“打开串口”



2、串口名设置

```c++
serial->setPortName(ui->comboBox->currentText());
```



3、波特率设置

```c++
serial->setBaudRate(ui->comboBox_2->currentText().toInt());
```

setBaudRate()函数接收qint32类型数据，而comBox里面是QString类型的，需要转换成int类型，故使用 toInt()函数。



4、数据位设置

```c++
switch(ui->comboBox_3->currentText().toInt())
{
	case 5: serial->setDataBits(QSerialPort::Data5); break;
	case 6: serial->setDataBits(QSerialPort::Data6); break;
	case 7: serial->setDataBits(QSerialPort::Data7); break;
	case 8: serial->setDataBits(QSerialPort::Data8); break;
	default: serial->setDataBits(QSerialPort::UnknownDataBits); break;   
}
```



5、校验位设置

```c++
switch(ui->comboBox_4->currentIndex())
{
	case 0: serial->setParity(QSerialPort::EvenParity); break;
	case 1: serial->setParity(QSerialPort::OddParity); break;
	case 2: serial->setParity(QSerialPort::NoParity); break;
	default: serial->setParity(QSerialPort::UnknownParity); break;
}
```



6、停止位

```c++
// 停止位
switch(ui->comboBox_5->currentIndex())
{
	case 0: serial->setStopBits(QSerialPort::OneStop); break;
	case 1: serial->setStopBits(QSerialPort::OneAndHalfStop); break;
	case 2: serial->setStopBits(QSerialPort::TwoStop); break;
	default: serial->setStopBits(QSerialPort::UnknownStopBits); break;    
}
```



7、流控

在串口通信中，流控（Flow Control）是一种用于控制数据流动的机制。设置流控的作用是定义在何时发送数据以及何时停止发送数据，以防止数据溢出或丢失。在你提到的代码中，设置流控为 `QSerialPort::NoFlowControl` 表示禁用流控。

```c++
serial->setFlowControl(QSerialPort::NoFlowControl);
```



8、设置未成功打开提示

```c++
if(!serial->open(QIODevice::ReadWrite)) // 未成功打开
{
	QMessageBox::information(this, "错误提示", "无法打开串口", QMessageBox::Ok);
	return ;
}
```



9、设置使能端

按照逻辑，当选好相应的端口时，便不再允许调用参数。

```c++
ui->comboBox->setEnabled(false);
ui->comboBox_2->setEnabled(false);
ui->comboBox_3->setEnabled(false);
ui->comboBox_4->setEnabled(false);
ui->comboBox_5->setEnabled(false);
```



10、关闭串口并重新设置使能端



### 3、currentText与currentIndex区别

1. **`currentText`:**

    - `currentText` 是 `QComboBox` 类的成员函数，返回当前选择项的文本内容（字符串）。
    - 例如，如果你有一个下拉框（`QComboBox`）并选择了其中的一个项，使用 `currentText` 可以获取该项的文本。

    ```c++
    QString text = ui->comboBox->currentText();
    ```

2. **`currentIndex`:**

    - `currentIndex` 是 `QComboBox` 类的成员函数，返回当前选择项的索引。
    - 例如，如果你有一个下拉框（`QComboBox`）并选择了其中的一个项，使用 `currentIndex` 可以获取该项在下拉框中的索引。

    ```c++
    int index = ui->comboBox->currentIndex();
    ```

关系：

- `currentText` ==返回当前选定项的文本==，是一个 `QString` 类型。
- `currentIndex` ==返回当前选定项的索引==，是一个 `int` 类型。

你可以根据需要选择使用其中一个或两者结合使用，具体取决于你对选择项的需求。如果你需要文本内容，使用 `currentText`；如果你需要索引，使用 `currentIndex`。

例如本项目中的数据位与校验位，数据位都是 QString 类型的数字，可以通过 toInt() 函数转换；而校验位虽然也是 QString 类型，但都是英文字母，因此需要按照索引来使用 switch() 函数。

![image-20240115171352351](Qt笔记.assets/image-20240115171352351-17053100337132.png)

![image-20240115171447718](Qt笔记.assets/image-20240115171447718-17053100886313.png)

![image-20240115171602498](Qt笔记.assets/image-20240115171602498-17053101636464.png)





## 30、视频30：串口调试助手项目_03：接收功能

### 1、项目需求

在串口调试助手项目的基础上，要求能够显示当前的已接串口端口号。可以设置串口调试助手的参数并打开串口。

新增：能够实现串口的接收功能

### 2、具体操作

2.1、创建串口相关的信号与槽

```c++
void serialPort_readyRead();
connect(serial, &QSerialPort::readyRead, this, &Widget::serialPort_readyRead);
```

==信号readyRead为从QSerialPort类的父类QIODevice Class中继承而来。==

测试槽函数：

```c++
void Widget::serialPort_readyRead()
{
    qDebug() << "Receive data.";
}
```

如下图所示，串口读取正常！

<img src="Qt笔记.assets/image-20240117194820318-17054921014151.png" alt="image-20240117194820318" style="zoom:80%;" />

2.2、CheckBox的设置

如下图所示，要求：有且只有一个可以被选中：

![image-20240117195453531](Qt笔记.assets/image-20240117195453531-17054924954642.png)

在widget.ui界面直接设置对应的槽函数，并编写槽函数相关内容：

调用QCheckBox类中的void setCheckState(Qt::CheckState *state*)函数

```c++
void Widget::on_checkBox_clicked()
{
    ui->checkBox->setCheckState(Qt::Checked);
    ui->checkBox_2->setCheckState(Qt::Unchecked);
    ui->checkBox_3->setCheckState(Qt::Unchecked);
}

void Widget::on_checkBox_2_clicked()
{
    ui->checkBox_2->setCheckState(Qt::Checked);
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->checkBox_3->setCheckState(Qt::Unchecked);
}

void Widget::on_checkBox_3_clicked()
{
    ui->checkBox_3->setCheckState(Qt::Checked);
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->checkBox_2->setCheckState(Qt::Unchecked);
}
```

如图所示：只能勾选Hex、ASCII和暂停三个其中的一个。

![image-20240117204019715](Qt笔记.assets/image-20240117204019715-17054952208783.png)



2.3	设置 CheckBox 暂停框的功能

```c++
void Widget::serialPort_readyRead()
{
//    qDebug() << "Receive data.";
    if(ui->checkBox_3->checkState() != Qt::Checked)
    {
            qDebug() << "Receive data.";

    }
}
```

输出如下：

![image-20240117205916122](Qt笔记.assets/image-20240117205916122-17054963570004.png)



2.4	读取串口发送的数据

QByteArray readAll()函数继承自 QSerialPort类的父类QIODevice类；

QByteArray 字节数组类型，与QString类型一致。

```c++
QString Receivetext; // 表示收到的内容
long Receive_Byte; // 接收的Receivetext的长度

void Widget::serialPort_readyRead()
{
//    qDebug() << "Receive data.";
    if(ui->checkBox_3->checkState() != Qt::Checked)
    {
//        qDebug() << "Receive data.";
        Receivetext = serial->readAll(); // 读取串口数据
        Receive_Byte = Receivetext.length(); // 计算读取串口数据的长度
        ui->label_11->setText(QString::number(Receive_Byte)); // 输出 读取数据的长度
        ui->textEdit->setText(Receivetext); // 
    }
}
```

如下图所示：接收数据框输出：please enter the words，接收字节：24

![image-20240117211852688](Qt笔记.assets/image-20240117211852688-17054975336185.png)



问题：只输出当前的最新数据，没有输出历史数据；只输出当前数据的长度，没有输出总共数据长度。



2.5	显示历史数据和总计输出数据长度

```c++
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(800, 600);
    setWindowTitle("串口调试助手");

    timer = new QTimer(this);
    timer->start(500);
    connect(timer, &QTimer::timeout, this, &Widget::TimerEvent_1);

    serial = new QSerialPort(this);

    ui->comboBox_2->setCurrentIndex(5);
    ui->comboBox_3->setCurrentIndex(3);
    ui->comboBox_4->setCurrentIndex(2);
    ui->comboBox_5->setCurrentIndex(0);

    Receive_Byte = 0; // 6 清零z
    connect(serial, &QSerialPort::readyRead, this, &Widget::serialPort_readyRead);

}


void Widget::serialPort_readyRead()
{
    QString last_text; // 1 存放历史数据

//    qDebug() << "Receive data.";
    if(ui->checkBox_3->checkState() != Qt::Checked)
    {
//        qDebug() << "Receive data.";
        last_text = ui->textEdit->toPlainText(); // 3 读取历史数据

        Receivetext = serial->readAll(); 
        Receive_Byte += Receivetext.length(); // 2 计算累计接收字符串长度
        ui->label_11->setText(QString::number(Receive_Byte));

        last_text = last_text.append(Receivetext); // 5
        ui->textEdit->setText(last_text); // 4
    }
}
```

如图所示输出结果：

接收数据区域在不停输出数据（包含历史数据）；接收字节长度在不断累加。

![image-20240117213653771](Qt笔记.assets/image-20240117213653771-17054986156236.png)



2.6 分Hex和ASCII两种输出方式

```c++
void Widget::serialPort_readyRead()
{
    QString last_text; // 1 存放历史数据
    int length; // 9
    int i; // 10

//    qDebug() << "Receive data.";
    if(ui->checkBox_3->checkState() != Qt::Checked)
    {
//        qDebug() << "Receive data.";
        last_text = ui->textEdit->toPlainText(); // 3 读取历史数据

        Receivetext = serial->readAll(); //
        Receive_Byte += Receivetext.length(); // 2 计算累计接收字符串长度
        ui->label_11->setText(QString::number(Receive_Byte));

        if(ui->checkBox->checkState() == Qt::Checked) // 7 hex
        {
            Receivetext = Receivetext.toLatin1().toHex(); // 8 拉丁字母输出转换成 16 进制
            length = Receivetext.length(); // 11
            for(i = 0; i < length / 2; i++) // 12 每两个字节插入一个空格
            {
                Receivetext.insert(2+3*i, ' ');
            }
        }
        else
        {
            Receivetext = Receivetext.toLatin1(); // 13拉丁字母输出
        }
        last_text = last_text.append(Receivetext); // 5 更新历史数据
        ui->textEdit->setText(last_text); // 4 输出历史数据
    }
}
```

如图所示：16进制每隔两个字节输出一个空格

![image-20240117220103959](Qt笔记.assets/image-20240117220103959-17055000652069.png)

ASCII码形式输出字符串形式：

![image-20240117220254352](Qt笔记.assets/image-20240117220254352-170550017540210.png)





## 31、视频31：串口调试助手项目_04：发送功能

### 1、项目需求

在串口调试助手项目的基础上，要求能够显示当前的已接串口端口号。可以设置串口调试助手的参数并打开串口。能够实现串口的接收功能。

新增：实现发送功能

### 2、具体操作

2.1	设置widget.ui界面

![image-20240118113830339](Qt笔记.assets/image-20240118113830339-17055491113101.png)

2.2	获得textEdit_2里面的内容

```c++
QString Sendtext; // 发送的内容

void Widget::on_pushButton_2_clicked()
{
    Sendtext = ui->textEdit_2->toPlainText(); 
    
}
```



2.3	写入串口

serial->write();的数据类型是QByteArray类型，而 Sendtext 是 QString 类型，因此需要将 QString 转换为 QByteArray 类型

```c++
void Widget::on_pushButton_2_clicked()
{
    QByteArray bytearray;
    
    Sendtext = ui->textEdit_2->toPlainText(); 
    
    bytearray = Sendtext.toLatin1();
    
    serial->write(bytearray);
}
```



2.4	计算长度

```c++
// 头文件中
long Send_Byte; // 接收的 Send_Byte 的长度    

// widget构造函数中
Send_Byte = 0;


void Widget::on_pushButton_2_clicked()
{
    QByteArray bytearray;
    
    Sendtext = ui->textEdit_2->toPlainText(); 
    
    bytearray = Sendtext.toLatin1();
    
    serial->write(bytearray);
    
    Send_Byte += Sendtext.length();
    
    ui->label_12->setText(QString::number(Send_Byte));
    
}
```

如下图所示：字节数在增加，但由于此时开发板没有接受处理程序，故没有相应。

![image-20240118115640386](Qt笔记.assets/image-20240118115640386-17055502014022.png)



2.5	清空接收区和发送区

```c++
void Widget::on_pushButton_3_clicked()
{
    ui->textEdit->clear();
}

void Widget::on_pushButton_4_clicked()
{
    ui->textEdit_2->clear();
}
```





## 32、视频32：绘图基本操作

### 1、简介

都是由创建的QPainter类对象来实现最终的显示操作。

### 2、具体代码

```c++
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPen pen(QColor (255, 0, 0)); // 创建了红色画笔对象
    pen.setWidth(3); // 设置画笔宽度为3个像素
    pen.setStyle(Qt::DashDotLine); // 设置画笔样式为虚线点线。
    painter.setPen(pen);    // 将上述配置好的画笔对象设置给painter


    painter.drawLine(QPoint (0, 0), QPoint (100, 100)); // 创建匿名对象；两个参数表示直线的起始位置；线
    painter.drawEllipse(QPoint (100, 100), 20, 20); // 圆形
    painter.drawEllipse(QPoint (100, 100), 50, 80); // 椭圆
    painter.drawRect(100, 100, 30, 30); // 正方形
    painter.drawRect(100, 100, 40, 80); // 长方形
    painter.drawText(100, 100, "I love you, Rick!"); // 显示文本


    QBrush brush(Qt::green, Qt::Dense3Pattern);
    painter.setBrush(brush);
//    painter.setPen(pen);
    painter.drawRect(200, 200, 50, 50);


    QConicalGradient conicalGradient(QPointF(200, 100), 0); // 渐变色 // 参数2：从该角度逆时针开始;这里指从三点钟方向开始
    conicalGradient.setColorAt(0.2, Qt::cyan); // 参数1：0～1，360度*0.2 = 72度，意思从0度开始，逆时针旋转72度
    conicalGradient.setColorAt(0.4, Qt::black);
    conicalGradient.setColorAt(0.7, Qt::red);
    conicalGradient.setColorAt(1, Qt::yellow);

    painter.setBrush(conicalGradient); // 不能使用上一个画刷，上一个画刷全是绿色
    painter.drawEllipse(QPointF(200, 100), 50, 50);
}
```





## 33、视频33：抗锯齿和坐标系变换

### 1、平移

```c++
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // 1.抗锯齿：边缘平滑 Antialiasing，translate
//    QPen pen(QColor(255, 0, 0));
    painter.setPen(QPen(Qt::red, 15));
    painter.drawEllipse(QPoint(200, 150), 100, 100);

    painter.setRenderHints(QPainter::Antialiasing); // 抗锯齿操作
    painter.translate(200, 0); // 偏移
    painter.drawEllipse(QPoint(200, 150), 100, 100); 
}
```

<img src="Qt笔记.assets/image-20240119160217481.png" alt="image-20240119160217481" style="zoom:80%;" />



### 2、旋转

```c++
// 2.旋转 rotate
painter.setPen(QPen(Qt::red, 10));
painter.drawLine(QPoint(10, 10), QPoint(100, 100));
painter.save(); // 保存一下当前的设置
painter.translate(200, 0);
painter.rotate(90); // 顺时针旋转90度
painter.setPen(QPen(Qt::blue, 10));
painter.drawLine(QPoint(10, 10), QPoint(100, 100));
painter.restore(); // 恢复到之前的状态
```

<img src="Qt笔记.assets/image-20240119160842436.png" alt="image-20240119160842436" style="zoom:80%;" />



### 3、缩放

```c++
// 3.缩放 scale
painter.setPen(QPen(Qt::red));
painter.setBrush(Qt::yellow);
painter.drawRect(50, 50, 50, 50);
painter.save();
painter.scale(1.5, 2);
painter.setBrush(Qt::green);
painter.drawRect(50, 50, 50, 50);
painter.restore();
```

<img src="Qt笔记.assets/image-20240119161430125.png" alt="image-20240119161430125" style="zoom:80%;" />



### 4、扭曲

```c++
    // 4.扭曲 shear
    painter.setPen(QPen(Qt::blue));
    painter.setBrush(Qt::yellow);
    painter.drawRect(50, 50, 50, 50);
    painter.save();
    painter.shear(0.5, 0); // 左上角 50*1.5 = 75， 右下角 100*1.5 = 150
    painter.setBrush(Qt::gray);
    painter.drawRect(50, 50, 50, 50);
    painter.restore();
```

<img src="Qt笔记.assets/image-20240119162049179.png" alt="image-20240119162049179" style="zoom:80%;" />





## 34、视频34：手动调用绘图事件处理函数

### 1、实现目的

手动调用绘图事件

### 2、具体步骤

2.1、前期准备

头文件公有成员

```c++
void paintEvent(QPaintEvent *);
```

源文件包含头文件

```c++
#include <QPainter>
```



2.2	绘制一个始终位于界面中心的圆

```c++
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this); 
    painter.setRenderHints(QPainter::Antialiasing); // 抗锯齿
    painter.translate(width()/2, height()/2); //  使坐标中心位于整个界面的中心，无论如何放大/缩小界面
    painter.drawEllipse(QPoint(0, 0), 120, 120); // 半径为120
}
```

运行结果：

<img src="Qt笔记.assets/image-20240119204040137.png" alt="image-20240119204040137" style="zoom:80%;" />



2.3 设置旋转角度

头文件私有变量

```c++
int angle;
```

源文件Widget构造函数：

```
angle = 0; // 角度初始化
```

```c++
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing); // 抗锯齿
    painter.translate(width()/2, height()/2); //  使坐标中心位于整个界面的中心，无论如何放大/缩小界面
    painter.drawEllipse(QPoint(0, 0), 120, 120); //
    painter.rotate(angle); // 旋转
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));
}
```



2.4	设置角度变化

```c++
void Widget::paintEvent(QPaintEvent *)
{
    angle += 10;
    if(angle == 360)
        angle =0;
    
    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing); // 抗锯齿
    painter.translate(width()/2, height()/2); //  使坐标中心位于整个界面的中心，无论如何放大/缩小界面
    painter.drawEllipse(QPoint(0, 0), 120, 120); //
    painter.rotate(angle); // 旋转
    painter.drawLine(QPoint(0, 0), QPoint(100, 0));
}
```

但没有连续变化，如下图，与上图对比，只变化一次，因此设计一个定时器来实现连续变化

![image-20240119205041540](Qt笔记.assets/image-20240119205041540-17056686425502.png)



2.5	设置定时器

```c++
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    angle = 0;
    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer, &QTimer::timeout, this, [&](){update();});
}
```

为什么不使用repaint()函数

重新调用 paintEvent() 以直接重新绘制小部件，除非禁用更新或小部件被隐藏。 我们建议只在需要立即重新绘制的情况下使用 repaint()，例如在动画期间。在几乎所有情况下，update() 更好，因为它允许Qt进行速度优化并最小化闪烁。 警告：如果在可能被从 paintEvent() 中调用的函数中调用 repaint()，可能会导致无限递归。update() 函数永远不会引起递归。

### 3、运行结果

![](Qt笔记.assets/笔记34.gif)





## 35、视频35：绘制文字和路径

### 1、本节内容

### 2、具体步骤

2.1	前期准备

头文件：

```c++
void paintEvent(QPaintEvent *);
```

源文件：

```c++
#include <QPainter>
void Widget::paintEvent(QPaintEvent *)
{    
}
```



2.2	具体代码

```c++
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QFont font("Noto Sans CJK SC Black", 20, QFont::Bold, true); // 设置字体类型、大小、黑体、斜体
//    QFont font("Courier 10 Pitch", 50, QFont::Bold, true);

    font.setUnderline(true); // 设置下划线

    painter.setFont(font); // 设置画笔
    painter.setPen(Qt::blue); // 设置画笔颜色
    painter.drawText(50, 50, "I love you, Rick!");
}

```



2.3	运行结果

<img src="Qt笔记.assets/image-20240120155321033.png" alt="image-20240120155321033" style="zoom:80%;" />



2.4	QPainterPath

QPainterPath 是  Qt  框架中的一个类，用于描述和操作 2D 图形路径。它提供了一种方便的方式来创建和管理路径，这些路径可以用于绘制、剪切和其他图形操作。

类似于容器，存储的当前的绘画设置。

```c++
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPainterPath path;

    path.moveTo(50, 250);
    path.lineTo(50, 200);
    path.lineTo(100, 100);
    path.addEllipse(QPoint(100, 100), 30, 30);
    painter.setPen(Qt::red);
    painter.drawPath(path);

    path.translate(200, 0);
    painter.setPen(Qt::blue);
    painter.drawPath(path);
}
```

### 3、运行结果 

![image-20240120161411208](Qt笔记.assets/image-20240120161411208-17057384521032.png)





## 36、视频36：绘图设备QPixmap_QImage

QWidget

QPixmap：图片类，主要用于显示图片，对于图片的显示做了优化处理，和平台有关。

QImage：图片类，图片不依赖于平台，多用于图片的传输，可以做像素级的修改。

QBitmap

QPicture

### 1、QPixmap

```c++
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    // 绘图设备 QPixmap
    QPixmap pix(400, 300); // 设置图像像素 400 * 300
    pix.fill(Qt::white); // 背景颜色设置，默认黑色
    QPainter painter(&pix); 
    
}

Widget::~Widget()
{
    delete ui;
}
```



```
QPainter painter(&pix); 
```

原型：QPainter::QPainter([QPaintDevice](qpaintdevice.html) **device*)，其中 QPaintDevice 可以是以下类型：

![image-20240122170231501](Qt笔记.assets/image-20240122170231501-17059141526161.png)

之前在Widget的构造函数中使用this，使之运行后可以在widget界面显示 。



运行结果：

![image-20240122171233381](Qt笔记.assets/image-20240122171233381-17059147549592.png)



### 2、QImage

```c++
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QImage
    QImage img(400, 300, QImage::Format_RGB32);
    img.fill(Qt::white);
    QPainter painter(&img);
    painter.setPen(Qt::red);
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    img.save("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test33/Pix_Image/Image/myImage.jpg");
}

Widget::~Widget()
{
    delete ui;
}
```

运行结果如下：

<img src="Qt笔记.assets/image-20240122182828890.png" alt="image-20240122182828890" style="zoom: 67%;" />



2.2	像素修改

1、导入资源图片擎天柱

![image-20240122183622986](Qt笔记.assets/image-20240122183622986-17059197841225.png)

2、事件处理函数

```c++
void paintEvent(QPaintEvent *event);
```

```c++
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QImage img;
    img.load("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test33/Pix_Image/Image/optimus prime.jpeg");
    for(int i = 50; i < 100; i++) // 50 * 50 的红方格
    {
        for(int j = 50; j < 100; j++)
        {
            QRgb rgb = qRgb(255, 0, 0);
            img.setPixel(i, j, rgb);
        }
    }
    
    painter.drawImage(0, 0, img);
}
```

 运行结果如下：

![image-20240122185316641](Qt笔记.assets/image-20240122185316641-17059207978366.png)





## 37、视频37：绘图设备QPicture和QBitmap

### 1、QPicture

QPicture 可以理解为是一个绘图的容器，里面保存有绘图的记录和重绘制的指令；存储的形式是二进制形式，也就是说我们无法双击打开 picture 文件。

1.1	头文件

```
#include <QPicture>
#include <QPainter>
```

1.2	代码文件

```c++
#include "widget.h"
#include "ui_widget.h"
#include <QPicture>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPicture pic;
//    QPainter painter(&pic); // 形式1
    QPainter painter;   // 形式2
    painter.begin(&pic); // 形式2
    
    painter.setPen(Qt::red);
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    painter.end();
    pic.save("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test34/QPicture_QBitmap/Image/pic.jpg");
}

Widget::~Widget()
{
    delete ui;
}
```

1.3	painter.end() 函数

end() 的调用确实与 QPicture 有关，因为它涉及到将绘图结果保存到  QPicture  中。这种方式使得你可以在需要的时候使用 QPicture 对象进行重绘，而不必再次执行相同的绘图操作。

如果没有painter.end()这一句，则不会有图片生成



1.4	加载已经存储的图像

```c++
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPicture pic;
    // 加载图片
    pic.load("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test34/QPicture_QBitmap/Image/pic.jpg");
    painter.drawPicture(0, 0, pic);
}
```

1.5	运行结果

<img src="Qt笔记.assets/image-20240122213114723.png" alt="image-20240122213114723" style="zoom:67%;" />



### 2、QBitmap

==QBitmap 绘制出来的是黑白的==

2.1	头文件：

```c++
#include <QBitmap>
```

2.2	代码文件

```c++
// QBitmap 绘制出来的是黑白的
    QBitmap bm(400, 300);
    QPainter painter(&bm);
    painter.setPen(Qt::red);
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    bm.save("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test34/QPicture_QBitmap/Image/bm.jpg");
```

2.3	运行结果

<img src="Qt笔记.assets/image-20240122212217412.png" alt="image-20240122212217412" style="zoom: 50%;" />

2.4	用QBitmap查看彩色图像

```c++
void Widget::paintEvent(QPaintEvent *)
{
    // QBitmap 打开彩色图片
    QPainter painter(this);
    QBitmap bm;
    // 加载图片
    bm.load("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test34/QPicture_QBitmap/Image/bm.jpg");
    painter.drawPixmap(0, 0, bm);
}
```

2.5	运行结果

![image-20240122213809223](Qt笔记.assets/image-20240122213809223-17059306905243.png)





## 38、绘制弧线

### 1、本节内容

绘制一个半圆形图形。

### 2、具体步骤

2.1	前期准备

```c++
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(1600, 900); // 原型this->resize(),但在widget构造函数里面，因此省略了this
    this->setStyleSheet("background-color: black"); // 背景全黑
}
```



2.2	重写事件处理函数

```c++
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;

    pen.setColor(Qt::green);
    painter.setPen(pen);

    painter.drawArc(25, 25, 1550, 1550, 0 * 16, 180 * 16); // 参数5以 1/16 度为单位，参数为16，意味着16 * (1/16) = 1度 // y
    painter.drawArc(180, 180, 1240, 1240, 0 * 16, 180 * 16);
    painter.drawArc(335, 335, 930, 930, 0 * 16, 180 * 16);
    painter.drawArc(490, 490, 620, 620, 0 * 16, 180 * 16);
    painter.drawArc(645, 645, 310, 310, 0 * 16, 180 * 16);
}
```



```
void QPainter::drawArc(int *x*, int *y*, int *width*, int *height*, int *startAngle*, int *spanAngle*)
```

绘制由矩形定义的弧，该矩形始于 (x, y)，具有指定的宽度和高度，以及给定的 startAngle 和 spanAngle。

- 
- 参数5以 1/16 度为单位，参数为16，意味着16 * (1/16) = 1度



![](Qt笔记.assets/屏幕截图 2024-01-23 131129-17059870104522.png)

第一个drawArc计算如下图所示：

![image-20240123131804638](Qt笔记.assets/image-20240123131804638-17059870866033.png)

### 3、运行结果：

![image-20240123130705270](Qt笔记.assets/image-20240123130705270-17059864265911.png)





## 39、超声波雷达项目界面设计_01雷达主界面

### 1、本节内容

以上节视频的绘制曲线界面为背景，绘制雷达界面

### 2、具体步骤

2.1	全部代码

```c++
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QtMath>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(1600, 900); // 原型this->resize(),但在widget构造函数里面，因此省略了this
    this->setStyleSheet("background-color: black"); // 背景全黑

}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;

    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿


    pen.setColor(Qt::green);
    painter.setPen(pen);

    painter.drawArc(100, 100, 1400, 1400, 0 * 16, 180 * 16); // 参数5以 1/16 度为单位，参数为16，意味着16 * (1/16) = 1度
    painter.drawArc(240, 240, 1120, 1120, 0 * 16, 180 * 16);
    painter.drawArc(380, 380, 840, 840, 0 * 16, 180 * 16);
    painter.drawArc(520, 520, 560, 560, 0 * 16, 180 * 16);
    painter.drawArc(660, 660, 280, 280, 0 * 16, 180 * 16);

    // 底部画一道线    
    painter.drawLine(0, 800, 1600, 800);

    // 每隔30度画一道线
    painter.save(); // 保存一下坐标系：原坐标系
    painter.translate(800, 800);

    for(int i = 0; i < 5; i++)
    {
        painter.rotate(-30); // 旋转坐标系30度，相对于原坐标系逆时针旋转30度
        painter.drawLine(0, 0, 720, 0);
    }
    painter.restore(); // 恢复到原坐标系

    painter.save();
    QFont font("Courier 10 Pitch", 30, QFont::Bold, true);
    painter.setFont(font);
    painter.setPen(Qt::green);
    painter.translate(800, 800); // 平移当前坐标系原点

    painter.drawText(720, 0, "0°");

    // 角度刻度
    // x = 720 * cos30, y = 720 * sin30
    painter.drawText(720 * qCos(qDegreesToRadians(30.0)), 720 * qSin(qDegreesToRadians(-30.0)), "30°"); // 坐标原点的右下方才是x正和y正
    painter.drawText(720 * qCos(qDegreesToRadians(60.0)), 720 * qSin(qDegreesToRadians(-60.0)), "60°");
    painter.drawText(720 * qCos(qDegreesToRadians(90.0))-20, 720 * qSin(qDegreesToRadians(-90.0)), "90°");
    painter.drawText(720 * qCos(qDegreesToRadians(120.0))-40, 720 * qSin(qDegreesToRadians(-120.0)), "120°");
    painter.drawText(720 * qCos(qDegreesToRadians(150.0))-80, 720 * qSin(qDegreesToRadians(-150.0)), "150°");
    painter.drawText(720 * qCos(qDegreesToRadians(180.0))-80, 720 * qSin(qDegreesToRadians(-180.0)), "180°");

    // 距离刻度
    painter.drawText(140, 30, "10cm");
    painter.drawText(280, 30, "20cm");
    painter.drawText(420, 30, "30cm");
    painter.drawText(560, 30, "40cm");
    painter.drawText(700, 30, "50cm");

}
```



2.2	Qt中 sin 和 cos 的函数使用

1. 头文件

    ```
    #include <QtMath>
    ```

2. 两个函数原型

[q](qtglobal.html#qreal-typedef)real qSin([qreal](qtglobal.html#qreal-typedef) *v*)

[q](qtglobal.html#qreal-typedef)real qCos([qreal](qtglobal.html#qreal-typedef) *v*)

这里的角度 v 使用的是==弧度制==！

但是 该头文件中同样提供了 qDegreesToRadians(float *degrees*)  来将角度转换为弧度制



### 3、运行结果

![image-20240123220307043](Qt笔记.assets/image-20240123220307043-17060185883851.png)





## 40、超声波雷达项目界面设计_02：绘制扫描效果

### 1、本节内容

在上一节的基础上，增加了动态扫描效果。

### 2、具体步骤

2.1	构建一条扫描线线段

```c++
// 扫描线段
pen.setWidth(12);
painter.setPen(pen);
painter.save();
painter.translate(800, 800);
int x = int(700 * qCos(qDegreesToRadians(angle)));
int y = int(-700 * qSin(qDegreesToRadians(angle)));
painter.drawLine(0, 0, x, y);
```

运行结果如图所示：

<img src="Qt笔记.assets/image-20240124171127710.png" alt="image-20240124171127710" style="zoom:80%;" />



2.2	线段旋转

头文件：

```c++
public slots:
    void timerTimeout();

private:
    Ui::Widget *ui;
    double angle = 0.0;
    int flag = 0;
```

源文件：

```c++
// 定时器实现线段旋转
QTimer * timer = new QTimer(this);
timer->start(20);
connect(timer, &QTimer::timeout, this, &Widget::timerTimeout);
```

```c++
void Widget::timerTimeout()
{
//    qDebug() << "hello world!";
    if(flag == 0)
    {
        angle++;
        if(angle == 180.0)
            flag = 1;
    }
    else
    {
        angle--;
        if(angle == 0)
            flag = 0;
    }

    update(); // 刷新串口部件
}
```

效果如下：

![](Qt笔记.assets/雷达界面.gif)



2.3	拖影（余影）设置

```c++
    // 添加余影/拖影
    double d_angle = angle;
    if(flag == 0)
    {
        for(int num = 1; num <= d_angle; num++)
        {
            painter.setOpacity(1 - num * 1.0 / ((d_angle > 30.0) ? 30.0 : d_angle));
            x = int(700 * qCos(qDegreesToRadians(d_angle - num)));
            y = int(-700 * qSin(qDegreesToRadians(d_angle - num)));
            painter.drawLine(0, 0, x, y);
            if(num == 30) // 设置最多拖影为 30 个
                break;
        }
    }
    else if(flag == 1)
    {
        for(int num =1; num <= (180 - d_angle); num++)
        {
            painter.setOpacity(1 - num * 1.0 / (((180 - d_angle) > 30.0) ? 30.0 : (180 - d_angle)));
            x = int(700 * qCos(qDegreesToRadians(d_angle + num)));
            y = int(-700 * qSin(qDegreesToRadians(d_angle + num)));
            painter.drawLine(0, 0, x, y);
            if(num == 30)
                break;
        }
    }
```

### 3、运行结果

总体代码：

头文件：

```c++
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *);

public slots:
    void timerTimeOut();

private:
    Ui::Widget *ui;
    double angle = 0.0;
    int flag = 0; // 0代表逆时针转动，1代表顺时针转动
};
#endif // WIDGET_H
```

源文件：

```c++
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QtMath>
#include <QTimer>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(1600, 900); // 原型this->resize(),但在widget构造函数里面，因此省略了this
    this->setStyleSheet("background-color: black"); // 背景全黑

    QTimer * timer = new QTimer(this);
    timer->start(20);
    connect(timer, &QTimer::timeout, this, &Widget::timerTimeOut);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;

    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿


    pen.setColor(Qt::green);
    painter.setPen(pen);

    painter.drawArc(100, 100, 1400, 1400, 0 * 16, 180 * 16); // 参数5以 1/16 度为单位，参数为16，意味着16 * (1/16) = 1度
    painter.drawArc(240, 240, 1120, 1120, 0 * 16, 180 * 16);
    painter.drawArc(380, 380, 840, 840, 0 * 16, 180 * 16);
    painter.drawArc(520, 520, 560, 560, 0 * 16, 180 * 16);
    painter.drawArc(660, 660, 280, 280, 0 * 16, 180 * 16);

    // 底部画一道线
    painter.drawLine(0, 800, 1600, 800);

    // 每隔30度画一道线
    painter.save(); // 保存一下坐标系：原坐标系
    painter.translate(800, 800);

    for(int i = 0; i < 5; i++)
    {
        painter.rotate(-30); // 旋转坐标系30度，相对于原坐标系逆时针旋转30度
        painter.drawLine(0, 0, 720, 0);
    }
    painter.restore(); // 恢复到原坐标系

    painter.save();
    QFont font("Courier 10 Pitch", 30, QFont::Bold, true);
    painter.setFont(font);
    painter.setPen(Qt::green);
    painter.translate(800, 800); // 平移当前坐标系原点

    painter.drawText(720, 0, "0°");

    // 角度刻度
    // x = 720 * cos30, y = 720 * sin30
    painter.drawText(720 * qCos(qDegreesToRadians(30.0)), -720 * qSin(qDegreesToRadians(30.0)), "30°"); // 坐标原点的右下方才是x正和y正
    painter.drawText(720 * qCos(qDegreesToRadians(60.0)), -720 * qSin(qDegreesToRadians(60.0)), "60°");
    painter.drawText(720 * qCos(qDegreesToRadians(90.0))-20, -720 * qSin(qDegreesToRadians(90.0)), "90°");
    painter.drawText(720 * qCos(qDegreesToRadians(120.0))-40, -720 * qSin(qDegreesToRadians(120.0)), "120°");
    painter.drawText(720 * qCos(qDegreesToRadians(150.0))-80, -720 * qSin(qDegreesToRadians(150.0)), "150°");
    painter.drawText(720 * qCos(qDegreesToRadians(180.0))-80, -720 * qSin(qDegreesToRadians(180.0)), "180°");

    // 距离刻度
    painter.drawText(140, 30, "10cm");
    painter.drawText(280, 30, "20cm");
    painter.drawText(420, 30, "30cm");
    painter.drawText(560, 30, "40cm");
    painter.drawText(700, 30, "50cm");
    painter.restore();

    // 扫描线段
    pen.setWidth(12);
    painter.setPen(pen);
    painter.save();
    painter.translate(800, 800);
    int x = int(700 * qCos(qDegreesToRadians(angle))); // 强制类型转换
    int y = int(-700 * qSin(qDegreesToRadians(angle))); // 右下方 x 和 y 是正的，右上方 x 是正的， y 是负的。
    painter.drawLine(0, 0, x, y);

    // 添加余影
    double d_angle = angle;
    if(flag == 0)
    {
        for(int num = 1; num <= d_angle; num++)
        {
            painter.setOpacity(1 - num * 1.0 / ((d_angle > 30.0) ? 30.0 : d_angle)); // 设置透明度
            x = int(700 * qCos(qDegreesToRadians(d_angle - num)));
            y = int(-700 * qSin(qDegreesToRadians(d_angle - num)));
            painter.drawLine(0, 0 , x, y);
            if(num == 30) // 设置最多拖影为 30 个
                break;
        }
    }
    else if(flag == 1)
    {
        for(int num = 1; num <= (180 - d_angle); num++)
        {
            painter.setOpacity(1 - num * 1.0 / (((180 - d_angle) > 30.0) ? 30.0 : (180 - d_angle))); // 设置透明度
            x = int(700 * qCos(qDegreesToRadians(d_angle + num)));
            y = int(-700 * qSin(qDegreesToRadians(d_angle + num)));
            painter.drawLine(0, 0 , x, y);
            if(num == 30)
                break;
        }
    }

    painter.restore();

}


void Widget::timerTimeOut()
{
    // 更新角度
//    qDebug() << "hello world!";
    if(flag == 0)
    {
        angle++;
        if(angle == 180)
            flag = 1;
    }
    else
    {
        angle--;
        if(angle == 0)
            flag = 0;
    }

    update();
}
```

![](Qt笔记.assets/雷达界面2.gif)





## 41、超声波雷达项目界面设计_03：Qt串口接收STM32发送的角度值



![image-20240124215308546](Qt笔记.assets/image-20240124215308546-17061043896821.png)





## 43、视频43：文件读写

### 1、本节内容

文件的读与写

### 2、具体步骤

2.1	创建如图所示 ui 界面

从左往右，从上往下依次为：LineEdit、PushButtonn、TextEdit。

![image-20240125113728719](Qt笔记.assets/image-20240125113728719-17061538498801.png)

2.2	信号与槽

```c++
connect(ui->pushButton, &QPushButton::clicked, this, [&](){});
```



2.3	读操作

```c++
#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, [&](){
        QString filename = QFileDialog::getOpenFileName(this, "打开文件", "/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test40/File");
        ui->lineEdit->setText(filename);
        QFile file(filename); // 将QFile对象关联到指定文件

        // 读
        file.open(QIODevice::ReadOnly);
//        QByteArray array = file.readAll(); // 读取全部内容
        QByteArray array;
        while(!file.atEnd())
        {
            array += file.readLine(); // 一行一行的读取
        }
        ui->textEdit->setText(array); // 此处发生了隐式转换
        file.close();
    });
}

Widget::~Widget()
{
    delete ui;
}


```

```c++
QString getOpenFileName(QWidget *parent = nullptr, const QString &caption = QString(), const QString &dir = QString(), const QString &filter = QString(), QString *selectedFilter = nullptr, QFileDialog::Options options = Options())
```

parent: 指定文件对话框的**父窗口**，即文件对话框在哪个窗口上显示。默认为nullptr，表示没有父窗口。

caption: 文件**对话框的标题**，显示在对话框的顶部。默认为一个空字符串。

dir: 指定对话框打开时显示的**目录路径**。默认为一个空字符串，表示使用系统默认目录。

filter: 用于筛选文件类型的过滤器，可以限制用户只能选择特定类型的文件。例如，"Text files (.txt);;XML files (.xml)"。默认为一个空字符串，表示不使用文件类型过滤器。

selectedFilter: 用于存储用户选择的过滤器的指针。如果用户选择了特定类型的文件，该指针将被设置为相应的过滤器字符串。默认为nullptr，表示不需要存储选择的过滤器。

options: 包含文件对话框的选项，以控制对话框的行为。这是一个包含多个选项的枚举类型，可以设置多个选项的组合。默认为Options()，表示没有特殊选项。



2.4	读操作运行结果

![image-20240125125751736](Qt笔记.assets/image-20240125125751736-17061586732542.png)



2.5	写操作

```c++
#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, [&](){
        QString filename = QFileDialog::getOpenFileName(this, "打开文件", "/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test40/File");
        ui->lineEdit->setText(filename);
        QFile file(filename); // 将QFile对象关联到指定文件

        // 读
        file.open(QIODevice::ReadOnly);
//        QByteArray array = file.readAll(); // 读取全部内容
        QByteArray array;
        while(!file.atEnd())
        {
            array += file.readLine(); // 一行一行的读取
        }
        ui->textEdit->setText(array); // 此处发生了隐式转换
        file.close();
        //-------------------------------------------------------------------------------------------------//
        // 写
        file.open(QIODevice::Append); // 单纯写入会覆盖原有内容，因此选择在原文末尾追加
        file.write("I love you, Rick!");
        file.close(); // 隐式转换
    });
}

Widget::~Widget()
{
    delete ui;
}
```

==Tips：==

1. **文件选择后立即读取**：在第一次运行时，你选择了文件后，立即读取了文件内容并显示在 textEdit 中。但由于在第一次运行时，文件末尾并没有追加内容，所以看起来好像没有写入。第二次运行时，由于上一次已经在文件末尾追加了内容，所以能够读取到并显示。
2. **文件读写位置**：在读取后，文件的读写位置（文件指针）可能已经在文件的末尾。在写入前，你没有将文件指针重新设置到文件的开头，导致追加的写入也发生在文件的末尾。在第一次运行时，这可能导致看不到之前追加的内容。

为了解决这个问题，你可以在写入前使用 file.seek(0) 将文件指针重新设置到文件的开头，确保写入操作发生在文件的开头而不是末尾。修改代码如下：

```
// 写
file.open(QIODevice::Append);
file.seek(0); // 将文件指针设置到文件开头
file.write("I love you, Rick!");
file.close();
```

2.6	运行结果

<img src="Qt笔记.assets/image-20240125130652966.png" alt="image-20240125130652966" style="zoom: 67%;" />







## 44、视频44：文件信息和文件定位操作

### 1、本节内容

输出文件信息和文件定位修改

### 2、具体步骤

2.1	输出文件信息

```c++
QFile file("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test41/File/MyTest.txt");
QFileInfo info(file);
qDebug() << "绝对路径：" << info.absoluteFilePath();
qDebug() << "文件名：" << info.fileName();
qDebug() << "后缀名：" << info.suffix();
qDebug() << "创建时间：" << info.created();
qDebug() << "文件大小：" << info.size();
```

运行结果如图所示：

![image-20240125183707054](Qt笔记.assets/image-20240125183707054-17061790280261.png)



2.2	想要传统的输出时间，比如年月日等

​	修改对应语句如下：

```c++
qDebug() << "创建时间：" << info.created().toString("yyyy.MM.dd hh:mm:ss");
```

运行结果如下：

![image-20240125184200782](Qt笔记.assets/image-20240125184200782-17061793222332.png)

2.3	修改文件定位	

```c++
c    file.open(QIODevice::ReadOnly);
    file.seek(0); // 当前文件指针指向文件开头
    QByteArray array = file.read(5);
    qDebug() << "前 5 个字节：" << array;
    qDebug() << "当前位置：" << file.pos();
    file.seek(15); // 当前文件指针指向文件第十五个字符后面
    array = file.read(5);
    qDebug() << "第 16 ～ 20 个字节：" << array;
    file.close();
```

运行结果如图所示：

![image-20240125184800230](Qt笔记.assets/image-20240125184800230-17061796815963.png)
