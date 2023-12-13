#include <fstream>
#include <iostream>

#include "functions.hpp"
#include "utilities.hpp"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " [input_file] [dna_sequence]"
              << std::endl;
    return 1;
  }

  std::string file = argv[1];
  std::string sequence = argv[2];
  std::string final = DNA(file, sequence);
  std::cout << final << std::endl;

  return 0;
}