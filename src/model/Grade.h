#ifndef GRADE_H
#define GRADE_H

#include <string>
#include "Point.h"

class Grade{
    private:
        std::string name;
        int percentage;			
    
    public:		
        Point *points;
        Grade();
        Grade(std::string name, int percentage, Point *points);
        std::string getName();
        int getPercentage();
        ~Grade();
};

#endif // GRADE_H