class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
         sort(meetings.begin(), meetings.end());
        
        int totalCoveredDays = 0;
        int currentStart = -1, currentEnd = -1;
        
        // Step 2: Merge overlapping meetings and count total covered days
        for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            
            if (start > currentEnd) {
                // If no overlap, add the covered days from the previous meeting
                if (currentStart != -1) {
                    totalCoveredDays += currentEnd - currentStart + 1;
                }
                // Start a new merged meeting
                currentStart = start;
                currentEnd = end;
            } else {
                // If overlap, extend the current merged meeting
                currentEnd = max(currentEnd, end);
            }
        }
        
        // Add the last merged meeting's days
        if (currentStart != -1) {
            totalCoveredDays += currentEnd - currentStart + 1;
        }
        
        // Step 3: Subtract the total covered days from the total available days
        return days - totalCoveredDays;
    }
};