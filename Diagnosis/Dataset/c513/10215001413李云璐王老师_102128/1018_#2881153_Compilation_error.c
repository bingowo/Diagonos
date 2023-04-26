#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int isprim[10000]= {0};
int prim[26];
int index=0;
vector<int>v1,v2;
void init() {
 for(int i =2; i < 10000; i++) {
  if(isprim[i]==0) {
   prim[index++]=i;
   if(index==26)
    break;
   for(int j = i+i; j < 10000; j+=i) {
    isprim[j]=1;
   }
  }
 }
}
void f(int t) {
 int i = v1.size()-1;
 int j = v2.size()-1;
 int carry=0;
 int k=0;
 vector<int>v;
 while(i>=0&&j>=0) {
  int m = v1[i]+v2[j]+carry;
  carry=m/prim[k];
  v.push_back(m%prim[k]);
  k++;
  i--;
  j--;
 }
 while(i>=0) {
  int m = v1[i]+carry;
  carry=m/prim[k];
  v.push_back(m%prim[k]);
  k++;
  i--;
 }
 while(j>=0) {
  int m = v2[j]+carry;
  carry=m/prim[k];
  v.push_back(m%prim[k]);
  k++;
  j--;
 }
 if(carry)
  v.push_back(carry);
 printf("case #%d:\n",t);
 for(int k = v.size()-1; k >= 0; k--) {
  cout<<v[k];
  if(k>0)
   cout<<",";
  else
   cout<<endl;
 }
}
int main() {

 init();
 
  v1.clear();
  v2.clear();
  int flag=0;
  while(1) {
   int m;
   cin>>m;
   char c=getchar();
   if(flag==0)
    v1.push_back(m);
   else
    v2.push_back(m);
   if(c==' ')
    flag=1;
   if(c=='\n')
    break;
  }
  f(i);
 
 return 0;
}