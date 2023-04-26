#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* countalp(char *s){
    char *temp;
    int count=0;
    temp = (char*)calloc(17,sizeof(char));
    for(int i=65; i<91; i++){
        if(strchr(s,(char)i)) temp[count++] = (char)i;
    }
    for(int i=97; i<123; i++){
        if(strchr(s,(char)i)) temp[count++] = (char)i;
    }
    temp[count] = '\0';
    return temp;
}
long long pow2(int n){
    long long ans=1;
    for(int i=0; i<n; i++) ans*=2;
    return ans;
}
int cmp1(const void *a, const void *b){
    char *s1=*(char**)a, *s2=*(char**)b;
    return strcmp(s1, s2);
}
int main(){
    int T, count, ret, p;
    scanf("%d", &T);
    char s[17], alp[17];
    char **arr;
    long long sum, temp;
    for(int k=0; k<T; k++){
        scanf("%s", s);
        strcpy(alp,countalp(s));
        count = strlen(alp);
        sum = pow2(count)-1;
        arr = (char**)malloc(sizeof(char*)*sum);
        for(long long i=1; i<=sum; i++){
            arr[i-1] = (char*)malloc(sizeof(char)*(count+1));
            ret = 0;
            p = 0;
            temp = i;
            while(temp!=0){
                if(temp%2==1) arr[i-1][ret++] = alp[p];
                p++;
                temp /=2;
            }
            arr[i-1][ret] = '\0';
        }
        qsort(arr, sum, sizeof(arr[0]), cmp1);
        printf("case #%d:\n", k);
        for(long long i=0; i<sum; i++) printf("%s\n", arr[i]);
        for(long long i=0; i<sum; i++) free(arr[i]);
        free(arr);
    }
    return 0;
}