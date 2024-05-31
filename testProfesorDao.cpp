#include "ProfessorDAO.h"

int main() {
    // Crear un objeto ProfessorDAO para un archivo de prueba
    ProfessorDAO dao("../data/Professors.txt");

    // Crear algunos profesores y escribirlos en el archivo
    Professor* prof1 = new Professor();
    prof1->setNames("John");
    prof1->setLastNames("Doe");
    prof1->setId(79562930);
    prof1->setClassesNumber(2);
    dao.writeProfessor(prof1);
    
    // Leer los profesores del archivo y mostrar sus nombres e ID
    Queue<Professor*>* professors = dao.getProfessors();
    while (!professors->isEmpty()) {
        Professor* prof = professors->denqueue();
        std::cout << "ID: " << prof->getId() << ", Name: " << prof->getNames() << " " << prof->getLastNames() << std::endl;
        delete prof;
    }

    delete professors;
    delete prof1;

    return 0;
}
