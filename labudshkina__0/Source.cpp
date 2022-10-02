#include <iostream> //библиотека,которая содержит потоки ввода и вывода
#include <string>  //тип string применяется для хранения строк 
#include <fstream> //библиотека,которая содержит потоки,которые организовывакют чтение/запись из файла/запись в файл

using namespace std; //сообщает компилятору ,что мы хотим испоьзовать все,что находится в пространстве std

struct pipe //создаем структуру с именем pipe
{
    string name;
    int lenght;
    int diametr;
    bool repair;//bool - встроенный тип.Переменная этого типа имеют значения true or false
};

struct CS //создаем структуру с именем cs
{
    string name;
    int countWS;
    int actWS;
    float eff; //float- представляет вещественное число двойной точности с плавающей точкой
};

void print_menu()
{
    system("cls"); //очищаем экран
    cout << "1. Добавить трубу\n";
    cout << "2. Добавить КС\n";
    cout << "3. Просмотр всех объектов\n";
    cout << "4. Редактировать трубу\n";
    cout << "5. Редактировать КС\n";
    cout << "6. Сохранить\n";
    cout << "7. Загрузить\n";
    cout << "0. Выход\n";
    cout << "\nВыберите действие - ";
}

//считаем введенный пункт меню(защищаем программу от некорректного ввода с помощью считывания строки и проверки ввода на корректность)
int get_variant(int count)
{
    int variant;
    string s; //строка для считывания введенных данных
    getline(cin, s); //считаем строку
    //пока ввод некорректен,сообщаем об этом и просим повторить его
    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 0 || variant > count)//(||)-логическое сложение,ИЛИ
    {
        cout << "Некорректный ввод. Попробуйте снова: "; //выводим сообщение об ошибке
        getline(cin, s); //считаем строку повторно
    }
    return variant;
}

//добавление трубы
pipe AddPipe()
{
    pipe Obj;
    system("cls");//очищаем экран
    cout << "Добавление трубы\n";
    cout << "Название: ";
    cin >> Obj.name;
    cout << "Длинна (м): ";
    cin >> Obj.lenght;
    cout << "Диаметр (мм): ";
    cin >> Obj.diametr;
    cout << "Ремонт (0 или 1): ";
    cin >> Obj.repair;
    return Obj;
}

//добавление кс
CS AddCS()
{
    CS Obj;
    system("cls");//очищаем экран
    cout << "Добавление КС\n";
    cout << "Название: ";
    cin >> Obj.name;
    cout << "Кол-во цехов: ";
    cin >> Obj.countWS;
    cout << "Кол-во цехов в работе: ";
    cin >> Obj.actWS;
    cout << "Эффективность: ";
    cin >> Obj.eff;
    return Obj;
}

//вывод параметров трубы
void ShowPipe(const pipe& Obj)
{
    cout << "Имя\t" << "Длина\t" << "Диаметр\t" << "Ремонт\t" << endl; //вывод значений параметров трубы на консоль
    cout << "---------------------------------------------------------------------------" << endl; //вывод данной "строки" на консоль
    cout << Obj.name << '\t' << Obj.lenght << '\t' << Obj.diametr << '\t' << Obj.repair << endl;

}

//вывод параметров КС
void ShowCS(const CS& Obj)
{
    cout << "Имя\t" << "Цехи\t" << "В работе" << " Эффективность\t" << endl;//вывод значений параметров КС на консоль
    cout << "---------------------------------------------------------------------------" << endl;//вывод данной "строки" на консоль
    cout << Obj.name << '\t' << Obj.countWS << '\t' << Obj.actWS << '\t' << Obj.eff << endl;
}

//редактирование параметров трубы
void EditPipe(pipe& Obj)
{
    system("cls");//очищаем экран
    cout << "Что редактируем?\n" << "1. Имя\n" << "2. Длинна\n" << "3. Диаметр\n" << "4. Ремонт\n" << "0. Выход\n" << ">";
    int cursor = get_variant(4); // получаем номер выбранного пункта меню
    switch (cursor) {
    case 1:
        cout << "Текущее имя: " << Obj.name << "\n";
        cout << "Новое имя: ";
        cin >> Obj.name;
        break;
    case 2:
        cout << "Текущая длинна: " << Obj.lenght << "\n";
        cout << "Новая длинна (м): ";
        cin >> Obj.lenght;
        break;
    case 3:
        cout << "Текущий диаметр: " << Obj.diametr << "\n";
        cout << "Новый диаметр (мм): ";
        cin >> Obj.diametr;
        break;
    case 4:
        cout << "Текущий Ремонт: " << Obj.repair << "\n";
        cout << "Ремонт (0 или 1): ";
        cin >> Obj.repair;
        break;
    case 0:
        break;
    }
}

//редактирование параметров КС
void EditCS(CS& Obj)
{
    system("cls");//очищаем экран
    cout << "Что редактируем?\n" << "1. Имя\n" << "2. Кол-во цехов\n" << "3. Кол-во цехов в работе\n" << "4. Эффективность\n" << "0. Выход\n" << ">";
    int cursor = get_variant(4);// получаем номер выбранного пункта меню
    switch (cursor) {
    case 1:
        cout << "Текущее имя: " << Obj.name << "\n";
        cout << "Новое имя: ";
        cin >> Obj.name;
        break;
    case 2:
        cout << "Текущее кол-во цехов: " << Obj.countWS << "\n";
        cout << "Новое кол-во цехов: ";
        cin >> Obj.countWS;
        break;
    case 3:
        cout << "Текущее кол-во цехов в работе: " << Obj.actWS << "\n";
        cout << "Новое кол-во цехов в работе: ";
        cin >> Obj.actWS;
        break;
    case 4:
        cout << "Текущая эффективность: " << Obj.eff << "\n";
        cout << "Новая эффективность: ";
        cin >> Obj.eff;
        break;
    case 0:
        break;
    }
}


int main() //вызов функции main()
{
    setlocale(0, ""); //вывод на консоль на русском языке
    int cursor;

    pipe p = { "0", 0, 0, 0 };
    CS CS = { "0", 0, 0, 0 };

    do
    {
        print_menu();
        cursor = get_variant(7);// получаем номер выбранного пункта меню

        switch (cursor) {
        case 1:
        {  
            p = AddPipe();
            break;
        }
        case 2:
        {
            CS = AddCS();
            break;
        }

        case 3:
        {
            system("cls");
            cout << "Просмотр всех объектов\n\n";
            ShowPipe(p);
            cout << "\n";
            ShowCS(CS);
            break;
        }

        case 4:
        {            
            EditPipe(p);
            break;
        }

        case 5:
        {
            EditCS(CS);
            break;
        }

        }
        if (cursor != 0) system("pause");//(!=)-неравенство 
    } while (cursor != 0);
    return 0;
}





