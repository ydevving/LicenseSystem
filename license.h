#pragma once

#include <iostream>
#include <string>
#include <regex>

class license_framework
{
private:
public:
	static void clear_console();
	static void print_menu();
	std::string generate_license();
	bool validate_email(std::string email);
	bool validate_password(std::string password);
};