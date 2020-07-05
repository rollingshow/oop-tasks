class Matrix
{
public:
    // переменные
    double **data;
    int size;

    // операторы суммирования, вычитания, умножения и деления
    Matrix operator+(const Matrix &first);
    Matrix operator-(const Matrix &first);
    Matrix operator*(const Matrix &first);
    Matrix operator/(const Matrix &first);

    // обратная матрица
    Matrix get_invert();
    // получить определитель
    int get_determinant();

    // конструктор пустой
    Matrix();
    // конструктор с массивом из указателей
    Matrix(double **, int);

private:
    // выборка подматрицы без столбца и строки
    void isolate(double **, double **, int, int, int);
    // транспонирование матрицы
    double **transponate(double **, int);
    // умножение на число
    double **multiply(double **, int, double);
    // рекурсивное вычисление определителя
    int determinant(double **, int);
    // поиск матрицы миноров со знаками
    void minor(double **, double **, int);
};