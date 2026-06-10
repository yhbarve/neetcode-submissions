/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts;
        vector<int> ends;
        for (auto i : intervals){
            starts.push_back(i.start);
            ends.push_back(i.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int i = 0;
        int j = 0;
        int curMeetings = 0;
        int maxMeetings = 0;
        while (i < starts.size() && j < ends.size()){
            if (starts[i] < ends[j]){
                curMeetings++;
                maxMeetings = max(maxMeetings, curMeetings);
                i++;
            } else {
                curMeetings--;
                j++;
            }
        }
        return maxMeetings;
    }
};
