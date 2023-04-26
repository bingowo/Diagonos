#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int z=0;z<T;z++)
    {
    char s[100];
    scanf("%s",s);
    double stack[100];
    int top=-1;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        char item[11];
        int k=0;
        while(i>=0&&s[i]!=' ') item[k++]=s[i--];
        for(int j=0,m=k-1;j<m;j++,m--)
        {
            char temp=item[j];
            item[j]=item[m];
            item[m]=temp;
        }
        item[k]='\0';
        double op1,op2;
        switch(item[0])
        {
            case'+': op1=stack[top--]; op2=stack[top--]; stack[++top]=op1+op2; break;
            case'-': op1=stack[top--]; op2=stack[top--]; stack[++top]=op1-op2; break;
            case'*': op1=stack[top--]; op2=stack[top--]; stack[++top]=op1*op2; break;
            case'/': op1=stack[top--]; op2=stack[top--]; stack[++top]=op1/op2; break;
            default: stack[++top]=atof(item);
        }
        printf("case #%d:\n",i);
        printf("%lf\n",stack[top]);
    }
    }
    return 0;
}
