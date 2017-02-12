#include <iostream>

using namespace std;

int ff, fs, sf, ss;

int countResult() {
	if(fs > 0 && fs > sf) {
		return ff + sf + sf + 1 + ss;
	}else if(fs > 0) {//sf >= fs
		return ff + fs + fs + ss;
	}else if(ff > 0) {//fs = 0
		return ff;
	}else {//fs = 0, ff = 0
		return ss + min(1, sf);
	}		
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> ff >> fs >> sf >> ss;
	cout << countResult();
	return 0;
}
