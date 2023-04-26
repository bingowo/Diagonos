#include <stdio.h>
#include <string.h>
char ans[10];
void mul(char a[],int n)
{
    char a0[20],b0[20];
    int i,j,c,x,l;
    char t;
    l=strlen(a);
    for(i=0;i<20;i++)
        a0[i]='0';
    a0[20]=0;
    for(i=0;i<l;i++){
        x=a[l-1-i]-'0';
        for(j=0;j<i;j++)
            b0[j]='0';
        c=0;
        for(j=0;j<n;j++){
            b0[j+i]=((ans[j]-'0')*x+c)%10+'0';
            c=((ans[j]-'0')*x+c)/10;
        }
        b0[n+i]=c+'0';
        for(j=n+i+1;j<20;j++)
            b0[j]='0';
        b0[20]=0;
        c=0;
        for(j=0;j<20;j++){
            t=a0[j];
            a0[j]=((t-'0')+(b0[j]-'0')+c)%10+'0';
            c=((t-'0')+(b0[j]-'0')+c)/10;
        }
    }
    for(i=0;i<n;i++)
        ans[i]=a0[i];
    ans[n]=0;
}
int main()
{
    char a[11];
    int b,n,t,i,j,l;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s%d%d",a,&b,&n);
        l=strlen(a);
        for(j=0;j<l;j++)
            ans[j]=a[l-j-1];
        for(j=l;j<n;j++)
            ans[j]='0';
        ans[n]=0;
        for(j=1;j<b;j++)
            mul(a,n);
        printf("case #%d:\n",i);
        for(j=n-1;j>=0;j--)
            printf("%c",ans[j]);
        printf("\n");
    }
    return 0;
}