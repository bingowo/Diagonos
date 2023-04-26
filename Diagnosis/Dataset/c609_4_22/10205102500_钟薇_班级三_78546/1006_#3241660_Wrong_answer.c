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
        int flag=0;
        for(int j=0;str[j]!='\000';j++)
            if(str[j]!='0' || str[j]!='1') 
            {
                flag=1;
                break;
            }        
        if(flag==0)
        {
            for(int j=0;str[j]!='\000';j++) result=(result+str[j]-48)*2;
            printf("%lld\n",result/2);
        }
        else
        {
            int abc[62];
            for(int j=0;j<62;j++)   abc[j]=-1;

            flag=0;
            for(int j=0;str[j]!='\000';j++)
            {
                if(str[j]>='0' && str[j]<='9' && abc[str[j]-48]==-1)
                {
                    if(flag==0) abc[str[j]-48]=1;
                    else if(flag==1)    abc[str[j]-48]=0;
                    else abc[str[j]-48]=flag;
                    flag++;
                }
                else if(str[j]>='A' && str[j]<='Z' && abc[str[j]-55]==-1)  
                {
                    if(flag==0) abc[str[j]-55]=1;
                    else if(flag==1)    abc[str[j]-55]=0;
                    else abc[str[j]-55]=flag;
                    flag++;
                }                
                else if(str[j]>='a' && str[j]<='z' && abc[str[j]-61]==-1) 
                {
                    if(flag==0) abc[str[j]-61]=1;
                    else if(flag==1)    abc[str[j]-61]=0;
                    else abc[str[j]-61]=flag;
                    flag++;
                }                
            }
            for(int j=0;str[j]!='\000';j++)
            {
                if(str[j]>='0' && str[j]<='9')  result=(result+abc[str[j]-48])*flag;
                else if(str[j]>='A' && str[j]<='Z')  result=(result+abc[str[j]-55])*flag;
                else if(str[j]>='a' && str[j]<='z') result=(result+abc[str[j]-61])*flag;
            }

            printf("%lld\n",result/flag);
        }
    }
    return 0;
}