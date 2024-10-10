#include<iostream>
using namespace std;
#define MAX 1000

//�˵�����
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

struct Person {  //��ϵ�˽ṹ��
	string m_name;
	int m_Sex;	//1 �� 2 Ů
	int M_age;	//����
	string m_Phone;	//�绰
	string M_Addr;	//סַ

};

struct Addressbooks {	

	struct Person personArray[MAX];	//������ϵ������

	int m_Size;	//��ǰ��ϵ�˸���
};//���ͨѶ¼�ṹ��

//1.�����ϵ��
void addPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷���ӡ�" << endl;
		return;
	}
	else {
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;

		abs->personArray[abs->m_Size].m_name = name;

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;

		int sex = 0;
		cin >> sex;
		while (true) {
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;

				break;
			}
			else {
				cout << "�޷�ʶ����Ա�����������" << endl;
			}
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].M_age = age;

		//��ϵ�绰
		cout << "��������ϵ�绰" << endl;
		string phone;
		cin >> phone;

		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].M_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;


	}
};

void showPerson(Addressbooks* abs) {
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ�ա�
	if(abs->m_Size == 0){
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "����:" << abs->personArray[i].m_name<<"\t";
			cout << "�Ա�:" <<( abs->personArray[i].m_Sex == 1 ? "��":"Ů") << "\t";
			cout << "����:" << abs->personArray[i].M_age<<"\t";
			cout << "�绰:" << abs->personArray[i].m_Phone<< "\t";
			cout << "סַ:" << abs->personArray[i].M_Addr << endl;
		}
	}
	system("pause");
	system("cls");
} //��ʾ��ϵ��

int main() {

	Addressbooks abs;

	abs.m_Size = 0;	//ͨѶ¼���ݸ�����ֵ

	int select = 0;//�����û�ѡ������Ķ���

	 //�˵�����

	
	while (true) {		//�����˳�����ѭ��

		showMenu();

		cin >> select;

		switch (select) {
		case 1:  //�����ϵ��
			addPerson(&abs);

			break;
		case 2: //��ʾ��ϵ��
			showPerson(&abs);

			break;
		case 3:  //ɾ����ϵ��
			break;
		case 4:  //������ϵ��
			break;
		case 5:  //�޸���ϵ��
			break;
		case 6:  //�����ϵ��
			break;
		case 0:  //�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		}

		
	}
	
	system("cls");
	system("pause");	
	return 0;
}