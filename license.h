#pragma once

#include <iostream>
#include <string>
#include <regex>

class license_framework
{
private:
public:
	static void main_loop();
	static void clear_console();
	static void print_menu();
	static std::string generate_license();
	static bool validate_email(std::string email);
	static bool validate_password(std::string password);
};