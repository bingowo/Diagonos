#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100;

bool cmpD(int a,int b){ //降序
   return a>b ;
}
void solve (char order){
   int arr[N];
   int i =0 ;
   while(cin >> arr[i]){ //EOF结束输入
      i++;
   }
   if(order == 'A'){
       sort(arr,arr+i); // 升序
   }else{
      sort(arr,arr+i,cmpD);
   }

   int carr[i] = {arr[0]};
	int   cnt = 0;
   for(int j =1 ;j < i ;j++){//去重
      if(carr[cnt]!=arr[j]){
         cnt ++;
         carr[cnt] = arr[j];
      }
   }
   for(int i =0 ;i < cnt+1;i++){
      cout << carr[i] << " ";
   }
}
int main()
{
    char order;
    cin >> order;
//    cin.get();
   solve(order);
    return 0;

}
