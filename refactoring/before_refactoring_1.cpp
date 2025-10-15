#include <iostream>
#include <cmath>

void find_average(const char* const comment_begin, const char* const comment_end, float* array, int size);

int main()
{
    int size = 10;
    float* array_a = new float[size];
    float* array_b = new float[size];
    float* array_c = new float[size];

    find_average("первая последовательность", "среднее первой последовательности = ", array_a, size);
    find_average("вторая последовательность", "среднее второй последовательности = ", array_b, size);
    find_average("третья последовательность", "среднее третьей последовательности = ", array_c, size);

    return 0;
}

void find_average(const char* const comment_begin, const char* const comment_end, float* array, int size){
    const char space = ' ';
    float sum = 0;

    std::cout << comment_begin << std::endl;

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
        std::cout << array[i];
        std::cout << space;
        sum += array[i];
    }
    std::cout << std::endl;

    float average = sum/size;

    std::cout << comment_end << average << std::endl;
}
