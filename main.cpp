#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Country {
    std::string name;
    float score;
    int food;
    int history;
    int nature;
    int life;
};
void sorting();
void writeRanking();
std::vector<Country> countries_struct; 
std::vector<Country> countries_sorted;
int index(){
        std::ifstream inputFile("list.txt");
        int lines = 0;
        std::string line;
        while (std::getline(inputFile, line)) {
            lines++;
        }
        inputFile.close();  
        return lines;
}
void getNamesFromTxt(){
    std::ifstream inputFile("countries");
    std::vector<std::string> countries;
    std::string line;
     while (std::getline(inputFile, line)) {
            countries.push_back(line);
        }
    for(const auto& country : countries) {
        Country p;
        p.name = country;
        countries_struct.push_back(p);
        }
    inputFile.close();
    
}
void writeTxt(std::string name, int score){
    std::ofstream outputFile("list.txt", std::ios::app);

    if (outputFile.is_open()){
        outputFile <<  name << ": " << score << "\n";
    }
    outputFile.close();
}
void setScores(){
    for(size_t i = index(); i < countries_struct.size(); i++) {
        std::cout << "\n" << countries_struct[i].name << "\n";
        std::cout << "Wiki -> https://en.wikipedia.org/wiki/" << countries_struct[i].name << "\n";
        std::cout << "Nota: ";
        // only using score directly cuz its faster to test
        // it should be like this -> get all individual score then do their average
        std::cin >> countries_struct[i].score;
        writeTxt(countries_struct[i].name, countries_struct[i].score);
        writeRanking();
    }
}
int partition(std::vector<Country>& arr, int low, int high) {
    float pivot = arr[high].score;
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j].score > pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(std::vector<Country>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
void sorting(){
    countries_sorted = countries_struct;
    quickSort(countries_sorted, 0, countries_struct.size() - 1);
}
void writeRanking(){
    sorting();
    std::ofstream outputFile("ranking.txt");
    int i = 0;
    if (outputFile.is_open()){
        for(const auto& country : countries_sorted) {
        i++;
        if (country.score != 0){
                outputFile << i << "- " << country.name << " : " << country.score << "\n"; 
            }
        }
    }
    outputFile.close();
}
int main() {
    getNamesFromTxt();
    setScores();
    return 0;
}
