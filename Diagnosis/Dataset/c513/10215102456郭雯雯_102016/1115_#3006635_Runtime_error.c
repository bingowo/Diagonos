#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a,const void *b){
    int c=*(int*)a,d=*(int*)b;
    return c-d;
}

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        char s[25];
        scanf("%s",s);
        int l=strlen(s);
        int ans[l+1];memset(ans,0,sizeof(ans));
        for(int i=0,j=1;i<strlen(s);i++,j++)ans[j]=s[i]-'0';
        for(int i=l;i>=1;i--)
            if(ans[i-1]<ans[i]){
                int c=ans[i-1],min=ans[i],j;
                for(j=i;j<=l;j++){
                    if(ans[j]>c&&ans[j]<min)min=ans[j];
                }
                ans[j]=c;ans[i-1]=min;
                qsort(ans+i,l-i+1,sizeof(int),cmp);
                break;
            }
        int m=0;while(ans[m]==0)m++;
        printf("case #%d:\n",a);
        for(int i=m;i<=l;i++)printf("%d",ans[i]);
        printf("\n");
        a++;
    }
}