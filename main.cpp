#include <iostream>
#include <array>
#include <ctime>

#define ARR_SIZE 100
#define n1 20
#define n2 30
#define n3 25
int main() {
    std::array<int,ARR_SIZE> arr1 ,arr2;
    std::srand(std::time(nullptr));
    for (int i = 0; i< ARR_SIZE; ++i){
        arr1[i] = std::rand();
        arr2[i] = std::rand();
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
