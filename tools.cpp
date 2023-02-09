#include "tools.h"

std::string Tools::generate_uuid_v4() 
{
    std::stringstream ss;
    int i;
    ss << std::hex;

    for (i = 0; i < 8; i++) {
        ss << dis(gen);
    }
    ss << "-";
    for (i = 0; i < 4; i++) {
        ss << dis(gen);
    }
    ss << "-4";
    for (i = 0; i < 3; i++) {
        ss << dis(gen);
    }
    ss << "-";
    ss << dis2(gen);
    for (i = 0; i < 3; i++) {
        ss << dis(gen);
    }
    ss << "-";
    for (i = 0; i < 12; i++) {
        ss << dis(gen);
    };

    return ss.str();
}

void Tools::clear_console()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void Tools::print_menu()
{
    std::cout << Tools::ascii_art << "\n\n";
    std::cout << Tools::menu << "\n\n";
}

bool Tools::exists(const char* name)
{
    struct stat buffer;
    return (stat(name, &buffer) == 0);
}

bool Tools::validate_email(const std::string& email)
{
    if (std::regex_search(email, email_regex)) return true; else return false;
}

bool Tools::validate_password(const std::string& password)
{
    if (password.find(':') == std::string::npos) return true; else return false;
}