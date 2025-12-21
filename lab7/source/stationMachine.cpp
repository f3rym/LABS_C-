#include "../header/stationaryMachine.h"
#include "../header/ExpInput.h"

StationaryMachine &StationaryMachine::operator=(const StationaryMachine &other)
{

    if (this != &other)
    {
        ComputingMachine::operator=(other);
        PCISlots = other.PCISlots;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const StationaryMachine &sm)
{
    const ComputingMachine &comp = sm;
    os << comp;
    os << std::setw(20) << sm.getPCISlots();
    return os;
}

void StationaryMachine::sortList(std::vector<ComputingMachine *> &list)
{
    // Сначала вызываем базовую сортировку
    ComputingMachine::sortList(list);

    // Проверяем, не прервали ли базовую сортировку
    if (list.empty())
        return;

    int choice;
    std::cout << "\n=== Сортировка параметров стационарных машин ===" << std::endl;
    std::cout << "1. Сортировка по количеству PCI слотов (возрастание)" << std::endl;
    std::cout << "2. Сортировка по количеству PCI слотов (убывание)" << std::endl;
    std::cout << "0. Пропустить" << std::endl;
    std::cout << "Выберите параметр: ";

    if (!(std::cin >> choice))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверный ввод!" << std::endl;
        return;
    }

    switch (choice)
    {
    case 1: 
        std::sort(list.begin(), list.end(),
                  [](ComputingMachine *a, ComputingMachine *b)
                  {
                      StationaryMachine *sa = dynamic_cast<StationaryMachine *>(a);
                      StationaryMachine *sb = dynamic_cast<StationaryMachine *>(b);
                      if (!sa && !sb)
                          return false; 
                      if (!sa)
                          return true; 
                      if (!sb)
                          return false;

                      return sa->PCISlots < sb->PCISlots;
                  });
        std::cout << "Сортировка по PCI слотам (возрастание) завершена!" << std::endl;
        break;

    case 2: 
        std::sort(list.begin(), list.end(),
                  [](ComputingMachine *a, ComputingMachine *b)
                  {
                      StationaryMachine *sa = dynamic_cast<StationaryMachine *>(a);
                      StationaryMachine *sb = dynamic_cast<StationaryMachine *>(b);

                      if (!sa && !sb)
                          return false;
                      if (!sa)
                          return true;
                      if (!sb)
                          return false;

                      return sa->PCISlots > sb->PCISlots;
                  });
        std::cout << "Сортировка по PCI слотам (убывание) завершена!" << std::endl;
        break;

    case 0:
        std::cout << "Сортировка пропущена!" << std::endl;
        break;

    default:
        std::cout << "Неверный выбор!" << std::endl;
    }
}

void StationaryMachine::readFromStream(std::istream &is)
{
    ComputingMachine::readFromStream(is);
    char delimiter = ';';
    int pci = 0;
    if (!(is >> delimiter))
        return;
    if (!(is >> pci))
        return;
    is.ignore();
    setPCISlots(pci);
}

void StationaryMachine::writeToStream(std::ostream &os) const
{
    ComputingMachine::writeToStream(os);
    os << ';' << getPCISlots();
}
void StationaryMachine::setMenu()
{
    ComputingMachine::setMenu();
    int choice;
    int intValue;
    ExpInput exp;

    do
    {
        std::cout << "\n=== Редактирование параметров стационарной машины ===" << std::endl;
        std::cout << "1. Изменить количество PCI слотов (" << PCISlots << ")" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выберите параметр для редактирования: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Введите количество PCI слотов: ";
            intValue = exp.isNumber(std::cin, 0, INT_MAX);
            setPCISlots(intValue);
            std::cout << "Количество PCI слотов изменено!" << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

std::istream &operator>>(std::istream &is, StationaryMachine &sm)
{
    ExpInput exp;
    ComputingMachine &comp = sm;
    is >> comp;
    std::cout << "Введите количество PCI слотов: ";
    sm.PCISlots = exp.isNumber(std::cin, 0, INT_MAX);
    return is;
}

void StationaryMachine::info()
{
    ComputingMachine::info();
    std::cout << std::setw(20) << "PCI Slots";
}

int StationaryMachine::getPCISlots() const { return PCISlots; };
void StationaryMachine::setPCISlots(int PCISlots)
{
    this->PCISlots = PCISlots;
}