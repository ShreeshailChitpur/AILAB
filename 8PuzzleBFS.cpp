#include <bits/stdc++.h>
using namespace std;

void printAss(vector<vector<vector<int>>> &ans){
    for(auto mac:ans){
        for(auto row:mac){
            for(auto ele:row){
                cout << ele << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

bool checkEqual(vector<vector<int>> start, vector<vector<int>> goal){
    return start == goal;
}

pair<int, int> findBlank(vector<vector<int>> curr){
    pair<int, int> ans;
    for(int i=0;i<3;i++){
        for(int j = 0; j<3;j++){
            if(curr[i][j] == 0){
                ans = {i,j};
                break;
            }
        }
    }
    return ans;
}

void bfs(vector<vector<int>> start, vector<vector<int>> goal){
    vector<vector<vector<int>>> ans;
    queue<pair<vector<vector<int>>, vector<vector<vector<int>>>>> q;

    q.push({start, ans});
    int delrow[] = {0,1,0,-1};
    int delcol[] = {1,0,-1,0};
    
    while(!q.empty()){
        int size = q.size();
        bool flag = false;
        while(size--){
            vector<vector<int>> curr = q.front().first;
            vector<vector<vector<int>>> vec = q.front().second;
            q.pop();
            
            if(checkEqual(curr, goal)){
                cout<<"Possible solution: "<<endl;
                printAss(vec);
                flag=true;
                break;
            }
            pair<int,int> blank = findBlank(curr);
            int row = blank.first;
            int col = blank.second;
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<3 && ncol>=0 && ncol<3){
                    swap(curr[row][col], curr[nrow][ncol]);
                    vec.push_back(curr);
                    q.push({curr,vec});
                    vec.pop_back();
                    swap(curr[row][col], curr[nrow][ncol]);
                }
            }
        }
        if(flag){
            break;
        }
    }
}

int main(){
    vector<vector<int>> start={{2,8,3},{1,6,4},{7,0,5}};
    vector<vector<int>> goal={{1,2,3},{8,0,4},{7,6,5}};

    bfs(start, goal);
    return 0;
}