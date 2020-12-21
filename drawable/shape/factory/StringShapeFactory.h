#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <cctype>
#include "../Shape.h"
#include "../DrawablePoint.h"
#include "../Line.h"
#include "../BorderRectangle.h"
#include "../BorderTriangle.h"
#include "../BorderCircle.h"
#include "../../../util/Color.h"

namespace drawIt {
    class StringShapeFactory {
        std::string shape;
        public:
            static std::shared_ptr<Shape> createShape(std::string stringShape) {
                std::string type;
                std::string fields;
                bool isType = true;
                for(auto c: stringShape) {
                    if(c == '{') {isType = false; } 
                    if(isType) {
                        type.push_back(c);
                    }else{
                        fields.push_back(c);
                    }
                }
                fields.pop_back();
                static int ile = 0;
                std::cout<<++ile<<std::endl;
                if(type == "Point") {
                    return createDrawablePoint(fields);
                }else if(type == "Line") {
                    return createLine(fields);
                }else if(type == "Triangle") {
                    return createTriangle(fields);
                }else if(type == "Rectangle") {
                    return createRectangle(fields);
                }else if(type == "Circle") {
                    return createCircle(fields);
                }
                return nullptr;
             
            }

        private:

            static std::vector<std::string> getNumbers(std::string fields) {
                std::vector<std::string> numbers;
                int i = 0;
                numbers.push_back(std::string(""));
                for(auto c: fields) {
                    if(isdigit(c)) {
                        numbers[i].push_back(c);
                    }
                    if(c == '.'){
                        numbers[i].push_back(c);
                    }
                    if(c == '-') {
                        numbers[i].push_back(c);
                    }
                    if(c == ',') {
                        i++;
                        numbers.push_back(std::string(""));
                    }
                }
                return numbers;
            }

            static std::shared_ptr<DrawablePoint> createDrawablePoint(std::string fields) {
                std::vector<std::string> numbers = getNumbers(fields);
                std::vector<std::string> colors(numbers.begin() + 2, numbers.end()); 
                return std::make_shared<DrawablePoint>(
                    stoi(numbers[0]),
                    stoi(numbers[1]),
                    getColor(colors));
            }

            static std::shared_ptr<Line> createLine(std::string fields) {
                std::vector<std::string> numbers = getNumbers(fields);
                std::vector<std::string> point1(numbers.begin(), numbers.begin()+2);
                std::vector<std::string> point2(numbers.begin()+2, numbers.begin()+4);
                std::vector<std::string> colors(numbers.begin()+4, numbers.end());
                return std::make_shared<Line>(
                    getPoint(point1), 
                    getPoint(point2),
                    getColor(colors));
            }

            static std::shared_ptr<BorderTriangle> createTriangle(std::string fields) {
                std::vector<std::string> numbers = getNumbers(fields);
                std::vector<std::string> point1(numbers.begin(), numbers.begin()+2);
                std::vector<std::string> point2(numbers.begin()+2, numbers.begin()+4);
                std::vector<std::string> point3(numbers.begin()+4, numbers.begin()+6);
                std::vector<std::string> colors1(numbers.begin()+6, numbers.begin()+9);
                std::vector<std::string> colors2(numbers.begin()+9, numbers.end()-1);
                return std::make_shared<BorderTriangle>(
                    getPoint(point1), 
                    getPoint(point2),
                    getPoint(point3),
                    getColor(colors1),
                    getColor(colors2),
                    std::stoi(numbers.back()));
            }

            static std::shared_ptr<BorderRectangle> createRectangle(std::string fields) {
                std::vector<std::string> numbers = getNumbers(fields);
                std::vector<std::string> point1(numbers.begin(), numbers.begin()+2);
                int width = std::stoi(numbers.at(2));
                int heigth = std::stoi(numbers.at(3));
                std::vector<std::string> colors1(numbers.begin()+4, numbers.begin()+7);
                std::vector<std::string> colors2(numbers.begin()+7, numbers.end()-1);
                bool fill = std::stoi(numbers.back());
                std::cout<<getPoint(point1)<<" "<<width<<" "<<heigth<<" "<<getColor(colors1)<<" "<<getColor(colors2)<<" "<<fill<<std::endl;
                return std::make_shared<BorderRectangle>(
                    getPoint(point1),

                    width, heigth,
                    getColor(colors1), getColor(colors2),
                    fill
                );
            }

            static std::shared_ptr<BorderCircle> createCircle(std::string fields) {
                std::vector<std::string> numbers = getNumbers(fields);
                std::vector<std::string> point1(numbers.begin(), numbers.begin()+2);
                float r = std::stof(numbers.at(2));
                std::cout<<r<<std::endl;
                std::vector<std::string> colors1(numbers.begin()+3, numbers.begin()+6);
                std::vector<std::string> colors2(numbers.begin()+6, numbers.end()-1);
                bool fill = std::stoi(numbers.back());
                return std::make_shared<BorderCircle>(
                    getPoint(point1),
                    r,
                    getColor(colors1),
                    getColor(colors2),
                    fill
                );
            }

            static Color getColor(std::vector<std::string> color) {
                return Color{
                    std::stof(color[0]),
                    std::stof(color[1]),
                    std::stof(color[2])};
            }

            static Point getPoint(std::vector<std::string> point) {
                return Point{
                    std::stoi(point[0]),
                    std::stoi(point[1])
                };
            }
    };
}