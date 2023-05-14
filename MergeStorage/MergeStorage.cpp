#include <iostream>

using namespace std;

// Объединение двух отсортированных подмассивов в один отсортированный массив
void merge(int arr[], int left[], int right[], int leftLen, int rightLen) {
    int i = 0, j = 0, k = 0;

    // Сравнение первых элементов обоих подмассивов
    // Добавление меньшего элемента в объединенный массив
    while (i < leftLen && j < rightLen) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }

    // Добавление всех оставшихся элементов из левого подмассива
    while (i < leftLen) {
        arr[k++] = left[i++];
    }

    // Добавление всех оставшихся элементов из правого подмассива
    while (j < rightLen) {
        arr[k++] = right[j++];
    }
}

// Сортировка массива с использованием алгоритма сортировки слиянием
void mergeSort(int arr[], int len) {
    if (len < 2) {
        // Базовый случай: массив уже отсортирован (или пуст)
        return;
    }

    // Разделение массивов на два подмассива примерно одинакового размера
    int mid = len / 2;
    int *left = new int[mid];
    int *right = new int[__int64(len) - mid];

    // Копирование элементов из исходного массива в левый и правый подмассивы
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < len; i++) {
        right[i - mid] = arr[i];
    }

    // Вызов рекурсивной сортировки для подмассивов
    mergeSort(left, mid);
    mergeSort(right, len - mid);

    // Слияние отсортированных подмассивов
    merge(arr, left, right, mid, len - mid);

    // Освобождение выделенной памяти
    delete[] left;
    delete[] right;
}

int main() {
    system("chcp 1251>nul");

    int len;

    // Запрашиваем у пользователя размер массива
    cout << "Введите количество элементов в массиве: ";
    cin >> len;

    // Создаем динамический массив нужного размера
    int* arr = new int[len];

    // Запрашиваем у пользователя значения для каждого элемента массива
    for (int i = 0; i < len; i++) {
        cout << "Введите значение элемента " << i << ": ";
        cin >> arr[i];
    }

    // Сортируем массив
    mergeSort(arr, len);

    // Выводим отсортированный массив
    cout << "Отсортированный массив: ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Освобождаем выделенную память
    delete[] arr;
    return 0;
}
