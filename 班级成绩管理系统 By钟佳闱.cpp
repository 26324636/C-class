#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;
 

class Student
{
public :
	void InforInset(Student stu[]); //成绩录入
	void ScoreShow(Student stu[]); //成绩显示
	void SavaDate(Student stu[]);  //输出文件
	void InforRead(Student stu[]); //读取文件
	void InforSort(Student stu[]); //成绩排序
	void AddSum(Student stu[]); //成绩总和
	void Modify(Student stu[]);	//成绩修改
	void Statis(Student stu[]); //成绩统计
	int SearchByID(Student stu[],string id); //通过学号返回数组下标
	
private:
	string ID; //定义学生学号
	string Name; //定义学生姓名
	string Course[20]; //定义课程
	float Mark[20]; //定义课程成绩
	float sum;  //定义成绩总和
	float Aver; //定义个人平均成绩
	float aver; //定义各课程平均成绩	
};

int N = 0; //学生数量
int Num = 0; //课程数量
string Password = "26324636"; //密码
void displayIndex();

/*主程序*/
int main()
{
	int fun;
	char returnFlag[5];
	Student st[20];
	Student stu;
	stu.InforRead(st);
	while(1)
	{
		displayIndex();
		cout <<  "请输入选项：";
		cin >> fun;
		switch (fun)
		{
		case 1 :
			stu.InforInset(st);
			break;
		case 2:
			stu.ScoreShow(st);
			break;
		case 3:
			stu.SavaDate(st);
			break;
		case 4:
			stu.InforRead (st);
			break;
		case 5 :
			stu.InforSort(st);
			break;
		case 6:
			stu.Modify(st);
			break;
		case 7:
			stu.Statis(st);
			break;
		case 8:
			system("cls");
			break;
		case 9:  
			cout <<" 确认退出系统？（y/n）";
			cin >> returnFlag;
			if(returnFlag[0] == 'y' || returnFlag[0] == 'Y')
			{
				exit(0);  
			}
			else
			{
				continue;
			}
			
			break; 
			
		}
		
	}
	return 0;
}




/*显示台*/
void displayIndex()
{
	printf("╔═══════班级成绩管理系统════════╗\n");
	printf("║                1.成绩录入;                   ║\n");
	printf("║                2.成绩显示;                   ║\n");
	printf("║                3.导出成绩;                   ║\n");
	printf("║                4.导入成绩;                   ║\n");
	printf("║                5.成绩排序;                   ║\n");
	printf("║                6.成绩修改;                   ║\n");
	printf("║                7.成绩统计;                   ║\n");
	printf("║                8.清屏;                       ║\n");
	printf("║                9.安全退出系统;               ║\n");
	printf("║                                              ║\n");
	printf("║                     Made By 钟佳闱 QQ26324636║\n");
	printf("╚═══════════════════════╝\n");
}

/*成绩录入*/
void Student :: InforInset(Student stu[])
{
	int i,j,h;
	char returnFlag[5];
	while(1)
	{
		cout << "请输入需要录入的学生数量：";
		cin >> N;
		
		cout << "请输入课程数量：";
		cin >> Num;
		cout << "请输入课程名称：";
		for(i = 0 ; i < Num ; i ++)
		{
			cin >> stu[0].Course[i];
		}
		
		for(i = 0 ; i < N ;i ++)
		{
			cout << "请输入学号：";
			cin >> stu[i].ID;
			cout << "请输入姓名：";
			cin >> stu[i].Name;
			
			
			cout << "请分别输入";
			
			for(h = 0 ; h < Num - 1 ; h ++)
			{
				cout << stu[0].Course[h] << ",";
			}
			cout << stu[0].Course[Num - 1] << "的成绩：";
			
			for(j = 0; j < Num ; j ++)
			{
				cin >> stu[i].Mark[j];
			}
		}
		cout << "成绩录入完毕，请记得先保存数据再继续操作哦~\n是否继续录入学生成绩？（y/n）:";
		cin >> returnFlag;
		if(returnFlag[0] == 'y' || returnFlag[0] == 'Y')
		{
			continue;
		}
		else
		{
			break;
		}
		
	}
}

/*成绩平均分总分*/
void Student :: AddSum(Student stu[])
{
	int i,j;
	
	for(i = 0 ; i < N ; i ++)
	{
		stu[i].sum = 0;
		for(j = 0 ; j < Num ; j ++)
		{
			stu[i].sum += stu[i].Mark[j]; 
		}
		stu[i].Aver = stu[i].sum / Num;
	}
}

/*成绩显示*/
void Student :: ScoreShow(Student stu[])
{
	int i,j;
	
	printf("----------------------------------------------------------------------\n");  
	cout << setw(10) << right <<"学号" << setw(10) << right << "姓名";
	for(i = 0 ; i < Num ; i ++)
	{
		cout<< setw(10) << stu[0].Course[i];
	}
	cout << setw(10) << right << "平均分" << setw(10) << right << "总分"; 
	cout << endl;
	printf("----------------------------------------------------------------------\n"); 
	AddSum(stu);
	for(i = 0 ; i < N - 1 ; i ++)
	{
		cout << setw(10) << right << stu[i].ID <<setw(10) << right << stu[i].Name;
		for(j = 0 ; j < Num ; j ++)
		{
			cout << setw(10) << setprecision(1)<<fixed<< right << stu[i].Mark[j];
		}
		cout << setw(10) << right << stu[i].Aver << setw(10) << right << stu[i].sum;
		cout << endl;
	}
	
}


/*输出文件*/
void Student::SavaDate(Student stu[])
{
	int i,j;
	ofstream outfile("班级成绩管理系统.txt",ios::out);
	if(!outfile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	outfile <<"----------------------------------------------------------------------\n";
	outfile  << "学号" << '\t' << "姓名" << '\t' ;
	
	for(i = 0 ; i < Num ; i ++)
	{
		outfile << stu[0].Course[i] <<'\t';
	}
	outfile << '\n';
	outfile <<"----------------------------------------------------------------------\n";
	for(i = 0 ; i < N ; i ++)
	{
		outfile << stu[i].ID << '\t' << stu[i].Name << '\t';
		for(j = 0 ; j < Num ; j ++)
		{
			outfile << stu[i].Mark[j] << '\t';
		}
		outfile << '\n';
	}
	
	cout << "文件导出完成！" << endl;
	outfile.close();
}

/*文件读取数据*/
void Student :: InforRead(Student stu[])
{
	
	int flag,h;
	char buf[1000];
	//	char buf1[1000];
	string s;
	
	Num = 0;
	ifstream infile("班级成绩管理系统.txt",ios :: in);
	if(!infile)
	{
		cerr << "文件不存在，请输入新的数据!" <<endl;
	}
	else
	{
		infile.getline(buf,1000);
		flag = 0 ;
		while(infile >> s )
		{
			flag ++;
			if(s == "----------------------------------------------------------------------")
			{
				
				break;
			}
			
			if(flag > 2 )
			{
				stu[0].Course[Num++] = s;			 
			}
		}
		//	infile.getline(buf1,1000);
		N = 0;
		while(!infile.eof())
		{
			
			infile >> stu[N].ID >> stu[N].Name;
			for(h = 0 ; h < flag - 3 ; h ++)
			{
				infile >> stu[N].Mark[h];
			}
			N ++;
		}
		cout << "数据导入完成！" << endl;
		infile.close();
	}
}

/*成绩排序*/
void Student ::InforSort (Student stu[])
{
	int i,j;
	Student temp;
	AddSum(stu);
	for(i = 0 ; i < N - 1 ; i ++)
	{
		for(j = 0 ; j < N - 1- i ; j ++)
		{
			if(stu[j].sum < stu[j + 1].sum)
			{
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
	ScoreShow(stu);
}

/*通过学号返回数组下标*/
int Student :: SearchByID(Student stu[],string id)
{
	int i;
	for(i = 0 ; i < N ; i ++)
	{
		if(id == stu[i].ID)
		{
			return i;
		}
	}
	return -1;
}

/*成绩修改*/
void Student ::Modify(Student stu[])
{
	string xh,pass;
	int returnnum,h,j,flag;
	flag = 3;
	
	cout <<"请输入8位密码：";
	while(1)
	{
		cin >> pass;
		if(pass == Password)
		{
			cout << "密码正确！请输入你要修改的学生学号：";
			cin >> xh;
			returnnum = SearchByID(stu,xh);
			if(returnnum == -1)
			{
				cout << "学生不存在！"<< endl;
				
			}
			else
			{
				cout << "请重新输入学生信息："<<endl;
				
				cout << "请输入学号：";
				cin >> stu[returnnum].ID;
				cout << "请输入姓名：";
				cin >> stu[returnnum].Name;
				
				
				cout << "请分别输入";
				
				for(h = 0 ; h < Num - 1 ; h ++)
				{
					cout << stu[0].Course[h] << ",";
				}
				cout << stu[0].Course[Num - 1] << "的成绩：";
				
				for(j = 0; j < Num ; j ++)
				{
					cin >> stu[returnnum].Mark[j];
				}
				
			}
			cout << "修改完后记得保存读出数据哦！" << endl;
		}
		else
		{
			flag --;
			if(flag > 0)
			{
				cout << "密码错误，你还有" << flag << "次机会，请重新输入密码：";
				continue;
			}
			else
			{
				break;
			}
			
			
		}
	}
	
}

/*成绩统计*/
void Student ::Statis(Student stu[])
{
	int i,j,flag,flag1,flag2 ;
	float aver;
	float max ;
	cout << "*****************************************************************" << endl;
	cout << "                     各课程最高成绩学生统计                       " << endl;
	cout << "*****************************************************************" << endl;
	cout << setw(15) << right << "课程";
	cout << setw(15) << right << "学号";
	cout << setw(15) << right << "姓名" ;
	cout << setw(15) << right << "成绩"<< endl;
	for(i = 0 ; i < Num; i ++)
	{
		max = 0;
		for(j = 0 ; j < N - 1; j ++)
		{
			if(stu[j].Mark[i] > max)
			{
				max = stu[j].Mark[i];
				flag = j;
				flag1 = i;			
			}
		}
		cout << setw(15) << right << stu[0].Course[i];
		cout << setw(15) << right << stu[flag].ID;
		cout << setw(15) << right << stu[flag].Name;
		cout << setw(15) << right << stu[flag].Mark[flag1] << endl;
	}
	cout << endl;
    cout << "*****************************************************************" << endl;
	cout << "                          各课程平均成绩                         " << endl;
	cout << "*****************************************************************" << endl;
	cout << setw(25) << right << "课程";
	cout << setw(25) << right << "平均成绩" << endl;
	for(i = 0 ; i < Num ; i ++)
	{
		sum = 0;
		for(j = 0 ; j < N - 1 ; j ++)
		{
			sum += stu[j].Mark[i];     
		}
		stu[i].aver = sum / (N - 1);
		cout << setw(25) << right << stu[0].Course[i];
		cout << setw(25) << right << stu[i].aver << endl;
	}
	cout << endl;
	
	cout << "*****************************************************************" << endl;
	cout << "                         超过平均成绩人数                        " << endl;
	cout << "*****************************************************************" << endl;
	cout << setw(25) << right << "课程";
	cout << setw(25) << right << "人数（个）" << endl;
	for(i = 0 ; i < Num ; i ++)
	{
		flag2 = 0;
		for(j = 0 ; j < N - 1 ; j ++)
		{
			if(stu[j].Mark[i] > stu[i].aver)
			{
				flag2 ++ ;
			}
		}
		cout << setw(25) << right << stu[0].Course[i];
		cout << setw(25) << right << flag2 << endl;
	}
	cout << endl;	
}

