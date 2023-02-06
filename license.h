#pragma once

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <sys/stat.h>
#include <filesystem>

static int pos;
static std::string input, temp, email;
static std::fstream accountsf;
static std::fstream licensesf;

static const char* ascii_art = R"(
	  _      _                          __      __       _  __ _           _   _             
	 | |    (_)                         \ \    / /      (_)/ _(_)         | | (_)            
	 | |     _  ___ ___ _ __  ___  ___   \ \  / /__ _ __ _| |_ _  ___ __ _| |_ _  ___  _ __  
	 | |    | |/ __/ _ \ '_ \/ __|/ _ \   \ \/ / _ \ '__| |  _| |/ __/ _` | __| |/ _ \| '_ \ 
	 | |____| | (_|  __/ | | \__ \  __/    \  /  __/ |  | | | | | (_| (_| | |_| | (_) | | | |
	 |______|_|\___\___|_| |_|___/\___|     \/ \___|_|  |_|_| |_|\___\__,_|\__|_|\___/|_| |_|
	)";

static const char* menu = R"(
	 1 -> Create license
	 2 -> Delete license
	 3 -> Validate license
	 4 -> Update license
	 5 -> License expiration check
	)";

static std::regex email_regex{ R"((?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|"(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\]))" };

class license
{
private:
	std::string m_Email;
public:
	static bool exists(const std::string& name);
	static void clear_console();
	static void print_menu();
	static std::string generate_license();
	static bool validate_email(const std::string& email);
	static bool validate_password(const std::string& password);
	static void io_check();
	static std::string create_license(const std::string& email);
	static bool delete_license(const std::string& email);
	static void validate_license();
	static void update_license();
	static void license_expiration();
};
