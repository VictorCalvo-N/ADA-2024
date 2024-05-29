#include <iostream>
#include <vector>
#include <algorithm> // para sort
using namespace std;

vector<float> Mochila(int m, const vector<int>& candidatosp, const vector<int>& beneficio) {
    int n = candidatosp.size();
    vector<float> solution(n, 0.0); // solución con ceros
    vector<pair<float, int>> prop(n); // beneficio/peso

    for (int i = 0; i < n; ++i) {
        prop[i] = make_pair(static_cast<float>(beneficio[i]) / candidatosp[i], i);
    }

    // ordenamos las proporciones en orden descendente
    sort(prop.rbegin(), prop.rend());

    for (const auto& item : prop) {
        int ind = item.second;
        if (candidatosp[ind] <= m) {
            solution[ind] = 1.0; // ponemos todo el elemento a la mochila
            m -= candidatosp[ind];
        }
        else {
            solution[ind] = static_cast<float>(m) / candidatosp[ind]; // ponemos una parte del elemento
            break; // no ponemos más elementos
        }
    }

    return solution;
}

int main() {
    vector<int> candidatosp = { 18, 15, 10, 8, 12, 13 };
    vector<int> beneficio = { 25, 24, 15, 30, 18, 17 };
    int capacidad_mochila = 60;

    vector<float> solucion = Mochila(capacidad_mochila, candidatosp, beneficio);

    cout << "Solución:";
    for (float frac : solucion) {
        cout << " " << frac;
    }
    cout << endl;

    return 0;
}
