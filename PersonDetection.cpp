#include "PersonDetection.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Loads up to 'maxEntries' detections from a CSV file
bool Dataset::loadFromCSV(const std::string& filename, int maxEntries) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << filename << "\n";
        return false;
    }

    std::string line;
    std::getline(file, line); // skips header

    int count = 0;
    while (std::getline(file, line) && count < maxEntries) {
        std::stringstream ss(line);
        std::string token;
        Detection det;

        // Extracts values from CSV line in the order:
        // filename, width, height, label, xmin, ymin, xmax, ymax
        std::getline(ss, det.filename, ',');
        std::getline(ss, token, ','); det.width = std::stoi(token);
        std::getline(ss, token, ','); det.height = std::stoi(token);
        std::getline(ss, det.person, ',');  // class label
        std::getline(ss, token, ','); det.xmin = std::stoi(token);
        std::getline(ss, token, ','); det.ymin = std::stoi(token);
        std::getline(ss, token, ','); det.xmax = std::stoi(token);
        std::getline(ss, token, ','); det.ymax = std::stoi(token);

        detections.push_back(det);
        ++count;
    }

    return true;
}
// Displays each loaded detection in a readable format
void Dataset::display() const {
    for (const auto& det : detections) {
        std::cout << "File: " << det.filename
            << ", Size: " << det.width << "x" << det.height
            << ", Bounding Box: (" << det.xmin << "," << det.ymin
            << ") to (" << det.xmax << "," << det.ymax << ")"
            << ", Class: " << det.person << "\n";
    }
}
