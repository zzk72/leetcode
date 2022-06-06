#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int* cnt = new int[numCourses] {0};
        vector<vector<int> >G(numCourses);
        int s, e, cu, n = numCourses;
        for (int i = 0; i < prerequisites.size(); i++) {
            s = prerequisites[i][1];
            e = prerequisites[i][0];
            cnt[e]++;
            G[s].push_back(e);
        }
        queue<int>Q;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) {
                Q.push(i); flag = true;
            }
        }
        if (!flag)return false;
        int tmp;
        for (int i = 0; i < n; i++) {
            if (Q.empty())return false;
            tmp = Q.front(); Q.pop();
            while (!G[tmp].empty()) {
                int near = G[tmp].back();
                G[tmp].pop_back();
                cnt[near]--;
                if (cnt[near] == 0)Q.push(near);
            }
        }
        return true;
    }
};