#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

void print_matrix(vector< vector<char> > &matrix, int row, int col)
{
    for(int i = row; i < matrix.size(); i++){
        for(int j = col; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int find_square(vector< vector<char> > &matrix, int i, int j) {
    int right_edge = 0;
    int down_edge = 0;
    int right_start = j;
    int down_start = i;
    int area = 0;
    int ret = 0;
    int flag = 0;

    print_matrix(matrix, down_start, right_start);
    while(j < matrix[down_start].size()){
        if(matrix[down_start][j] == '1')
            right_edge++;
        else
            break;
        j++;
    }
    while(i < matrix.size()) {
        if(matrix[i][right_start] == '1')
            down_edge++;
        else
            break;
        i++;
    }
    cout << down_edge << " " << right_edge << endl;
    int sq_len = min(right_edge, down_edge);

    for(int max_len = sq_len; max_len > 0; max_len--){
        for(int k = 0; k < max_len; k++) {
            for(int l = 0; l < max_len; l++) {
                if(matrix[down_start + k][right_start + l] == '1')
                    area++;
                else
                    area = INT_MIN;
            }
        }
        ret = max(ret, area);
        area = 0;
    }
    cout << "area = " << ret << endl;
    return ret;
}

int maximalSquare(vector< vector<char> > &matrix) {
    int max_area = 0;
    int area = 0;

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            if((matrix[i][j] == '1') && (i < matrix.size()-1) && (j < matrix[i].size()-1) ) {
                cout << "[" << i << " " << j << "]" << endl;
                area = find_square(matrix, i, j);
                max_area = max(max_area, area);
            }
        }
    }
    return max_area;
}

int main() {
    vector<char> row1 = {'1','0','1','1','0','1'};
    vector<char> row2 = {'1','1','1','1','1','1'};
    vector<char> row3 = {'0','1','1','0','1','1'};
    vector<char> row4 = {'1','1','1','0','1','0'};
    vector<char> row5 = {'0','1','1','1','1','1'};
    vector<char> row6 = {'1','1','0','1','1','1'};
    vector<char> row7 = {'1','1','1','0'};
    vector< vector<char> > input;
    
    input.push_back(row1);
    input.push_back(row2);
    input.push_back(row3);
    input.push_back(row4);
    input.push_back(row5);
    input.push_back(row6);
    //input.push_back(row7);

    print_matrix(input, 0, 0);
    int ret = maximalSquare(input);
    
    cout << ret << endl;
}