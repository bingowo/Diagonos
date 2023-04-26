#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char a[1000];
        scanf("%s",&a);
        int l=strlen(a);
        int ans;
        double e=0;
        double m;
        int n;
        for(int j=l-1;j>=0;j--){
            m=pow(3,e);
            e++;
            if(a[j]=='-') n=-1;
            else if(a[j]=='0') n=0;
            else if(a[j]=='1') n=1;
            ans=ans+n*(int)m;
        }
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
    return 0;
}
