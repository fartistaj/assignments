#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, vector<char>> graph = 
{
    {'A', {'B', 'C'}},
    {'B', {'D'}},
    {'C', {'E'}},
    {'D', {}},
    {'E', {}}
};

void BFS(char start) 
{
    queue<char> q;
    unordered_map<char, bool> visited;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";

    while (!q.empty()) 
    {
        char current = q.front();
        q.pop();
        cout << current << " ";

        for (char neighbor : graph[current])
        {
            if (!visited[neighbor]) 
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

void DFS(char start) 
{
    stack<char> s;
    unordered_map<char, bool> visited;

    s.push(start);

    cout << "DFS Traversal: ";

    while (!s.empty()) 
    {
        char current = s.top();
        s.pop();

        if (!visited[current]) 
        {
            cout << current << " ";
            visited[current] = true;

            for (auto it = graph[current].rbegin(); it != graph[current].rend(); ++it) 
            {
                if (!visited[*it]) 
                {
                    s.push(*it);
                }
            }
        }
    }
    cout << endl;
}

int main() 
{
    BFS('A');
    DFS('A');
    return 0;
}
