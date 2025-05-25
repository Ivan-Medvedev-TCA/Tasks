#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;
int getValue();
/**
 * @brief Считывает целое значение с клавиатуры с проверкой ввода
 * @return Введенное целое число
 * @note При некорректном вводе завершает программу с ошибкой
 */

size_t getSize();
/**
 * @brief Получает и проверяет размер массива
 * @return Положительный размер массива
 * @note При значении <= 0 завершает программу с ошибкой
 */

int** getNewArray(const size_t m, const size_t n);
/**
 * @brief Создает двумерный массив (матрицу) в динамической памяти
 * @param m Количество строк в массиве
 * @param n Количество столбцов в массиве
 * @return Указатель на созданный двумерный массив
 */

void printArray(int** array, const size_t m, const size_t n);

/**
 * @brief Выводит массив в форматированном виде
 * @param array Целевой массив для вывода
 * @param m Количество строк
 * @param n Количество столбцов
 */

void fillArray(int** array, const size_t m, const size_t n);

/**
 * @brief Заполняет массив вручную через консольный ввод
 * @param array Целевой массив
 * @param m Количество строк
 * @param n Количество столбцов
 */

void fillRandom(int** array, const size_t m, const size_t n, const int start, const int end);
/**
 * @brief Заполняет массив случайными числами в заданном диапазоне
 * @param array Целевой массив
 * @param m Количество строк
 * @param n Количество столбцов
 * @param start Нижняя граница значений
 * @param end Верхняя граница значений
 */

void deleteArray(int** array, const size_t m, const size_t n);
/**
 * @brief Освобождает память двумерного массива
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 */

int** copyArray(int** array, const size_t m, const size_t n);
/**
 * @brief Создает глубокую копию массива
 * @param array Исходный массив для копирования
 * @param m Количество строк
 * @param n Количество столбцов
 * @return Новая независимая копия массива
 */

void zapchutmass(int** array, size_t m, size_t n);
/**
 * @brief Заменяет четные элементы на максимальный по модулю элемент в столбце
 * @param array Целевой массив
 * @param m Количество строк
 * @param n Количество столбцов
 * @note Модифицирует исходный массив
 */

int** ydchet(int** array, size_t m, size_t n, size_t& new_n);
/**
 * @brief Удаляет столбцы с четным первым элементом
 * @param array Исходный массив
 * @param m Количество строк
 * @param n Количество столбцов
 * @param new_n Ссылка для возврата нового количества столбцов
 * @return Новый массив без удаленных столбцов или nullptr
 * @note Требует последующего удаления возвращаемого массива
 */

enum { RANDOM = 1, MANUAL = 0 };
/**
* @brief Перечисление для выбора способа заполнения данных
* @param MANUALY Выбор ручного заполнения массива
* @param RANDOM Выбор автоматического заполнения массива
*/
int main() 
{
    cout << "Введите m (строки): ";
    size_t m = getSize();
    cout << "Введите n (столбцы): ";
    size_t n = getSize();
    int** array = getNewArray(m, n); 
    cout << "Выберите способ заполнения: " << MANUAL << " - вручную, " << RANDOM << " - случайные числа: ";
    int choice = getValue();
    int start = 0, end = 0;
    switch (choice) 
    {
        case RANDOM:
            cout << "Введите начало диапазона: ";
            start = getValue();
            cout << "Введите конец диапазона: ";
            end = getValue();
            fillRandom(array, m, n, start, end);
            break;
        case MANUAL:
            fillArray(array, m, n);
            break;
        default:
            cout << "Ошибка";
            deleteArray(array, m, n);
            return 1;
    }
    cout << "Исходный массив:";
    printArray(array, m, n);
    int** task1Array = copyArray(array, m, n);
    zapchutmass(task1Array, m, n);
    cout << "После задачи 1 (замена чётных на максимум в столбце):";
    printArray(task1Array, m, n);
    deleteArray(task1Array, m, n);
    size_t new_n;
    int** task2Array = ydchet(array, m, n, new_n);
    cout << "После задачи 2 (удалены столбцы с чётным первым элементом):";
    if (task2Array != nullptr && new_n > 0) 
    {
        printArray(task2Array, m, new_n);
        deleteArray(task2Array, m, new_n);
    } 
    else 
    {
        cout << "Нет оставшихся столбцов.";
    }

    deleteArray(array, m, n);
    return 0;
}

int** getNewArray(const size_t m, const size_t n) 
{
    int** array = new int*[m];
    for (size_t i = 0; i < m; i++) 
    {
        array[i] = new int[n];
    }
    return array;
}

void deleteArray(int** array, const size_t m, const size_t n) 
{
    for (size_t i = 0; i < m; i++) 
    {
        delete[] array[i]; 
    }
    delete[] array;
}

void printArray(int** array, const size_t m, const size_t n) 
{
    for (size_t i = 0; i < m; i++) 
    {
        for (size_t j = 0; j < n; j++) 
        {
            cout << setw(6) << array[i][j];
        }
        cout << endl;
    }
}

void fillArray(int** array, const size_t m, const size_t n) 
{
    for (size_t i = 0; i < m; i++) 
    {
        for (size_t j = 0; j < n; j++) 
        {
            cout << "Введите array[" << i << "][" << j << "]: ";
            array[i][j] = getValue();
        }
    }
}

void fillRandom(int** array, const size_t m, const size_t n, const int start, const int end) 
{
    srand(time(0));
    for (size_t i = 0; i < m; i++) 
    {
        for (size_t j = 0; j < n; j++) 
        {
            array[i][j] = rand() % (end - start + 1) + start;
        }
    }
}

int getValue() 
{
    int value = 0;
    cin >> value;
    if (cin.fail()) 
    {
        cerr << "Ошибка ввода!";
        abort();
    }
    return value;
}

size_t getSize() 
{
    int size = getValue();
    if (size <= 0) 
    {
        cerr << "Размер должен быть положительным!";
        abort();
    }
    return static_cast<size_t>(size);
}

int** copyArray(int** array, const size_t m, const size_t n) 
{
    int** newArray = getNewArray(m, n);
    for (size_t i = 0; i < m; i++) 
    {
        for (size_t j = 0; j < n; j++) 
        {
            newArray[i][j] = array[i][j];
        }
    }
    return newArray;
}

void zapchutmass(int** array, size_t m, size_t n) 
{
    for (size_t j = 0; j < n; j++) 
    {
        int max_abs = abs(array[0][j]);
        int max_val = array[0][j];
        for (size_t i = 1; i < m; i++) 
        {
            if (abs(array[i][j]) > max_abs) 
            {
                max_abs = abs(array[i][j]);
                max_val = array[i][j];
            }
        }
        for (size_t i = 0; i < m; i++) 
        {
            if (array[i][j] % 2 == 0) 
            {
                array[i][j] = max_val;
            }
        }
    }
}

int** ydchet(int** array, size_t m, size_t n, size_t& new_n) 
{
    size_t count = 0;
    for (size_t j = 0; j < n; j++) 
    {
        if (array[0][j] % 2 != 0) 
        {
            count++;
        }
    }
    new_n = count;

    if (count == 0) 
    {
        return nullptr;
    }
    int** newArray = getNewArray(m, new_n);
    size_t new_j = 0;

    for (size_t j = 0; j < n; j++) 
    {
        if (array[0][j] % 2 != 0) 
        {
            for (size_t i = 0; i < m; i++) 
            {
                newArray[i][new_j] = array[i][j];
            }
            new_j++;
        }
    }
    return newArray;
}
