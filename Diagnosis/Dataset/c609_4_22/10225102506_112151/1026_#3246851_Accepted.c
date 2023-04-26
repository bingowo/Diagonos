#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b){
    char *s1=(char *)a;
    char *s2=(char *)b;
    int len1=strlen(s1),len2=strlen(s2);
    int cnt1=0,cnt2=0;
    for(int i=0;i<len1;i++){
        for(int j=i+1;j<len1;j++){
            if(s1[i]==s1[j]){
                cnt1++;
                break;
            }
        }
    }
    for(int i=0;i<len2;i++){
        for(int j=i+1;j<len2;j++){
            if(s2[i]==s2[j]){
                cnt2++;
                break;
            }
        }
    }
    int cnt_a=len1-cnt1;
    int cnt_b=len2-cnt2;
    if(cnt_a!=cnt_b)  return cnt_b-cnt_a;
    else    return strcmp(s1,s2);
}

int main()
{
    int T,n;
    char s[100][21];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        for(int j=0;j<n;j++)
            scanf("%s",&s[j]);
        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<n;k++)
            printf("%s\n",s[k]);
    }
    return 0;
}
