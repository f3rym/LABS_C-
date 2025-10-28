#include "../header.h"
#include "../header/Garage.h"

bool Garage::getHasElectricity() { return hasElectricity; }
bool Garage::getHasHeating() { return hasHeating; }

void Garage::setHasElectricity(bool electricity) { hasElectricity = electricity; }
void Garage::setHasHeating(bool heating) { hasHeating = heating; }

std::ostream &operator<<(std::ostream &os, Garage &gar)
{
    NonResidential &nr = gar;
    os << nr;
    os << std::left;
    if (gar.hasElectricity)
        os << std::setw(3) << "+";
    else
        os << std::setw(3) << "-";
    if (gar.hasHeating)
        os << std::setw(3) << "+";
    else
        os << std::setw(3) << "-";
    return os;
}

void Garage::info()
{
    NonResidential::info();
    std::cout << std::left;
    std::cout << std::setw(6) << "Пл.Раб.пов(м²)"
        << " | " << std::setw(3) << "Электричество"
        << " | " << std::setw(3) << "Отопление"
        << "  |\n";
}

std::istream &operator>>(std::istream &is, Garage &gar)
{
    NonResidential &nr = gar;
    is >> nr;
    std::cout << "Есть электричество (1-да/0-нет): ";
    is >> gar.hasElectricity;
    std::cout << "Есть отопление (1-да/0-нет): ";
    is >> gar.hasHeating;
    return is;
}

bool Garage::writeToFile(const char *filename)
{
    std::ofstream file(filename, std::ios::app);
    if (!file)
    {
        std::cerr << "Ошибка открытия файла для записи\n";
        return false;
    }
    file << "garage" << " ";
    NonResidential::writeToFile(file);
    file << " " << this->hasElectricity << " " << this->hasHeating << std::endl;
    return true;
}

LinkedList<Garage> Garage::readFromFile(const char *filename)
{
    LinkedList<Garage> gar;
    std::ifstream file(filename);

    if (!file)
    {
        std::cerr << "Ошибка открытия файла для чтения\n";
        return gar;
    }
    char type[MAX_STR];
    Garage temp;
    while (file >> type)
    {
        if (strcmp(type, "garage") == 0)
        {
            NonResidential &pr = temp;
            pr = NonResidential::readFromFile(file);
            file >> temp.hasElectricity >> temp.hasHeating;
            gar.addToEnd(temp);
        }
        else
        {
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return gar;
}