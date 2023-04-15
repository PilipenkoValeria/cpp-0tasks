#include <iostream>
#include "ComplesNamespace.h"

using namespace BoxAndContainer;
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Box box0(10, 10, 10, 10.0, 10000);
    Box box1(20, 20, 20, 20.0, 20000);
    Box box2(30, 30, 30, 30.0, 30000);
    Box boxes[] = { box0, box1, box2 };
    int size = sizeof boxes / sizeof(*boxes);

    int sum = getSumValue(boxes, 3);
    cout << "Суммарная стоимость содержимого всех коробок: "<<sum << endl;
    cout << "Сумма длины, ширины и высоты всех коробок не превосходит 180: " << sumLWHlessThan(boxes, size, 180) << endl;
    cout << "Максимальный вес коробок, объем которых меньше 1500: "<< getMaxWeight(boxes, size, 1500) << endl;
    cout << "Все коробки можно вложить друг в друга по одной: "<< putUpEachOther(boxes, size) << endl;
    cout << "Box 1 == Box 2: "<< (box0 == box1) << endl;

    Box cinBox;
    Container container(100, 100, 100, 100);
    cout << container;
    cin >> cinBox;
    cout << cinBox << endl;
    container.addBox(box0);
    container.addBox(box1);
    container.addBox(box2);
    cout << "Добавили коробки в контейнер \n" << container << endl;
    container.addBoxByIndex(2, cinBox);
    cout << "Добавили коробку на (2) место, если суммарный вес коробок меньше веса контейнера\n" << container << endl;
    container.deleteBoxByIndex(1);
    cout << "Удалили коробку (1) " << endl;
    cout << "В контейнере " << container.countBoxes() << " коробки" << endl;
    cout << container;
}