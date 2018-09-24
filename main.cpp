#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void print(int numbers[], int size);
void countingSort(int numbers[], int size);

int main(int argc, char *argv[]) {
    //int numbers[] = {53, 89, 23, 29, 64, 95, 76, 34, 33, 98, 30}; // No los está ordenando correctamente
    int numbers[] = {1, 3, 4, 17, 9, 13, 2, 11, 5, 4}; // Probaste con este caso?
    int size = sizeof(numbers) / sizeof(*numbers);

    print(numbers, size);
    countingSort(numbers, size);
    print(numbers, size);

    system("read");
    return EXIT_SUCCESS;
}

void print(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
}

void countingSort(int numbers[], int size) {
    int min = *min_element(numbers,numbers+size);
    int csize = *max_element(numbers, numbers+size) -min +1;
    int count[csize];
    memset(count, 0, sizeof(count));
    int sorted[size];


    for(int i = 0; numbers[i]; ++i){ //1.
        ++count[numbers[i]-min];
    }

    for(int i=1; i<csize+1; i++){
      count[i]+=count[i-1];
    }

    for(int i=0; numbers[i]; ++i){
      sorted[count[numbers[i]-min]-=1] = numbers[i];
    }

    for(int i=0; numbers[i]; i++){
      numbers[i]=sorted[i];
    }

    cout << endl;
}
