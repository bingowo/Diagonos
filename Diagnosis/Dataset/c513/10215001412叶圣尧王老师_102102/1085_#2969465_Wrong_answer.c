#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void mini(char*A,char*B)
{
    int a[strlen(A)],b[strlen(B)],c[strlen(A)],i,j,d=0;
    for(i=0;i<strlen(A);i++)a[i]=A[i]-'0';
    for(i=0;i<strlen(B);i++)b[i]=B[i]-'0';
    for(i=strlen(A)-1,j=strlen(B)-1;i>=0&&j>=0;i--,j--)
    {
        int t=a[i]-b[j]-d+10;
        c[i]=t%10;
        d=1-t/10;
    }
    for(;i>=1;i--)
    {
        int t=a[i]+10-d;
        c[i]=t%10;
        d=1-t/10;
    }
    c[0]=a[0]-d;
    while(c[i]==0)i++;
    for(;i<strlen(A);i++)printf("%d",c[i]);
    printf("\n");
}

int main()
{
    char A[501],B[501];
    while(~scanf("%s %s",A,B))
    {
        int d;
        if(strlen(A)>strlen(B)){mini(A,B);}
        else if(strlen(A)<strlen(B)){mini(B,A);printf("-");}
        else if(strcmp(A,B)>0){mini(A,B);}
        else if(strcmp(A,B)<0){mini(B,A);printf("-");}
        else
        {
            printf("0\n");
        }
    }
}