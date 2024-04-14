# rviz2_plugin_ser2res
rviz2_plugin_ser2res is a RViz plugin for resetting displays via service.
## Dependencies
Ubuntu 22.04

ROS2 Humble
## Compilation
```
cd ~/ros2_ws/src
git clone https://github.com/ASIG-X/rviz2_plugin_ser2res
cd ..
colcon build --symlink-install --packages-select rviz2_plugin_ser2res
```
## Usage
To use this plugin, please follow the steps below.

1. Click on the “+” button in the toolbar of RViz2.
2. Select "ser2res" under "rviz2_plugin_ser2res".
3. Reset all displays by using the following two methods:

* Open a new terminal and run
```
ros2 service call /rviz2/reset_time std_srvs/srv/Empty
```
* Alternatively, you can create a client in your code 
```
rclcpp::Client<std_srvs::srv::Empty>::SharedPtr client = nh->create_client<std_srvs::srv::Empty>("/rviz2/reset_time");
```
and send a request  
```
auto request = std::make_shared<std_srvs::srv::Empty::Request>();
auto result = client->async_send_request(request);
rclcpp::Rate rate(10);
while (!result.valid()) {
    rate.sleep();
}
```
## Contributors
Ziyu Cao (email: ziyu.cao@liu.se)

Kailai Li (email: kailai.li@rug.nl)
## License
The source code is released under [GPLv3](https://www.gnu.org/licenses/) license.

We are constantly working on improving our code. For any technical issues, please contact Ziyu Cao (ziyu.cao@liu.se).
