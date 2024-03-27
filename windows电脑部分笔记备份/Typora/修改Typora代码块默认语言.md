目录



### 文章目录

- - [1.操作过程](https://blog.csdn.net/qq_41642036/article/details/125610807?spm=1001.2101.3001.6650.15&utm_medium=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&utm_relevant_index=19#1_5)
    - - [1.1下载安装AHK](https://blog.csdn.net/qq_41642036/article/details/125610807?spm=1001.2101.3001.6650.15&utm_medium=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&utm_relevant_index=19#11AHK_7)
        - [1.2创建 ahk 文档](https://blog.csdn.net/qq_41642036/article/details/125610807?spm=1001.2101.3001.6650.15&utm_medium=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&utm_relevant_index=19#12_ahk__30)
        - [1.3更改文件名并运行](https://blog.csdn.net/qq_41642036/article/details/125610807?spm=1001.2101.3001.6650.15&utm_medium=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&utm_relevant_index=19#13_62)
        - [1.4测试验证](https://blog.csdn.net/qq_41642036/article/details/125610807?spm=1001.2101.3001.6650.15&utm_medium=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&utm_relevant_index=19#14_69)
    - [2 补充知识（AHK ）](https://blog.csdn.net/qq_41642036/article/details/125610807?spm=1001.2101.3001.6650.15&utm_medium=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&utm_relevant_index=19#2_AHK__88)
    - - [2.1 基本介绍](https://blog.csdn.net/qq_41642036/article/details/125610807?spm=1001.2101.3001.6650.15&utm_medium=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&utm_relevant_index=19#21___98)
        - [2.2 热键修饰符](https://blog.csdn.net/qq_41642036/article/details/125610807?spm=1001.2101.3001.6650.15&utm_medium=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-15-125610807-blog-119920818.235^v32^pc_relevant_default_base3&utm_relevant_index=19#22__102)

最近在学pytroch，看视频用Typora做笔记，里面代码块每次都要选编程语言，用多了真的很难受。。。查了各种教程，本笔记记录了我从0安装ahk,并通过脚本实现自动设置Typora代码块编程语言的全过程。



## 1.操作过程

### 1.1下载安装AHK

下载链接：https://[autohotkey](https://so.csdn.net/so/search?q=autohotkey&spm=1001.2101.3001.7020).com/download/ahk-install.exe

安装包长这样哈：

![在这里插入图片描述](https://img-blog.csdnimg.cn/921fd9e8117d443eb6952bb6781f0343.png)

**安装：**

1. 右键以管理员方式运行，点击第一个：

![在这里插入图片描述](https://img-blog.csdnimg.cn/2bf2f54fee8e4e7eb68b03598c2d8846.png)

1. 已经安装好了，点 View Changes & New Features( 其实不用点，直接点Exit也成)
    ![在这里插入图片描述](https://img-blog.csdnimg.cn/ddd2cfbd93964933b715e6fbeacc0555.png)

### 1.2创建 ahk 文档

穿件一个TXT文档，粘贴如下代码，再把文件名改成 .ahk

```v
#IfWinActive ahk_exe Typora.exe
{
    ; Ctrl+Alt+K pythonCode    
    ; crtl  是  ^      shift   是   +    k  是  k键
    ^+k::addCodePython()
}
addCodePython(){
Send,{Asc 096}
Send,{Asc 096}
Send,{Asc 096}
Send,python
Send,{Enter}
Send,{Enter}
Return
}

```

语法：

Send,{Asc 096} 表示 输出 `

asc码的096就是 `

Send,python 表示输出python

Send,{Enter} 等于是 敲了 回车键。

==实际使用代码==

```
#IfWinActive ahk_exe Typora.exe
{
    ; Ctrl+Alt+K javaCode    
    ; crtl  是  ^      alt   是   !    k  是  k键
    ^!k::addCodeJava()
}
addCodeJava(){
Send,{```}
Send,{```}
Send,{```}
Send,{```}
Send,c
Send,{`+`}
Send,{`+`}
Send,{Enter}
Return
}
```



### 1.3更改文件名并运行

将.txt 文档后缀名改成 .ahk
改名后txt文档图标会变成这个样子

![image-20220704230811051](https://img-blog.csdnimg.cn/img_convert/8825f0036be66fd05a81822d7e459d12.png)

### 1.4测试验证

![image-20220704230907360](https://img-blog.csdnimg.cn/img_convert/02fde5213921c337042fd1cdb81dd2b0.png)

然后在本文实验下 按代码块的快捷键：shift + ctrl + k

![image-20220704231411187](https://img-blog.csdnimg.cn/img_convert/37cf65444dbe2dc85690188f12aabea6.png)

成功啦，打开就有两行空行，代码也被设为python语言

```python
# 成功了，随便写两句
# 快快乐乐
12
```

上述过程参考：[https://blog.csdn.net/qq_36478274/article/details/119920818]

### 1.4设置开机自启动

如果想设置为开机启动，那就按下“window徽标键+R”，输入`shell:Common Startup`，将刚刚保存的文件放到打开的启动文件夹内即可！

## 2 补充知识（AHK ）

感觉无意间发现了个宝藏，ank还挺有趣的，决定在这里整理一些和本文有关的AutoHotKey的基础知识

资料来源：

AHK官网：[AutoHotkey](https://www.autohotkey.com/)

blog:

### 2.1 基本介绍

AutoHotkey是一种**免费的** （从任何意义上来说） **开源**产品，根据[GNU GPL](https://www.autohotkey.com/docs/license.htm) （通用公共许可证，版本2，1991年6月）发行。 它是流行的[AutoIt](https://www.autoitscript.com/site/autoit/)语言的分支。 AutoHotkey最初是作为键盘快捷键和鼠标单击/移动功能（因此，其名称为“ Hotkey”）开始的，但已增强为一种强大的编程/脚本语言。

### 2.2 热键修饰符

[热键 - 定义与使用 | AutoHotkey (wyagd001.github.io)](https://wyagd001.github.io/zh-cn/docs/Hotkeys.htm)

热键有时也称为快捷键, 因为它们能简便地触发动作(例如运行程序或[键盘宏](https://wyagd001.github.io/zh-cn/docs/misc/Macros.htm)). 在下面的例子中, Win+N 被设置为启动记事本. 磅的符号 [#] 表示 Win, 它被称为 **修饰符**

a代码块编程语言的小程序中: crtl 是 ^ shift 是 + k 是 k键

![在这里插入图片描述](https://img-blog.csdnimg.cn/8aed1cf00ff84fed98343e639fa8a747.png)