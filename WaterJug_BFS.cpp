#include <bits/stdc++.h>
using namespace std;

int main()
{
    //                      4, 3
    pair<int, int> start = {0, 0};
    pair<int, int> end = {2, 0};
    queue<pair<pair<int, int>, vector<pair<int, int>>>> q;
    q.push({start, {{0, 0}}});
    while (!q.empty())
    {
        bool flag = false;
        int size = q.size();
        while (size--)
        {
            pair<int, int> curr = q.front().first;
            vector<pair<int, int>> vec = q.front().second;
            int x = curr.first;
            int y = curr.second;
            q.pop();
            if (curr == end)
            {
                cout << "Possible solution:" << endl;
                for (auto it : vec)
                    cout << it.first << " " << it.second << endl;
                flag = true;
                break;
            }
            if (x < 4)
            {
                pair<int, int> node = {4, y};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
            if (y < 3)
            {
                pair<int, int> node = {x, 3};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
            if (x > 0)
            {
                pair<int, int> node = {0, y};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
            if (y > 0)
            {
                pair<int, int> node = {x, 0};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
            if (x + y >= 4 && y > 0)
            {
                pair<int, int> node = {4, y - (4 - x)};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
            if (x + y >= 3 && x > 0)
            {
                pair<int, int> node = {x - (3 - y), 3};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
            if (x + y <= 4 && y > 0)
            {
                pair<int, int> node = {x + y, 0};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
            if (x + y <= 3 && x > 0)
            {
                pair<int, int> node = {0, x + y};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
        }
        if (flag)
            break;
    }
    return 0;
}