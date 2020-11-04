#ifndef LIB_FOR_SYS_H_INCLUDED
#define LIB_FOR_SYS_H_INCLUDED

void print_menu(void);
void read(int score[],long ID[],char name[][30],int *pn);
void caculate(int score[],int n,int *ps,float *pa);
void sort_score(int score[],long ID[],char name[][30],int n,int (*pFUN)(int a,int b));
void sort_ID(int score[],long ID[],char name[][30],int n);
void sort_name(int score[],long ID[],char name[][30],int n);
void find_ID(int score[],long ID[],char name[][30],int n);
void find_name(int score[],long ID[],char name[][30],int n);
void analysis(int score[],long ID[],int n);
void list_record(int score[],long ID[],char name[][30],int n);
int descend(int a,int b);
int ascend(int a,int b);

#endif // LIB_FOR_SYS_H_INCLUDED
