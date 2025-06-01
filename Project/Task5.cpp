#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>

std::vector<double> sortTemperatures(const std::vector<double>& temperatures) {
    if (temperatures.empty()) {
        return {};
    }

    std::unordered_map<int, int> count;

    for (double temp : temperatures) {
        int temp_int = static_cast<int>(temp * 10 + 0.5); 
        count[temp_int]++;
    }

    std::vector<double> sorted_temps;
    sorted_temps.reserve(temperatures.size());

    for (int temp_int = 970; temp_int <= 990; temp_int++) {
        if (count.find(temp_int) != count.end()) {
            double actual_temp = temp_int / 10.0;

            for (int i = 0; i < count[temp_int]; i++) {
                sorted_temps.push_back(actual_temp);
            }
        }
    }

    return sorted_temps;
}

std::vector<double> sortTemperaturesArray(const std::vector<double>& temperatures) {
    if (temperatures.empty()) {
        return {};
    }

    const int MIN_TEMP_INT = 970; 
    const int MAX_TEMP_INT = 990; 
    const int RANGE = MAX_TEMP_INT - MIN_TEMP_INT + 1; 

    std::vector<int> count(RANGE, 0);

    for (double temp : temperatures) {
        int temp_int = static_cast<int>(temp * 10 + 0.5);
        count[temp_int - MIN_TEMP_INT]++;
    }

    std::vector<double> sorted_temps;
    sorted_temps.reserve(temperatures.size());

    for (int i = 0; i < RANGE; i++) {
        if (count[i] > 0) {
            double actual_temp = (MIN_TEMP_INT + i) / 10.0;
            for (int j = 0; j < count[i]; j++) {
                sorted_temps.push_back(actual_temp);
            }
        }
    }

    return sorted_temps;
}

void demonstrateCountingSort(const std::vector<double>& temperatures) {
    std::cout << "\nOriginal temperatures: [";
    for (size_t i = 0; i < temperatures.size(); ++i) {
        std::cout << std::fixed << std::setprecision(1) << temperatures[i];
        if (i < temperatures.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    std::unordered_map<int, int> count;
    std::cout << "\nCounting process:" << std::endl;
    std::cout << "Temperature -> Integer -> Count" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    for (double temp : temperatures) {
        int temp_int = static_cast<int>(temp * 10 + 0.5);
        count[temp_int]++;
    }

    std::cout << "\nFrequency count:" << std::endl;
    std::cout << "Temperature\tCount" << std::endl;
    std::cout << "-------------------" << std::endl;

    for (int temp_int = 970; temp_int <= 990; temp_int++) {
        if (count.find(temp_int) != count.end()) {
            double actual_temp = temp_int / 10.0;
            std::cout << std::fixed << std::setprecision(1) << actual_temp
                << "°F\t\t" << count[temp_int] << std::endl;
        }
    }

    std::vector<double> sorted_temps = sortTemperatures(temperatures);
    std::cout << "\nSorted temperatures: [";
    for (size_t i = 0; i < sorted_temps.size(); ++i) {
        std::cout << std::fixed << std::setprecision(1) << sorted_temps[i];
        if (i < sorted_temps.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
}

void performanceComparison(const std::vector<double>& temperatures) {
    std::cout << "\nPerformance Analysis:" << std::endl;
    std::cout << "Array size: " << temperatures.size() << " elements" << std::endl;
    std::cout << "Possible temperature values: 21 (97.0 to 99.0 with 0.1 precision)" << std::endl;
    std::cout << "\nComplexity Analysis:" << std::endl;
    std::cout << "• Counting Sort: O(N) time, O(K) space where K=21 (constant)" << std::endl;
    std::cout << "• QuickSort: O(N log N) time, O(log N) space" << std::endl;
    std::cout << "• For large N, Counting Sort is significantly faster!" << std::endl;
}

int main() {
    std::vector<double> temps1 = { 98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1 };
    std::cout << "TEST CASE 1: Given example" << std::endl;
    demonstrateCountingSort(temps1);

    std::vector<double> temps2 = { 98.6, 98.6, 98.6, 98.6 };
    std::cout << "TEST CASE 2: All same temperature" << std::endl;
    demonstrateCountingSort(temps2);

    std::vector<double> temps3 = { 97.0, 97.5, 98.0, 98.5, 99.0 };
    std::cout << "TEST CASE 3: Already sorted" << std::endl;
    demonstrateCountingSort(temps3);

    std::vector<double> temps4 = { 99.0, 98.5, 98.0, 97.5, 97.0 };
    std::cout << "TEST CASE 4: Reverse sorted" << std::endl;
    demonstrateCountingSort(temps4);

    performanceComparison(temps1);

    std::vector<double> result1 = sortTemperatures(temps1);
    std::vector<double> result2 = sortTemperaturesArray(temps1);

    std::cout << "\nVerification: Both implementations match: "
        << (result1 == result2 ? "? YES" : "? NO") << std::endl;

    return 0;
}