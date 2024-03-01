QMediaPlayer和QVideoWidget是Qt中用于播放视频的两个组件。在Linux下使用这两个组件播放视频，需要先安装相应的依赖库。

1. 安装Qt的multimedia组件

在Ubuntu下可以通过以下命令安装：

sudo apt-get install qtmultimedia5-dev

1. 安装GStreamer库

GStreamer是一个开源的多媒体框架，提供了音频和视频的编解码、流媒体传输等功能。在Ubuntu下可以通过以下命令安装：

sudo apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev





播放WMV后缀的视频文件

打开wmv格式视频后，系统提示安装advanced streaming format，但是Ubuntu软件商店里并没有这个东西。

在网上找到的教程里大都要求安装W64codecs.deb

这两种方法都很麻烦。

后来发现有一款视频软件叫smplayer很好用。

```
sudo apt-get install smplayer
```


