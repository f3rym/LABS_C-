#include "../header.h"
#include "../header/Apartment.h"
#include "../header/Property.h"

int Apartment::getCountRoom() { return countRoom; }
int Apartment::getNumHouse() { return numHouse; }
int Apartment::getNumApartment() { return numApartment; }
int Apartment::getNumFloor() { return numFloor; }
char *Apartment::getMetro() { return metro; }
bool Apartment::getRepair() { return repair; }

void Apartment::setCountRoom(int rooms) { countRoom = rooms; }
void Apartment::setNumHouse(int house) { numHouse = house; }
void Apartment::setNumApartment(int apartment) { numApartment = apartment; }
void Apartment::setNumFloor(int floor) { numFloor = floor; }
void Apartment::setMetro(char *m) { strcpy_s(metro, m); }
void Apartment::setRepair(bool rep) { repair = rep; }

std::ostream &operator<<(std::ostream &os, Apartment &ap)
{
    Property &pr = ap;
    os << pr;
    os << std::left;
    os << std::setw(8) << ap.countRoom;
    os << std::setw(6) << ap.numHouse;
    os << std::setw(6) << ap.numApartment;
    os << std::setw(6) << ap.numFloor;
    os << std::setw(12) << ap.metro;
    if (ap.repair)
        os << std::setw(4) << "+";
    else
        os << std::setw(4) << "-";
    return os;
}
void Apartment::info()
{
    Property::info();

    std::cout << std::left;
    std::cout << std::setw(8) << "Комнат"
              << " | " << std::setw(6) << "Дом"
              << " | " << std::setw(6) << "Кв."
              << " | " << std::setw(6) << "Этаж"
              << " | " << std::setw(12) << "Метро"
              << " | " << std::setw(6) << "Рем."
              << " |" << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
}
std::istream &operator>>(std::istream &is, Apartment &ap)
{
    Property &pr = ap;
    is >> pr;
    std::cout << "Введите количество комнат: ";
    is >> ap.countRoom;
    std::cout << "Введите номер дома: ";
    is >> ap.numHouse;
    std::cout << "Введите номер квартиры: ";
    is >> ap.numApartment;
    std::cout << "Введите этаж: ";
    is >> ap.numFloor;
    is.ignore();
    std::cout << "Введите станцию метро: ";
    is.getline(ap.metro, MAX_STR);
    std::cout << "Есть ремонт (1-да/0-нет): ";
    is >> ap.repair;
    return is;
}

bool Apartment::writeToFile(const char *filename)
{
    std::ofstream file(filename, std::ios::app);
    if (!file)
    {
        std::cerr << "Ошибка открытия файла для записи\n";
        return false;
    }
    file << "apartment" << " ";
    Property::writeToFile(file);
    file << " " << this->countRoom << " " << this->numHouse << " " << this->numApartment << " " << this->numFloor << " " << this->metro << " " << this->repair << std::endl;
    return true;
}

LinkedList<Apartment> Apartment::readFromFile(const char *filename)
{
    LinkedList<Apartment> apartments;
    std::ifstream file(filename);

    if (!file)
    {
        std::cerr << "Ошибка открытия файла для чтения\n";
        return apartments;
    }

    char type[MAX_STR];
    Apartment temp;
    while (file >> type)
    {
        if (strcmp(type, "apartment") == 0)
        {
            Property &pr = temp;
            pr = Property::readFromFile(file);
            file >> temp.countRoom >> temp.numHouse >> temp.numApartment >> temp.numFloor >> temp.metro >> temp.repair;
            apartments.addToEnd(temp);
        }
        else
        {
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return apartments;
}
