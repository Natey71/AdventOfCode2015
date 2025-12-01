#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream file("file.txt");
    if(!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }


    // x*length*width + 2*width*height + 2*height*length
    std::string line;
    int totalSurfaceArea = 0;
    while(std::getline(file, line)) {
        std::string s = line;
        int l, w, h;
        char x;
        std::istringstream ss(s);
        ss >> l >> x >> w >> x >> h;

        std::vector<int> sides = {l*w, w*h, h*l};
        std::sort(sides.begin(), sides.end());
        int smallestSide = sides[0];

        int surfaceArea = 2*l*w + 2*w*h + 2*h*l;
        surfaceArea += smallestSide; // extra paper for the smallest side
        totalSurfaceArea += surfaceArea;
        // Uncomment for testing
        // std::cout << "Length: " << l << " Width: " << w << " Height: " << h << " - Surface: " << surfaceArea << std::endl;
    }
    std::cout << "Total Surface Area: " << totalSurfaceArea << std::endl;

    return 0;
}