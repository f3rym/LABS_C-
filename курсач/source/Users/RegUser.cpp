#include "../../header.h"
#include "../../header/Users/RegUser.h"

int RegUser::getBalance() const { return balance; }

void RegUser::setBalance(int newBalance) { balance = newBalance; }

void RegUser::addBalance(int amount) { balance += amount; }

void RegUser::subtractBalance(int amount) { balance -= amount; }

std::ostream &operator<<(std::ostream &os, RegUser &user)
{
    User &baseUser = user;
    os << baseUser;
    os << std::setw(15) << user.getBalance();
    return os;
}

std::istream &operator>>(std::istream &is, RegUser &user)
{
    User &baseUser = user;
    is >> baseUser;

    int balance;
    std::cout << "Введите баланс: ";
    is >> balance;

    user.setBalance(balance);
    return is;
}