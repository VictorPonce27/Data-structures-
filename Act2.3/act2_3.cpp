//
//  By victor Ponce A00827302
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "datos.h"
#include "Queue.h"
#include "Double_Linked_List.h"

int binaryS(Double_Linked_List<datos> &list, int n){
    int high = list.get_size() - 1;
    int low = 0;
    while (high >= low){
        int middle = (high + low) / 2;
        if (list[middle] == n){
            return middle;
        }
        else if (list[middle]<n){
            low = middle + 1;
        }
        else{
            high = middle - 1;
        }
    }
    return binaryS(list, list[high+1].get_time());
}


int binaryE(Double_Linked_List<datos> &list, int n){

    int high = list.get_size() - 1;
    int low = 0;
    while (high >= low){
        int middle = (high + low) / 2;
        if (list[middle] == n){
            return middle;
        }
        else if (list[middle]<n){
            low = middle + 1;
        }
        else{
            high = middle - 1;
        }
    }
    return binaryE(list, list[high-1].get_time());
}


int stringMonthToNum(string month){
    Double_Linked_List<string> months{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for(int i = 0; i<months.get_size();i++){
        if(months[i] == month){
            return i+1;
        }
    }
    return 0;
}


int daysToSec(int days){
    return days * 1000000;
}

int hoursToSec(int hours){
    return hours * 10000;
}

void validateMont(int &month){
    bool done = false;
    while(!done){
        if(month<=5 || month>10){
            cout << " You have enter an invalid value please choose month of search again: " << endl;
            cin >> month;
        }
        else{
            done = true;
        }
    }
}

void validateDay(int &day){
    bool done = false;
    while(!done){
        if(day<=0 || day>=31){
            cout << " You have enter an invalid value please the day of search again: " << endl;
            cin >> day;
        }
        else{
            done = true;
        }
    }
}

void validateHour(int hour){
    bool done = false;
    while(!done){
        if(hour<=0 || hour>=24){
            cout << " You have enter an invalid value please the day of search again: " << endl;
        }
        else{
            done = true;
        }
    }

}


int main(){
    Double_Linked_List<datos> infoList;
    string month;
    int day,hour,min,second,numMonth,start,end,date1,date2;
    string ip;
    string fail;
    string line;
    string type;
    char delim = ' ';
    bool done = false;
    bool next = false;

    //search variables
    int searchMonth1;
    int searchMonth2;
    int searchDay1;
    int searchDay2;
    int searchHour1;
    int searchHour2;

    ifstream inFile("bitacora.txt");
    //adding the info to the doubly linked list
    if(inFile.is_open()){
        while(getline(inFile,line)){
            stringstream ss(line);
            getline(ss,type,' ');
            month = type;
            getline(ss,type,' ');
            day = stoi(type);
            getline(ss,type,':');
            hour = stoi(type);
            getline(ss,type,':');
            min = stoi(type);
            getline(ss,type,' ');
            second = stoi(type);
            getline(ss,type,' ');
            ip = type;
            getline(ss,type);
            fail = type;
            numMonth = stringMonthToNum(month);
            datos var(month, numMonth, day, hour, min, second, ip, fail);
            infoList.add_last(var);
        }
    }
    infoList.sort();
    //output file
    infoList.Print(); 
    //asks for the range that you wan to see in the console; 
    while(!done){
        int middle = 0;

        cout<<"Choose initial month of search as number: "<<endl;
        cin >> searchMonth1;
        validateMont(searchMonth1);

        cout<<"Choose final month of search as number: "<<endl;
        cin >> searchMonth2;
        validateMont(searchMonth2);

        cout<<"choose initial day of serach: "<<endl;
        cin >> searchDay1;
        validateDay(searchDay1);

        cout<<"choose final day of search: "<<endl;
        cin >> searchDay2;
        validateDay(searchDay2);
        cout<<"Choose initial hour search"<<endl;
        cin >> searchHour1;

        cout<<"choose final hour of search"<<endl;
        cin >> searchHour2;


        date1 = (searchMonth1 * 100000000) + (searchDay1 * 1000000) + (searchHour1 * 10000);
        date2 = (searchMonth2 * 100000000) + (searchDay2 * 1000000) + (searchHour2 * 10000);
        //verefies that start search date is less than end search date
        if(date1 < date2){
            start = binaryS(infoList, date1);
            end = binaryE(infoList,date2);
        }
        else{
            end = binaryS(infoList, date1);
            start = binaryE(infoList, date2);
        }
            int count = 0;
            char temp = 'x';

            for(int i = start; i<=end;i++){
                if(count >= 20){
                    cout<<"To keep printing press enter, to stop type x "<<endl;
                    cin.get(temp);
                    if(temp == '\n'){
                        count = 0;
                    }
                    else{
                        i = end;
                    }

                }
                if(i<=end){
                infoList[i].print();
                }
                count++;
            }

        }
        return 0;
}
