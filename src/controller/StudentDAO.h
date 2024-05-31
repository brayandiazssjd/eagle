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
		int parcial;
		
	public:
		StudentDAO(const std::string& _path) : File(_path){
		}
		
		Student* createStudent(int line){
			std::vector<std::string> info = readDataFromLine<std::string>(line);
			if(!info.empty()){
				Point *points;
				std::vector<Grade*> grades;
				for(int i=3 ; i<=info.size(); i++){
					points = new Point("topic"+std::to_string(i), stol(info[i]));
					grades.push_back(new Grade("parcial" + std::to_string(parcial), 10.0, points));
					delete points;
				}
				Student *student = new Student(info[1]+" "+info[2], stol(info[0]), grades);
				return student;	
			}else{
				return nullptr;
			}	
		}
		
	    Queue<Student*>* getStudents() {
	    	count=1;
	        Queue<Student*>* stuQ = new Queue<Student*>;
	        parcial = stoi(readDataFromLine<std::string>(count)[0]);
	        count++;
	        Student* student = createStudent(count);
	        count++;
	        while(student != nullptr){
	
	        	stuQ->enqueue(student);
	        	student = createStudent(count);
	        	count++;
			}
	        return stuQ;
	    }
	    void writeStudent(Student* stu) {
	        std::ostringstream oss;
	        oss << stu->getId() << " " << stu->getName();
	        std::vector<Grade*> grades = stu->getGrades();
	        for (Grade* grade : grades) {
	            oss << " " << grade->getPoint()->getPercentage();
	        }
	        writeLine(count, oss.str());
	        //count++;
	    }
};
