#include "readData.h"
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char ** argv){

    int dimension;
    double ** cost;
    const char * cend = "\n";
    const std::string ofile = "distance_matrix";
    readData(argc, argv, &dimension, &cost);


    std::ofstream file(ofile);
    file << dimension << cend;
    for (int i = 1; i <= dimension; i++) {
        for (int j = i+1; j <= dimension; j++)
            file << cost[i][j] << " ";

        if (i != dimension)
            file << cend;
    }

    fs::path filename = fs::path(argv[1]).filename();

    const fs::path rnd_dir = "../rand_iter_values";
    const fs::path rnd_extension = ".rnd";
    const fs::path rnd_filename = rnd_dir / filename.replace_extension(rnd_extension);

    std::fstream rnd_file(rnd_filename, ios_base::in);

    if (rnd_file.good() == false) {
        std::cout << "Aborted: Ainda nao exieste arquivo \'.rnd\' para essa instancia.\n"; 
        return -1;
    }

    // TEMPORARIO (SLDQ)
    file << "EOF\n" << std::string(filename) << "\nRND" << cend;

    std::string line;
    std::getline(rnd_file, line);
    file << line << cend;

    int rnd_size = std::stoi(line);
    for (int i = 0; i < rnd_size; i++) {
        std::getline(rnd_file, line);
        file << line << cend;
    }

    file.close();

    std::system(std::string("mv " + ofile + " ../../").c_str());

    return 0;
}
