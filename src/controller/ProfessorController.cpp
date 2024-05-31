<<<<<<< HEAD
class ProfessorController {
private:
	//OList<Professor> list;
public:
=======
#include "../../include/ProfessorController.h"
>>>>>>> 2c13d1c89010d6b1265760f20dc6c0dfa1b16d8d

// Constructor
ProfessorController::ProfessorController() {
    professorDao = new ProfessorDAO("../data/Professors.txt"); // Asume que el archivo de datos está en esta ruta
}

// Destructor
ProfessorController::~ProfessorController() {
    delete professorDao;
}

// Método para agregar un profesor
void ProfessorController::addProfessor(Professor* professor) {
    professorDao->writeProfessor(professor);
}

// Método para eliminar un profesor
// Nota: Necesitarás implementar este método en ProfessorDAO
void ProfessorController::removeProfessor(int id) {
    professorDao->removeProfessor(id);
}


// Método para obtener un profesor
Professor* ProfessorController::getProfessor(int id) {
    DLOList<Professor *>* professors = professorDao->getProfessors();
    for (int i = 0; i < professors->length(); i++) {
        if (professors->get(i)->getId() == id) {
            return professors->get(i);
        }
    }
    return nullptr; // Devuelve nullptr si no se encuentra el profesor con el id dado
}

DLOList<Professor *>* ProfessorController::getProfessors() {
    return professorDao->getProfessors();
}

DLOList<int>* ProfessorController::getIdsProfessors() {
    DLOList<int>* idsList = new DLOList<int>();
    DLOList<Professor*>* professorsList = this->getProfessors();

    for (int i = 0; i < professorsList->length(); i++) {
        Professor* professor = professorsList->get(i);
        idsList->add(professor->getId());
    }

    return idsList;
}
