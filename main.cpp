#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int n;
    cout << "Введите размерность матрицы: ";
    cin >> n;

    //Создание матрицы
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];

    //Поток вывода из файла
    ifstream in("C:\\Users\\Mrsla\\CLionProjects\\MatrixDeleteFile\\file.txt");

    int indexMax=0, //индекс строки максимума
        indexMin=0, //индекс строки минимума
        min, //значение минимума
        max; //значение максимума

        //ввод из файла в матрицу
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            in >> matrix[i][j];

        }
    }

    //Закрываем поток на вывод из файла
    in.close();

    min = matrix[0][0];
    max = matrix[0][0];

    //Поиск минимума и максимума
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            if(max < matrix[i][j]){ //Первая строка так как условие < , при повторе не будет замены
                max = matrix[i][j];
                indexMax = i;
            }
            if(min >= matrix[i][j]){ //Последняя стркоа так как условие >= , будет замена до последней строки
                min = matrix[i][j];
                indexMin=i;
            }
        }
    }

    ofstream of("C:\\Users\\Mrsla\\CLionProjects\\MatrixDeleteFile\\file.txt");

    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != indexMax && i!=indexMin){ //Если строка не содержит максимума или минимума то мы выводим
                of << matrix[i][j];
            }
        }
        if(i != indexMax && i!=indexMin) //если текущая строка не содержит максимум ил минимум то ставим снос каретки
         of << endl;
    }




    return 0;
}