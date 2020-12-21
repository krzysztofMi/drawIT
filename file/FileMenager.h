#pragma once

#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>

#include "../drawable/shape/factory/StringShapeFactory.h"

namespace drawIt {
    class FileMenager{
        private:
            std::string filePath;
        public:
            FileMenager(std::string filePath): filePath{filePath} {}

            void saveVector(std::vector<std::shared_ptr<Shape>> items) {
                std::ofstream file;
                file.open(filePath);
                if(file) {
                    for(auto item: items) {
                        file<<item->toString();
                    }
                    file.close();
                } else {
                    std::cerr << "ERROR! " << filePath << "not created!" <<std::endl;
                }
            }

            std::vector<std::shared_ptr<Shape>>  retriveVector() {
                std::vector<std::shared_ptr<Shape>> drawable;
                std::ifstream file;
                file.open(filePath);
                if(file) {
                    std::string line;
                    while(std::getline(file, line)) {
                        drawable.push_back(StringShapeFactory::createShape(line));
                    }
                    file.close();
                } else {
                    std::cerr << "ERROR! " << filePath << "not created!" <<std::endl;
                }
                return drawable;
            }
    };
}