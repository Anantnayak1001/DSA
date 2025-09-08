#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> CalculateWarmerDays(vector<int> &dailyTemps) {
    int daysCount = dailyTemps.size();
    stack<int> indexStack;
    vector<int> waitingDays(daysCount);

    for (int currentDay = daysCount - 1; currentDay >= 0; currentDay--) {
        while (!indexStack.empty() && dailyTemps[indexStack.top()] <= dailyTemps[currentDay]) {
            indexStack.pop();
        }

        waitingDays[currentDay] = indexStack.empty() ? 0 : (indexStack.top() - currentDay);
        indexStack.push(currentDay);
    }

    return waitingDays;
}

void PrintResults(const vector<int> &results) {
    for(int i = 0; i < results.size(); i++) {
        cout << results[i] << "\t";
    }
    cout << endl;
}

int main() {
    vector<int> temperatures = {2, 4, 3, 1, 8, 5, 9, 88};
    
    vector<int> daysToWait = CalculateWarmerDays(temperatures);

    cout << "Days to wait for warmer temperature: ";
    PrintResults(daysToWait);
    
    return 0;
}