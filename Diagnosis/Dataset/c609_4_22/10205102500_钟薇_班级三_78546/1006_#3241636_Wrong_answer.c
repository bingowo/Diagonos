#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char str[61];
        scanf("%s",&str);
        long long int result=0;
        if(str[0]=='0' || str[0]=='1')
        {
            for(int j=0;str[j]!='\000';j++) result=(result+str[j]-48)*2;
            printf("%lld\n",result/2);
        }
        else
        {
            int abc[27];
            for(int j=0;j<28;j++)   abc[j]=-1;

            int flag=0;
            for(int j=0;str[j]!='\000';j++)
            {
                if(str[j]>='A' && str[j]<='Z' && abc[str[j]-64]==-1)  
                {
                    if(flag==0) abc[str[j]-64]=1;
                    else if(flag==1)    abc[str[j]-64]=0;
                    else abc[str[j]-64]=flag;
                    flag++;
                }                
                else if(str[j]>='a' && str[j]<='z' && abc[str[j]-96]==-1) 
                {
                    if(flag==0) abc[str[j]-96]=1;
                    else if(flag==1)    abc[str[j]-96]=0;
                    else abc[str[j]-96]=flag;
                    flag++;
                }                
            }
            for(int j=0;str[j]!='\000';j++)
            {
                if(str[j]>='A' && str[j]<='Z')  result=(result+abc[str[j]-64])*flag;
                else if(str[j]>='a' && str[j]<='z') result=(result+abc[str[j]-96])*flag;
            }

            printf("%lld\n",result/flag);
        }
    }
    return 0;
}