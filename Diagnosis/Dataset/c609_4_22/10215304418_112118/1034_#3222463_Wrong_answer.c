#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st[123456];

int main(){
    scanf("%s",st);
    int i=0;
    int f=0;
    while (i<strlen(st)){
        if (st[i]=='0' && st[i+1]=='x'){
            i+=2;
            long long sum=0;
            if (!((st[i]>='0' && st[i]<='9')||(st[i]>='a' && st[i]<='f'))) {
                continue;
            }
            while ((st[i]>='0' && st[i]<='9')||(st[i]>='a' && st[i]<='f')){
                sum*=16;
                if (st[i]>='0' && st[i]<='9'){
                    sum+=st[i]-'0';
                }
                else {
                    sum+=st[i]-'a'+10;
                }
                i++;
            }
            if (sum!=0) f=1;
            if (sum>2147483647) printf("%lld ",sum-4294967296);
            else printf("%lld ",sum);
        }
        else i++;
    }
    if (f==0) printf("-1\n");
    return 0;
}
