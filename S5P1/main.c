#include <stdio.h>
#include "lib_for_sys.h"
int main(void)
{
    int s[50],sum,choice,flag=0,f_exit=0,n;
    long a[50];
    float aver;
    printf("Name:A-mess\n\n");
    while(1)
    {
        print_menu();
        while(scanf("%d",&choice)!=1||choice<1||choice>9)
        {
            while(getchar()!='\n');
            printf("please input the choice above:");
        }
        printf("\n");
        switch(choice)
        {
        case 1:
            read(s,a,&n);
            flag=1;
            break;
        case 2:
            if(flag==0)
            {
                printf("please inupt record first!\n\n");
                break;
            }
            else
            {
                caculate(s,n,&sum,&aver);
            }
            break;
        case 3:
            if(flag==0)
            {
                printf("please inupt record first!\n\n");
                break;
            }
            else
            {
                sort1(s,a,n,FUN1);
            }
            break;
        case 4:
            if(flag==0)
            {
                printf("please inupt record first!\n\n");
                break;
            }
            else
            {
                sort1(s,a,n,FUN2);
            }
            break;
        case 5:
            if(flag==0)
            {
                printf("please inupt record first!\n\n");
                break;
            }
            else
            {
                sort2(s,a,n);
            }
            break;
        case 6:
            if(flag==0)
            {
                printf("please inupt record first!\n\n");
                break;
            }
            else
            {
                look(s,a,n);
            }
            break;
        case 7:
            if(flag==0)
            {
                printf("please inupt record first!\n\n");
                break;
            }
            else
            {
                apart(s,a,n);
            }
            break;
        case 8:
            if(flag==0)
            {
                printf("please inupt record first!\n\n");
                break;
            }
            else
            {
                list_record(s,a,n);
            }
            break;
        case 9:
            printf("exit!");
            f_exit=1;
            break;
        }
        if(f_exit==1) break;
    }
}
/*
15
200210001 97
200210089 46
200210023 71
200210004 13
200210301 0
200210302 60
200210303 54
200210304 79
200210325 100
200210306 98
200210225 82
200210665 12
200210779 56
200100008 79
256564211 47
*/
//
