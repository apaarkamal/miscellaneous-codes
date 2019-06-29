#include <iostream>
using namespace std;
int main() {
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
    int n,mid;
    cin>>n;
    // for middle rows and colums
    mid=(n+1)/2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1){// for 1st row 
                if(j==1||j>=mid){
                    cout<<"*";
                }
                else if(j>=mid){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
            else if(i==mid){// for middle row
                cout<<"*";
            }
            else if(i==n){// for last row
                if(j==n||j<=mid){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
            else{// for rest of the rows
                if(i<mid){
                    if(j==1||j==mid){
                        cout<<"*";
                    }
                    else{
                        cout<<" ";
                    }
                }
                else{
                    if(j==n||j==mid){
                        cout<<"*";
                    }
                    else{
                        cout<<" ";
                    }
                }
            }
        }
        cout<<'\n';
    }
}
