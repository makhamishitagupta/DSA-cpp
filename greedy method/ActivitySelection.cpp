/*
🔷 Problem 1: Activity Selection
Given start and end times of activities, select the maximum number of activities
that don't overlap. Choose the earliest finishing activity greedily.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Activity
{
public:
    int start, end;
    Activity(int s, int e) : start(s), end(e) {}
};

bool cmp(Activity a, Activity b)
{
    return a.end < b.end;
}

class ActivitySelection
{
public:
    void selectActivities(vector<Activity> &activities)
    {
        sort(activities.begin(), activities.end(), cmp);
        int last_end = -1;
        cout << "Selected Activities:\n";
        for (auto act : activities)
        {
            if (act.start >= last_end)
            {
                cout << "[" << act.start << ", " << act.end << "]\n";
                last_end = act.end;
            }
        }
    }
};

int main()
{
    vector<Activity> activities = {{0, 6}, {3, 4}, {1, 2}, {5, 9}, {5, 7}, {8, 9}};
    ActivitySelection obj;
    obj.selectActivities(activities);
    return 0;
}
