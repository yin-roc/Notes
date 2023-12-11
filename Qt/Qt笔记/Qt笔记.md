# Qt学习目录

[TOC]

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



7、Widget.ui文件

编译Ui界面时，会自动生成出相应代码
