#include <iostream>
#include <array>
#include <ctime>
#include <iomanip>
#include <thread>

#define ARR_SIZE 100
#define n1 20
#define n2 30
#define n3 25
int main() {
    std::array<float,ARR_SIZE> arr1 ,arr2;
    std::srand(std::time(nullptr));
    for (int i = 0; i< ARR_SIZE; ++i){
        arr1[i] = std::rand();
        arr2[i] = std::rand();
    }
    std::thread t1([&arr1, &arr2]{
        for(int i = 0; i< n1; ++i)
            std::cout << std::setprecision(3) << "THREAD1:" << arr1[i] << " " << arr2[i] << " " << arr1[i]*arr2[i] << std::endl;
        // для задержки:
        // std::cout << "THREAD1:";
        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
        // std::cout << std::setprecision(3) << std::setprecision(3) << arr1[i] << " " << arr2[i] << " " << arr1[i]*arr2[i] << std::endl;
    });
    std::thread t2([&arr1, &arr2]{
        for(int i = 0; i< n2; ++i)
            std::cout << std::setprecision(3) << "THREAD2:" << arr1[i] << " " << arr2[i] << " " << arr1[i]+arr2[i] << std::endl;
        // для задержки:
        // std::cout << "THREAD2:";
        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
        // std::cout << std::setprecision(3) << arr1[i] << " " << arr2[i] << " " << arr1[i]+arr2[i] << std::endl;
    });
    std::thread t3([]{
        for(int i = 0; i< n3; ++i)
            std::cout << std::setprecision(3) << "THREAD3:" << std::rand() << std::endl;
        // для задержки:
        // std::cout << "THREAD3:";
        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
        // std::cout << std::setprecision(3) << std::rand() << std::endl;
    });
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
