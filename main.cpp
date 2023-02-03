#include <iostream>
#include <fstream>
#include <string>

#include "license.h"

int main()
{
    const char* lr = "Login/Register\n\n 1 -> Login \n 2 -> Register \n\nOption: ";
    std::string input, temp;
    std::fstream accounts_f("accounts.txt");

    bool newly_made = (accounts_f) ? true : false;

    accounts_f.open("accounts.txt", std::ios::app | std::ios::in);

    //std::getline(accounts_f, temp);
    if (temp == "") newly_made = true;

    while (true)
    {
        license_framework::clear_console();
        std::cout << accounts_f.is_open() << '\n';
        std::cout << newly_made << std::endl;
        std::cout << lr;

        std::getline(std::cin, input);
        
        if (input == "1" && newly_made == true)
        {
            std::cout << "De lul";
            while (std::getline(accounts_f, temp))
            {
                std::cout << "Gekke manna\n";
                std::cout << temp << '\n';
            }
            
            std::cin.get();
        }
        else if (input == "1" && newly_made == true)
        {
            std::cout << "No active accounts in database, make an account first!\nEnter to continue...";
            std::cin.get();
            continue;
        }
        else if (input == "2")
        {
            while (true)
            {
                std::cout << "Enter a new e-mail: ";
                std::getline(std::cin, input);
                if (license_framework::validate_email(input))
                    break;
                else
                    std::cerr << "\nInvalid email, please input a valid email address.\n";
            }

            std::cout << input << '\n';
            accounts_f << input << ":";

            while (true)
            {
                std::cout << "Enter a new password: ";
                std::getline(std::cin, input);
                if (license_framework::validate_password(input))
                    break;
                else
                    std::cerr << "\nInvalid password, please remove the \':\' from the input.\n";
            }

            accounts_f << input << "\n";
            accounts_f.close();

            std::cout << "\nSuccessfully created account! (password -> " << input << ")\n";
            std::cout << "\nPress enter to continue...";
            std::cin.get();
        }
        else if (input == "3")
        {
            break;
        }
        else
        {
            std::cerr << "Wrong input, choose either 1 or 2!\n";
        }
    }

    accounts_f.close();

    std::cin.get();
}