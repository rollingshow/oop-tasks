class Matrix{
    public:
        // операторы суммирования, вычитания, умножения и деления
        Matrix operator+(const Matrix& first);
        Matrix operator-(const Matrix& first);
        Matrix operator*(const Matrix& first);
        Matrix operator/(const Matrix& first);

        // обратная матрица
        Matrix get_invert();
        // получить определитель
        int get_determ();

        // конструктор пустой
        Matrix();
        // конструктор с массивом
        Matrix(const double** array);
    private:
        

};