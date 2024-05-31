#include "ProfessorDAO.h"

int main() {
    // Crear un objeto ProfessorDAO para un archivo de prueba
    ProfessorDAO dao("test.txt");

    // Crear algunos profesores y escribirlos en el archivo
    Professor* prof1 = new Professor();
    prof1->setNames("John");
    prof1->setLastNames("Doe");
    prof1->setId(1);
    dao.writeProfessor(prof1);
    Professor* prof2 = new Professor();
    prof2->setNames("Jane");
    prof2->setLastNames("Doe");
    prof2->setId(2);
    dao.writeProfessor(prof2);
    // Leer los profesores del archivo y mostrar sus nombres e ID
    Queue<Professor*>* professors = dao.getProfessors();
    while (!professors->isEmpty()) {
        Professor* prof = professors->denqueue();
        std::cout << "ID: " << prof->getId() << ", Name: " << prof->getNames() << " " << prof->getLastNames() << std::endl;
        delete prof;
    }

    delete professors;
    delete prof1;
    //delete prof2;

    return 0;
}
