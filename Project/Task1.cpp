#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

struct Player {
    std::string first_name;
    std::string last_name;
    std::string team;

    Player(const std::string& fname, const std::string& lname, const std::string& t)
        : first_name(fname), last_name(lname), team(t) {}

    std::string getFullName() const {
        return first_name + " " + last_name;
    }
};

std::vector<std::string> findDualSportPlayers(const std::vector<Player>& basketball_players,
    const std::vector<Player>& football_players) {
    std::vector<std::string> dual_sport_players;
    std::unordered_set<std::string> basketball_names;

    for (const auto& player : basketball_players) {
        basketball_names.insert(player.getFullName());
    }

    for (const auto& player : football_players) {
        std::string full_name = player.getFullName();

        if (basketball_names.find(full_name) != basketball_names.end()) {
            dual_sport_players.push_back(full_name);
        }
    }

    return dual_sport_players;
}

int main() {
    std::vector<Player> basketball_players = {
        Player("Jill", "Huang", "Gators"),
        Player("Janko", "Barton", "Sharks"),
        Player("Wanda", "Vakulskas", "Sharks"),
        Player("Jill", "Moloney", "Gators"),
        Player("Luuk", "Watkins", "Gators")
    };

    std::vector<Player> football_players = {
        Player("Hanzla", "Radosti", "32ers"),
        Player("Tina", "Watkins", "Barleycorns"),
        Player("Alex", "Patel", "32ers"),
        Player("Jill", "Huang", "Barleycorns"),
        Player("Wanda", "Vakulskas", "Barleycorns")
    };

    std::vector<std::string> dual_players = findDualSportPlayers(basketball_players, football_players);

    std::cout << "Players who participate in both sports:" << std::endl;
    std::cout << "[";
    for (size_t i = 0; i < dual_players.size(); ++i) {
        std::cout << "\"" << dual_players[i] << "\"";
        if (i < dual_players.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}