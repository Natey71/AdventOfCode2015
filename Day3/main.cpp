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
    int x = 0;
    int y = 0;
    std::set<std::pair<int, int>> visited;
    visited.insert({x, y});
    while(std::getline(file, line)) {
        for(char &c : line) {
            if(c == '^') {
                y += 1;
            } else if(c == 'v') {
                y -= 1;
            } else if(c == '>') {
                x += 1;
            } else if(c == '<') {
                x -= 1;
            }
            visited.insert({x, y});
        }
    }
    std::cout << "Visited Houses: " << visited.size() << std::endl;
}