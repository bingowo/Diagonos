#include<iostream>
#include<vector>
#include<string>

using namespace std;
struct BIGINT{
int cnt;
vector<int> v;
};

void div2(BIGINT *n)
{
    int carry=0;
    if(n->v[n->cnt-1]<2) {n->cnt--;carry=1;}
 for( int i=n->cnt-1;i>=0;i--)
 {
     int t=10*carry+n->v[i];
     n->v[i]=t/2;
     carry=t%2;
 }
}

void add1(BIGINT *n)
{
    int carry=0,i=1;
    n->v[0]=n->v[0]+1;
    carry=n->v[0]/10;
    n->v[0]=n->v[0]%10;
    while(carry!=0&&i<n->cnt)
    {
        n->v[i]+=carry;
        carry=n->v[i]/10;
        n->v[i]=n->v[i]%10;
        i++;
    }
    if(carry!=0) {n->v[i]=carry;n->cnt++;}
}
int main()
{
     string s; vector<int> bin(400,0); int cnt=0;
     cin>>s;
     int sign=1,len=s.length();
     BIGINT n={0,{9}};
     for( int i=len-1;i>=1;i--)
        n.v[n.cnt++]=s[i]-'0';

     if(s[0]=='-') {sign=-1;}
     else { n.v[n.cnt++]=s[0]-'0';}
 while(n.cnt>0)
 {
     int temp=n.v[0]%2;

     bin[cnt++]=temp;
     div2(&n);

     if(sign==-1&&temp)
     {
         if(n.cnt==0) {n.cnt++;n.v[0]=1;}
         else add1(&n);
     }
     sign=-sign;

 }
 for(int i=cnt-1;i>=0;i--)
      cout<<bin[i];
	return 0;
}

