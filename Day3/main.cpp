#include <iostream>
#include <fstream>
#include <vector>
#include <set> 
#include <utility>

int main() {
    std::ifstream file("file.txt");
    if(!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;  
    }
    std::string line;
    // Starting position
    int x = 0;
    int y = 0;
    // To track visited houses
    std::set<std::pair<int, int>> visited;
    // Add starting position to visited
    visited.insert({x, y});
    while(std::getline(file, line)) {
        for(char &c : line) {
            // Move based on character
            // ^ = up, v = down, > = right, < = left
            // ^ add to y, v subtract from y
            // > add to x, < subtract from x
            if(c == '^') {
                y += 1;
            } else if(c == 'v') {
                y -= 1;
            } else if(c == '>') {
                x += 1;
            } else if(c == '<') {
                x -= 1;
            }
            // Record the new position
            visited.insert({x, y});
        }
    }
    
    std::cout << "Visited Houses: " << visited.size() << std::endl;
}