#include "header.h"
#include "header/EngineSystem.h"



// User *loginMenu(EngineSystem &system)
// {
//     int choice = 0;
//     do
//     {
//         std::cout << "\n=== ВХОД В СИСТЕМУ ===\n";
//         std::cout << "1. Войти\n";
//         std::cout << "2. Зарегистрироваться\n";
//         std::cout << "3. Выход\n";
//         std::cout << "Выберите действие: ";
//         std::cin >> choice;
//         std::cin.ignore();

//         switch (choice)
//         {
//         case 1:
//         {
//             if (system.getUsers().empty())
//             {
//                 std::cout << "Нет зарегистрированных пользователей. Сначала зарегистрируйтесь.\n";
//                 break;
//             }

//             int id;
//             std::cout << "Введите ваш ID: ";
//             std::cin >> id;
//             std::cin.ignore();

//             for (auto user : system.getUsers())
//             {
//                 if (user->getId() == id)
//                 {
//                     std::cout << "Добро пожаловать, " << user->getName() << "!\n";
//                     return user; // возвращаем вошедшего пользователя
//                 }
//             }
//             std::cout << "Пользователь с таким ID не найден.\n";
//             break;
//         }
//         case 2: // Регистрация
//         {
//             RegUser *newUser = new RegUser();
//             std::cin >> *newUser;    // ввод данных
//             system.addUser(newUser); // добавляем в систему
//             std::cout << "Регистрация успешна! Ваш ID: " << newUser->getId() << "\n";
//             return newUser; // сразу заходим под новым пользователем
//         }
//         case 3:
//             std::cout << "Выход из программы.\n";
//             return nullptr;
//         default:
//             std::cout << "Неверный выбор, попробуйте снова.\n";
//         }

//     } while (true);
// }


