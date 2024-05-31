#include <iostream>
#include "StudentController.cpp"
#include "ProfessorController.h"
#include "../include/DLOList.h"

void displayMenu() {
    std::cout << "1. Consultar promedio de un estudiante" << std::endl;
    std::cout << "2. Promedio de estudiantes en un curso" << std::endl;
    std::cout << "3. Promedio por tema de todos los estudiantes de un profesor" << std::endl;
    std::cout << "4. Lista de profesores" << std::endl;
    std::cout << "5. Añadir profesor" << std::endl;
    std::cout << "6. Estudiantes con nota superior en un tema" << std::endl;
    std::cout << "7. General ParcialXX.bin" << std::endl;
    std::cout << "8. Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
}

int main(int argc, char** argv) {
	std::cout << "epale iniciando "<<std::endl;
    StudentController controller("../data/Students.txt");
    ProfessorController profController;
    ProfessorDAO dao("../data/Professors.txt");
    
    
    std::cout << "controller creado"<<std::endl;
    controller.pruebota();
    int option;
    do {
        displayMenu();
        std::cin >> option;
        switch (option) {
            case 1: {
                long id;
                std::cout << "Ingrese ID del estudiante: ";
                std::cin >> id;
                Student* student = controller.getStudentById(id);
                if (student) {
                    float average = controller.calculateAverageGrade(student);
                    std::cout << "Nombre:" << student->getName() << " Promedio del estudiante: " << average << std::endl;
                } else {
                    std::cout << "Estudiante no encontrado." << std::endl;
                }
                break;
            }
            case 2: {
                std::string course;
                std::cout << "Ingrese el curso: ";
                std::cin >> course;
                controller.averageGradeByCourse(course);
                break;
            }
            case 3: {
                std::string professor;
                std::cout << "Ingrese el profesor: ";
                std::cin >> professor;
                controller.averageGradeByTopic(professor);
                break;
            }
            case 4: {
                DLOList<Professor *> *professors = profController.getProfessors(); // Usa el m?todo getProfessors de ProfessorController
    for (int i = 0; i < professors->length(); i++)
    {
        Professor *prof = professors->get(i);
        std::cout << "CC: " << prof->getId() << ", Nombre: " << prof->getNames() << " " << prof->getLastNames() << ", Número de clases: " << prof->getClassesNumber()<< std::endl;
    }
                break;
            }
            case 5: {
            	std::string aux;
            	int aux1;
                Professor* prof1 = new Professor();
                std::cout<<"Ingrese cedula:"<<std::endl; 
                std::cin>>aux1;
				prof1->setId(aux1);
                std::cout<<"Ingrese el nombre:"<<std::endl; 
                std::cin>>aux;
				prof1->setNames(aux);
                std::cout<<"Ingrese el apellido:"<<std::endl; 
                std::cin>>aux;
				prof1->setLastNames(aux);
                std::cout<<"Ingrese numero de clases:"<<std::endl; 
                std::cin>>aux1;
				prof1->setClassesNumber(aux1);
            	profController.addProfessor(prof1);
                break;
            }
            case 6: {
                float grade;
                std::string topic;
                std::cout << "Ingrese la nota: ";
                std::cin >> grade;
                std::cout << "Ingrese el tema: ";
                std::cin >> topic;
                controller.studentsWithGradeAbove(grade, topic);
                break;
            }
            case 7: {
				controller.generatePartialFiles();
                break;
            }
            case 8:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
                break;
        }
    } while (option != 6);

    return 0;
}
