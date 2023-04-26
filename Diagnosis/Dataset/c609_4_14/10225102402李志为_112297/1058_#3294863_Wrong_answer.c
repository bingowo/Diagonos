#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char v[103];
    int cnt;
}N;
char ans[400]={0};
void Div(N* a)
{
    int carry=0;
    if(a->v[a->cnt-1]<2){
        a->v[a->cnt-1]=0;
        a->cnt--;
        carry=1;
    }
    for(int i=a->cnt-1;i>=0;i--){
        int t=carry*10+a->v[i];
        a->v[i]=t/2;
        carry=t%2;
    }
}
void Add(N* a)
{
    int carry=0,i=1;
    if(a->v[0]==9){
        a->v[0]=0;
        carry =1;
        if(a->cnt==1) a->cnt++;
    }
    else a->v[0]++;
    while(carry!=0){
        int t=carry+a->v[i];
        if(t==10){
            carry=1;
            a->v[i++]=0;
        }
        else{
           a->v[i]=t;
           break;
        }
    }

}
int main()
{
    char s[400];
    int l,sign=1,j=0;
    scanf("%s",s);
    l=strlen(s);
    N n={0,{0}};
    for(int i=l-1;i>=1;i--){
        n.v[n.cnt++]=s[i]-'0';
    }
    if(s[0]=='-') sign=-1;
    else n.v[n.cnt++]=s[0]-'0';
    while(n.cnt>0){
        ans[j++]=n.v[0]%2;
        Div(&n);
        printf("%d\n",n.v[0]);
        if( sign==-1 && ans[j-1]==1){
            Add(&n);
            sign=1;
            if(n.cnt==0){
                n.cnt++;
                n.v[0]=1;
            }
        }
        else sign=-1*sign;
    }
    j--;
    for(;j>=0;j--) printf("%d",ans[j]);
    return 0;
}