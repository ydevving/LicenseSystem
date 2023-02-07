#include "license.h"
#include "tools.h"

bool license::exists(const char* name) {
    struct stat buffer;
    return (stat(name, &buffer) == 0);
}

void license::clear_console()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void license::print_menu()
{
	std::cout << ascii_art << "\n\n";
    std::cout << menu << "\n\n";
}

std::string license::generate_license()
{
	return uuid::generate_uuid_v4();
}

bool license::validate_email(const std::string& email)
{
    if (std::regex_search(email, email_regex)) return true; else return false;
}

bool license::validate_password(const std::string& password)
{
    if (password.find(':') == std::string::npos) return true; else return false;
}

void license::io_check()
{
    std::cout << "io_check\n";
    if (!accountsf.is_open())
    {
        accountsf.open("accounts.txt", std::fstream::in | std::fstream::app);
        accountsf.clear();
        accountsf.seekg(0, std::ios::beg);
    }

    if (!licensesf.is_open())
    {
        licensesf.open("licenses.txt", std::fstream::in | std::fstream::app);
        licensesf.clear();
        licensesf.seekg(0, std::ios::beg);
    }
}

void license::show_licenses(const std::string& email)
{
    license::io_check();

    if (!licensesf.is_open()) return;

    std::cout << "Past checks\n";
    std::cout << email << '\n';

    bool present = false;

    input = "---------------------------------------\n";

    std::cout << licensesf.rdstate() << "\n";

    while (std::getline(licensesf, temp))
    {
        std::cout << temp << '\n';
        if ((pos = temp.find(':')) != std::string::npos && (temp.substr(pos + 1)) == email)
        {
            if (!present) present = true;
            input += "|";
            input += temp.substr(0, pos);;
            input += "|";
            input += "\n";
        }
    }

    if (present)
        input += "---------------------------------------\n";
    else
        input = "\nNo licenses present! Create one.\n";

    std::cout << input << "\n";

    licensesf.clear();
    licensesf.seekg(0, std::ios::beg);
}

std::string license::create_license(const std::string& email)
{
    license::io_check();

    std::string uuid = uuid::generate_uuid_v4();
    licensesf << uuid << ":" << email << "\n";
    std::cout << uuid << std::endl;

    licensesf.close();

    return uuid;
}

bool license::delete_license(const std::string& email)
{
    license::io_check();

    std::ofstream tempf;
    tempf.open("temp.txt", std::ofstream::out);

    if (!tempf.is_open())
    {
        std::cerr << "File IO is closed!";
        exit(-1);
    }

    while (std::getline(licensesf, temp))
    {
        if ((pos = temp.find(':')) != std::string::npos && (input = temp.substr(pos+1)) == email)
        {
            std::cout << temp << "\n";
            std::cout << "Found, removing line\n";
            continue;
        }
        else
        {
            std::cout << "Else\n" << temp << "\n";
            tempf << temp << "\n";
        }
    }

    // Clears bit to 'good' state after reading operation, so we can remove the file. Otherwise no perms error as file handle is open
    licensesf.clear();
    licensesf.seekg(0, std::ios::beg);

    tempf.close();
    licensesf.close();
;
    std::cout << "Remove!\n";
    std::cout << std::remove("licenses.txt") << "\n";
    std::cout << std::rename("temp.txt", "licenses.txt") << "\n";

    std::cout << "Exists: " << license::exists("licenses.txt") << " | " << license::exists("temp.txt") << "\n";

    return true;
}

void license::validate_license(const std::string& email)
{
    license::io_check();

    bool found_license = false;

    while (true)
    {
        std::cout << "\nEnter your license: ";
        std::getline(std::cin, input);

        while (std::getline(licensesf, temp))
        {
            if ((pos = temp.find(':')) != std::string::npos && (temp.substr(pos + 1)) == email && (temp = temp.substr(0, pos)) == input)
            {
                found_license = true;
                break;
            }
        }

        licensesf.clear();
        licensesf.seekg(0, std::ios::beg);

        if (found_license)
        {
            std::cout << "Your active license found - " << temp << "\n";
            break;
        }
        else
            std::cerr << "\nInvalid license.\n";
    }
}
