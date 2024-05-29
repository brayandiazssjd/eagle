#include "../../../include/ProfessorDAO.h"

ProfessorDAO::ProfessorDAO(const std::string& _path) : File(_path) {
}

Professor ProfessorDAO::createProfessor(int line) {
    std::vector<std::string> info = readDataFromLine<std::string>(line);
    Professor professor;
    professor.setNames(info[1]);
    professor.setLastNames(info[2]);
    professor.setId(stoi(info[0]));
    return professor;
}

Queue<Professor> ProfessorDAO::getProfessors() {
    Queue<Professor> profQ;
    for(int i=1; i<=count; i++){
        profQ.enqueue(createProfessor(i));
    }
    return profQ;
}