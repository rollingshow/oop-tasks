class String
{
public:
    // возврат строки определенной длины слева
    String left(int range);

    // возврат строки определенной длины справа
    String right(int range);

    // возврат строки с положения до конца
    String mid(int start);

    // возврат строки с положения определенной длины
    String mid(int start, int range);

    // добавление строки
    String concat(String input);

    // конструктор пустой
    String();

    // конструктор с данными
    String(const char *input);

    // возврат длины строки
    int length();

    // перевод строки в массив символов
    char *to_char();

private:
    // длина и массив символов строки
    int len = 0;
    char *array;

    // установка знака окончания
    void eol();

    // рассчёт длины строки
    int get_len(const char *input);
};