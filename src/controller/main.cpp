#include <iostream>
#include "StudentController.cpp"

void displayMenu() {
    std::cout << "1. Consultar promedio de un estudiante" << std::endl;
    std::cout << "2. Promedio de estudiantes en un curso" << std::endl;
    std::cout << "3. Promedio por tema de todos los estudiantes de un profesor" << std::endl;
    std::cout << "4. Lista de profesores por número de clases" << std::endl;
    std::cout << "5. Estudiantes con nota superior en un tema" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
}

int main(int argc, char** argv) {
	std::cout << "epale iniciando "<<std::endl;
    StudentController controller("../../data/Students.txt");
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
                int classCount;
                std::cout << "Ingrese el número de clases: ";
                std::cin >> classCount;
                controller.listTeachersByClassCount(classCount);
                break;
            }
            case 5: {
                float grade;
                std::string topic;
                std::cout << "Ingrese la nota: ";
                std::cin >> grade;
                std::cout << "Ingrese el tema: ";
                std::cin >> topic;
                controller.studentsWithGradeAbove(grade, topic);
                break;
            }
            case 6:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
                break;
        }
    } while (option != 6);

    return 0;
}
