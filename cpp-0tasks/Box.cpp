#include<iostream>
#include"Box.h"
using namespace std;

Box::Box() {
	length = 0;
    width = 0;
    height = 0;
    weight = 0;
    value = 0;
}

Box::Box(int Length, int Width, int Height, double Weight, int Value) {
    length = Length;
    width = Width;
    height = Height;
    weight = Weight;
    value = Value;
}

Box::~Box() {
    length = 0;
    width = 0;
    height = 0;
    weight = 0;
    value = 0;
}

void Box::setLength(int Length) { 
    length = Length;
}

void Box::setWidth(int Width) { 
    width = Width;
}

void Box::setHeight(int Height) { 
    height = Height;
}

void Box::setWeight(double Weight) { 
    weight = Weight; 
}

void Box::setValue(int Value) {
    value = Value; 
}

int Box::getLength() { 
    return length; 
}

int Box::getWidth() { 
    return width; 
}

int Box::getHeight() { 
    return height; 
}

double Box::getWeight() { 
    return weight; 
}

int Box::getValue() { 
    return value; 
}

int getSumValue(Box boxes[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += boxes[i].getValue();
    }
    return sum;
}

bool sumLWHlessThan(Box boxes[], int size, int val) {
    int sumLWHofAll = 0;
    for (int i = 0; i < size; i++) {
        sumLWHofAll += boxes[i].getLength() + boxes[i].getWidth() + boxes[i].getHeight();

    }
    return sumLWHofAll <= val;
}

double getMaxWeight(Box boxes[], int size, int maxV) {  
    double maxWeight = 0;
    for (int i = 0; i < size; i++) {
        if ((boxes[i].getLength() * boxes[i].getWidth() * boxes[i].getHeight()) < maxV) {
            if (boxes[i].getWeight() >= maxWeight) {
                maxWeight = boxes[i].getWeight();
            }
        }
    }
    return maxWeight;
}

bool putUpEachOther(Box boxes[], int size) {
    int countSize = 0;
    int V = 0;
    int Comb = (((size - 1) * (size)) / 2); 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((boxes[i].getLength() * boxes[i].getWidth() * boxes[i].getHeight() 
                < boxes[j].getLength() * boxes[j].getWidth() * boxes[j].getHeight()))
            {
                V++;
            }
        }
    }
    if (Comb == V)
    {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if ((boxes[i].getLength() < boxes[i].getWidth() && boxes[i].getHeight()
                    < boxes[j].getLength() && boxes[i].getWidth() < boxes[j].getHeight()))
                {
                    countSize++;
                }
            }
        }
        if (Comb != countSize) {
            return false;
        }
        return true;
    }
    else return false;
}

bool operator==(Box box1, Box box2) {
    return box1.getLength() == box2.getLength() && box1.getWidth() == box2.getWidth() &&
        box1.getHeight() == box2.getHeight() && box1.getWeight() == box2.getWeight() &&
        box1.getValue() == box2.getValue();
}

ostream& operator<<(ostream& os, Box box) {
    os << "Длина: " << box.getLength();
    os << ", Ширина: " << box.getWidth();
    os << ", Высота: " << box.getHeight();
    os << ", Вес: " << box.getWeight();
    os << ", Стоимость: " << box.getValue() << ".";
    return os;
}

istream& operator>>(istream& is, Box& box) {
    cout << "Введите длину: ";
    is >> box.length;
    cout << "Введите ширину: ";
    is >> box.width;
    cout << "Введите высоту: ";
    is >> box.height;
    cout << "Введите вес: ";
    is >> box.weight;
    std::cout << "Введите стоимость: ";
    is >> box.value;
    return is;
}