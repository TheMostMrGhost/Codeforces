#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    size_t start = 0, end = 0;
    int sum = 0;

    while (start < gas.size() && gas[start] < cost[start]) {
        start++;
    }

    if (start == gas.size()) {
        return -1;
    }

    end = (start + 1) % gas.size();
    sum = gas[start] - cost[start];

    while (start < gas.size() && start != end) {
        if (sum >= cost[end] - gas[end] && sum >= 0) {
            sum += gas[end] - cost[end];
            end = (end + 1) % gas.size();
        } else {
            start++;
            if (start == gas.size()) {
                break;
            }

            if (start == end) {
                sum = gas[start] - cost[start];
                end = (start + 1) % gas.size();
            }
        }
    }

    if (start == end && start != gas.size() && sum >= 0) {
        return start;
    }

    return -1;
}

int main(int argc, char *argv[]) {

    {
        vector<int> gas = {1, 2, 3, 4, 5};
        vector<int> cost = {3, 4, 5, 1, 2};
        cout << canCompleteCircuit(gas, cost) << endl;
    }
    {
        vector<int> gas = {2, 3, 4};
        vector<int> cost = {3, 4, 3};
        cout << canCompleteCircuit(gas, cost) << endl;
    }
    {
        vector<int> gas = {3, 3, 4};
        vector<int> cost = {3, 4, 4};
        cout << canCompleteCircuit(gas, cost) << endl;
    }
    {
        vector<int> gas = {1, 2, 3, 4, 5, 5, 70};
        vector<int> cost = {2, 3, 4, 3, 9, 6, 2};
        cout << canCompleteCircuit(gas, cost) << endl;
    }
    return 0;
}
