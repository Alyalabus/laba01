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
            std::cin.ignore(1000000, '\n');//
            std::cout << "Введено корректное число.Повторите попытку: ";
            std::cin >> z;
    }
    return z;
}

float Get_variant2(float n) {
    float a;
    std::cin >> a;
    while ((std::cin.fail()) || (a < 0) || (a > n) || (std::cin.get() != '\n')) {
        std::cin.clear();
        std::cin.ignore(1000000, '\n');
        std::cout << "Введите корректное число: ";
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
    std::cout << "Название: ";
    std::getline(cin, Obj.name);
    std::cout << "Длинна (м): ";
    Obj.lenght = Get_variant1(1000000);
    while (Obj.lenght <= 0) {
        std::cout << "Длинна должна быть больше 0!" << endl;
        Obj.lenght = Get_variant1(1000000);
    }
    std::cout << "Диаметр (мм): ";
    Obj.diametr = Get_variant1(1000000);
    while (Obj.diametr <= 0) {
        std::cout << "Диаметр должен быть больше 0!" << endl;
        Obj.diametr = Get_variant1(1000000);
    }
    std::cout << "Ремонт (0 или 1): ";
    Obj.repair = Get_variant1(1);
    return Obj;
}

//добавление кс
CS AddCS()
{
    CS Obj;
    system("cls");//очищаем экран
    std::cout << "Добавление КС\n";
    std::cout << "Название: ";
    std::getline(cin, Obj.name);
    std::cout << "Кол-во цехов: ";
    Obj.countWS = Get_variant1(1000000);
    while (Obj.countWS <= 0) {
        std::cout << "Кол-во цехов должно быть больше 0!" << endl;
        Obj.countWS = Get_variant1(1000000);
    }
    std::cout << "Кол-во цехов в работе: ";
    Obj.actWS = Get_variant1(1000000);
    while (Obj.countWS < Obj.actWS) {
        std::cout << "Количество цехов в работе должно быть меньше либо равно общему количеству цехов!" << endl;
        Obj.actWS = Get_variant1(1000000);
    }
    std::cout << "Эффективность(0-1): ";
    Obj.eff = Get_variant2(1);
    return Obj;
}

//вывод параметров трубы
void ShowPipe(const pipe& Obj)
{
    std::cout << "Имя\t" << "Длина\t" << "Диаметр\t" << "Ремонт\t" << endl; //вывод значений параметров трубы на консоль
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
    std::cout << "Что редактируем?\n" << "1. Имя\n" << "2. Длинна\n" << "3. Диаметр\n" << "4. Ремонт\n" << "0. Выход\n" << ">";
    click = Get_variant1(4); // получаем номер выбранного пункта меню
    switch (click) {
    case 1:
        std::cout << "Текущее имя: " << Obj.name << "\n";
        std::cout << "Новое имя: ";
        std::getline(cin, Obj.name);
        break;
    case 2:
        std::cout << "Текущая длинна: " << Obj.lenght << "\n";
        std::cout << "Новая длинна (м): ";
        Obj.lenght = Get_variant1(1000000);
        while (Obj.lenght <= 0) {
            std::cout << "Длинна должна быть больше 0!" << endl;
            Obj.lenght = Get_variant1(1000000);
        }
        break;
    case 3:
        std::cout << "Текущий диаметр: " << Obj.diametr << "\n";
        std::cout << "Новый диаметр (мм): ";
        Obj.diametr = Get_variant1(1000000);
        while (Obj.diametr <= 0) {
            std::cout << "Диаметр должен быть больше 0!" << endl;
            Obj.diametr = Get_variant1(1000000);
        }
        break;
    case 4:
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
        std::cout << "Что редактируем?\n" << "1. Имя\n" << "2. Кол-во цехов\n" << "3. Кол-во цехов в работе\n" << "4. Эффективность\n" << "0. Выход\n" << ">";
        click = Get_variant1(4);// получаем номер выбранного пункта меню
        switch (click) {
        case 1:
            std::cout << "Текущее имя: " << Obj.name << "\n";
            std::cout << "Новое имя: ";
            getline(cin, Obj.name);
            break;
        case 2:
            std::cout << "Текущее кол-во цехов: " << Obj.countWS << "\n";
            std::cout << "Новое кол-во цехов: ";
            Obj.countWS = Get_variant1(1000000);
            while (Obj.countWS <= 0) {
                std::cout << "Кол-во цехов должно быть больше 0!" << endl;
                Obj.countWS = Get_variant1(1000000);
            }
            break;
        case 3:
            std::cout << "Текущее кол-во цехов в работе: " << Obj.actWS << "\n";
            std::cout << "Новое кол-во цехов в работе: ";
            Obj.actWS = Get_variant1(1000000);
            while (Obj.countWS < Obj.actWS) {
                std::cout << "Количество цехов в работе должно быть меньше либо равно общему количеству цехов!" << endl;
                Obj.actWS = Get_variant1(1000000);
            }
            break;
        case 4:
            std::cout << "Текущая эффективность: " << Obj.eff << "\n";
            std::cout << "Новая эффективность: ";
            Obj.eff = Get_variant2(1);
            break;
        case 0:
            break;
        }
    } while (click != 0);
}

//сохранение данных в файлик
void Save(const pipe& Obj1, const CS& Obj2)
{
    ofstream fout("C:\\Users\\Мой пк\\Desktop\\laaba\\laba01\\mas.txt");//записываент данные в файл данных
    fout << Obj1.name << " " << Obj1.lenght << " " << Obj1.diametr << " " << Obj1.repair << endl;
    fout << Obj2.name << " " << Obj2.countWS << " " << Obj2.actWS << " " << Obj2.eff << endl;
    fout.close();
}


void Upload(pipe& Obj1, CS& Obj2)
{
    ifstream fin("C:\\Users\\Мой пк\\Desktop\\laaba\\laba01\\mas.txt");//считывает данные из файла данных
    string buff;
    if (!fin.is_open()) // если файл не открыт
        std::cout << "Файл не может быть открыт!\n";
    else {

        std::getline(fin, Obj1.name, '/');
        std::getline(fin, buff, '/');
        if (stoi(buff) <= 0) {
            std::cout << "Файл не корректен 1!" << endl;
            return;
        }
        else {
            Obj1.lenght = stoi(buff);
        }
        std::getline(fin, buff, '/');
        if (stoi(buff) <= 0) {
            std::cout << "Файл не корректен 2!" << endl;
            return;
        }
        else {
            Obj1.diametr = stoi(buff);
        }
        std::getline(fin, buff);
        if ((stoi(buff) < 0) || (stoi(buff) > 1)) {
            std::cout << "Файл не корректен 3!" << endl;
            return;
        }
        else {
            Obj1.repair = stoi(buff);
        }

        std::getline(fin, Obj2.name, '/');
        std::getline(fin, buff, '/');
        if (stoi(buff) <= 0) {
            std::cout << "Файл не корректен 4!" << endl;
            return;
        }
        else {
            Obj2.countWS = stoi(buff);
        }
        std::getline(fin, buff, '/');
        if (Obj2.countWS < stoi(buff)) {
            std::cout << "Файл не корректен 5!" << endl;
            return;
        }
        else {
            Obj2.actWS = stoi(buff);
        }
        std::getline(fin, buff);
        if ((stof(buff) < 0) || (stof(buff) > 1)) {
            std::cout << "Файл не корректен 6!" << endl;
            return;
        }
        else {
            Obj2.eff = stof(buff);
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





