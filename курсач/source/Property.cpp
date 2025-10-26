#include "../header.h"
#include "../header/Property.h"
#include "../header/Apartment.h"
#include "../header/Garage.h"
#include "../header/House.h"
#include "../header/Land.h"
#include "../header/Storage.h"
#include "../header/Office.h"

double Property::getTotalArea() { return totalArea; }
int Property::getPrice() { return price; }
char *Property::getCity() { return city; }
char *Property::getRegion() { return region; }
char *Property::getStreet() { return street; }

void Property::setTotalArea(double area) { totalArea = area; }
void Property::setPrice(int pr) { price = pr; }
void Property::setCity(char *c) { strcpy_s(city, c); }
void Property::setRegion(char *r) { strcpy_s(region, r); }
void Property::setStreet(char *s) { strcpy_s(street, s); }

std::ostream &operator<<(std::ostream &os, Property &pr)
{
    os << std::left;
    os << std::setw(12) << pr.totalArea;
    os << std::setw(6) << pr.price;
    os << std::setw(10) << pr.city;
    os << std::setw(10) << pr.region;
    os << std::setw(10) << pr.street;
    return os;
}

void Property::info()
{
    std::cout << std::left;
    std::cout << "| " << std::setw(12) << "Площадь(м²)"
              << " | " << std::setw(6) << "Цена"
              << " | " << std::setw(10) << "Город"
              << " | " << std::setw(10) << "Область"
              << " | " << std::setw(10) << "Улица"
              << " |\n";
}

std::istream &operator>>(std::istream &is, Property &pr)
{
    std::cout << "Введите общую площадь: ";
    is >> pr.totalArea;
    std::cout << "Введите цену: ";
    is >> pr.price;
    std::cout << "Введите город: ";
    is.ignore();
    is.getline(pr.city, MAX_STR);
    std::cout << "Введите область: ";
    is.getline(pr.region, MAX_STR);
    std::cout << "Введите улицу: ";
    rewind(stdin);
    is.getline(pr.street, MAX_STR);
    return is;
}

// void savePropertyToFile(const char *type, Property *prop)
// {
//     std::ofstream file("files/property.txt", std::ios::app);
//     if (!file)
//     {
//         std::cerr << "Ошибка открытия файла для записи!" << std::endl;
//         return;
//     }
//     file << type << " " << prop->getPropertyId() << " " << prop->getOwnerId() << " ";
//     if (strcmp(type, "apartment") == 0)
//     {
//         Apartment *apt = dynamic_cast<Apartment *>(prop);
//         if (apt)
//             file << *apt;
//     }
//     else if (strcmp(type, "house") == 0)
//     {
//         House *house = dynamic_cast<House *>(prop);
//         if (house)
//             file << *house;
//     }
//     else if (strcmp(type, "garage") == 0)
//     {
//         Garage *garage = dynamic_cast<Garage *>(prop);
//         if (garage)
//             file << *garage;
//     }
//     else if (strcmp(type, "land") == 0)
//     {
//         Land *land = dynamic_cast<Land *>(prop);
//         if (land)
//             file << *land;
//     }
//     else if (strcmp(type, "office") == 0)
//     {
//         Office *office = dynamic_cast<Office *>(prop);
//         if (office)
//             file << *office;
//     }
//     else if (strcmp(type, "storage") == 0)
//     {
//         Storage *storage = dynamic_cast<Storage *>(prop);
//         if (storage)
//             file << *storage;
//     }
//     else
//     {
//         file << *prop;
//     }
//     file << std::endl;
//     file.close();
// }

void savePropertyToFile(const char *type, Property *prop)
{
    std::ofstream file("files/property.txt", std::ios::app);
    if (!file)
    {
        std::cerr << "Ошибка открытия файла для записи property.txt\n";
        return;
    }

    // Базовые поля
    file << type << ' '
         << prop->getPropertyId() << ' '
         << prop->getOwnerId() << ' '
         << std::fixed << std::setprecision(2) << prop->getTotalArea() << ' '
         << prop->getPrice() << ' '
         << prop->getCity() << ' '
         << prop->getRegion() << ' '
         << prop->getStreet() << ' ';

    if (std::string(type) == "apartment")
    {
        Apartment *a = dynamic_cast<Apartment *>(prop);
        if (a)
        {
            file << a->getCountRoom() << ' '
                 << a->getNumHouse() << ' '
                 << a->getNumApartment() << ' '
                 << a->getNumFloor() << ' '
                 << a->getMetro() << ' '
                 << (a->getRepair() ? 1 : 0);
        }
    }
    else if (std::string(type) == "house")
    {
        House *h = dynamic_cast<House *>(prop);
        if (h)
        {
            file << h->getNumHouse() << ' '
                 << h->getCountRoom() << ' '
                 << h->getFloorCount() << ' '
                 << h->getWaterSupply() << ' '
                 << h->getTypeHeating() << ' '
                 << h->getWallMaterial();
        }
    }
    else if (std::string(type) == "land")
    {
        Land *l = dynamic_cast<Land *>(prop);
        if (l)
        {
            file <<  l->getLandType();
        }
    }
    else if (std::string(type) == "garage")
    {
        Garage *g = dynamic_cast<Garage *>(prop);
        if (g)
        {
            // Garage наследует NonResidential, но в save кладём только свои поля (nonres поля лежат в базовом Property? у вас NonResidential хранит purpose/vent/fire)
            // Если у гаража есть поля from NonResidential, их нужно записать: purpose, vent, fire
            NonResidential *nr = dynamic_cast<NonResidential *>(g);
            if (nr)
            {
                
                file << nr->getPurpose() << ' '
                     << (nr->getHasVentilation() ? 1 : 0) << ' '
                     << (nr->getHasFireSafety() ? 1 : 0) << ' ';
            }
            file << (g->getHasElectricity() ? 1 : 0) << ' '
                 << (g->getHasHeating() ? 1 : 0);
        }
    }
    else if (std::string(type) == "storage")
    {
        Storage *s = dynamic_cast<Storage *>(prop);
        if (s)
        {
            // storage наследует Commercial -> Commercial содержит condition, metro, parking, secure
            Commercial *com = dynamic_cast<Commercial *>(s);
            if (com)
            {
                file <<  com->getCondition() << ' '
                     <<  com->getMetro() << ' '
                     << (com->getHasParking() ? 1 : 0) << ' '
                     << (com->getSecureSystem() ? 1 : 0) << ' ';
            }
            file << s->getTempRegime() << ' '
                 << s->getStorageVolume() << ' '
                 << (s->getTruckAccess() ? 1 : 0);
        }
    }
    else if (std::string(type) == "office")
    {
        Office *o = dynamic_cast<Office *>(prop);
        if (o)
        {
            Commercial *com = dynamic_cast<Commercial *>(o);
            if (com)
            {
                file << com->getCondition() << ' '
                     << com->getMetro() << ' '
                     << (com->getHasParking() ? 1 : 0) << ' '
                     << (com->getSecureSystem() ? 1 : 0) << ' ';
            }
            file << o->getTotalWorkplaces() << ' '
                 << o->getNumHouse() << ' '
                 << o->getCountPremises() << ' '
                 << o->getNumFloor();
        }
    }
    else if (std::string(type) == "commercial")
    {
        Commercial *com = dynamic_cast<Commercial *>(prop);
        if (com)
        {
            file << com->getCondition() << ' '
                 << com->getMetro() << ' '
                 << (com->getHasParking() ? 1 : 0) << ' '
                 << (com->getSecureSystem() ? 1 : 0);
        }
    }
    else
    {
    }

    file << '\n';
    file.close();
}

LinkedList<Property *> loadPropertyFromFile()
{
    LinkedList<Property *> properties;
    std::ifstream file("files/property.txt");
    if (!file)
    {
        std::cerr << "Файл files/property.txt не найден, верну пустой список\n";
        return properties;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        std::istringstream iss(line);
        std::string type;
        if (!(iss >> type))
            continue;

        int propID = -1;
        int ownerID = -1;
        if (!(iss >> propID >> ownerID))
            continue;

        double area = 0.0;
        int price = 0;
        std::string city, region, street;

        if (!(iss >> area >> price))
            continue;
        if (!(iss >> city >> region >>   street))
            continue;

        Property *prop = nullptr;

        if (type == "apartment")
        {
            int rooms, house, apartmentNum, floor;
            std::string metro;
            int rep;
            if (!(iss >> rooms >> house >> apartmentNum >> floor))
                continue;
            if (!(iss >> metro) >> rep)
                continue;

            Apartment *a = new Apartment();
            a->setTotalArea(area);
            a->setPrice(price);
            a->setCity(const_cast<char *>(city.c_str()));
            a->setRegion(const_cast<char *>(region.c_str()));
            a->setStreet(const_cast<char *>(street.c_str()));
            a->setOwnerId(ownerID);
            a->setPropertyId(propID);

            a->setCountRoom(rooms);
            a->setNumHouse(house);
            a->setNumApartment(apartmentNum);
            a->setNumFloor(floor);
            a->setMetro(const_cast<char *>(metro.c_str()));
            a->setRepair(rep != 0);

            prop = a;
        }
        else if (type == "house")
        {
            int numHouse, rooms, floors;
            std::string water, heating, material;
            if (!(iss >> numHouse >> rooms >> floors))
                continue;
            if (!(iss >> water >> heating >> material))
                continue;

            House *h = new House();
            h->setTotalArea(area);
            h->setPrice(price);
            h->setCity(const_cast<char *>(city.c_str()));
            h->setRegion(const_cast<char *>(region.c_str()));
            h->setStreet(const_cast<char *>(street.c_str()));
            h->setOwnerId(ownerID);
            h->setPropertyId(propID);

            h->setNumHouse(numHouse);
            h->setCountRoom(rooms);
            h->setFloorCount(floors);
            h->setWaterSupply(const_cast<char *>(water.c_str()));
            h->setTypeHeating(const_cast<char *>(heating.c_str()));
            h->setWallMaterial(const_cast<char *>(material.c_str()));

            prop = h;
        }
        else if (type == "land")
        {
            std::string landType;
            if (!(iss >> landType))
                continue;

            Land *l = new Land();
            l->setTotalArea(area);
            l->setPrice(price);
            l->setCity(const_cast<char *>(city.c_str()));
            l->setRegion(const_cast<char *>(region.c_str()));
            l->setStreet(const_cast<char *>(street.c_str()));
            l->setOwnerId(ownerID);
            l->setPropertyId(propID);

            l->setLandType(const_cast<char *>(landType.c_str()));
            prop = l;
        }
        else if (type == "garage")
        {
            // прочитать NonResidential поля + свои
            std::string purpose;
            int vent, fire;
            if (!(iss >> purpose) >> vent >> fire)
                continue;
            int electricity, heating;
            if (!(iss >> electricity >> heating))
                continue;

            Garage *g = new Garage();
            g->setTotalArea(area);
            g->setPrice(price);
            g->setCity(const_cast<char *>(city.c_str()));
            g->setRegion(const_cast<char *>(region.c_str()));
            g->setStreet(const_cast<char *>(street.c_str()));
            g->setOwnerId(ownerID);
            g->setPropertyId(propID);

            NonResidential *nr = dynamic_cast<NonResidential *>(g);
            if (nr)
            {
                nr->setPurpose(const_cast<char *>(purpose.c_str()));
                nr->setHasVentilation(vent != 0);
                nr->setHasFireSafety(fire != 0);
            }
            g->setHasElectricity(electricity != 0);
            g->setHasHeating(heating != 0);

            prop = g;
        }
        else if (type == "storage")
        {
            // сначала commercial поля
            std::string condition, metro;
            int parking, secure;
            if (!(iss >> condition >> metro >> parking >> secure))
                continue;
            std::string tempRegime;
            int volume, truck;
            if (!(iss >> tempRegime) >> volume >> truck)
                continue;

            Storage *s = new Storage();
            s->setTotalArea(area);
            s->setPrice(price);
            s->setCity(const_cast<char *>(city.c_str()));
            s->setRegion(const_cast<char *>(region.c_str()));
            s->setStreet(const_cast<char *>(street.c_str()));
            s->setOwnerId(ownerID);
            s->setPropertyId(propID);

            Commercial *com = dynamic_cast<Commercial *>(s);
            if (com)
            {
                com->setCondition(const_cast<char *>(condition.c_str()));
                com->setMetro(const_cast<char *>(metro.c_str()));
                com->setHasParking(parking != 0);
                com->setSecureSystem(secure != 0);
            }

            s->setTempRegime(const_cast<char *>(tempRegime.c_str()));
            s->setStorageVolume(volume);
            s->setTruckAccess(truck != 0);

            prop = s;
        }
        else if (type == "office")
        {
            std::string condition, metro;
            int parking, secure;
            if (!(iss >> condition >> metro >> parking >> secure))
                continue;
            int workplaces, numHouse, premises, floor;
            if (!(iss >> workplaces >> numHouse >> premises >> floor))
                continue;

            Office *o = new Office();
            o->setTotalArea(area);
            o->setPrice(price);
            o->setCity(const_cast<char *>(city.c_str()));
            o->setRegion(const_cast<char *>(region.c_str()));
            o->setStreet(const_cast<char *>(street.c_str()));
            o->setOwnerId(ownerID);
            o->setPropertyId(propID);

            Commercial *com = dynamic_cast<Commercial *>(o);
            if (com)
            {
                com->setCondition(const_cast<char *>(condition.c_str()));
                com->setMetro(const_cast<char *>(metro.c_str()));
                com->setHasParking(parking != 0);
                com->setSecureSystem(secure != 0);
            }

            o->setTotalWorkplaces(workplaces);
            o->setNumHouse(numHouse);
            o->setCountPremises(premises);
            o->setNumFloor(floor);

            prop = o;
        }
        else if (type == "commercial")
        {
            std::string condition, metro;
            int parking, secure;
            if (!(iss >> condition >> metro >> parking >> secure))
                continue;

            Commercial *c = new Commercial();
            c->setTotalArea(area);
            c->setPrice(price);
            c->setCity(const_cast<char *>(city.c_str()));
            c->setRegion(const_cast<char *>(region.c_str()));
            c->setStreet(const_cast<char *>(street.c_str()));
            c->setOwnerId(ownerID);
            c->setPropertyId(propID);

            c->setCondition(const_cast<char *>(condition.c_str()));
            c->setMetro(const_cast<char *>(metro.c_str()));
            c->setHasParking(parking != 0);
            c->setSecureSystem(secure != 0);

            prop = c;
        }
        else
        {
            continue;
        }

        if (prop)
        {
            properties.addToEnd(prop);
        }
    }

    file.close();
    return properties;
}

// LinkedList<Property *> loadPropertyFromFile()
// {
//     LinkedList<Property *> properties;
//     std::ifstream file("files/property.txt");
//     if (!file)
//     {
//         std::cerr << "Ошибка открытия файла для чтения!" << std::endl;
//     }
//     else
//     {
//         char line[MAX_STR];
//         while (file.getline(line, MAX_STR))
//         {
//             std::istringstream iss(line);
//             char type[MAX_STR];
//             iss >> type;

//             Property *prop = nullptr;

//             if (strcmp(type, "apartment") == 0)
//             {
//                 prop = new Apartment();
//             }
//             else if (strcmp(type, "house") == 0)
//             {
//                 prop = new House();
//             }
//             else if (strcmp(type, "land") == 0)
//             {
//                 prop = new Land();
//             }
//             else if (strcmp(type, "office") == 0)
//             {
//                 prop = new Office();
//             }
//             else if (strcmp(type, "storage") == 0)
//             {
//                 prop = new Storage();
//             }
//             else if (strcmp(type, "garage") == 0)
//             {
//                 prop = new Garage();
//             }

//             if (prop)
//             {
//                 int userID, propID;
//                 iss >> propID;
//                 iss >> userID;
//                 iss >> *prop;
//                 properties.addToEnd(prop);
//             }
//         }
//         file.close();
//     }
//     return properties;
// }