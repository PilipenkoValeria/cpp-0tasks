#include "Container.h"
#include "tooMuchWeight.h"
using namespace std;

Container::Container(int Length, int Width, int Height, double MaxWeight) :
    length(Length), width(Width), height(Height), maxWeight(MaxWeight) {}

void Container::addBoxByIndex(int index, Box box) {
        try
        {
            if (getSumWeight() + box.getWeight() <= maxWeight) {
                boxes.insert(boxes.cbegin() + index, box);
            }
            else { cout <<endl<< "OverWeight" << endl<<endl; }
        }
        catch (tooMuchWeight& overweight)
        {
            std::cerr << overweight.what() << endl;
        }
}

void Container::deleteBoxByIndex(int index) {
    if (index <= boxes.size() && index >= 0) {
        boxes.erase(boxes.cbegin() + index);
    }
}

int Container::countBoxes() {
    return boxes.size();
}

double Container::getSumWeight() {
    double sum = 0;
    for (Box box : boxes) {
        sum += box.getWeight();
    }
    return sum;
}

int Container::getSumValue() {
    int sum = 0;
    for (Box box : boxes) {
        sum += box.getValue();
    }
    return sum;
}

Box Container::getBoxByIndex(int index) {
    if (index <= boxes.size() && index >= 0) {
        return boxes.at(index);
    }
    else {
        throw std::exception();
    }
}

Box& Container::operator[](int index) {
    return boxes[index];
}

ostream& operator<<(ostream& os, const Container& container) {
    os << "Контейнер: " << endl;
    os << "\tДлина: " << container.length;
    os << ", Ширина: " << container.width;
    os << ", Высота: " << container.height;
    os << ", Максимальный вес: " << container.maxWeight;
    if (!container.boxes.empty()) {
        cout << endl;
        os << "Коробки: " << endl;
        for (const Box& _box : container.boxes) {
            os << "\t";
            os << _box;
            os << "\n";
        }
        os << "\n";
    }
    else {
        cout << endl;
        os << "Контейнер пуст!" << endl;
    }
    return os;
}

istream& operator>>(istream& is, Container& container) {
    cout << "Введите длину: ";
    is >> container.length;
    cout << "Введите ширину: ";
    is >> container.width;
    cout << "Введите высоту: ";
    is >> container.height;
    cout << "Введите максимальный вес: ";
    is >> container.maxWeight;
    return is;
}