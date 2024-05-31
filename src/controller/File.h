#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class File {
private:
    std::string path;

public:
    File(std::string _path){
		this->path = _path;
	}

	template <class T>
    std::vector<T> read() {
        std::vector<T> arr;
        std::ifstream file(path);
        if (file.is_open()) {
            T item;
            while (file >> item) {
                arr.push_back(item);
            }
            file.close();
        }
        return arr;
    }

	template <class T>
    void write(const T& toWrite) {
        std::ofstream file(path, std::ios::app);
        if (file.is_open()) {
            file << toWrite;
            file.close();
        }
    }

    std::string readLine() {
        std::string line;
        std::ifstream file(path);
        if (file.is_open() && std::getline(file, line)) {
            file.close();
        }
        return line;
    }
    
	template <class T>
	std::vector<T> readDataFromLine(int lineNumber) {
	    std::vector<T> data;
	    std::ifstream file(path);
	    std::string line;
	    int currentLine = 0;
	    if (file.is_open()) {
	        while (std::getline(file, line)) {
	            currentLine++;
	            if (currentLine == lineNumber) {
	                std::istringstream iss(line);
	                T element;
	                while (iss >> element) {
	                    data.push_back(element);
	                }
	                break;
	            }
	        }
	        file.close();
	    }
	    return data;
	}
	
	void writeLine(int lineNumber, const std::string& newContent) {
        std::ifstream file(path);
        std::vector<std::string> lines;
        std::string line;
        int currentLine = 0;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                lines.push_back(line);
            }
            file.close();
        }

        if (lineNumber > 0 && lineNumber <= lines.size()) {
            lines[lineNumber - 1] = newContent;
        } else if (lineNumber == lines.size() + 1) {
            lines.push_back(newContent);
        } else {
            std::cerr << "Line number out of range" << std::endl;
            return;
        }

        std::ofstream outFile(path);
        if (outFile.is_open()) {
            for (const auto& l : lines) {
                outFile << l << std::endl;
            }
            outFile.close();
        }
    }
    
    void writeLines(const std::vector<std::string>& lines) {
        std::ofstream file(path);
        if (file.is_open()) {
            for (const auto& line : lines) {
                file << line << std::endl;
            }
            file.close();
        }
    }

};

#endif

