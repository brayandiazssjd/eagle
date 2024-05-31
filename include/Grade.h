#ifndef GRADE_H
#define GRADE_H

#include <string>
#include "Point.h"

class Grade{
    private:
        std::string name;
        float percentage;
		Point *points;			
    
    public:		
        Grade();
        Grade(std::string name, float percentage, Point *points);
        std::string getName();
        int getPercentage();
        Point getPoint();
        ~Grade();
};

#endif // GRADE_H
