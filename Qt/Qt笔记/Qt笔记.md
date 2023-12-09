# Qt学习目录

[TOC]

## 1、Qt的几个名词和概念

Qt：一个==跨平台==的C++==图形用户界面应用程序框架==，支持WIn、Mac和Unix。

Qt Creator：IDE，集成开发环境，类似于Visual Studio，包括C++编辑器、项目生成管理工具、图形界面的调试器等

Qt Designer：专门用来设计图形界面的。包含在Qt Creator里面。



## 2、创建一个Qt工程helloworld

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