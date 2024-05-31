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
    
	void generatePartialFiles() {
	    std::map<int, std::vector<float>> partialScores;
	    std::map<int, int> questionCount;
	
	    Queue<Student*>* tempQueue = studentDAO->getStudents();
	    while (!tempQueue->isEmpty()) {
	        Student* student = tempQueue->denqueue();
	        std::vector<Grade*> grades = student->getGrades();
	        int parcial = 1;
	        for (size_t i = 0; i < grades.size(); ++i) {
	            if ((i % 10 == 0) && (i != 0)) {
	                parcial++;
	            }
	            partialScores[parcial].push_back(grades[i]->getPoint()->getPercentage());
	            questionCount[parcial] = 10;
	        }
	        delete student;
	    }
	    delete tempQueue;
	
	    for (const auto& entry : partialScores) {
	        int parcial = entry.first;
	        const std::vector<float>& scores = entry.second;
	        std::string fileName = "Parcial" + std::to_string(parcial) + ".txt";
	        File outFile(fileName);
	
	        std::vector<std::string> lines;
	
	        for (int question = 1; question <= questionCount[parcial]; ++question) {
	            float sum = 0;
	            int count = 0;
	            for (size_t i = question - 1; i < scores.size(); i += 10) {
	                sum += scores[i];
	                count++;
	            }
	            float average = (count > 0) ? sum / count : 0;
	
	            std::ostringstream oss;
	            oss << "Pregunta " << question << ": " << average;
	            lines.push_back(oss.str());
	        }
	
	        outFile.writeLines(lines);
	        std::cout << "Archivo " << fileName << " generado." << std::endl;
	    }
	}


    
};
