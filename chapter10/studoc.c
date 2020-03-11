#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HEADER1 "-------------STUDENT-------------- \n"
#define HEADER2 "|number| name | comp | Eng | sum | ave | mici | \n"
#define HEADER3 "|-----|----|----|----|---|---|---|---|"
#define FORMAT "|%-10s|%-15s|%4d|%4d|%4d|%4d|%.2f|%4d| \n"
#define DATA p->data.num,p->data.name,p->data.cgrade,p->data.mgrade,p->data.egrade,p->data.total,p->data.ave,p->data.rank
#define END "---------------------------------- \n"

int saveflag = 0; //是否需要存盘标志变量
typedef struct student //学生有关数据结构
{
	char num[10];
	char name[10];
	int cgrade;
	int mgrade;
	int egrade;
	int total;
	float ave;
	int rank;
};


typedef struct node //定义每条记录或节点的数据结构
{
	struct student data;
	struct node *next;
}Node, *Link;  //Link为node类型的指针的别名;



void menu()
{
	system("cls"); //调用DOS命令，清屏，与clrscr()功能相同
	printf("The Students Grade Manangement System \n\n");
	printf("******************menu******************\n");
	printf("*     1 input record    2 delete record* \n");
	printf("*     3 search record   4 modify record* \n");
	printf("*     5 insert record   6 count record * \n");
	printf("*     7 sort record     8 save record  * \n");
	printf("*     9 display record  0 quit system  * \n");
	printf("****************************************\n");
}


void printheader()
{
	printf(HEADER1);
	printf(HEADER2);
	printf(HEADER3);
}


void Wrong()
{
	printf("\n\n\n\n\n***** Error: input has wrong! press any key to continue***** \n");
	getchar();
}


void Nofind()
{
	printf("\n=====>Not find this student! \n");
}


void Disp(Link l) //输出错误按键信息
{
	Node *p;
	p = l->next;

	if(!p)
	{
		printf("\n=====>Not student record! \n");
		getchar();
		return;
	}

	printf("\n\n");
	printheader();

	while(p)
	{
		printdata(p);
		p = p->next;
		printf(HEADER3);
	}

	getchar();
	getchar();
	printf("\n");
}

Node *Locateofnum(Link l, char findmess[]) //按学号查询
{
	Node *r;
	r = l->next;
	while(r)
	{
		if(strcmp(r->data.num, findmess)==0)
			return r;
		r = r->next;
	}

	return 0;
}

void Locateofname(Link l, char findmess[], Node *n[]) //按姓名查询
{
	Node *r;
	int i = 0;
	r = l->next;
	while(r)
	{
		if(strcmp(r->data.name, findmess)==0)
			n[i++] = r;
		r = r->next;
	}
}


void stringinput(char *t, int lens, char *notice) //输入字符串，并进行长度验证
{
	char n[255];
	printf(notice);
	scanf("%s", n);
	while(strlen(n)>lens)
	{
		printf("\n exceed the required length! \n");
		printf(notice);
		scanf("%s", n)

	}
	strcpy(t, n);
}

int numberinput(char *notice) //输入分数，要求分数在0～100之间
{
	int t = 0;
	printf(notice);
	scanf("%d", &t);
	while(t>100 || t<0)
	{
		printf("\n score must in [0, 100]! \n");
		printf(notice);
		scanf("%d", &t);
	}
	return t;
}

void Add(Link l) //增加学生记录
{
	Node *p, *r, *s;
	char ch, flag=0, num[10];
	r = 1;
	s = l->next;
	system("cls");
	Disp(l);//先显示已有的学生信息

	while(r->next != NULL)
		r = r->next; //将指针移至链表末尾，准备添加记录
	while(l) //一次可输入多条记录，直至输入学号为0的记录结束添加操作
	{
		while(l) //输入学号，保证该学号没有被使用，若输入学号为0,则退出添加记录操作
		{
			stringinput(num, 10, "input number (press '0' return menu):"); //格式化输入学号长度是否超过10
			flag = 0;

			if(strcmp(num, "0")==0) //输入为0，则退出添加操作，返回主界面
			{
				flag = 1;
				break;
			}
			s = s->next;
			while(s) //查询该学号是否已经存在，若存在则要求重新输入一个未被占用的学号
			{
				if(strcmp(s->data.num, num)==0)
				{
					flag = 1;
					break;
				}
				s = s->next;
			}
			if(flag == 1)
			{
				getchar();
				printf("=====> The number %s is existing, try again? (y/n):", num);
				scanf("%c", &ch);
				if(ch=='y'||ch == 'Y')
					continue;
				else
					return;
			}
			else
				break;
		}

		p = (Node *)malloc(sizeof(Node));
		if(!p)
		{
			printf("\n allocate memory failure");
			return;
		}

		strcpy(p->data.num, num);
		stringinput(p->data.name, 15, "Name:");
		p->data.cgrade = numberinput("C language Score[0~100]:");
		p->data.mgrade = numberinput("C math Score[0~100]:");
		p->data.egrade = numberinput("C English Score[0~100]:");
		p->data.total = p->data.egrade + p->data.mgrade + p->data.cgrade;
		p->data.ave = (float)(p->data.total/3);
		p->data.rank = 0;
		p->next = p;
		r->next = p;
		r = p;
		saveflag = 1;
	}
	return;
}


void Qur(Link l)
{
	int select;
	char searchinput[20];
	Node *p;
	Node *n[5] = {NULL};
	int i = 0;
	if(! l->next)
	{
		system("cls");
		printf("\n=====>No student record!\n");
		getchar();
		return;
	}

	system("cls");
	printf("\n ===== > 1 Search by number ===== > 2 Search by name\n");
	printf("     please choice[1,2]:");
	scanf("%d", &select);
	if(select ==1)
	{
		stringinput(searchinput, 10, "input the existing student number:");
		p = Locateofnum(l, searchinput);
		if(p)
		{
			printheader();
			printdata(p);
			printf(END);
			printf("press any key to return");
			getchar();
		}
		else
			Nofind();
		getchar();
	}
	else if (select == 2)
	{
		stringinput (searchinput, 15, "input the existing student name:");
		Locateofname(l, searchinput,n);//在链表中查找姓名为searchinput值的节点，并将节点指针保存在数组n中
		while((p=n[i++])!=NULL)
		{
			printheader();
			printdata(p);
			printf(END);
		}
		printf("press any key to return");
		getchar();
		if(n[0]==NULL)
			Nofind();
		getchar();
	}
	else Wrong();
	getchar();
}


void Del(Link l)
{
	Node *p, *r;
	char findmess[20], ch;
	if(! l->next)
	{
		system("cls");
		printf("\n=====>No students record! \n");
		getchar();
		return;
	}
	system("cls");
	Disp(l);
	stringinput(findmess, 10, "input the existing student number:");
	getchar();
	p = Locateofnum(l, findmess);
	printf("Are you sure to delete %s (y/n)?", findmess);
	scanf("%c", &ch);
	if(ch=='y'||ch =='Y')
	{
		if(p)
		{
			r = l;
			while(r-next!=p)
				r = r->next;
			r->next = p-next;
			free(p);
			printf("\n =====> deletesuccess!\n");
			getchar();
			saveflag = 1;
		}
		else Nofind();
		getchar();
	}
}


void Modify(Link l)
{
	Node *p;
	char findmess[20];
	if(!l->next)
	{
		system("cls");
		printf("\n===== >No student record! \n");
		getchar();
		return;
	}
	system("cls");
	printf("modify student recorder");
	Disp(l);

	stringinput(findmess, 10, "input the existing student number:");
	p = Locateofnum(l, findmess);

	if(p)
	{
		printf("Number:%s,\n", p->data.num);
		printf("Name:%s,\n",p->data.name);
		stringinput(p->data.name, 15, "input new name:");
		printf("C language score:%d,", p->data.cgrade);
		p->data.cgrade = numberinput("C language Score[0~100]:");
		printf("math score:%d", p->data.mgrade);
		p->data.mgrade = numberinput("Math score[0~100]:");

		printf("English score:%d", p->data.egrade);
		p->data.egrade = numberinput("English score[0~100]:");
		
		p->data.total I=  p->data.egrade + p->data.cgrade+ p->data.mgrade;
		p->data.ave = (float)(p->data.total/3);
		p->data.rank = 0;
		printf("\n =====>modify success! \n");
		Disp(l);
		saveflag = 1;
	}
	else
		Nofind();

	getchar();
	getchar();
}


void Insert(Link l)  //插入记录， 按学号查询到要插入的节点的位置，然后在该学号之后插入一个新节点。
{   
	Link p, v, newinfo;
	char ch, num[10], s[10];
	int flag = 0;
	v = l->next;
	system("cls");
	Disp(l);

	while(l)
	{
		stringinput(s, 10, "Please input insert location after the Number:");
		flag = 0;
		v= l->next;
		
		while(v){
			if(strcmp(v->data.num, s)==0)
				break;
			v = v->next;
		}

		if(flag == 1)
			break;
		else
		{
			getchar();
			printf("\n ======> The number %s is not existing, try again?(y/n):",s);
			scanf("%c", &ch);
			if(ch == 'y'|| ch =='Y')
				continue;
			else
				return;
	
		}
	}
	stringinput(num, 10, "input new student number:");
	v = l->next;
	while(v)
	{
		if (strcmp(v->data.num, num) == 0)
		{
			printf("===== > Sorry, the new number: '%s' is existing ! \n", num);
			printheader();
			printdata(v);
			printf("\n");
			getchar();
			getchar();
			return;
		}
		v = v->next;
	}
	
	newinfo = (Node *)malloc(sizeof(Node));
	if (! newinfo)
	{
		printf("\n allocate memory failure "); //没有申请到打印提示信息;
		return;
	}

	strcpy(newinfo->data.num, num);
	stringinput(newinfo->data.name, 15, "Name:");
	newinfo->data.cgrade = numberinput("C language Score[0~100]:");
	newinfo->data.mgrade = numberinput("Math Score[0~100]:");
	newinfo->data.egrade = numberinput("English Score[0~100]:");
	newinfo->data.total = newinfo->data.egrade+newinfo->data.cgrade+newinfo->data.mgrade;
	newinfo->data.ave = (int) (newinfo->data.total/3);
	newinfo->data.rank = 0;
	newinfo->next = NULL;
	saveflag = 1;
	p = l->next;

	while(l)
	{
		if (strcmp(p->data.num, s) == 0)
		{
			newinfo->next = p->next;
			p->next = newinfo;
			break;
		}
		p = p->next;
	}Disp(l);
	printf("\n\n");
	
	getchar();
}


void Count(Link l)  //统计该班的第一名和单科和各科各成绩段的人数;
{
	Node *pm, *pe, *pc, *pt;
	Node *r = l->next;
	int countc[5] = {0}, countm[5] = {0}, counte[5] = {0};

	if (!r)
	{
		system("cls");
		printf("\n===== >Not student record! \n");
		getchar();
		return;
	}
	system("cls");
	Disp(l);
	pm = pe = pc = pt = r;
	while (r)
	{
		if (r->data.cgrade < 60) countc[0]++;
		if (r->data.egrade < 60) counte[0]++;
		if (r->data.mgrade < 60) countm[0]++;

		if (r->data.cgrade <70 && r->data.cgrade >=60) countc[1]++;
		if (r->data.egrade < 70 && r->data.egrade >=60) counte[1]++;
		if (r->data.mgrade <70 && r->data.mgrade >=60) countm[1]++;
		
		if (r->data.cgrade < 80 && r->data.cgrade >= 70) countc[2]++;
		if (r->data.egrade < 80 && r->data.egrade >= 70) counte[2]++;
		if (r->data.mgrade <80 && r->data.mgrade >= 70) countm[2]++;

		if (r->data.cgrade < 90 && r->data.cgrade >= 80) countc[3]++;
		if (r->data.egrade < 90 && r->data.egrade >= 80) counte[3]++;
		if (r->data.mgrade <90 && r->data.mgrade >= 80) countm[3]++;

		if (r->data.cgrade >= 90) countc[4]++;
		if (r->data.egrade >= 90) counte[4]++;
		if (r->data.mgrade >= 90) countm[4]++;
	
		if (r->data.cgrade >= pc->data.cgrade) pc = r;
		if (r->data.egrade >= pc->data.egrade) pe = r;
		if (r->data.mgrade >= pc->data.mgrade) pm = r;
		if (r->data.total >= pc->data.total) pt = r;
		r = r->next;
	}

	printf("\n-------------the TongJi result------------\n");
	printf("C language 0~59:%d (ren)\n", countc[0]);
	printf("C language 60~59:%d (ren)\n", countc[1]);
	printf("C language 70~59:%d (ren)\n", countc[2]);
	printf("C language 80~59:%d (ren)\n", countc[3]);
	printf("C language 90~100:%d (ren)\n", countc[4]);

	printf("--------------------------------------------------");
	printf("math               0~59:%d (ren)\n",countm[0]);
	printf("math               60~69:%d (ren)\n",countm[1]);
	printf("math               70~79:%d (ren)\n",countm[2]);
	printf("math               80~89:%d (ren)\n",countm[3]);
	printf("math               90~100:%d (ren)\n",countm[4]);

	printf("--------------------------------------------------");
	printf("English            0~59:%d (ren)\n",counte[0]);
	printf("English            60~69:%d (ren)\n",counte[1]);
	printf("English            70~79:%d (ren)\n",counte[2]);
	printf("English            80~89:%d (ren)\n",counte[3]);
	printf("English            90~100:%d (ren)\n",counte[4]);
	printf("--------------------------------------------------");

	printf("The highest student by total score num:%s total score:%d\n", pt->data.num, pt->data.total);
	printf("The highest student by English score num:%s total score:%d\n", pe->data.num, pe->data.egrade);
	printf("The highest student by C language score num:%s total score:%d\n", pc->data.num, pc->data.cgrade);
	printf("The highest student by math score num:%s total score:%d\n", pm->data.num, pm->data.mgrade);
	
	printf("\n\npress any key to return");
	getchar();
}


void Sort(Link l)
{
	struct student temp;
	Node *p1, *p2, *p;
	int i = 0;
	if ( l->next == NULL)
	{
		system("cls");
		printf("\n===== > Not student record! \n");
		getchar();
		return;
	}

	system("cls");
	Disp(l);
	p1 = l->next;
	while (p1)
	{
		p2 = p1->next;
		p = p1;
		while (p2)
		{
			if (p2->data.total >= p->data.total)
			{
				p = p2;
			}
			p2 = p2->next;
		}
		temp = p->data;
		p->data = p1->data;
		p1->data = temp;
		p1 = p1->next;
	}
	p = l->next;
	while (p != NULL)
	{
		i++;
		p->data.rank = i;
		p = p->next;
	}
	
	Disp(l);
	saveflag = 1;
	printf("\n             ===== > sort complete! \n");
}


void Save(Link l)
{
	
}