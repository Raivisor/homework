#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

using ll = long long;

void showArray(vector<ll>& a){
    for(ll c : a){
        cout << c << " ";
    }
    cout << "\n";
}

vector<ll> generate(int N){
    vector<ll> a;
    mt19937 mt(time(nullptr));
    for(;N-- > 0;){
        int p = (mt()%10); int q = (mt()%10);
        a.push_back(pow(2,p)*pow(3,q));
    }
    return a;
}

void shellSorting(vector<ll>& a, int N){
    int h = 1;
    while(3*h + 1 <= (N + 2)/3){
        h = 3*h + 1;
    }
    for(; h > 0; h /= 3){
        for(int i = h; i < N; i++){
            int temp = a[i];
            int j = i;
            for(; j >= h && a[j-h] > temp;j -= h){
                a[j] = a[j-h];
            }
            a[j] = temp;
        }
    }
}

void solve(int N){
    vector<ll> a = generate(N);
    vector<ll> b = a;
    //showArray(a);
    auto start1 = steady_clock::now();
    shellSorting(a, N);
    auto stop1 = steady_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1-start1);
    auto start2 = steady_clock::now();
    sort(b.begin(),b.end());
    auto stop2 = steady_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2-start2);
    cout << "Время выполнения сортировки Шелла на " << N << " элементов: " << duration1.count() << "\n";
    cout << "Время выполнения встроенной сортировки на "<< N << " элементов: " << duration2.count() <<"\n";
    duration1.count() <= duration2.count() ? cout << "Невероятно!!!" : cout << "Неудевительно";
    cout << "\n";
}

int main(){
    int N = 1000;
    for(int i = 0; i < 4; i++){
        solve(N);
        N *= 10;
    }
}