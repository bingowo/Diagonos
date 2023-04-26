#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);

        char n[100];
        scanf("%s",&n);

        int result=0;
        for(int j=0;n[j]!='\000';j++)
        {
            if(n[j]=='1')   result=(result+1)*3;
            else if(n[j]=='-')  result=(result-1)*3;
            else    result*=3;
        }
        printf("%d\n",result/3);
    }
    return 0;
}