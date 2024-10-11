#include<iostream>
using namespace std;
#define MAX 1000

//菜单界面
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

struct Person {  //联系人结构体
	string m_name;
	int m_Sex;	//1 男 2 女
	int M_age;	//年龄
	string m_Phone;	//电话
	string M_Addr;	//住址

};

struct Addressbooks {	

	struct Person personArray[MAX];	//保存联系人数组

	int m_Size;	//当前联系人个数
};//设计通讯录结构体

//1.添加联系人
void addPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加。" << endl;
		return;
	}
	else {
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;

		abs->personArray[abs->m_Size].m_name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;

		int sex = 0;
		
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;

				break;
			}
			else {
				cout << "无法识别的性别，请重新输入" << endl;
			}
		}
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].M_age = age;

		//联系电话
		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;

		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].M_Addr = address;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;


	}
};

void showPerson(Addressbooks* abs) {
	//判断通讯录中人数是否为0，如果为0，提示记录为空。
	if (abs->m_Size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名:" << abs->personArray[i].m_name << "\t";
			cout << "性别:" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄:" << abs->personArray[i].M_age << "\t";
			cout << "电话:" << abs->personArray[i].m_Phone << "\t";
			cout << "住址:" << abs->personArray[i].M_Addr << endl;
		}
	}
	system("pause");
	system("cls");
} //显示联系人

//检测联系人是否存在
int isExist(Addressbooks* abs, string name) {

	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_name == name) {
			return i;  //找到了，返回这个人在数组中的下标编号。
		}
	}
	return -1;
}

//删除联系人
void deletePerson(Addressbooks* abs) {
	cout << "请输入你要删除的联系人：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];  //数据前移
		}

		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else {

		cout << "查无此人" << endl;

	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(Addressbooks* abs) {
	cout << "请输入您要要查找的联系人" << endl;
	string name;
	cin >> name;
	int res = isExist(abs, name);

	if (res != -1) {
		cout << "姓名:" << abs->personArray[res].m_name << "\t";
		cout << "性别:" << (abs->personArray[res].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄:" << abs->personArray[res].M_age << "\t";
		cout << "电话:" << abs->personArray[res].m_Phone << "\t";
		cout << "住址:" << abs->personArray[res].M_Addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//修改指定联系人信息
void modifyPerson(Addressbooks* abs) {
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;

		abs->personArray[ret].m_name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;

		int sex = 0;
		
		while (true) {
			cin >> sex;

			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;

				break;
			}
			else {
				cout << "无法识别的性别，请重新输入" << endl;
			}
		}
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].M_age = age;

		//联系电话
		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;

		abs->personArray[ret].m_Phone = phone;

		//住址
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].M_Addr = address;
	}
	else {
		cout << "查无此人" << endl;
	}
}

//清空联系人
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;

	system("pause");
	system("cls");
}

int main() {

	Addressbooks abs; 

	abs.m_Size = 0;	//通讯录内容个数赋值

	int select = 0;//创建用户选择输入的对象

	 //菜单调用

	
	while (true) {		//限制退出程序循环

		showMenu();

		cin >> select;

		switch (select) {
		case 1:  //添加联系人
			addPerson(&abs);

			break;
		case 2: //显示联系人
			showPerson(&abs);

			break;
		case 3:  //删除联系人
			deletePerson(&abs);

			break;
		case 4:  //查找联系人
			findPerson(&abs);

			break;
		case 5:  //修改联系人
			modifyPerson(&abs);

			break;
		case 6:  //清空联系人
			cleanPerson(&abs);

			break;
		case 0:  //退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		}

		
	}
	
	system("cls");
	system("pause");	
	return 0;
}