#ifndef LIB_FOR_SYS_H_INCLUDED
#define LIB_FOR_SYS_H_INCLUDED

void print_menu(void);
void read(int s[],long a[],int *pn);
void caculate(int s[],int n,int *ps,float *pa);
void sort1(int s[],long a[],int n,int (*pFUN)(int a,int b));
void sort2(int s[],long a[],int n);
void look(int s[],long a[],int n);
void apart(int s[],long a[],int n);
void list_record(int s[],long a[],int n);
int FUN1(int a,int b);
int FUN2(int a,int b);
#endif // LIB_FOR_SYS_H_INCLUDED
