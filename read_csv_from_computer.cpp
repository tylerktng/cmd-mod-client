#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    // update these for filename and if testing
    std::string fileName = "WindlessSim.csv";
    int testing = 0;

    std::vector<std::vector<double>> csvContent;
    std::vector<double> row;
	std:: string line, word;

    std::fstream file (fileName, std::ios::in);
	if(file.is_open()) {
		while(getline(file, line)) {
			row.clear();
            // skip comment lines that begin with hash character
            if (line[0] == '#') {
                continue;
            }
 
			std::stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(stod(word));
			csvContent.push_back(row);
		}
	}
	else {
		std::cout << "Could not open the file" << std::endl;
    }

    // Prints the contents of the CSV file to test
    if (testing) {
        for(int i = 0; i < csvContent.size(); i++) {
            for(int j = 0; j < csvContent[i].size(); j++) {
                std::cout << csvContent[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
	return 0;
}