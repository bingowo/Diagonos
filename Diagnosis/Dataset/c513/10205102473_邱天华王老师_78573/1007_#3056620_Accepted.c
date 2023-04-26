#include<stdio.h>

int main()
{
    int T;
    int a;
    int s[100];
    scanf("%d ",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&a);
        int cnt=0,col=1,max=1;
        while(a)
        {
            s[cnt++]=a%2;
            a=a>>1;
        }
        
        for(int j=0;j<cnt;j++)
        {
            if(max<=col)max=col;
            if(s[j]!=s[j+1]){
                    col++;
                    }
            else col=1;


        }
        printf("case #%d:\n",i);
        printf("%d\n",max);
    }
    return 0;
}