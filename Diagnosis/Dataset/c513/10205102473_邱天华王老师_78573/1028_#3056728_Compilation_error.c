#include <iostream>
#include<algorithm> 
#include<vector>
using namespace std;

int main()
{
   int s[101];
   char lt;
   cin>>lt;
   int a;
   int tmp,cnt=0;
   while(1)
   {
   	cin>>tmp;
	s[cnt++]=tmp;
	if(cin.get()=='\n')
	break;	
   } 
   if(lt=='A')
   {sort(s,s+cnt);
   }
   else
   sort(s,s+cnt,greater<int>());
   
   int n=unique(s,s+cnt)-s;
   for(int i=0;i<n;i++)
   cout<<s[i]<<" ";
   return 0;
   }