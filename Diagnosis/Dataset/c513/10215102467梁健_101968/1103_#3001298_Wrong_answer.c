#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
long long a[5]={0};
char name[4][3]={"AX","BX","CX","DX"};
void IN()
{
    char ord[20];scanf("%s",ord);
    int nump=3;char num[15];
    for(int i=3;i<strlen(ord);i++){
        num[i-3]=ord[i];
    }
    int n=atoi(num);
    char ORD[3];
    ORD[0]=ord[0];ORD[1]=ord[1];ORD[2]=0;
    for(int i=0;i<4;i++){
        if(strcmp(ORD,name[i])==0){
            a[i]=n;
            printf("IN %s=%lld\n",ORD,a[i]);
        }
    }
}

void MOV()
{
    char ord[20];scanf("%s",ord);
    int m1=-1,m2=-1;
    char M1[3],M2[3];
    M1[0]=ord[0];M1[1]=ord[1];M1[2]=0;
    M2[0]=ord[3];M2[1]=ord[4];M2[2]=0;
    for(int i=0;i<4;i++){
        if(strcmp(name[i],M1)==0)m1=i;
        if(strcmp(name[i],M2)==0)m2=i;
    }
    a[m1]=a[m2];
    printf("MOV %s=%s,%s=%lld\n",M1,M2,M1,a[m1]);
}

void ADD()
{
    char ord[20];scanf("%s",ord);
    int m1=-1,m2=-1;
    char M1[3],M2[3];
    M1[0]=ord[0];M1[1]=ord[1];M1[2]=0;
    M2[0]=ord[3];M2[1]=ord[4];M2[2]=0;
    for(int i=0;i<4;i++){
        if(strcmp(name[i],M1)==0)m1=i;
        if(strcmp(name[i],M2)==0)m2=i;
    }
    a[m1]+=a[m2];
    printf("ADD %s=%lld\n",M1,a[m1]);
}

void SUB()
{
    char ord[20];scanf("%s",ord);
    int m1=-1,m2=-1;
    char M1[3],M2[3];
    M1[0]=ord[0];M1[1]=ord[1];M1[2]=0;
    M2[0]=ord[3];M2[1]=ord[4];M2[2]=0;
    for(int i=0;i<4;i++){
        if(strcmp(name[i],M1)==0)m1=i;
        if(strcmp(name[i],M2)==0)m2=i;
    }
    a[m1]-=a[m2];
    printf("SUB %s=%lld\n",M1,a[m1]);
}

void MUL()
{
    char ord[20];scanf("%s",ord);
    int m1=-1,m2=-1;
    char M1[3],M2[3];
    M1[0]=ord[0];M1[1]=ord[1];M1[2]=0;
    M2[0]=ord[3];M2[1]=ord[4];M2[2]=0;
    for(int i=0;i<4;i++){
        if(strcmp(name[i],M1)==0)m1=i;
        if(strcmp(name[i],M2)==0)m2=i;
    }
    a[m1]*=a[m2];
    printf("MUL %s=%lld\n",M1,a[m1]);
}

void DIV()
{
    char ord[20];scanf("%s",ord);
    int m1=-1,m2=-1;
    char M1[3],M2[3];
    M1[0]=ord[0];M1[1]=ord[1];M1[2]=0;
    M2[0]=ord[3];M2[1]=ord[4];M2[2]=0;
    for(int i=0;i<4;i++){
        if(strcmp(name[i],M1)==0)m1=i;
        if(strcmp(name[i],M2)==0)m2=i;
    }
    if(a[m2]!=0)a[m1]/=a[m2];
    printf("DIV %s=%lld\n",M1,a[m1]);
}

void OUT()
{
    char ord[20];scanf("%s",ord);
    int m1=-1;
    char M1[3];
    M1[0]=ord[0];M1[1]=ord[1];M1[2]=0;
    for(int i=0;i<4;i++){
        if(strcmp(name[i],M1)==0)m1=i;
    }
    printf("AX=%lld BX=%lld CX=%lld DX=%lld\n",a[0],a[1],a[2],a[3]);
    printf("%lld\n",a[m1]);
}

int main()
{
    char s[3];
    char z[7][4]={{"IN"},{"MOV"},{"ADD"},{"SUB"},{"MUL"},{"DIV"},{"OUT"}};
    while(scanf("%s",s)!=EOF){
        if(strcmp(s,z[0])==0)IN();
        else if(strcmp(s,z[1])==0)MOV();
        else if(strcmp(s,z[2])==0)ADD();
        else if(strcmp(s,z[3])==0)SUB();
        else if(strcmp(s,z[4])==0)MUL();
        else if(strcmp(s,z[5])==0)DIV();
        else if(strcmp(s,z[6])==0)OUT();
    }

    return 0;
}
