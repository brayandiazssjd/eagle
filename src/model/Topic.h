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

Topic::Topic(){
}

Topic::Topic(std::string name, int id){
    this->name = name;
    this->id = id;
}

std::string Topic::getName(){
    return name;
}

int Topic::getId(){
    return id;
}

Topic::~Topic(){
}
