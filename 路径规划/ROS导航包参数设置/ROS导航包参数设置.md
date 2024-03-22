https://blog.csdn.net/zong596568821xp/article/details/77848101



首先了解在导航堆中，move_base包与其它包（如amcl、map_server）的关系，如图所示



在move_base节点运行前需要四个配置文件，这些文件定义了一系列相关参数，包括越过障碍物的代价、机器人的半径、路径规划时需要考虑未来多长的路、我们想让机器人以多块的速度移动等等。这四个配置文件分别是：

base_local_planner_params.yaml

costmap_common_params.yaml

global_costmap_params.yaml

local_costmap_params.yaml

导航包使用两个成本地图来存储有关地图的障碍物信息。一个成本地图用于全局规划，意味着在整个环境中创建长期计划，另一个用于本地规划和避障。有一些配置选项，我们希望两个代价地图都使用，一些我们要在每种代价地图上单独设置。因此，下面有三个部分用于代价地图的配置：常用配置选项，全局配置选项和本地配置选项。

注意：以下部分仅涵盖了代价地图的基本配置选项。有关各种选项的文档，请参阅costmap_2d文档（http://wiki.ros.org/costmap_2d）

导航包使用代价地图存储有关障碍物的信息。为了正确执行此操作，我们需要为costmaps指定应该监听传感器主题和更新频率。我们创建一个名为costmap_common_params.yaml的文件，如下所示，并填写：、

```
obstacle_range: 2.5
raytrace_range: 3.0
footprint: [[x0, y0], [x1, y1], ... [xn, yn]]
#robot_radius: ir_of_robot
inflation_radius: 0.55

observation_sources: laser_scan_sensor point_cloud_sensor

laser_scan_sensor: {sensor_frame: frame_name, data_type: LaserScan, topic: topic_name, marking: true, clearing: true}

point_cloud_sensor: {sensor_frame: frame_name, data_type: PointCloud, topic: topic_name, marking: true, clearing: true}
```

让我们将上面的文件分解说明。

```
obstacle_range: 2.5
raytrace_range: 3.0
```

这些参数设置了代价地图中的障碍物信息的阈值。 "obstacle_range" 参数确定最大范围传感器读数，这将导致障碍物被放入代价地图中。在这里，我们把它设置在2.5米，这意味着机器人只会更新其地图包含距离移动基座2.5米以内的障碍物的信息。“raytrace_range”参数确定了用于清除指定范围外的空间。将其设置为3.0米，这意味着机器人将尝试清除3米外的空间，在代价地图中清除3米外的障碍物。

```
footprint: [[x0, y0], [x1, y1], ... [xn, yn]]
#robot_radius: ir_of_robot
inflation_radius: 0.55
```

在这里，我们设置机器人的占用面积或机器人的半径是圆形。在指定占地面积的情况下，假设机器人的中心处于（0.0,0.0），并且支持顺时针和逆时针规格。我们还将设定代价地图的膨胀半径。膨胀半径应设定为在代价地图的与障碍物保持安全的最大距离。例如，将膨胀半径设定为0.55米，意味着机器人针对相同的障碍物获取的所有路径都保持距离障碍物0.55米或更远。如果你的机器人不能很好地通过窄门或其它狭窄的地方，则稍微减小这个值，相反地，如果机器人不断地撞到东西，则尝试增大这个值。

```
observation_sources: laser_scan_sensor point_cloud_sensor
```

“observe_sources”传感器源参数定义把信息传递给代价地图的传感器列表，以空格分隔每个传感器，每个传感器分别定义。

```
laser_scan_sensor: {sensor_frame: frame_name, data_type: LaserScan, topic: topic_name, marking: true, clearing: true}
```

设置上述传感器源observation_sources的传感器信息。以laser_scan_sensor作为例子，应将“frame_name”参数设置为传感器坐标系的名称，“data_type”参数应根据话题使用的消息设置为LaserScan或PointCloud，并将“topic_name”设置为传感器发布数据的话题。“marking”和“clearing”参数确定传感器是否向代价地图添加障碍物信息或从代价地图中清除障碍物信息，或者同时都做。

全局代价地图配置（global_costmap_params.yaml）
我们将在下面创建一个文件，用于存储特定于全局代价地图的配置选项。打开一个带有global_costmap_params.yaml文件的编辑器，并粘贴到以下文本中：

```
global_costmap:
  global_frame: /map
  robot_base_frame: base_link
  update_frequency: 5.0
  static_map: true
```

“global_frame”参数定义了代价地图应该运行的坐标系，在这种情况下，我们将选择/map坐标系。对于全局代价地图，我们用map框架来作为global框架。

“robot_base_frame”参数定义了代价地图应该为机器人的基座的坐标系。这个通常不是base_link就是base_footprint。对于turtlebot应设为base_footprint。

“update_frequency”参数决定了代价地图更新的频率（以Hz为单位）。根据传感器数据，全局地图更新的频率，这个数值越大，你的计算机的CPU负担会越重，特别对于全局地图，通常设定一个相对较小、在1.0到5.0之间的值。

“static_map”参数确定是否由map_server提供的地图服务来进行代价地图的初始化。如果您没有使用现有的地图或地图服务器，请将static_map参数设置为false。当本地地图需要根据传感器数据动态更新的时候，我们通常会把这个参数设为false。

本地代价地图配置（local_costmap_params.yaml）
我们将在下面创建一个文件，它将存储特定于本地代价地图的配置选项。打开一个带有文件local_costmap_params.yaml的编辑器并粘贴到以下文本中：

```
local_costmap:
  global_frame: odom
  robot_base_frame: base_link
  update_frequency: 5.0
  publish_frequency: 2.0
  static_map: false
  rolling_window: true
  width: 6.0
  height: 6.0
  resolution: 0.05
```

“global_frame”，“robot_base_frame”，“update_frequency”和“static_map”参数与上述“全局代价地图配置”部分中描述的相同。“publish_frequency”参数确定代价地图发布可视化信息的速率（以Hz为单位）。将“rolling_window”参数设置为true意味着当机器人移动时，保持机器人在本地代价地图中心。“宽度”，“高度”和“分辨率”参数设置本地代价地图（滑动地图）的宽度（米），高度（米）和分辨率（米/单元格）。请注意，这个网格的分辨率与静态地图的分辨率不同，但大多数时候我们倾向设置为相同值。

完整的配置选项
此最低配置应该可以运行，但是有关可用于代价地图的配置选项的更多详细信息，请参阅costmap_2d文档。

基本本地规划器配置/base_local_planner_params.yaml
base_local_planner负责把上层规划器计算的速度指令发送给移动基座。我们需要根据我们的机器人的规格来设置一些配置选项，以便开始运行。打开一个名为base_local_planner_params.yaml的文件，并粘贴以下文本：

```
TrajectoryPlannerROS:
  max_vel_x: 0.45
  min_vel_x: 0.1
  max_vel_theta: 1.0
  min_in_place_vel_theta: 0.4

  acc_lim_theta: 3.2
  acc_lim_x: 2.5
  acc_lim_y: 2.5

  holonomic_robot: true
```

上述参数的第一部分定义了机器人的速度限制。第二部分定义了机器人的加速度限制。
注意：本节仅介绍TrajectoryPlanner的基本配置选项。有关各种选项的文档，请参阅base_local_planner文档。

创建导航包的启动文件
现在我们已经有了所有的配置文件，我们需要把所有的东西放在导航包的启动文件中。打开一个带有move_base.launch文件的编辑器并粘贴以下文本：

```
<launch>
  <master auto="start"/>

  <!-- Run the map server -->
  <node name="map_server" pkg="map_server" type="map_server" args="$(find my_map_package)/my_map.pgm my_map_resolution"/>

  <!--- Run AMCL -->
  <include file="$(find amcl)/examples/amcl_omni.launch" />

  <node pkg="move_base" type="move_base" respawn="false" name="move_base" output="screen">
    <rosparam file="$(find my_robot_name_2dnav)/costmap_common_params.yaml" command="load" ns="global_costmap" />
    <rosparam file="$(find my_robot_name_2dnav)/costmap_common_params.yaml" command="load" ns="local_costmap" />
    <rosparam file="$(find my_robot_name_2dnav)/local_costmap_params.yaml" command="load" />
    <rosparam file="$(find my_robot_name_2dnav)/global_costmap_params.yaml" command="load" />
    <rosparam file="$(find my_robot_name_2dnav)/base_local_planner_params.yaml" command="load" />
  </node>
</launch>
```

您需要对此文件进行的唯一更改是将地图服务器更改为指向已创建的地图，如果您有差分驱动器机器人，则将“amcl_omni.launch”更改为“amcl_diff.launch”。

AMCL配置（amcl）
AMCL有许多配置选项会影响本地化的性能。（待补充）

amcl的英文全称是adaptive Monte Carlo localization，其实就是蒙特卡洛定位方法的一种升级版，使用自适应的KLD方法来更新粒子，这里不再多说（主要我也不熟），而mcl（蒙特卡洛定位）法使用的是粒子滤波的方法来进行定位的。而粒子滤波很粗浅的说就是一开始在地图空间很均匀的撒一把粒子，然后通过获取机器人的motion来移动粒子，比如机器人向前移动了一米，所有的粒子也就向前移动一米，不管现在这个粒子的位置对不对。使用每个粒子所处位置模拟一个传感器信息跟观察到的传感器信息（一般是激光）作对比，从而赋给每个粒子一个概率。之后根据生成的概率来重新生成粒子，概率越高的生成的概率越大。这样的迭代之后，所有的粒子会慢慢地收敛到一起，机器人的确切位置也就被推算出来了。 

首先在参数表里面有几个比较重要的参数。 

```
~initial_pose_x (double, default: 0.0 meters) 
Initial pose mean (x), used to initialize filter with Gaussian distribution. 
~initial_pose_y (double, default: 0.0 meters) 
Initial pose mean (y), used to initialize filter with Gaussian distribution. 
~initial_pose_a (double, default: 0.0 radians) 
Initial pose mean (yaw), used to initialize filter with Gaussian distribution. 
~initial_cov_xx (double, default: 0.5*0.5 meters) 
Initial pose covariance (x*x), used to initialize filter with Gaussian distribution. 
~initial_cov_yy (double, default: 0.5*0.5 meters) 
Initial pose covariance (y*y), used to initialize filter with Gaussian distribution. 
~initial_cov_aa (double, default: (π/12)*(π/12) radian) 
Initial pose covariance (yaw*yaw), used to initialize filter with Gaussian distribution.
```

这个代表了你初始化粒子时粒子分布的一个状态，注意要把方差设的大一些，要不所有例子上来就是一坨的就没法玩了。 

