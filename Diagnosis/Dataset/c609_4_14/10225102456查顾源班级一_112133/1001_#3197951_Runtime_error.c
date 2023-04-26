#include<stdio.h>

int f(int N,int R)
{
    int cmt=0,a=N;
    while(a)
    {
        a/=R;
        cmt++;
    }
    char s[cmt];
    int i=cmt;
    while(i>0)
    {s[i]=N%R;
    if (s[i]>9)
        s[i]=s[i]-10+'A';
        else
            s[i]+='0';
    i--;
    N/=R;
    }
    return s;

}

int main()
{int T,N,R;
scanf("%d",T);
while(T)
{
    scanf("%d%d",&N,&R);
    printf("%d\n",f(N,R));
    T--;
}
    return 0;
}
