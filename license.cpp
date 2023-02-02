#include "license.h"
#include "tools.h"

#include <iostream>

const char* ascii_art = R"(
  _      _                          __      __       _  __ _           _   _             
 | |    (_)                         \ \    / /      (_)/ _(_)         | | (_)            
 | |     _  ___ ___ _ __  ___  ___   \ \  / /__ _ __ _| |_ _  ___ __ _| |_ _  ___  _ __  
 | |    | |/ __/ _ \ '_ \/ __|/ _ \   \ \/ / _ \ '__| |  _| |/ __/ _` | __| |/ _ \| '_ \ 
 | |____| | (_|  __/ | | \__ \  __/    \  /  __/ |  | | | | | (_| (_| | |_| | (_) | | | |
 |______|_|\___\___|_| |_|___/\___|     \/ \___|_|  |_|_| |_|\___\__,_|\__|_|\___/|_| |_|
)";

void license_framework::print_menu()
{
	std::cout << ascii_art << "\n\n";

}

std::string license_framework::generate_license()
{
	return uuid::generate_uuid_v4();
}
