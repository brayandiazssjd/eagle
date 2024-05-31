#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "../../include/Tree2.h"
#include "StudentDAO.h"
//#include "../../include/Student.h"
#include "../../include/Student.h"
#include "../../include/Grade.h"
#include "../../include/Point.h"

class StudentController {
private:
    Tree<Student*>* studentTree;
    StudentDAO* studentDAO;
    Queue<Student*>* students, *pruebita;

public:
    StudentController(const std::string& filePath){
    	studentDAO = new StudentDAO(filePath);
    	std::cout << "creado Dao"<<std::endl;
    	students = studentDAO->getStudents();
    	pruebita = studentDAO->getStudents();
    	std::cout << "queue creada "<<std::endl;
    	studentTree = new Tree<Student*>(studentDAO->getCount());
    	std::cout << "tree creado"<<std::endl;
        loadStudents(students);
    }

	~StudentController() {
	    delete studentTree;
	    delete studentDAO;
	}

	void pruebota(){
		while(!pruebita->isEmpty()){
			Student* student = pruebita->denqueue();
			std::cout<< "ID" << student->getId() << "Nombre "<< student->getName() << std::endl;
		}
	}

    void loadStudents(Queue<Student*>* students) {
        std::cout << "loading students "<<std::endl;
        
        while (!students->isEmpty()) {
            Student* student = students->denqueue();
            std::cout << "dequeue"<<std::endl;
            studentTree->add(student);
            std::cout << "añadadido al arbocol"<<std::endl;
        }
        delete students;
    }

	Student* getStudentById(long id) {
		std::cout << "ESTA? "<< studentTree->findBool(id) <<std::endl;
	    Student* student = studentTree->find(id);
	    return student;
	}


    float calculateAverageGrade(Student* student) {
        std::vector<Grade*> grades = student->getGrades();     
        float total = 0;
        for (Grade* grade : grades) {
        	Point* points = grade->getPoint();
            total += points->getPercentage();
        }
        return total / grades.size()-4;
    }

    void averageGradeByCourse(std::string course) {
        // Implementación para calcular el promedio de los estudiantes en un curso específico
    }

    void averageGradeByTopic(std::string topic) {
        // Implementación para calcular el promedio de los estudiantes por tema
    }

    void listTeachersByClassCount(int classCount) {
        // Implementación para listar profesores por cantidad de clases
    }

    void studentsWithGradeAbove(float grade, std::string topic) {
        // Implementación para listar estudiantes con nota superior en un tema específico
    }
};
