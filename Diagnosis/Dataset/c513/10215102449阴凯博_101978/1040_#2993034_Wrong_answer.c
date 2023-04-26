#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int ABO[4][4][4]=
{1,0,0,1, 1,1,1,0, 1,1,1,1, 1,0,0,1,
1,1,1,0, 1,1,1,0, 1,1,1,0, 1,0,1,0,
1,1,1,1, 1,1,1,0, 0,0,1,1, 0,0,1,1,
1,0,0,1, 1,0,1,0, 0,0,1,1, 0,0,0,1};



int* read()
{
    char s[100],s1[100],s2[100];
    scanf("%s",s);
    int*flag=(int*)calloc(2,sizeof(int));
    int i,j;
    for (i=0;i<strlen(s) && isalpha(s[i]);i++)
        s1[i]=s[i];
    s1[i]=0;
    if (!strcmp(s1,"A")) flag[0]=1;
    else if (!strcmp(s1,"B")) flag[0]=3;
    else if (!strcmp(s1,"AB")) flag[0]=2;
    else if (!strcmp(s1,"O")) flag[0]=4;
    else if (!strcmp(s1,"?")) flag[0]=0;
    if (flag[0])
    {
        for (i,j=0;i<strlen(s);i++,j++)
            s2[j]=s[i];
        s2[j]=0;
        if (!strcmp(s2,"+")) flag[1]=2;
        if (!strcmp(s2,"-")) flag[1]=1;
    }
    return flag;

}

void print(int x,int type,int Rh)
{
    if (type>1) printf(",");
    if (x==1)
    {
        printf("A");
        if (Rh==1)
            printf("+,A-");
        else if (Rh==0)
            printf("-");
        else if (Rh==-1)
            printf("+");
    }
     if (x==2)
    {
        printf("AB");
        if (Rh==1)
            printf("+,AB-");
        else if (Rh==0)
            printf("-");
        else if (Rh==-1)
            printf("+");
    }
     if (x==3)
    {
        printf("B");
        if (Rh==1)
            printf("+,B-");
        else if (Rh==0)
            printf("-");
        else if (Rh==-1)
            printf("+");
    }
     if (x==4)
    {
        printf("O");
        if (Rh==1)
            printf("+,O-");
        else if (Rh==0)
            printf("-");
        else if (Rh==-1)
            printf("+");
    }

}

void write(int ans_ABO[4], int Rh)
{
    int ABO=0;
    for (int i=0;i<4;i++)
        ABO+=ans_ABO[i];
    if (ABO==0) printf("impossible");
    else
    {
        int cnt=0;
        for (int i=0;i<4;i++)
            if (ans_ABO[i])
            {
                cnt++;
            }
        if (cnt>1 || (cnt==1 && Rh))
        {
            printf("{");
            cnt=0;
            for (int i=0;i<4;i++)
            if (ans_ABO[i])
            {
                cnt++;
                print(i+1,cnt,Rh);
            }
            printf("}");
        }
        else
        {
            cnt=0;
            for (int i=0;i<4;i++)
            if (ans_ABO[i])
            {
                cnt++;
                print(i+1,cnt,Rh);
            }
        }




    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int ans_ABO[4]={0}, ans_Rh=0;
        int* father; int* mother; int* child;
        father=read();  mother=read();  child=read();
        if (father[0]==0)
        {
            int m1,c1,m2,c2;
            m1=mother[0]-1;
            c1=child[0]-1;
            m2=mother[1]-1;
            c2=child[1]-1;
            for (int j=0;j<4;j++)
                ans_ABO[j]=ABO[j][m1][c1];
            if (c2==1 && m2==0)
                ans_Rh=-1;
            else
                ans_Rh=1;

        }
        if (mother[0]==0)
        {
            int f1,c1,f2,c2;
            f1=father[0]-1;
            c1=child[0]-1;
            f2=father[1]-1;
            c2=child[1]-1;
            for (int j=0;j<4;j++)
                ans_ABO[j]=ABO[f1][j][c1];
            if (c2==1 && f2==0)
                ans_Rh=-1;
            else
                ans_Rh=1;
        }
        if (child[0]==0)
        {
            int f1,m1,f2,m2;
            f1=father[0]-1;
            m1=mother[0]-1;
            f2=father[1]-1;
            m2=mother[1]-1;
            for (int j=0;j<4;j++)
                ans_ABO[j]=ABO[f1][m1][j];
            ans_Rh=f2|m2;
        }
        if (father[0]!=0) print(father[0],0,(father[1]-1)?-1:0); else write(ans_ABO,ans_Rh);
        printf(" ");
        if (mother[0]!=0) print(mother[0],0,(mother[1]-1)?-1:0); else write(ans_ABO,ans_Rh);
        printf(" ");
        if (child[0]!=0) print(child[0],0,(child[1]-1)?-1:0); else write(ans_ABO,ans_Rh);
        printf("\n");
        free(father); free(mother); free(child);
    }
    return 0;
}
