#include <stdio.h>
#include <string.h>

int main()
{
    char s[30],ans[30];
    int n[10];
    int t,i,i0,j,k,l,p;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s",s);
        l=strlen(s);
        p=-1;
        memset(n,0,sizeof(n));
        memset(ans,0,sizeof(ans));
        for(j=0;j<l;j++){
            n[s[j]-'0']++;
            if(j<l-1&&s[j]<s[j+1])
                p=j;
        }
        if(p==-1){
            n[0]++;
            k=1;
            while(n[k]==0)
                k++;
            ans[0]=k+'0';
            n[k]--;
            k=1;
            for(i0=0;i0<10;i0++)
                while(n[i0]>0){
                    ans[k]=i0+'0';
                    k++;
                    n[i0]--;
                }
            ans[k]=0;
        }
        else{
            for(k=0;k<p;k++){
                ans[k]=s[k];
                n[s[k]-'0']--;
            }
            i0=s[p]-'0'+1;
            while(n[i0]==0)
                i0++;
            ans[p]=i0+'0';
            n[i0]--;
            k=p+1;
            for(i0=0;i0<10;i0++)
                while(n[i0]>0){
                    ans[k]=i0+'0';
                    k++;
                    n[i0]--;
                }
            ans[k]=0;
        }
        printf("case #%d:\n",i);
        printf("%s\n",ans);
    }
    return 0;
}
