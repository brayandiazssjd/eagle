#include <string>

class Class{
    private:
        std::string id;
        int professorId;

    public:
        Class();
        Class(std::string id, int professorId);
        std::string getId();
        int getProfessorId();
        ~Class();
};

Class::Class(){
}

Class::Class(std::string id, int professorId){
    this->id = id;
    this->professorId = professorId;
}

std::string Class::getId(){
    return id;
}

int Class::getProfessorId(){
    return professorId;
}

Class::~Class(){
}