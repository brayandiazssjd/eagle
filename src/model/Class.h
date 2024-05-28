#include <string>

class ClassA{
    private:
        std::string id;
        int professorId;

    public:
        ClassA();
        ClassA(std::string id, int professorId);
        std::string getId();
        int getProfessorId();
        ~ClassA();
};

ClassA::ClassA(){
}

ClassA::ClassA(std::string id, int professorId){
    this->id = id;
    this->professorId = professorId;
}

std::string ClassA::getId(){
    return id;
}

int ClassA::getProfessorId(){
    return professorId;
}

ClassA::~ClassA(){
}