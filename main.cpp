#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <array>
#include <cstring>

int main() {
    // update these for filename and if testing
    std::string fileName = "WindlessSim.csv";
    bool testing = true;

    std::vector<std::array<double, 6>> csvContent;
	std:: string line, word;

    std::fstream file (fileName, std::ios::in);
	if(file.is_open()) {
        //std::cout << "open file" << std::endl;
		while(getline(file, line)) {
            
			//row.clear();
            // skip comment lines that begin with hash character
            if (line[0] == '#') {
                continue;
            }
 
			std::stringstream str(line);

            std::array<double, 6> row;
            int satellites;

            sscanf(str.str().c_str(), "%lf, %lf, %lf, %lf, %lf, %lf, %d", &(row[0]), &(row[1]), &(row[2]), &(row[3]), &(row[4]), &(row[5]), &satellites);

            int i = 0;
			// while(getline(str, word, ',')) {
            //     //std::cout << word << std::endl;
			// 	row.push_back(stod(word));
            //     i++;
            // }
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