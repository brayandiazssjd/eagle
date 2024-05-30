#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "File.h"
#include "Student.h"
#include "Queue.h"

class StudentDAO : public File{
	private:
		int count = 50;
		
	public:
		StudentDAO(const std::string& _path) : File(_path){
		}
		
		//Las lineas saltan de a 4
		Student* createStudent(int line){
			std::vector<std::string> info = readDataFromLine<std::string>(line);
			Student *student = new Student(info[2]+" "+info[3], stol(info[0]), nullptr);
			return student;
		}
		
	    Queue<Student*>* getStudents() {
	        Queue<Student*>* stuQ = new Queue<Student*>;
	        for (int i = 1; i <= count; i++) {
	            Student* student = createStudent(i);
	            if (student != nullptr) {
	                stuQ->enqueue(student);
	            }
	        }
	        return stuQ;
	    }
		void writeStudent(Student* stu){
			writeLine(count+1, stu->getId()+" "+stu->getName());
			count++;
		}
};
