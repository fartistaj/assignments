#include <iostream>
#include <vector>
#include <numeric>

int findMissingNumberSum(const std::vector<int>& arr) {
    int n = arr.size() + 1; 
    int expected_sum = n * (n - 1) / 2;

    int actual_sum = 0;
    for (int num : arr) {
        actual_sum += num;
    }

    return expected_sum - actual_sum;
}

int findMissingNumberXOR(const std::vector<int>& arr) {
    int n = arr.size() + 1;
    int xor_all = 0;
    int xor_array = 0;

    for (int i = 0; i < n; i++) {
        xor_all ^= i;
    }

    for (int num : arr) {
        xor_array ^= num;
    }

    return xor_all ^ xor_array;
}

int findMissingNumberAccumulate(const std::vector<int>& arr) {
    int n = arr.size() + 1;
    int expected_sum = n * (n - 1) / 2;
    int actual_sum = std::accumulate(arr.begin(), arr.end(), 0);
    return expected_sum - actual_sum;
}

void testMethods(const std::vector<int>& arr, const std::string& description) {
    std::cout << "\nTesting: " << description << std::endl;
    std::cout << "Array: [";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Missing number (Sum method): " << findMissingNumberSum(arr) << std::endl;
    std::cout << "Missing number (XOR method): " << findMissingNumberXOR(arr) << std::endl;
    std::cout << "Missing number (Accumulate): " << findMissingNumberAccumulate(arr) << std::endl;
}

int main() {
    std::vector<int> arr1 = { 2, 3, 0, 6, 1, 5 };
    testMethods(arr1, "Array from 0-6, missing 4");

    std::vector<int> arr2 = { 8, 2, 3, 9, 4, 7, 5, 0, 6 };
    testMethods(arr2, "Array from 0-9, missing 1");

    std::vector<int> arr3 = { 0, 1, 3 };
    testMethods(arr3, "Array from 0-3, missing 2");

    std::vector<int> arr4 = { 1, 2, 3, 4 };
    testMethods(arr4, "Array from 0-4, missing 0");

    return 0;
}