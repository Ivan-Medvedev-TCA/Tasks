#include <iostream>
#include <cstdlib>
#include <ctime>

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
void zapmass(int* arr, size_t n);

/**
* @brief Выводит массив на экран
* @param arr Указатель на массив
* @param n Размер массива
*/
void vivoidmass(int* arr, size_t n);

/**
* @brief Находит максимальный отрицательный элемент массива
* @param arr Указатель на массив
* @param n Размер массива
* @return Максимальное отрицательное значение или -11 если таких элементов нет
*/
int maxotrmass(int* arr, size_t n);

/**
* @brief Заменяет второй элемент массива на первый отрицательный
* @param arr Указатель на массив
* @param n Размер массива
* @return Выводит предупреждение если массив слишком мал или нет отрицательных элементов
*/
void zammass(int* arr, size_t n);

/**
* @brief Считает количество положительных элементов, не превышающих A
* @param arr Указатель на массив
* @param n Размер массива
* @param A Верхняя граница значений
* @return Количество элементов удовлетворяющих условию
*/
int c4etmass(int* arr, size_t n, int A);

/**
* @brief Ищет первую пару соседних элементов с суммой меньше заданного числа
* @param arr Указатель на массив
* @param n Размер массива
* @param number Целевая сумма для сравнения
* @return Индекс первого элемента пары или -1 если пара не найдена
*/
int parmass(int* arr, size_t n, int number);

/**
* @brief Проверяет наличие отрицательных элементов в массиве
* @param arr Указатель на массив
* @param n Размер массива
* @return true, если есть хотя бы один отрицательный элемент, иначе false
*/
bool firstNegativ(int* arr, size_t n);

/**
* @brief Проверяет наличие отрицательных элементов в массиве
* @param arr Указатель на массив для проверки
* @param n Размер проверяемого массива
* @return true - если массив содержит хотя бы один отрицательный элемент, false - если отрицательных элементов нет
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
    cout << "Основной массив: ";
    vivoidmass(arr, n);
    zammass(arr, n);
    cout << "Массив после замены: ";
    vivoidmass(arr, n);
    cout << "Введите А для задания 2: ";
    int A = getValue();
    int count = c4etmass(arr, n, A);
    cout << "Количество положительных элементов <= A: " << count << endl;
    cout << "Введите число для задачи 3: ";
    int num = getValue();
    int pairIndex = parmass(arr, n, num);
    if (pairIndex == -1)
    {
        cout << "Пара не найдена." << endl;
    } 
    else 
    {
        cout << "Пар: " << pairIndex << endl;
    }
    delete[] arr;
    return 0;
}

int getValue() 
{
    int value = 0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Неверный ввод. Остановка." << endl;
        abort();
    }
    return value;
}

size_t razmmass()
{
    cout << "Введите размер массива: ";
    int n = getValue();
    kormass(n);
    return size_t(n);
}

void kormass(const int n)
{
    if (n <= 0) 
    {
        cout << "Неверный размер. Остановка." << endl;
        abort();
    }
}

void zapmass(int* arr, const size_t n)
{
    cout << "Выбери метод ввода (" << RANDOM << " - Рандом, " << MANUALY << " - Ручной ввод): ";
    int choice = getValue();
    switch (choice) 
    {
        case RANDOM: 
        {
            srand(time(0));
            for (size_t i = 0; i < n; i++)
            {
                arr[i] = -10 + rand() % 21;
            }
            break;
        }
        case MANUALY: 
        {
            for (size_t i = 0; i < n; i++) 
            {
                while (true) 
                {
                    cout << "Ввод массива[" << i + 1 << "] (от -10 до 10): ";
                    int value = getValue();
                    if (value >= -10 && value <= 10)
                    {
                        arr[i] = value;
                        break;
                    }
                    cout << "Ошибка! Значение не должно превышать от -10 до 10. Выбери другое значение.";
                }
            }
            break;
        }
        default:
            cout << "Неверный выбор. Остановка." << endl;
            abort();
    }
}

void vivoidmass(int* arr, const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int maxotrmass(int* arr, const size_t n)
{
    int maxNeg = -11;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] < 0 && arr[i] > maxNeg)
        {
            maxNeg = arr[i];
        }
    }
    return maxNeg;
}

void zammass(int* arr, const size_t n)
{
    if (n < 2)
    {
        cout << "Массив слишком мал для замены второго элемента." << endl;
        return;
    }
    int firstNeg = -11;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            firstNeg = arr[i];
            break;
        }
    }
    if (firstNeg == -11) 
    {
        cout << "Нет отрицательных элементов. Второй элемент не заменен." << endl;
    } else 
    {
        arr[1] = firstNeg;
    }
}

int c4etmass(int* arr, size_t n, int A) 
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

int parmass(int* arr, size_t n, int number) 
{
    for (size_t i = 0; i < n - 1; i++) 
    {
        if (arr[i] + arr[i + 1] < number)
        {
            return i;
        }
    }
    return -1;
}

bool firstNegativ(int* arr, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        if (arr[i] < 0) 
        {
            return true;
        }
    }
    return false;
}
