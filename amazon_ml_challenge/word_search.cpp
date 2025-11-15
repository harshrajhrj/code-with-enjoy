#include <bits/stdc++.h>
using namespace std;

bool wordsearch(vector<vector<char>> &grid, string word)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};

    function<bool(int, int, int)> dfs = [&](int i, int j, int index) -> bool
    {
        if (word.length() - 1 == index)
            return grid[i][j] == word[index];

        // if current letter in grid = current letter in word then bypass this condition
        if (grid[i][j] != word[index])
            return false;

        visited[i][j] = true;

        for (int k = 0; k < 4; k++)
        {
            int _row = i + row[k];
            int _col = j + col[k];

            if (_row >= 0 && _row < m && _col >= 0 && _col < n && !visited[_row][_col])
                if (dfs(_row, _col, index + 1))
                    return true;
        }

        visited[i][j] = false;
        return false;
    };

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dfs(i, j, 0)) // always start from index = 0 because we don't know where to start first letter of the word
                return true;  // word found
        }
    }

    return false; // word not found
}
int main()
{
    vector<vector<char>> grid = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << wordsearch(grid, word);
    return 0;
}