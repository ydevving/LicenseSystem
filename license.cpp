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

void License::show_licenses()
{
    if (!m_lFile->is_open()) m_lFile->open("licenses.txt", std::fstream::in | std::fstream::app);

    bool present = false;
    c2 = "---------------------------------------\n";

    while (std::getline(*m_lFile, c1))
    {
        if ((pos = c1.find(':')) != std::string::npos && c1.substr(pos + 1) == m_Email)
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

std::string License::create_license()
{
    if (!m_lFile->is_open()) m_lFile->open("licenses.txt", std::fstream::in | std::fstream::app);

    std::string uuid = Tools::generate_uuid_v4();

    *m_lFile << uuid << ":" << m_Email << "\n";
    std::cout << uuid << std::endl;

    m_lFile->close();

    return uuid;
}

bool License::delete_license()
{
    if (!m_lFile->is_open()) m_lFile->open("licenses.txt", std::fstream::in | std::fstream::app);

    std::ofstream tempf;
    tempf.open("temp.txt", std::ofstream::out);

    if (!tempf.is_open())
    {
        std::cerr << "File IO is closed!";
        exit(-1);
    }

    while (std::getline(*m_lFile, c1))
    {
        if ((pos = c1.find(':')) != std::string::npos && c1.substr(pos+1) == m_Email)
            continue;
        else
            tempf << c1 << "\n";
    }

    // Clears bit to 'good' state after reading operation, so we can remove the file. Otherwise no perms error as file handle is open
    reset_filepos();

    m_lFile->close();
    tempf.close();

    std::remove("licenses.txt");
    std::rename("temp.txt", "licenses.txt");

    return true;
}

void License::validate_license()
{
    if (!m_lFile->is_open()) m_lFile->open("licenses.txt", std::fstream::in | std::fstream::app);

    bool found_license = false;

    while (true)
    {
        std::cout << "\nEnter your license: ";
        std::getline(std::cin, c1);

        while (std::getline(*m_lFile, c1))
        {
            if ((pos = c1.find(':')) != std::string::npos && (c1.substr(pos + 1)) == m_Email && (c1 = c1.substr(0, pos)) == c2)
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
        {
            std::cerr << "\nInvalid license.\n";
        }
    }
}

void License::reset_filepos(std::ios_base::iostate state, std::streamoff seekpos, std::ios_base::seekdir way)
{
    m_lFile->clear(state);
    m_lFile->seekg(0, std::ios::beg);
}
