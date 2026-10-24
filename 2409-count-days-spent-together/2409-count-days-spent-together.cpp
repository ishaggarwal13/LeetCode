class Solution {
public:
    int findDay(string date){
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        //stoi to convert into integer and subtr to find date and month in str
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3,2));

        int total = day;

        for(int i=0; i<month-1; i++){
            total += days[i];
        }

        return total;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int dayAliceArrive = findDay(arriveAlice);
        int dayAliceLeave = findDay(leaveAlice);

        int dayBobArrive = findDay(arriveBob);
        int dayBobLeave = findDay(leaveBob);

        int start = max(dayAliceArrive, dayBobArrive);
        int end = min(dayAliceLeave, dayBobLeave);

        return max(0, (end-start+1));
    }
};