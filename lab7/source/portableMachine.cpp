#include "../header.h"
#include "../header/portableMachine.h"
#include "../header/ExpInput.h"
portableMachine &portableMachine::operator=(const portableMachine &other)
{
    if (this != &other)
    {
        ComputingMachine::operator=(other);
        batteryHealth = other.batteryHealth;
        sizeDisplay = other.sizeDisplay;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const portableMachine &pm)
{
    const ComputingMachine &com = pm;
    os << com;
    os << std::setw(20) << pm.getBatteryHealth();
    os << std::setw(20) << pm.getSizeDisplay();
    return os;
}

std::istream &operator>>(std::istream &is, portableMachine &pm)
{
    ExpInput exp;
    ComputingMachine &com = pm;
    is >> com;
    std::cout << "Введите ёмкость батареи(mAh): ";
    pm.batteryHealth = exp.isNumber(std::cin, 0, INT_MAX);
    std::cout << "Введите размер дисплея(дюйм): ";
    pm.sizeDisplay = exp.isNumber(std::cin, 0, INT_MAX);

    return is;
}

void portableMachine::sortList(std::vector<ComputingMachine *> &list)
{
    ComputingMachine::sortList(list);

    int choice;
    std::cout << "\n=== Сортировка параметров портативного устройства ===" << std::endl;
    std::cout << "1. Сортировка по емкости батареи (возрастание)" << std::endl;
    std::cout << "2. Сортировка по емкости батареи (убывание)" << std::endl;
    std::cout << "3. Сортировка по размеру дисплея (возрастание)" << std::endl;
    std::cout << "4. Сортировка по размеру дисплея (убывание)" << std::endl;
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
                      portableMachine *pa = dynamic_cast<portableMachine *>(a);
                      portableMachine *pb = dynamic_cast<portableMachine *>(b);

                      if (!pa && !pb)
                          return false;
                      if (!pa)
                          return true; 
                      if (!pb)
                          return false;

                      return pa->batteryHealth < pb->batteryHealth;
                  });
        std::cout << "Сортировка по батарее (возрастание) завершена!" << std::endl;
        break;

    case 2: // Батарея - убывание
        std::sort(list.begin(), list.end(),
                  [](ComputingMachine *a, ComputingMachine *b)
                  {
                      portableMachine *pa = dynamic_cast<portableMachine *>(a);
                      portableMachine *pb = dynamic_cast<portableMachine *>(b);

                      if (!pa && !pb)
                          return false;
                      if (!pa)
                          return true;
                      if (!pb)
                          return false;

                      return pa->batteryHealth > pb->batteryHealth;
                  });
        std::cout << "Сортировка по батарее (убывание) завершена!" << std::endl;
        break;

    case 3: // Дисплей - возрастание
        std::sort(list.begin(), list.end(),
                  [](ComputingMachine *a, ComputingMachine *b)
                  {
                      portableMachine *pa = dynamic_cast<portableMachine *>(a);
                      portableMachine *pb = dynamic_cast<portableMachine *>(b);

                      if (!pa && !pb)
                          return false;
                      if (!pa)
                          return true;
                      if (!pb)
                          return false;

                      return pa->sizeDisplay < pb->sizeDisplay;
                  });
        std::cout << "Сортировка по размеру дисплея (возрастание) завершена!" << std::endl;
        break;

    case 4: // Дисплей - убывание
        std::sort(list.begin(), list.end(),
                  [](ComputingMachine *a, ComputingMachine *b)
                  {
                      portableMachine *pa = dynamic_cast<portableMachine *>(a);
                      portableMachine *pb = dynamic_cast<portableMachine *>(b);

                      if (!pa && !pb)
                          return false;
                      if (!pa)
                          return true;
                      if (!pb)
                          return false;

                      return pa->sizeDisplay > pb->sizeDisplay;
                  });
        std::cout << "Сортировка по размеру дисплея (убывание) завершена!" << std::endl;
        break;

    case 0:
        std::cout << "Сортировка пропущена!" << std::endl;
        break;

    default:
        std::cout << "Неверный выбор!" << std::endl;
    }
}

void portableMachine::info()
{
    ComputingMachine::info();
    std::cout << std::setw(20) << "Battery(mAh)" << std::setw(20) << "Size Display";
}

void portableMachine::setMenu()
{
    ComputingMachine::setMenu();
    ExpInput exp;
    int choice;
    int intValue;

    do
    {
        std::cout << "\n=== Редактирование параметров портативного устройства ===" << std::endl;
        std::cout << "1. Изменить емкость батареи (" << batteryHealth << " mAh)" << std::endl;
        std::cout << "2. Изменить размер дисплея (" << sizeDisplay << "\")" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выберите параметр для редактирования: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Введите новую емкость батареи (mAh): ";
            intValue = exp.isNumber(std::cin, 0, INT_MAX);
            setBatteryHealth(intValue);
            std::cout << "Емкость батареи изменена!" << std::endl;
            break;
        case 2:
            std::cout << "Введите новый размер дисплея (дюймы): ";
            intValue = exp.isNumber(std::cin, 0, INT_MAX);
            setSizeDisplay(intValue);
            std::cout << "Размер дисплея изменен!" << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

int portableMachine::getBatteryHealth() const
{
    return batteryHealth;
}
int portableMachine::getSizeDisplay() const { return sizeDisplay; }
void portableMachine::setBatteryHealth(int batteryHealth)
{
    this->batteryHealth = batteryHealth;
}
void portableMachine::setSizeDisplay(int sizeDisplay)
{
    this->sizeDisplay = sizeDisplay;
}

void portableMachine::writeToStream(std::ostream &os) const
{
    ComputingMachine::writeToStream(os);
    os << ';' << getBatteryHealth() << ';' << getSizeDisplay();
}

void portableMachine::readFromStream(std::istream &is)
{
    ComputingMachine::readFromStream(is);
    char delimiter = ';';
    int battery = 0;
    int sizeD = 0;
    if (!(is >> delimiter))
        return;
    if (!(is >> battery))
        return;
    if (!(is >> delimiter))
        return;
    if (!(is >>  sizeD))
        return;
    is.ignore();
    setBatteryHealth(battery);
    setSizeDisplay(sizeD);
}