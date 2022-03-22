#include<iostream>
#include<algorithm>
using namespace std;

int dp[1000001];

int func(int n){
    int result;
    int mins[5] = {1000,1000,1000,1000,1000};

    if(n==1) return 1;
    if(n==2) return 1;
    if(n==3) return 1;
    //if(n==4) return 2;

    if(n%3==0){ //3으로 나누어 떨어지면
        return 1 + func(n/3);
    }
    if(n%2 == 0){
        mins[0] =  1 + func(n/2);
    }
    if((n-1)%3 ==0){
        mins[1] = 1 + func((n-1));
    }
    if((n-2)%3 == 0){
        mins[2] = 2 + func((n-2));
    }
    if((n-1)%2 == 0){
        mins[3] = 1 + func((n-1));
    }
    if((n-2)%2 == 0){
        mins[4] = 2 + func((n-2));
    }

   return result = *min_element(mins,mins+5);
}

int main(){
    int num;
    //while(1){
    cin>>num;

    cout<<func(num)<<endl;
    //}
}