#include <iostream>
#include <regex>
#include <string>

#include "Num_sys.h"

NumberSystem::NumberSystem(){
    num_sys = 2;
    dec_value = 0;

    sys_value = new char[2];
    sys_value[0] = '0';
    sys_value[1] = '\0';

    sys_size = 1;
}

NumberSystem::NumberSystem(int decimal, int system){
    num_sys = system;
    dec_value = decimal;
    set_decimal(decimal);

    std::cout << sys_value;
}

void NumberSystem::set_value(const char* value){
    std::string pattern_str = "^[0-" + std::to_string(num_sys-1) + "]+$";
    std::regex pattern_reg(pattern_str);

    if(!std::regex_match(value, pattern_reg)){
        std::cerr << "Wrong numeric system in NumberSystem::set_value()";
        exit(-1);
    }

    
    
}

void NumberSystem::set_decimal(int decimal){
    int over = 1;
    int size = 0;
    int i = 0;

    // Рассчтиываем размер массива и создаём
    while(over < decimal){
        over *= num_sys;
        size++;
    }
    char* array = new char[size+1];

    // Заполняем массив
    while(decimal > 0)
    {
        array[size-i-1] = (decimal % num_sys + 48);
        
        decimal /= num_sys;
        i++;
    }
    array[size] = '\0';

    // Очищаем память и сохраняем
    delete[] sys_value;
    sys_value = array;
    sys_size = size;
}