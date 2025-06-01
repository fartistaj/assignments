#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int longestConsecutive(const std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    std::unordered_set<int> num_set(nums.begin(), nums.end());

    int longest_streak = 0;

    for (int num : nums) {
        if (num_set.find(num - 1) == num_set.end()) {
            int current_num = num;
            int current_streak = 1;

            while (num_set.find(current_num + 1) != num_set.end()) {
                current_num++;
                current_streak++;
            }

            longest_streak = std::max(longest_streak, current_streak);
        }
    }

    return longest_streak;
}

int longestConsecutiveDetailed(const std::vector<int>& nums, std::vector<int>& longest_sequence) {
    longest_sequence.clear();

    if (nums.empty()) {
        return 0;
    }

    std::unordered_set<int> num_set(nums.begin(), nums.end());

    int longest_streak = 0;
    int best_start = 0;

    for (int num : nums) {
        if (num_set.find(num - 1) == num_set.end()) {
            int current_num = num;
            int current_streak = 1;

            while (num_set.find(current_num + 1) != num_set.end()) {
                current_num++;
                current_streak++;
            }

            if (current_streak > longest_streak) {
                longest_streak = current_streak;
                best_start = num;
            }
        }
    }

    for (int i = 0; i < longest_streak; i++) {
        longest_sequence.push_back(best_start + i);
    }

    return longest_streak;
}

void demonstrateAlgorithm(const std::vector<int>& nums) {
    std::cout << "\nArray: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i < nums.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    std::unordered_set<int> num_set(nums.begin(), nums.end());
    std::cout << "\nUnique numbers in set: {";
    std::vector<int> sorted_unique(num_set.begin(), num_set.end());
    std::sort(sorted_unique.begin(), sorted_unique.end());
    for (size_t i = 0; i < sorted_unique.size(); ++i) {
        std::cout << sorted_unique[i];
        if (i < sorted_unique.size() - 1) std::cout << ", ";
    }
    std::cout << "}" << std::endl;

    std::cout << "\nStep-by-step analysis:" << std::endl;
    std::cout << "Number\tIs Start?\tSequence Found\t\tLength" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    int longest_streak = 0;
    std::vector<int> best_sequence;

    for (int num : nums) {
        bool is_start = (num_set.find(num - 1) == num_set.end());

        if (is_start) {
            std::vector<int> current_sequence;
            int current_num = num;

            while (num_set.find(current_num) != num_set.end()) {
                current_sequence.push_back(current_num);
                current_num++;
            }

            std::cout << num << "\tYES\t\t";
            for (size_t i = 0; i < current_sequence.size(); ++i) {
                std::cout << current_sequence[i];
                if (i < current_sequence.size() - 1) std::cout << "->";
            }
            std::cout << "\t\t" << current_sequence.size() << std::endl;

            if (current_sequence.size() > best_sequence.size()) {
                best_sequence = current_sequence;
                longest_streak = current_sequence.size();
            }
        }
        else {
            std::cout << num << "\tNO\t\t(part of existing sequence)\t-" << std::endl;
        }
    }

    std::vector<int> final_sequence;
    int result = longestConsecutiveDetailed(nums, final_sequence);

    std::cout << "\nResult:" << std::endl;
    std::cout << "Longest consecutive sequence length: " << result << std::endl;
    std::cout << "Sequence: ";
    for (size_t i = 0; i < final_sequence.size(); ++i) {
        std::cout << final_sequence[i];
        if (i < final_sequence.size() - 1) std::cout << " -> ";
    }
    std::cout << std::endl;
    std::cout << std::string(60, '=') << std::endl;
}

void performanceAnalysis() {
    std::cout << "\nPerformance Analysis:" << std::endl;
    std::cout << "\nTime Complexity: O(N)" << std::endl;
    std::cout << "• Hash set creation: O(N)" << std::endl;
    std::cout << "• Main loop: O(N) iterations" << std::endl;
    std::cout << "• Each number is visited at most twice:" << std::endl;
    std::cout << "  - Once in the outer loop" << std::endl;
    std::cout << "  - Once when extending a sequence" << std::endl;
    std::cout << "• Hash set lookups: O(1) average case" << std::endl;

    std::cout << "\nSpace Complexity: O(N)" << std::endl;
    std::cout << "• Hash set stores all unique numbers" << std::endl;

    std::cout << "\nKey Optimization:" << std::endl;
    std::cout << "• Only start counting from sequence beginnings" << std::endl;
    std::cout << "• A number N is a sequence start if (N-1) is not in the set" << std::endl;
    std::cout << "• This avoids redundant work and ensures O(N) time" << std::endl;
}

int main() {
    std::vector<int> nums1 = { 10, 5, 12, 3, 55, 30, 4, 11, 2 };
    std::cout << "TEST CASE 1: First given example" << std::endl;
    demonstrateAlgorithm(nums1);

    std::vector<int> nums2 = { 19, 13, 15, 12, 18, 14, 17, 11 };
    std::cout << "TEST CASE 2: Second given example" << std::endl;
    demonstrateAlgorithm(nums2);

    std::vector<int> nums3 = { 42 };
    std::cout << "TEST CASE 3: Single element" << std::endl;
    demonstrateAlgorithm(nums3);

    std::vector<int> nums4 = { 1, 3, 5, 7, 9 };
    std::cout << "TEST CASE 4: No consecutive sequences" << std::endl;
    demonstrateAlgorithm(nums4);

    std::vector<int> nums5 = { 1, 2, 2, 3, 3, 4, 5 };
    std::cout << "TEST CASE 5: With duplicates" << std::endl;
    demonstrateAlgorithm(nums5);

    performanceAnalysis();

    return 0;
}