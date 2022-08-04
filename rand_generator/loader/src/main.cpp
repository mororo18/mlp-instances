#include "readData.h"
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char ** argv){

    int dimension;
    double ** cost;
    
    readData(argc, argv, &dimension, &cost);


    std::ofstream file("distance_matrix");
    file << dimension << std::endl;
    for (int i = 1; i <= dimension; i++) {
        for (int j = i+1; j <= dimension; j++)
            file << cost[i][j] << " ";

        if (i != dimension)
            file << std::endl;
    }

    fs::path filename = fs::path(argv[1]).filename();

    const fs::path rnd_dir = "../rand_iter_values";
    const fs::path rnd_extension = ".rnd";
    const fs::path rnd_file = rnd_dir / filename.replace_extension(rnd_extension);

    std::fstream rnd_values(rnd_file, ios_base::in);

    if (rnd_values.good() == false) {
        std::cout << "Aborted: Ainda nao exieste arquivo \'.rnd\' para essa instancia.\n"; 
        return -1;
    }

    std::string line;
    while (std::getline(rnd_values, line)) {
        file << line << std::endl;
    }

    file.close();

    return 0;
}
