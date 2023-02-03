#include "license.h"
#include "tools.h"

const char* ascii_art = R"(
  _      _                          __      __       _  __ _           _   _             
 | |    (_)                         \ \    / /      (_)/ _(_)         | | (_)            
 | |     _  ___ ___ _ __  ___  ___   \ \  / /__ _ __ _| |_ _  ___ __ _| |_ _  ___  _ __  
 | |    | |/ __/ _ \ '_ \/ __|/ _ \   \ \/ / _ \ '__| |  _| |/ __/ _` | __| |/ _ \| '_ \ 
 | |____| | (_|  __/ | | \__ \  __/    \  /  __/ |  | | | | | (_| (_| | |_| | (_) | | | |
 |______|_|\___\___|_| |_|___/\___|     \/ \___|_|  |_|_| |_|\___\__,_|\__|_|\___/|_| |_|
)";

const char* menu = R"(
 1 -> Create license
 2 -> Delete license
 3 -> Validate license
 4 -> Update license
 5 -> License validity check
)";

std::regex email_regex(R"((?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|"(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\]))");

void license_framework::main_loop()
{
    while (true)
    {
        license_framework::clear_console();
        std::cout << ascii_art << "\n\n";
        std::cout << menu << "\n\n";
        std::cout << "Option: ";
        
    }
}   

void license_framework::clear_console()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void license_framework::print_menu()
{
	std::cout << ascii_art << "\n\n";
	std::cout << menu << "\n\n";
}

std::string license_framework::generate_license()
{
	return uuid::generate_uuid_v4();
}

bool license_framework::validate_email(std::string email)
{
    if (std::regex_search(email, email_regex)) return true; else return false;
}

bool license_framework::validate_password(std::string password)
{
    if (password.find(':') == std::string::npos) return true; else return false;
}
