#include <bits/stdc++.h>
using namespace std;

bool mycompare(vector<int> interval1, vector<int> interval2){

    return interval1[0] < interval2[0];
}
vector<vector<int>> mergeIntervals(vector<vector<int>> intervals){

    //sort the intervals in ascending order
    sort(intervals.begin(), intervals.end(),mycompare);

    stack<vector<int>> s;

    s.push(intervals[0]);

    for (int i = 1; i < intervals.size(); i++){

        vector<int> interval = s.top();

        if(intervals[i][0] <= interval[1]){
            //merge both these intervals
            s.pop();

            s.push({(min(intervals[i][0], interval[0])), max(interval[1], intervals[i][1])});
        }
        else{
            s.push(intervals[i]);
        }
    }

    intervals.clear();

    while(!s.empty()){

        intervals.push_back(s.top());
        s.pop();
    }

    return intervals;
}
int main(){
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {6, 10},
        {15, 18}};

    intervals = mergeIntervals(intervals);

    for (int i = 0; i < intervals.size(); i++){

        cout << "["<<intervals[i][0] << "," << intervals[i][1] << "] ";
    }
    
    return 0;
}