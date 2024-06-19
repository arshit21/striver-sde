class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> vec;
        for(int i = 0; i < intervals.size()-1; i++){
            if(intervals[i].back() >= intervals[i+1].front() && intervals[i].back() <= intervals[i+1].back()){
                vec.push_back(intervals[i].front());
                vec.push_back(intervals[i+1].back());
                intervals.erase(intervals.begin()+i, intervals.begin()+i+2);
                intervals.insert(intervals.begin()+i, vec);
                i = i - 2;
                vec.clear();
            }
            else if(intervals[i].back() >= intervals[i+1].front() && intervals[i].back() > intervals[i+1].back()){
                vec.push_back(intervals[i].front());
                vec.push_back(intervals[i].back());
                intervals.erase(intervals.begin()+i, intervals.begin()+i+2);
                intervals.insert(intervals.begin()+i, vec);
                i = i - 2;
                vec.clear();
            }
            if(i < -1){
                i = -1;
            }
        }
        return intervals;
    }      
};