#include <WinSock2.h>
#include <Windows.h>
#include "mysql.h"    //引入mysql头文件
#include <iostream>
#include<iomanip>
using namespace std;
const char DataBase_UserName[] = "root";    //数据库用户名username
const char DataBase_Password[] = "123456";   //数据库密码，填自己的密码
const char DataBase_Host[] = "localhost";  //数据库连接地址
const char DataBase_Name[] = "test_1";  //database name
unsigned int DataBase_Port = 3306;
MYSQL mysql; // mysql连接
MYSQL_FIELD* fd; // 字段列数组
char field[32][32]; // 存字段名二维数组
MYSQL_RES* res; // 这个结构代表返回行的一个查询结果集
MYSQL_ROW column; // 一个行数据的类型安全(type-safe)的表示，表示数据行的列
char sql[1000]; // sql语句
class carmanage {
public:
	carmanage() {}
	bool ConnectDatabase(); // 连接数据库
	void FreeConnect(); // 释放资源
	bool QueryDatabase1(); // 查询1
	bool QueryDatabase2(); // 查询2
	bool QueryDatabase3(); // 查询3
	bool InsertData1(); // 插入数据1
	bool InsertData2(); // 插入数据2
	bool InsertData3(); // 插入数据3
	bool DeleteData1(); // 删除数据
	bool DeleteData2(); // 删除数据
	bool DeleteData3(); // 删除数据
	bool SeekData1();//查找数据
	bool SeekData2();//查找数据
	bool SeekData3();//查找数据
	bool ModifyData1();//修改数据
	bool ModifyData2();//修改数据
	bool ModifyData3();//修改数据
};
bool carmanage::ConnectDatabase()
{
	//初始化mysql
	mysql_init(&mysql);   //连接mysql，数据库
	if (!(mysql_real_connect(&mysql, DataBase_Host, DataBase_UserName, DataBase_Password, DataBase_Name, DataBase_Port, NULL, 0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去
	{
		printf("Error connecting to database:%s\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		MessageBoxA(NULL, "连接MYSQL数据成功！", "消息", MB_OK);
		printf("Connected...\n");
		return true;
	}
}
void carmanage::FreeConnect() // 释放资源
{
	cout << "释放数据库资源..." << endl;
	mysql_free_result(res);
	mysql_close(&mysql);
}
bool carmanage::QueryDatabase1()
{
	sprintf_s(sql, "select *from car");
	mysql_query(&mysql, "set names gbk"); // 设置编码格式
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "查询失败：" << mysql_error(&mysql) << endl;
		return false; // 查询失败
	}
	else
	{
		cout << "查询成功..." << endl; // 查询成功
	}
	if (!(res = mysql_store_result(&mysql))) // 获取结果集
	{
		cout << "查询对象失败：" << mysql_error(&mysql) << endl;
		return false; // 查询对象失败
	}
	cout << "数据行数：" << mysql_affected_rows(&mysql) << endl; // 打印数据行数
	char* str_field[32]; // 定义一个字符串数组存储字段信息
	for (int i = 0; i < 6; i++) // 在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	for (int i = 0; i < 6; i++) // 输出查询信息
	{
		cout << setw(10) << str_field[i] << " ";
	}
	cout << endl;
	while (column = mysql_fetch_row(res)) // 在已知字段数量情况下，获取并打印下一行
	{
		cout << setw(10) << column[0] << " ";
		cout << setw(10) << column[1] << " ";
		cout << setw(10) << column[2] << " ";
		cout << setw(10) << column[3] << " ";
		cout << setw(10) << column[4] << " ";
		cout << setw(10) << column[5] << endl;
	}
	return true; // 查询成功
}
bool carmanage::QueryDatabase2()
{
	sprintf_s(sql, "select *from staff");
	mysql_query(&mysql, "set names gbk"); // 设置编码格式
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "查询失败：" << mysql_error(&mysql) << endl;
		return false; // 查询失败
	}
	else
	{
		cout << "查询成功..." << endl; // 查询成功
	}
	if (!(res = mysql_store_result(&mysql))) // 获取结果集
	{
		cout << "查询对象失败：" << mysql_error(&mysql) << endl;
		return false; // 查询对象失败
	}
	cout << "数据行数：" << mysql_affected_rows(&mysql) << endl; // 打印数据行数
	char* str_field[32]; // 定义一个字符串数组存储字段信息
	for (int i = 0; i < 4; i++) // 在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	for (int i = 0; i < 4; i++) // 输出查询信息
	{
		cout << setw(10) << str_field[i] << " ";
	}
	cout << endl;
	while (column = mysql_fetch_row(res)) // 在已知字段数量情况下，获取并打印下一行
	{
		cout << setw(10) << column[0] << " ";
		cout << setw(10) << column[1] << " ";
		cout << setw(10) << column[2] << " ";
		cout << setw(10) << column[3] << endl;
	}
	return true; // 查询成功
}
bool carmanage::QueryDatabase3()
{
	sprintf_s(sql, "select *from sale");
	mysql_query(&mysql, "set names gbk"); // 设置编码格式
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "查询失败：" << mysql_error(&mysql) << endl;
		return false; // 查询失败
	}
	else
	{
		cout << "查询成功..." << endl; // 查询成功
	}
	if (!(res = mysql_store_result(&mysql))) // 获取结果集
	{
		cout << "查询对象失败：" << mysql_error(&mysql) << endl;
		return false; // 查询对象失败
	}
	cout << "数据行数：" << mysql_affected_rows(&mysql) << endl; // 打印数据行数
	char* str_field[32]; // 定义一个字符串数组存储字段信息
	for (int i = 0; i < 5; i++) // 在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	for (int i = 0; i < 5; i++) // 输出查询信息
	{
		cout << setw(10) << str_field[i] << " ";
	}
	cout << endl;
	while (column = mysql_fetch_row(res)) // 在已知字段数量情况下，获取并打印下一行
	{
		cout << setw(10) << column[0] << " ";
		cout << setw(10) << column[1] << " ";
		cout << setw(10) << column[2] << " ";
		cout << setw(10) << column[3] << " ";
		cout << setw(10) << column[4] << endl;
	}
	return true; // 查询成功
}
bool carmanage::InsertData1()//插入函数
{
	int id_ca=0;
	int price=0;
	char model[50];
	char colour[50];
	char manufacturer[50];
	char data[50];
	cout << "请输入ID" << endl;
	cin >> id_ca;
	cout << "请输入型号" << endl;
	cin >> model;
	cout << "请输入颜色" << endl;
	cin >> colour;
	cout << "请输入制造商" << endl;
	cin >> manufacturer;
	cout << "请输入出厂日期" << endl;
	cin >> data;
	cout << "请输入售价" << endl;
	cin >> price;
	sprintf_s(sql,1000, "insert into car values (%d,'%s','%s','%s','%s', %d)",
		id_ca,model,colour,manufacturer,data,price);
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "插入失败：" << mysql_error(&mysql) << endl;
		return false;
	}
	else
	{
		cout << "插入成功..." << endl;
		return true;
	}
}
bool carmanage::InsertData3()//插入函数
{
	char data[50];
	int price = 0;
	int id_c = 0;
	int id_ca = 0;
	int id_s = 0;
	cout << "请输入出售日期" << endl;
	cin >> data;
	cout << "请输入售价" << endl;
	cin >> price;
	cout << "请输入此次销售记录ID" << endl;
	cin >> id_c;
	cout << "请输入出售车辆ID" << endl;
	cin >> id_ca;
	cout << "请输入售货员职工ID" << endl;
	cin >> id_s;
	sprintf_s(sql, 1000, "insert into sale values ('%s',%d,%d,%d,%d)",
		data,price,id_c,id_ca,id_s);
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "插入失败：" << mysql_error(&mysql) << endl;
		return false;
	}
	else
	{
		cout << "插入成功..." << endl;
		return true;
	}
}
bool carmanage::InsertData2()//插入函数
{
	int id_s = 0;
	int age = 0;
	char name[50];
	char sex[50];
	cin >> id_s;
	cout << "next" << endl;
	cin >> name;
	cout << "next" << endl;
	cin >> age;
	cout << "next" << endl;
	cin >> sex;
	sprintf_s(sql, 1000, "insert into staff values (%d,'%s','%d','%s')",
		id_s,name,age,sex);
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "插入失败：" << mysql_error(&mysql) << endl;
		return false;
	}
	else
	{
		cout << "插入成功..." << endl;
		return true;
	}
}
bool carmanage::DeleteData1()//删除数据
{
	int id = 0;
	cout << "要删除数据ID为：" << endl;
	cin >> id;
	sprintf_s(sql, "delete from car where id_ca=%d;",id);
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "删除失败：" << mysql_error(&mysql) << endl;
		return false;
	}
	else
	{
		cout << "删除成功..." << endl;
		return true;
	}
}
bool carmanage::DeleteData2()//删除数据
{
	int id = 0;
	cout << "要删除数据ID为："<<endl;
	cin >> id;
	sprintf_s(sql, "delete from staff where id_s=%d;",id);
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "删除失败：" << mysql_error(&mysql) << endl;
		return false;
	}
	else
	{
		cout << "删除成功..." << endl;
		return true;
	}
}
bool carmanage::DeleteData3()//删除数据
{
	int id = 0;
	cout << "要删除数据ID为：" << endl;
	cin >> id;
	sprintf_s(sql, "delete from staff where id_c=%d;", id);
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "删除失败：" << mysql_error(&mysql) << endl;
		return false;
	}
	else
	{
		cout << "删除成功..." << endl;
		return true;
	}
}
bool carmanage::SeekData1()//查找数据
{
	int id = 0;
	cout << "输入id" << endl;
	cin >> id;
	sprintf_s(sql, "select *from car where id_ca=%d", id);
	mysql_query(&mysql, "set names gbk"); // 设置编码格式
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "查询失败：" << mysql_error(&mysql) << endl;
		return false; // 查询失败
	}
	else
	{
		cout << "查询成功..." << endl; // 查询成功
	}
	if (!(res = mysql_store_result(&mysql))) // 获取结果集
	{
		cout << "查询对象失败：" << mysql_error(&mysql) << endl;
		return false; // 查询对象失败
	}
	cout << "数据行数：" << mysql_affected_rows(&mysql) << endl; // 打印数据行数
	char* str_field[32]; // 定义一个字符串数组存储字段信息
	for (int i = 0; i < 6; i++) // 在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	for (int i = 0; i < 6; i++) // 输出查询信息
	{
		cout << setw(10) << str_field[i] << " ";
	}
	cout << endl;
	while (column = mysql_fetch_row(res)) // 在已知字段数量情况下，获取并打印下一行
	{
		cout << setw(10) << column[0] << " ";
		cout << setw(10) << column[1] << " ";
		cout << setw(10) << column[2] << " ";
		cout << setw(10) << column[3] << " ";
		cout << setw(10) << column[4] << " ";
		cout << setw(10) << column[5] << endl;
	}
	return true; // 查询成功
}
bool carmanage::SeekData2()//查找数据
{
	int id;
	cout << "请输入查找人员的职工ID" << endl;
	cin >> id;
	sprintf_s(sql, "select *from staff where id_s=%d",id);
	mysql_query(&mysql, "set names gbk"); // 设置编码格式
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "查询失败：" << mysql_error(&mysql) << endl;
		return false; // 查询失败
	}
	else
	{
		cout << "查询成功..." << endl; // 查询成功
	}
	if (!(res = mysql_store_result(&mysql))) // 获取结果集
	{
		cout << "查询对象失败：" << mysql_error(&mysql) << endl;
		return false; // 查询对象失败
	}
	cout << "数据行数：" << mysql_affected_rows(&mysql) << endl; // 打印数据行数
	char* str_field[32]; // 定义一个字符串数组存储字段信息
	for (int i = 0; i < 4; i++) // 在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	for (int i = 0; i < 4; i++) // 输出查询信息
	{
		cout << setw(10) << str_field[i] << " ";
	}
	cout << endl;
	while (column = mysql_fetch_row(res)) // 在已知字段数量情况下，获取并打印下一行
	{
		cout << setw(10) << column[0] << " ";
		cout << setw(10) << column[1] << " ";
		cout << setw(10) << column[2] << " ";
		cout << setw(10) << column[3] << endl;
	}
	return true; // 查询成功
}
bool carmanage::SeekData3()//查找数据
{
	int id;
	cout << "请输入查询的单号ID" << endl;
	cin >> id;
	sprintf_s(sql, "select *from sale where id_c=%d",id);
	mysql_query(&mysql, "set names gbk"); // 设置编码格式
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "查询失败：" << mysql_error(&mysql) << endl;
		return false; // 查询失败
	}
	else
	{
		cout << "查询成功..." << endl; // 查询成功
	}
	if (!(res = mysql_store_result(&mysql))) // 获取结果集
	{
		cout << "查询对象失败：" << mysql_error(&mysql) << endl;
		return false; // 查询对象失败
	}
	cout << "数据行数：" << mysql_affected_rows(&mysql) << endl; // 打印数据行数
	char* str_field[32]; // 定义一个字符串数组存储字段信息
	for (int i = 0; i < 5; i++) // 在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	for (int i = 0; i < 5; i++) // 输出查询信息
	{
		cout << setw(10) << str_field[i] << " ";
	}
	cout << endl;
	while (column = mysql_fetch_row(res)) // 在已知字段数量情况下，获取并打印下一行
	{
		cout << setw(10) << column[0] << " ";
		cout << setw(10) << column[1] << " ";
		cout << setw(10) << column[2] << " ";
		cout << setw(10) << column[3] << " ";
		cout << setw(10) << column[4] << endl;
	}
	return true; // 查询成功
}
bool carmanage::ModifyData1()//修改数据
{
	int id_ca = 0;
	int price = 0;
	char model[50];
	char colour[50];
	char manufacturer[50];
	char data[50];
	cout << "请输入ID" << endl;
	cin >> id_ca;
	cout << "请输入型号" << endl;
	cin >> model;
	cout << "请输入颜色" << endl;
	cin >> colour;
	cout << "请输入制造商" << endl;
	cin >> manufacturer;
	cout << "请输入出厂日期" << endl;
	cin >> data;
	cout << "请输入售价" << endl;
	cin >> price;
	sprintf_s(sql, 1000, "update car set model='%s',colour='%s',manufacturer='%s',data='%s',price=%d where id_ca=%d",
		model, colour, manufacturer, data, price,id_ca);
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "修改失败：" << mysql_error(&mysql) << endl;
		return false;
	}
	else
	{
		cout << "修改成功..." << endl;
		return true;
	}
}
bool carmanage::ModifyData2()//修改数据
{
	int id_s = 0;
	int age = 0;
	char name[50];
	char sex[50];
	cout << "请输入ID" << endl;
	cin >> id_s;
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入年龄" << endl;
	cin >> age;
	cout << "请输入性别" << endl;
	cin >> sex;
	sprintf_s(sql, 1000, "update staff set name='%s',age=%d,sex='%s' where id_s=%d",
		name, age, sex,id_s);
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "修改失败：" << mysql_error(&mysql) << endl;
		return false;
	}
	else
	{
		cout << "修改成功..." << endl;
		return true;
	}
}
bool carmanage::ModifyData3()//修改数据
{
	char data[50];
	int price = 0;
	int id_c = 0;
	int id_ca = 0;
	int id_s = 0;
	cout << "请输入出售日期" << endl;
	cin >> data;
	cout << "请输入售价" << endl;
	cin >> price;
	cout << "请输入此次销售记录ID" << endl;
	cin >> id_c;
	cout << "请输入出售车辆ID" << endl;
	cin >> id_ca;
	cout << "请输入售货员职工ID" << endl;
	cin >> id_s;
	sprintf_s(sql, 1000, "update sale set time='%s',price=%d,id_ca=%d,id_s=%d where id_c=%d",
		data,price,id_ca,id_s,id_c);
	if (mysql_query(&mysql, sql)) // 执行SQL语句
	{
		cout << "修改失败：" << mysql_error(&mysql) << endl;
		return false;
	}
	else
	{
		cout << "修改成功..." << endl;
		return true;
	}
}
int main(int argc, char** argv)
{
	int n = 0;
	char ch;
	carmanage a;
	a.ConnectDatabase();//连接数据库
	do
	{
		cout << "************欢迎使用车辆管理系统**********" << endl;
		cout << "__________________________________________" << endl;
		cout << "                  主菜单                  " << endl;
		cout << "1.显示车辆表中信息************************" << endl;
		cout << "2.显示人员表中信息************************" << endl;
		cout << "3.显示销售表中信息************************" << endl;
		cout << "4.插入车辆信息****************************" << endl;
		cout << "5.插入人员信息****************************" << endl;
		cout << "6.插入销售信息****************************" << endl;
		cout << "7.删除车辆表信息**************************" << endl;
		cout << "8.删除人员表信息**************************" << endl;
		cout << "9.删除销售表中信息************************" << endl;
		cout << "A.查找车辆表中数据************************" << endl;
		cout << "B.查找人员表中数据************************" << endl;
		cout << "C.查找销售表中数据************************" << endl;
		cout << "D.修改车辆表中数据************************" << endl;
		cout << "E.修改人员表中数据************************" << endl;
		cout << "F.修改销售表中数据************************" << endl;
		cout << "0.退出主菜单******************************" << endl;
		cout << "__________________________________________" << endl;
		cout << "请选择：";
		cin >> ch;
		switch (ch)
		{
		case '1':a.QueryDatabase1(); break;
		case '2':a.QueryDatabase2(); break;
		case '3':a.QueryDatabase3(); break;
		case '4':a.InsertData1(); break;
		case '5':a.InsertData2(); break;
		case '6':a.InsertData3(); break;
		case '7':a.DeleteData1(); break;
		case '8':a.DeleteData2(); break;
		case '9':a.DeleteData3(); break;
		case 'A':a.SeekData1(); break;
		case 'B':a.SeekData2(); break;
		case 'C':a.SeekData3(); break;
		case 'D':a.ModifyData1(); break;
		case 'E':a.ModifyData2(); break;
		case 'F':a.ModifyData3(); break;
		case '0':a.FreeConnect(); break;//释放存储空间
		default:break;
		}
	} while (n != 0);
	a.FreeConnect();//释放存储空间
}