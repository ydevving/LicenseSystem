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
	 1 -> Show licenses
	 2 -> Create license
	 3 -> Delete license
	 4 -> Validate license
	)";


std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 15);
std::uniform_int_distribution<> dis2(8, 11);

std::regex email_regex{ R"((?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|"(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\]))" };

const char* red = "\x1B[31m";
const char* green = "\x1B[32m";
const char* yellow = "\x1B[33m";
const char* blue = "\x1B[34m";
const char* magenta = "\x1B[35m";
const char* cyan = "\x1B[36m";
const char* bright_red = "\x1B[91m";
const char* bright_green = "\x1B[92m";
const char* bright_yellow = "\x1B[93m";
const char* bright_blue = "\x1B[94m";
const char* bright_magenta = "\x1B[95m";
const char* bright_cyan = "\x1B[96m";

const char* end = "\033[0m";

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
    std::cout << ascii_art << "\n\n";
    std::cout << menu << "\n\n";
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
