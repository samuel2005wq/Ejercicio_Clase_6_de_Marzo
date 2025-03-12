// Hecho por: Samuel Acuña y Carolina García
#include <iostream>
#include <string>
using namespace std;

// Callback functions for different operations
int add(int a, int b) // suma
{
    return a + b;
}

int multiply(int a, int b) // multiplicación
{
    return a * b;
}

int subtract(int a, int b) // resta
{
    return a - b;
}

// Function that performs an operation using a callback
void performOperation(int (*callback)(int, int), int x, int y)
{
    cout << "The result of the operation is: " << callback(x, y) << endl; // imprime el resultado de la operación
}

int main(int argc, char *argv[]) // argc es el número de argumentos que se pasan y argv es un array de punteros a los argumentos
{
    if (argc != 4)
    {
        cerr << "Usage: " << argv[0] << " <num1> <operation> <num2>" << endl; // imprime el mensaje de error
        return 1;
    }

    int num1 = stoi(argv[1]); // stoi convierte un string a un entero
    int num2 = stoi(argv[3]); // stoi convierte un string a un entero
    char op = argv[2][0];

    // Passing different functions as callbacks
    if (op == '+')
    {
        cout << "Addition: ";
        performOperation(add, num1, num2); // llama a la función add
    }
    else if (op == 'x') // 'x' is used to represent multiplication no se usa '*' porque es un caracter especial
    {
        cout << "Multiplication: ";
        performOperation(multiply, num1, num2); // llama a la función multiply
    }
    else if (op == '-')
    {
        cout << "Subtraction: ";
        performOperation(subtract, num1, num2); // llama a la función subtract
    }
    else
    {
        cerr << "Invalid operation" << endl; // imprime el mensaje de error
    }

    int (*operations[])(int, int) = {add, multiply, subtract};
    // Iterate over the array and call each operation
    for (int i = 0; i < 3; ++i)
    {
        cout << "Operation " << i + 1 << ": ";
        performOperation(operations[i], num1, num2); // llama a las funciones del array
    }

    cout << argv << endl;

    return 0;
}