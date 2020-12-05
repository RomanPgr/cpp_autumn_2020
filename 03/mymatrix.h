#ifndef MYMATRIX_H
#define MYMATRIX_H
#include <cstring>
#include <iostream>


class MyMatrixLine{
public:
    MyMatrixLine(int* data, unsigned int columns);
    int& operator[](unsigned int index);
    MyMatrixLine& operator*(int mult);
    MyMatrixLine& operator*(double mult);
    MyMatrixLine& operator*=(int mult);
    MyMatrixLine& operator*=(double mult);
    MyMatrixLine& operator+();
    MyMatrixLine& operator-();
    MyMatrixLine& operator-=(int sub);
    MyMatrixLine& operator+=(int add);
    MyMatrixLine& operator-=(const MyMatrixLine& sub);
    MyMatrixLine& operator+=(const MyMatrixLine& add);
    MyMatrixLine& operator-(const MyMatrixLine& sub);
    MyMatrixLine& operator+(const MyMatrixLine& add);
    ~MyMatrixLine();

private:
    int* data;
    unsigned int length;
};


class MyMatrix{
public:
    MyMatrix(unsigned int rows, unsigned int columns);
    MyMatrix(const MyMatrix&);
    ~MyMatrix();

    unsigned int GetNumberRows();
    unsigned int GetNumberColumns();
    MyMatrix& SetZero();
    
    MyMatrixLine& operator[](unsigned int index);
    MyMatrix& operator+();
    MyMatrix& operator+=(int add);
    MyMatrix& operator+=(const MyMatrix& add);

    MyMatrix& operator-=(int sub);
    MyMatrix& operator-=(const MyMatrix& sub);

    MyMatrix& operator*=(int mult);
    MyMatrix& operator*=(double mult);

    [[nodiscard]] MyMatrix operator*(int mult) const;
    [[nodiscard]] MyMatrix operator*(double mult) const;

    [[nodiscard]] MyMatrix operator+(const MyMatrix& sub) const;
    [[nodiscard]] MyMatrix operator-(const MyMatrix& add) const;
    [[nodiscard]] MyMatrix operator-() const;

    MyMatrix& operator=(const MyMatrix& matr);
    bool operator==(const MyMatrix& matr) const;
    
    friend std::ostream& operator<<(std::ostream& stream, const MyMatrix& matrix){
        for (unsigned int i = 0; i < matrix.rows; i++){
            for (unsigned int j = 0; j < matrix.columns; j++){
                stream << matrix.data[i * matrix.columns + j] << '\t';
            }
            stream << '\n';
        }
        stream.flush();
        return stream;
    }

    /*[[nodiscard("new inside")]]*/ friend MyMatrix operator*(int mul, const MyMatrix& matrix){
        MyMatrix result(matrix.rows, matrix.columns);
        for (unsigned int i = 0; i < matrix.rows * matrix.columns; i++){
                result.data[i] = matrix.data[i] * mul;
        }
        return result;
    }
    

private:
    unsigned int rows;
    unsigned int columns;
    MyMatrixLine* proxy;
    int* data;
};

#endif
