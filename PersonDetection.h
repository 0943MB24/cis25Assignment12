#pragma once

#include <vector>
#include <string>

// Holds info for one detection entry
struct Detection {
    std::string filename;
    int width;
    int height;
    std::string person;
    int xmin;
    int ymin;
    int xmax;
    int ymax;
};

// Dataset class encapsulates loading and displaying detections
class Dataset {
private:
    std::vector<Detection> detections;

public:
    // Loads detections from CSV file up to maxEntries
    bool loadFromCSV(const std::string& filename, int maxEntries);

    // Displays all loaded detections
    void display() const;

    // Retrieves loaded detections
    const std::vector<Detection>& getDetections() const { return detections; }

};