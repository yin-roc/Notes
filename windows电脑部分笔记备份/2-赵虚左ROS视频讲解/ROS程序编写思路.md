[TOC]

# 其他

## 1、args后接参数 -f 和 -d 的区别

```
<node pkg="rviz" type="rviz" name="rviz" args="-d $(find three_nav_demo)/config/nav_test.rviz" />
```

```
<arg name="filename" value="$(find three_nav_demo)/map/nav" />
<node name="map_save" pkg="map_server" type="map_saver" args="-f $(arg filename)" />
```

在ROS中，`-f`和`-d`后面的参数都可以是文件名或文件路径，但它们用于不同的目的：`-f`是用于保存数据，而`-d`是用于加载 RViz 配置。

- `-f`用于指定保存地图文件时的文件名或文件路径。在`map_saver`节点中，`-f`参数用于定义要保存地图的文件名或路径，例如：`-f my_map`或`-f /path/to/my_map`。这个参数告诉节点将地图保存到指定的文件中。
- `-d`用于指定 RViz 配置文件的路径或名称。在`rviz`节点中，`-d`参数用于告诉 RViz 加载指定路径的配置文件。这个配置文件包含 RViz 中各种可视化组件的设置，而不是保存数据。例如：`-d my_config.rviz`或`-d /path/to/my_config.rviz`。这个参数告诉 RViz 加载特定的配置文件以显示所需的可视化界面。



# Chapter 2	ROS通信机制

## 1、话题通信

### 1、话题通信基本操作

#### 1、发布者

1. 包含头文件
2. 初始化 ROS 节点
3. 创建节点句柄
4. 创建发布者对象
5. 编写发布逻辑并发布数据

```c++
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

/*
    发布方实现：
    1、包含头文件；
        ROS 中文本类型 ----> std_msgs/String.h
    2、初始化 ROS 节点；
    3、创建节点句柄；
    4、创建发布者对象；
    5、编写发布逻辑并发布数据。
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 2、初始化 ROS 节点；
    ros::init(argc, argv, "erGouzi");

    // 3、创建节点句柄；
    ros::NodeHandle nh;
    
    // 4、创建发布者对象；
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang", 10);

    // 5、编写发布逻辑并发布数据。
    // 要求以 10 Hz的频率发布数据，并且文本后添加编号
    // 先创建被发布的消息
    std_msgs::String msg;

    // 发布频率
    ros::Rate rate(1);

    // 设置编号
    int count = 0;

    // 休眠
    / ros::Duration(3).sleep();

    while (ros::ok())
    {
        count++;

        // 使用 stringstream 实现字符串拼接数字
        std::stringstream ss;
        ss << "hello ----> " << count;

        msg.data = ss.str();
        pub.publish(msg);

        // 添加日志
        ROS_INFO("发布的数据：%s", ss.str().c_str());

        rate.sleep();
        ros::spinOnce(); //官方建议，处理回调函数
    }
    
    return 0;
}

```



#### 2、订阅者

订阅方实现：

1. 包含头文件
2. 初始化 ROS 节点
3. 创建节点句柄
4. 创建订阅者对象
5. 处理订阅到的数据（回调函数）
6. spin()

```c++
#include "ros/ros.h"
#include "std_msgs/String.h"

/*
    订阅方实现：
        1、包含头文件
        2、初始化 ROS 节点
        3、创建节点句柄
        4、创建订阅者对象
        5、处理订阅到的数据
        6、spin()
*/

void doMsg(const std_msgs::StringConstPtr &msg)
{
    // 通过 msg 获取并操作订阅到的数据
    ROS_INFO("翠花订阅到的数据：%s", msg->data.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 2、初始化 ROS 节点
    ros::init(argc, argv, "cuiHua");

    // 3、创建节点句柄
    ros::NodeHandle nh;

    // 4、创建订阅者对象
    ros::Subscriber sub = nh.subscribe("fang", 10, doMsg);

    // 5、处理订阅到的数据

    // 6、spin()   
    ros::spin(); 

    return 0;
}
```



### 2、话题通信自定义msg

#### 1、发布者(msg)

1. 新建 msg 目录并添加文件 .msg

2. 配置 package.xml 文件：

    ```
    <build_depend>message_generation</build_depend>
    <exec_depend>message_runtime</exec_depend>
    ```

3. **CMakeLists.txt**编辑 msg 相关配置：

    ```cmake
    #编译时依赖
    find_package(catkin REQUIRED COMPONENTS
      roscpp
      rospy
      std_msgs
      message_generation
    )
    # 需要加入 message_generation,必须有 std_msgs
    
    
    ## 配置 msg 源文件
    add_message_files(
      FILES
      Person.msg
    )
    
    
    # 生成消息时依赖于 std_msgs
    generate_messages(
      DEPENDENCIES
      std_msgs
    )
    
    
    #执行时依赖
    catkin_package(
    #  INCLUDE_DIRS include
    #  LIBRARIES demo02_talker_listener
      CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
    #  DEPENDS system_lib
    )
    ```

4. 包含头文件

5. 初始化 ROS 节点

6. 创建节点句柄

7. 创建发布者对象

5. 编写发布逻辑
    1. 创建被发布的消息并初始化
    2. 设置发布频率
    3. 循环发布数据
        1. 核心：发布数据
        2. 休眠

```c++
#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"

/*
    1、包含头文件
    2、初始化 ROS 节点
    3、创建节点句柄
    4、创建发布者对象
    5、编写发布逻辑并发布消息
*/

int main(int argc, char *argv[])
{
    // 2、初始化 ROS 节点
    ros::init(argc, argv, "talker_person");

    // 3、创建节点句柄
    ros::NodeHandle nh;

    // 4、创建发布者对象
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::Person>("chatter_person", 10);
    

    // 5、编写发布逻辑并发布消息
    // 5-1、创建被发布的数据
    plumbing_pub_sub::Person person;
    person.age = 25;
    person.height = 1.80;
    person.name = "yinpeng";
    // 5-2、设置发布频率
    ros::Rate rate(10);

    // 5-3、循环发布数据
    // 核心：发布数据
    while (ros::ok())
    {
        pub.publish(person);
        ROS_INFO("发布的数据：%s, %d, %.2f", person.name.c_str(), person.age, person.height);
        person.age += 1;    

        // 休眠
        rate.sleep();
        ros::spinOnce(); 
    }   
    return 0;
}
```



#### 2、订阅者(msg)

1. 包含头文件
2. 初始化 ROS 节点
3. 创建节点句柄
4. 创建订阅者对象
5. 处理订阅到的数据(回调函数)
6. 调用 spin() 函数

```c++
#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"

/*
    1、包含头文件
    2、初始化 ROS 节点
    3、创建节点句柄
    4、创建订阅者对象
    5、处理订阅到的数据(回调函数)
    6、调用 spin() 函数
*/

void doPerson(const plumbing_pub_sub::Person::ConstPtr& p)
{
    ROS_INFO("订阅人的消息：%s, %d, %.2f", p->name.c_str(), p->age, p->height);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 2、初始化 ROS 节点
    ros::init(argc, argv, "listener_person");

    // 3、创建节点句柄
    ros::NodeHandle nh;

    // 4、创建订阅者对象
    ros::Subscriber sub = nh.subscribe<plumbing_pub_sub::Person>("chatter_person", 10, doPerson);

    // 5、处理订阅到的数据(回调函数)
    // 6、调用 spin() 函数
    ros::spin();

    return 0;
}
```



### 3、服务通信

#### 1、基础配置

1. 首先创建 srv 目录并创建 .srv 文件；

2. 配置 package.xml：

    ```
    <build_depend>message_generation</build_depend>
    <exec_depend>message_runtime</exec_depend>
    ```

3. 配置 CMakeLists.txt：

    ```
    find_package(catkin REQUIRED COMPONENTS
      roscpp
      rospy
      std_msgs
      message_generation
    )
    # 需要加入 message_generation,必须有 std_msgs
    
    add_service_files(
      FILES
      AddInts.srv
    )
    
    generate_messages(
      DEPENDENCIES
      std_msgs
    )
    
    # 官网没有配置 message_runtime，经过测试配置也是可以的
    catkin_package(
    #  INCLUDE_DIRS include
    #  LIBRARIES plumbing_server_client
     CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
    #  DEPENDS system_lib
    )
    ```

4. 创建服务端和客户端文件，并配置CMakeLists.txt

    ```cmake
    add_executable(AddInts_Server src/AddInts_Server.cpp)
    add_executable(AddInts_Client src/AddInts_Client.cpp)
    
    
    add_dependencies(AddInts_Server ${PROJECT_NAME}_gencpp)
    add_dependencies(AddInts_Client ${PROJECT_NAME}_gencpp)
    
    
    target_link_libraries(AddInts_Server
      ${catkin_LIBRARIES}
    )
    target_link_libraries(AddInts_Client
      ${catkin_LIBRARIES}
    )
    ```

#### 2、服务端实现

1. 包含头文件；

2. 初始化 ROS 节点；

3. 创建节点句柄；

4. 创建服务对象；

5. 回调函数处理请求并产生响应；

6. 由于请求有多个，需要调用 ros::spin()。

    ```c++
    #include "ros/ros.h"
    #include "plumbing_server_client/AddInts.h"
    
    /*
        需求: 
            编写两个节点实现服务通信，客户端节点需要提交两个整数到服务器
            服务器需要解析客户端提交的数据，相加后，将结果响应回客户端，
            客户端再解析
    
        服务器实现:
            1.包含头文件
            2.初始化 ROS 节点
            3.创建节点句柄
            4.创建 服务 对象
            5.回调函数处理请求并产生响应
            6.由于请求有多个，需要调用 ros::spin()
    */
    
    bool doNums(plumbing_server_client::AddInts::Request & request,
                plumbing_server_client::AddInts::Response & response)
    {
        // 1、处理请求
        int num1 = request.num1;
        int num2 = request.num2;
        ROS_INFO("收到的请求数据: num1 = %d, num2 = %d", num1, num2);
        // 2、组织响应
        int sum = num1 + num2;
        response.sum = sum;
        ROS_INFO("求和结果: sum = %d", sum);
        return true;
    }
    
    int main(int argc, char *argv[])
    {
        setlocale(LC_ALL, "");
    
        // 2.初始化 ROS 节点
        ros::init(argc, argv, "heiShui");
    
        // 3.创建 ROS 句柄
        ros::NodeHandle nh;
    
        // 4.创建服务对象
        ros::ServiceServer server = nh.advertiseService("addInts", doNums);
    
        // 5.回调函数处理请求并产生响应
        // 6.由于请求有多个，需要调用 ros::spin()
        ros::spin();
        return 0;
    }
    ```

#### 3、客户端实现

1. 包含头文件
2. 初始化 ROS 节点
3. 创建节点句柄
4. 创建客户端对象
5. 提交请求并处理响应
    1. 组织请求
    2. 处理相应

```c++
#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

/*
    （1）客户端：提交两个整数，并处理响应的数据
        1、包含头文件
        2、初始化 ROS 节点
        3、创建节点句柄
        4、创建客户端对象
        5、提交请求并处理响应
    
    （2）实现参数的动态提交：
        1、格式：rosrun xxxx xxxx 12 34
        2、节点在执行时，需要获取命令中的参数，并组织进 request
        argc[0]:节点名
        argc[1]:参数1
        argc[2]:参数2

    （3）问题：
            如果先启动客户端，那么会请求异常
        
        需求：
            如果先启动了客户端，不要直接抛出异常，而是挂起，等服务器启动后，再正常请求
        
        解决：
            在 ROS 中内置了相关函数，这些函数可以让客户端启动后挂起，等待的服务器启动
            1、client.waitForExistence();
            2、ros::service::waitForService("服务话题");
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    // 解决问题(2),优化实现,获取命令中的参数
    if(argc != 3)
    // 第一个参数是文件的路径，第二个参数是12，第三个参数是34
    {
        ROS_INFO("提交的参数个数不对！");
        return 1;
    }

    // 2、初始化 ROS 节点
    ros::init(argc, argv, "daBao");

    // 3、创建节点句柄
    ros::NodeHandle nh;

    // 4、创建客户端对象
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("addInts");

    // 5、提交请求并处理响应
    plumbing_server_client::AddInts ai;

    // 5-1、组织请求
        ai.request.num1 = atoi(argv[1]);
        ai.request.num2 = atoi(argv[2]);
        // 对应解决了问题 2
        // argv[1] 还是字符串类型，因为 char * argv[]，因此需要将他转换成整数类型
        // 因此，使用 atoi，用来将字符串转化为整数

    // 5-2、处理响应
    // 问题3、调用判断服务器状态的函数
    // 函数1
    // client.waitForExistence();
    // 函数2
    ros::service::waitForService("addInts"); 

    bool flag = client.call(ai);
    if(flag)
    {
        ROS_INFO("响应成功！");
        // 获取结果
        ROS_INFO("响应结果 = %d", ai.response.sum);
    }
    else
    {
        ROS_INFO("响应失败");
    }

    return 0;
}
```



### 4、参数操作

#### 1、参数服务器新增(修改)参数

1. 创建功能包并添加依赖（roscpp、rospy、std_msgs)
2. 配置CMakelists.txt
3. 编写逻辑

```c++
#include "ros/ros.h"

/*
    需要实现参数的新增与修改
    需求：首先设置机器人的共享参数：类型、半径，
         再修改半径(0.2m)
    实现：
        新增：
         键指函数里面的参数 key
         ros::NodeHandle
            setParam("键", 值)
         ros::param
            set("键", 值)
        
        修改：只需要继续调用 setParam 或 set 函数，保证键是已经存在的，那么值会被覆盖

        void setParam(const std::string &key, const std::map<std::string, bool> &map) const
*/

int main(int argc, char *argv[])
{
    // 初始化 ROS 节点
    ros::init(argc, argv, "set_param_c");

    // 创建 ROS 节点句柄
    ros::NodeHandle nh;

    // 参数增--------------------------------
    // 方案1：nh
    nh.setParam("type", "xiaoHuang");
    nh.setParam("radius", 0.15);
    
    // 方案2：ros::param
    ros::param::set("type_param", "xiaoBai");
    ros::param::set("radius_param", 0.15);

    // 参数改--------------------------------
    // 方案1：nh
    nh.setParam("radius", 0.2);

    // 方案2：ros::param
    ros::param::set("radius_param", 0.25);

    return 0;
}
```



#### 2、参数服务器获取参数

1. 创建功能包并添加依赖（roscpp、rospy、std_msgs)

2. 配置CMakelists.txt

3. 编写逻辑

    ```c++
    #include "ros/ros.h"
    
    /*
        演示实现参数的查询
        实现：
            ros::NodeHandle------------------
    
            1、param(键, 默认值)
                存在，返回对应结果，否则返回默认值
            
            2、getParam(键，存储结果的变量)
                存在，返回 true， 且将值赋给参数2
                若键不存在，那么返回值为 false，且不为参数2赋值
            
            3、getParamCached键，存储结果的变量---提高变量获取效率
                存在，返回 true， 且将值付给参数2
                若键不存在，那么返回值为 false，且不为参数2赋值
            
            4、getParamNames(std::vector<std::string>):获取所有参数的名称
                获取所有的键，并存储在参数 vector 中
    
            5、hasParam(键)
                是否包含某个键，存在则返回 true，否则返回 false
    
            6、searchParam(参数1，参数2)
                搜索键，参数1是被搜索的键，参数2存储搜索结果的变量
            
    		ros::param--------------------------------
    
    */
    
    int main(int argc, char *argv[])
    {
        // 设置编码
        setlocale(LC_ALL, "");
    
        // 初始化 ROS 节点
        ros::init(argc, argv, "get_param_c");
        
        // 创建节点句柄
        ros::NodeHandle nh;
    
        // ros::NodeHandle-------------------
        // 1. param
        double radius = nh.param("radius", 0.5); // 如果没有查找到 radius，使用默认值0.5
    
        // 查找 键 为 radius 的值，如果没有，使用默认值 0.5
        ROS_INFO("radius = %.2f", radius);
    
        // 2. getParam()
        double radius2 = 0.3;
        // bool result = nh.getParam("radius", radius2);
        // if(result)
        // {
        //     ROS_INFO("获取的半径是：%.2f", radius2);
        // }
        // else
        // {
        //     ROS_INFO("被查询的结果是不存在的。");
        // }
    
        // 3、getParamCached 与 getParam 类似，只是底层性能上有提升
        // 一般测试下，看不出来
        bool result = nh.getParamCached("radius", radius2);
        if(result)
        {
            ROS_INFO("获取的半径是：%.2f", radius2);
        }
        else
        {
            ROS_INFO("被查询的结果不存在。");
        }
    
        // 4、getParamNames(std::vector<std::string>):获取所有参数的名称
        std::vector<std::string> names; // 保存参数名称
        nh.getParamNames(names);
        for(auto && name : names)
        {
            ROS_INFO("遍历的元素：%s", name.c_str());
        }
    
        // 5、hasParam
        bool flag1 = nh.hasParam("radius");
        bool flag2 = nh.hasParam("radiusxxxx");
        ROS_INFO("radius 存在吗？ %d", flag1);
        ROS_INFO("radiusxxxx 存在吗？%d", flag2);
    
        // searchParam
        std::string key;
        nh.searchParam("radius", key);
        ROS_INFO("搜索的结果:%s",key.c_str());
    
        // ros::param-------------------------------
        double radius_param = ros::param::param("radius", 100.5);
        ROS_INFO("radius_param = %.2f", 0.25);
    
        std::vector<std::string> names_param;
        ros::param::getParamNames(names_param);
        for(auto && name : names_param)
        {
            ROS_INFO("键：%s", name.c_str());
        }
    
        return 0;
    }
    
    ```



#### 3.参数服务器**删除**参数

1. 创建功能包并添加依赖（roscpp、rospy、std_msgs)
2. 配置CMakelists.txt
3. 编写逻辑

```c++
#include "ros/ros.h"

/*
    演示参数删除：
        实现：
            ros::NodeHandle()
                deleteParam()
            ros::param
                del()

*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "param_del_c");
    ros::NodeHandle nh;

    // 删除：NodeHandle--------------------------
    bool flag1 = nh.deleteParam("radius");
    if(flag1)
    {
        ROS_INFO("删除成功！");
    }
    else
    {
        ROS_INFO("删除失败！");
    }

    // 删除：ros::param---------------------------
    bool flag2 = ros::param::del("radius_param");
    if(flag2)
    {
        ROS_INFO("radius_param 删除成功！");
    }
    else
    {
        ROS_INFO("radius_param 删除失败！");
    }

    return 0;
}
```









# Chapter 5	ROS常用组件

## 1、TF坐标变换

### 1、坐标msg消息

在坐标变换中常用的两个msg：geometry_msgs/TransformStamped 和 geometry_msgs/PointStamped

==geometry_msgs/TransformStamped==：传输坐标系相关位置信息，主要用于坐标变换：

消息类型分为三部分：

```
1.header:
	（1）时间戳：stamp
	（2）坐标系：frame_id
2.child_frame_id：字符串类型，相对坐标系
3.transform：geometry_msgs/Transform 类型的数据结构
	（1）偏移量：translation，geometry_msgs/Vector3 类型的数据，表示三维空间中的平移变换
		x，y，z
	（2）四元数（欧拉角的另外一种表示方式）：rotation，geometry_msgs/Quaternion类型的数据，表示三维空间中的旋转变换
		x，y，z，w
```

==geometry_msgs/PointStamped==：传输某个坐标系内坐标点的信息

消息类型分为两部分：

```
1.header:
	（1）时间戳：stamp
	（2）坐标系：frame_id
2.point：geometry_msgs/PointStamped 类型的数据结构
	点坐标：x，y，z
```

​			

**tips**：header中一般还有一个seq表示序号，但其是 ROS 自动管理的。

### 2、静态坐标变换

#### 1、发布者

**编写思路：**

1. 准备工作（设置编码、节点初始化和NodeHandle）

2. 创建发布者对象（tf2_ros::StaticTransformBroadcaster pub）

3. 编写要发布的内容（geometry_msgs::TransformStamped tfs）

    对tfs进行赋值，包括：header、child_frame_id和transform

    ​		header：seq、stamp和frame_id，其中参数seq是ROS自动设置

    ​		child_frame_id：子坐标系

    ​		transform：

    ​								translation：（中文意思选偏移），需要设置x，y，z三个方向的偏移量

    ​								rotation：四元素（与欧拉角可以互相转换），需要设置x，y，z，w四个分量，其中														x，y，z是虚部（i，j，k的分量）。

4. 使用广播器发布坐标信息（ pub.sendTransform(tfs)）

**四元素与欧拉角的关系和区别：**

- 四元数和欧拉角都可以用来表示旋转，但它们的表示方式不同。四元数使用四个数值，而欧拉角使用三个角度（滚动、俯仰和偏航）。
- 四元数可以避免万向节锁问题，而欧拉角可能会在某些情况下受到万向节锁的限制。
- 四元数通常在计算机图形和游戏开发中更常用，因为它们具有较小的计算复杂性，并且可以轻松进行插值和叠加操作。
- 欧拉角在直观理解和人类交互方面可能更容易使用，但需要谨慎处理顺序和边界情况，以避免歧义。

```c++
#include "ros/ros.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

/*
    需求：发布两个坐标系的相对关系

    流程：
        1、包含头文件
        2、设置编码、节点初始化、NodeHandle
        3、创建发布对象
        4、组织被发布的消息
        5、发布数据
        6、spin()
*/

int main(int argc, char *argv[])
{
    // 2、设置编码、节点初始化、NodeHandle
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "static_pub");
    ros::NodeHandle nh;

    // 3、创建发布对象
    tf2_ros::StaticTransformBroadcaster pub;
    // tf2_ros::StaticTransformBroadcaster对象，并将其命名为pub。
    // 这个对象的主要作用是允许你发布（broadcast）静态变换（static transform），使其他ROS节点能够了解两个不同坐标系之间的关系

    ros::Rate rate(1);

    while (ros::ok())
    {
        // 4、组织被发布的消息
        geometry_msgs::TransformStamped tfs; 
        // geometry_msgs::TransformStamped 是 ROS 中的一种消息类型，通常用于表示两个坐标系之间的变换关系。
        // 这个消息包含了以下信息：
        // header：通常包含有关消息的元数据，如时间戳和坐标系信息。
        // child_frame_id：子坐标系的名称。
        // transform：描述了从父坐标系到子坐标系的变换的具体信息，包括平移和旋转。

        tfs.header.stamp = ros::Time::now();
        tfs.header.frame_id = "base_link"; //相对坐标系关系中被参考的那一个
        tfs.child_frame_id = "laser";
        tfs.transform.translation.x = 0.2;
        tfs.transform.translation.y = 0.0;
        tfs.transform.translation.z = 0.5;

        // 需要根据欧拉角转换
        tf2::Quaternion qtn; // 创建 四元数 对象
        // 向该对象设置欧拉角，这个对象可以将欧拉角转换成四元数
        qtn.setRPY(0, 0, 0); // 这一行将四元数对象 qtn 的值设置为指定的欧拉角
        // setRPY 方法接受三个参数，分别是滚动（Roll）、俯仰（Pitch）和偏航（Yaw）的欧拉角。
        // 在这个代码中，欧拉角都被设置为0弧度，表示没有旋转。这意味着 tfs 对象的旋转部分被设置为没有旋转的四元数，即单位四元数，以确保它代表了原始坐标系。
        // 欧拉角的单位是弧度。

        tfs.transform.rotation.x = qtn.getX();
        tfs.transform.rotation.y = qtn.getY();
        tfs.transform.rotation.z = qtn.getZ();
        tfs.transform.rotation.w = qtn.getW();
        // 这些行将 qtn 中的四元数的实部和虚部分别分配给 tfs 中的 transform.rotation 的四个成员。
        // 实部 (w)：四元数的实部，通常表示旋转的角度部分。
        // 虚部 (x, y, z)：四元数的虚部，通常表示旋转的轴部分。
        // 这是为了将四元数的值正确设置到ROS消息对象中，以便在ROS中发布或传输坐标变换信息。

        // 5、发布数据
        pub.sendTransform(tfs); // 用于发布坐标变换消息的特定函数
        // 6、spin()  
        ros::spinOnce();
        rate.sleep();
    }
    
    return 0;
}
```

除此之外，还可以==直接通过命令行发布静态坐标系==之间的联系：

当坐标系之间的相对位置固定时，那么所需参数也是固定的: 父系坐标名称、子级坐标系名称、x偏移量、y偏移量、z偏移量、x 翻滚角度、y俯仰角度、z偏航角度，**实现逻辑相同，参数不同，那么 ROS 系统就已经==封装好了专门的节点==**，使用方式如下:

```
rosrun tf2_ros static_transform_publisher x偏移量 y偏移量 z偏移量 z偏航角度 y俯仰角度 x翻滚角度 父级坐标系 子级坐标系
```

示例:`rosrun tf2_ros static_transform_publisher 0.2 0 0.5 0 0 0 /baselink /laser`

也建议使用该种方式直接实现静态坐标系相对信息发布。



#### 2、订阅者

**编写思路：**

1. 设置编码、初始化节点和NodeHandle；

2. 创建订阅对象：

    步骤1：创建一个缓冲区对象：buffer（tf2_ros::Buffer类型）；

    步骤2：创建一个监听者对象：listener（tf2_ros::TransformListener类型），接收缓冲区作为参数（这里的buffer），该对象用于从缓冲区中实时获得坐标变换信息；

3. 在子坐标系中创建一个坐标点：ps（geometry_msgs::PointStamped类型），对该对象的header和point进行初始化设置；（此处要开始循环接收）

4. 创建另一个坐标点：ps_out（geometry_msgs::PointStamped类型）用于接收转换后的坐标点信息。

    通用格式为：

    ```
    transformed_data = buffer.transform(original_data, target_frame);
    ```

```c++
#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

/*
    订阅方：订阅发生的坐标系相对关系，传入一个坐标点，调用 tf 实现转换

    流程：
        1、包含头文件
        2、编码、初始化、NodeHandle(必须的)
        3、创建订阅对象；------->订阅坐标系相对关系
        4、组织一个坐标点数据
        5、转换算法，需要调用 tf 内置实现
        6、最后输出。
*/

int main(int argc, char *argv[])
{
    // 2、编码、初始化、NodeHandle(必须的)
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "static_sub");
    ros::NodeHandle nh;

    // 3、创建订阅对象；------->订阅坐标系相对关系
    // 3-1、创建一个 buffer 缓存,管理和维护坐标变换信息
    tf2_ros::Buffer buffer;
    
    // 3-2、再创建监听对象（监听对象可以将订阅到的数据存入 buffer）
    // tf2_ros::TransformListener 是一个用于监听坐标变换信息的类。
    // 这个监听器对象允许节点订阅坐标变换信息，以便实时获取两个不同坐标系之间的坐标变换关系
    tf2_ros::TransformListener listener(buffer); 

    // 4、组织一个坐标点数据
    // 创建了一个名为 ps 的消息对象，用于存储三维点数据，并且该点带有时间戳和坐标系信息。
    geometry_msgs::PointStamped ps;

    // 设置 ps 消息的头部（header）的坐标系（frame_id）。
    // 指定了这个三维点所处的坐标系，即 "laser" 坐标系。这表示这个三维点的坐标是相对于 "laser" 坐标系的。
    ps.header.frame_id = "laser"; 

    // 设置 ps 消息的头部的时间戳（stamp）。
    // ros::Time::now() 返回当前的 ROS 时间，因此这里将当前时间作为时间戳，表示这个三维点的时间信息。
    ps.header.stamp = ros::Time::now();

    // 设置 ps 消息中的三维点的坐标
    ps.point.x = 2.0;
    ps.point.y = 3.0;
    ps.point.z = 5.0;
    
    // 5、转换算法，需要调用 tf 内置实现
    ros::Rate rate(10);
    while(ros::ok())
    {
        // 核心代码 --- 将 ps 转换成相对于 base_link 的坐标点
        geometry_msgs::PointStamped ps_out;

        /*
            调用了 buffer 的转换函数 transform
            参数1：被转换的坐标点
            参数2：目标坐标系
            返回值：输出的坐标点

            PS1：调用时必须包含头文件 tf2_geometry_msgs/tf2_geometry_msgs.h
            PS2: 运行时存在的问题：抛出一个异常 base_link 不存在
                原因：订阅数据是一个耗时操作，可能在调用一个 transform 转换函数时，
                    坐标系的相对关系还没有订阅到，因此出现异常
                解决：
                    方案1：在调用转换函数前，执行休眠
                    方案2：进行异常处理 try 函数（建议）
        */
        try
        {
            ps_out = buffer.transform(ps, "base_link");
            
            // 6、最后输出。
            ROS_INFO("转换后的坐标值：(%.2f, %.2f, %.2f)，参考的坐标系：%s",
                        ps_out.point.x,
                        ps_out.point.y,
                        ps_out.point.z,
                        ps_out.header.frame_id.c_str()
                        );
        }
        catch(const std::exception& e)
        {
            // std::cerr << e.what() << '\n';
            ROS_INFO("异常消息：%s", e.what());
        }
        
        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
```



### 3、动态坐标变换

#### 1、发布者

**编写思路：**

1. 设置编码、初始化节点和NodeHandle

2. 创建订阅对象，订阅对象：/turtle1/pose

3. 回调函数处理：获取位姿信息，并转换成相对信息发布

    （1）创建发布对象pub（tf2_ros::TransformBroadcaster);

    （2）组织待发布的消息ts（geometry_msgs::TransformStamped);

    ​			header(stamp、frame_id)、child_frame_id、transform(translation、rotation);

    （3）发布ts（pub.sendTransform);

4. spin()函数

```c++
#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h" // 欧拉角

/*
    发布方：需要订阅乌龟的位姿信息，转换成相对于窗体的坐标关系，并发布
    准 备：
        话题：/turtle1/pose
        消息：/turtlesim/Pose
    
    流程：
        1、包含头文件；
        2、设置编码、初始化、NodeHandle
        3、创建订阅对象，订阅 /turtle1/pose;
        4、回调函数处理订阅的消息：将位姿信息转换成坐标相对关系并发布（关注）
        5、spin()
*/

void doPose(const turtlesim::Pose::ConstPtr & pose)
{
    // 获取位姿信息，转换成坐标系相对关系（核心），并发布
    // a.创建发布对象
    static tf2_ros::TransformBroadcaster pub;

    // b.组织被发布的数据
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    ts.child_frame_id = "turtle1";

    // 坐标系偏移量设置
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;

    // 坐标系四元数
    /*
        位姿信息中没有四元数，但是有个偏航角度，又已知乌龟是 2D，没有翻滚与俯仰角度，
        所以可以得出乌龟的欧拉角：0 0 theta
    */
    tf2::Quaternion qtn;
    qtn.setRPY(0, 0, pose->theta);
    
	// 归一化 qtn.normlized
        
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();

    // c.发布
    pub.sendTransform(ts);
}

int main(int argc, char *argv[])
{
    // 2、设置编码、初始化、NodeHandle
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "dynamic_pub");
    ros::NodeHandle nh;

    // 3、创建订阅对象，订阅 /turtle1/pose;
    ros::Subscriber sub = nh.subscribe("/turtle1/pose", 100, doPose);
    // 4、回调函数处理订阅的消息：将位姿信息转换成坐标相对关系并发布（关注）
    // 5、spin()
    ros::spin();
    
    return 0;
}

```



#### 2、订阅者

**编写思路：**

1. 编码、初始化和NodeHandle

2. 创建订阅对象，订阅坐标系相对关系

    （1）创建一个 buffer 缓存（tf2_ros::Buffer）

    （2）创建一个监听对象 listener（tf2_ros::Buffer），接收 buffer 为参数

3. 组织一个坐标点数据：ps（geometry_msgs::PointStamped）并初始化

    ​			包括：header（frame_id和stamp）、point（x、y、z）

4. 循环：创建一个坐标点 ps_out 用于接收转换的坐标信息。

    ```
    transformed_data = buffer.transform(original_data, target_frame);
    ```

```c++
#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

/*
    订阅方：订阅发生的坐标系相对关系，传入一个坐标点，调用 tf 实现转换

    流程：
        1、包含头文件
        2、编码、初始化、NodeHandle（必须的）
        3、创建订阅对象；---------> 订阅坐标系相对关系
        4、组织一个坐标点数据
        5、转换算法，需要调用 tf 内置实现
        6、最后输出。
*/

// 从 tf01_static 修改而来，共有三处修改

int main(int argc, char *argv[])
{
    // 2、编码、初始化、NodeHandle（必须的）
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "dynamic_sub");
    ros::NodeHandle nh;

    // 3、创建订阅对象；---------> 订阅坐标系相对关系
    // 3-1、创建一个 buffer 缓存
    tf2_ros::Buffer buffer;

    // 3-2、再创建监听对象（监听对象可以将订阅的数据存入 buffer）
    tf2_ros::TransformListener listener(buffer);

    // 4、组织一个坐标点数据
    geometry_msgs::PointStamped ps;
    // ----------- 修改 1 ------------
    // 参考的坐标系
    ps.header.frame_id = "turtle1";

    // ----------- 修改 2 ------------
    // 时间戳
    ps.header.stamp = ros::Time(0.0); // 0.0 相当于不加时间戳，直接转换成不判断时间是否对齐

    // ps.header.stamp = ros::Time::now(); // 会报错，加了时间戳，得验证时间是否对齐
 
    ps.point.x = 2.0;
    ps.point.y = 3.0;
    ps.point.z = 5.0;

    // 方案1：添加休眠：以防已经开始订阅了，而发布者还没发布消息
    // ros::Duration(2).sleep();
    // 5、转换算法，需要调用 tf 内置实现
    ros::Rate rate(10);

    while (ros::ok())
    {
        // 核心代码 --- 将 ps 转换成相对于 base_link 的坐标点
        geometry_msgs::PointStamped ps_out;

        /*
            调用了 buffer 的转换函数 transform
            参数1:被转换的坐标点
            参数2：目标坐标系
            返回值：输出的坐标点

            PS1：调用时必须包含头文件 tf2_geometry_msgs/tf2_geometry_msgs.h
            PS2：运行时出现问题：抛出一个异常 base_link 不存在
                原因：订阅数据是一个耗时操作，可能在调用一个 transform 转换函数时，
                        坐标系的相对关系还没有订阅到，因此出现异常
                解决：
                    方案1：在调用转换函数前，执行休眠
                    方案2：进行异常处理 try 函数（建议）
        */

        try
        {
            // ------------ 修改3 ---------------
            ps_out = buffer.transform(ps, "world");

            // 6、最后输出。   
            ROS_INFO("转换后的坐标值：(%.2f, %.2f, %.2f)，参考的坐标系：%s",
                        ps_out.point.x,
                        ps_out.point.y,
                        ps_out.point.z,
                        ps_out.header.frame_id.c_str()
                    );
        }
        catch(const std::exception& e)
        {
            // std::cerr << e.what() << '\n';
            ROS_INFO("异常消息：%s", e.what());
        }
        
        rate.sleep();
        ros::spinOnce();
    }
    
    return 0;
}
```



### 4、多坐标变换

现有坐标系统，父级坐标系统 world,下有两子级系统 son1，son2，son1 相对于 world，以及 son2 相对于 world 的关系是已知的，求 son1原点在 son2中的坐标，又已知在 son1中一点的坐标，要求求出该点在 son2 中的坐标。

#### 1、发布者

采用launch文件发布两个子坐标系son1和son2相对于坐标系world的关系：

```
<launch>
    <!-- 发布 son1 相对于 world 以及 son2 相对于 world 的关系 -->
    <node name="son1" pkg="tf2_ros" type="static_transform_publisher" args="5 0 0 0 0 0 /world /son1" output="screen"/>
    
    <node name="son2" pkg="tf2_ros" type="static_transform_publisher" args="3 0 0 0 0 0 /world /son2" output="screen"/>
</launch>
```



#### 2、订阅者

**编写思路：**

1. 编码、初始化和NodeHandle

2. 创建订阅对象

    （1）创建缓冲区对象：buffer（tf2_ros::Buffer）

    （2）创建监听者对象：sub（tf2_ros::TransformListener），接收buffer作为参数

3. 创建坐标系son1中坐标点psAtSon1（geometry_msgs::PointStamped类型），并进行相关初始化

4. 循环：创建son1ToSon2（geometry_msgs::TransformStamped）来表示两个坐标系之间的变换关系

    ```c++
    geometry_msgs::TransformStamped variable_name = buffer.lookupTransform(target_frame, source_frame, time);
    ```

5. 计算 son1 的某个坐标点在 son2 中的坐标值：

    ```c++
    geometry_msgs::PointStamped psAtSon2 = buffer.transform(psAtSon1, target_frame);
    ```

    要转换的点：pSAtSon1，要转换到的坐标系：son2

```C++
#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"

/*
    订阅方实现：
        1、计算 son1 和 son2 的相对关系
        2、计算 son1 的某个坐标点在 son2 中的坐标值

    流程：
        1、包含头文件；
        2、编码、初始化、NodeHandle；
        3、创建订阅对象；
        4、编写解析逻辑；
        5、spinOnce()；
*/

int main(int argc, char *argv[])
{
    // 2、编码、初始化、NodeHandle；
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "tfs_sub");
    ros::NodeHandle nh;

    // 3、创建订阅对象；
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);

    // 4、编写解析逻辑；
    // 创建坐标点
    geometry_msgs::PointStamped psAtSon1;
    psAtSon1.header.stamp = ros::Time::now();
    psAtSon1.header.frame_id = "son1";
    psAtSon1.point.x = 1.0;
    psAtSon1.point.y = 2.0;
    psAtSon1.point.z = 3.0;

    ros::Rate rate(10);
    while (ros::ok())
    {
        // 核心
        try
        {
            // 1、计算 son1 和 son2 的相对关系
            /*
                参数1：目标坐标系
                参数2：源坐标系
                参数3：ros::Time(0) 取间隔最短的两个坐标系关系计算相对关系
                返回值：geometry_msgs::TransformStamped 源相对于目标坐标系的相对关系

                例如：A 相对于 B 的坐标系关系
                B 作为目标坐标系
                A 作为源坐标系
            */

           geometry_msgs::TransformStamped son1ToSon2 = buffer.lookupTransform("son2", "son1", ros::Time(0));
           ROS_INFO("Son1 相对于 Son2 的信息：父级名称：%s, 子级名称：%s, 偏移量(%.2f, %.2f, %.2f)",
                        son1ToSon2.header.frame_id.c_str(), // son2
                        son1ToSon2.child_frame_id.c_str(), // son1
                        son1ToSon2.transform.translation.x,
                        son1ToSon2.transform.translation.y,
                        son1ToSon2.transform.translation.z);
            
            // 2、计算 son1 的某个坐标点在 son2 中的坐标值
            geometry_msgs::PointStamped psAtSon2 = buffer.transform(psAtSon1, "son2"); // 要转换的点：pSAtSon1，要转换到的坐标系：son2
            ROS_INFO("坐标点在 son2 中的值：(%.2f, %.2f, %.2f)", 
                        psAtSon2.point.x,
                        psAtSon2.point.y,
                        psAtSon2.point.z
                    );
        }
        catch(const std::exception& e)
        {
            ROS_INFO("错误提示：%s", e.what());
            // std::cerr << e.what() << '\n';
        }
        rate.sleep();
        ros::spinOnce();
    }
    // 5、spinOnce()；
    
    return 0;
}
```



### 5、TF坐标变换实操

**需求描述：**

程序启动之初: 产生两只乌龟，中间的乌龟(A) 和 左下乌龟(B), B 会自动运行至A的位置，并且键盘控制时，只是控制 A 的运动，但是 B 可以跟随 A 运行。

#### 1、launch文件

```xml
<launch>
    <!-- 1、启动乌龟 GUI 节点 -->
    <node name="turtle1" pkg="turtlesim" type="turtlesim_node" output="screen"/>
    <node name="key" pkg="turtlesim" type="turtle_teleop_key" output="screen"/>
    
    <!-- 2、生成新的乌龟节点 -->
    <node name="turtle2" pkg="tf04_test" type="test01_new_turtle_c" output="screen"/>
    
    <!-- 3、需要设置两个乌龟相对于世界坐标系的发布 -->
    <!-- 
        基本实现思路：
            1、节点只编写一个
            2、这个节点需要启动两次
            3、节点启动时动态传参：第一次启动传递 turtle1，第二次启动传递 turtle2
     -->
    <node name="pub1" pkg="tf04_test" type="test02_pub_turtle_c" args="turtle1" output="screen"/>
    <node name="pub2" pkg="tf04_test" type="test02_pub_turtle_c" args="turtle2" output="screen"/>

    <!-- 4、需要订阅 turtle1 和 turtle2 相对于世界坐标系的坐标消息，
            并转换成 turtle1 相对于 turtle2 的坐标关系
            在生成速度消息
     -->
    <node name="control" pkg="tf04_test" type="test03_control_turtle2_c" output="screen"/>
    
</launch>
```



#### 2、创建新乌龟（新的服务）

```c++
#include "ros/ros.h"
#include "turtlesim/Spawn.h"

/*
    需求：向服务端发送请求，生成一只新乌龟
        话题：/spawn
        消息：turtlesim/Spawn
    
    1、包含头文件；
    2、初始化 ros 节点；
    3、创建节点句柄；
    4、创建客户端对象；
    5、组织数据并发送；
    6、处理响应； // 数据什么时候发送，是可控的，因此不需要 spinOnce 函数
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 2、初始化 ros 节点；
    ros::init(argc, argv, "service_call");

    // 3、创建节点句柄；
    ros::NodeHandle nh;

    // 4、创建客户端对象；
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");

    // 5、组织数据并发送；
    // 5-1、组织请求数据
    turtlesim::Spawn spawn;
    spawn.request.x = 1.0;
    spawn.request.y = 4.0;
    spawn.request.theta = 1.57;
    spawn.request.name = "turtle2";

    // 5-2、发送请求
    // 判断服务器状态
    // ros::service::waitForService("/spawn");
    client.waitForExistence();
    bool flag = client.call(spawn); // flag 接收响应状态，响应结果也会被设置进 spawn 对象

    // 6、处理响应； // 数据什么时候发送，是可控的，因此不需要 spinOnce 函数
    if(flag)
    {
        ROS_INFO("乌龟生成成功，新乌龟叫：%s", spawn.request.name.c_str());
    }
    else
    {
        ROS_INFO("请求失败！！！");
    }
    return 0;
}
```



#### 3、创建发布者

创建动态坐标变换中的发布者（与第三小节的发布者一致）

```C++
// 此处为 tf02_dynamic 功能包中的 demo01_dynamic_pub.cpp

#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h" // 欧拉角

/*
    发布方：需要订阅乌龟的位姿信息，转换成相对于窗体的坐标关系，并发布
    准 备：
        话题：/turtle1/pose
        消息：/turtlesim/Pose
    
    流程：
        1、包含头文件；
        2、设置编码、初始化、NodeHandle
        3、创建订阅对象，订阅 /turtle1/pose;
        4、回调函数处理订阅的消息：将位姿信息转换成坐标相对关系并发布（关注）
        5、spin()
*/

// 声明变量接收传递的参数
std::string turtle_name;

void doPose(const turtlesim::Pose::ConstPtr & pose)
{
    // 获取位姿信息，转换成坐标系相对关系（核心），并发布
    // a.创建发布对象
    static tf2_ros::TransformBroadcaster pub;

    // b.组织被发布的数据
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    // 关键点2：动态传入
    // ts.child_frame_id = "turtle1";
    ts.child_frame_id = turtle_name;


    // 坐标系偏移量设置
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;

    // 坐标系四元数
    /*
        位姿信息中没有四元数，但是有个偏航角度，又已知乌龟是 2D，没有翻滚与俯仰角度，
        所以可以得出乌龟的欧拉角：0 0 theta
    */
    tf2::Quaternion qtn;
    qtn.setRPY(0, 0, pose->theta);

    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();

    // c.发布
    pub.sendTransform(ts);
}

int main(int argc, char *argv[])
{
    /*
        解析 launch 文件通过 args 传入的参数
    */
    
    // 这里不一致
    if(argc != 4)
    {
        ROS_ERROR("请传入一个参数");
        return 1;
    }
    else
    {
        turtle_name = argv[1];
    }

    // 2、设置编码、初始化、NodeHandle
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "dynamic_pub");
    ros::NodeHandle nh;

    // 3、创建订阅对象，订阅 /turtle1/pose;

    // 关键点1：订阅的话题名称，turtle1 或 turtle2 动态传入
    ros::Subscriber sub = nh.subscribe(turtle_name + "/pose", 100, doPose);
    // 4、回调函数处理订阅的消息：将位姿信息转换成坐标相对关系并发布（关注）
    // 5、spin()
    ros::spin();
    return 0;
}
```



#### 4、创建订阅者

编写订阅方，订阅两只乌龟信息，生成速度信息并发布

需求：    

​			需求1：换算出 turtle1 相对于 turtle2 的关系；
​    				  需求2：计算角速度和线速度并发布。

**编写思路：**

1. 编码、初始化和NodeHandle

2. 创建订阅对象

    （1）创建缓冲区对象buffer（tf2_ros::Buffer）

    （2）创建监听者对象sub（tf2_ros::TransformListener），接收buffer作为参数

3. 创建发布者对象，发布话题名和发布频率

4. 编写解析逻辑：

    （1）计算 son1 和 son2 的相对关系

    （2）根据相对计算组织速度消息（设置线速度x和角速度z）

5. 发布速度消息

```c++
#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Twist.h"

/*
    需求1：换算出 turtle1 相对于 turtle2 的关系
    需求2：计算角速度和线速度并发布
*/

int main(int argc, char *argv[])
{
    // 2、编码、初始化、NodeHandle
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "tfs_sub");
    ros::NodeHandle nh;

    // 3、创建订阅对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);

    // A、创建发布对象
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 100);
    
    // 4、编写解析逻辑

    ros::Rate rate(10);
    while (ros::ok())
    {
        // 核心
        try
        {
            // 1、计算 son1 和 son2 的相对关系
            geometry_msgs::TransformStamped son1ToSon2 = buffer.lookupTransform("turtle2", "turtle1", ros::Time(0));

            // B、根据相对计算并组织速度消息
            geometry_msgs::Twist twist;
            /*
                组织速度，只需要设置线速度的 x 与角速度的 z
                x = 系数 * 开方(y^2 + x^2)
                z = 系数 * 反正切(对边，邻边)
            */
            twist.linear.x = 0.5 * sqrt(pow(son1ToSon2.transform.translation.x, 2) + pow(son1ToSon2.transform.translation.y, 2));
            twist.angular.z = 4 * atan2(son1ToSon2.transform.translation.y, son1ToSon2.transform.translation.x);

            // C、发布
            pub.publish(twist);
        }
        catch(const std::exception& e)
        {
            ROS_INFO("错误提示：%s", e.what());
            // std::cerr << e.what() << '\n';
        }

        rate.sleep();
        ros::spinOnce();
        
    }   

    return 0;
}
```





## 2、rosbag

在ROS中关于==数据的留存以及读取实现==，提供了专门的工具: rosbag。

### 1、rosbag使用——命令行

1. 录制

    ```
    rosbag record -a -o 目标文件
    ```

2. 查看文件

    ```
    rosbag info 文件名
    ```

3. 回放文件

    ```
    rosbag play 文件名
    ```



### 2、rosbag使用——编码

#### 1、写bag

```c++
#include "ros/ros.h"
#include "rosbag/bag.h"
#include "std_msgs/String.h"

/*
    需求：使用 rosbag 向磁盘文件写出数据（话题 + 消息）
    流程：
        1、导包；
        2、初始化；
        3、创建 rosbag 对象
        4、打开文件流；
        5、写数据；
        6、关闭文件流；
*/

int main(int argc, char *argv[])
{
    // 2、初始化；
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "bag_write");
    ros::NodeHandle nh;

    // 3、创建 rosbag 对象
    rosbag::Bag bag;

    // 4、打开文件流；
    bag.open("/home/yin-roc/1_Code/Ubuntu20.04/ROS_demo/demo02_ws/src/six_rosbag_demo/hello.bag", rosbag::BagMode::Write);

    // 5、写数据；
    std_msgs::String msg;
    msg.data = "hello xxxx ";

    /*
    参数1：话题
    参数2：时间戳
    参数3：消息
    */

    bag.write("/chatter", ros::Time::now(), msg);
    bag.write("/chatter", ros::Time::now(), msg);
    bag.write("/chatter", ros::Time::now(), msg);
    bag.write("/chatter", ros::Time::now(), msg);
    bag.write("/chatter", ros::Time::now(), msg);


    // 6、关闭文件流；
    bag.close();

    return 0;
}
```



#### 2、读bag

```c++
#include "ros/ros.h"
#include "rosbag/bag.h"
#include "rosbag/view.h"
#include "std_msgs/String.h"

/*
    需求：使用 rosbag 读取磁盘文件上的 bag 文件
    流程：
        1、导包；
        2、初始化；
        3、创建 rosbag 对象；
        4、打开文件流（以读的方式打开）；
        5、读数据
        6、关闭文件流
*/

int main(int argc, char *argv[])
{
    // 2、初始化；
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "bag_read");
    ros::NodeHandle nh;

    // 3、创建 rosbag 对象；
    rosbag::Bag bag;

    // 4、打开文件流（以读的方式打开）；
    bag.open("/home/yin-roc/1_Code/Ubuntu20.04/ROS_demo/demo02_ws/src/six_rosbag_demo/hello.bag", rosbag::BagMode::Read);
    
    // 5、读数据
    // 取出话题、时间戳和消息内容
    // 可以先获取消息的集合，再迭代出消息的字段
    for(auto && m :rosbag::View(bag))
    {
        // 解析
        std::string topic = m.getTopic();
        ros::Time time = m.getTime();
        std_msgs::StringPtr p = m.instantiate<std_msgs::String>();
        ROS_INFO("解析的内容，话题:%s, 时间戳:%.2f, 消息值:%s",
                    topic.c_str(),
                    time.toSec(),
                    p->data.c_str()
                    );
    }

    // 6、关闭文件流
    bag.close();
    
    return 0;
}
```



## 3、rqt工具箱

一些常用插件如下：

#### 1、rqt_graph

可视化显示计算图

#### 2、rqt_console

rqt_console 是 ROS 中用于显示和过滤日志的图形化插件

#### 3、rqt_plot

图形绘制插件，可以以 2D 绘图的方式绘制发布在 topic 上的数据

#### 4、rqt_bag

录制和重放 bag 文件的图形化插件
