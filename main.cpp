#include <iostream>
#include <random>
#include <algorithm>

int opp;
int passwordLength;
int secureScore;
const std::string separator = "------------------------------------------------------------------------------------------";
const std::string lower = "\tabcdefghijklmnopqrstuvwxyz\n";
const std::string upper = "\tABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
const std::string digits = "\t0123456789\n";
const std::string punctuation = "\t!@#$%&*()_+-=[]|,./?><\n";
std::string returnMenu;
std::string characters;
std::string userInputPassword;
std::string randomCreatedPassword;
std::string answer;

void passwordCreator();
void passwordCheck();
void mixer();
void returnMainMenu();
void returnPasswordCheck();
void returnPasswordCreator();
void exitSection();

int main() {
    std::cout << "\n\tPassword_Security_Check_CPP" << std::endl;

    std::cout << "\n\tRandom Password Creator_______1" << std::endl;
    std::cout << "\tPassword Check________________2" << std::endl;
    std::cout << "\tExit__________________________0" << std::endl;

    std::cout << "\n\tChoose your operation:";
    std::cin >> opp;

    switch (opp) {
        case 1:
            passwordCreator();
            break;
        case 2:
            passwordCheck();
            break;
        case 0:
            exitSection();
            break;
        default:
            std::cout << "Invalid selection. Please choose a valid option." << std::endl;
            main();
            break;
    }

    return 0;
}

void passwordCreator(){
    std::cout << separator << std::endl;
    std::cout << ("\tRANDOM PASSWORD GENERATOR") << std::endl;

    // QUESTIONS
    std::cout << ("\n(Recommended minimum 8)\nHow many characters do you need?") << std::endl;
    std::cin >> passwordLength;

    std::cout << ("\n(Recommended)\nDo you want to use UPPERCASE: (Y/N)\t\t") << upper;
    std::cin >> answer;
    if (answer == "y" || answer == "Y"){
        characters += upper;
    }

    std::cout << ("\n(Recommended)\nDo you want to use LOWERCASE: (Y/N)\t\t") << lower;
    std::cin >> answer;
    if (answer == "y" || answer == "Y"){
        characters += lower;
    }

    std::cout << ("\n(Recommended)\nDo you want to use DIGIT: (Y/N)\t\t\t") << digits;
    std::cin >> answer;
    if (answer == "y" || answer == "Y"){
        characters += digits;
    }

    std::cout << ("\n(Recommended)\nDo you want to use PUNCTUATION: (Y/N)\t\t") << punctuation;
    std::cin >> answer;
    if (answer == "y" || answer == "Y"){
        characters += punctuation;
    }

    std::cout << ("\n\nYour elements:\n") << characters << std:: endl;

    mixer();

    std::cout << "Your random created password:\t" << randomCreatedPassword << std::endl;

    returnPasswordCreator();
}

void mixer (){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, characters.length() - 1);


    for (int i = 0; i < passwordLength; i++) {
        int randomIndex = dist(gen);
        char randomChar = characters[randomIndex];
        randomCreatedPassword += randomChar;
    }
}

void passwordCheck() {
    std::cout << separator << std::endl;
    std::cout << "\tPASSWORD CHECK PART" << std::endl;

    secureScore = 0 ;

    std::cout << "\n Please enter your userInputPassword:\t" << std::endl;
    std::cin >> userInputPassword;

    if (userInputPassword.length() >= 8){
        std::cout << "Password length >= 8\t+1P" << std::endl;
        secureScore += 1;
    }
    if (userInputPassword.find_first_of(lower) != std::string::npos){
        std::cout << "Lower case Letter used\t+1P" << std::endl;
        secureScore += 1;
    }
    if (userInputPassword.find_first_of(upper) != std::string::npos){
        std::cout << "Upper case leter used\t+1P" << std::endl;
        secureScore +=1;
    }
    if (userInputPassword.find_first_of(digits) != std::string::npos){
        std::cout << "Number used\t\t+1P" << std::endl;
        secureScore += 1;
    }
    if (userInputPassword.find_first_of(punctuation) != std::string::npos){
        std::cout << "Special character used\t+1P" << std::endl;
        secureScore += 1;
    }

    std::cout << "Your userInputPassword secure score " << secureScore << " out of 5" << "\t(" << secureScore << "/5)" << std::endl;

    returnPasswordCheck();
}

void returnMainMenu() {
    std::cout << "\nDo you want to return to the main menu? (Y/N)" << std::endl;
    std::cin >> returnMenu;
    if (returnMenu == "y" || returnMenu == "Y") {
        main();
    }
    else if (returnMenu == "n" || returnMenu == "N"){
        exitSection();
    }
    else {
        std::cout << "\n\tInvalid choice" << std::endl;
        returnMainMenu();
    }
}

void returnPasswordCheck() {
    std::cout << "\nDo you want to use this function again? (Y/N)" << std::endl;
    std::cin >> returnMenu;
    if (returnMenu == "y" || returnMenu == "Y") {
        passwordCheck();
    }
    else if (returnMenu == "n" || returnMenu == "N"){
        main();
    }
    else {
        std::cout << "\n\tInvalid choice" << std::endl;
        returnPasswordCheck();
    }
}

void returnPasswordCreator() {
    std::cout << "\nDo you want to use this function again? (Y/N)" << std::endl;
    std::cin >> returnMenu;
    if (returnMenu == "y" || returnMenu == "Y"){
        passwordCreator();
    }
    else if (returnMenu == "n" || returnMenu == "N") {
        main();
    } else {
        std::cout << "\n\tInvalid choice" << std::endl;
        returnPasswordCreator();
    }
}

void exitSection(){
    std::cout << "\n\n" << separator << std::endl;
    std::cout << "\n\tPROGRAM IS OVER" << std::endl;
    exit(0);
}
