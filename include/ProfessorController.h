#include "ProfessorDAO.h"
#include "Professor.h"
#include "DLOList.h"

class ProfessorController {
private:
    ProfessorDAO* professorDao;

public:
    // Constructor
    ProfessorController();

    // Destructor
    ~ProfessorController();

    // Método para agregar un profesor
    void addProfessor(Professor* professor);

    // Método para eliminar un profesor
    void removeProfessor(int id);


    // Método para obtener un profesor
    Professor* getProfessor(int id);
    
    DLOList<int>* getIdsProfessors();

    DLOList<Professor *>* getProfessors();

    
};
