#include <iostream>
using namespace std;

int main(){
    int card[50];
    int cardb[50];
    while(1){
        int n,r;
        cin >> n >> r;
        if(n==0 && r==0){
            break;
        }
        for(int i=0;i<n;i++){
            card[i] = n-i;
            cardb[i] = n-i;
        }
        for(int i=0;i<r;i++){
            int p,c;
            cin >> p >> c;
            for(int j=0;j<p-1;j++){
                cardb[c+j] = card[j];
            }
            for(int j=0;j<c;j++){
                cardb[j] = card[p-1+j];
            }
            for(int j=0;j<n;j++){
                card[j] = cardb[j];
            }
        }

        cout << card[0] << '\n';

    }
    return 0;
}
