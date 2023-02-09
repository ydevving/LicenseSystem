#pragma once

#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <regex>
#include <sys/stat.h>

struct Tools
{
public:
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

	std::regex email_regex{ R"((?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|"(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\]))" };

	std::random_device				rd;
	std::mt19937                    gen(rd());
	std::uniform_int_distribution<> dis(0, 15);
	std::uniform_int_distribution<> dis2(8, 11);

	std::string generate_uuid_v4();
	void clear_console();
	void print_menu();
	bool exists(const char* name);
	bool validate_email(const std::string& email);
	bool validate_password(const std::string& password);

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
};
