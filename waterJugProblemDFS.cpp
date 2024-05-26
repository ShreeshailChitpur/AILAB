#include <bits/stdc++.h>
#include <queue>
using namespace std;

void bfs(pair<int, int> start, pair<int, int> end){
    queue<pair<pair<int, int>, vector<pair<int, int>>>> q;
    q.push({start, {{0, 0}}});
    while(!q.empty()){
        bool flag = false;
        int size = q.size();
        while(size--){
            pair<int, int> curr = q.front().first;
            vector<pair<int, int>> path = q.front().second;
            int x = curr.first;
            int y = curr.second;
            q.pop();

            //check for solutoin
            if(curr == end){
                cout<< "Possible solution: "<<endl;
                for(auto it:path){
                    cout<<it.first<<" "<<it.second<<endl;
                }
                flag = true;
                break;
            }
            if(x<4){
                pair<int, int> node = {4, y};
                path.push_back(node);
                q.push({node, path});
                path.pop_back();
            }
            if(y<3){
                pair<int, int> node = {x, 3};
                path.push_back(node);
                q.push({node, path});
                path.pop_back();
            }
            if(x>0){
                pair<int, int> node = {0, y};
                path.push_back(node);
                q.push({node, path});
                path.pop_back();
            }
            if(y>0){
                pair<int, int> node = {x, 0};
                path.push_back(node);
                q.push({node, path});
                path.pop_back();
            }
            if(x+y>=4 && y>0){
                pair<int, int> node = {4, y-(4-x)};
                path.push_back(node);
                q.push({node, path});
                path.pop_back();
            }
            if(x+y>=3 && x>0){
                pair<int, int> node = {x-(3-y), 3};
                path.push_back(node);
                q.push({node, path});
                path.pop_back();
            }
            if(x+y<=4 && y>0){
                pair<int, int> node = {x+y, 0};
                path.push_back(node);
                q.push({node, path});
                path.pop_back();
            }
            if(x+y<=3 && x>0){
                pair<int, int> node = {0, x+y};
                path.push_back(node);
                q.push({node, path});
                path.pop_back();
            }
        }
        if(flag){
            break;
        }
    }
}

int main(){
    pair<int, int> start = {0,0};
    pair<int, int> end = {2,0};
    bfs(start, end);
    
    return 0;
}
