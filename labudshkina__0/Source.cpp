#include <iostream> //����������,������� �������� ������ ����� � ������
#include <string>  //��� string ����������� ��� �������� ����� 
#include <fstream> //����������,������� �������� ������,������� ��������������� ������/������ �� �����/������ � ����

using namespace std; //�������� ����������� ,��� �� ����� ����������� ���,��� ��������� � ������������ std

struct pipe //������� ��������� � ������ pipe
{
    string name;
    int lenght;
    int diametr;
    bool repair;//bool - ���������� ���.���������� ����� ���� ����� �������� true or false
};

struct CS //������� ��������� � ������ cs
{
    string name;
    int countWS;
    int actWS;
    float eff; //float- ������������ ������������ ����� ������� �������� � ��������� ������
};

void print_menu()
{
    system("cls"); //������� �����
    std::cout << "1. �������� �����\n";
    std::cout << "2. �������� ��\n";
    std::cout << "3. �������� ���� ��������\n";
    std::cout << "4. ������������� �����\n";
    std::cout << "5. ������������� ��\n";
    std::cout << "6. ���������\n";
    std::cout << "7. ���������\n";
    std::cout << "0. �����\n";
    std::cout << "\n�������� �������� - ";
}

//������� ��������� ����� ����(�������� ��������� �� ������������� ����� � ������� ���������� ������ � �������� ����� �� ������������)
int Get_variant1(int k)
{
    int z;
        std::cin >> z;
        while ((cin.fail()) || (z < 0) || (z > k) || (cin.get() != '\n')) {//(||)-���������� ��������,���
            std::cin.clear();
            std::cin.ignore(1000000, '\n');//
            std::cout << "������� ���������� �����.��������� �������: ";
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
        std::cout << "������� ���������� �����: ";
        std::cin >> a;
    }
    return a;
}

//���������� �����
pipe AddPipe()
{
    pipe Obj;
    system("cls");//������� �����
    std::cout << "���������� �����\n";
    std::cout << "��������: ";
    std::getline(cin, Obj.name);
    std::cout << "������ (�): ";
    Obj.lenght = Get_variant1(1000000);
    while (Obj.lenght <= 0) {
        std::cout << "������ ������ ���� ������ 0!" << endl;
        Obj.lenght = Get_variant1(1000000);
    }
    std::cout << "������� (��): ";
    Obj.diametr = Get_variant1(1000000);
    while (Obj.diametr <= 0) {
        std::cout << "������� ������ ���� ������ 0!" << endl;
        Obj.diametr = Get_variant1(1000000);
    }
    std::cout << "������ (0 ��� 1): ";
    Obj.repair = Get_variant1(1);
    return Obj;
}

//���������� ��
CS AddCS()
{
    CS Obj;
    system("cls");//������� �����
    std::cout << "���������� ��\n";
    std::cout << "��������: ";
    std::getline(cin, Obj.name);
    std::cout << "���-�� �����: ";
    Obj.countWS = Get_variant1(1000000);
    while (Obj.countWS <= 0) {
        std::cout << "���-�� ����� ������ ���� ������ 0!" << endl;
        Obj.countWS = Get_variant1(1000000);
    }
    std::cout << "���-�� ����� � ������: ";
    Obj.actWS = Get_variant1(1000000);
    while (Obj.countWS < Obj.actWS) {
        std::cout << "���������� ����� � ������ ������ ���� ������ ���� ����� ������ ���������� �����!" << endl;
        Obj.actWS = Get_variant1(1000000);
    }
    std::cout << "�������������(0-1): ";
    Obj.eff = Get_variant2(1);
    return Obj;
}

//����� ���������� �����
void ShowPipe(const pipe& Obj)
{
    std::cout << "���\t" << "�����\t" << "�������\t" << "������\t" << endl; //����� �������� ���������� ����� �� �������
    std::cout << "---------------------------------------------------------------------------" << endl; //����� ������ "������" �� �������
    std::cout << Obj.name << '\t' << Obj.lenght << '\t' << Obj.diametr << '\t' << Obj.repair << endl;

}

//����� ���������� ��
void ShowCS(const CS& Obj)
{
    std::cout << "���\t" << "����\t" << "� ������" << " �������������\t" << endl;//����� �������� ���������� �� �� �������
    std::cout << "---------------------------------------------------------------------------" << endl;//����� ������ "������" �� �������
    std::cout << Obj.name << '\t' << Obj.countWS << '\t' << Obj.actWS << '\t' << Obj.eff << endl;
}

//�������������� ���������� �����
void EditPipe(pipe& Obj)
{
    int click = 0;
    do {
    system("cls");//������� �����
    std::cout << "��� �����������?\n" << "1. ���\n" << "2. ������\n" << "3. �������\n" << "4. ������\n" << "0. �����\n" << ">";
    click = Get_variant1(4); // �������� ����� ���������� ������ ����
    switch (click) {
    case 1:
        std::cout << "������� ���: " << Obj.name << "\n";
        std::cout << "����� ���: ";
        std::getline(cin, Obj.name);
        break;
    case 2:
        std::cout << "������� ������: " << Obj.lenght << "\n";
        std::cout << "����� ������ (�): ";
        Obj.lenght = Get_variant1(1000000);
        while (Obj.lenght <= 0) {
            std::cout << "������ ������ ���� ������ 0!" << endl;
            Obj.lenght = Get_variant1(1000000);
        }
        break;
    case 3:
        std::cout << "������� �������: " << Obj.diametr << "\n";
        std::cout << "����� ������� (��): ";
        Obj.diametr = Get_variant1(1000000);
        while (Obj.diametr <= 0) {
            std::cout << "������� ������ ���� ������ 0!" << endl;
            Obj.diametr = Get_variant1(1000000);
        }
        break;
    case 4:
        std::cout << "������� ������: " << Obj.repair << "\n";
        std::cout << "������ (0 ��� 1): ";
        Obj.repair = Get_variant1(1);
        break;
    case 0:
        break;
    }
    } while (click != 0);
}

//�������������� ���������� ��
void EditCS(CS& Obj)
{
    int click = 0;
    do {
        system("cls");//������� �����
        std::cout << "��� �����������?\n" << "1. ���\n" << "2. ���-�� �����\n" << "3. ���-�� ����� � ������\n" << "4. �������������\n" << "0. �����\n" << ">";
        click = Get_variant1(4);// �������� ����� ���������� ������ ����
        switch (click) {
        case 1:
            std::cout << "������� ���: " << Obj.name << "\n";
            std::cout << "����� ���: ";
            getline(cin, Obj.name);
            break;
        case 2:
            std::cout << "������� ���-�� �����: " << Obj.countWS << "\n";
            std::cout << "����� ���-�� �����: ";
            Obj.countWS = Get_variant1(1000000);
            while (Obj.countWS <= 0) {
                std::cout << "���-�� ����� ������ ���� ������ 0!" << endl;
                Obj.countWS = Get_variant1(1000000);
            }
            break;
        case 3:
            std::cout << "������� ���-�� ����� � ������: " << Obj.actWS << "\n";
            std::cout << "����� ���-�� ����� � ������: ";
            Obj.actWS = Get_variant1(1000000);
            while (Obj.countWS < Obj.actWS) {
                std::cout << "���������� ����� � ������ ������ ���� ������ ���� ����� ������ ���������� �����!" << endl;
                Obj.actWS = Get_variant1(1000000);
            }
            break;
        case 4:
            std::cout << "������� �������������: " << Obj.eff << "\n";
            std::cout << "����� �������������: ";
            Obj.eff = Get_variant2(1);
            break;
        case 0:
            break;
        }
    } while (click != 0);
}

//���������� ������ � ������
void Save(const pipe& Obj1, const CS& Obj2)
{
    ofstream fout("C:\\Users\\��� ��\\Desktop\\laaba\\laba01\\mas.txt");//����������� ������ � ���� ������
    fout << Obj1.name << " " << Obj1.lenght << " " << Obj1.diametr << " " << Obj1.repair << endl;
    fout << Obj2.name << " " << Obj2.countWS << " " << Obj2.actWS << " " << Obj2.eff << endl;
    fout.close();
}


void Upload(pipe& Obj1, CS& Obj2)
{
    ifstream fin("C:\\Users\\��� ��\\Desktop\\laaba\\laba01\\mas.txt");//��������� ������ �� ����� ������
    string buff;
    if (!fin.is_open()) // ���� ���� �� ������
        std::cout << "���� �� ����� ���� ������!\n";
    else {

        std::getline(fin, Obj1.name, '/');
        std::getline(fin, buff, '/');
        if (stoi(buff) <= 0) {
            std::cout << "���� �� ��������� 1!" << endl;
            return;
        }
        else {
            Obj1.lenght = stoi(buff);
        }
        std::getline(fin, buff, '/');
        if (stoi(buff) <= 0) {
            std::cout << "���� �� ��������� 2!" << endl;
            return;
        }
        else {
            Obj1.diametr = stoi(buff);
        }
        std::getline(fin, buff);
        if ((stoi(buff) < 0) || (stoi(buff) > 1)) {
            std::cout << "���� �� ��������� 3!" << endl;
            return;
        }
        else {
            Obj1.repair = stoi(buff);
        }

        std::getline(fin, Obj2.name, '/');
        std::getline(fin, buff, '/');
        if (stoi(buff) <= 0) {
            std::cout << "���� �� ��������� 4!" << endl;
            return;
        }
        else {
            Obj2.countWS = stoi(buff);
        }
        std::getline(fin, buff, '/');
        if (Obj2.countWS < stoi(buff)) {
            std::cout << "���� �� ��������� 5!" << endl;
            return;
        }
        else {
            Obj2.actWS = stoi(buff);
        }
        std::getline(fin, buff);
        if ((stof(buff) < 0) || (stof(buff) > 1)) {
            std::cout << "���� �� ��������� 6!" << endl;
            return;
        }
        else {
            Obj2.eff = stof(buff);
        }

        fin.close(); // ��������� ����  
        return;
    }
}

int main() //����� ������� main()
{
    setlocale(0, ""); //����� �� ������� �� ������� �����
    int click;

    pipe p = { "0", 0, 0, 0 };
    CS CS = { "0", 0, 0, 0 };

    do
    {
        print_menu();
        click = Get_variant1(7);// �������� ����� ���������� ������ ����

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
            std::cout << "�������� ���� ��������\n\n";
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

        if (click != 0) system("pause");//(!=)-����������� 
    } while (click != 0);
    return 0;
}





