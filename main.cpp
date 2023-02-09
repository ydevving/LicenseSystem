#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "license.h"
#include "tools.h"

int main()
{
    bool empty_db = false;

    std::fstream aFile, lFile;
    std::string input, temp, email;
    size_t pos;

    aFile.open("accounts.txt", std::fstream::in | std::fstream::app);
    lFile.open("licenses.txt", std::fstream::in | std::fstream::app);
    
    while (std::getline(aFile, temp))
    {
        if (temp.find(':') != std::string::npos) break; else empty_db = true; break;
    }

    aFile.seekg(0);

    // Login/Registration menu
    while (true)
    {
        Tools::clear_console();
        std::cout << "Login/Register\n\n 1 -> Login \n 2 -> Register \n 3 -> Exit\n\nOption: ";

        std::getline(std::cin, input);
        
        if (input == "1" && empty_db == false)
        {
            if (!aFile.is_open())
                aFile.open("accounts.txt");

            bool run_loop = true;
            while (run_loop)
            {
                std::cout << "Enter a new e-mail: ";
                std::getline(std::cin, input);

                if (Tools::validate_email(input))
                {
                    while (std::getline(aFile, temp))
                    {
                        if ((pos = temp.find(':')) != std::string::npos && (email = temp.substr(0, pos)) == input)
                        {
                            run_loop = false;
                            break;
                        }
                    }

                    aFile.clear();
                    aFile.seekg(0, std::ios::beg);
                }
                else
                    std::cerr << "\nInvalid email, please input a valid email address.\n";
            }

            run_loop = true;

            while (run_loop)
            {
                std::cout << "Enter a new password: ";
                std::getline(std::cin, input);

                if (Tools::validate_password(input))
                {
                    while (std::getline(aFile, temp))
                    {
                        std::cout << temp << std::endl;
                        if ((pos = temp.find(':')) != std::string::npos && (temp = temp.substr(pos+1)) == input)
                        {
                            run_loop = false;
                            break;
                        }
                    }
                    
                    aFile.clear();
                    aFile.seekg(0, std::ios::beg);
                }
                else
                    std::cerr << "\nInvalid email, please input a valid email address.\n";
            }

            std::cout << "Logged in successfully!\n";
            break;
        }
        else if (input == "1" && empty_db == true)
        {
            std::cout << "No active accounts in database, make an account first!\nEnter to continue...";
            std::cin.get();
            continue;
        }
        else if (input == "2")
        {
            aFile.clear();
            aFile.seekg(0);

            while (true)
            {
                std::cout << "Enter a new e-mail: ";
                std::getline(std::cin, temp);
                if (Tools::validate_email(temp))
                    break;
                else
                    std::cerr << "\nInvalid email, please input a valid email address.\n";
            }

            while (true)
            {
                std::cout << "Enter a new password: ";
                std::getline(std::cin, input);
                if (Tools::validate_password(input))
                    break;
                else
                    std::cerr << "\nInvalid password, please remove the \':\' from the input.\n";
            }

            aFile << temp << ":" << input << "\n";
            aFile.close();

            std::cout << "\nSuccessfully created account! (password -> " << input << ")\n";
            std::cout << "\nPress enter to continue...";
            std::cin.get();
        }
        else if (input == "3")
        {
            exit(0);
        }
        else
        {
            std::cerr << "Wrong input, choose either 1 or 2!\n";
        }
    }

    // License menu

    if (!Tools::validate_email(email) || !lFile || !aFile)
    {
        std::cout << "Error encountered creating License object!\n";
        exit(-1);
    }

    License account(email, &lFile, &aFile);

    while (true)
    {
        
        Tools::clear_console();
        Tools::print_menu();
        
        while (true)
        {
            std::cout << "Option: ";
            std::getline(std::cin, input);

            if (input.length() > 1)
                continue;

            switch (input.c_str()[0])
            {
            case '1':
                account.show_licenses();
                break;
            case '2':
                account.create_license();
                break;
            case '3':
                account.delete_license();
                break;
            case '4':
                account.validate_license();
                break;
            default:
                break;
            }
        }

    }

    if (aFile.is_open())
        aFile.close();
    if (lFile.is_open())
        lFile.close();

    std::cin.get();
}