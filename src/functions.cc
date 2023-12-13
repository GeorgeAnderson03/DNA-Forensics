#include "functions.hpp"

#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "utilities.hpp"
int CountStr(std::string str, std::string sub) {
  int count = 0;
  unsigned long strlength = str.length();
  unsigned long sublength = sub.length();

  for (unsigned long i = 0; i <= (strlength - sublength); i++) {
    unsigned long j = 0;
    for (j = 0; j < sublength; j++) {
      if (str[i + j] != sub[j]) {
        break;
      }
    }
    if (j == sublength) {
      count++;
      j = 0;
    }
  }
  return count;
}

int Repeating(std::string& str, std::string& sub) {
  int freq = CountStr(str, sub);
  // std::cout << freq << std::endl;
  std::string temp;
  for (int i = 0; i < freq; i++) {
    temp += sub;
  }
  size_t found = str.find(temp);
  while (found == std::string::npos) {
    freq -= 1;
    temp = "";
    for (int i = 0; i < freq; i++) {
      temp += sub;
    }
    found = str.find(temp);
  }

  return freq;
}

std::string DNA(std::string& file, std::string sequence) {
  std::vector<std::string> vect1;
  std::vector<std::string> list;
  std::vector<int> temp;
  std::map<std::string, std::vector<std::string>> wholemap;
  std::ifstream ifs{file};
  for (std::string line; std::getline(ifs, line); line = "") {
    vect1 = utilities::GetSubstrs(line, ',');
    std::string columnname = vect1.at(0);
    list.push_back(columnname);
    wholemap.insert(std::pair<std::string, std::vector<std::string>>(
        columnname, std::vector<std::string>()));
    for (unsigned int i = 1; i < vect1.size(); i++) {
      wholemap[columnname].push_back(vect1[i]);
    }
  }
  std::vector<std::string> cnames = wholemap.at(list[0]);
  for (unsigned int i = 0; i < wholemap.at(list.at(0)).size(); i++) {
    temp.push_back(Repeating(sequence, cnames[i]));
  }
  int count = 0;
  std::string finalname;
  for (unsigned int i = 1; i < list.size(); i++) {
    std::vector<int> comparedna;
    for (unsigned int j = 0; j < wholemap.at(list.at(i)).size(); j++) {
      std::vector<std::string> currentnumber = wholemap.at(list[i]);
      int converted = std::stoi(currentnumber[j]);
      comparedna.push_back(converted);
    }
    if (comparedna == temp) {
      count++;
      finalname = list[i];
    }
  }
  if (count != 1) {
    return "No Match";
  }
  return finalname;
}
