Linux / Ubuntu上使用vscode编译运行和调试C/C++ - tnnmigga的文章 - 知乎 https://zhuanlan.zhihu.com/p/80659895

## 一、前期准备

1. 首先在[微软官网](https://link.zhihu.com/?target=https%3A//code.visualstudio.com/)下载并安装好visual stdio code

\2. 因为vscode只是一个代码编辑器，没有自带有C/C++的编译器，因此我们需要安装一个C/C++编译器，打开终端依次输入，确保安装好gcc/g++和gdb

```text
sudo apt-get update
[有密码则输入密码]
sudo apt-get install gcc
[有密码则输入密码]
sudo apt-get install g++
[有密码则输入密码]
sudo apt-get install gdb
[有密码则输入密码]
```

\3. 安装必要的插件，打开vscode，点击左面竖排第五个按钮，搜索并安装上如下两个插件

- C/C++
- Code Runner

安装好以后重启一下vscode，为避免出现其他问题，先暂时不要安装其他插件界面给你推荐的插件

## 二、编译运行程序

编译运行程序将介绍两种方法

1. 使用之前安装好的`Code Runner插件`一键编译运行程序
2. 打开vscode的`集成终端`使用命令行编译和运行

**点击：文件>新建文件**，出现一个空白文档，我准备了一段测试用的代码，请复制粘贴到空白文档中

```text
#include <stdio.h>
int main(){
   char name[100];
   printf("What is your name?\n");
   scanf("%s",name);
   printf("Hello,%s,nice to meet you!\n",name);
}
```

然后按Ctrl+S并**将文件后缀名改为`.c`或`.cpp`**后保存到电脑上，然后点击右上角的三角形按钮（原本这个位置没有，是安装Code Runner插件后新增的一键编译运行程序的按钮），或者按Ctrl+Alt+N就能编译运行当前程序

![img](https://pic3.zhimg.com/80/v2-01e9d60c2e5fc2179eb97b4627d9c162_1440w.webp)

这就是**使用Code Runner插件运行程序的方法**，点击右上角的**垃圾桶**图标可以直接结束程序运行

同时可以按 ctrl+ ~终端在其中输入命令行指令来编译运行

------



下面开始正式配置调试环境

首先在电脑上你习惯的位置新建一个文件夹，用于存放编写的代码，接下来配置好的调试环境，仅会对存放在这一个文件夹以及文件夹的子目录里程序生效！

新建好文件夹后，在vscode界面，点击：文件>打开文件夹，打开刚刚新建的文件夹（我的文件夹名叫CODE）

再点击新建文件夹在打开的文件夹下新建一个 `.vscode`文件夹（注意前面的"."号）

然后在.vscode文件夹下新建两个json文件分别叫做

- launch.json
- tasks.json

然后将下面的代码复制到对应的json文件中去并保存

**launch.json**

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "C/C++",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "preLaunchTask": "compile",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```

**tasks.json**

> **如果需要是`c语言`也就是`gcc`将下面的`command`项由`g++`改为`gcc`**

```json
{
    "version": "2.0.0",
    "tasks": [{
            "label": "compile",
            "command": "g++",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "problemMatcher": {
                "owner": "cpp",
                "fileLocation": [
                    "relative",
                    "${workspaceRoot}"
                ],
                "pattern": {
                    "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
                    "file": 1,
                    "line": 2,
                    "column": 3,
                    "severity": 4,
                    "message": 5
                }
            },
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

事实上现在已经可以正常调试了

并且此时可以按 **ctrl+shift+b** 直接调用配置好的g++ task 编译程序而不运行程序，类似于一些IDE的编译选项

很多地方写得不太详细，某些地方可以参考