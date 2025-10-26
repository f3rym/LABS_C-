#include "../header.h"
#include "../header/Storage.h"

char *Storage::getTempRegime() { return tempRegime; }
int Storage::getStorageVolume() { return storageVolume; }
bool Storage::getTruckAccess() { return truckAccess; }

void Storage::setTempRegime(char *temp) { strcpy_s(tempRegime, temp); }
void Storage::setStorageVolume(int volume) { storageVolume = volume; }
void Storage::setTruckAccess(bool truck) { truckAccess = truck; }

std::ostream &operator<<(std::ostream &os, Storage &st)
{
    Commercial &com = st;
    os << com;
    os << std::left;
    os << std::setw(6) << st.tempRegime;
    os << std::setw(6) << st.storageVolume;
    if (st.truckAccess)
        os << std::setw(3) << "+";
    else
        os << std::setw(3) << "-";
    return os;
}

void Storage::info()
{
    Commercial::info();

    std::cout << std::left;
    std::cout << " | " << std::setw(6) << "Темп."
              << " | " << std::setw(6) << "Объем"
              << " | " << std::setw(3) << "Фура"
              << " |\n";
}

std::istream &operator>>(std::istream &is, Storage &st)
{
    Commercial &com = st;
    is >> com;
    is.ignore();
    std::cout << "Введите температурный режим: ";
    is.getline(st.tempRegime, MAX_STR);
    std::cout << "Введите объем хранения: ";
    is >> st.storageVolume;
    std::cout << "Есть подъезд для фур (1-да/0-нет): ";
    is >> st.truckAccess;
    return is;
}