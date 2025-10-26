#include "header.h"
#include "header/EngineSystem.h"
#include "windows.h"

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    EngineSystem system;
    User* us = nullptr;
    system.load();

    while(us == nullptr)
    {
        us = system.login();
    }
    // Добавляем пользователей
    std::cout << "=== ДОБАВЛЕНИЕ ПОЛЬЗОВАТЕЛЕЙ ===\n";
    // system.addUser();
    // Добавляем недвижимость
    // system.addUser();

    //  system.addUser();
   system.addProperty(*us);
    // std::cout << "\n=== ПОИСК ===\n";
    // system.findByParam(1);
    //   std::cout << "\n=== ДОБАВЛЕНИЕ НЕДВИЖИМОСТИ ===\n";

    // Выводим всю недвижимость
    std::cout << "\n=== ВЫВОД ВСЕЙ НЕДВИЖИМОСТИ ===\n";
    system.printAllProperties();
    std::cout << "looool";
    return 0;
}

// Обработка исключений     ()_____+=_=+
// Минимум базовый класс ошибка Exp -> int kod, char mes[80] ------><.<> Exp_vvod char err[20] -----> readfie Exp_file Exp_contr
// коды ошибок добавь
// проверка целых плавующих ,,,функция введно ли число?  из потока, границы, вернуть число, для перегрузки ввода вывода,
// функция ,,,,,,,_,,,,, пишите на английском( либо на русском либо на английском все буквы, проверять), пока не введешь верно, программа не выполнится специфика по типу паспортта, дата платежа
// перегрузку вместо системной функции
// должна вернуть число что надо
/////////////////////@AddAccessAllowedAceEx();


// ppppppol
//#//-----------//#//
// llllllop