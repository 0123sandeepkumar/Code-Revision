class Solution {
public:
    int paths;
    
    void dfs(vector<vector<int>> &grid, int x, int y, int cntzero) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return;

        if (grid[x][y] == 1 || grid[x][y] == -1 || cntzero < 0) 
            return;
        if (grid[x][y] == 2) {
            if (cntzero == 0)
                paths ++;
            return;
        }
        
        grid[x][y] = -1;
        
        dfs(grid, x-1, y, cntzero-1);
        dfs(grid, x+1, y, cntzero-1);
        dfs(grid, x, y-1, cntzero-1);
        dfs(grid, x, y+1, cntzero-1);
        
        grid[x][y] = 0;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        paths = 0;
        int r = grid.size(), c = grid[0].size();
        
        int cntzero = 0;
        int starti, startj;
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                if (grid[i][j] == 1) {
                    starti = i, startj = j;
                } else if (grid[i][j] == 0) {
                    cntzero ++;
                }
            }
        }
        
        dfs(grid, starti-1, startj, cntzero);
        dfs(grid, starti+1, startj, cntzero);
        dfs(grid, starti, startj-1, cntzero);
        dfs(grid, starti, startj+1, cntzero);
        return paths;
    }
};