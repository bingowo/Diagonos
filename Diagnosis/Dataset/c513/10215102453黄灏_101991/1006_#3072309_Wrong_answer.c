#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int sum=0,len=0;
        printf("case #%d:\n",i);
        char str[1000];
        scanf("%s",str);
        int num[1000]={0};
        len=strlen(str);
        for(int j=0;j<len;j++){
            if(str[j]=='-') num[j]=-1;
            else if(str[j]=='0') num[j]=0;
            else num[j]=1;
            sum=sum+num[i]*pow(3,len-i-1);
        }
        printf("%d\n",sum);
        
    }
    return 0;
}
