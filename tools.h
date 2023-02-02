#pragma once

#include <random>
#include <sstream>
#include <string>

namespace uuid {
    static std::random_device              rd;
    static std::mt19937                    gen(rd());
    static std::uniform_int_distribution<> dis(0, 15);
    static std::uniform_int_distribution<> dis2(8, 11);

    std::string generate_uuid_v4();
}

struct Colors
{
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