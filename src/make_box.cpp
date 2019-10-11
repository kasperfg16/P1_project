#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/TeleportAbsolute.h>
#include <turtlesim/SetPen.h>
#include <iostream>

#include <stdlib.h>
/* srand, rand */s
#include <time.h>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "move_turtlesim");

  float box_size = ros::param::param("~box_size", 9.0);

  int width = 0;
  float offset = 5.5f;
  int red = 0;
  int blue = 0;
  int green = 0;

  srand (time(NULL));
  width = rand() % 10 + 1;
  red = rand() % 255 + 1;
  green = rand() % 255 + 1;
  blue = rand() % 255 + 1;

/*

    std::cout << "Define Width: ";
    std::cin >> width;

*/

std::cout << "Width: " << width << std::endl;

  ros::NodeHandle nh;

  ros::service::waitForService("/turtle1/teleport_absolute", -1);

  ros::ServiceClient teleport_client = nh.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
  ros::ServiceClient pen_client = nh.serviceClient<turtlesim::SetPen>("/turtle1/set_pen");


  turtlesim::SetPen pen_srv;
  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  turtlesim::TeleportAbsolute srv;

  srv.request.x = 5.5-box_size/2;
  srv.request.y = 5.5-box_size/2;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = width;
  pen_srv.request.r = red;
  pen_srv.request.g = green;
  pen_srv.request.b = blue;
  pen_client.call(pen_srv);


  srv.request.x = offset-box_size/2;
  srv.request.y = offset+box_size/2;
  teleport_client.call(srv);

  srv.request.x = offset+box_size/2;
  srv.request.y = offset+box_size/2;
  teleport_client.call(srv);

  srv.request.x = offset+box_size/2;
  srv.request.y = offset-box_size/2;
  teleport_client.call(srv);

  srv.request.x = offset-box_size/2;
  srv.request.y = offset-box_size/2;
  teleport_client.call(srv);

  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  srv.request.x = offset;
  srv.request.y = offset;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = 4;
  pen_srv.request.r = red;
  pen_srv.request.g = green;
  pen_srv.request.b = blue;
  pen_client.call(pen_srv);

  return 0;
}
