%%
rosshutdown;  clear; clc; close all; 
%%
rosinit(); %Conexi ́on con nodo maestro
%%
velPub = rospublisher("/turtle1/cmd_vel","geometry_msgs/Twist"); %Creaci ́on publicador 
velMsg = rosmessage(velPub); %Creaci ́on de mensaje

velSub = rossubscriber("/turtle1/cmd_vel","geometry_msgs/Twist"); %Creaci ́on publicador 

%%
for i = 1:10 
    velMsg.Linear.X = -i; %Valor del mensaje
    velMsg.Angular.Z = pi ; %Valor del mensaje
    send(velPub,velMsg); %Envio
    pause(1)

end 

