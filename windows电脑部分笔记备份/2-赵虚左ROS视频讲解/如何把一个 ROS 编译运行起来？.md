如何把一个 ROS 编译运行起来？

\1. 下载课程包 hw_1，并解压
\2. 创建工作空间
Ctrl+alt+t，打开终端，复制并逐条运行以下命令

```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
```

之后将 hw_1/src 中的三个文件夹复制到/catkin_ws/src 路径下
继续在终端执行命令

```
catkin_init_workspace
cd ~/catkin_ws/
catkin_make
source devel/setup.bash
```

\3. 打开 rviz
在终端执行命令
roscore
==ctrl+shift+t，打开新一页终端，执行以下命令==
rviz
显示出 rviz 初始页面  