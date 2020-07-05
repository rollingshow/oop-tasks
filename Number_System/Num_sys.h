class NumberSystem
{
public:
    // операторы суммирования, вычитания, умножения и деления
    NumberSystem operator+(const NumberSystem &right);
    NumberSystem operator-(const NumberSystem &right);
    NumberSystem operator*(const NumberSystem &right);
    NumberSystem operator/(const NumberSystem &right);

    // конструкторы
    NumberSystem();
    NumberSystem(int, int);

    // установка значения (в с/с)
    void set_value(const char*);
    // установка значения (в десятичной с/с)
    void set_decimal(int);
    // смена системы счисления
    void set_system(int);

    // получение значения (в десятичнй с/с)
    int get_decimal();
    // получение значения (в с/с)
    char* get_value();
    // получение системы счисления
    int get_system();
private:
    int dec_value, num_sys;

    int sys_size;
    char* sys_value;

    // перевод в с/с
    char* to_sys(int);
    // перевод в десятичую с/с
    int to_dec(int);
};