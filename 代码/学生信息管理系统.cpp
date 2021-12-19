#include <stdio.h>   
#include <malloc.h> 
#include <string.h> 
#include <stdlib.h> 
#include <windows.h> 
typedef struct score
{
	int score_c;		//C语言成绩
	int score_math;		//高等数学
	int score_english;  //大学英语成绩
}Score;
typedef struct Student  
{  
   char name[100]; 		//姓名  
   char num[100];  		//学号  
   char sex;			//性别 (m代表女生f代表男生)  
   int age;				//年龄  
   Score score;			//成绩  
}stu;  
typedef struct LNode  
{  
    stu data;  
    struct LNode *next;  
}LinkList;

void train()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t");
	for(int y=0;y<=0;y++)
	{
		Sleep(60); 
		int a,b;
		a=0;
		while(a<=10)
		{
			system("cls"); 
			b=1;
 			printf("\n\n\n\n"); 
			while(b<=a)
			{
				printf(" ");
				b++;
			}
		
			printf("┌════════┐...┌════════┐...┌.═════════┐   ╭═════╮\n");
			b=1;
			while(b<=a){printf(" ");b++;;}
			printf("║        ║ ═ ║        ║ ═ ║          ║═  ║ 　  ║\n");
			b=1;
			while(b<=a)
			{
				printf(" ");
				b++;
			}
			printf("└⊙═⊙═⊙═⊙ ⊙═⊙═⊙═⊙  └⊙═⊙═⊙═⊙~~ ╰⊙═⊙╯\n");
 			Sleep(1);
 			a=a+1;
			 }	
	 }
	system("cls");
 }
char nam[100];//名字  
char nu[100];//学号  
char s;//性别  
int ag;//年龄  
Score sc;//成绩 

void menu()/* 菜单界面*/
{
	 printf("\t\t\t  ******************************************************\n\n");
	 printf("\t\t\t  *                学生信息管理系统                   * \n\n");
	 printf("\t\t\t  ******************************************************\n\n"); 
	 printf("\t\t\t*********************系统功能菜单*************************\n");
	 printf("\t\t\t     ----------------------   ----------------------  \n");
	 printf("\t\t\t     *********************************************  \n");
	 printf("\t\t\t     * 0.系统帮助及说明  * *  1.刷新学生信息   *   \n");
	 printf("\t\t\t     *********************************************  \n"); 
	 printf("\t\t\t     * 2.查询学生信息    * *  3.修改学生信息   *   \n");
	 printf("\t\t\t     *********************************************  \n");
	 printf("\t\t\t     * 4.增加学生信息    * *  5.按学号删除信息 *   \n");
	 printf("\t\t\t     *********************************************  \n");
	 printf("\t\t\t     * 6.显示当前信息    * *  7.保存当前学生信息*   \n");
	 printf("\t\t\t     ********************** **********************  \n");
	 printf("\t\t\t     * 8.退出系统        *        \n");
	 printf("\t\t\t     **********************        \n");
	 printf("\t\t\t     ----------------------   ----------------------  \n");
}

void help()/*帮助界面*/
{ 
	 printf("\n\t\t\t0.欢迎使用系统帮助！\n");
	 printf("\n\t\t\t1.初次进入系统后,请先选择增加学生信息;\n");
	 printf("\n\t\t\t2.按照菜单提示键入数字代号;\n");
	 printf("\n\t\t\t3.增加学生信息后,切记保存;\n");
	 printf("\n\t\t\t4.谢谢您的使用！\n");
}

void InitList(LinkList *&L)//初始化链表  
{  
    L=(LinkList *)malloc(sizeof(LinkList));  
    L->next=NULL;  
}
void ListInsert(LinkList *&L,LinkList *p)//插入新的节点  
{  
    LinkList *q=NULL;
    q=L;
    p->next=q->next;
    q->next=p;
}  
void addstu(LinkList *&L)//增加新的学生  
{   
    printf("请输入学生的信息：\n");  
    printf("学号：");  
    scanf("%s",nu);  
    LinkList *q=L->next;  
    while(q!=NULL )  //用于判断学生信息是否已经存在
    {  
        if(0==strcmp(q->data.num,nu))  
        {  
            printf("该学生已存在\n");  
            break;  
        }  
        q=q->next;  
    }  
    if(q==NULL)  
    {  
        LinkList *p;  
        InitList(p);//先初始化链表  
        strcpy(p->data.num,nu);  
        printf("姓名") ;  
        scanf("%s",nam) ;  
        strcpy(p->data.name,nam);  
        printf("性别：（m为男 f为女）");  
        scanf(" %c",&s);  
        p->data.sex=s;  
        printf("年龄：");  
        scanf("%d",&ag);  
        p->data.age=ag;  
	 	printf("C语言成绩：");
  		scanf("%d",&sc.score_c); 
  		while(sc.score_c<0||sc.score_c>100)
  		{
            printf("输入有误，请重新输入\n");
   			scanf("%d",&sc.score_c);  
        }
  		p->data.score.score_c=sc.score_c;
  		printf("高等数学成绩：");
  		scanf("%d",&sc.score_math); 
   		while(sc.score_math<0||sc.score_math>100)
   		{
            printf("输入有误，请重新输入\n");
            scanf("%d",&sc.score_math);  
        }
   		p->data.score.score_math=sc.score_math;
  		printf("大学英语成绩：");
  		scanf("%d",&sc.score_english);  
        while(sc.score_english<0||sc.score_english>100)
        {
            printf("输入有误，请重新输入\n");
            scanf("%d",&sc.score_english);  
        }
        p->data.score.score_english=sc.score_english;  
        ListInsert(L,p);//后插入节点，每输入一个数据，插入一个节点。 
    }  
}  

void deletestu(LinkList *L)//删除学生  
{   
    printf("请输入您要删除的学生的学号:");  
    scanf("%s",nu);  
    //判断  
    LinkList *p,*pre;  
    if(L->next==NULL)  
    {  
        printf("还没有学生信息,请增加学生信息\n");  
        return;  
    }  
    pre=L; //需要再用一个指针指向头指针 
    p=pre->next;  
    int judge=0;  //后面进行判断是否删除成功。 
    while(p)  
    {  
         if(0==strcmp(p->data.num,nu))  
         {  
                 judge=1;  
                 pre->next=p->next;  
                 free(p);  
                 printf("删除学生成功\n");  
                 break;  
         }  
         pre=p;  
         p=p->next;  
    }  
    if(judge==0)  
       printf("这个学生不存在\n");  
}  

void changestu(LinkList *L)//改变学生信息  
{  
	int judge=0;  
    printf("请输入您要修改学生的学号：\n");  
    scanf("%s",nu);  
    LinkList *q=L->next;  
    while(q!=NULL )  
    {  
        if(0==strcmp(q->data.num,nu))  
        {  
            judge=1;  
            printf("请输入您要修改的信息选项：1.姓名 2. 成绩(c语言，高等数学，大学英语)  3.年龄   \n");  
            int choose;  
            scanf("%d",&choose); 
            switch(choose)  
            {  
            case 1:  
                	printf("请输入您要修改的名字：");  
                	scanf("%s",nam);  
                	printf("修改的名字为：%s\n",nam);  
                	strcpy(q->data.name,nam);
                	printf("修改名字成功！\n");  
                	break;  
            case 2:  
                	printf("请输入您要修改的成绩");  
               		scanf("%d%d%d",&sc.score_c,&sc.score_math,&sc.score_english);  
                	printf("修改的c成绩为：%d  修改的高等数学成绩为：%d  修改的大学英语成绩为：%d\n",sc.score_c,sc.score_math,sc.score_english);  
               		q->data.score=sc;  
                	printf("修改成绩成功！\n");  
                	break;  
            case 3:  
                	printf("请输入您要修改的年龄：");  
                	scanf("%d",&ag);  
                	printf("修改的年龄为：%d\n",ag);  
               		q->data.age=ag;  
                	printf("修改年龄成功！\n");  
                	break;  
            default :  
                	printf("请输入正确的选项\n");  
                	break;  
            }  
        }  
        q=q->next;  
    }  
   if(judge==0)  
   {  
     printf("该生不存在\n");  
   }  
}  
void findstu(LinkList *L)//按学号或者姓名查找学生并输出该生信息  
{  
    int flag; 
    printf("1.按学号查询：\n");
    printf("2.按姓名查询：\n");
    printf("请输入查询方式：");
    scanf("%d",&flag); 
    if(flag==1){
        printf("请输入该生学号："); 
        scanf("%s",nu);  
        //判断  
        LinkList *q=L->next;//指向头指针的下个节点 
        while(q!=NULL )  
        {  
            if(strcmp(q->data.num,nu)==0)  
            {  
                printf("姓名：%s\n",q->data.name);  
                printf("学号：%s\n",q->data.num);  
                printf("性别：%c\n",q->data.sex);  
                printf("年龄：%d\n",q->data.age);  
                printf("c语言成绩：%d\n",q->data.score.score_c); 
    			printf("高等数学成绩：%d\n",q->data.score.score_math); 
    			printf("大学英语成绩：%d\n",q->data.score.score_english); 
                break;  
            }  
             q=q->next;  
        }  
        if(q==NULL)  
            printf("该生不存在\n");  
    	}else{
        	printf("请输入该生姓名：");
        	scanf("%s",nam);  
        	LinkList *q=L->next;  
        	while(q!=NULL)  
        	{  
            	if(strcmp(q->data.name,nam)==0)  
            	{  
                	printf("姓名：%s\n",q->data.name);  
                	printf("学号：%s\n",q->data.num);  
                	printf("性别：%c\n",q->data.sex);  
                	printf("年龄：%d\n",q->data.age);  
                	printf("c语言成绩：%d\n",q->data.score.score_c); 
    				printf("高等数学成绩：%d\n",q->data.score.score_math); 
    				printf("大学英语成绩：%d\n",q->data.score.score_english);
                	break;  
            	}  
             	q=q->next;  
        	}  
        	if(q==NULL)  
            	printf("该生不存在\n");  
    	}
}  
void display(LinkList *&L)//浏览全部学生信息  
{  
    LinkList *q=L->next;  
    if(q==NULL)  
    {  
        printf("还没有学生信息，请增加学生信息\n");  
        return;  
    }  
    while(q!=NULL)  
    {   
  		printf("姓名：%s\t",q->data.name);  
        printf("学号：%s\t",q->data.num);  
        printf("性别：%c\t",q->data.sex);  
        printf("年龄：%d\t",q->data.age);  
        printf("c语言成绩：%d\t",q->data.score.score_c); 
  		printf("高等数学成绩：%d\t",q->data.score.score_math); 
  		printf("大学英语成绩：%d\n",q->data.score.score_english);
  		q=q->next;  
    }  
}  
void sort(LinkList *&L)//按学号排序排序 并输出排序后的结果  
{   
    LinkList *q,temp,*r=L->next;  
    //判断  
    if(r==NULL)  
    {  
        printf("还没有学生信息，请增加学生信息\n");  
        return;  
    }  
    while(r!=NULL)
    {
    	q=r->next;
    	while(q!=NULL)
    	{
    		if(r->data.num>q->data.num)
    		{
    			temp=*r;
    			*r=*q;
    			*q=temp;
    			temp.next=r->next;
    			r->next=q->next;
    			q->next=temp.next;
			}q=q->next;
		}r=r->next;
	}
        printf("刷新后的学生信息是：\n");  
    	display(L);  
}  
void saveStuDentFile(LinkList * &L)//保存学生信息到文件  
{  
    FILE *fp;  
    LinkList *p=L->next;  
    if((fp=fopen("student.txt","w"))==NULL)// 以可写(输入)的方式打开当前目录下的.txt  
    {  
        printf("不能打开此文件，请按任意键退出\n");   
        exit(1);  //异常退出 
    }  
    while(p)  
    {  
        fprintf(fp,"%s  %s  %c  %d  %d %d %d \n",p->data.num,p->data.name,p->data.sex,p->data.age,p->data.score.score_c,p->data.score.score_math,p->data.score.score_english);  
        p=p->next;  
        printf("保存成功\n");
    }  
    fclose(fp);  
}  

void readStuDentput (LinkList *&L) //运行前把文件内容读取到电脑内存  
{  
    FILE *fp;  
    fp=fopen("student.txt","a+"); //以只读方式打开当前目录下的.txt  
    if(fp==NULL)  
    {  
        printf("文件不存在\n");  
        exit(0);                   //终止程序  
    }  
     
    while(!feof(fp))  
    {  
        char nu[100];//学号  
        char nam[100];//名字 
        char s;//性别  
        int ag;//年龄  
        score sc;//成绩  
        fscanf(fp," %s %s %c %d %d %d %d",nu,nam,&s,&ag,&sc.score_c,&sc.score_math,&sc.score_english);
      
    }  
    fclose(fp);  
    
}  

int main()  
{       
	LinkList *L;  
    InitList(L);  
    readStuDentput (L);   //运行前把文件内容读取到电脑   
    int choose;  
    train();
    while(1)  
    {  
  		printf("\n");
        menu();     //功能菜单 
  		printf("请输入您的选择：\n"); 
        scanf("%d",&choose);  
        switch(choose)  
        {  
        case 0://系统帮助及说明
   			help();
   			system("pause");
            system("cls");
   			break; 
        case 1://刷新信息（按学号排序）
   			sort(L);
   			system("pause");
            system("cls");
   			break;
  		case 2: //查询学生信息
            findstu(L);  
            system("pause");
            system("cls");
            break;  
        case 3://修改学生信息  
   			changestu(L); 
            break; 
  		case 4://增加学生信息  
            addstu(L); 
            system("cls");
            break; 
 		case 5://删除学生信息  
            deletestu(L);  
            system("pause");
            system("cls");
            break;  
        case 6://输出所有学生的信息  
            display(L);  
            system("pause");
            system("cls");
            break; 
        case 7://保存学生信息到文件   
            saveStuDentFile(L);
			system("pause");
            system("cls");  
            break;
  		case 8://退出  
            printf("谢谢使用！");  
            exit(0);        
        default:  
            printf("请输入正确的选择\n");  
            break;  
        }  
    } 
 	return 0;
}  

