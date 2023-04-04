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
    os << "���������: " << endl;
    os << "\t�����: " << container.length;
    os << ", ������: " << container.width;
    os << ", ������: " << container.height;
    os << ", ������������ ���: " << container.maxWeight;
    if (!container.boxes.empty()) {
        cout << endl;
        os << "�������: " << endl;
        for (const Box& _box : container.boxes) {
            os << "\t";
            os << _box;
            os << "\n";
        }
        os << "\n";
    }
    else {
        cout << endl;
        os << "��������� ����!" << endl;
    }
    return os;
}

istream& operator>>(istream& is, Container& container) {
    cout << "������� �����: ";
    is >> container.length;
    cout << "������� ������: ";
    is >> container.width;
    cout << "������� ������: ";
    is >> container.height;
    cout << "������� ������������ ���: ";
    is >> container.maxWeight;
    return is;
}