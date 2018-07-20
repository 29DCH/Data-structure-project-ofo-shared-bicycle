#include <iostream>
#include <algorithm>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define NAME 20
#define TIME 20

const int st_num=100;
int cu_num=100;
int count = 0;
int count1 = 0;

typedef struct bike
{
    int b_num;
    char b_time[TIME];
    char r_time[TIME];
    char username[NAME];
    bool info=false;
    struct bike *next;
} BIKE,*LinkList,*LinkStack;
BIKE Bike[st_num];

void Push(LinkStack &top,int bnum,char user[],char btime[],char rtime[])
{
    LinkStack p;
    p=new bike();
    p->b_num=bnum;
    strcpy(p->username,user);
    strcpy(p->b_time,btime);
    strcpy(p->r_time,rtime);
    p->next=top;
    top=p;
}

void Pop(LinkStack &top)
{
    LinkStack p;
    p=top;
    top=p->next;
    free(p);
}

void Init(LinkStack &s)
{
    s=NULL;
}

void Printinfo(LinkStack p)
{
    while(p)
    {
        printf("%d\t\t%s\t\t%s\t\t%s\n",p->b_num,p->username,p->b_time,p->r_time);
        p=p->next;
    }
}


LinkList Initlist(LinkList l)
{
    LinkList p = (LinkList)malloc(sizeof(BIKE));
    p->next = NULL;
    l = p;
    return l;
}

LinkList inputdata(LinkList l)
{
    int i;
    LinkList p = (LinkList)malloc(sizeof(BIKE));
    printf("�����뵥�����:");
    scanf("%d",&i);
    if(!p->info)
    {
        p->b_num=i;
        Bike[i].b_num=i;
        cu_num--;
        p->info=true;
        Bike[i].info=true;
    }
    printf("������賵������:");
    scanf("%s",p->username);
    strcpy(Bike[i].username,p->username);
    printf("������賵ʱ��:");
    scanf("%s",p->b_time);
    strcpy(Bike[i].b_time,p->b_time);
    printf("�����뻹��ʱ��:");
     scanf("%s",p->r_time);
    strcpy(Bike[i].r_time,p->r_time);
    p->next = l->next;
    l->next = p;
    printf("���������\n");
    count1++;
    return l;
}

void outputdata(int b_num,char username[],char b_time[],char r_time[])
{
    LinkStack s;
    Init(s);
    Push(s,b_num,username,b_time,r_time);
    Printinfo(s);
}

void ShowAll(LinkList l)
{
    LinkList p = l->next;
    printf("�������\t�賵������\t�賵ʱ��\t����ʱ��\n");
    while(p)
    {
        outputdata(p->b_num,p->username,p->b_time,p->r_time);
        p = p->next;
    }
    printf("\n��������\n");
}

void menu()
{
    printf("\t\t\t      ��ӭ����OFO�賵ϵͳ\n");
    for(int i=0; i<20; i++)
        cout<<" ";
    for(int i=0; i<40; i++)
        cout<<"*";
    cout<<endl;
    printf("\t\t1.�����뵥�����,�賵������,�賵ʱ��,����ʱ��\t\t\n");
    printf("\t\t\t\t2.������Ϣ��ʾ\t\t\n");
    printf("\t\t\t\t3.�賵��Ϣ��ʾ\t\t\n");
    printf("\t\t\t\t4.�������Ų�ѯ\t\t\n");
    printf("\t\t\t\t5.���賵ʱ���ѯ\t\n");
    printf("\t\t\t\t6.������ʱ���ѯ\t\n");
    printf("\t\t\t\t7.�������߲�ѯ\t\t\n");
    printf("\t\t\t\t8.���賵��Ϣ¼���ļ�\t\t\n");
    printf("\t\t\t\t9.���ļ��ж�ȡ�賵��Ϣ\t\t\n");
    printf("\t\t\t\t10.����賵��Ϣ\t\t\n");
    printf("\t\t\t\t11.ɾ���賵��Ϣ\t\t\n");
    printf("\t\t\t\t12.�޸Ľ賵��Ϣ\t\t\n");
    printf("\t\t\t\t13.���賵ʱ������\t\t\n");
    printf("\t\t\t\t14.�˳��賵ϵͳ\t\t\n");
    for(int i=0; i<20; i++)
        cout<<" ";
    for(int i=0; i<40; i++)
        cout<<"*";
    cout<<endl;
}

void print_bike_num()
{
    int count=0;
    for(int i=1; i<=st_num; i++)
        if(!Bike[i].info)
        {
            count++;
            printf("%d ",i);
            if(!(count%10))
                cout<<endl;
        }
}

int print_num()
{
    return cu_num;
}

int erfen(int *a,int l,int r,int v)
{
    int mid;
    while(l<=r)
    {
        mid=l+r;
        mid/=2;
        if(a[mid]==v)
            return mid;
        else if(a[mid]>v)
            r=mid-1;
        else  l=mid+1;
    }
    return -1;
}

void search_num(LinkList l)
{
    LinkList p = l->next;
    int num;
    int flag=0;
    printf("������Ҫ���ҵĵ������:");
    scanf("%d",&num);
    while(p)
    {
        if(num==p->b_num)
        {
            flag=1;
            printf("�������\t�賵������\t�賵ʱ��\t����ʱ��\n");
            outputdata(p->b_num,p->username,p->b_time,p->r_time);
            printf("\n");
            break;
        }
        p=p->next;
    }
    if(!flag)
    {
        printf("û����Ҫ��ѯ�ĵ���\n");
    }
}

void search_btime(LinkList l)
{
    char btime[20];
    int flag=0;
    LinkList p = l->next;
    printf("������Ҫ���ҵĽ賵ʱ��:");
    scanf("%s",btime);
    while(p)
    {
        if(!strcmp(btime,p->b_time))
        {
            flag=1;
            printf("�������\t�賵������\t�賵ʱ��\t����ʱ��\n");
            outputdata(p->b_num,p->username,p->b_time,p->r_time);
            printf("\n");
            break;
        }
        p=p->next;
    }
    if(!flag)
    {
        printf("û����Ҫ��ѯ�ĵ���\n");
    }
}

void search_rtime(LinkList l)
{
    char rtime[20];
    int flag=0;
    LinkList p = l->next;
    printf("������Ҫ���ҵĻ���ʱ��:");
    scanf("%s",rtime);
    while(p)
    {
        if(!strcmp(rtime,p->r_time))
        {
            flag=1;
            printf("�������\t�賵������\t�賵ʱ��\t����ʱ��\n");
            outputdata(p->b_num,p->username,p->b_time,p->r_time);
            printf("\n");
            break;
        }
        p=p->next;
    }
    if(!flag)
    {
        printf("û����Ҫ��ѯ�ĵ���\n");
    }
}

void search_username(LinkList l)
{
    char user[20];
    int flag=0;
    LinkList p = l->next;
    printf("������Ҫ���ҵĽ賵������:");
    scanf("%s",user);
    while(p)
    {
        if(!strcmp(user,p->username))
        {
            flag=1;
            printf("�������\t�賵������\t�賵ʱ��\t����ʱ��\n");
            outputdata(p->b_num,p->username,p->b_time,p->r_time);
            printf("\n");
            break;
        }
        p=p->next;
    }
    if(!flag)
    {
        printf("û����Ҫ��ѯ�ĵ���\n");
    }
}

void swapchar(char *a,char *b)
{
    char tmp[20];
    strcpy(tmp,a);
    strcpy(a,b);
    strcpy(b,tmp);
}

void swapint(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

LinkList FromFile(LinkList l)
{
    FILE *fp;
    LinkList p;
    char m[100];
    char n[100];
    int num;
    int i = 0;
    if((fp = fopen("D://bikeinfo.txt","r")) == NULL)
    {
        printf("�ļ��޷���!\n");
        return l;
    }
    while((fscanf(fp,"%s %s",m,n)) != EOF)
    {
        p = (LinkList)malloc(sizeof(BIKE));
        fscanf(fp,"%s %d",m,&num);
        p->b_num = num;
        fscanf(fp,"%s %s",m,n);
        strcpy(p->username,n);
        fscanf(fp,"%s %s",m,n);
        strcpy(p->b_time,n);
        fscanf(fp,"%s %s",m,n);
        strcpy(p->r_time,n);
        p->next = l->next;
        l->next = p;
        i++;
    }
    fclose(fp);
    if(i == 0)
    {
        printf("�ļ�Ϊ��!\n");
        return l;
    }
    else
    {
        printf("��ȡ���!\n");
        count1+=i;
        return l;
    }
}

void ToFile(LinkList l)
{
    FILE *fp;
    LinkList p = l->next;
    if((fp = fopen("D://bikeinfo.txt","a+")) == NULL)
    {
        printf("�����ļ��޷���!\n");
        return;
    }
    if(p == NULL)
    {
        printf("����Ϊ��!\n");
        return;
    }
    printf("��ʼ¼�������ļ�...\n");
    while(p)
    {
        fprintf(fp,"%s %d\n","�������",p->b_num);
        fprintf(fp,"%s %s\n","ʹ����",p->username);
        fprintf(fp,"%s %s\n","�賵ʱ��",p->b_time);
        fprintf(fp,"%s %s\n","����ʱ��",p->r_time);
        p = p->next;
    }
    printf("¼���������!\n");
    fclose(fp);
}

LinkList sort_btime(LinkList l)
{
    int k=0,m=0;
    int a[105]= {0};
    for(int i=1; i<=st_num; i++)
        for(int j=i+1; j<=st_num; j++)
            if(Bike[j].info&&strcmp(Bike[j].b_time,Bike[j+1].b_time)<0)
            {
                swapint(&Bike[j].b_num,&Bike[j+1].b_num);
                swapchar(Bike[j].username,Bike[j+1].username);
                swapchar(Bike[j].b_time,Bike[j+1].b_time);
                swapchar(Bike[j].r_time,Bike[j+1].r_time);
            }
    for(int i=1; i<=st_num; i++)
        if(Bike[i].info)
            a[k++]=i;
    LinkList p;
    p = l->next;
    while(p&&m<=k)
    {
        p->b_num=Bike[a[m]].b_num;
        strcpy(p->username,Bike[a[m]].username);
        strcpy(p->b_time,Bike[a[m]].b_time);
        strcpy(p->r_time,Bike[a[m]].r_time);
        p = p->next;
        m++;
    }
    printf("���賵ʱ���������!\n");
    return l;
}

LinkList FindNode(int n,LinkList l)
{
    int i;
    int flag = 0;
    LinkList p = l;
    for(i=0 ; i<n ; i++)
    {
        p = p->next;
    }
    return p;
}

LinkList Insert(LinkList l)
{
    int n;
    LinkList p = (LinkList)malloc(sizeof(BIKE));
    LinkList m;
    printf("������������ݵ�λ��:\n");
    scanf("%d",&n);
    if(n > count1||n<0)
    {
        printf("�����涨��Χ!\n");
        return l;
    }
    m = FindNode(n,l);
    printf("�����뵥�����:\n");
    scanf("%d",&p->b_num);
    printf("�������������\n");
    scanf("%s",p->username);
    printf("������賵ʱ��\n");
    scanf("%s",p->b_time);
    printf("�����뻹��ʱ��\n");
    scanf("%s",p->r_time);
    p->next = m->next;
    m->next = p;
    printf("�����������!\n");
    count1++;
    return l;
}

LinkList Remove(LinkList l)
{
    int n;
    printf("�������Ƴ����ݵ�λ��:\n");
    scanf("%d",&n);
    if(n > count1||n<0)
    {
        printf("�����涨��Χ!\n");
        return l;
    }
    LinkList m = FindNode(n,l);
    LinkList p = FindNode(n-1,l);
    p->next = m->next;
    free(m);
    printf("ɾ���������!\n");
    count1--;
    return l;
}

LinkList Change(LinkList l)
{
    int n,x;
    int c_num;
    char c_name[20],c_btime[20],c_rtime[20],c_info[20];
    LinkList m;
    printf("�������޸����ݵ�λ��:\n");
    scanf("%d",&n);
    if(n > count1||n<0)
    {
        printf("�����涨��Χ!\n");
        return l;
    }
    m = FindNode(n,l);
    printf("������Ҫ�޸ĵ����ݱ��(1.������� 2.�������� 3.�賵ʱ�� 4.����ʱ��:\n");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        printf("��������ĺ�ĵ������:\n");
        scanf("%d",&c_num);
        m->b_num=c_num;
        break;
    case 2:
        printf("��������ĺ�Ľ�������\n");
        scanf("%s",c_name);
        strcpy(m->username,c_name);
        break;
    case 3:
        printf("��������ĺ�Ľ賵ʱ��\n");
        scanf("%s",c_btime);
        strcpy(m->b_time,c_btime);
        break;
    case 4:
        printf("��������ĺ�Ļ���ʱ��\n");
        scanf("%s",c_rtime);
        strcpy(m->r_time,c_rtime);
        break;
    }
    printf("�޸��������!\n");
    return l;
}

void FreeNode(LinkList node)
{
    LinkList tail;
    while(node)
    {
        tail = node->next;
        free(node);
        node = tail;
    }
}

int main()
{
    int choice_num;
    LinkList head;
    LinkList a;
    int i;
    head = Initlist(head);
    LinkList tail;
    while(1)
    {
        menu();
        cout<<"��ѡ����Ĳ������:"<<endl;
        cin>>choice_num;
        switch(choice_num)
        {
        case 1:
            printf("�����뵥�����,�賵������,�賵ʱ��,����ʱ��:\n");
            head=inputdata(head);
            break;
        case 2:
            printf("������%d����������ѡ��:\n",print_num());
            print_bike_num();
            break;
        case 3:
            printf("�賵��Ϣ��ʾ:\n");
            ShowAll(head);
            break;
        case 4:
            printf("�����뵥���Ų�ѯ:\n");
            search_num(head);
            break;
        case 5:
            printf("������賵ʱ���ѯ:\n");
            search_btime(head);
            break;
        case 6:
            printf("�����뻹��ʱ���ѯ:\n");
            search_rtime(head);
            break;
        case 7:
            printf("�����������������ѯ:\n");
            search_username(head);
            break;
        case 8:
            printf("�뽫�賵��Ϣ¼���ļ�:\n");
            ToFile(head);
            break;
        case 9:
            printf("����ļ��ж�ȡ�賵��Ϣ:\n");
            head = FromFile(head);
            break;
        case 10:
            printf("�����賵��Ϣ:\n");
            head=Insert(head);
            break;
        case 11:
            printf("��ɾ���賵��Ϣ:\n");
            head=Remove(head);
            break;
        case 12:
            printf("���޸Ľ賵��Ϣ:\n");
            head=Change(head);
            break;
        case 13:
            printf("���ݽ賵ʱ������賵�������ʾ:\n");
            a = head;
            head = sort_btime(head);
            ShowAll(head);
            while(a)
            {
                tail = a->next;
                free(a);
                a = tail;
            }
            break;
        case 14:
            printf("�����˳��賵ϵͳ,�ټ�!\n");
            exit(0);
        default:
            printf("����������,������������ȷ�Ĳ������\n");
        }
        getchar();
        getchar();
        system("cls");
    }

    return 0;
}
