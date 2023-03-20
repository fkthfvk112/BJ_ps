#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string d;
    int x, y, d_diff = 0;
    cin>>x>>y;

    for(int m = 1; m < x; m++){
        if(m == 4|| m==6||m==9||m==11){
            d_diff += 30;
        }
        else if(m == 2){
            d_diff += 28;
        }
        else{
            d_diff+= 31;
        }
    };
    d_diff += y-1;

    if(d_diff % 7 == 0) d = "MON";
    if(d_diff % 7 == 1) d = "TUE";
    if(d_diff % 7 == 2) d = "WED";
    if(d_diff % 7 == 3) d = "THU";
    if(d_diff % 7 == 4) d = "FRI";
    if(d_diff % 7 == 5) d = "SAT";
    if(d_diff % 7 == 6) d = "SUN";

    cout<<d;

return 0;
}
