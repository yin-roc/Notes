# 1、在线安装

借鉴博主：

[Linux 系统（Ubuntu）下安装 Qt 环境](https://blog.csdn.net/YMGogre/article/details/130565726)

补充：在线安装选择版本如果没有想要的 Qt 版本，勾选旁边的archive，其他取消勾选，点filter。



问题1：在线安装完后，运行 qtcreator 报错：

```
Fron 6.5.0, xcb-cursor0 or libxcb-cursor0 is needed to load the Qt xcb platforn plugin.
Could not load the Qt platforn plugin "xcb" in "" even though it was found.
This application failed to start because no Qt platforn plugin could be initialized. Reinstalling the application may fix this problem.

Available platform plugins are: vnc, linuxfb, eglfs, wayland-egl, mininal, minimalegl, xcb, vkkhrdisplay, wayland, offscreen.
```

解决方法：少安装了某些库

借鉴：[Ubuntu18.04下解决Qt出现qt.qpa.plugin:Could not load the Qt platform plugin “xcb“问题](https://blog.csdn.net/LOVEmy134611/article/details/107212845/)

# 2、Qt 配置 ROS 开发环境见下文

[Qt 配置 ROS 开发环境](https://blog.csdn.net/YMGogre/article/details/130586111) 推荐使用该博主推荐的方法。



# 3、Qt下创建 ros 工作空间，新建 ros 包后无法看到 src文件

解决方法：
[Qt ros开发环境中，添加包后无法显示src文件夹的问题解决](https://blog.csdn.net/wenliang1314/article/details/81701437)



# 4、问题2：在 Qt Creator 上创建 ROS 项目并新建/导入 ROS 包执行 catkin_make 报错



```
➜  catkin_qt_ws catkin_make
Base path: /home/yin-roc/workspace/catkin_qt_ws
Source space: /home/yin-roc/workspace/catkin_qt_ws/src
Build space: /home/yin-roc/workspace/catkin_qt_ws/build
The build space at '/home/yin-roc/workspace/catkin_qt_ws/build' was previously built by 'catkin build'. Please remove the build space or pick a different build space.
```

解决办法：删除原先编译产生的 build 和 devel，并手动编译：

[https://blog.csdn.net/weixin_45813121/article/details/132010422]: https://blog.csdn.net/weixin_45813121/article/details/132010422



# 5、问题3：重新编译时，使用 catkin_make 报错

```
Errors     << qviz_demo:cmake /home/yin-roc/workspace/catkin_qt_ws/logs/qviz_demo/build.cmake.003.log
CMake Error at /opt/ros/noetic/share/catkin/cmake/catkinConfig.cmake:83 (find_package):
Could not find a package configuration file provided by "rviz" with any of
the following names:

	rvizConfig.cmake
	rviz-config.cmake

Add the installation prefix of "rviz" to CMAKE_PREFIX_PATH or set
"rviz_DIR" to a directory containing one of the above files.  If "rviz"
provides a separate development package or SDK, be sure it has been
installed.
```

解决办法：ros失效了，重新安装ros。

[小鱼的一键安装系列](https://fishros.org.cn/forum/topic/20/%E5%B0%8F%E9%B1%BC%E7%9A%84%E4%B8%80%E9%94%AE%E5%AE%89%E8%A3%85%E7%B3%BB%E5%88%97?lang=zh-CN)



# 6、问题4：编译自有工程时，报错：

```
CMake Error at /usr/lib/x86_64-linux-gnu/cmake/Qt5/Qt5Config.cmake:28 (find_package):
  Could not find a package configuration file provided by "Qt5Multimedia"
  with any of the following names:

    Qt5MultimediaConfig.cmake
    qt5multimedia-config.cmake

  Add the installation prefix of "Qt5Multimedia" to CMAKE_PREFIX_PATH or set
  "Qt5Multimedia_DIR" to a directory containing one of the above files.  If
  "Qt5Multimedia" provides a separate development package or SDK, be sure it
  has been installed.
```

缺少安装库，执行命令：

```
sudo apt-get install qtmultimedia5-dev
```



# 7、问题5：编译自有工程时，报错：

```
CMake Error at /usr/lib/x86_64-linux-gnu/cmake/Qt5/Qt5Config.cmake:28 (find_package):
  Could not find a package configuration file provided by "Qt5WebChannel"
  with any of the following names:

    Qt5WebChannelConfig.cmake
    qt5webchannel-config.cmake

  Add the installation prefix of "Qt5WebChannel" to CMAKE_PREFIX_PATH or set
  "Qt5WebChannel_DIR" to a directory containing one of the above files.  If
  "Qt5WebChannel" provides a separate development package or SDK, be sure it
  has been installed.
```

缺少安装库，执行命令：

```
sudo apt-get install qtwebengine5-dev
```



# 8、问题6：编译自有工程时，报错：

```
CMake Error at /usr/lib/x86_64-linux-gnu/cmake/Qt5/Qt5Config.cmake:28 (find_package):
  Could not find a package configuration file provided by "Qt5SerialPort"
  with any of the following names:

    Qt5SerialPortConfig.cmake
    qt5serialport-config.cmake

  Add the installation prefix of "Qt5SerialPort" to CMAKE_PREFIX_PATH or set
  "Qt5SerialPort_DIR" to a directory containing one of the above files.  If
  "Qt5SerialPort" provides a separate development package or SDK, be sure it
  has been installed.
```

缺少库支持，执行命令：

```
sudo apt install libqt5serialport5-dev
```



9、问题7：导入外部工程时报错：

```c++
the following names:    Qt6Config.cmake   qt6-config.cmake   Qt5Config.cmake   qt5-config.cmake  Add the installation prefix of &quot;QT&quot; to CMAKE_PREFIX_PATH or set &quot;QT_DIR&quot; to a directory containing one of the above files.  If &quot;QT&quot; provides a separate development package or SDK, be sure it has been installed.
```

功能包下的 CMakeLists 加入如下语句：

```
set(CMAKE_PREFIX_PATH "/home/yin-roc/Qt/6.6.2/gcc_64")
```



10、问题8：导入外部工程出错：

```
/home/yin-roc/1-Github/workspace/qt_ros_ws/catkin_ws_1/src/ros_qt_test/CMakeLists.txt:31: error: By not providing "Findcatkin.cmake" in CMAKE_MODULE_PATH this project has
asked CMake to find a package configuration file provided by "catkin", but
CMake did not find one.

Could not find a package configuration file provided by "catkin" with any
of the following names:

  catkinConfig.cmake
  catkin-config.cmake

Add the installation prefix of "catkin" to CMAKE_PREFIX_PATH or set
"catkin_DIR" to a directory containing one of the above files.  If "catkin"
provides a separate development package or SDK, be sure it has been
installed.
```

还有诸如roscpp等类似问题，建议重装qt
