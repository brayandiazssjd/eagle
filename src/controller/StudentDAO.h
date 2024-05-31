#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "File.h"
#include "../../include/Student.h"
#include "../../include/Queue.h"

class StudentDAO : public File{
	private:
		int count = 0;
		int parcial = 1;
		
	public:
		StudentDAO(const std::string& _path) : File(_path){
		}
		
		Student* createStudent(int line){
			std::vector<std::string> info = readDataFromLine<std::string>(line);
			std::cout << "vector creado"<<std::endl;
			if(!info.empty()){

				std::vector<Grade*> grades;
				std::vector<Point*> pointsToDelete;
				std::cout << "vectores grades y points creados"<<std::endl;
				for(int i=5 ; i<info.size(); i++){
	                if ((i - 4) % 10 == 0) {  // Ajuste de índices para cambiar de parcial.
	                    parcial++;
	                }
		            Point* point = new Point("topic" + std::to_string(i), std::stof(info[i]));
		            pointsToDelete.push_back(point);
				    std::cout << "pointsToDelete.push_back"<<std::endl;
				    grades.push_back(new Grade("parcial" + std::to_string(parcial), 10.0, point));
				    std::cout << "grades.push_back"<<std::endl;
				}
				Student *student = new Student(info[2]+" "+info[3], stol(info[0]), grades);
				std::cout << "student new creado"<<std::endl;
				for (Point* point : pointsToDelete) {
				    delete point;
				}
				return student;

			}else{
				return nullptr;
			}	
		}
		
	    Queue<Student*>* getStudents() {
	    	std::cout << "get students"<<std::endl;
	    	count=1;
	        Queue<Student*>* stuQ = new Queue<Student*>;
	        std::cout << "stuq creada"<<std::endl;
	        //parcial = stoi(readDataFromLine<std::string>(count)[0]);
	        //count++;
	        Student* student = createStudent(count);
	        std::cout << "estudiante creado"<<std::endl;
	        count++;
	        while(student != nullptr){
	        	stuQ->enqueue(student);
	        	std::cout << "enqueued student"<<std::endl;
	        	student = createStudent(count);
	        	count++;
			}
			std::cout << "a retornar"<<std::endl;
	        return stuQ;
	    }
	    
	    void writeStudent(Student* stu) {
	        std::ostringstream oss;
	        oss << stu->getId()<< " "<< stu->getCourse() << " " << stu->getName();
	        std::vector<Grade*> grades = stu->getGrades();
	        for (Grade* grade : grades) {
	            oss << " " << grade->getPoint()->getPercentage();
	        }
	        writeLine(count, oss.str());
	        count++;
	    }
	    
	    int getCount(){
	    	return count;
		}
};
