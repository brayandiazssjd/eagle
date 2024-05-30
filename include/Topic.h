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
        void setName(std::string _name);
        void setId(int _id);
        ~Topic();
};

#endif // TOPIC_H