/*
🔷 Problem 4: Job Scheduling with Deadlines
Schedule jobs to maximize total profit, each job takes 1 unit of time and must be
done before its deadline.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job
{
public:
    char id;
    int deadline, profit;
    Job(char i, int d, int p) : id(i), deadline(d), profit(p) {}
};

bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

class JobScheduler
{
public:
    void scheduleJobs(vector<Job> &jobs)
    {
        sort(jobs.begin(), jobs.end(), cmp);
        int maxDeadline = 0;
        for (auto job : jobs)
            maxDeadline = max(maxDeadline, job.deadline);
        vector<char> slot(maxDeadline + 1, '-');
        int totalProfit = 0;

        for (auto job : jobs)
        {
            for (int j = job.deadline; j > 0; j--)
            {
                if (slot[j] == '-')
                {
                    slot[j] = job.id;
                    totalProfit += job.profit;
                    break;
                }
            }
        }

        cout << "Scheduled Jobs: ";
        for (int i = 1; i <= maxDeadline; i++)
            if (slot[i] != '-')
                cout << slot[i] << " ";
        cout << "\nTotal Profit: " << totalProfit << "\n";
    }
};

int main()
{
    vector<Job> jobs = {
        {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    JobScheduler obj;
    obj.scheduleJobs(jobs);
    return 0;
}
