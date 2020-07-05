#include <iostream>
#include <regex>
#include <string>
#include <math.h>

#include "Num_sys.h"

NumberSystem::NumberSystem()
{
    num_sys = 2;
    dec_value = 0;

    sys_value = new char[2];
    sys_value[0] = '0';
    sys_value[1] = '\0';

    sys_size = 1;
}

NumberSystem::~NumberSystem()
{

    delete[] sys_value;
}

NumberSystem::NumberSystem(int decimal, int system)
{
    if (system < 2 || system > 9)
    {
        std::cerr << "Wrong numeric system in NumberSystem::NumberSystem()";
        exit(-2);
    }
    num_sys = system;
    dec_value = decimal;

    set_decimal(decimal);
}

void NumberSystem::set_value(const char *value)
{
    std::string pattern_str = "^[+-]?[0-" + std::to_string(num_sys - 1) + "]+$";
    std::regex pattern_reg(pattern_str);
    if (!std::regex_match(value, pattern_reg))
    {
        std::cerr << "Wrong numeric system in NumberSystem::set_value()";
        exit(-1);
    }

    // Учёт знака при вводе
    int sign_space = 0;
    if (value[0] == '+' || value[0] == '-')
    {
        sign_space = 1;
        sign = value[0];
    }
    else
    {
        sign = '+';
    }

    // Считаем длину строки с числом в с/с
    int length = 0;
    while (value[length] != '\0')
    {
        length++;
    }
    length -= sign_space;

    // Выделяем память и обнуляем десятичное значение
    dec_value = 0;
    char *array = new char[length + 1];

    // Заполняем массив и переводим в десятичное число
    for (int i = 0 + sign_space; i < length + sign_space; i++)
    {
        array[i - sign_space] = value[i];
        dec_value += pow(num_sys, length - i - 1) * (int)(value[i] - 48);
    }
    array[length] = '\0';

    // Очищаем память и сохраняем
    // delete[] sys_value;

    sys_value = array;
    sys_size = length;
}

void NumberSystem::set_decimal(int decimal)
{
    int over = 1;
    int size = 0;
    int i = 0;

    // Устанавливаем знак
    if (decimal < 0)
    {
        sign = '-';
        decimal *= -1;
    }
    else
    {
        sign = '+';
    }

    char *array;
    if (decimal != 0)
    {
        // Рассчитываем размер массива и создаём
        while (over < decimal)
        {
            over *= num_sys;
            size++;
        }
        array = new char[size + 1];

        // Заполняем массив
        while (decimal > 0)
        {
            array[size - i - 1] = (decimal % num_sys + 48);

            decimal /= num_sys;
            i++;
        }
    }
    else
    {
        size = 1;
        array = new char[size + 1];
        array[0] = '0';
    }
    array[size] = '\0';

    sys_value = array;
    sys_size = size;
}

void NumberSystem::set_system(int system)
{
    if (system < 2 || system > 9)
    {
        std::cerr << "Wrong numeric system in NumberSystem::set_system()";
        exit(-3);
    }
    num_sys = system;

    set_decimal(dec_value);
}

int NumberSystem::get_decimal()
{
    return dec_value;
}

char *NumberSystem::get_value()
{
    // set_decimal(dec_value);

    char *result = new char[sys_size + 2];
    result[0] = (char)sign;
    for (int i = 1; i < sys_size + 1; i++)
    {
        result[i] = sys_value[i - 1];
    }
    result[sys_size + 1] = '\0';

    return result;
}

int NumberSystem::get_system()
{
    return num_sys;
}

NumberSystem NumberSystem::operator+(const NumberSystem &right)
{
    int new_dec = dec_value + right.dec_value;
    NumberSystem result(new_dec, num_sys);

    // Возврат результата
    return result;
}

NumberSystem NumberSystem::operator-(const NumberSystem &right)
{
    int new_dec = dec_value - right.dec_value;
    NumberSystem result(new_dec, num_sys);

    // Возврат результата
    return result;
}

NumberSystem NumberSystem::operator*(const NumberSystem &right)
{
    int new_dec = dec_value * right.dec_value;
    NumberSystem result(new_dec, num_sys);

    // Возврат результата
    return result;
}

NumberSystem NumberSystem::operator/(const NumberSystem &right)
{
    int new_dec = dec_value / right.dec_value;
    NumberSystem result(new_dec, num_sys);

    // Возврат результата
    return result;
}