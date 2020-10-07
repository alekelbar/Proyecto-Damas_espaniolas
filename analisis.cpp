#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int arreglo[2][2] = {
        {1, 1},
        {2, 2}};

    if (arreglo[0 - 1][1] == 1)
        cout << "puedo revisar sin erores";
    else
        cout << "no puedo revisar";
        
    return 0;
}
