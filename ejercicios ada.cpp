/* Multiplicacion de numeros grandes
#include <iostream>
#include <vector>
using namespace std;

// Función para multiplicar dos números grandes usando divide y vencerás
vector<int> multiply(vector<int>& num1, vector<int>& num2) {
    int n = num1.size();
    int m = num2.size();

    vector<int> result(n + m, 0);

    // Multiplicación de los dígitos
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int product = num1[i] * num2[j];
            int sum = product + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    // Eliminamos los ceros iniciales
    while (!result.empty() && result.front() == 0) {
        result.erase(result.begin());
    }

    return result;
}

int main() {
    string str1, str2;
    cout << "Ingresa el primer número grande: ";
    cin >> str1;
    cout << "Ingresa el segundo número grande: ";
    cin >> str2;

    // Convertimos los números a vectores de dígitos / para agregar el valor entero resultante al final del vector
    vector<int> num1, num2;
    for (char c : str1) {
        num1.push_back(c - '0');
    }
    for (char c : str2) {
        num2.push_back(c - '0'); //convertimos el carácter numérico en su valor entero equivalente
    }

    // Multiplicamos los números
    vector<int> result = multiply(num1, num2);

    cout << "El resultado de la multiplicación es: ";
    for (int digit : result) {
        cout << digit;
    }
    cout << endl;

    return 0;
}*/


//Multiplicacion de matrices
#include<iostream>
using namespace std;

const int tam = 200; // tamaño máximo de tu matriz

void multi(int n, int a[tam][tam], int b[tam][tam], int result[tam][tam]) {
    if (n == 1) {
        result[0][0] = a[0][0] * b[0][0];
        return;
    }

    int matri1[tam][tam], matri2[tam][tam];

    // Divide las matrices en 4 sub-matrices y realiza las operaciones necesarias
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            int a11 = a[i][j];
            int a12 = a[i][j + n / 2];
            int a21 = a[i + n / 2][j];
            int a22 = a[i + n / 2][j + n / 2];

            int b11 = b[i][j];
            int b12 = b[i][j + n / 2];
            int b21 = b[i + n / 2][j];
            int b22 = b[i + n / 2][j + n / 2];

            // Calcula los valores intermedios
            int m1 = (a11 + a22) * (b11 + b22);
            int m2 = (a21 + a22) * b11;
            int m3 = a11 * (b12 - b22);
            int m4 = a22 * (b21 - b11);
            int m5 = (a11 + a12) * b22;
            int m6 = (a21 - a11) * (b11 + b12);
            int m7 = (a12 - a22) * (b21 + b22);

            // Calcula los valores de la matriz resultante
            result[i][j] = m1 + m4 - m5 + m7;
            result[i][j + n / 2] = m3 + m5;
            result[i + n / 2][j] = m2 + m4;
            result[i + n / 2][j + n / 2] = m1 - m2 + m3 + m6;
        }
    }
}

int main() {
    int a[tam][tam] = {
        {1, 2, 3, 4, 5, 6},
        {9, 10, 11, 12, 13, 14},
        {17, 18, 19, 20, 21, 22},
        {25, 26, 27, 28, 29, 30},
        {33, 34, 35, 36, 37, 38},
        {41, 42, 43, 44, 45, 46}
    };

    int b[tam][tam] = {
        {65, 66, 67, 68, 69, 70},
        {73, 74, 75, 76, 77, 78},
        {81, 82, 83, 84, 85, 86},
        {89, 90, 91, 92, 93, 94},
        {97, 98, 99, 100, 101, 102},
        {105, 106, 107, 108, 109, 110}
    };

    int c[tam][tam];

    multi(6, a, b, c);

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }

    return 0;
}