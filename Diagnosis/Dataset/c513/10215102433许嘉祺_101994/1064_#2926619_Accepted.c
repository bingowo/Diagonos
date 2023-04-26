#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{

    int n;
    int top=0;
    double op1,op2;
    scanf("%d",&n);
    getchar();
    char a[1000];
    double stack[100];
    for (int i=0; i<n; i++)
    {
        gets(a);
        char item[20];
        top=0;
        for (int j=strlen(a)-1; j>=0; j--)
        {
            int k=0;
            while(a[j]!=' '&&j>=0) item[k++]=a[j--];
            item[k]=0;
            for (int l=0; l<k/2; l++)
            {
                char c=item[l];
                item[l]=item[k-l-1];
                item[k-1-l]=c;
            }

            switch(item[0])
            {

            case '+':op1=stack[top-1];op2=stack[top-2];top=top-2;stack[top++]=op1+op2;break;
            case '-':op1=stack[top-1];op2=stack[top-2];top=top-2;stack[top++]=op1-op2;break;
            case '/':op1=stack[top-1];op2=stack[top-2];top=top-2;stack[top++]=op1/op2;break;
            case '*':op1=stack[top-1];op2=stack[top-2];top=top-2;stack[top++]=op1*op2;break;
            default:stack[top++]=atof(item);

            }

        }
        printf("case #%d:\n",i);
        printf("%.6lf\n",stack[0]);
    }


    return 0;
}