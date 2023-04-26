#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
        t++;
    }
    for(int i=k-1;i>=0;i--)
    {
        printf("%d",L[i]);
    }
    free(L);
}
int main()
{
    char s[501];
    scanf("%s",s);
    int L[200];
    for(int i=0;i<200;i++)
    {
    	L[i]=0;
	}
    int t=0,num=0,i=0;
    
    for(i=0;s[i]!='\0';i++)
    {
        if(num<3)
        {
            L[t]+=(s[i]-'0')*pow(10,2-num);
        }
        if(num==3)
        {
        	t=t+1;
            L[t]=(s[i]-'0')*pow(10,2);
            num=1;
        }
        num++;
    }
    
    printf("0001");
    EJZ(i,10);
    for(int k=0;k<t;k++) EJZ(L[k],10);
    if(i%3==2) EJZ(L[t]/10,7);
    else if(i%3==1) EJZ(L[t]/100,4);
    else EJZ(L[t],10);
    return 0;
}