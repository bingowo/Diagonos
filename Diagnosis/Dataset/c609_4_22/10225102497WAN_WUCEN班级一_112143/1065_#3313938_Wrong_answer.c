#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        char Expression[102]={0},Operator[101]={0};
        int len=0,Noperator=0,cutlen=0,isoperationN[101]={0},k=0,n=0;
        double twooperationN[2]={0},operationN[101]={0};
        fgets(Expression,102,stdin);
        Expression[len=strlen(Expression)-1]='\0';
        for(k=0;cutlen<len;)
        {
            char string[101]={0};
            sscanf(Expression+cutlen,"%s",string);
            cutlen+=strlen(string)+1;
            if(string[0]=='+'||string[0]=='-'||string[0]=='*'||string[0]=='/')
            {
                Noperator++;
                Operator[k++]=string[0];
            }
            else
            {
                isoperationN[k]++;
                operationN[k++]=atof(string);
            }
        }
        n=k;
        for(;k>=0;k--)
        {
            if(Operator[k])
            {
                int c=1,d=0;
                while(k+c<=n&&!Operator[k+c]&&d<2)
                {
                    if(isoperationN[k+c])
                    {
                        twooperationN[d++]=operationN[k+c];
                        isoperationN[k+c]=0;
                    }
                    c++;
                }
                switch(Operator[k])
                {
                    case '+':
                        twooperationN[1]=twooperationN[0]+twooperationN[1];
                        break;
                    case '-':
                        twooperationN[1]=twooperationN[0]-twooperationN[1];
                        break;
                    case '*':
                        twooperationN[1]=twooperationN[0]*twooperationN[1];
                        break;
                    case '/':
                        twooperationN[1]=twooperationN[0]/twooperationN[1];
                        break;
                    default:
                        printf("wrong operator");
                        break;
                }
                Operator[k]=0;
                k=n;
            }
        }
        printf("case #%d:\n",i);
        printf("%lf\n",twooperationN[1]);
    }
}
