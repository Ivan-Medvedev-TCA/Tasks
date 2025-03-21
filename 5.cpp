#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;

/**
 * @brief Считывает целое число с проверкой корректности ввода
 * @return Корректное целое число
 */
int getIntValue();

/**
 * @brief Считывает вещественное число с проверкой корректности ввода
 * @return Корректное вещественное число
 */
double getDoubleValue();

/**
 * @brief Проверяет, что n >= 1
 * @param n Введенное значение
 */
void validateN(int n);

/**
 * @brief Вычисляет факториал числа 
 * @param num Число для вычисления факториала
 * @return Факториал числа
 */
unsigned long long factorial(int num);

/**
 * @brief Вычисляет сумму первых n членов ряда 
 * @param n Количество членов
 * @return Сумма n членов
 */
double sumN(int n);

/**
 * @brief Вычисляет сумму членов ряда, не меньших по модулю е
 * @param e Пороговое значение
 * @return Сумма подходящих членов
 */
double sumE(double e);

int main()
{
    
    // Ввод и проверка n
    cout << "Введите количество членов ряда (n >= 1): ";
    int n = getIntValue();
    validateN(n);
    cout << "Сумма первых " << n << " членов: " 
         << fixed << setprecision(6) << sumN(n) << endl;

    // Ввод и проверка e
    cout << "Введите точность e (e > 0): ";
    double e = getDoubleValue();
    if (e <= 0)
    
    {
        cerr << "Ошибка: e должно быть положительным!" << endl;
        return 1;
    }
    
    cout << "Сумма членов >= " << e << ": " 
         << fixed << setprecision(6) << sumE(e) << endl;

    return 0;
}
int getIntValue()
{
    int value;
    cin >> value;
    if (cin.fail()) 
    {
        cerr << "Ошибка ввода: требуется целое число!" << endl;
        exit(1);
    }
    return value;
}

double getDoubleValue()
{
    double value;
    cin >> value;
    if (cin.fail())
    {
        cerr << "Ошибка ввода: требуется число!" << endl;
        exit(1);
    }
    return value;
}

void validateN(int n) 
{
    if (n < 1) 
    {
        cerr << "Ошибка: n должно быть >= 1!" << endl;
        exit(1);
    }
}

unsigned long long factorial(int num)
{
    if (num < 0) return 0;
    unsigned long long result = 1;
    for (int i = 1; i <= num; ++i) 
    {
        result *= i;
    }
    return result;
}

double sumN(int n)
{
    double total = 0.0;
    for (int o = 0; o < n; ++o) 
    { 
        double numerator = pow(-1, o);
        unsigned long long denominator = factorial(o) * factorial(o + 1);
        total += numerator / denominator;
    }
    return total;
}

double sumE(double e)

{
    double total = 0.0;
    int o = 0;
    while (true)
    
    {
        double numerator = pow(-1, o);
        unsigned long long denominator = factorial(o) * factorial(o + 1);
        double term = numerator / denominator;
        
        if (abs(term) < e) break; 
        
        total += term;
        ++o;
    }
    return total;
}
