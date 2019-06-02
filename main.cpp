#include <iostream>
#include <fstream>

using namespace std;


//Функция считывания из файла в матрицу
bool loadFromFile(int** matrix, string file, int n) {

    //Поток вывода из файла
    ifstream in(file);

    if (in.is_open()) {
    //ввод из файла в матрицу
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> matrix[i][j];

        }
    }
    cout << matrix[0][0];

    //Закрываем поток на вывод из файла
    in.close();
        return true;
    } else{
        cout << endl << "Ошибка открытия файлов";
        return false;
    }
}

//Функция поиска индекса первой строки содержащей максимальный элемент
int getFirstIndexMax(int **matrix, int n){
   int max = matrix[0][0];
   int indexMax=0;
   //Поиск первой строки максимума
    for(int i =0; i<n; i++) {
        for (int j = 0; j < n; j++) {
            if (max < matrix[i][j]) { //Первая строка так как условие < , при повторе не будет замены
                max = matrix[i][j];
                indexMax = i;
            }
        }
    }
    return indexMax;
}

//Функция поиска индекса последней строки содержащей минимальный элемент
int getLastIndexMin(int **matrix, int n){
   int min = matrix[0][0];
    int indexMin=0;
    //Поиск первой строки максимума
    for(int i =0; i<n; i++) {
        for (int j = 0; j < n; j++) {
            if (min >= matrix[i][j]) { //Последняя стркоа так как условие >= , будет замена до последней строки
                min = matrix[i][j];
                indexMin = i;
            }
        }
    }
    return indexMin;
}

//Функция вывода матрицы в файл без строк с максимальным и минимальным элементом.
void outputInFile(int** matrix, int n, int indexMax, int indexMin, string file){
    ofstream of(file);
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != indexMax && i!=indexMin){ //Если строка не содержит максимума или минимума то мы выводим
                of << matrix[i][j] << " ";
            }
        }
        if(i != indexMax && i!=indexMin) //если текущая строка не содержит максимум ил минимум то ставим снос каретки
            of << endl;
    }

}

int main() {

    string file = "C:\\Users\\Mrsla\\CLionProjects\\MatrixDeleteFile\\file.txt";
    int n;
    cout << "Введите размерность матрицы: ";
    cin >> n;


    //Создание матрицы
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];

    //Загрузка из файла и проверка открылся ли файл
    if( loadFromFile(matrix,file, n) ){
        //Функция вывода матрицы в файл. Передаем матрицу, ее размер, вызываем функции получения индексов строк содержащих максимальный и минимальный размер и строку с путем до файла.
        outputInFile(matrix, n, getFirstIndexMax(matrix,n), getLastIndexMin(matrix,n),file);
    }

    return 0;
}