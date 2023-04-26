#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
const int ABO[8][8][8]={1,1,0,0,0,0,1,1,  1,1,0,0,0,0,1,1,  1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,  1,1,1,1,1,1,0,0,  1,1,1,1,1,1,0,0,  1,1,0,0,0,0,1,1,  1,1,0,0,0,0,1,1,
 1,1,0,0,0,0,1,1,  0,1,0,0,0,0,0,1,  1,1,1,1,1,1,1,1,  0,1,0,1,0,1,0,1,  1,1,1,1,1,1,0,0,  0,1,0,1,0,1,0,0,  1,1,0,0,0,0,1,1,  0,1,0,0,0,0,0,1,
 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,  0,0,1,1,0,0,1,1,  0,0,1,1,0,0,1,1,  1,1,1,1,1,1,0,0,  1,1,1,1,1,1,0,0,  0,0,1,1,0,0,1,1,  0,0,1,1,0,0,1,1,
 1,1,1,1,1,1,1,1,  0,1,0,1,0,1,0,1,  0,0,1,1,0,0,1,1,  0,0,0,1,0,0,0,1,  1,1,1,1,1,1,0,0,  0,1,0,1,0,1,0,0,  0,0,1,1,0,0,1,1,  0,0,0,1,0,0,0,1,
 1,1,1,1,1,1,0,0,  1,1,1,1,1,1,0,0,  1,1,1,1,1,1,0,0,  1,1,1,1,1,1,0,0,  1,1,1,1,1,1,0,0,  1,1,1,1,1,1,0,0,  1,1,1,1,0,0,0,0, 1,1,1,1,0,0,0,0,
 1,1,1,1,1,1,0,0,  0,1,0,1,0,1,0,0,  1,1,1,1,1,1,0,0,  0,1,0,1,0,1,0,0,  1,1,1,1,1,1,0,0,  0,1,0,1,0,1,0,0,  1,1,1,1,0,0,0,0,  0,1,0,1,0,0,0,0,
 1,1,0,0,0,0,1,1,  1,1,0,0,0,0,1,1,  0,0,1,1,0,0,1,1,  0,0,1,1,0,0,1,1,  1,1,1,1,0,0,0,0,  1,1,1,1,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,0,1,1,
 1,1,0,0,0,0,1,1,  0,1,0,0,0,0,0,1,  0,0,1,1,0,0,1,1,  0,0,0,1,0,0,0,1,  1,1,1,1,0,0,0,0,  0,1,0,1,0,0,0,0,  0,0,0,0,0,0,1,1,  0,0,0,0,0,0,0,1};
int read()
{
    char s[10];
    scanf("%s",s);
    int f=0;
    if(!strcmp(s,"A+"))
        f=1;
    else if(!strcmp(s,"B+"))
        f=3;
    else if(!strcmp(s,"A-"))
        f=2;
    else if(!strcmp(s,"B-"))
        f=4;
    else if (!strcmp(s,"AB+"))
        f=5;
    else if(!strcmp(s,"AB-"))
        f=6;
    else if(!strcmp(s,"O+"))
        f=7;
    else if(!strcmp(s,"O-"))
        f=8;
    else if(!strcmp(s,"?"))
        f=0;
    return f;
}
void print(int x,int type)
{
    if(type==1) printf("{");
    else if(type>1) printf(",");
    if(x==1) printf("A+");
    if(x==2) printf("A-");
    if(x==3) printf("B+");
    if(x==4) printf("B-");
    if(x==5) printf("AB+");
 if(x==6) printf("AB-");
  if(x==7) printf("O+");
   if(x==8) printf("O-");

}
void write(int ans_abo[])
{
    int abo=0;
    for(int i=0;i<8;i++)
        abo+=ans_abo[i];
    if(abo==0) printf("impossible");
    else
    {
        int cnt=0;
        for(int i=0;i<8;i++)
            if(ans_abo[i])
        {
            cnt++;
            print(i+1,cnt);
        }
        printf("}");
    }
}
int main()
{  int n;
scanf("%d",&n);
for (int i=0;i<n;i++){
    int ans_abo[8]={0};
int father,mother,child;
  father=read();mother=read();child=read();
  if(father==0)
    {int m1,c1;
    m1=mother-1;
    c1=child-1;
    for(int i=0;i<8;i++)
        ans_abo[i]=ABO[i][m1][c1];
  }
  if(mother==0)     {int f1,c1;
    f1=father-1;
    c1=child-1;
    for(int i=0;i<8;i++)
        ans_abo[i]=ABO[f1][i][c1];}
  if(child==0)     {int m1,f1;
    m1=mother-1;
    f1=father-1;
    for(int i=0;i<4;i++)
        ans_abo[i]=ABO[f1][m1][i];}
  if(father!=0) print(father,0);    else write(ans_abo);
  printf(" ");
   if(mother!=0) print(mother,0);     else write(ans_abo);
   printf(" ");
   if(child!=0) print(child,0);     else write(ans_abo);
   printf("\n");
}
return 0;
}
