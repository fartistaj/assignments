#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int maxProfit(const std::vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }

    int min_price = prices[0]; 
    int max_profit = 0;         

    for (int i = 1; i < prices.size(); i++) {
        min_price = std::min(min_price, prices[i]);

        int current_profit = prices[i] - min_price;

        max_profit = std::max(max_profit, current_profit);
    }

    return max_profit;
}

int maxProfitDetailed(const std::vector<int>& prices, int& buy_day, int& sell_day) {
    if (prices.empty()) {
        buy_day = sell_day = -1;
        return 0;
    }

    int min_price = prices[0];
    int min_price_day = 0;
    int max_profit = 0;
    buy_day = 0;
    sell_day = 0;

    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
            min_price_day = i;
        }

        int current_profit = prices[i] - min_price;
        if (current_profit > max_profit) {
            max_profit = current_profit;
            buy_day = min_price_day;
            sell_day = i;
        }
    }

    return max_profit;
}

void demonstrateAlgorithm(const std::vector<int>& prices) {
    std::cout << "\nStock Prices: [";
    for (size_t i = 0; i < prices.size(); ++i) {
        std::cout << prices[i];
        if (i < prices.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    std::cout << "\nStep-by-step analysis:" << std::endl;
    std::cout << "Day\tPrice\tMin Price\tProfit if Sell\tMax Profit So Far" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;

    int min_price = prices[0];
    int max_profit = 0;

    std::cout << "1\t$" << prices[0] << "\t$" << min_price << "\t\t-\t\t$0" << std::endl;

    for (int i = 1; i < prices.size(); ++i) {
        min_price = std::min(min_price, prices[i]);
        int current_profit = prices[i] - min_price;
        max_profit = std::max(max_profit, current_profit);

        std::cout << (i + 1) << "\t$" << prices[i] << "\t$" << min_price
            << "\t\t$" << current_profit << "\t\t$" << max_profit << std::endl;
    }

    int buy_day, sell_day;
    int profit = maxProfitDetailed(prices, buy_day, sell_day);

    std::cout << "\nResult:" << std::endl;
    std::cout << "Maximum Profit: $" << profit << std::endl;
    if (profit > 0) {
        std::cout << "Buy on Day " << (buy_day + 1) << " at $" << prices[buy_day] << std::endl;
        std::cout << "Sell on Day " << (sell_day + 1) << " at $" << prices[sell_day] << std::endl;
    }
    else {
        std::cout << "No profitable transaction possible (prices only decrease)" << std::endl;
    }
    std::cout << std::string(60, '=') << std::endl;
}

int main() {
    std::vector<int> prices1 = { 10, 7, 5, 8, 11, 2, 6 };
    std::cout << "TEST CASE 1:" << std::endl;
    demonstrateAlgorithm(prices1);

    std::vector<int> prices2 = { 1, 2, 3, 4, 5, 6 };
    std::cout << "TEST CASE 2:" << std::endl;
    demonstrateAlgorithm(prices2);

    std::vector<int> prices3 = { 6, 5, 4, 3, 2, 1 };
    std::cout << "TEST CASE 3:" << std::endl;
    demonstrateAlgorithm(prices3);

    std::vector<int> prices4 = { 5 };
    std::cout << "TEST CASE 4:" << std::endl;
    demonstrateAlgorithm(prices4);

    return 0;
}