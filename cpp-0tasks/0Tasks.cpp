#include <iostream>
#include "ComplesNamespace.h"

using namespace BoxAndContainer;

int main() {
    Box box0(30, 30, 30, 10.0, 10000);
    Box box1(20, 20, 20, 20.0, 20000);
    Box box2(10, 10, 10, 30.0, 30000);

    Box boxes[] = { box0, box1, box2 };

    int sum = getSumValue(boxes, 3);

    printf("Sum: %d\n", sum);

    printf("Is less than: %d\n", sumLWHlessThan(box0, 40));

    printf("Get max weight: %lf\n", getMaxWeight(boxes, 3, 8000));

    printf("Is fit: %d\n", putUpEachOther(boxes, 3));

    printf("my_box1 == my_box2: %d\n", box0 == box1);

    Box cin_box;

    std::cin >> cin_box;

    std::cout << cin_box << std::endl;

    std::cout << "----------------------------------------------------------------" << std::endl;

    Container container(1000, 1000, 1000, 10000);

    container.addBox(box0);
    container.addBox(box1);

    std::cout << container;

    container.addBoxByIndex(2, cin_box);

    std::cout << container;

    container.deleteBoxByIndex(2);
    container[0] = cin_box;
    std::cout <<"In container " << container.countBoxes() << std::endl;
    std::cout << container;

    std::cout << container[0];

    return 0;
}