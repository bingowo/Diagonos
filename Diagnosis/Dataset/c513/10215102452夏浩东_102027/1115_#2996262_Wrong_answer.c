#include <stdio.h>
#include <string.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int mm=0; mm<cnt; mm++)
    {
        char s[30];
        int L[30],zero=0;
        scanf("%s",s);
        for(int i=0;s[i]=='0';i++) zero++;
        for(int i=zero;i<=(int)strlen(s);i++) s[i-zero]=s[i];
        int len=(int)strlen(s);
        for(int i=0; i<len; i++) L[i]=s[i]-'0';
        int flag=0;
        for(int i=0;i<len-1;i++){
            if(L[i]<L[i+1]){flag=1; break;}
        }
        if(flag==1){
            for(int i=len-1;i>0;i--)
            {
                int hh=0;
                for(int j=i-1;j>=0;j--){
                    if(L[i]>L[j]){
                        int temp = L[i];
                        L[i]=L[j];
                        L[j]=temp;
                        hh=1;
                        break;
                    }   
                }
                if(hh==1) break;
            }
        }else{
            for(int i=0;i<(len-1)/2;i++)
            {
                int temp = L[i];
                L[i]=L[len-2-i];
                L[len-2-i]=temp;
            }
            int a = L[len-1];
            for(int i=len-2;i>=0;i--)
            {
                L[i+2]=L[i];
            }
            L[0]=a;
            L[1]=0;
            len++;
        }
        printf("case #%d:\n",mm);
        for(int i=0;i<len;i++)
        {
            printf("%d",L[i]);
        }
        printf("\n");
    }
    return 0;
}