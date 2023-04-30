/**
 * Teleop2
 * ---
 *  Interfaz de control para turtlesim, con funcionalidades 
 *  adicionales sobre el movimiento de la tortuga. Usa termios
 *  para la lectura de datos. 
 * 
 *  Laboratoio 3 de Robótica - Universidad Nacional de Colombia 
 *
 * 
 *  @author Nelson David Ramirez 
 *  @author Felipe Zuleta Romero
 *  @author Andrés Morales Martínez
 * 
 *  @version 0.1v 
 *  @date 29-Abril-2023
 * 
*/

#include "ros/ros.h"
#include <turtlesim/TeleportRelative.h>
#include <turtlesim/TeleportAbsolute.h>
#include <geometry_msgs/Twist.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <iostream>

#include "teleop2.h"

char key(' ');

turtlesim::TeleportAbsolute::Request req_abs; 
turtlesim::TeleportAbsolute::Response res_abs; 

turtlesim::TeleportRelative::Request req;
turtlesim::TeleportRelative::Response res;

int main(int argc, char** argv){
    // iniciar nodo 
    ROS_INFO("Iniciando nuevo comando de control <turtlesim>"); 
    ros::init(argc, argv, "turtle_teleop_key2"); 
    
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
    geometry_msgs::Twist twist; // Crear el mensaje 

    printf("%s", msg); // GUI message
    
    // Creación de servicios (TeleportRelative, TeleportRelative)
    ros::ServiceClient relative_tp = nh.serviceClient<turtlesim::TeleportRelative>("/turtle1/teleport_relative");
    ros::ServiceClient absolute_tp = nh.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
    
    while(true){
        key = getch();
            
        // Twist vacío
        twist.linear.x = 0.0; twist.linear.y = 0.0; twist.linear.z = 0.0;
        twist.angular.x = 0.0; twist.angular.y = 0.0; twist.angular.z = 0.0;
     
     // Flujo de control 
    switch (key)
    {   
    case 'w':
        // ROS_INFO("Up"); 
        twist.linear.x = _DEFAULT_LINEAR_VEL; 
        break;

    case 's':
        // ROS_INFO("Down"); 
        twist.linear.x = -1.0 * _DEFAULT_LINEAR_VEL; 
        break;

    case 'a':
        // ROS_INFO("CCW"); 
        twist.angular.z = _DEFAULT_LINEAR_VEL; 
        break;

    case 'd':
        // ROS_INFO("CW"); 
        twist.angular.z = -1.0 * _DEFAULT_LINEAR_VEL; 
        break;

    case 'r':
        // ROS_INFO("Posición inicial"); 
        req_abs.theta = 0.0; 
        req_abs.x = _HALF_WIDTH; 
        req_abs.y = _HALF_HEIGHT; 

        absolute_tp.call(req_abs, res_abs); 
        break;
    case ' ':
        req.angular = 3.14; 
        req.linear = 0; 
        bool succ = relative_tp.call(req, res); 
        break;
    }

    pub.publish(twist); // Publicar al tópico
    
    
    // Cancel node 
    if (key == '\x03'){
        printf("Gracias por usar turtle_teleop_key2\n Apoyanos en nuestro repo en GH <3");
        break;
    }
    ros::spinOnce();
    }
    return 1; 
}


int getch(void)
{
  int ch;
  struct termios oldt;
  struct termios newt;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;

  newt.c_lflag &= ~(ICANON | ECHO);
  newt.c_iflag |= IGNBRK;
  newt.c_iflag &= ~(INLCR | ICRNL | IXON | IXOFF);
  newt.c_lflag &= ~(ICANON | ECHO | ECHOK | ECHOE | ECHONL | ISIG | IEXTEN);
  newt.c_cc[VMIN] = 1;
  newt.c_cc[VTIME] = 0;
  tcsetattr(fileno(stdin), TCSANOW, &newt);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return ch;
}