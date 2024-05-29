#ifndef TOPIC_H
#define TOPIC_H

#include <string>

class Topic{
    private:
        std::string name;
        int id;

    public:
        Topic();
        Topic(std::string name, int id);
        std::string getName();
        int getId();
        ~Topic();
};

#endif // TOPIC_H