#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "File.h"
#include "Professor.h"
#include "DLOList.h"

class ProfessorDAO : public File
{
private:
    int count = 0;

public:
    ProfessorDAO(const std::string &_path) : File(_path)
    {
    }

    Professor *createProfessor(int line)
    {
        std::vector<std::string> info = readDataFromLine<std::string>(line);
        if (!info.empty())
        {
            Professor *professor = new Professor();
            professor->setNames(info[1]);
            professor->setLastNames(info[2]);
            professor->setId(stoi(info[0]));
            professor->setClassesNumber(stoi(info[3]));
            return professor;
        }
        else
        {
            return nullptr;
        }
    }
    
    DLOList<int> *getIdsProfessors()
{
    count = 1;
    DLOList<int> *IdsList = new DLOList<int>;
    Professor *professor = createProfessor(count);
    count++;
    while (professor != nullptr)
    {
        IdsList->add(professor->getId()); 
        professor = createProfessor(count);
        count++;
    }
    return IdsList;
}

    DLOList<Professor *> *getProfessors()
    {	
    	
        count = 1;
        DLOList<Professor *> *profList = new DLOList<Professor *>;
        Professor *professor = createProfessor(count);
        count++;
        while (professor != nullptr)
        {
            profList->add(professor); 
            professor = createProfessor(count);
            count++;
        }
        return profList;
    }

    void writeProfessor(Professor *prof)
    {
        std::ostringstream oss;
        oss << prof->getId() << " " << prof->getNames() << " " << prof->getLastNames() << " " << prof->getClassesNumber();
        std::ofstream file("../data/Professors.txt", std::ios::app);
        if (file.is_open())
        {
            file << oss.str() << "\n";
            file.close();
        }
    }
    void removeProfessor(int id)
    {
        std::ifstream fileIn("../data/Professors.txt");
        std::ofstream fileOut("../data/Professors_temp.txt");
        std::string line;
        while (getline(fileIn, line))
        {
            std::istringstream iss(line);
            int currentId;
            iss >> currentId; // Asume que el ID es el primer elemento en la línea
            if (currentId != id)
            {
                fileOut << line << "\n";
            }
        }
        fileIn.close();
        fileOut.close();
        // Reemplaza el archivo original con el archivo temporal
        remove("../data/Professors.txt");
        rename("../data/Professors_temp.txt", "../data/Professors.txt");
    }
};
