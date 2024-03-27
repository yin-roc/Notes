# Linux配置Qv2ray详细教程 - Ubuntu为例 - 已更换为clash

[2020-02-02](https://mahongfei.com/1776.html)[6](https://mahongfei.com/1776.html#comments)

[分享](https://mahongfei.com/1776.html)

科学上网的话，windows平台我们可以使用clash，v2rayN等软件，mac的话可以使用clashX等，但是对于linux平台，我们的选择有Qv2ray和clash，这篇文章主要介绍**Qv2ray**这款软件。

简介：Linux/Windows/macOS 跨平台 v2ray GUI 。使用 c++ 编写，支持订阅，扫描二维码，支持自定义路由编辑 。使用 Qt 框架的跨平台 v2ray 客户端。支持 Windows, Linux, macOS。

Qv2ray之前宣布停止更新，不过后面又宣布更新了。

目前支持 VMess / VLESS / SSR / Trojan / Trojan-Go / NaiveProxy / HTTP / HTTPS / SOCKS5 等协议，也算是一个比较大而全的客户端了，不过目前用的人还不是特别多，一般都是Linux用户多一些。

今天这篇文章主要是linux上面配置教程。

***注：本教程基于Ubuntu，其他Linux平台类似。***

由于在Qv2ray在Ubuntu22.04上面无法启动，会报错如下，修复起来太麻烦，所以本教程更换为Clash，使用更加简单，基本和windows差不多。

![img](https://mahongfei.com/wp-content/uploads/2020/02/1652240280-null_2022-05-11_11-37-39.png)

报错如上，有技术的小伙伴可以研究下，我们这里换成Clash教程。

## 第1步： 下载安装Linux版本的Clash

首先下载Linux版本的clash客户端，github下载链接。

PS : github下载慢的见文章末尾下载链接。

[Releases · Fndroid/clash_for_windows_pkg (github.com)](https://github.com/Fndroid/clash_for_windows_pkg/releases)

下载release页面的linux版本，如下图；

![img](https://mahongfei.com/wp-content/uploads/2020/02/1652240485-null_2022-05-11_11-41-04.png)

*注意：此片文章写作时clash版本是0.19.16。*

将下载的linux版本的clash压缩文件解压，解压命令如下：

```
tar -zxvf Clash.for.Windows-0.19.16-x64-linux.tar.gz
```



之后cd到解压后的目录,赋予cfw文件执行权限：

```
cd Clash.for.Windows-0.19.16-x64-linux
chmod +x cfw
```

```
./cfw
```



运行之后会有Clash主界面打开，后面配置就和windows一致了，下面简单记录下。

![img](https://mahongfei.com/wp-content/uploads/2020/02/1652241245-null_2022-05-11_11-53-10.png)

![img](https://mahongfei.com/wp-content/uploads/2020/02/1652241366-null_2022-05-11_11-55-48.png)

## 第2步： 导入订阅链接(即节点)

大家需要的可以走我的AFF哦  -  

[DUCKGOGO - 专线,稳定!](https://web.duckgogo.top/#/register?code=yaRDwCq0)



首先登录用户中心，点击【一键订阅】-【复制订阅地址】。

![img](https://mahongfei.com/wp-content/uploads/2020/02/1652241667-null_2022-05-11_12-00-33.png)

将复制的订阅链接粘贴到clash左侧的【配置】选项卡的上方URL处，再点击【下载】，将配置文件导入到Clash中。

![img](https://mahongfei.com/wp-content/uploads/2020/02/1652242534-null_2022-05-11_12-04-33.png)

再点击clash左侧的proxies，在第一个里面选择自己想要使用的节点，我这里选择TW为例说明；

![img](https://mahongfei.com/wp-content/uploads/2020/02/1652242563-null_2022-05-11_12-06-56.png)

此时我们firefox浏览器打开谷歌试试，发现是上不去的，那是因为linux需要手动设置一下代理ip和端口哦，请看下一步。

## 第3步： 手动设置Linux系统代理ip和端口

不知道是不是因为权限的原因，clash在linux上面无法自动打开代理端口，需要手动进行设置，设置方法如下：

首先查看clash的默认代理端口是7890；

![img](https://mahongfei.com/wp-content/uploads/2020/02/1652242597-null_2022-05-11_12-11-43.png)

打开Linux的设置-网络，点击代理后面的设置，照着下图设置http，https，socks都设置为ip是127.0.0.1，端口7890，如图所示：

![img](https://mahongfei.com/wp-content/uploads/2020/02/1652242889-null_2022-05-11_12-20-24.png)

至此，需要设置的地方都设置完了，让我门打开浏览器看看效果如何？

谷歌，youtube全部正常，大功告成！

![img](https://mahongfei.com/wp-content/uploads/2020/02/1652243019-null_2022-05-11_12-23-13.png)

最后附上下载链接：

下载请使用自带浏览器,不要使用QQ或者微信哦

[APPS 下载](https://apps.boluoge.dev/)