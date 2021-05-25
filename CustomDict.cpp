#include <iostream>
#include "Dict.h"
using namespace std;

int main()
{
    Dict A("blin", 3);
    cout << A.size();
    A.add("Blabla", "value");
    cout << A.translate("Blabla");
    A.add("Leha", "Alexey");
    A.print();
    A.save("F:\CLionProjects");
    Dict B("chort.txt");
    B.add("What", "you");
    B.print();
    B.save("haha");
    return 0;
}

