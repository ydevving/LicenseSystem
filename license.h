#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "tools.h"

class License
{
public:
	License() = delete;
	License(const std::string& email, std::fstream* lFile, std::fstream* aFile);
	~License();

	void show_licenses(const std::string& email);
	std::string create_license(const std::string& email);
	bool delete_license(const std::string& email);
	void validate_license(const std::string& email);
private:
	void reset_filepos(std::ios_base::iostate state = 0, std::streamoff seekpos = 0, std::ios_base::seekdir way = std::ios::beg);
private:
	std::string m_Email;
	std::fstream* m_lFile;
	std::fstream* m_aFile;

	// c1 = temp, c2 = input (temporary reference, DELETE COMMENT AFTER REFACTORING!)
	std::string c1, c2;
	size_t pos;

	bool present = false;
};
