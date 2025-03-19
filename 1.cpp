#include <iostream>
#include <cmath>
using namespace std;

/**
 *@brief - Функция для вычисления A по заданному уравнению 
*@param x - значение переменной x
 *@param y - значение переменной y
 *@param z - значение переменной z 
 *@return - возвращает рассчитанное значение
 */
double getA(const double x, const double y,const double z);

/**
 *@brief - Функция для вычисления B по заданному уравнению 
 *@param x - значение переменной x
 *@param y - значение переменной y
 *@param z - значение переменной z
 *@return - возвращает рассчитанное значение
 */
double getB(const double x, const double y,const double z);
/**
 *@brief - Точка входа в программу 
 *@return - возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double x = 1.4;
    const double y = 3.1;
    const double z = 0.5;
    cout<<"A = "<<getA(x,y,z)<<endl;
    cout<<"B = "<<getB(x,y,z);
    return 0;
}
double getA(const double x, const double y,const double z)
{
    return sqrt(2 * x * sin(2 * x) + exp(-2 * x) * (x + y));
}
double getB(const double x, const double y,const double z)
{
    return  (exp(2*x)*log(z+x))-(pow(y,3*x)*log(y-x));
}
