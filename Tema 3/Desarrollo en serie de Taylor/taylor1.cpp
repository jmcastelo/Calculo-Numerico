// Calculo numerico: Tema 3 / Desarrollo en serie de Taylor / taylor1.cpp

#include <iostream>
#include <cmath>

using namespace std;

// Funcion recursiva
float factorial(float n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int main()
{
    // Establecemos la precision y tipo de notacion numerica de cout
    cout.precision(6);
    cout.setf(ios::scientific);

    cout << "x\t\t" << "exp(-x)\t\t" << "Serie\t\t" << "Num. Terms." << endl;
    
    const float epsilon = 1.0e-7; // Precision

    // Calculamos la serie en el valor x
    for (float x = 0.0; x <= 15.0; x++)
    {
        int n = 0; // Numero del termino
        float termino = 1.0; // Termino inicial: n = 0
        float suma = 1.0;

        //cout << "n\t" << "pow(-x, n)\t" << "factorial(n)\t" << "termino" << endl;

        // Iteramos hasta que el error (termino de corte) sea menor que epsilon
        while (fabs(termino) > epsilon)
        {
            n++;
            termino = pow(-x, n) / factorial(n);
            suma += termino;
            
            //cout << n << "\t" << pow(-x, n) << "\t" << factorial(n) << "\t" << termino << endl;
        }

        cout << x << '\t' << exp(-x) << '\t' << suma << '\t' << n << endl;
    }

    return 0;
}