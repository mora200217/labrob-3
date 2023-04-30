
const char* msg = R"(
-------------------------------
Movimiento
  W: Mover al frente
  S: Mover atrás
  A: Girar izquierda (CCW)
  D: Girar Dereca (CW)

  R: Volver a origen
  SPACE: Girar 180º
-------------------------------
-------------------------------
Integrantes: 
    - Nelson David Ramirez 
    - Andrés Morales Martínez
    - Felipe Zuleta Romero

CTRL-C to quit
)";


// turtlesim_node parámetros
const float _HALF_WIDTH = 5.5; 
const float _HALF_HEIGHT = 5.5; 

float _DEFAULT_LINEAR_VEL = 1.5;  // unidades 
float _DEFAULT_ANGULAR_VEL = 1.0; // rads

int getch(void); 

