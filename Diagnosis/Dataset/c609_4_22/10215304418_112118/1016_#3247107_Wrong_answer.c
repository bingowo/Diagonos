#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long a=0,b=0;
    char st[1234];
    scanf("%s",st);
    int f=1;
    int i=0;
    if (st[i]=='-') {
        f=-1;
        i++;
    }
    while (st[i]>='0'&&st[i]<='9' && i<strlen(st)){
        a*=10;
        a+=st[i]-'0';
        i++;
    }
    if (st[i]=='i'){
        b=a*f;
        a=0;
    }
    else{
        a*=f;
        if (i<strlen(st)){
            int ff=1;
            if (st[i]=='-') {
                ff=-1;
            }
            i++;
            if (st[i]=='i') b=1;
            else{
                while (st[i]>='0'&&st[i]<='9'){
                    b*=10;
                    b+=st[i]-'0';
                    i++;
                }
            }
            b=b*ff;
        }
    }
    int arr[123456];
    i=0;
    while (!(a==0 && b==0)){
        long long c,d;
        if ((a+b)%2==0){
            arr[i]=0;
            d=-1*(a+b)/2;
            c=b+d;
        }
        else{
            arr[i]=1;
            d=-1*(a+b-1)/2;
            c=b+d;
        }
        i++;
        a=c;
        b=d;
    }
    for (int j=i-1;j>=0;j--)
        printf("%d",arr[j]);
    printf("\n");
    return 0;
}/*
a+bi=c+di * -1+i +r
=-c-d+ (c-d)i +r
a=-c-d+r
b=c-d
a+b=-2d+r
d=a+b-r/-2
c=a+d;
*/
