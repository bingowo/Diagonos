#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st[123456];
int a[123456];

int main(){
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%s",st);
        int pos=0;
        int j=0;
        int f=0;
        while (pos<strlen(st)){
            if (j==0){
                j++;
                if (st[pos]!=st[0]){
                    f=1;
                    break;
                }
                if (st[pos]=='(') a[j]=1;
                else if (st[pos]=='[') a[j]=2;
                else if (st[pos]=='{') a[j]=3;
                else {
                    f=1;
                    break;
                }
            }
            else {
                if (st[pos]==')' && a[j]==1) j--;
                else if (st[pos]==']' && a[j]==2) j--;
                else if (st[pos]=='}' && a[j]==3) j--;
                else if (st[pos]=='[' && a[j]==3) {
                    j++;
                    a[j]=2;
                }
                else if (st[pos]=='(' && a[j]==2) {
                    j++;
                    a[j]=1;
                }
                else if (st[pos]=='{' && a[j]==1) {
                    j++;
                    a[j]=3;
                }
                else {
                    f=1;
                    break;
                }
            }
            pos++;
        }
        if (j!=0) f=1;
        if (f==1) {
            printf("No\n");
        }
        else printf("Yes\n");
    }
    return 0;
}
