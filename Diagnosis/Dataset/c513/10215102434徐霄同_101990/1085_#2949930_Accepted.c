#include <stdio.h>
#include <string.h>

int main()
{
    char a[501],b[501],a0[501],b0[501],t[501];
    int la,lb,l,f,i;
    while(scanf("%s%s",a0,b0)!=EOF){
        la=strlen(a0);
        lb=strlen(b0);
        for(i=0;i<la;i++)
            a[i]=a0[la-i-1];
        for(i=0;i<lb;i++)
            b[i]=b0[lb-i-1];
        if(la>lb){
            l=la;
            for(i=lb;i<l;i++)
                b[i]='0';
            a[l]=0;
            b[l]=0;
        }
        else{
            l=lb;
            for(i=la;i<l;i++)
                a[i]='0';
            a[l]=0;
            b[l]=0;
        }
        f=0;
        for(i=l-1;i>=0;i--)
            if(a[i]>b[i]){
                f=1;
                break;
            }
            else if(a[i]<b[i]){
                f=-1;
                break;
            }
        if(f==0)
            printf("0\n");
        else{
            if(f==-1){
                strcpy(t,a);
                strcpy(a,b);
                strcpy(b,t);
            }
            for(i=0;i<l;i++){
                if(a[i]<b[i]){
                    a[i]=a[i]+10;
                    a[i+1]=a[i+1]-1;
                }
                t[i]=a[i]-b[i]+'0';
            }
            t[i]=0;
            i--;
            while(t[i]=='0'){
                t[i]=0;
                i--;
            }
            if(f==-1)
                printf("-");
            for(i=strlen(t)-1;i>=0;i--)
                printf("%c",t[i]);
            printf("\n");
        }
    }
    return 0;
}
