
class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int target_arrival_time = times[targetFriend][0];

        sort(times.begin(), times.end());

        priority_queue<int, vector<int>, greater<int>> pq_chairs;
        for (int i = 0; i < times.size(); i++)
        {
            pq_chairs.push(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_leaving;

        for (auto x : times)
        {
            int arrival_time = x[0];
            int departure_time = x[1];

            while (!pq_leaving.empty() && pq_leaving.top().first <= arrival_time)
            {
                pq_chairs.push(pq_leaving.top().second);
                pq_leaving.pop();
            }

            int chair = pq_chairs.top();
            pq_chairs.pop();

            pq_leaving.push(make_pair(departure_time, chair));
            if (target_arrival_time == arrival_time)
                return chair;
        }
        return -1;
    }
};