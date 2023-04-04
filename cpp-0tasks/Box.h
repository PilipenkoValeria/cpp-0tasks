#include <ostream>

class Box {
private:
    int length;
    int width;
    int height;
    double weight;
    int value;
public:
    Box();
    ~Box();
    Box(int, int, int, double, int);
    void setLength(int);
    void setWidth(int);
    void setHeight(int);
    void setWeight(double);
    void setValue(int);
    int getLength();
    int getWidth();
    int getHeight();
    double getWeight();
    int getValue();
    friend bool operator==(Box, Box);
    friend std::ostream& operator<<(std::ostream&, Box);
    friend std::istream& operator>>(std::istream&, Box&);
};
int getSumValue(Box[], int);
bool sumLWHlessThan(Box[], int, int);
double getMaxWeight(Box[], int, int);
bool putUpEachOther(Box[], int);
