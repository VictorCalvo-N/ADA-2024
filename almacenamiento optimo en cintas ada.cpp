// almacenamiento optimo en cintas
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void almacenarcintas(vector<int>& valores) {
	sort(valores.begin(), valores.end());//ordenar los archivos

    int n = valores.size();
    double TMR = 0.0;
    int acumuladortam = 0;

	for (int i = 0; i < n; i++) {//calcular el TMR
        acumuladortam += valores[i];
		TMR += acumuladortam;//sumar el acumuladortam de los tamaños de los archivos
    }

	TMR /= n;//dividir el TMR entre la cantidad de archivos

    cout << "el TMR minimo es: " << TMR << endl;
    cout << "los archivos estan en orden: ";
    for (int i = 0; i < n; i++) {
        cout << valores[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> valores = { 5,10,3 };

    almacenarcintas(valores);

    return 0;
}
