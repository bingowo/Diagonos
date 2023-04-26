#include<stdio.h>
#include<string.h>

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        char s[25];
        scanf("%s",s);
        l=strlen(s);
        int ans[l+1];memset(ans,0,sizeof(ans));
        for(int i=0,j=1;i<strlen(s);i++,j++)ans[j]=s[i]-'0';
        for(int i=l;i>=1;i--)
            if(ans[i-1]<ans[i]){
                qsort(ans+i,l-i+1,sizeof(int),cmp);
                int c=ans[i];
                ans[i]=ans[i-1];
                ans[i-1]=c;
                break;
            }
        int m=0;while(ans[m]==0)m++;
        printf("case #%d:\n",a);
        for(int i=m;i<=l;i++)printf("%d",ans[i]);
        printf("\n");
        a++;
    }
}