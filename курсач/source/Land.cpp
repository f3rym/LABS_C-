#include "../header.h"
#include "../header/Land.h"

char *Land::getLandType() { return landType; }

void Land::setLandType(char *type) { strcpy_s(landType, type); }

std::ostream &operator<<(std::ostream &os, Land &l)
{
    PrivateSector &ps = l;
    os << ps;
    os << std::left;
    os << std::setw(10) << l.landType;
    return os;
}
void Land::info()
{
    PrivateSector::info();

    std::cout << " | " << std::left;
    std::cout << " | " << std::setw(10) << "Тип участка"
              << " |\n";
}


std::istream &operator>>(std::istream &is, Land &l)
{
    PrivateSector &ps = l;
    is >> ps;
    is.ignore();
    std::cout << "Введите тип участка: ";
    is.getline(l.landType, MAX_STR);
    return is;
}

bool Land::writeToFile(const char *filename)
{
    std::ofstream file(filename, std::ios::app);
    if (!file)
    {
        std::cerr << "Ошибка открытия файла для записи\n";
        return false;
    }
    file << "land" << " ";
    PrivateSector::writeToFile(file);
    file << " " << this->landType << std::endl;
    return true;
}

LinkedList<Land> Land::readFromFile(const char *filename)
{
    LinkedList<Land> land;
    std::ifstream file(filename);

    if (!file)
    {
        std::cerr << "Ошибка открытия файла для чтения\n";
        return land;
    }
    char type[MAX_STR];
    Land temp;
    while (file >> type)
    {
        if (strcmp(type, "land") == 0)
        {
            PrivateSector &pr = temp;
            pr = PrivateSector::readFromFile(file);
            file >> temp.landType;
            land.addToEnd(temp);
        }
        else
        {
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return land;
}