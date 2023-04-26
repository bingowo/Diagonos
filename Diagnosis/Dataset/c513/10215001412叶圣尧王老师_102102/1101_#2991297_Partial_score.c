#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void val1(char b[],char c[])
{
    if(strcmp(b,"A+")==0&&strcmp(c,"A+")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"A-")==0&&strcmp(c,"A+")==0)printf("{A+,AB+,B+,O+}");
    else if(strcmp(b,"B+")==0&&strcmp(c,"A+")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(b,"B-")==0&&strcmp(c,"A+")==0)printf("{A+,AB+,B+,O+}");
    else if(strcmp(b,"AB+")==0&&strcmp(c,"A+")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"AB-")==0&&strcmp(c,"A+")==0)printf("{A+,AB+,B+,O+}");
    else if(strcmp(b,"O+")==0&&strcmp(c,"A+")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(b,"O-")==0&&strcmp(c,"A+")==0)printf("{A+,AB+}");
    else if(strcmp(b,"A+")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"A-")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"B+")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(b,"B-")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(b,"AB+")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"AB-")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"O+")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(b,"O-")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(b,"A+")==0&&strcmp(c,"B+")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(b,"A-")==0&&strcmp(c,"B+")==0)printf("{AB+,B+}");
    else if(strcmp(b,"B+")==0&&strcmp(c,"B+")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"B-")==0&&strcmp(c,"B+")==0)printf("{A+,AB+,B+,O+}");
    else if(strcmp(b,"AB+")==0&&strcmp(c,"B+")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"AB-")==0&&strcmp(c,"B+")==0)printf("{A+,AB+;B+,O+}");
    else if(strcmp(b,"O+")==0&&strcmp(c,"B+")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(b,"O-")==0&&strcmp(c,"B+")==0)printf("{AB+,B+}");
    else if(strcmp(b,"A+")==0&&strcmp(c,"B-")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(b,"A-")==0&&strcmp(c,"B-")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(b,"B+")==0&&strcmp(c,"B-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"B-")==0&&strcmp(c,"B-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"AB+")==0&&strcmp(c,"B-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"AB-")==0&&strcmp(c,"B-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"O+")==0&&strcmp(c,"B-")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(b,"O-")==0&&strcmp(c,"B-")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(b,"A+")==0&&strcmp(c,"AB+")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(b,"A-")==0&&strcmp(c,"AB+")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(b,"B+")==0&&strcmp(c,"AB+")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(b,"B-")==0&&strcmp(c,"AB+")==0)printf("{A+,AB+}");
    else if(strcmp(b,"AB+")==0&&strcmp(c,"AB+")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"AB-")==0&&strcmp(c,"AB+")==0)printf("{A+,AB+,B+}");
    else if(strcmp(b,"O+")==0&&strcmp(c,"AB+")==0)printf("impossible");
    else if(strcmp(b,"O-")==0&&strcmp(c,"AB+")==0)printf("impossible");
    else if(strcmp(b,"A+")==0&&strcmp(c,"AB-")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(b,"A-")==0&&strcmp(c,"AB-")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(b,"B+")==0&&strcmp(c,"AB-")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(b,"B-")==0&&strcmp(c,"AB-")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(b,"AB+")==0&&strcmp(c,"AB-")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"AB-")==0&&strcmp(c,"AB-")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"O+")==0&&strcmp(c,"AB-")==0)printf("impossible");
    else if(strcmp(b,"O-")==0&&strcmp(c,"AB-")==0)printf("impossible");
    else if(strcmp(b,"A+")==0&&strcmp(c,"O+")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(b,"A-")==0&&strcmp(c,"O+")==0)printf("{A+,B+,O+}");
    else if(strcmp(b,"B+")==0&&strcmp(c,"O+")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(b,"B-")==0&&strcmp(c,"O+")==0)printf("{A+,B+,O+}");
    else if(strcmp(b,"AB+")==0&&strcmp(c,"O+")==0)printf("impossible");
    else if(strcmp(b,"AB-")==0&&strcmp(c,"O+")==0)printf("impossible");
    else if(strcmp(b,"O+")==0&&strcmp(c,"O+")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(b,"O-")==0&&strcmp(c,"O+")==0)printf("{A+,B+,O+}");
    else if(strcmp(b,"A+")==0&&strcmp(c,"O-")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(b,"A-")==0&&strcmp(c,"O-")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(b,"B+")==0&&strcmp(c,"O-")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(b,"B-")==0&&strcmp(c,"O-")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(b,"AB+")==0&&strcmp(c,"O-")==0)printf("impossible");
    else if(strcmp(b,"AB-")==0&&strcmp(c,"O-")==0)printf("impossible");
    else if(strcmp(b,"O+")==0&&strcmp(c,"O-")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(b,"O-")==0&&strcmp(c,"O-")==0)printf("{A+,A-,B+,B-,O+,O-}");
}

void val2(char a[],char c[])
{
    if(strcmp(a,"A+")==0&&strcmp(c,"A+")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(a,"A-")==0&&strcmp(c,"A+")==0)printf("{A+,AB+,B+,O+}");
    else if(strcmp(a,"B+")==0&&strcmp(c,"A+")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(a,"B-")==0&&strcmp(c,"A+")==0)printf("{A+,AB+,B+,O+}");
    else if(strcmp(a,"AB+")==0&&strcmp(c,"A+")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(a,"AB-")==0&&strcmp(c,"A+")==0)printf("{A+,AB+,B+,O+}");
    else if(strcmp(a,"O+")==0&&strcmp(c,"A+")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(a,"O-")==0&&strcmp(c,"A+")==0)printf("{A+,AB+}");
    else if(strcmp(a,"A+")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(a,"A-")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(a,"B+")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(a,"B-")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(a,"AB+")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(a,"AB-")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(a,"O+")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(a,"O-")==0&&strcmp(c,"A-")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(a,"A+")==0&&strcmp(c,"B+")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(a,"A-")==0&&strcmp(c,"B+")==0)printf("{AB+,B+}");
    else if(strcmp(a,"B+")==0&&strcmp(c,"B+")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(a,"B-")==0&&strcmp(c,"B+")==0)printf("{A+,AB+,B+,O+}");
    else if(strcmp(a,"AB+")==0&&strcmp(c,"B+")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(a,"AB-")==0&&strcmp(c,"B+")==0)printf("{A+,AB+;B+,O+}");
    else if(strcmp(a,"O+")==0&&strcmp(c,"B+")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(a,"O-")==0&&strcmp(c,"B+")==0)printf("{AB+,B+}");
    else if(strcmp(a,"A+")==0&&strcmp(c,"B-")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(a,"A-")==0&&strcmp(c,"B-")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(a,"B+")==0&&strcmp(c,"B-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(a,"B-")==0&&strcmp(c,"B-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(a,"AB+")==0&&strcmp(c,"B-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(a,"AB-")==0&&strcmp(c,"B-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(a,"O+")==0&&strcmp(c,"B-")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(a,"O-")==0&&strcmp(c,"B-")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(a,"A+")==0&&strcmp(c,"AB+")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(a,"A-")==0&&strcmp(c,"AB+")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(a,"B+")==0&&strcmp(c,"AB+")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(a,"B-")==0&&strcmp(c,"AB+")==0)printf("{A+,AB+}");
    else if(strcmp(a,"AB+")==0&&strcmp(c,"AB+")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(a,"AB-")==0&&strcmp(c,"AB+")==0)printf("{A+,AB+,B+}");
    else if(strcmp(a,"O+")==0&&strcmp(c,"AB+")==0)printf("impossible");
    else if(strcmp(a,"O-")==0&&strcmp(c,"AB+")==0)printf("impossible");
    else if(strcmp(a,"A+")==0&&strcmp(c,"AB-")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(a,"A-")==0&&strcmp(c,"AB-")==0)printf("{AB+,AB-,B+,B-}");
    else if(strcmp(a,"B+")==0&&strcmp(c,"AB-")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(a,"B-")==0&&strcmp(c,"AB-")==0)printf("{A+,A-,AB+,AB-}");
    else if(strcmp(a,"AB+")==0&&strcmp(c,"AB-")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(a,"AB-")==0&&strcmp(c,"AB-")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(a,"O+")==0&&strcmp(c,"AB-")==0)printf("impossible");
    else if(strcmp(a,"O-")==0&&strcmp(c,"AB-")==0)printf("impossible");
    else if(strcmp(a,"A+")==0&&strcmp(c,"O+")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(a,"A-")==0&&strcmp(c,"O+")==0)printf("{A+,B+,O+}");
    else if(strcmp(a,"B+")==0&&strcmp(c,"O+")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(a,"B-")==0&&strcmp(c,"O+")==0)printf("{A+,B+,O+}");
    else if(strcmp(a,"AB+")==0&&strcmp(c,"O+")==0)printf("impossible");
    else if(strcmp(a,"AB-")==0&&strcmp(c,"O+")==0)printf("impossible");
    else if(strcmp(a,"O+")==0&&strcmp(c,"O+")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(a,"O-")==0&&strcmp(c,"O+")==0)printf("{A+,B+,O+}");
    else if(strcmp(a,"A+")==0&&strcmp(c,"O-")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(a,"A-")==0&&strcmp(c,"O-")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(a,"B+")==0&&strcmp(c,"O-")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(a,"B-")==0&&strcmp(c,"O-")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(a,"AB+")==0&&strcmp(c,"O-")==0)printf("impossible");
    else if(strcmp(a,"AB-")==0&&strcmp(c,"O-")==0)printf("impossible");
    else if(strcmp(a,"O+")==0&&strcmp(c,"O-")==0)printf("{A+,A-,B+,B-,O+,O-}");
    else if(strcmp(a,"O-")==0&&strcmp(c,"O-")==0)printf("{A+,A-,B+,B-,O+,O-}");
}

void val3(char a[],char b[])
{
    if(strcmp(b,"A+")==0&&strcmp(a,"A+")==0)printf("{A+,A-,O+,O-}");
    else if(strcmp(b,"A-")==0&&strcmp(a,"A+")==0)printf("{A+,A-,O+,O-}");
    else if(strcmp(b,"B+")==0&&strcmp(a,"A+")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"B-")==0&&strcmp(a,"A+")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"AB+")==0&&strcmp(a,"A+")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"AB-")==0&&strcmp(a,"A+")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"O+")==0&&strcmp(a,"A+")==0)printf("{A+,A-,O+,O-}");
    else if(strcmp(b,"O-")==0&&strcmp(a,"A+")==0)printf("{A+,A-,O+,O-}");
    else if(strcmp(b,"A+")==0&&strcmp(a,"A-")==0)printf("{A+,A-,O+,O-}");
    else if(strcmp(b,"A-")==0&&strcmp(a,"A-")==0)printf("{A-,O-}");
    else if(strcmp(b,"B+")==0&&strcmp(a,"A-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"B-")==0&&strcmp(a,"A-")==0)printf("{A-,AB-,B-,O-}");
    else if(strcmp(b,"AB+")==0&&strcmp(a,"A-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"AB-")==0&&strcmp(a,"A-")==0)printf("{A-,AB-,B-,O-}");
    else if(strcmp(b,"O+")==0&&strcmp(a,"A-")==0)printf("{A+,A-,O+,O-}");
    else if(strcmp(b,"O-")==0&&strcmp(a,"A-")==0)printf("{A-,O-}");
    else if(strcmp(b,"A+")==0&&strcmp(a,"B+")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"A-")==0&&strcmp(a,"B+")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"B+")==0&&strcmp(a,"B+")==0)printf("{B+,B-,O+,O-}");
    else if(strcmp(b,"B-")==0&&strcmp(a,"B+")==0)printf("{B+,B-,O+,O-}");
    else if(strcmp(b,"AB+")==0&&strcmp(a,"B+")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"AB-")==0&&strcmp(a,"B+")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"O+")==0&&strcmp(a,"B+")==0)printf("{B+,B-,O+,O-}");
    else if(strcmp(b,"O-")==0&&strcmp(a,"B+")==0)printf("{B+,B-,O+,O-}");
    else if(strcmp(b,"A+")==0&&strcmp(a,"B-")==0)printf("{A+,A-,AB+,AB-,B+,B-,O+,O-}");
    else if(strcmp(b,"A-")==0&&strcmp(a,"B-")==0)printf("{A-,AB-,B-,O-}");
    else if(strcmp(b,"B+")==0&&strcmp(a,"B-")==0)printf("{B+,B-,O+,O-}");
    else if(strcmp(b,"B-")==0&&strcmp(a,"B-")==0)printf("{B-,O-}");
    else if(strcmp(b,"AB+")==0&&strcmp(a,"B-")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"AB-")==0&&strcmp(a,"B-")==0)printf("{A-,AB-,B-}");
    else if(strcmp(b,"O+")==0&&strcmp(a,"B-")==0)printf("{B+,B-,O+,O-}");
    else if(strcmp(b,"O-")==0&&strcmp(a,"B-")==0)printf("{B-,O-}");
    else if(strcmp(b,"A+")==0&&strcmp(a,"AB+")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"A-")==0&&strcmp(a,"AB+")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"B+")==0&&strcmp(a,"AB+")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"B-")==0&&strcmp(a,"AB+")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"AB+")==0&&strcmp(a,"AB+")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"AB-")==0&&strcmp(a,"AB+")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"O+")==0&&strcmp(a,"AB+")==0)printf("{A+,A-,B+,B-}");
    else if(strcmp(b,"O-")==0&&strcmp(a,"AB+")==0)printf("{A+,A-,B+,B-}");
    else if(strcmp(b,"A+")==0&&strcmp(a,"AB-")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"A-")==0&&strcmp(a,"AB-")==0)printf("{A-,AB-,B-}");
    else if(strcmp(b,"B+")==0&&strcmp(a,"AB-")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"B-")==0&&strcmp(a,"AB-")==0)printf("{A-,AB-,B-}");
    else if(strcmp(b,"AB+")==0&&strcmp(a,"AB-")==0)printf("{A+,A-,AB+,AB-,B+,B-}");
    else if(strcmp(b,"AB-")==0&&strcmp(a,"AB-")==0)printf("{A-,AB-,B-}");
    else if(strcmp(b,"O+")==0&&strcmp(a,"AB-")==0)printf("{A+,A-,B+,B-}");
    else if(strcmp(b,"O-")==0&&strcmp(a,"AB-")==0)printf("{A-,B-}");
    else if(strcmp(b,"A+")==0&&strcmp(a,"O+")==0)printf("{A+,A-,O+,O-}");
    else if(strcmp(b,"A-")==0&&strcmp(a,"O+")==0)printf("{A+,A-,O+,O-}");
    else if(strcmp(b,"B+")==0&&strcmp(a,"O+")==0)printf("{B+,B-,O+,O-}");
    else if(strcmp(b,"B-")==0&&strcmp(a,"O+")==0)printf("{B+,B-,O+,O-}");
    else if(strcmp(b,"AB+")==0&&strcmp(a,"O+")==0)printf("{A+,A-,B+,B-}");
    else if(strcmp(b,"AB-")==0&&strcmp(a,"O+")==0)printf("{A+,A-,B+,B-}");
    else if(strcmp(b,"O+")==0&&strcmp(a,"O+")==0)printf("{O+,O-}");
    else if(strcmp(b,"O-")==0&&strcmp(a,"O+")==0)printf("{O+,O-}");
    else if(strcmp(b,"A+")==0&&strcmp(a,"O-")==0)printf("{A+,A-,O+,O-}");
    else if(strcmp(b,"A-")==0&&strcmp(a,"O-")==0)printf("{A-,O-}");
    else if(strcmp(b,"B+")==0&&strcmp(a,"O-")==0)printf("{B+,B-,O+,O-}");
    else if(strcmp(b,"B-")==0&&strcmp(a,"O-")==0)printf("{B-,O-}");
    else if(strcmp(b,"AB+")==0&&strcmp(a,"O-")==0)printf("{A+,A-,B+,B-}");
    else if(strcmp(b,"AB-")==0&&strcmp(a,"O-")==0)printf("{A-,B-}");
    else if(strcmp(b,"O+")==0&&strcmp(a,"O-")==0)printf("{O+,O-}");
    else if(strcmp(b,"O-")==0&&strcmp(a,"O-")==0)printf("O-");
}

int main()
{
    int n;scanf("%d",&n);
    for(int t=0;t<n;t++)
    {
        char a[4],b[4],c[4];
        scanf("%s %s %s",a,b,c);
        if(strcmp(c,"?")==0)
            {printf("%s %s ",a,b);val3(a,b);printf("\n");}
        else if(strcmp(a,"?")==0)
            {val1(b,c);printf(" %s %s\n",b,c);}
        else
            {printf("%s ",a);val2(a,c);printf(" %s\n",c);}
    }
}