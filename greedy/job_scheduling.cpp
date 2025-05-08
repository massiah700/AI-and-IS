#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Compare jobs by deadline (index 2)
bool compareJobs(const vector<int> &job1, const vector<int> &job2)
{
    return job1[2] < job2[2]; // deadline comparison
}

pair<int, vector<vector<int>>> greedyJobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), compareJobs);

    int current_time = 0;
    vector<vector<int>> scheduled_jobs;
    int total_profit = 0;

    for (auto &job : jobs)
    {
        int processing_time = job[0];
        int profit = job[1];
        int deadline = job[2];

        if (current_time + processing_time <= deadline)
        {
            current_time += processing_time;
            scheduled_jobs.push_back(job);
            total_profit += profit;
        }
    }

    return {total_profit, scheduled_jobs};
}

int main()
{
    vector<vector<int>> jobs = {
        {2, 60, 4},
        {1, 100, 1},
        {3, 20, 3},
        {2, 40, 2},
        {1, 20, 2}};

    auto result = greedyJobScheduling(jobs);

    cout << "Total profit earned: " << result.first << endl;
    cout << "Scheduled jobs:\n";
    for (auto &job : result.second)
    {
        cout << "Processing time: " << job[0]
             << ", Profit: " << job[1]
             << ", Deadline: " << job[2] << endl;
    }

    return 0;
}
