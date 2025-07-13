#include <iostream>
#include <vector>
using namespace std;

// we are assuming start and checking either we reach to next station 
// if not (gas deficit , -ve value) we move to next index
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int currentGas = 0;
        int totalGas = 0;
        int totalCost = 0;

        for (int i = 0; i < gas.size(); i++) {
            currentGas += gas[i] - cost[i];
            totalGas += gas[i];
            totalCost += cost[i];

            if (currentGas < 0) {
                start = i + 1;
                currentGas = 0;
            }
        }

        if (totalGas < totalCost) {
            return -1;
        } else {
            return start;
        }
    }


int main() {
    
    vector<int> gas  = {4, 6, 7, 4};
    vector<int> cost = {6, 5, 3, 5};


    int result = canCompleteCircuit(gas, cost);

    if (result != -1) {
        cout << "Start index to complete the circuit: " << result << endl;
    } else {
        cout << "It's not possible to complete the circuit." << endl;
    }
}
