#include <stdio.h>
#include <string.h>
#include "lib_for_sys.h"
void print_menu(void)
{
    printf("1.Input record\n");
    printf("2.Caculate total and average score of course\n");
    printf("3.Sort in descending order by score\n");
    printf("4.Sort in ascending order by score\n");
    printf("5.Sort in ascending order by student's ID\n");
    printf("6.Sort in dictionary order ba name\n");
    printf("7.Search by student's ID\n");
    printf("8.Search by student's name\n");
    printf("9.Statistic analysis\n");
    printf("10.List record\n");
    printf("11.Exit\n");
    printf("Please input your choice:");
}
void read(int score[],long ID[],char name[][30],int *pn)
{
    int i;
    printf("Please input the students` number:");
    scanf("%d",pn);
    printf("please input the student`s ID ,name and score:\n");
    for(i=0;i<*pn;i++)
    {
        scanf("%ld%s%d",&ID[i],name[i],&score[i]);
    }
}
void caculate(int score[],int n,int *ps,float *pa)
{
    int i=0;
    *ps=0;
    for(i=0;i<n;i++)
    {
        *ps+=score[i];
    }
    *pa=*ps/(float)n;
    printf("sum:%d\naver:%f\n\n",*ps,*pa);
}
void sort_score(int score[],long ID[],char name[][30],int n,int (*pFUN)(int a,int b))
{
    int s1[20];
    long a1[20],t;
    char n1[50][30],tn[30];
    int i,j,k;
    for(i=0;i<n;i++)
    {
        s1[i]=score[i];
        a1[i]=ID[i];
        strcpy(n1[i],name[i]);
    }
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i;j<n;j++)
        {
            if((*pFUN)(s1[k],s1[j]))   k=j;
        }
        if(i!=k)
        {
            t=s1[k];
            s1[k]=s1[i];
            s1[i]=t;
            t=a1[k];
            a1[k]=a1[i];
            a1[i]=t;
            strcpy(tn,n1[k]);
            strcpy(n1[k],n1[i]);
            strcpy(n1[i],tn);
        }
    }
    printf("ID\t\tname\t\tscore\n");
    for(i=0;i<n;i++)
    {
        printf("%ld\t%-15s\t%d\n",a1[i],n1[i],s1[i]);
    }
}
void sort_ID(int score[],long ID[],char name[][30],int n)
{
    int s1[20];
    long a1[20],t;
    char n1[50][30],tn[30];
    int i,j,k;
    for(i=0;i<n;i++)
    {
        s1[i]=score[i];
        a1[i]=ID[i];
        strcpy(n1[i],name[i]);
    }
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i;j<n;j++)
        {
            if(a1[j]<a1[k])   k=j;
        }
        if(i!=k)
        {
            t=s1[k];
            s1[k]=s1[i];
            s1[i]=t;
            t=a1[k];
            a1[k]=a1[i];
            a1[i]=t;
            strcpy(tn,n1[k]);
            strcpy(n1[k],n1[i]);
            strcpy(n1[i],tn);
        }
    }
    printf("ID\t\tname\t\tscore\n");
    for(i=0;i<n;i++)
    {
        printf("%ld\t%-15s\t%d\n",a1[i],n1[i],s1[i]);
    }
}
void sort_name(int score[],long ID[],char name[][30],int n)
{
    int s1[20];
    long a1[20],t;
    char n1[50][30],tn[30];
    int i,j,k;
    for(i=0;i<n;i++)
    {
        s1[i]=score[i];
        a1[i]=ID[i];
        strcpy(n1[i],name[i]);
    }
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i;j<n;j++)
        {
            if(strcmp(n1[k],n1[j])>0)
                k=j;
        }
        if(i!=k)
        {
            t=s1[k];
            s1[k]=s1[i];
            s1[i]=t;
            t=a1[k];
            a1[k]=a1[i];
            a1[i]=t;
            strcpy(tn,n1[k]);
            strcpy(n1[k],n1[i]);
            strcpy(n1[i],tn);
        }
    }
    printf("ID\t\tname\t\tscore\n");
    for(i=0;i<n;i++)
    {
        printf("%ld\t%-15s\t%d\n",a1[i],n1[i],s1[i]);
    }
}
void find_ID(int score[],long ID[],char name[][30],int n)
{
    int i,j,k,flag=0;
    int s1[20];
    long a1[20],t,x;
    char n1[50][30],tn[30];
    printf("please input the student`s ID:");
    while(1!=scanf("%ld",&x))
    {
        while(getchar()!='\n');
        printf("Please input a ID:");
    }
    for(i=0;i<n;i++)
    {
        s1[i]=score[i];
        a1[i]=ID[i];
        strcpy(n1[i],name[i]);
    }
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i;j<n;j++)
        {
            if(s1[j]>s1[k])   k=j;
        }
        if(i!=k)
        {
            t=s1[k];
            s1[k]=s1[i];
            s1[i]=t;
            t=a1[k];
            a1[k]=a1[i];
            a1[i]=t;
            strcpy(tn,n1[k]);
            strcpy(n1[k],n1[i]);
            strcpy(n1[i],tn);
        }
    }
    for(i=0;i<n;i++)
    {
        if(a1[i]==x)
        {
            printf("ID\t\tname\t  score    rank\n%ld\t%-10s%d\t    %d\n",a1[i],n1[i],s1[i],i+1);
            flag=1;
        }
    }
    if(flag==0) printf("Not found!Please check the ID!\n\n");
}
void find_name(int score[],long ID[],char name[][30],int n)
{
    int i,j,k,flag=0;
    int s1[20];
    long a1[20],t;
    char n1[50][30],tn[30],x[30];
    printf("please input the student`s name:");
    scanf("%s",x);
    for(i=0;i<n;i++)
    {
        s1[i]=score[i];
        a1[i]=ID[i];
        strcpy(n1[i],name[i]);
    }
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i;j<n;j++)
        {
            if(s1[j]>s1[k])   k=j;
        }
        if(i!=k)
        {
            t=s1[k];
            s1[k]=s1[i];
            s1[i]=t;
            t=a1[k];
            a1[k]=a1[i];
            a1[i]=t;
            strcpy(tn,n1[k]);
            strcpy(n1[k],n1[i]);
            strcpy(n1[i],tn);
        }
    }
    for(i=0;i<n;i++)
    {
        if(strcmp(x,n1[i])==0)
        {
            printf("ID\t\tname\t  score    rank\n%ld\t%-10s%d\t    %d\n",a1[i],n1[i],s1[i],i+1);
            flag=1;
        }
    }
    if(flag==0) printf("Not found!Please check the name!\n\n");
}
void analysis(int score[],long ID[],int n)
{
    int i;
    int count[6]={0};
    for(i=0;i<n;i++)
    {
        if(score[i]>=90)
        {
            count[0]++;;
        }
        if(score[i]>=80&&score[i]<=89)
        {
            count[1]++;
        }
        if(score[i]>=70&&score[i]<=79)
        {
            count[2]++;
        }
        if(score[i]>=60&&score[i]<=69)
        {
            count[3]++;
        }
        if(score[i]<=59)
        {
            count[4]++;
        }
    }
    printf("Excelent  Good   Normal    Pass    Fali\n");
    for(i=0;i<5;i++)
    {
        printf("  %3d   ",count[i]);
    }
    printf("\n");
    for(i=0;i<5;i++)
    {
        printf("   %3.2f ",count[i]/(double)n);
    }
    printf("\n");
}
void list_record(int score[],long ID[],char name[][30],int n)
{
    int i=0;
    printf("\nID\t\t  name\t\tscore\n");
    for(i=0;i<n;i++)
    {
        printf("%ld\t  %-11s\t%d\n",ID[i],name[i],score[i]);
    }
}

int descend(int a,int b)
{
    if(a<b)
        return 1;
    else
        return 0;
}
int ascend(int a,int b)
{
    if(a>b)
        return 1;
    else
        return 0;
}
