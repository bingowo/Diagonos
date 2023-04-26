#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp1(const void *a , const void *b){
    int m,n;
    m=*(unsigned int*)a;
    n=*(unsigned int*)b;
    int i=0,j=0;
    while(m!=0){
        i++;
        m=m>>1;
    }
    while(n!=0){
        j++;
        n=n>>1;
    }
    if(m==n)
        return *(int*)a-*(int*)b;
    else
        return j-i;
}

int main(){
    int s[1000000];
    scanf("%s",&s);
    int n=sizeof(s)-1;
    qsort(s,n,sizeof(s[0]),cmp1);
    for(int i=0;i<n-1;i++)
        printf("%d ",s[i]);
    printf("%d\n",s[n-1]);
    return 0;#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp1(const void *a , const void *b){
    int m,n;
    m=*(unsigned int*)a;
    n=*(unsigned int*)b;
    int i=0,j=0;
    while(m>0){
        i++;
        m=m/10;
    }
    while(n>0){
        j++;
        n=n/10;
    }
    if(j==i)
        return *(int*)a-*(int*)b;
    else
        return j-i;
}

int main(){
    int s[1000000];
    scanf("%s",&s);
    int n=sizeof(s)-1;
    qsort(s,n,sizeof(s[0]),cmp1);
    for(int i=0;i<n-1;i++)
        printf("%d ",s[i]);
    printf("%d\n",s[n-1]);
    return 0;
}
}