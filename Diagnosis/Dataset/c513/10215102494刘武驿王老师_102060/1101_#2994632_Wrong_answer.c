#include<stdio.h>
#include<math.h>
#include<string.h>
const int Rh[2][2][2]={1,1,1,1,1,1,0,1};
const int ABO[4][4][4]=
{1,0,0,1,  1,1,1,0,  1,1,1,1,  1,0,0,1,
1,1,1,0,   1,1,1,0,   1,1,1,0,  1,0,1,0,
 1,1,1,1,  1,1,1,0,    0,0,1,1,  0,0,1,1,
1,0,0,1,   1,0,1,0,    0,0,1,1,  0,0,0,1};
int father,mother,child;
int ans_ABO[4];
int ans_Rh[2];
int read()
{
    char s[10];
    scanf("%s",s);
    int flag=0;
    if(!strcmp(s,"A+")) flag=1;
    else if(!strcmp(s,"A-")) flag=-1;
    else if(!strcmp(s,"B+")) flag=3;
    else if(!strcmp(s,"B-")) flag=-3;
    else if(!strcmp(s,"AB+")) flag=2;
    else if(!strcmp(s,"AB-")) flag=-2;
    else if(!strcmp(s,"O+")) flag=4;
    else if(!strcmp(s,"O-")) flag=-4;
    else if(!strcmp(s,"?")) flag=0;
    return flag;
}
void print(int x,int type)
{
    if(type==1) printf("{");
    else if(type>1) printf(",");
    if(x==1||x==-1) printf("A");
    if(x==2||x==-2) printf("AB");
    if(x==3||x==-3) printf("B");
    if(x==4||x==-4) printf("O");
    if(x>0) printf("+");
    else printf("-");
}
void write()
{
    int ABO=0,Rh=0;
    for(int i=0;i<4;i++)
        ABO+=ans_ABO[i];
    for(int i=0;i<2;i++)
        Rh+=ans_Rh[i];
    if(ABO*Rh==0) printf("impossible");
    if(ABO*Rh==1)
    {
        for(int i=0;i<4;i++)
            if(ans_ABO[i])
               for(int j=0;j<2;j++)
                  if(ans_Rh[j])
                   {
                    if(j==0) print(i+1,0);
                    else print(-i-1,0);
                   }
    }
    if(ABO*Rh>1)
    {
        int cnt=0;
        for(int i=0; i<4; i++)
            if(ans_ABO[i])
                for(int j=0; j<2; j++)
                    if(ans_Rh[j])
                    {
                        cnt++;
                        if(j==0) print(i+1,cnt);
                        else print(-i-1,cnt);
                    }
        printf("}");
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int _q=0;_q<n;_q++)
    {
    father=read();mother=read();child=read();
    if(father==0)
    {
         int m1,c1,m2,c2;
         if(mother>0) {m1=mother-1;m2=0;}
         else {m1=-1-mother;m2=1;}
         if(child>0) {c1=child-1;c2=0;}
         else {c1=-1-child;c2=1;}
         for(int i=0;i<4;i++)
            ans_ABO[i]=ABO[i][m1][c1];
          for(int i=0;i<2;i++)
            ans_Rh[i]=Rh[i][m2][c2];
    }
    if(mother==0)
    {
         int m1,c1,m2,c2;
         if(father>0) {m1=father-1;m2=0;}
         else {m1=-1-father;m2=1;}
         if(child>0) {c1=child-1;c2=0;}
         else {c1=-1-child;c2=1;}
         for(int i=0;i<4;i++)
            ans_ABO[i]=ABO[m1][i][c1];
          for(int i=0;i<2;i++)
            ans_Rh[i]=Rh[m2][i][c2];
    }
    if(child==0)
    {
        int m1,c1,m2,c2;
         if(father>0) {m1=father-1;m2=0;}
         else {m1=-1-father;m2=1;}
         if(mother>0) {c1=mother-1;c2=0;}
         else {c1=-1-mother;c2=1;}
         for(int i=0;i<4;i++)
            ans_ABO[i]=ABO[m1][c1][i];
          for(int i=0;i<2;i++)
            ans_Rh[i]=Rh[m2][c1][i];
    }
    if(father!=0) print(father,0);    else write();
    printf(" ");
    if(mother!=0) print(mother,0);     else write();
    printf(" ");
    if(child!=0) print(child,0);     else write();
    printf("\n");
    }
}
