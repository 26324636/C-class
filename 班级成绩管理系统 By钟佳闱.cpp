#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;
 

class Student
{
public :
	void InforInset(Student stu[]); //�ɼ�¼��
	void ScoreShow(Student stu[]); //�ɼ���ʾ
	void SavaDate(Student stu[]);  //����ļ�
	void InforRead(Student stu[]); //��ȡ�ļ�
	void InforSort(Student stu[]); //�ɼ�����
	void AddSum(Student stu[]); //�ɼ��ܺ�
	void Modify(Student stu[]);	//�ɼ��޸�
	void Statis(Student stu[]); //�ɼ�ͳ��
	int SearchByID(Student stu[],string id); //ͨ��ѧ�ŷ��������±�
	
private:
	string ID; //����ѧ��ѧ��
	string Name; //����ѧ������
	string Course[20]; //����γ�
	float Mark[20]; //����γ̳ɼ�
	float sum;  //����ɼ��ܺ�
	float Aver; //�������ƽ���ɼ�
	float aver; //������γ�ƽ���ɼ�	
};

int N = 0; //ѧ������
int Num = 0; //�γ�����
string Password = "26324636"; //����
void displayIndex();

/*������*/
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
		cout <<  "������ѡ�";
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
			cout <<" ȷ���˳�ϵͳ����y/n��";
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




/*��ʾ̨*/
void displayIndex()
{
	printf("�X�T�T�T�T�T�T�T�༶�ɼ�����ϵͳ�T�T�T�T�T�T�T�T�[\n");
	printf("�U                1.�ɼ�¼��;                   �U\n");
	printf("�U                2.�ɼ���ʾ;                   �U\n");
	printf("�U                3.�����ɼ�;                   �U\n");
	printf("�U                4.����ɼ�;                   �U\n");
	printf("�U                5.�ɼ�����;                   �U\n");
	printf("�U                6.�ɼ��޸�;                   �U\n");
	printf("�U                7.�ɼ�ͳ��;                   �U\n");
	printf("�U                8.����;                       �U\n");
	printf("�U                9.��ȫ�˳�ϵͳ;               �U\n");
	printf("�U                                              �U\n");
	printf("�U                     Made By �Ӽ��� QQ26324636�U\n");
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
}

/*�ɼ�¼��*/
void Student :: InforInset(Student stu[])
{
	int i,j,h;
	char returnFlag[5];
	while(1)
	{
		cout << "��������Ҫ¼���ѧ��������";
		cin >> N;
		
		cout << "������γ�������";
		cin >> Num;
		cout << "������γ����ƣ�";
		for(i = 0 ; i < Num ; i ++)
		{
			cin >> stu[0].Course[i];
		}
		
		for(i = 0 ; i < N ;i ++)
		{
			cout << "������ѧ�ţ�";
			cin >> stu[i].ID;
			cout << "������������";
			cin >> stu[i].Name;
			
			
			cout << "��ֱ�����";
			
			for(h = 0 ; h < Num - 1 ; h ++)
			{
				cout << stu[0].Course[h] << ",";
			}
			cout << stu[0].Course[Num - 1] << "�ĳɼ���";
			
			for(j = 0; j < Num ; j ++)
			{
				cin >> stu[i].Mark[j];
			}
		}
		cout << "�ɼ�¼����ϣ���ǵ��ȱ��������ټ�������Ŷ~\n�Ƿ����¼��ѧ���ɼ�����y/n��:";
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

/*�ɼ�ƽ�����ܷ�*/
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

/*�ɼ���ʾ*/
void Student :: ScoreShow(Student stu[])
{
	int i,j;
	
	printf("----------------------------------------------------------------------\n");  
	cout << setw(10) << right <<"ѧ��" << setw(10) << right << "����";
	for(i = 0 ; i < Num ; i ++)
	{
		cout<< setw(10) << stu[0].Course[i];
	}
	cout << setw(10) << right << "ƽ����" << setw(10) << right << "�ܷ�"; 
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


/*����ļ�*/
void Student::SavaDate(Student stu[])
{
	int i,j;
	ofstream outfile("�༶�ɼ�����ϵͳ.txt",ios::out);
	if(!outfile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	outfile <<"----------------------------------------------------------------------\n";
	outfile  << "ѧ��" << '\t' << "����" << '\t' ;
	
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
	
	cout << "�ļ�������ɣ�" << endl;
	outfile.close();
}

/*�ļ���ȡ����*/
void Student :: InforRead(Student stu[])
{
	
	int flag,h;
	char buf[1000];
	//	char buf1[1000];
	string s;
	
	Num = 0;
	ifstream infile("�༶�ɼ�����ϵͳ.txt",ios :: in);
	if(!infile)
	{
		cerr << "�ļ������ڣ��������µ�����!" <<endl;
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
		cout << "���ݵ�����ɣ�" << endl;
		infile.close();
	}
}

/*�ɼ�����*/
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

/*ͨ��ѧ�ŷ��������±�*/
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

/*�ɼ��޸�*/
void Student ::Modify(Student stu[])
{
	string xh,pass;
	int returnnum,h,j,flag;
	flag = 3;
	
	cout <<"������8λ���룺";
	while(1)
	{
		cin >> pass;
		if(pass == Password)
		{
			cout << "������ȷ����������Ҫ�޸ĵ�ѧ��ѧ�ţ�";
			cin >> xh;
			returnnum = SearchByID(stu,xh);
			if(returnnum == -1)
			{
				cout << "ѧ�������ڣ�"<< endl;
				
			}
			else
			{
				cout << "����������ѧ����Ϣ��"<<endl;
				
				cout << "������ѧ�ţ�";
				cin >> stu[returnnum].ID;
				cout << "������������";
				cin >> stu[returnnum].Name;
				
				
				cout << "��ֱ�����";
				
				for(h = 0 ; h < Num - 1 ; h ++)
				{
					cout << stu[0].Course[h] << ",";
				}
				cout << stu[0].Course[Num - 1] << "�ĳɼ���";
				
				for(j = 0; j < Num ; j ++)
				{
					cin >> stu[returnnum].Mark[j];
				}
				
			}
			cout << "�޸����ǵñ����������Ŷ��" << endl;
		}
		else
		{
			flag --;
			if(flag > 0)
			{
				cout << "��������㻹��" << flag << "�λ��ᣬ�������������룺";
				continue;
			}
			else
			{
				break;
			}
			
			
		}
	}
	
}

/*�ɼ�ͳ��*/
void Student ::Statis(Student stu[])
{
	int i,j,flag,flag1,flag2 ;
	float aver;
	float max ;
	cout << "*****************************************************************" << endl;
	cout << "                     ���γ���߳ɼ�ѧ��ͳ��                       " << endl;
	cout << "*****************************************************************" << endl;
	cout << setw(15) << right << "�γ�";
	cout << setw(15) << right << "ѧ��";
	cout << setw(15) << right << "����" ;
	cout << setw(15) << right << "�ɼ�"<< endl;
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
	cout << "                          ���γ�ƽ���ɼ�                         " << endl;
	cout << "*****************************************************************" << endl;
	cout << setw(25) << right << "�γ�";
	cout << setw(25) << right << "ƽ���ɼ�" << endl;
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
	cout << "                         ����ƽ���ɼ�����                        " << endl;
	cout << "*****************************************************************" << endl;
	cout << setw(25) << right << "�γ�";
	cout << setw(25) << right << "����������" << endl;
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

