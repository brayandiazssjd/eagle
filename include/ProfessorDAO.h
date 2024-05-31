#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "File.h"
#include "Professor.h"
#include "Queue.h"

class ProfessorDAO : public File{
    private:
        int count = 0;
        
    public:
        ProfessorDAO(const std::string& _path) : File(_path){
        }
        
        Professor* createProfessor(int line){
            std::vector<std::string> info = readDataFromLine<std::string>(line);
            if(!info.empty()){
                Professor *professor = new Professor();
                professor->setNames(info[1]);
                professor->setLastNames(info[2]);
                professor->setId(stoi(info[0]));
                professor->setClassesNumber(stoi(info[3]));
                return professor;	
            }else{
                return nullptr;
            }	
        }
        
        Queue<Professor*>* getProfessors() {
        	count=1;
            Queue<Professor*>* profQ = new Queue<Professor*>;
            Professor* professor = createProfessor(count);
            count++;
            while(professor != nullptr){
            	profQ->enqueue(professor);
            	professor = createProfessor(count);
            	count++;
            }
            return profQ;
        }
       void writeProfessor(Professor* prof) {
    std::ostringstream oss;
    oss << prof->getId() << " " << prof->getNames() << " " << prof->getLastNames() << " " << prof->getClassesNumber();
    std::ofstream file("test.txt", std::ios::app);
    if (file.is_open()) {
        file << oss.str() << "\n";
        file.close();
    }
}
};
