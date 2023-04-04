#include "ComplesNamespace.h"
#include "tooMuchWeight.h"
using namespace std;

namespace BoxAndContainer {
    Box::Box() {
        length = 0;
        width = 0;
        height = 0;
        weight = 0;
        value = 0;
    }

    Box::Box(int _length, int _width, int _height, double _weight, int _value) {
        length = _length;
        width = _width;
        height = _height;
        weight = _weight;
        value = _value;
    }

    Box::~Box() {
        length = 0;
        width = 0;
        height = 0;
        weight = 0;
        value = 0;
    }

    void Box::setLength(int _length) { length = _length; }
    void Box::setWidth(int _width) { width = _width; }
    void Box::setHeight(int _height) { height = _height; }
    void Box::setWeight(double _weight) { weight = _weight; }
    void Box::setValue(int _value) { value = _value; }

    int Box::getLength() { return length; }
    int Box::getWidth() { return width; }
    int Box::getHeight() { return height; }
    double Box::getWeight() { return weight; }
    int Box::getValue() { return value; }

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

    Container::Container(int _length, int _width, int _height, double _maxWeight) :
        length(_length), width(_width), height(_height), maxWeight(_maxWeight) {}

    int Container::countBoxes() {
        return boxes.size();
    }

    void Container::addBoxByIndex(int index, Box box) {
            try
            {
                if (getSumWeight() + box.getWeight() <= maxWeight) {
                    boxes.insert(boxes.cbegin() + index, box);
                }
                else { cout << endl << "OverWeight" << endl << endl; }
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

    int Container::addBox(Box box) {
        try
        {
            if (getSumWeight() + box.getWeight() <= maxWeight) {
                boxes.push_back(box);
                return static_cast<int>(boxes.size() - 1);
            }
        }
        catch (const tooMuchWeight& overweight)
        {
            cerr << overweight.what() << box <<endl;
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
}