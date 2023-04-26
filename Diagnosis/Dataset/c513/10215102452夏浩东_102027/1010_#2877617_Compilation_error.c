#include <stdio.h>
#include <math.h>
void EJZ(int num,int k)
{
    int*L=(int*)malloc(k*sizeof(int));
    int t=0;
    for(int i=0;i<k;i++)
    {
        L[i]=0;
    }
    while(num>0)
    {
        L[t]=num%2;
        num=num/2;
    }
    for(int i=k-1;i>=0;i++)
    {
        pritnf("%d",L[i]);
    }
}
int main()
{
    char s[501];
    scanf("%s",s);
    int L[200];
    int t=0,num=0,i=0;
    
    for(i=0;s[i]!='\0';i++)
    {
        if(num<3)
        {
            L[t]+=(s[i]-'0')*pow(10,num);
            num++;
        }
        if(num==3)
        {
            t++;
            num=0;
            L[t]+=(s[i]-'0')*pow(10,num);
        }
    }
    int w =0;
    if((i+1)%3==1)
    {
        L[t+1]=s[i-1]-'0';
        w=1;
    }
    else if((i+1)%3==2)
    {
        L[t+1]=(s[i-1]-'0')+10*(s[i-2]-'0');
        w=2;
    }
    printf("0001");
    EJZ(i,10);
    for(int k=0;k<t;k++) EJZ(L[k],10);
    if(w==2) EJZ(L[t],7);
    else if(w==1) EJZ(L[t],4);
    return 0;
}