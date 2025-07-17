#include "PersonDetection.h"
#include <iostream>

int main() {
    Dataset dataset;

    // Attempts to load up to 10 entries from the dataset CSV file
    std::string csvFile = "_annotations.csv"; // Updates path if needed
    int entryCount = 10;

    if (dataset.loadFromCSV(csvFile, entryCount)) {
        dataset.display(); // Displays the loaded detections
    }
    else {
        std::cout << "Failed to load dataset.\n";
    }

    return 0;
}
