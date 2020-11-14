#include <iostream>
#include "mymatrix.h"

int main(){
    unsigned int rows = 5;
    unsigned int columns = 5;
    MyMatrix a(rows, columns), b(rows, columns);
    a.SetZero();
    b.SetZero();
    a[3][4] = 10;
    b[3][4] = 20;
    

    std::cout << (a + b)[3][4] << "\n\n"; 
    std::cout << a << "\n";

    std::cout << (a == b) << "\n";
    a.SetZero();
    b.SetZero();
    std::cout << (a == b) << "\n";

    for (unsigned int i = 0; i < rows; i++){
        for (unsigned int j = 0; j < columns; j++){
            a[i][j] = 10;
        }
    }
    b += 10;
    std::cout << (a == b) << "\n\n";
    std::cout << (a + b) << '\n';

    MyMatrix c = a;
    auto d(7 * c * 3);
    std::cout << a << '\n' << '\n' << c << '\n' << (2 * c) << '\n' << d << '\n';

    a *= 8;
    b = -b;
    std::cout << a << '\n' << b << '\n' << (a + b) <<'\n';

    a[1] * 0.5;
    b[3] + a[2];
    b[4] *= 3;
    std::cout << a << '\n' << b << '\n' << (a + b) << '\n';

    std::cout << a.GetNumberColumns() << 'X' << a.GetNumberRows() << std::endl;
}
