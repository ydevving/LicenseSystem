#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "license.h"

int main()
{
    const char* lr = "Login/Register\n\n 1 -> Login \n 2 -> Register \n\nOption: ";
    bool empty_db = false;

    accounts_f.open("accounts.txt", std::fstream::in | std::fstream::app);
    licenses_f.open("licenses.txt", std::fstream::in | std::fstream::app);
    
    while (std::getline(accounts_f, temp))
    {
        if (temp.find(':') != std::string::npos) break; else empty_db = true; break;
    }

    accounts_f.seekg(0);

    // Login/Registration menu
    while (true)
    {
        license::clear_console();
        std::cout << lr;

        std::getline(std::cin, input);
        
        if (input == "1" && empty_db == false)
        {
            if (!accounts_f.is_open())
                accounts_f.open("accounts.txt");

            bool run_loop = true;
            while (run_loop)
            {
                std::cout << "Enter a new e-mail: ";
                std::getline(std::cin, input);

                if (license::validate_email(input))
                {
                    while (std::getline(accounts_f, temp))
                    {
                        if ((pos = temp.find(':')) != std::string::npos && (temp = temp.substr(0, pos)) == input)
                        {
                            email = temp;
                            run_loop = false;
                            break;
                        }
                    }

                    accounts_f.clear(); //Yo
                    accounts_f.seekg(0, std::ios::beg);
                }
                else
                    std::cerr << "\nInvalid email, please input a valid email address.\n";
            }

            run_loop = true;

            while (run_loop)
            {
                std::cout << "Enter a new password: ";
                std::getline(std::cin, input);

                if (license::validate_password(input))
                {
                    while (std::getline(accounts_f, temp))
                    {
                        std::cout << temp << std::endl;
                        if ((pos = temp.find(':')) != std::string::npos && (temp = temp.substr(pos+1)) == input)
                        {
                            run_loop = false;
                            break;
                        }
                    }
                    
                    accounts_f.clear();
                    accounts_f.seekg(0, std::ios::beg);
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
            while (true)
            {
                std::cout << "Enter a new e-mail: ";
                std::getline(std::cin, input);
                if (license::validate_email(input))
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
                if (license::validate_password(input))
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

    // License menu
    while (true)
    {
        license::clear_console();
        license::print_menu();
        
        while (true)
        {
            std::cout << "Option: ";
            std::getline(std::cin, input);

            if (input.length() > 1)
                continue;

            switch (input.c_str()[0])
            {
            case '1':
                license::create_license(email);
                break;
            case '2':
                license::delete_license(email);
                break;
            case '3':
                //license::validate_license(email);
                break;
            case '4':
                //license::update_license(email);
                break;
            case '5':
                //license::license_expiration(email);
                break;
            default:
                continue;
            }
        }

    }

    if (!accounts_f.is_open())
        accounts_f.close();
    if (!licenses_f.is_open())
        licenses_f.close();

    std::cin.get();
}