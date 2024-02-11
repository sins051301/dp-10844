#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<long long int>stair_size[10000];

int main() {
    
    int n, i, j;
    long long int mod = 1000000000, stair=0;     
    cin >> n;
   //처음은 0 1 1 1 1 1 1 1 1 1 로 초기화 해준다.
    for (i = 0; i <= 9; i++) {
        stair_size[0].push_back(1);
    }

    stair_size[0][0] = 0;  

    for (i = 1; i < n; i++) {
        stair_size[i].resize(10, 0);   //배열 초기화
        for (j = 0; j <= 9; j++) {
            if (j == 0) {    
                stair_size[i][j] = stair_size[i-1][j+1]%mod;   
                
            }
            else if (j == 9) {
                stair_size[i][j] = stair_size[i-1][j-1]%mod;

            }
            else {
                stair_size[i][j] = stair_size[i-1][j-1]%mod + stair_size[i - 1][j+1] % mod;
            }
        }
    }

      for (i = 0; i <= 9; i++) {
            stair += stair_size[n - 1][i];   //각 개수를 다 더해준다.
      }

     cout << stair%mod;   


}