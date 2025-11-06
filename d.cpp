#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    double value, weight;
};

bool cmp(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

double fractionalKnapsack(double W, vector<Item> &items) {
    sort(items.begin(), items.end(), cmp);
    double totalValue = 0.0, remainingWeight = W;
    for (auto &item : items) {
        if (item.weight <= remainingWeight) {
            remainingWeight -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * (remainingWeight / item.weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    double capacity = 50;
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    cout << fractionalKnapsack(capacity, items) << endl;
    return 0;
}
