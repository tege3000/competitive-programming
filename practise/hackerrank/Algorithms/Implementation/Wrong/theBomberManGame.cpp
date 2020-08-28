#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid) {
    int row = grid.size();
    int col = grid[0].size();
    
    
    if(n == 1) {
        return grid;
    }
    
    for(int z = 0; z < n; z++) {
        // initially do nothing, except identify the marked indexes with bombs
        vector<vector<int>> marked;
        
        for(int a = 0; a < row; a++) {
            for(int b = 0; b < col; b++) {
                vector<int> index;
                
                if(grid[a][b] == 'O') {
                    index.push_back(a);
                    index.push_back(b);
                    
                    marked.push_back(index);
                    
                }
            }
        }
        
        if(n == z) {
            return grid;
        }
        
        z++;
        for(int a = 0; a < row; a++) {
            for(int b = 0; b < col; b++) {
                
                if(grid[a][b] != 'O') {
                    grid[a][b] = 'O';
                }
            }
        }
        
        if(n == z) {
            return grid;
        }
        
        z++;
        for(int i = 0; i < marked.size(); i++) {
            
            int x = marked[i][0];
            int y = marked[i][1];
            
            grid[x][y] = '.';
            
            if(x != 0) {
                grid[x-1][y] = '.';
            }
            
            if(x != row-1) {
                grid[x+1][y] = '.';
            }
            
            if(y != 0) {
                grid[x][y-1] = '.';
            }
            
            if(y != col-1) {
                grid[x][y+1] = '.';
            }
            
        }
        
        if(n == z) {
            return grid;
        }
        
    }
    
    return grid;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}