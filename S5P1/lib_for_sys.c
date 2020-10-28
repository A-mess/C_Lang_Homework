#include <stdio.h>
#include "lib_for_sys.h"
void print_menu(void)
{
    printf("1.Input record\n");
    printf("2.Caculate total and average score of course\n");
    printf("3.Sort in descending order by score\n");
    printf("4.Sort in ascending order by score\n");
    printf("5.Sort in ascending order by student's ID\n");
    printf("6.Search by student's ID\n");
    printf("7.Statistic analysis\n");
    printf("8.List record\n");
    printf("9.Exit\n");
    printf("Please input your choice:");
}
void read(int s[],long a[],int *pn)
{
    int i;
    printf("Please input the students` number:");
    scanf("%d",pn);
    printf("please input the student`s ID and score:\n");
    for(i=0;i<*pn;i++)
    {
        scanf("%ld%d",&a[i],&s[i]);
    }
}
void caculate(int s[],int n,int *ps,float *pa)
{
    int i=0;
    *ps=0;
    for(i=0;i<n;i++)
    {
        *ps+=s[i];
    }
    *pa=*ps/(float)n;
    printf("sum:%d\naver:%f\n\n",*ps,*pa);
}
void list_record(int s[],long a[],int n)
{
    int i=0;
    printf("\nID\t\tscore\n");
    for(i=0;i<n;i++)
    {
        printf("%ld\t%d\n",a[i],s[i]);
    }
}
void sort1(int s[],long a[],int n,int (*pFUN)(int a,int b))
{
    int s1[20],i,j,k;
    long a1[20],t;
    for(i=0;i<n;i++)
    {
        s1[i]=s[i];
        a1[i]=a[i];
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
        }
    }
    printf("ID\t\tscore\n");
    for(i=0;i<n;i++)
    {
        printf("%ld\t%d\n",a1[i],s1[i]);
    }
}
void sort2(int s[],long a[],int n)
{
    int s1[20],i,j,k;
    long a1[20],t;
    for(i=0;i<n;i++)
    {
        s1[i]=s[i];
        a1[i]=a[i];
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
        }
    }
    printf("ID\t\tscore\n");
    for(i=0;i<n;i++)
    {
        printf("%ld\t%d\n",a1[i],s1[i]);
    }
}
void look(int s[],long a[],int n)
{
    int s1[20],i,j,k,flag=0;
    long a1[20],t,x;
    printf("please input the student`s ID:");
    scanf("%ld",&x);
    for(i=0;i<n;i++)
    {
        s1[i]=s[i];
        a1[i]=a[i];
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
        }
    }
    for(i=0;i<n;i++)
    {
        if(a1[i]==x)
        {
            printf("ID\t\tscore\trank\n%ld\t%d\t%d\n",a1[i],s1[i],i+1);
            flag=1;
        }

    }
    if(flag==0) printf("Not found!Please check the ID!\n\n");
}
void apart(int s[],long a[],int n)
{
    int i;
    int count[6]={0};
    for(i=0;i<n;i++)
    {
        if(s[i]>=90)
        {
            count[0]++;;
        }
        if(s[i]>=80&&s[i]<=89)
        {
            count[1]++;
        }
        if(s[i]>=70&&s[i]<=79)
        {
            count[2]++;
        }
        if(s[i]>=60&&s[i]<=69)
        {
            count[3]++;
        }
        if(s[i]<=59)
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
int FUN1(int a,int b)
{
    if(a<b)
        return 1;
    else
        return 0;
}
int FUN2(int a,int b)
{
    if(a>b)
        return 1;
    else
        return 0;
}
