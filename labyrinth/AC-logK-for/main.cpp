#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N, M; cin >> N >> M;

    // 存在判定

    int n = 2 * N + 1;
    vector<string> ans(n, string(n, '#'));
    for(int i = 1; i < n; i += 2){
        for(int j = 1; j < n; j += 2){
            ans[i][j] = '.';
        }
    }

    int y = 1, x = 1;

}