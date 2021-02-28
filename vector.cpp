#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

vector< vector<int> > insert_interval(vector< vector<int> > &intervals, vector<int> &newInterval) {
    vector< vector<int> > output;
    int last = 0;
    
    for(int i = 0; i < intervals.size(); i++) {
        if(intervals[i][0] < newInterval[0])
            output.push_back(intervals[i]);
    }
    
    last = output.size()-1;
    if(output[last][1] < newInterval[0]){
        output.push_back(newInterval);
    }
    else {
        if(newInterval[1] > output[last][1])
            output[last][1] = newInterval[1];
        else
            output[last][1] = output[last][1];
    }
    
    for(int i = 0; i < intervals.size(); i++) {
        if(intervals[i][0] > output[last][1])
            output.push_back(intervals[i]);
        else
            output[last][1] = intervals[i][1];
    }        
    return output;
}

/*
 * [[1,3],[6,9]]
*/
int main(){
    //vector< vector<int> > input;
    //vector<int> sub_vec;
    //vector< vector<int> > output;

    //sub_vec.push_back(1);
    //sub_vec.push_back(3);
    //input.push_back(sub_vec);

    //sub_vec[0] = 6;
    //sub_vec[1] = 9;
    //input.push_back(sub_vec);

    //sub_vec.push_back(2);
    //sub_vec.push_back(5);
    //output = insert_interval(&input, &sub_vec);

    //for(int i = 0; i < output.size(); i++){
        //for(int j = 0; i < output[i].size(); j++)
            //cout << output[i][j] << " ";
    //}    
    //cout << endl;

    vector<int> a;
    a.push_back(-1);
    a.push_back(-3);
    a.push_back(5);
    vector<int>::iterator begin = a.begin();
    vector<int>::iterator end = a.end();

    
    cout << *begin << " " << *(end-1) << endl;
}