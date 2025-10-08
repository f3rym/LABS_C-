#include "intersectionArrays.h"

int enterInfoAboutArray(int i)
{
    int size;
    std::cout << "Введите длину " << i << " массива: ";
    std::cin >> size;
    return size;
}

intersectionArrays::intersectionArrays()
{
    array = nullptr;
    size = 0;
}
intersectionArrays::intersectionArrays(int size)
{
    array = new int[size]();
    this->size = size;
}
intersectionArrays::intersectionArrays(const intersectionArrays &other)
{
    this->size = other.size;
    this->array = new int[this->size];
    for (int i = 0; i < this->size; i++)
        this->array[i] = other.array[i];
}

void intersectionArrays::enterElements()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Введите значение [" << i + 1 << "] : ";
        std::cin >> array[i];
    }
}

// intersectionArrays intersectionArrays::findIntersection(intersectionArrays& m, intersectionArrays& n)
//{
//     int res = 0;
//     intersectionArrays* smaller = (m.size <= n.size) ? &m : &n;
//     intersectionArrays* larger = (m.size > n.size) ? &m : &n;
//     int* temp;
//     temp = new int[smaller->size];
//     for (int i = 0; i < smaller->size; i++)
//         for (int j = 0; j < larger->size; j++)
//         {
//             bool isUniq = true;
//             if (smaller->array[i] == larger->array[j])
//             {
//                 for (int k = 0; k < res; k++)
//                 {
//                     if (smaller->array[i] == temp[k])
//                     {
//                         isUniq = false;
//                         break;
//                     }
//                 }
//                 if (isUniq)
//                 {
//                     temp[res] = smaller->array[i];
//                     res++;
//                 }
//             }
//         }
//     intersectionArrays result(res);
//     for (int i = 0; i < res; i++)
//         result.array[i] = temp[i];
//     delete[] temp;
//     return result;
// }
intersectionArrays intersectionArrays::operator=(const intersectionArrays &other)
{
    if(this != &other)
    {
        delete[] array;
        size = other.size;
        array = new int[size];
        for (int i = 0; i < other.size; i++)
        {
            array[i] = other.array[i];
        }
    }
    return *this;
}


intersectionArrays intersectionArrays::operator+(const intersectionArrays &other)
{
    int sizeFinal = this->size + other.size;
    intersectionArrays result(sizeFinal);
    for (int i = 0; i < this->size; i++)
    {
        result.array[i] = this->array[i];
    }
    for (int i = 0; i < other.size; i++)
    {
        result.array[i + this->size] = other.array[i];
    }
    return result;
}

intersectionArrays intersectionArrays::findIntersection(intersectionArrays &n)
{
    int res = 0;
    intersectionArrays smaller = (this->size <= n.size) ? *this : n;
    intersectionArrays larger = (this->size > n.size) ? *this : n;
    intersectionArrays result(smaller.size);
    for (int i = 0; i < smaller.size; i++)
        for (int j = 0; j < larger.size; j++)
        {
            bool isUniq = true;
            if (smaller.array[i] == larger.array[j])
            {
                for (int k = 0; k < res; k++)
                {
                    if (smaller.array[i] == result.array[k])
                    {
                        isUniq = false;
                        break;
                    }
                }
                if (isUniq)
                {
                    result.array[res] = smaller.array[i];
                    res++;
                }
            }
        }
    return result;
}

void intersectionArrays::printArray()
{

    std::cout << "Array [ ";
    for (int i = 0; i < size; i++)
    {
        if (array[i] != 0)
        {
            std::cout << array[i] << " ";
        }
    }
    std::cout << "]\n";
}

intersectionArrays::~intersectionArrays()
{
    delete[] array;
}

void menu()
{
    int var;
    intersectionArrays array1;
    intersectionArrays array2;
    intersectionArrays array3;

    while (1)
    {

        std::cout << "-------------------" << std::endl;
        std::cout << "1. Заполнить первый массив" << std::endl;
        std::cout << "2. Скопировать 1 массив во 2" << std::endl;
        std::cout << "3. Заполнить второй массив" << std::endl;
        std::cout << "4. Вывести 1 массив" << std::endl;
        std::cout << "5. Вывести 2 массив" << std::endl;
        std::cout << "6. Найти пересечение" << std::endl;
        std::cout << "7. Сложение массивов" << std::endl;
        std::cout << "8. Выйти" << std::endl;
        std::cout << " : ";
        std::cin >> var;
        if (var == 1)
        {
            int size1;
            size1 = enterInfoAboutArray(1);
            array1 = intersectionArrays(size1);
            array1.enterElements();
        }
        else if (var == 2)
        {
                array2 = array1;
                std::cout << "Массив скопирован успешно." << std::endl;
        }
        else if (var == 3)
        {
            int size2;
            size2 = enterInfoAboutArray(2);
            array2 = intersectionArrays(size2);
            array2.enterElements();
        }
        else if (var == 4)
        {
                array1.printArray();
        }
        else if (var == 5)
        {
                array2.printArray();
        }
        else if (var == 6)
        {
                intersectionArrays res = array2.findIntersection(array1);
                res.printArray();
        }
        else if (var == 7)
        {
            array3 = array1 + array2;
            std::cout << "Новый массив: " << std::endl;
            array3.printArray();
        }
        else if (var == 8)
        {
            std::cout << "Выйти." << std::endl;
            break;
        }
        else
            std::cout << "Команда не найдена, попробуй снова." << std::endl;
    }
}

int againProg()
{
    int again;
    std::cout << "\nСнова? \033[32mДа - 1\033[0m. \033[31mНет - 0 \033[0m:\t";
    while (1)
    {
        std::cin >> again;
        if ((again != 0 && again != 1))
        {
            std::cout << "\033[31mОшибка. Переход к завершению...\033[0m";
            rewind(stdin);
            again = 0;
            return again;
        }
        else
            break;
    }
    return again;
}