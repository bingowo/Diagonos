#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp1(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int main(){
    int n;
    int *lens, *num;
    scanf("%d", &n);
    char **s;
    s = (char**)malloc(sizeof(char*)*n);
    lens = (int*)calloc(n,sizeof(int));
    num = (int*)calloc(n,sizeof(int));
    for(int i=0; i<n; i++){
        s[i] = (char*)malloc(sizeof(char)*100);
        scanf("%s", s[i]); //s[i]本身就是个地址
        lens[i] = strlen(s[i])-1;
    }
    char c;
    int mid = n/2, sum = 0, flag=1;
    while(lens[n-1]!=-1){
        c=s[0][lens[0]];
        for(int i=0; i<n; i++){
            while(s[i][lens[i]]==c){
                num[i]++;
                lens[i]--;
            }
            if(num[i]==0){
                flag=0;
                break;
            }
        }
        if(flag==0) break;
        qsort(num,n,sizeof(num[0]),cmp1);//往中间的值靠
        for(int i=0; i<mid; i++) sum+=num[mid]-num[i];
        for(int i=mid+1; i<n; i++) sum+=num[i]-num[mid];
        memset(num,0,sizeof(num[0])*n);
    }
    if(flag==1) printf("%d", sum);
    else printf("%d", -1);
    for(int i=0; i<n; i++) free(s[i]);
    free(s);
    free(lens);
    free(num);
    return 0;
}