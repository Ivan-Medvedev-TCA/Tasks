#include <iostream>
#include <cmath>
#include <limits>

/**
 * @brief Считывает числовое значение с консоли с проверкой на корректность.
 * @return double — считанное значение.
 * @throws abort() при некорректном вводе.
 */
double getValue();

/**
 * @brief Проверяет корректность шага табуляции.
 * @param step — шаг табуляции.
 * @throws abort() если шаг <= 0.
 */
void checkStep(const double step);

/**
 * @brief Проверяет корректность шага табуляции.
 * @param step — шаг табуляции.
 * @throws abort() если шаг <= 0.
 */
double getY(const double x);

using namespace std;

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена верно
*/
int main()
{
    cout << "введите а: ";
    double xstart = getValue();
    cout << "введите в: ";
    double xend = getValue();
    cout << "введите шаг: ";
    double step = getValue();
    checkStep(step);

    for (double x = xstart; x < xend + step; x += step) 
    {
        cout << "x = " << x;
            cout << " y = " << getY(x) << endl;
    }
    return 0;
}

double getValue()
{
    double value = 0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Ошибка: Некорректный ввод" << endl;
        abort();
    }
    return value;
}

void checkStep(const double step) {
    if (step <= 0)
    {
        cout << "Ошибка: Шаг должен быть > 0" << endl;
        abort();
    }
}

double getY(const double x) 
{
    return 3*x-14+exp(x)-exp(-x);
}
