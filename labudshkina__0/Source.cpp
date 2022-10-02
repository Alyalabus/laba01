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
    cout << "1. �������� �����\n";
    cout << "2. �������� ��\n";
    cout << "3. �������� ���� ��������\n";
    cout << "4. ������������� �����\n";
    cout << "5. ������������� ��\n";
    cout << "6. ���������\n";
    cout << "7. ���������\n";
    cout << "0. �����\n";
    cout << "\n�������� �������� - ";
}

//������� ��������� ����� ����(�������� ��������� �� ������������� ����� � ������� ���������� ������ � �������� ����� �� ������������)
int get_variant(int count)
{
    int variant;
    string s; //������ ��� ���������� ��������� ������
    getline(cin, s); //������� ������
    //���� ���� �����������,�������� �� ���� � ������ ��������� ���
    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 0 || variant > count)//(||)-���������� ��������,���
    {
        cout << "������������ ����. ���������� �����: "; //������� ��������� �� ������
        getline(cin, s); //������� ������ ��������
    }
    return variant;
}

//���������� �����
pipe AddPipe()
{
    pipe Obj;
    system("cls");//������� �����
    cout << "���������� �����\n";
    cout << "��������: ";
    cin >> Obj.name;
    cout << "������ (�): ";
    cin >> Obj.lenght;
    cout << "������� (��): ";
    cin >> Obj.diametr;
    cout << "������ (0 ��� 1): ";
    cin >> Obj.repair;
    return Obj;
}

//���������� ��
CS AddCS()
{
    CS Obj;
    system("cls");//������� �����
    cout << "���������� ��\n";
    cout << "��������: ";
    cin >> Obj.name;
    cout << "���-�� �����: ";
    cin >> Obj.countWS;
    cout << "���-�� ����� � ������: ";
    cin >> Obj.actWS;
    cout << "�������������: ";
    cin >> Obj.eff;
    return Obj;
}

//����� ���������� �����
void ShowPipe(const pipe& Obj)
{
    cout << "���\t" << "�����\t" << "�������\t" << "������\t" << endl; //����� �������� ���������� ����� �� �������
    cout << "---------------------------------------------------------------------------" << endl; //����� ������ "������" �� �������
    cout << Obj.name << '\t' << Obj.lenght << '\t' << Obj.diametr << '\t' << Obj.repair << endl;

}

//����� ���������� ��
void ShowCS(const CS& Obj)
{
    cout << "���\t" << "����\t" << "� ������" << " �������������\t" << endl;//����� �������� ���������� �� �� �������
    cout << "---------------------------------------------------------------------------" << endl;//����� ������ "������" �� �������
    cout << Obj.name << '\t' << Obj.countWS << '\t' << Obj.actWS << '\t' << Obj.eff << endl;
}

//�������������� ���������� �����
void EditPipe(pipe& Obj)
{
    system("cls");//������� �����
    cout << "��� �����������?\n" << "1. ���\n" << "2. ������\n" << "3. �������\n" << "4. ������\n" << "0. �����\n" << ">";
    int cursor = get_variant(4); // �������� ����� ���������� ������ ����
    switch (cursor) {
    case 1:
        cout << "������� ���: " << Obj.name << "\n";
        cout << "����� ���: ";
        cin >> Obj.name;
        break;
    case 2:
        cout << "������� ������: " << Obj.lenght << "\n";
        cout << "����� ������ (�): ";
        cin >> Obj.lenght;
        break;
    case 3:
        cout << "������� �������: " << Obj.diametr << "\n";
        cout << "����� ������� (��): ";
        cin >> Obj.diametr;
        break;
    case 4:
        cout << "������� ������: " << Obj.repair << "\n";
        cout << "������ (0 ��� 1): ";
        cin >> Obj.repair;
        break;
    case 0:
        break;
    }
}

//�������������� ���������� ��
void EditCS(CS& Obj)
{
    system("cls");//������� �����
    cout << "��� �����������?\n" << "1. ���\n" << "2. ���-�� �����\n" << "3. ���-�� ����� � ������\n" << "4. �������������\n" << "0. �����\n" << ">";
    int cursor = get_variant(4);// �������� ����� ���������� ������ ����
    switch (cursor) {
    case 1:
        cout << "������� ���: " << Obj.name << "\n";
        cout << "����� ���: ";
        cin >> Obj.name;
        break;
    case 2:
        cout << "������� ���-�� �����: " << Obj.countWS << "\n";
        cout << "����� ���-�� �����: ";
        cin >> Obj.countWS;
        break;
    case 3:
        cout << "������� ���-�� ����� � ������: " << Obj.actWS << "\n";
        cout << "����� ���-�� ����� � ������: ";
        cin >> Obj.actWS;
        break;
    case 4:
        cout << "������� �������������: " << Obj.eff << "\n";
        cout << "����� �������������: ";
        cin >> Obj.eff;
        break;
    case 0:
        break;
    }
}


int main() //����� ������� main()
{
    setlocale(0, ""); //����� �� ������� �� ������� �����
    int cursor;

    pipe p = { "0", 0, 0, 0 };
    CS CS = { "0", 0, 0, 0 };

    do
    {
        print_menu();
        cursor = get_variant(7);// �������� ����� ���������� ������ ����

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
            cout << "�������� ���� ��������\n\n";
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
        if (cursor != 0) system("pause");//(!=)-����������� 
    } while (cursor != 0);
    return 0;
}





