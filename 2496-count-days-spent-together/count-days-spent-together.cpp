class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int day = 0;
        int am = stoi(arriveAlice.substr(0, 2));
        int la = stoi(leaveAlice.substr(0, 2));
        int ab = stoi(arriveBob.substr(0, 2));
        int lb = stoi(leaveBob.substr(0, 2));
        int am1 = stoi(arriveAlice.substr(3, 2));
        int la1 = stoi(leaveAlice.substr(3, 2));
        int ab1 = stoi(arriveBob.substr(3, 2));
        int lb1 = stoi(leaveBob.substr(3, 2));
        vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int alicest = am1;
        for (int i = 0; i < am - 1; i++) {
            alicest += month[i];
        }
        int aliceend = la1;
        for (int i = 0; i < la - 1; i++) {
            aliceend += month[i];
        }
        int bobst = ab1;
        for (int i = 0; i < ab - 1; i++) {
            bobst += month[i];
        }
        int bobend = lb1;
        for (int i = 0; i < lb - 1; i++) {
            bobend += month[i];
        }
        int start = max(alicest, bobst);
        int end = min(aliceend, bobend);

        if (start <= end) {
            day = end - start + 1;
        }
        return day;
    }
};