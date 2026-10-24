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

        int count=0;
        
        for(int i=1; i<=365; i++){
            if(i >= dayAliceArrive && i <= dayAliceLeave && 
            i >= dayBobArrive && i <= dayBobLeave){
                count++;
            }
        }

        return count;
    }
};