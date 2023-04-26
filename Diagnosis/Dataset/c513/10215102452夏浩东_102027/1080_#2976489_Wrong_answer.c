#include <stdio.h>
#include <string.h>
int main()
{
    int cnt=0; scanf("%d",&cnt);
    for(int k=0;k<cnt;k++)
    {
        char s[102];
        int L[334],num=0;
        for(int i=0;i<334;i++) L[i]=0;
        scanf("%s",s);
        int len = strlen(s);
        while(1)
        {
            int flag=0;
            L[num++]=(s[len-1]-'0')%2;
            int left=0;
            for(int i=0;i<len;i++)
            {
                char c =(char)((s[i]-'0'+left*10)/2+'0');
                left = (s[i]-'0'+(left*10))%2;
                s[i] = c;
            }
            for(int i=0;i<len;i++) if(s[i]!='0') flag=1;
            if(flag==0) break;
        }
        //for(int i=0;i<num;i++) printf("%d ",L[i]);
        //printf("\n");
        int zero=0;
        while(L[zero]==0) zero++;
        int res[102],r=0; 
        for(int i=0;i<102;i++) res[i]=0;
        int count=0,temp=0;
        for(int i=zero;i<num;i++)
        {
            temp+=L[i]*(1<<count);
            count++;
            if(temp>=10){res[r++]=temp%10;temp=temp/10;count=0;}
        }
        res[r]=temp;
        printf("case #%d:\n",k);
        for(int i=r;i>=0;i--) printf("%d",res[i]);
        printf("\n");
    }
    return 0;
}