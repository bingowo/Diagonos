#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s1[81],s2[81],s[81];
        scanf("%s %s %s",s1,s2,s);
        int len1=strlen(s1),len2=strlen(s2),len=strlen(s);
        int* p1=(int* )malloc((len-len1+1)*sizeof(int));
        int* p2=(int* )malloc((len-len2+1)*sizeof(int));
        int num1=0,num2=0,i=0,j=0;
        for(;i<=len-len1;i++){
            if(s[i]==s1[0]){
                int ii=0;
                for(;ii<len1;ii++){
                    if(s[i+ii]!=s1[ii]) break;
                }
                if(ii==len1){
                    *(p1+num1)=i;
                    num1++;
                }
            }
        }
        for(;j<=len-len2;j++){
            if(s[j]==s2[0]){
                int jj=0;
                for(;jj<len2;jj++){
                    if(s[j+jj]!=s2[jj]) break;
                }
                if(jj==len2){
                    *(p2+num2)=j;
                    num2++;
                }
            }
        }
        printf("case #%d:\n",t);
        if(num1==0||num2==0) printf("0\n");
        else{
            int ans1=0,ans2=0;
            ans1=*(p2+num2-1)-*(p1)-len1;
            ans2=*(p1+num1-1)-*(p2)-len2;
            printf("%d\n",ans1>ans2?ans1:ans2);
        }
        free(p1);
        free(p2);
    }
    return 0;
}
