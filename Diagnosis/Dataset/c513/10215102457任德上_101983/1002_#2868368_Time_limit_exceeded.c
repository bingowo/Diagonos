#include<stdio.h>
int main(){
    int T,a[123],index=0,Case=0;
    for(int i = 0;i<123;i++)a[i]=-1;
    char s[60];
    scanf("%d",&T);
    while(T-->0){
        int m = 0;
        scanf("%s",s);
        a[s[index++]]=1;
        while(s[index]){
            if(a[s[index]]==-1)a[s[index++]]=m++;
            if(m==1)m=2;
        }
        printf("case #%d:\n",Case++);
        for(int m=0;s[m];m++)printf("%d",a[s[m]]);
        printf("\n");
    }
    return 0;
}
