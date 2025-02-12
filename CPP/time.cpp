#include<bits/stdc++.h>
using namespace std;

vector<int> getUnexpiredTokens(int time_to_live, vector<string> queries) {
    vector<int> res;
    vector<vector<string>> que;
    vector<string> curr;
    unordered_map<string, int> exMap;
    for(auto q : queries){
        curr.clear();
        stringstream ss(q);
        string temp = "";
        while(getline(ss, temp, ' ')){
            curr.push_back(temp);
        }
        que.push_back(curr);
    }
    for(auto q : que){
        if(q[0]=="generate"){
            int currTime = stoi(q[2]);
            exMap[q[1]]=(time_to_live+currTime);
        }else if(q[0]=="renew"){
            int currTime = stoi(q[2]);
            auto j = exMap.find(q[1]);
            if(j!=exMap.end()){
                if(j->second<currTime){
                    cout << "renewing " << q[1];
                    exMap[q[1]]=(time_to_live+currTime);
                }
            }
        }else{
            int currTime = stoi(q[1]);
            int count = 0;
            for(auto j : exMap){
                cout << j.first << " " << j.second << "\n";
                if(j.second > currTime){
                    count++;
                }
            }
            res.push_back(count);
        }
    }
    return res;

}

int main(){
    vector<string> queries = {"generate a 3", "renew a 5", "generate a 7", "renew a 8", "generate a 9", "count 12"}
    return 0;
}