#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {
    vector<int> cNew;
    int found =0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < c.size(); j++) {
            if(c[j] == i) {
                cNew.push_back(1);
                found = 1;
            }
        }
        
        if(found == 0) {
            cNew.push_back(0);
        }
        else {
            found = 0;
        }
    }
    
    for(auto i : cNew) {
        cout << i << " ";
    }
    cout << "\n";
    
    int maxVal = 0;
    int indexStopped = 0;
    int found1 = 0;
    
    for(int i = 0; i < n; i = indexStopped) {
        //cout << "t" << i << endl;
        if(cNew[i] == 0) {
            if(i == 0) {
                for(int j = i+1; j < n; j++) {
                    if(cNew[j] == 1) {
                        indexStopped = j;
                        found1 = 1;
                        break;
                    }
                }
                if(found1 == 1) {
                    maxVal = max(maxVal, indexStopped - i);
                    found1 = 0;
                }
                else {
                    maxVal = 0;
                    break;
                }
            }
            
        }
        else {
            for(int j = i+1; j < n; j++) {
                if(cNew[j] == 1) {
                    indexStopped = j;
                    found1 = 1;
                    break;
                }
            }
            if(found1 == 1) {
                maxVal = max(maxVal, (indexStopped - i)/2);
                found1 = 0;
            }
            else {
                maxVal = max(maxVal, (n-1) - i);
                break;
            }
        }
        
        
    }
    
    return maxVal;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

    fout << result << "\n";

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
