//find LCM
#include <iostream>
using namespace std;
int Findlcm(int x, int y);
int main(){
    int num1, num2, LCM;
    cout<<"Enter any 2 numbers to find LCM: "<<endl;
    cin>>num1;
    cin>>num2;
 
    if(num1 > num2)
        LCM = Findlcm(num2, num1);
    else
        LCM = Findlcm(num1, num2);
 
    cout<<"LCM of "<<num1 << " and "<< num2 <<" is: "<<LCM;
 
    return 0;
}
int Findlcm(int x, int y){
    static int multiple = 0;
    multiple += y;
    if((multiple % x == 0) && (multiple % y == 0))
    {
        return multiple;
    }
    else
    {
        return Findlcm(x, y);
    }
}