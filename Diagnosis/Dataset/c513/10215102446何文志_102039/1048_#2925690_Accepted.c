#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 100
void multiply(char *s1,char *s2, int* co)
{
    int co1[N]={0},co2[N]={0},i,j;
    readpoly(s1,co1); readpoly(s2,co2);
    for (i=0;i<N/2;i++)
        for (j=0;j<N/2;j++)
            co[i+j]+=co1[i]*co2[j];
}
void readpoly(char *p, int* co)
{
    while (*p)
    {
        int sign=1,c=0,d=0;
        if (*p=='+' ) p++;
        else if (*p=='-') sign=-1,p++;
        while (isdigit(*p)) { c=c*10+*p-'0'; p++; }
        if (*p!='x') { co[0]=c*sign; return; } else p++;
        if (c==0) c=1;
        if (*p=='^') p++;
        while (isdigit(*p)) { d=d*10+*p-'0'; p++; }
        if (d==0) d=1;
        co[d]=c*sign;
    }
}
int main()
{
    char s1[N+1],s2[N+1];
    while(scanf("%s%s",s1,s2)==2)
    {
        int co[N]={0},out[N],n=0,i;
        multiply(s1,s2,co);
        for (i=0;i<N;i++)
        {if (co[i]) out[n++]=co[i];}
        for (i=n-1;i>=0;i--)
        {
            printf("%d",out[i]);
            if (i>0) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
//int main()
//{
//    char s1[100],s2[100];memset(s1,0,100*sizeof(char));memset(s2,0,100*sizeof(char));
//    while(scanf("%s%s",s1,s2)!=EOF)
//    {
//        int n1[50],n2[50];memset(n1,0,50*sizeof(int));memset(n2,0,50*sizeof(int));
//        printf("%s   %s\n",s1,s2);
//        int i1 = 0,i2 = 0;
        /*
        while(i1<strlen(s1))
        {
            int flag = 1,cur1 = 0,cur2 = 0;
            if(s1[i1]=='-'){flag = -1;i1++;}
            else if(s1[i1]=='+'){flag = 1;i1++;}
            printf("flag = %d ",flag);
            if(s1[i1]=='x'){cur1 = flag;i1++;}
            else
            {
                while(isdigit(s1[i1]))
                {
                    cur1 = cur1*10+s1[i1]-'0';
                    i1++;
                }
            }
            cur1*=flag;
            printf("cur1 = %d ",cur1);
            if(s1[i1]!='x'){cur2 = 0;}
            else
            {
                if(s1[i1+1]!='^'){cur2 = 1;i1++;}
                else
                {
                    i1+=2;
                    while(isdigit(s1[i1]))
                    {
                        cur2 = cur2*10+s1[i1]-'0';
                    }
                }
            }
            i1++;
            printf("cur2 = %d\n",cur2);
            n1[cur2] = cur1;
        }
        */
//    }
//    return 0;
//}
