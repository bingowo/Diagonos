#include<stdio.h>
int main(){
    int T,Case=0;
    long long int end;
    scanf("%d",&T);
    while(T-->0){
        int a[123];
        for(int i = 0;i<123;i++)a[i]=-1;
        int m = 0,index=0,sys=2;
        char s[61];
        scanf("%s",s);
        a[s[index++]]=1;
        while(s[index]){
            if(a[s[index]]==-1)a[s[index]]=m++;
            if(m==1)m=2;
            index++;
        }
        sys=m<2?2:m;
        printf("case #%d:\n",Case++);
        end=a[s[0]]*sys+a[s[1]];
        for(int m=2;s[m];m++)end=a[s[m]]+end*sys;
        printf("%lld\n",end);
    }
    return 0;
}