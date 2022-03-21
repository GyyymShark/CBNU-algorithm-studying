#include<iostream>
#include<vector>
using namespace std;

int func (int n){
    if(n == 1) return 1;
    else if(n == 2) return 2;
    else if(n == 3) return 4;

    else 
        return func(n-1) + func(n-2) + func(n-3);
}

int main(){
    int T;
    cin>>T;

    for(int i=0;i<T;i++){

    int num;
    cin>>num;

    cout<<func(num)<<endl;
    }
}
