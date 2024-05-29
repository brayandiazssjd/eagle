#include <iostream>
#include "../../include/ProfessorDAO.h"

int main() {
    // Crea un objeto ProfessorDAO que interactúa con un archivo específico
    ProfessorDAO dao("datosTest.txt");

    // Obtiene los profesores del archivo
    Queue<Professor> professors = dao.getProfessors();

    // Imprime la información de cada profesor
    while (!professors.isEmpty()) {
        Professor professor = professors.denqueue();
        std::cout << "Nombre: " << professor.getNames() << "\n";
        std::cout << "Apellidos: " << professor.getLastNames() << "\n";
        std::cout << "ID: " << professor.getId() << "\n";
        std::cout << "-------------------\n";
    }

    return 0;
}
