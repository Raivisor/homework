#include <iostream>
#include <random>

int* generate_array(int* array, const int array_size);

void merge(int* array, const int left, const int mid, const int right);

void merge_sort(int* array, const int left, const int right);

void print_array(const char* const comment, int* array, const int array_size);

int main() {
    int array_size;
    std::cout << "Введите размер массива: ";
    std::cin >> array_size;

    int* array = new int[array_size];
    generate_array(array, array_size);
    
    print_array("Сгенерированный массив: ", array, array_size);

    merge_sort(array, 0, array_size-1);

    print_array("Отсортированный массив: ", array, array_size);

    delete[] array;

    return 0;
}

int* generate_array(int* array, const int array_size) {
    std::mt19937 mt(time(nullptr));

    for(int i = 0; i < array_size; i++) {
        array[i] = mt()%1000;
    }

    return array;
}

void merge(int* array, const int left, const int mid, const int right) {
    int* temp = new int[right - left + 1];
    int left_array_idx = left;
    int right_array_idx = mid+1;
    int merged_idx = 0;

    while(left_array_idx <= mid && right_array_idx <= right) {
        if(array[left_array_idx] <= array[right_array_idx]) {
            temp[merged_idx++] = array[left_array_idx++];
        }
        else {
            temp[merged_idx++] = array[right_array_idx++];
        }
    }

    while(left_array_idx <= mid) {
        temp[merged_idx++] = array[left_array_idx++];
    }

    while(right_array_idx <= right) {
        temp[merged_idx++] = array[right_array_idx++];
    }

    for(int i = 0; i < merged_idx; i++){
        array[left + i] = temp[i];
    }

    delete[] temp;
}

void merge_sort(int* array, const int left, const int right) {
    if(left < right) {
        int mid = (right + left) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid+1, right);
        merge(array, left, mid, right);
    }
}

void print_array(const char* const comment, int* array, const int array_size) {
    const char space = ' ';
    std::cout << comment;
    for(int i = 0; i < array_size; i++) {
        std::cout << array[i] << space;
    }
    std::cout << "\n";
}