#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ABO[4][4][4] = {1,0,0,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1};
int Rh[2][2][2] = {1,1,1,1,1,1,0,1};
int ans_ABO[5],ans_Rh[3];

int read()
{
    char s[10];int flag = 0;
    scanf("%s",s);
    if(!strcmp(s,"A+"))flag = 1;
    else if(!strcmp(s,"A-"))flag = -1;
    else if(!strcmp(s,"AB+"))flag = 2;
    else if(!strcmp(s,"AB-"))flag = -2;
    else if(!strcmp(s,"B+"))flag = 3;
    else if(!strcmp(s,"B-"))flag = -3;
    else if(!strcmp(s,"O+"))flag = 4;
    else if(!strcmp(s,"O-"))flag = -4;//通过这些flag的值确定排列数；
    else if(!strcmp(s,"?"))flag = 0;
    return flag;
}

void print(int x,int type)
{
    if(type == 1)printf("{");
    else if(type > 1)printf(",");
    if(x == 1 || x == -1)printf("A");
    if(x == 2 || x == -2)printf("AB");
    if(x == 3 || x == -3)printf("B");
    if(x == 4 || x == -4)printf("O");
    if(x > 0)printf("+");//判断Rh阴性或阳性；
    else if(x < 0)printf("-");
}

void write()
{
    int i,j,ans1 = 0,ans2 = 0,cnt;
    for(i = 0; i < 4; i++)ans1 += ans_ABO[i];
    for(i = 0; i < 2; i++)ans2 += ans_Rh[i];
    if(ans1*ans2 == 0)printf("impossible");//ans1*ans2的结果代表了有多少种结果，为0则没有可能的结果；
    else if(ans1*ans2 == 1)
       {
        for(i = 0; i < 4; i++)
            if(ans_ABO[i])
              for(j = 0; j < 2; j++)
                 if(ans_Rh[j])
                  {
                     if(j == 0)print(i+1,0);//i+1和-i-1分别是判断血型类型；
                     else print(-i-1,0);
                  }
        }
    else if(ans1*ans2 > 1)
       {
        for(i = 0,cnt = 0; i < 4; i++)
            if(ans_ABO[i])
              for(j = 0; j < 2; j++)
                 if(ans_Rh[j])
                  {
                      cnt++;//记录种类数，方便计入函数；
                     if(j == 0)print(i+1,cnt);
                     else print(-i-1,cnt);
                  }
         printf("}");
         //printf("%d",ans1*ans2);
       }
}

int main()
{
    int father,mother,child,i,f1,f2,m1,m2,c1,c2;
    int cas,k;
    scanf("%d",&cas);
    for(k = 0; k < cas; k++)
    {
        father = read();mother = read();child = read();
        if(!father)
       {
        if(mother > 0){m1 = mother-1;m2 = 0;}
        else {m1 = -1-mother;m2 = 1;}
        if(child > 0){c1 = child-1;c2 = 0;}
        else {c1 = -1-child;c2 = 1;}
        for(i = 0; i < 4; i++)ans_ABO[i] = ABO[i][m1][c1];//选择在这种情况下的组合情况；（对照表看）
        for(i = 0; i < 2; i++)ans_Rh[i] = Rh[i][m2][c2];
        write();printf(" ");
        print(mother,0);printf(" ");
        print(child,0);printf(" ");
        printf("\n");
        }
        if(!mother)
       {
        if(father > 0){f1 = father-1;f2 = 0;}
        else {f1 = -1-father;f2 = 1;}
        if(child > 0){c1 = child-1;c2 = 0;}
        else {c1 = -1-child;c2 = 1;}
        for(i = 0; i < 4; i++)ans_ABO[i] = ABO[f1][i][c1];
        for(i = 0; i < 2; i++)ans_Rh[i] = Rh[f2][i][c2];
        print(father,0);printf(" ");
        write();printf(" ");
        print(child,0);printf(" ");
        printf("\n");
       }
       if(!child)
      {
        if(father > 0){f1 = father-1;f2 = 0;}
        else {f1 = -1-father;f2 = 1;}
        if(mother > 0){m1 = mother-1;m2 = 0;}
        else {m1 = -1-mother;m2 = 1;}
        for(i = 0; i < 4; i++)ans_ABO[i] = ABO[f1][m1][i];
        for(i = 0; i < 2; i++)ans_Rh[i] = Rh[f2][m2][i];
        print(father,0);printf(" ");
        print(mother,0);printf(" ");
        write();
        printf("\n");
       }
    }
    return 0;
}