#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    char c;
    getchar();
    for(int i=0;i<T;i++)
    {
        int j=0,k=0,flag=0;
        float ans;
        double w=1;
        double data[100]={0};
        char fu[33];
        while(scanf("%c",&c)&&c!='\n')
        {
            if(flag==1){
                if(c==' '){
                    flag=0;
                    w=1;
                    k++;
                }
                else{
                    w*=0.1;
                    data[k]=data[k]+w*(c-'0');
                }
                continue;
            }
            if(c=='+'||c=='-'||c=='*'||c=='/')
            {
                fu[j]=c;
                flag=2;
            }
            else if(c=='.'){
                flag=1;
                continue;
            }
            else if(c>='0'&&c<='9')
            {
                data[k]=data[k]*10+c-'0';
            }
            else if(c==' '){
                if(flag==2){
                    j++;
                }
                else {
                    k++;
                    w=1;
                }
                flag=0;
            }
        }
        for(int m=j-1,n=1;m>=0;m--,n++){
            if(fu[m]=='+'){
                ans=data[n-1]+data[n];
                data[n]=ans;
            }
            else if(fu[m]=='-')
            {
                ans=data[n-1]-data[n];
                data[n]=ans;
            }
            else if(fu[m]=='*')
            {
                ans=data[n-1]*data[n];
                data[n]=ans;
            }
            else if(fu[m]=='/')
            {
                ans=data[n-1]/data[n];
                data[n]=ans;
            }
        }
        printf("case #%d:\n%.6f\n",i,ans);
    }
    return 0;
}