#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define L 101

struct BIGINT
{
    int flag,len,v[L];
};

BIGINT Zero={1,0,{0}};
BIGINT One={1,1,{1}};

void scan(string s,BIGINT* A)
{

    A->len=s.length();
    for(int i=0;i<A->len-1;i++)
    {
        A->v[i] = s[A->len-1-i]-'0';
    }
    if(s[0]=='-'){ A->flag=-1;A->len--;}
    else{ A->v[A->len-1] = s[0]-'0';A->flag=1;}
}

void add(BIGINT* A,BIGINT* B)
{
    int carry=0,cnt=0;
    do{
        A->v[cnt] = A->v[cnt] + B->v[cnt] + carry;
        carry = A->v[cnt]/10;
        A->v[cnt] %= 10;
        cnt++;
    }while(cnt< A->len);
    if(carry!=0)
    {
        A->len++;
        A->v[cnt]=carry;
    }
}

void DIV2(BIGINT *n)
{
    int carry=0;
    if (n->v[n->len-1]<2)n->len--,carry=1;
    for (int i=n->len-1;i>=0;i--)
    {
        int t=10*carry+n->v[i];
        n->v[i]=t/2;
        carry=t%2;
    }
}

void printI(struct BIGINT A)
{
    if(A.flag==-1)cout<<"-";
    for(int i=A.len-1;i>=0;i--)
        cout<<A.v[i];
    cout<<endl;
}

int main()
{
    string s;
    BIGINT a={1,1,{0}};
    cin>>s;scan(s,&a);
    int bin[400]={0},cnt=0;
    while(a.len>0)
    {
        int temp=a.v[0]%2;

        bin[cnt++]=temp;
        DIV2(&a);

        if(a.flag==-1 && temp)
        {
            if (a.len==0){a.len++;a.v[0]=1;}
            else add(&a,&One);
        }
        a.flag*=-1;
    }

    for (int i=cnt-1;i>=0;i--)
        cout<<bin[i];
    cout<<endl;
    return 0;
}
