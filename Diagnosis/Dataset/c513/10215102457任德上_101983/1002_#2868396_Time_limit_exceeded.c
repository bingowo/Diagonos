#include<stdio.h>
int main(){
    int T,a[123],Case=0,sys=0;
    long long int end;
    for(int i = 0;i<123;i++)a[i]=-1;
    char s[60];
    scanf("%d",&T);
    while(T-->0){
        int m = 0,index=0;
        scanf("%s",s);
        a[s[index++]]=1;
        while(s[index]){
            if(a[s[index]]==-1)a[s[index++]]=m++;
            if(m==1)m=2;
        }
        printf("case #%d:\n",Case++);
        for(int m=0;s[m++];sys++);
        end=a[s[0]]*sys+a[s[1]];
        for(int m=2;s[m];m++)end=a[s[m]]+end*sys;
        printf("%lld\n",end);
    }
    return 0;
}
