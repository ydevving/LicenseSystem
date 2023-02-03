#include <iostream>
#include <fstream>
#include <string>

#include "license.h"

int main()
{
    const char* lr = "Login/Register\n\n 1 -> Login \n 2 -> Register \n\nOption: ";
    std::string choice;
    std::string temp;
    std::fstream accounts_f("accounts.txt");

    bool newly_made = (accounts_f) ? true : false;

    accounts_f.open("accounts.txt", std::fstream::in | std::fstream::app);

    std::getline(accounts_f, temp);
    if (temp == "") newly_made = true;

    while (true)
    {
        license_framework::clear_console();
        std::cout << lr;

        std::getline(std::cin, choice);
        
        if (choice == "1" && newly_made == false)
        {
            
        }
        else if (choice == "1" && newly_made == true)
        {
            std::cout << "No active accounts in database, make an account first!\nEnter to continue...";
            std::cin.get();
            continue;
        }
        else if (choice == "2")
        {
            while (std::getline(accounts_f, temp))
            {
                if (temp != "" && temp.find(':') == std::string::npos)
                {
                    
                }
            }
        }
        else
        {
            std::cerr << "Wrong input, choose either 1 or 2!\n";
        }
    }

    std::cin.get();
}