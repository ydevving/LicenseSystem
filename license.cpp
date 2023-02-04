#include "license.h"
#include "tools.h"

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
	std::cout << ldata::ascii_art << "\n\n";
    std::cout << ldata::menu << "\n\n";
}

std::string license_framework::generate_license()
{
	return uuid::generate_uuid_v4();
}

bool license_framework::validate_email(std::string email)
{
    if (std::regex_search(email, ldata::email_regex)) return true; else return false;
}

bool license_framework::validate_password(std::string password)
{
    if (password.find(':') == std::string::npos) return true; else return false;
}

void license_framework::create_license()
{

}
