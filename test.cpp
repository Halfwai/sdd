#include <iostream>

double getMean(int arr[5], int size)
{
    double total {0};
    for (int i = 0; i < size; ++i)
    {
        total += arr[i];
    }
    return total/size;
}


int main()
{
    std::cout << "Hello World" << std::endl;

    int j {4};

    int arr[5] {1, 2, 3, 4, 5};

    std::cout << "j = " << j << std::endl;

    for (int i = 0; i < 5; ++i)
    {
       std::cout << "arr " << i << ":" << arr[i] << std::endl; 
    }

    std::cout << "Mean of array = " <<getMean(arr, 5) << std::endl;
}