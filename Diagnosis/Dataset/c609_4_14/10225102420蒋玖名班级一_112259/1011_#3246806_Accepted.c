#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[35]={'\0'};
    int i=0;
    do
    {
        scanf("%c",&a[i]);
        i++;
    }while(a[i-1]!='\n');
    int flag=1;
    long long A=0,B=0,C=1;
    for(int j=0;j<i;j++)
    {
        if(a[j]=='.') flag=-1;
        if(a[j]<='2'&&a[j]>='0'&&flag==1)
        {
            if(a[j]=='2') A=A*3-1;
            else A=A*3+a[j]-'0';
        }
        if(a[j]<='2'&&a[j]>='0'&&flag==-1)
        {
            C=C*3;
            if(a[j]=='2') B=B*3-1;
            else B=B*3+a[j]-'0';
        }
    }
    if(A==0&&B!=0) printf("%lld %lld\n",B,C);
    if(A>0&&B>0) printf("%lld %lld %lld\n",A,B,C);
    if(A<0&&B<0) printf("%lld %lld %lld\n",A,-B,C);
    if(A<0&&B>0) printf("%lld %lld %lld\n",A+1,C-B,C);
    if(A>0&&B<0) printf("%lld %lld %lld\n",A-1,C+B,C);
    if(A!=0&&B==0) printf("%lld\n",A);
    if(A==0&&B==0) printf("%d\n",0);
    return 0;
}
