#include "license.h"

License::License(const std::string& email, std::fstream* lFile, std::fstream* aFile)
{
    m_Email = email;
    m_lFile = lFile;
    m_aFile = aFile;

    std::cout << "License object created!\n";
}

License::~License()
{
    m_lFile->close();
    m_aFile->close();

    m_lFile = nullptr;
    m_aFile = nullptr;
}

void License::show_licenses(const std::string& email)
{
    if (!m_lFile->is_open()) return;

    c2 = "---------------------------------------\n";

    while (std::getline(*m_lFile, c1))
    {
        if ((pos = c1.find(':')) != std::string::npos && (c1.substr(pos + 1)) == email)
        {
            if (!present) present = true;
            c2 += "|";
            c2 += c1.substr(0, pos);
            c2 += "|";
            c2 += "\n";
        }
    }

    if (present)
        c2 += "---------------------------------------\n";
    else
        c2 = "\nNo licenses present! Create one.\n";

    reset_filepos();

    std::cout << c2 << "\n";
}

std::string License::create_license(const std::string& email)
{
    std::string uuid = Tools::generate_uuid_v4();

    *m_lFile << uuid << ":" << email << "\n";
    std::cout << uuid << std::endl;

    m_lFile->close();

    return uuid;
}

bool License::delete_license(const std::string& email)
{
    std::ofstream tempf;
    tempf.open("temp.txt", std::ofstream::out);

    if (!tempf.is_open())
    {
        std::cerr << "File IO is closed!";
        exit(-1);
    }

    while (std::getline(*m_lFile, c1))
    {
        if ((pos = c1.find(':')) != std::string::npos && c1.substr(pos+1) == email)
        {
            std::cout << "Found, removing line\n";
            continue;
        }
        else
        {
            std::cout << "Else\n" << c1 << "\n";
            tempf << c1 << "\n";
        }
    }

    // Clears bit to 'good' state after reading operation, so we can remove the file. Otherwise no perms error as file handle is open
    reset_filepos();

    m_lFile->close();
    tempf.close();

    std::cout << std::remove("licenses.txt") << "\n";
    perror("Error occured");
    std::cout << std::rename("temp.txt", "licenses.txt") << "\n";

    std::cout << "Exists: " << Tools::exists("licenses.txt") << " | " << Tools::exists("temp.txt") << "\n";

    return true;
}

void License::validate_license(const std::string& email)
{
    bool found_license = false;

    while (true)
    {
        std::cout << "\nEnter your license: ";
        std::getline(std::cin, c1);

        while (std::getline(*m_lFile, c1))
        {
            if ((pos = c1.find(':')) != std::string::npos && (c1.substr(pos + 1)) == email && (c1 = c1.substr(0, pos)) == c2)
            {
                found_license = true;
                break;
            }
        }

        reset_filepos();

        if (found_license)
        {
            std::cout << "Your active license found - " << c1 << "\n";
            break;
        }
        else
            std::cerr << "\nInvalid license.\n";
    }
}

void License::reset_filepos(std::ios_base::iostate state, std::streamoff seekpos, std::ios_base::seekdir way)
{
    m_lFile->clear(state);
    m_lFile->seekg(0, std::ios::beg);
}
