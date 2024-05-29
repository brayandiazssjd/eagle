#ifndef PROFESSOR_DAO_H
#define PROFESSOR_DAO_H

#include <vector>
#include "file.h"
#include "Professor.h"
#include "Queue.h"

class ProfessorDAO : public File {
private:
    int count = 5;
public:
    ProfessorDAO(const std::string& _path);
    Professor createProfessor(int line);
    Queue<Professor> getProfessors();
};

#endif // PROFESSOR_DAO_H