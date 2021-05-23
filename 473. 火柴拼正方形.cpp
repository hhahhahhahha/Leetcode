class Solution {
public
    int size;
    bool makesquare(vectorint& matchsticks) {与困难题同思路
        int total = 0;
        int row[4];
        size = matchsticks.size();
        memset(row, 0, sizeof(row));
        for(auto &stick matchsticks){
            total += stick;
        }

        sort(matchsticks.begin(), matchsticks.end(), [&](int &a, int &b){
            return ab;
        });

        if (total % 4 != 0) return false;
        total = 4;每边长度
        return dfs(total, row, matchsticks, 0);
    }

    bool dfs(int max, int row[4], const vectorint & matchsticks, int index){
        if (index == size) return true;

        for (int i = 0; i  4; ++i){
            if (row[i] + matchsticks[index] = max){
                row[i] += matchsticks[index];
                if(dfs(max, row, matchsticks, index + 1)) return true;
                row[i] -= matchsticks[index];
            }

            if (row[i] == 0  row[i] + matchsticks[index] == max){
                break;
            }
        }

        return false;
    }
};
