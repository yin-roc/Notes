### 1、运行Qt闪退并报错：Terminal process exited with code 11

指针声明了却未定义



### 2、Qt中碰到串口打开失败

可以试试：

```
sudo chmod 7 /dev/ttyS0
```

碰到连接单片机时，应该先运行程序后使能该串口：

```
sudo chmod 777 /dev/ttyUSB0
```

