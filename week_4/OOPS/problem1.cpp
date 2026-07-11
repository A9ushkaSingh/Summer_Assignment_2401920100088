#include <iostream>
using namespace std;

class Test
{
public:
    virtual int square(int n) = 0;
};

class Arithmetic : public Test
{
public:
    int square(int n)
    {
        return n * n;
    }
};

int main()
{
    Arithmetic obj;
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Square = " << obj.square(n);

    return 0;
}
