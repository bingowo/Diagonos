#include <stdio.h>
#include <string.h>

int main( )
{
    char a[1005],b[1005],c[1005];
    int a1[1005],b1[1005];
    int sum[1005];
    while(scanf("%s %s",a,b)!=EOF){
        int lena= strlen(a),lenb= strlen(b);
        for(int i=0;i<lena;i++)
            a1[i]=a[i]-'0';
        for(int i=0;i<lenb;i++)
            b1[i]=b[i]-'0';
        int len=lena-lenb;
        int flag=0;
        int co=0;
        if(len==0){
            if(strcmp(a,b)<0){
                flag=1;
                for(int i=lena-1;i>=0;i--){
                    if(b1[i]-a1[i]<0){
                        sum[co++]=b1[i]-a1[i]+10;
                        b1[i-1]--;
                    } else{
                        sum[co++]=b1[i]-a1[i];
                    }
                }
            } else{
                for(int i=lena-1;i>=0;i--){
                    if(a1[i]-b1[i]<0){
                        sum[co++]=a1[i]-b1[i]+10;
                        a1[i-1]--;
                    } else{
                        sum[co++]=a1[i]-b1[i];
                    }
                }
            }
        } else if(len<0){
            flag=1;
            for(int i=lenb-1;i>=lenb-lena;i--)
                if(b1[i]-a1[i-(lenb-lena)]<0){
                    sum[co++]=b1[i]-a1[i-(lenb-lena)]+10;
                    b1[i-1]--;
                } else{
                    sum[co++]=b1[i]-a1[i-(lenb-lena)];
                }
            for(int i=lenb-lena-1;i>=0;i--) {
                if (b1[i] < 0) {
                    b1[i] += 10;
                    b1[i - 1]--;
                }
                sum[co++] = b1[i];
            }
        } else{
            for(int i=lena-1;i>=lena-lenb;i--)
                if(a1[i]-b1[i-(lena-lenb)]<0){
                    sum[co++]=a1[i]-b1[i-(lena-lenb)]+10;
                    a1[i-1]--;
                } else{
                    sum[co++]=a1[i]-b1[i-(lena-lenb)];
                }
            for(int i=lena-lenb-1;i>=0;i--) {
                if (a1[i] < 0) {
                    a1[i] += 10;
                    a1[i - 1]--;
                }
                sum[co++] = a1[i];
            }
        }
        if(flag)
            printf("-");
        int i=co-1;
        while (sum[i]==0)
            i--;
        for(;i>=0;i--)
            printf("%d",sum[i]);
        printf("\n");
    }
    return 0;
}
