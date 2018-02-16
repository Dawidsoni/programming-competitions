#include <iostream>
#include <queue>
using namespace std;

class Passenger {
public:
     Passenger(int index_, int time_, int floor_) {
        index = index_;
        time = time_;
        floor = floor_;
    }

    int index, time, floor;
};

int pCount, elTimeWait, elCapacity, roryIndex;
int input_id, input_time, input_floor;
int curTime, curTrip, lastPassIndex;
queue<Passenger> pQueue[2];
int arriveTime[110], tripNum[110];

void updateCurTime() {
    int lastPassTime;
    if(pQueue[1].size() > 0 && (pQueue[0].empty() || pQueue[0].front().time >= pQueue[1].front().time)) {
        lastPassTime = pQueue[1].front().time + elTimeWait;
    }else {
        lastPassTime = pQueue[0].front().time + elTimeWait;
    }
    curTime = max(curTime + elTimeWait, lastPassTime);
}

vector<Passenger> getPassengerList() {
    vector<Passenger> result;
    while(pQueue[1].size() > 0 &&  pQueue[1].front().time <= curTime && result.size() < elCapacity) {
        result.push_back(pQueue[1].front());
        lastPassIndex = pQueue[1].front().index;
        pQueue[1].pop();
    }
    while(pQueue[0].size() > 0 &&  pQueue[0].front().time <= curTime && result.size() < elCapacity) {
        result.push_back(pQueue[0].front());
        lastPassIndex = pQueue[0].front().index;
        pQueue[0].pop();
    }
    return result;
}

void runElevator(vector<Passenger>& pList) {
    int maxFloor = 0;
    for(int i = 0; i < (int)pList.size(); i++) {
        maxFloor = max(maxFloor, pList[i].floor);
        arriveTime[pList[i].index] = curTime + pList[i].floor;
        tripNum[pList[i].index] = curTrip;
    }
    curTime += (maxFloor * 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> pCount >> elTimeWait >> elCapacity >> roryIndex;
    for(int i = 0; i < pCount; i++) {
        cin >> input_id >> input_time >> input_floor;
        pQueue[input_id - 1].push(Passenger(i + 1, input_time, input_floor));
    }
    curTrip = 1;
    while(pQueue[0].size() > 0 || pQueue[1].size() > 0) {
        updateCurTime();
        vector<Passenger> pList = getPassengerList();
        runElevator(pList);
        curTrip++;
    }
    cout << tripNum[roryIndex] << " " << arriveTime[lastPassIndex] << "\n";
    return 0;
}
