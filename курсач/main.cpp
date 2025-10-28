#include "header.h"
#include "header/EngineSystem.h"
#include "windows.h"
#include "header/Apartment.h"

int main()
{
  SetConsoleOutputCP(65001);
  SetConsoleCP(65001);

  EngineSystemBase system;
  User us;
  int again;
    system.load();
    us = system.login();
    system.menuUser(us);

  return 0;
}
