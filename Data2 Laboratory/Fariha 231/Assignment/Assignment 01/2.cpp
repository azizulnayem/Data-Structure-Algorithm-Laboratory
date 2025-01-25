#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

bool is_palindrome(string s, int st, int ed)
{

   if (st == ed)
   {

      return true;
   }

   if (s[st] != s[ed])
      return false;

   if (st < ed + 1)
      return is_palindrome(s, st + 1, ed - 1);

   return true;
}



int sum_palindrome(int x, int y)
{
   if (x <= y)
   {
      string s = to_string(x);
      if (is_palindrome(s,0, s.size() - 1))
      {
         cout << x << " ";
         return x + sum_palindrome(x + 1, y);
      }
      else
         return 0 + sum_palindrome(x + 1, y);
   }
   else return 0;
}

int main()
{
   int x,y;
   cin>>x>>y;

   int sum = sum_palindrome(x,y);
   cout<<"\nsum " << sum;

   return 0;
}
