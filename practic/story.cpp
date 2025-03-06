#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <random>
#include <fstream>
using namespace std;


    void initializeData(std::vector<std::string>& heroes, std::vector<std::string>& places, std::vector<std::string>& actions, std::vector<std::string>& details) {
    heroes = {"смелый рыцарь", "хитрый вор", "волшебник", "отважный пират", "дерзкий исследователь"};
    places = {"в далёком королевстве", "на заброшенной фабрике", "в густом лесу", "на просторах космоса", "у подножия гор"};
    actions = {"победил дракона", "обнаружил сокровища", "выиграл битву", "устроил бал", "раскрыл древнюю тайну"};
    details = {"с волшебным мечом", "на летающем ковре", "под звуки волшебной музыки", "с удивительной силой", "в сопровождении магического существа"};
}
  string generateStory(const vector<std::string>& heroes, const vector<std::string>& places, const vector<std::string>& actions, const vector<std::string>& details){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 4);
    int heroIndex = distrib(gen);
    int placeIndex = distrib(gen);
    int actionIndex = distrib(gen);
    int detailIndex = distrib(gen);
    string story = heroes[heroIndex] + " " + places[placeIndex] + ", " + actions[actionIndex] + " " + details[detailIndex] + ".";
 cout << "\\nСгенерированная история:\\n" << story << endl;  
return story;
  }

void saveStory(const string& story){
    char saveChoice;
    std::cout << "\nСохранить историю в файл (stories.txt)? (Y/N): ";
    std::cin >> saveChoice;

    if (saveChoice == 'Y' || saveChoice == 'y') {
        std::ofstream outFile("stories.txt", std::ios::app);
        if (outFile.is_open()) {
            outFile << story << "\n";
            outFile.close();
            std::cout << "История сохранена в файл stories.txt" << std::endl;
        } else {
            std::cout << "Ошибка открытия файла для записи!" << std::endl;
        }
    }}

bool askPlayAgain() {
    char playAgain;
    std::cout << "\nХотите сгенерировать новую историю? (Y/N): ";
    std::cin >> playAgain;
    return (playAgain == 'Y' || playAgain == 'y');
}

int main()
{   setlocale(LC_ALL, "Russian");
    std::vector<std::string> heroes;
    std::vector<std::string> places;
    std::vector<std::string> actions;
    std::vector<std::string> details;
    initializeData(heroes, places, actions, details);

    
    bool playAgain = true;
    while (playAgain) {
       
        std::string story = generateStory(heroes, places, actions, details);
        std::cout << "\nСгенерированная история:\n" << story << std::endl;
        saveStory(story);
        playAgain = askPlayAgain();
    }

    std::cout << "\nСпасибо за игру! До свидания!" << std::endl;
    return 0;
    
}