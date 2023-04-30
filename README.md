# Laboratorio #3 Robótica
Tercer laboratorio de la asignatura de Robótica de la Universidad Nacional de Colombia 2023-i.

<p align="center">
<img width="40%" src="https://github.com/mora200217/labrob-3/blob/master/assets/turtle.gif" /> 
</p>



**Integrantes**: 
* Nelson David Ramírez Marín
* Andrés Zuleta 
* Andrés Morales Martínez


## Planteamiento del Problema 
ROS(Robot Operation System) es un middleware robótico, es decir, una colección de frameworks para el desarrollo de software de robots, el cual tiene cierta estructura y semantica que debe ser previamente conocida para lograr su uso de manera eficaz y optima.
 
## Desarrollo 
Se escribio un código en C++ que permite operar una tortuga del paquete turtlesim con el teclado, el cual tiene las siguientes funciones:
- Se mueve hacia adelante y hacia atrás con las teclas W y S
- Gira en sentido horario y antihorario con las teclas D y A.
- Retorna a su posición y orientación centrales con la tecla R
- Da un giro de 180° con la tecla ESPACIO

Se emplea el uso de publishers y de servicios para publicar al tópico `/turtle1/cmd_vel` o llamar los servicios `turtlesim/TeleportRelative` y turtlesim/TeleportAbsolute`

### Estructura del proyecto 

Todo el proyecto está dentro del catkin workspace `turtle_patch`. El paquete central se llama `turtle_control`. Contiene un `.launch` y un nodo ejecutable. 

## Guía de uso
Agrega el pkg a source. 
```
source devel/setup.bash
```

Para correr el proyecto, basta con ejecutar el `example.launch`

```
roslaunch turtle_control example.launch
```

Esto llamará el `tustlesim_node` para vizualizar la tortuga, y el nodo `turtle_teleop_key2` para la GUI de control de movimiento. 

<p align="center">
 <img width="70%" src="https://github.com/mora200217/labrob-3/blob/master/assets/example_launch.png"/>
 </p> 


https://user-images.githubusercontent.com/24869683/235335727-a4c7a3c0-7fd8-4062-9133-6eebed02b2cf.mp4




## Conclusiones

1. Saber la sintaxis que se usan en diferentes lenguajes de programacion, como Python o C++, da una vision y recursividad mas amplia a la hora de elegir en donde se puede programar un codigo.
2. El framework ROS con su metodo de conectar nodos ayuda a realizar diversas operaciones de una manera rápida y sencilla.
3. Los servicios son una herramienta o método bastante util para usar subrutinas de manera mas eficiente.
