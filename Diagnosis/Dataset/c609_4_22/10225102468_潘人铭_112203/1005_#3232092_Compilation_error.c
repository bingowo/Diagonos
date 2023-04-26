#include <iostream>
#include <math.h>

using namespace std;

int main()
{
 int t; cin >> t;
 for (int i = 0; i < t; i++)
 {
  string num; cin >> num;
  int len = num.size();
  double ans = 0;
  int cnt = 0;
  while (len!=0)
  {
   if (num[len - 1] == '1') ans += pow(3, cnt);
   if (num[len - 1] == '-') ans -= pow(3, cnt);
   cnt++;
   num.erase(len - 1, 1);
   len--;
  }
  cout << "case #" << i << ":" << endl;
  cout << ans << endl;

 }
}