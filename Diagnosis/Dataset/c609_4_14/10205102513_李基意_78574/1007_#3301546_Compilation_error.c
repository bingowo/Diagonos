#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
long long int a;//十进制表示 64位
int cnt;//1的个数
}LIST;

int cmp(const void* a,const void* b)
{
LIST aa=(LIST*)a;
LIST bb=(LIST*)b;
if(aa.cnt!=bb.cnt)
return bb.cnt-aa.cnt;
else
return aa.a-bb.a;

}
int main(void)
{
LIST test[1001];
int T,i1,i,j,N;
cin>>T;
for(i1=0;i1>N;
for(i=0;i>test[i].a;
long long int d=1;
for(j=0;j<64;j++)
{
if(test[i].a&d)
test[i].cnt++;
d=d<<1;
}

    }
    qsort(test,N,sizeof(LIST),cmp);
    cout<<"case #"<<i1<<":"<<endl;
    for(i=0;i<N;i++)
    {
        cout<<test[i].a<<" ";
    }
    cout<<endl;

}
return 0;
}