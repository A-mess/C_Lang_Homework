#include <stdio.h>
#include "lib_for_sys.h"
int main(void)
{
    int score[50],sum,choice,flag=0,f_exit=0,n;
    long ID[50];
    float aver;
    char name[50][30]={0};
    printf("Name:Amess\n\n");
    while(1)
    {
        print_menu();
        while(scanf("%d",&choice)!=1||choice<1||choice>11)
        {
            while(getchar()!='\n');
            printf("please input the choice above:");
        }
        printf("\n");
        switch(choice)
        {
        case 1:
            read(score,ID,name,&n);
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
                caculate(score,n,&sum,&aver);
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
                sort_score(score,ID,name,n,descend);
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
                sort_score(score,ID,name,n,ascend);
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
                sort_ID(score,ID,name,n);
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
                sort_name(score,ID,name,n);
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
                find_ID(score,ID,name,n);
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
                find_name(score,ID,name,n);
            }
            break;
        case 9:
            if(flag==0)
            {
                printf("please inupt record first!\n\n");
                break;
            }
            else
            {
                analysis(score,ID,n);
            }
            break;
        case 10:
            if(flag==0)
            {
                printf("please inupt record first!\n\n");
                break;
            }
            else
            {
                list_record(score,ID,name,n);
            }
            break;
        case 11:
            printf("exit!");
            f_exit=1;
            break;
        }
        if(f_exit==1) break;
    }
}
/*
15
200210001 tefer 97
200210089 hychai 46
200210023 meder 71
200210004 nelander 13
200210301 kaloke 0
200210302 eberter 60
200210303 peter 54
200210304 ich 79
200210325 cqy 100
200210306 amy 98
200210225 kete 82
200210665 wander 12
200210779 jimi 56
200100008 lancy 79
256564211 luke 47
*/
//
