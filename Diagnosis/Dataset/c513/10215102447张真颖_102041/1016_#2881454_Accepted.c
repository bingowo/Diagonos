#include <stdio.h>
#include <stdlib.h>

void convert(int n,int r,char t[])
{
    char sign[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char s[17];
    int temp,i,j;
    for(i=0;n!=0;i++)
    {
        if(n%r<0)
        {
            temp=n/r+1;
            s[i]=sign[n-temp*r];
            n=temp;
        }
        else
        {
            s[i]=sign[n%r];
            n/=r;
        }
    }
    i-=1;
    while(i>=0)
        t[j++]=s[i--];
    t[j]=0;

}

int main()
{
    int N,R;
    char t[17];
    scanf("%d %d",&N,&R);
    if(N==0) printf("0");
    else{
    convert(N,R,t);
    printf("%s\n",t);}
    return 0;
}
