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
            std::cin.ignore(100000, '\n');//
            std::cout << "������� �� ���������� �����.��������� �������: ";
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
        std::cout << "������� �� ���������� �����.��������� �������: ";
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
    std::cout << "����� (�): ";
    Obj.lenght = Get_variant1(100000);
    while (Obj.lenght <= 0) {
        std::cout << "����� ������ ���� ������ 0!" << endl;
        Obj.lenght = Get_variant1(100000);
    }
    std::cout << "������� (��): ";
    Obj.diametr = Get_variant1(100000);
    while (Obj.diametr <= 0) {
        std::cout << "������� ������ ���� ������ 0!" << endl;
        Obj.diametr = Get_variant1(100000);
    }
    std::cout << "������ (0-�� ����� ��� 1-�����): ";
    Obj.repair = Get_variant1(1);
    return Obj;
}

//���������� ��
CS AddCS()
{
    CS Obj;
    system("cls");//������� �����
    std::cout << "���������� ��\n";
    std::cout << "��� ��:\n";
        std::getline(cin, Obj.name);
    std::cout << "���-�� �����: ";
    Obj.countWS = Get_variant1(100000);
    while (Obj.countWS <= 0) {
        std::cout << "���-�� ����� ������ ���� ������ 0!" << endl;
        Obj.countWS = Get_variant1(100000);
    }
    std::cout << "���-�� ����� � ������: ";
    Obj.actWS = Get_variant1(100000);
    while (Obj.countWS < Obj.actWS) {
        std::cout << "���������� ����� � ������ �� ����� ���� ������ ������ ���������� �����!" << endl;
        Obj.actWS = Get_variant1(100000);
    }
    std::cout << "�������������(0-1): ";
    Obj.eff = Get_variant2(1);
    return Obj;
}

//����� ���������� �����
void ShowPipe(const pipe& Obj)
{
    std::cout << "�����\t" << "�������\t" << "������\t" << endl; //����� �������� ���������� ����� �� �������
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
    std::cout  << "1. ������\n" << "0. �����\n" << ">";
    click = Get_variant1(4); // �������� ����� ���������� ������ ����
    switch (click) {
    case 1:
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
        std::cout << "��� �����������?\n" << "1. ���-�� ����� � ������\n" << "0. �����\n" << ">";
        click = Get_variant1(4);// �������� ����� ���������� ������ ����
        switch (click) {
        case 1:
            std::cout << "������� ���-�� ����� � ������: " << Obj.actWS << "\n";
            std::cout << "����� ���-�� ����� � ������: ";
            Obj.actWS = Get_variant1(100000);
            while (Obj.countWS < Obj.actWS) {
                std::cout << "���������� ����� � ������ ������ ���� ������ ���� ����� ������ ���������� �����!" << endl;
                Obj.actWS = Get_variant1(100000);
            }
            break;
        case 0:
            break;
        }
    } while (click != 0);
}

//���������� ������ � ������
void Save(const pipe& Obj1, const CS& Obj2)
{
    ofstream fout("C:\\Users\\student\\Desktop\\laba01-main\\mas.txt");//����������� ������ � ���� ������
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
    ifstream fin("C:\\Users\\student\\Desktop\\laba01-main\\mas.txt");//��������� ������ �� ����� ������
    string buff;
    // ������� is_open(),�������� ����� ��� ������ � ����
    if (!fin.is_open()) // ���� ���� �� ������
        std::cout << "���� �� ����� ���� ������!\n";
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





