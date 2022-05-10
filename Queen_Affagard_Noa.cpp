#include <iostream>
#include <vector>

using namespace std;


bool check(vector<vector<bool>>& grid, int row, int col) {
    int i, j;


    for (i = 0; i < col; i++)
        if (grid[row][i])
            return false;


    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (grid[i][j])
            return false;


    for (i = row, j = col; j >= 0 && i < grid.size(); i++, j--)
        if (grid[i][j])
            return false;

    return true;
}
void showBackTab(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
void showTab(vector<vector<bool>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
void QueenIterative(vector<vector<bool>>& grid, int nbQueen) {
    vector<vector<int>> backTab;
    for (int i = 0; i < 2; i++) {
        backTab.push_back(vector<int>(nbQueen));
        for (int j = 0; j < nbQueen; j++) {
            backTab[i][j] = -1;
        }
    }

    int queenPlaced = 0;
    int row = 0;
    int col = 0;
    int backCol = -1;

    while (nbQueen > queenPlaced) {
        if (check(grid, row, col)) {
            backCol++;
            backTab[0][backCol] = row;
            backTab[1][backCol] = col;

            grid[row][col] = true;
            queenPlaced++;
            if (col != nbQueen - 1) {
                col++;
                row = 0;
            }
            else {
                col = nbQueen - 1;
                row = nbQueen - 1;
            }
        }
        else if (row == nbQueen - 1) {
            if (col == nbQueen - 1) {
                
                grid[backTab[0][backCol]][backTab[1][backCol]] = false;

                if (backTab[0][backCol] + 1 < nbQueen) {
                    row = backTab[0][backCol] + 1;
                    col = backTab[1][backCol];
                }
                else if (backTab[1][backCol] + 1 < nbQueen) {
                    row = 0;
                    col = backTab[1][backCol] + 1;
                }
                else {
                    backCol--;
                    row = backTab[0][backCol] + 1;
                    col = backTab[1][backCol];
                    grid[backTab[0][backCol]][backTab[1][backCol]] = false;
                    backTab[0][backCol] = -1;
                    backTab[1][backCol] = -1;
                    queenPlaced--;
                }

                backTab[0][backCol] = -1;
                backTab[1][backCol] = -1;
                backCol--;
                queenPlaced--;
            }

            else {
                row = 0;
                col++;
            }
        }
        else {
            row++;
        }

    }
}

int main() {
    int nbQueen = 6;
    vector<vector<bool>> grid(nbQueen, vector<bool>(nbQueen, false));
    QueenIterative(grid, nbQueen);

    showTab(grid);

}
//Petit message pour te dire en toute honneteté que hugo ma fortement aidé pour ce devoir. je pense pas que j'y serai arrivé sans lui.