#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*A-0 AB-1 B-2 O-3*/
const int ABO[4][4][4]={1,0,0,1, 1,1,1,0, 1,1,1,1,  1,0,0,1, 
                        1,1,1,0, 1,1,1,0, 1,1,1,0, 1,0,1,0, 
                        1,1,1,1, 1,1,1,0, 0,0,1,1, 0,0,1,1,
                        1,0,0,1, 1,1,0,0, 0,0,1,1, 0,0,0,1};
const int Rh[2][2][2]={1,1, 1,1, 1,1, 0,1};
int ansABO[4],ansRh[2];
int read()
{
    char s[10];
    int flag;
    scanf("%s",s);
    if(!strcmp(s,"A+")) flag=1;
    if(!strcmp(s,"A-")) flag=-1;
    if(!strcmp(s,"AB+")) flag=2;
    if(!strcmp(s,"AB-")) flag=-2;
    if(!strcmp(s,"B+")) flag=3;
    if(!strcmp(s,"B-")) flag=-3;
    if(!strcmp(s,"O+")) flag=4;
    if(!strcmp(s,"O+")) flag=-4;
    if(!strcmp(s,"?")) flag=0;
    return flag;
}
void print(int x,int type)
{if(type==1) printf("{");
 if(type>1)  printf(",");
 if(x==1||x==-1) printf("A");
 if(x==-2||x==2) printf("AB");
 if(x==3||x==-3) printf("B");
 if(x==4||x==-4) printf("O");
 if(x>0) printf("+");
 else printf("-");

}
void write()
{
    int abo=0,rh=0,i,j;
    for( i=0;i<4;i++)
    {
        abo+=ansABO[i];
    }
    for( i=0;i<2;i++)
    {
        rh+=ansRh[i];
    }
    if(abo*rh==0) printf("impossible");
    if(abo*rh==1)
    {
        for(i=0;i<4;i++)
        {
            if(ansABO[i])
            {
                for(j=0;j<2;j++)
                {
                    if(ansRh[j])
                    {
                        if(j){print(-i-1,0);}
                        else {print(i+1,0);}
                    }
                }
            }
        }
    }
    if(abo*rh>1)
    {
        int cnt=0;
        for(int i=0;i<4;i++)
        {
            if(ansABO[i])
            {
                for(j=0;j<2;j++)
                {
                    if(ansRh[j])
                    {
                        cnt++;
                        if(j){print(-i-1,cnt);}
                        else {print(i+1,cnt);}

                    }
                }
            }
        }
        printf("}");
    }
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {int father,mother,child;
 father=read();
 mother=read();
 child=read();
 if(father==0)
 {
     int c1,m1,c2,m2;
     if(mother>0){c1=0;m1=mother-1;}
     else{c1=1;m1=-mother-1;}
     if(child>0){c2=0;m2=child-1;}
     else{c2=1;m2=-child-1;}
     for(int j=0;j<4;j++)
     {
         ansABO[j]=ABO[j][m1][m2];

     }
     for(int j=0;j<2;j++)
     {
         ansRh[j]=Rh[j][c1][c2];

     }

 }
 if(mother==0)
 {
   int c1,m1,c2,m2;
     if(father>0){c1=0;m1=father-1;}
     else{c1=1;m1=-father-1;}
     if(child>0){c2=0;m2=child-1;}
     else{c2=1;m2=-child-1;}
     for(int j=0;j<4;j++)
     {
         ansABO[j]=ABO[m1][j][m2];

     }
     for(int j=0;j<2;j++)
     {
         ansRh[j]=Rh[c1][j][c2];

     }
 }
 if(child==0)
 {
     int c1,m1,c2,m2;
     if(father>0){c1=0;m1=father-1;}
     else{c1=1;m1=-father-1;}
     if(mother>0){c2=0;m2=mother-1;}
     else{c1=1;m2=-mother-1;}
     for(int j=0;j<4;j++)
     {
         ansABO[j]=ABO[m1][m2][j];

     }
     for(int j=0;j<2;j++)
     {
         ansRh[j]=Rh[c1][c2][j];

     }
 }
 if(father){print(father,0);}
 else{write();}
 printf(" ");
 if(mother){print(mother,0);}
 else{write();}
 printf(" ");
 if(child){print(child,0);}
 else{write();}
 printf("\n");

}
}
