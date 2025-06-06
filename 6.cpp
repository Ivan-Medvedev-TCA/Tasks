#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <limits> 

using namespace std;

/**
* @brief Считывает целое значение с клавиатуры с проверкой ввода
* @return Введенное значение
*/
int getValue();

/**
* @brief Получает и проверяет размер массива
* @return Размер массива
*/
size_t razmmass();

/**
* @brief Проверяет корректность размера массива
* @param n Проверяемое значение размера
* @return Завершает программу при n <= 0
*/
void kormass(const int n);

/**
* @brief Заполняет массив значениями
* @param arr Указатель на массив
* @param n Размер массива
*/
void zapmass(int* arr,const size_t n);

/**
* @brief Выводит массив на экран
* @param arr Указатель на массив
* @param n Размер массива
*/
void vivoidmass(const int* arr,const size_t n);

/**
* @brief Находит максимальный отрицательный элемент массива
* @param arr Указатель на массив
* @param n Размер массива
* @return Максимальное отрицательное значение или -1 если таких элементов нет
*/
int maxotrmass(const int* arr, const size_t n);

/**
* @brief Заменяет второй элемент массива на первый отрицательный
* @param arr Указатель на массив
* @param n Размер массива
* @note Выводит предупреждение если массив слишком мал или нет отрицательных элементов
*/
void zammass(int* arr,const size_t n);

/**
* @brief Считает количество положительных элементов, не превышающих A
* @param arr Указатель на массив
* @param n Размер массива
* @param A Верхняя граница значений
* @return Количество элементов удовлетворяющих условию
*/
int c4etmass(const int* arr,const size_t n, const int A);

/**
* @brief Ищет первую пару соседних элементов с суммой меньше заданного числа
* @param arr Указатель на массив
* @param n Размер массива
* @param number Целевая сумма для сравнения
* @return Индекс первого элемента пары или -1 если пара не найдена
*/
int parmass(const int* arr, const size_t n, const int number);

/**
* @brief Находит индекс первого отрицательного элемента в массиве
* @param arr Указатель на массив для проверки
* @param n Размер проверяемого массива
* @return Индекс первого отрицательного элемента или -1 если таких элементов нет
*/
int firstNegativ(const int* arr, size_t n);

/**
* @brief Создает полную копию массива
* @param source Исходный массив для копирования
* @param size Размер массива
* @return Указатель на новый массив-копию
*/
int* copyArray(const int* source,const size_t size);

/**
 * @brief Режимы ввода элементов массива
 */
enum {MANUALY, RANDOM}; 

/**
 * @brief Точка входа в программу
 * @return 0 при успешном выполнении
 */
int main() 
{
    size_t n = razmmass();
    int* arr = new int[n];
    zapmass(arr, n);
    cout << "Исходный массив: ";
    vivoidmass(arr, n);
    
    int* arr_copy = copyArray(arr, n);
    
  
    zammass(arr_copy, n);
    cout << "Массив после замены (копия): ";
    vivoidmass(arr_copy, n);

    cout << "Введите А для задания 2: ";
    int A = getValue();
    int count = c4etmass(arr_copy, n, A);
    cout << "Количество положительных элементов <= A: " << count << endl;
    
    cout << "Введите число для задачи 3: ";
    int num = getValue();
    int pairIndex = parmass(arr_copy, n, num);
    
    if (pairIndex == -1) {
        cout << "Пара не найдена." << endl;
    } else {
        cout << "Пара начинается с индекса: " << pairIndex << endl;
    }
  
    delete[] arr;
    delete[] arr_copy;
    return 0;
}

int* copyArray(const int* source,const size_t size) 
{
    int* newArray = new int[size];
    for (size_t i = 0; i < size; i++) 
    {
        newArray[i] = source[i];
    }
    return newArray;
}

int getValue()
{
    int value = 0;
    if (!(cin >> value)) {
        cerr << "Ошибка ввода! Программа завершена." << endl;
        abort();
    }
    return value;
}

size_t razmmass()
{
    cout << "Введите размер массива: ";
    int n = getValue();
    kormass(n);
    return static_cast<size_t>(n);
}

void kormass(const int n)
{
    if (n <= 0) 
    {
        cout << "Недопустимый размер. Программа остановлена." << endl;
        abort();
    }
}

void zapmass(int* arr,const size_t n)
{
    cout << "Выберите метод ввода (" << RANDOM << " - Случайный, " << MANUALY << " - Ручной): ";
    int choice = getValue();
    int min_val, max_val;
    
    cout << "Введите минимальное значение: ";
    min_val = getValue();
    cout << "Введите максимальное значение: ";
    max_val = getValue();

    if (min_val > max_val) {
        cout << "Ошибка: минимальное значение больше максимального. Программа остановлена." << endl;
        abort();
    }

    switch (choice) 
    {
        case RANDOM: 
        {
            srand(time(0));
            for (size_t i = 0; i < n; i++)
            {
                arr[i] = min_val + rand() % (max_val - min_val + 1);
            }
            break;
        }
        case MANUALY: 
        {
            for (size_t i = 0; i < n; i++) 
            {
                cout << "Введите элемент[" << i + 1 << "] (от " << min_val << " до " << max_val << "): ";
                int value = getValue();
              
                if (value < min_val || value > max_val) {
                    cout << "Ошибка: значение вне диапазона. Программа остановлена." << endl;
                    abort();
                }
                arr[i] = value;
            }
            break;
        }
        default:
            cout << "Неверный выбор. Программа остановлена." << endl;
            abort();
    }
}

void vivoidmass(const int* arr,const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int maxotrmass(const int* arr,const size_t n)
{
    bool found = false;       
    int maxNeg = 0;           

    for (size_t i = 0; i < n; i++) 
    {
        if (arr[i] < 0)
        {     
            if (!found)
            {
                maxNeg = arr[i];
                found = true;
            } 
            else 
            {
                if (arr[i] > maxNeg)
                {
                    maxNeg = arr[i];
                }
            }
        }
    }
    if (!found) 
    {
        return -1;  
    }
    return maxNeg;   
}

void zammass(int* arr,const size_t n)
{
    if (n < 2)
    {
        cout << "Массив слишком мал для замены второго элемента." << endl;
        return;
    }
    int index = firstNegativ(arr, n);
    if (index == -1) 
    {
        cout << "Отрицательные элементы отсутствуют. Замена не выполнена." << endl;
    } 
    else 
    {
        arr[1] = arr[index];
    }
}

int c4etmass(const int* arr,const size_t n, const int A) 
{
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] > 0 && arr[i] <= A)
        {
            count++;
        }
    }
    return count;
}

int parmass(const int* arr, const size_t n, const int number) 
{
    for (size_t i = 0; i < n - 1; i++) 
    {
        if (arr[i] + arr[i + 1] < number)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int firstNegativ(const int* arr,const size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        if (arr[i] < 0) 
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}
