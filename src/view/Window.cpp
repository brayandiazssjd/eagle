#include "../../include/Window.h"
/*Window::Window(Listener l) {
                this.l = l;
        }

Window::void print(int f, int s) {
                switch (f) {
                        case 1 -> {

                        }
                }*/

int man() {
  std::cout
      << "\tSeleccione:\n\t1 para consultar\n\t2 para editar\n\t3 para guardar";
  int input = 0;
  std::cin >> input;
  return input;
}

int Window::add() {
  std::cout << "\t1 para profesor\n\t2 para estudiantes\n\t3 para tema";
  int input = 0;
  std::cin>>input;
  return input;
}

template <typename T>
void print(T mss) {
  
}


int Window::update() { 
  std::cout << "\t1 para estudiante\n\t2 para profesor\n\t3 para nota";
  int input = 0;
  std::cin>>input;
  return input;
}

int Window::consult() {
  std::cout << "\t1 para la inforamación de un estudiante" << std::endl
            << "\t2 para ver los estudiantes en un curso" << std::endl
            << "\t3 para estudiantes con una nota superior" << std::endl
            << "\t4 para profesores con un número dado de clases" << std::endl
            << "\t5 para el promedio de notas de los estudiantes que ven clase "
               "con un profesor";
  int input = 0;
  std::cin >> input;
  return input;
}

