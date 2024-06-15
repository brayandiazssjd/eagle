#include <DLOList.h>
#include "ProfessorController.h"

int main()
{
    // Crear un objeto ProfessorDAO para un archivo de prueba
    ProfessorDAO dao("../data/Professors.txt");
    DLOList<Professor *> *professorsList = new DLOList<Professor *>();
    // Crear un objeto ProfessorController
    ProfessorController controller;

    // Crear algunos profesores y escribirlos en el archivo
    Professor *prof1;
DLOList<int>* idsList = controller.getIdsProfessors();
    for (int i = 0; i < idsList->length(); i++)
{
    int id = idsList->get(i);
    std::cout << "ID: " << id << std::endl;
}
    // Leer los profesores del archivo y mostrar sus nombres e ID
    DLOList<Professor *> *professors = controller.getProfessors(); // Usa el método getProfessors de ProfessorController
    for (int i = 0; i < professors->length(); i++)
    {
        Professor *prof = professors->get(i);
        std::cout << "ID: " << prof->getId() << ", Name: " << prof->getNames() << " " << prof->getLastNames() << std::endl;
    }
    prof1 = controller.getProfessor(56789012);
    std::cout<<prof1->getId()<<" "<<prof1->getNames();
    

    delete professors;
    delete prof1;

    return 0;
}
