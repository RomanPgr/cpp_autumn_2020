#include "mymatrix.h"

MyMatrixLine::MyMatrixLine(int* data, unsigned int columns) :
data(data),
length(columns){
}

int& MyMatrixLine::operator[](unsigned int index){
    if (index >= length){
        throw std::out_of_range("columns in matrix: " + std::to_string(length) + ", you ask " + std::to_string(index));
    }
    return data[index];
}

MyMatrixLine& MyMatrixLine::operator*(int mult){
    for (unsigned int i = 0; i < length; i++){
        data[i] *= mult;
    }
    return *this;
}

MyMatrixLine& MyMatrixLine::operator*(double mult){
    for (unsigned int i = 0; i < length; i++){
        data[i] = (int)(data[i] * mult);
    }
    return *this;
}

MyMatrixLine& MyMatrixLine::operator*=(int mult){
    for (unsigned int i = 0; i < length; i++){
        data[i] *= mult;
    }
    return *this;
}

MyMatrixLine& MyMatrixLine::operator*=(double mult){
    for (unsigned int i = 0; i < length; i++){
        data[i] = (int)(data[i] * mult);
    }
    return *this;
}

MyMatrixLine& MyMatrixLine::operator+(){
    return *this;
}

MyMatrixLine& MyMatrixLine::operator-(){
    for (unsigned int i = 0; i < length; i++){
        data[i] *= -1;
    }
    return *this;
}

MyMatrixLine& MyMatrixLine::operator-=(int sub){
    for (unsigned int i = 0; i < length; i++){
        data[i] -= sub;
    }
    return *this;
}
MyMatrixLine& MyMatrixLine::operator+=(int add){
    for (unsigned int i = 0; i < length; i++){
        data[i] += add;
    }
    return *this;
}
MyMatrixLine& MyMatrixLine::operator-=(const MyMatrixLine& sub){
    if (length != sub.length){
        throw std::logic_error("Mismatch in the number of columns");
    }
    for (unsigned int i = 0; i < length; i++){
        data[i] -= sub.data[i];
    }
    return *this;
}

MyMatrixLine& MyMatrixLine::operator-(const MyMatrixLine& sub){
    *this -= sub;
    return *this;
}

MyMatrixLine& MyMatrixLine::operator+(const MyMatrixLine& add){
    *this += add;
    return *this;
}

MyMatrixLine& MyMatrixLine::operator+=(const MyMatrixLine& add){
    if (length != add.length){
        throw std::logic_error("Mismatch in the number of columns");
    }
    for (unsigned int i = 0; i < length; i++){
        data[i] += add.data[i];
    }
    return *this;
}

MyMatrixLine::~MyMatrixLine() = default;














MyMatrix::MyMatrix(unsigned int rows, unsigned int columns) :
    rows(rows),
    columns(columns),
    proxy(nullptr){
    data = new int[rows * columns];
}

unsigned int MyMatrix::GetNumberRows(){
    return rows;
}

unsigned int MyMatrix::GetNumberColumns(){
    return columns;
}

MyMatrixLine& MyMatrix::operator[](unsigned int index){
    if (index >= rows){
        throw std::out_of_range("rows in matrix: " + std::to_string(rows) + ", you ask " + std::to_string(index));
    }
    delete proxy;
    proxy = new MyMatrixLine(data + (index * columns), columns);
    return *proxy;
}

MyMatrix MyMatrix::operator*(int mult) const{
    MyMatrix result(rows, columns);
    for (unsigned int i = 0; i < rows * columns; i++){
        result.data[i] = this->data[i] * mult;
    }
    return result;
}

MyMatrix MyMatrix::operator*(double mult) const{
    MyMatrix result(rows, columns);
    for (unsigned int i = 0; i < rows * columns; i++){
        result.data[i] = (int)(this->data[i] * mult);
    }
    return result;
}

MyMatrix& MyMatrix::operator*=(int mult){
    for (unsigned int i = 0; i < rows * columns; i++){
        this->data[i] *= mult;
    }
    return *this;
}

MyMatrix& MyMatrix::operator*=(double mult){
    for (unsigned int i = 0; i < rows * columns; i++){
        this->data[i] = (int)(this->data[i] * mult);
    }
    return *this;
}

MyMatrix& MyMatrix::operator-=(int sub){
    for (unsigned int i = 0; i < rows * columns; i++){
        this->data[i] -= sub;
    }
    return *this;
}

MyMatrix& MyMatrix::operator+=(int add){
    for (unsigned int i = 0; i < rows * columns; i++){
        this->data[i] += add;
    }
    return *this;
}

MyMatrix MyMatrix::operator-() const{
    MyMatrix result(rows, columns);
    for (unsigned int i = 0; i < rows * columns; i++){
        result.data[i] = -this->data[i];
    }
    return result;
}

MyMatrix MyMatrix::operator+(const MyMatrix& add) const{
    if (rows != add.rows){
        throw std::logic_error("Mismatch in the number of rows");
    }
    if (columns != add.columns){
        throw std::logic_error("Mismatch in the number of columns");
    }
    MyMatrix result(rows, columns);
    for (unsigned int i = 0; i < rows * columns; i++){
        result.data[i] = this->data[i] + add.data[i];
    }
    return result;
}

MyMatrix& MyMatrix::operator-=(const MyMatrix& sub){
    if (rows != sub.rows){
        throw std::logic_error("Mismatch in the number of rows");
    }
    if (columns != sub.columns){
        throw std::logic_error("Mismatch in the number of columns");
    }
    for (unsigned int i = 0; i < rows * columns; i++){
        this->data[i] -= sub.data[i];
    }
    return *this;
}
MyMatrix& MyMatrix::operator+=(const MyMatrix& add){
    if (rows != add.rows){
        throw std::logic_error("Mismatch in the number of rows");
    }
    if (columns != add.columns){
        throw std::logic_error("Mismatch in the number of columns");
    }
    for (unsigned int i = 0; i < rows * columns; i++){
        this->data[i] += add.data[i];
    }
    return *this;
}

MyMatrix& MyMatrix::operator+(){
    return *this;
}

MyMatrix MyMatrix::operator-(const MyMatrix& sub) const{
    if (rows != sub.rows){
        throw std::logic_error("Mismatch in the number of rows");
    }
    if (columns != sub.columns){
        throw std::logic_error("Mismatch in the number of columns");
    }
    MyMatrix result(rows, columns);
    for (unsigned int i = 0; i < rows * columns; i++){
        result.data[i] = this->data[i] - sub.data[i];
    }
    return result;
}

MyMatrix::~MyMatrix(){
    delete[] data;
    delete proxy;
}

MyMatrix& MyMatrix::SetZero(){
    for (unsigned int i = 0; i < rows * columns; i++){
        data[i] = 0;
    }
    return *this;
}

bool MyMatrix::operator==(const MyMatrix& matr) const{
    if (rows != matr.rows || columns != matr.columns){
        return false;
    }
    for (unsigned int i = 0; i < rows * columns; i++){
        if (data[i] != matr.data[i]){
            return false;
        }
    }
    return true;
}

MyMatrix::MyMatrix(const MyMatrix& m) :
rows(m.rows),
columns(m.columns),
proxy(nullptr){
    data = new int[rows * columns];
    memcpy(data, m.data, rows * columns * sizeof(int));
}


MyMatrix& MyMatrix::operator=(const MyMatrix& matr){
    if (this == &matr){
        return *this;
    }
    delete[] data;
    delete proxy;
    rows = matr.rows;
    columns = matr.columns;
    proxy = nullptr;
    data = new int[rows * columns];
    memcpy(data, matr.data, rows * columns * sizeof(int));
    return *this;
}
