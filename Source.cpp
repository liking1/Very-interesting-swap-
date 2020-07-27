#include <iostream>
#include<ctime>
using namespace std;

const int sizeArray = 50;
int myArray[sizeArray];
void showArray(int array[]) {

    for (int i = 0; i < sizeArray; i++)
    {
        if (i % 10 == 0 && i != 0) {
            cout << endl;
        }
        cout << array[i] << " ";
    }
    cout << endl;
}

void searchElement(int array[], int find, int size) {
    setlocale(LC_ALL, "");
    for (int i = 0; i < size; i++)
    {
        if (array[i] == find) {
            cout << "Номер елементу:_> " << i + 1 << " в масиві." << endl;       
        }
    }
}

void sortBubbleU(int array[]) {
    setlocale(LC_ALL, "");
    int count = 0;
    for (int i = sizeArray - 1; i >= 0; i--)
    {
        for (int j = sizeArray - 1; j >= 0; j--)
        {
            if (array[j] < array[j + 1]) { 
                int temp = array[j]; 
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            count++;
        }
    }
    cout << "Вiдстортування вiдбулося за " << count << " кроків." << endl;
}

void sortBubbleD(int array[]) {
    setlocale(LC_ALL, "");
    int count = 0;
    for (int i = 0; i < sizeArray - 1; i++)
    {
        for (int j = 0; j < sizeArray - 1; j++)
        {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            count++;
        }
    }
    cout << "Вiдстортування вiдбулося за " << count << " кроків." << endl;
}

void sortSelectU(int array[]) {
    setlocale(LC_ALL, "");
    int count = 0;
    for (int i = sizeArray; i >= 0; i--)
    {
        int temp = array[99];
        for (int j = i - 1; j >= 0; j--)
        {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            count++;
        }
    }
    cout << "Вiдстортування вiдбулося за " << count << " кроків." << endl;
}

void sortSelectD(int array[]) {
    setlocale(LC_ALL, "");
    int count = 0;
    for (int i = 0; i < sizeArray; i++)
    {
        int temp = array[0];
        for (int j = i + 1; j < sizeArray; j++)
        {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            count++;
        }
    }
    cout << "Вiдстортування вiдбулося за " << count << " кроків." << endl;
}

void sortInsertionU(int array[]) {
    setlocale(LC_ALL, "");
    int temp = 0; 
    int index = 0; 
    int count = 0;
    for (int i = 0; i < sizeArray; i++)
    {
        temp = array[i];
        index = i - 1;

        while (index >= 0 && array[index] > temp)
        {
            array[index + 1] = array[index];
            array[index] = temp;
            index--;
            count++;
        }
    }
    cout << "Вiдстортування вiдбулося за " << count << " кроків." << endl;
}

void sortInsertionD(int array[]) {
    setlocale(LC_ALL, "");
    int temp = 0;
    int index = 0;
    int count = 0;
    for (int i = sizeArray; i >= 0; i--)
    {
        temp = array[i];
        index = i + 1;

        while (index <= 99 && array[index] < temp)
        {
            array[index - 1] = array[index];
            array[index] = temp;
            index++;
            count++;
        }
    }
    cout << "Вiдстортування вiдбулося за " << count << " кроків." << endl;
}

void avArray(int array[]) {
    setlocale(LC_ALL, "");
    int add = 0;
    for (int i = 0; i < sizeArray; i++)
    {
        add += array[i];
    }
    cout << "Середнє арифетичне: " << add / sizeArray << endl;
}

void menu() {
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int action = 0;
    int randStart, randEnd;

    do
    {
        cout << "1. Заповнити масив випадковими числами" << endl;
        cout << "2. Показати масив на екранi" << endl;
        cout << "3. Знайти елемент в масивi" << endl;
        cout << "4. Сортувати масив" << endl;
        cout << "5. Розрахунок середнього арифметичного" << endl;
        cout << "6. Знайти кiлькiсть елементiв кратнi 5" << endl;
        cout << "8. Вихiд" << endl;
        cout << endl;
        cout << "Виберiть номер  ";
        cin >> action;

        switch (action)
        {
        case 1: {
            system("cls");
            cout << "Введiть числовиу рандомiзацiю: " << endl << "Початок дiапазону: ";
            cin >> randStart;
            randStart--;
            cout << "Кiнець дiапазону: ";
            cin >> randEnd;
            randEnd++;
            for (int i = 0; i < sizeArray; i++)
            {
                myArray[i] = rand() % (randEnd - randStart) + randStart;
            }
        }break;

        case 2: {
            system("cls");
            showArray(myArray);
        }break;

        case 3: {
            int numberFind;
            cout << "Введiть число для пошуку числа в масивi: " << endl;
            cin >> numberFind;
            searchElement(myArray, sizeArray, numberFind);
        }break;

        case 4: {
            system("cls");
            cout << "Виберiть алгоритм сортування:" << endl;
            cout << "1. Бульбашковий; " << endl;
            cout << "2. Вибiрковий" << endl;
            cout << "3. Вставковий" << endl;
            cin >> action;
            switch (action)
            {
            case 1: {
                system("cls");
                cout << "Спосiб сортування:" << endl;
                cout << "1. За зростанням" << endl;
                cout << "2. За спаданням" << endl;
                cin >> action;
                switch (action)
                {
                case 1: {
                    system("cls");
                    sortBubbleD(myArray);
                }break;
                case 2: {
                    system("cls");
                    sortBubbleU(myArray);
                }break;
                }
            }break;
            case 2: {
                system("cls");
                cout << "Спосiб сортування:" << endl;
                cout << "1. За зростанням"  << endl;
                cout << "2. За спаданням"   << endl;
                cin >> action;
                switch (action)
                {
                case 1: {
                    system("cls");
                    sortSelectD(myArray);
                }break;
                case 2: {
                    system("cls");
                    sortSelectU(myArray);
                }break;
                }
            }break;
            case 3: {
                system("cls");
                cout << "Спосiб сортування:" << endl;
                cout << "1. За зростанням" << endl;
                cout << "2. За спаданням"  << endl;
                cin >> action;
                switch (action)
                {
                case 1: {
                    system("cls");
                    sortBubbleD(myArray);
                }break;
                case 2: {
                    system("cls");
                    sortBubbleU(myArray);
                }break;
                }
            }break;
            }
        }break;

        case 5: {
            system("cls");
            avArray(myArray);
        }break;

        case 6: {
            system("cls");
            int count = 0;
            for (int i = 0; i < sizeArray; i++)
            {
                if (myArray[i] % 5 == 0)
                    count++;
            }
            cout << "Кiльки елементiв в масивi, помножених на 5: " << count << endl;
        }break;

        case 8: {
            system("cls");
            cout << "ПАКА!" << endl;
            cout << endl;
        }break;
        }
    } while (action != 8);
}

int main() {
    setlocale(LC_ALL, "");
    menu();

    cout << "Масив: " << endl;
    showArray(myArray);
    return 0;
}