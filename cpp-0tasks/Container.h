#include <vector>
#include <iostream>
#include "Box.h"

class Container {
private:
    std::vector<Box> boxes;
    int length;
    int width;
    int height;
    double maxWeight;
public:
    Container(int, int, int, double);
    void addBoxByIndex(int, Box);
    void deleteBoxByIndex(int);
    int countBoxes();
    double getSumWeight();
    int getSumValue();
    Box getBoxByIndex(int);
    int addBox(Box);
    Box& operator[](int);
    friend std::ostream& operator<<(std::ostream&, const Container&);
    friend std::istream& operator>>(std::istream&, Container&);
};
