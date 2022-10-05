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
    std::cout << "1. Добавить трубу\n";
    std::cout << "2. Добавить КС\n";
    std::cout << "3. Просмотр всех объектов\n";
    std::cout << "4. Редактировать трубу\n";
    std::cout << "5. Редактировать КС\n";
    std::cout << "6. Сохранить\n";
    std::cout << "7. Загрузить\n";
    std::cout << "0. Выход\n";
    std::cout << "\nВыберите действие - ";
}

//считаем введенный пункт меню(защищаем программу от некорректного ввода с помощью считывания строки и проверки ввода на корректность)
int Get_variant1(int k)
{
    int z;
        std::cin >> z;
        while ((cin.fail()) || (z < 0) || (z > k) || (cin.get() != '\n')) {//(||)-логическое сложение,ИЛИ
            std::cin.clear();
            std::cin.ignore(100000, '\n');//
            std::cout << "Введено не корректное число.Повторите попытку: ";
            std::cin >> z;
    }
    return z;
}

float Get_variant2(float n) {
    float a;
    std::cin >> a;
    while ((std::cin.fail()) || (a < 0) || (a > n) || (std::cin.get() != '\n')) {
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "Введено не корректное число.Повторите попытку: ";
        std::cin >> a;
    }
    return a;
}

//добавление трубы
pipe AddPipe()
{
    pipe Obj;
    system("cls");//очищаем экран
    std::cout << "Добавление трубы\n";
    std::cout << "Длина (м): ";
    Obj.lenght = Get_variant1(100000);
    while (Obj.lenght <= 0) {
        std::cout << "Длина должна быть больше 0!" << endl;
        Obj.lenght = Get_variant1(100000);
    }
    std::cout << "Диаметр (мм): ";
    Obj.diametr = Get_variant1(100000);
    while (Obj.diametr <= 0) {
        std::cout << "Диаметр должен быть больше 0!" << endl;
        Obj.diametr = Get_variant1(100000);
    }
    std::cout << "Ремонт (0-не нужен или 1-нужен): ";
    Obj.repair = Get_variant1(1);
    return Obj;
}

//добавление кс
CS AddCS()
{
    CS Obj;
    system("cls");//очищаем экран
    std::cout << "Добавление КС\n";
    std::cout << "Имя КС:\n";
        std::getline(cin, Obj.name);
    std::cout << "Кол-во цехов: ";
    Obj.countWS = Get_variant1(100000);
    while (Obj.countWS <= 0) {
        std::cout << "Кол-во цехов должно быть больше 0!" << endl;
        Obj.countWS = Get_variant1(100000);
    }
    std::cout << "Кол-во цехов в работе: ";
    Obj.actWS = Get_variant1(100000);
    while (Obj.countWS < Obj.actWS) {
        std::cout << "Количество цехов в работе не может быть меньше общего количества цехов!" << endl;
        Obj.actWS = Get_variant1(100000);
    }
    std::cout << "Эффективность(0-1): ";
    Obj.eff = Get_variant2(1);
    return Obj;
}

//вывод параметров трубы
void ShowPipe(const pipe& Obj)
{
    std::cout << "Длина\t" << "Диаметр\t" << "Ремонт\t" << endl; //вывод значений параметров трубы на консоль
    std::cout << "---------------------------------------------------------------------------" << endl; //вывод данной "строки" на консоль
    std::cout << Obj.name << '\t' << Obj.lenght << '\t' << Obj.diametr << '\t' << Obj.repair << endl;

}

//вывод параметров КС
void ShowCS(const CS& Obj)
{
    std::cout << "Имя\t" << "Цехи\t" << "В работе" << " Эффективность\t" << endl;//вывод значений параметров КС на консоль
    std::cout << "---------------------------------------------------------------------------" << endl;//вывод данной "строки" на консоль
    std::cout << Obj.name << '\t' << Obj.countWS << '\t' << Obj.actWS << '\t' << Obj.eff << endl;
}

//редактирование параметров трубы
void EditPipe(pipe& Obj)
{
    int click = 0;
    do {
    system("cls");//очищаем экран
    std::cout  << "1. Ремонт\n" << "0. Выход\n" << ">";
    click = Get_variant1(4); // получаем номер выбранного пункта меню
    switch (click) {
    case 1:
        std::cout << "Текущий Ремонт: " << Obj.repair << "\n";
        std::cout << "Ремонт (0 или 1): ";
        Obj.repair = Get_variant1(1);
        break;
    case 0:
        break;
    }
    } while (click != 0);
}

//редактирование параметров КС
void EditCS(CS& Obj)
{
    int click = 0;
    do {
        system("cls");//очищаем экран
        std::cout << "Что редактируем?\n" << "1. Кол-во цехов в работе\n" << "0. Выход\n" << ">";
        click = Get_variant1(4);// получаем номер выбранного пункта меню
        switch (click) {
        case 1:
            std::cout << "Текущее кол-во цехов в работе: " << Obj.actWS << "\n";
            std::cout << "Новое кол-во цехов в работе: ";
            Obj.actWS = Get_variant1(100000);
            while (Obj.countWS < Obj.actWS) {
                std::cout << "Количество цехов в работе должно быть меньше либо равно общему количеству цехов!" << endl;
                Obj.actWS = Get_variant1(100000);
            }
            break;
        case 0:
            break;
        }
    } while (click != 0);
}

//сохранение данных в файлик
void Save(const pipe& Obj1, const CS& Obj2)
{
    ofstream fout("C:\\Users\\student\\Desktop\\laba01-main\\mas.txt");//записываент данные в файл данных
    if (Obj1.lenght != 0) {
        fout <<0<< Obj1.name << "\n" << Obj1.lenght << "\n" << Obj1.diametr << "\n" << Obj1.repair << endl;
    }
    if (Obj2.countWS != 0) {
        fout <<1<< Obj2.name << "\n" << Obj2.countWS << "\n" << Obj2.actWS << "\n" << Obj2.eff << endl;
    }
    fout.close();
}

void Upload(pipe& Obj1, CS& Obj2)
{
    ifstream fin("C:\\Users\\student\\Desktop\\laba01-main\\mas.txt");//считывает данные из файла данных
    string buff;
    // функция is_open(),открытие файла для записи в него
    if (!fin.is_open()) // если файл не открыт
        std::cout << "Файл не может быть открыт!\n";
    else {
        int i = 0;
        int q;
        while (i <= 1) {
            fin >> q;
            if (q == 0) {
                fin >> ws;
                fin >> Obj1.lenght;
                fin >> Obj1.diametr;
                fin >> Obj1.repair;
            }

            else if (q == 1) {
                fin >> ws;
                std::getline(fin, Obj2.name);
                fin >> Obj2.countWS;
                fin >> Obj2.actWS;
                fin >> Obj2.eff;
            }
            i++;
        }

        fin.close(); // закрываем файл  
        return;
    }
}

int main() //вызов функции main()
{
    setlocale(0, ""); //вывод на консоль на русском языке
    int click;

    pipe p = { "0", 0, 0, 0 };
    CS CS = { "0", 0, 0, 0 };

    do
    {
        print_menu();
        click = Get_variant1(7);// получаем номер выбранного пункта меню

        switch (click) {
        case 1: {
            p = AddPipe();
            break;
        }
        case 2: {
            CS = AddCS();
            break;
        }

        case 3: {
            system("cls");
            std::cout << "Просмотр всех объектов\n\n";
            ShowPipe(p);
            std::cout << "\n";
            ShowCS(CS);
            break;
        }

        case 4: {
            EditPipe(p);
            break;
        }

        case 5: {
            EditCS(CS);
            break;
        }
        case 6: {
            Save(p, CS);
            break;
        }

        case 7: {
            Upload(p, CS);
            break;
        }
        }

        if (click != 0) system("pause");//(!=)-неравенство 
    } while (click != 0);
    return 0;
}





