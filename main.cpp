#include <vector>
#include <iostream>

void countingSortByBit(std::vector<unsigned char>& arr, int bit) 
{
    std::vector<unsigned char> output(arr.size());
    int count[2] = { 0 };

    for (unsigned char num : arr) 
    {
        count[(num >> bit) & 1]++;
    }
    count[1] += count[0];

    for (int i = arr.size() - 1; i >= 0; --i) 
    {
        output[--count[(arr[i] >> bit) & 1]] = arr[i];
    }

    arr = output;
}

void binaryRadixSort(std::vector<unsigned char>& arr)
{
    for (int bit = 0; bit < 8; ++bit)
    {
        countingSortByBit(arr, bit);
    }
}

void printArray(const std::vector<unsigned char>& arr) 
{
    for (unsigned char num : arr) 
    {
        std::cout << (int)num << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<unsigned char> arr = { 14, 2, 5, 12 };
    std::cout << "Original array: ";
    printArray(arr);

    binaryRadixSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);
    return 0;
}