#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

long long maxProduct(const std::vector<int>& nums) {
    if (nums.size() < 2) {
        throw std::invalid_argument("Array must contain at least 2 numbers");
    }

    int largest = INT_MIN, second_largest = INT_MIN;
    int smallest = INT_MAX, second_smallest = INT_MAX;

    for (int num : nums) {
        if (num > largest) {
            second_largest = largest;
            largest = num;
        }
        else if (num > second_largest) {
            second_largest = num;
        }

        if (num < smallest) {
            second_smallest = smallest;
            smallest = num;
        }
        else if (num < second_smallest) {
            second_smallest = num;
        }
    }

    long long product1 = (long long)largest * second_largest;
    long long product2 = (long long)smallest * second_smallest;

    return std::max(product1, product2);
}

long long maxProductDetailed(const std::vector<int>& nums, int& num1, int& num2) {
    if (nums.size() < 2) {
        throw std::invalid_argument("Array must contain at least 2 numbers");
    }

    int largest = INT_MIN, second_largest = INT_MIN;
    int smallest = INT_MAX, second_smallest = INT_MAX;

    for (int num : nums) {
        if (num > largest) {
            second_largest = largest;
            largest = num;
        }
        else if (num > second_largest) {
            second_largest = num;
        }

        if (num < smallest) {
            second_smallest = smallest;
            smallest = num;
        }
        else if (num < second_smallest) {
            second_smallest = num;
        }
    }

    long long product1 = (long long)largest * second_largest;
    long long product2 = (long long)smallest * second_smallest;

    if (product1 > product2) {
        num1 = largest;
        num2 = second_largest;
        return product1;
    }
    else {
        num1 = smallest;
        num2 = second_smallest;
        return product2;
    }
}

void demonstrateAlgorithm(const std::vector<int>& nums) {
    std::cout << "\nArray: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i < nums.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    std::cout << "\nStep-by-step analysis:" << std::endl;
    std::cout << "Number\tLargest\t2nd Largest\tSmallest\t2nd Smallest" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;

    int largest = INT_MIN, second_largest = INT_MIN;
    int smallest = INT_MAX, second_smallest = INT_MAX;

    for (int num : nums) {
        if (num > largest) {
            second_largest = largest;
            largest = num;
        }
        else if (num > second_largest) {
            second_largest = num;
        }

        if (num < smallest) {
            second_smallest = smallest;
            smallest = num;
        }
        else if (num < second_smallest) {
            second_smallest = num;
        }

        std::cout << num << "\t" << largest << "\t" << second_largest
            << "\t\t" << smallest << "\t\t" << second_smallest << std::endl;
    }

    long long product1 = (long long)largest * second_largest;
    long long product2 = (long long)smallest * second_smallest;

    std::cout << "\nPossible products:" << std::endl;
    std::cout << "Two largest numbers: " << largest << " × " << second_largest
        << " = " << product1 << std::endl;
    std::cout << "Two smallest numbers: " << smallest << " × " << second_smallest
        << " = " << product2 << std::endl;

    int num1, num2;
    long long max_prod = maxProductDetailed(nums, num1, num2);

    std::cout << "\nResult:" << std::endl;
    std::cout << "Maximum Product: " << max_prod << std::endl;
    std::cout << "Numbers used: " << num1 << " × " << num2 << " = " << max_prod << std::endl;
    std::cout << std::string(60, '=') << std::endl;
}

int main() {
    std::vector<int> nums1 = { 5, -10, -6, 9, 4 };
    std::cout << "TEST CASE 1: Mixed positive and negative numbers" << std::endl;
    demonstrateAlgorithm(nums1);

    std::vector<int> nums2 = { 3, 7, 1, 9, 2, 8 };
    std::cout << "TEST CASE 2: All positive numbers" << std::endl;
    demonstrateAlgorithm(nums2);

    std::vector<int> nums3 = { -5, -2, -8, -1, -4 };
    std::cout << "TEST CASE 3: All negative numbers" << std::endl;
    demonstrateAlgorithm(nums3);

    std::vector<int> nums4 = { -3, 0, -1, 4, 2 };
    std::cout << "TEST CASE 4: Mix with zero" << std::endl;
    demonstrateAlgorithm(nums4);

    std::vector<int> nums5 = { -100, -50 };
    std::cout << "TEST CASE 5: Two numbers only" << std::endl;
    demonstrateAlgorithm(nums5);

    return 0;
}