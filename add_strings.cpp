#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class add_strings
{

public:
    // Se declaran las variables
    string result = "";
    int zi1 = 0;
    int zi2 = 0;
    // Se crea la función addStrings
    string addStrings(string num1, string num2)
    {
        // Se declaran las variables
        int pos = 0;
        int j = num2.size() - 1;
        int i = num1.size() - 1;

        // Se crea un bucle while que se ejecutará mientras i sea mayor o igual a 0 o j sea mayor o igual a 0
        while (i >= 0 || j >= 0)
        {
            // Se declaran las variables x y y
            int x = i >= 0 ? num1[i] - '0' : 0; // Se convierte el valor de num1 en un entero
            int y = j >= 0 ? num2[j] - '0' : 0; // Se convierte el valor de num2 en un entero

            // Se suman los valores de x y y multiplicados por 10 elevado a la posición
            zi1 += x * pow(10, pos);
            zi2 += y * pow(10, pos);

            // Se decrementan los valores de i, j e incrementa pos
            i--;
            j--;
            pos++;
        }
        // Se convierte el resultado en un string
        result = to_string(zi1 + zi2);

        // Se retorna el resultado
        return result;
    };
};

int main(int argc, char *argv[]) // argc es el número de argumentos que se pasan y argv es un array de punteros a los argumentos
{
    // Se comprueba que se pasen 3 argumentos
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " <num1> <num2>" << endl; // imprime el mensaje de error
        return 1;
    }

    // Se declaran las variables num1 y num2
    string num1 = argv[1];
    string num2 = argv[2];

    // Se crea un objeto de la clase add_strings
    add_strings add;
    cout << "Addition: " << add.addStrings(num1, num2) << endl; // Se llama a la función addStrings

    return 0;
}