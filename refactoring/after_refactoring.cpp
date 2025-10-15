#include <iostream>
#include <cmath>

void find_average(
    const char* const comment_begin, 
    const char* const comment_end, 
    int* array, 
    const int size, 
    const int number
);

int main()
{
    const int size = 10;
    const int count = 3;

    for (int i = 0; i < count; i++){
        int array[size];
        find_average(
            "последовательность номер ", 
            "среднее последовательности = ", 
            array, 
            size, 
            i
        );
    }

    return 0;
}

void find_average(
    const char* const comment_begin, 
    const char* const comment_end, 
    int* array, 
    const int size,  
    const int number
) {
    const char space = ' ';
    float sum = 0;

    std::cout << comment_begin << number + 1 << std::endl;

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
        std::cout << array[i];
        std::cout << space;
        sum += array[i];
    }
    std::cout << std::endl;

    float average = sum / size;

    std::cout << comment_end << average << std::endl;
}
