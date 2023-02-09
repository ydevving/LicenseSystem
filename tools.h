#pragma once

#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <regex>
#include <sys/stat.h>

namespace Tools
{
	extern std::string generate_uuid_v4();
	extern void clear_console();
	extern void print_menu();
	extern bool exists(const char* name);
	extern bool validate_email(const std::string& email);
	extern bool validate_password(const std::string& password);
};
