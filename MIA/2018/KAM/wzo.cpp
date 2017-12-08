#include <iostream>
using namespace std;

const int MAX_SIZE = 1100000;

int houseCount, cameraCount, intervalSize, houseNum;
bool hasCamera[MAX_SIZE];

int main() {
	cin >> houseCount >> cameraCount >> intervalSize;
	for(int i = 0; i < cameraCount; i++) {
		cin >> houseNum;
		hasCamera[houseNum] = true;
	}
	int curCameraCount = 0;
	int result = 0;
	for(int houseNum = 1; houseNum <= houseCount; houseNum++) {
		if(hasCamera[houseNum]) {
			curCameraCount++;
		}	
		if(houseNum == intervalSize - 1 && curCameraCount == 0) {
			hasCamera[houseNum] = true;
			curCameraCount++;
			result++;
		}
		if(houseNum == intervalSize && curCameraCount <= 1) {
			hasCamera[houseNum] = true;
			curCameraCount++;
			result++;
		}
		if(houseNum <= intervalSize) {
			continue;
		}
		if(hasCamera[houseNum - intervalSize]) {
			curCameraCount--;
		}
		if(curCameraCount < 2) {
			hasCamera[houseNum] = true;
			curCameraCount++;
			result++;
		}
	}
	cout << result << "\n";
	return 0;
}
