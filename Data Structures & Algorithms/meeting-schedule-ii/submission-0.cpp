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
        vector<int> startTimes;
        vector<int> endTimes;
        for (int i = 0; i < intervals.size(); i++){
            startTimes.push_back(intervals[i].start);
            endTimes.push_back(intervals[i].end);
        }
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int maxRooms = 0;
        int ct = 0;
        int i = 0;
        int j = 0;
        while (i < startTimes.size()){
            if (startTimes[i] < endTimes[j]){
                ct++;
                maxRooms = max(maxRooms, ct);
                i++;
            } else {
                ct--;
                j++;
            }
        }
        return maxRooms;
    }
};
