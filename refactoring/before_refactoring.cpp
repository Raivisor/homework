#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int i = 10; float a[10], b[10], c[10];
    float sa = 0;
    float sb = 0;
    float sc = 0;
    cout << "первая последовательность" << endl;
    for(i = 0; i < 10; i++){
        a[i] = rand() % 10;
        cout << a[i];
        cout << ' ';
        sa += a[i];
    }
    cout << endl << "среднее первой последовательности = " << sa / 10 << endl;
    cout << "вторая последовательность" << endl;
    for(i = 0; i < 10; i++){
        b[i] = rand() % 10;
        cout << b[i];
        cout << ' ';
        sb += b[i];
    }
    cout << endl << "среднее второй последовательности = " << sb / 10 << endl;
    cout << "третья последовательность" << endl;
    for(i = 0; i < 10; i++){
        c[i] = rand() % 10;
        cout << c[i];
        cout << ' ';
        sc += c[i];
    }
    cout << endl << "среднее третьей последовательности = " << sc / 10 << endl;
    return 0;
}
