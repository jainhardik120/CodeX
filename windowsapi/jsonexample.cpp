#include<iostream>
#include"json.hpp"

using json = nlohmann::json;

using namespace std;

int main(){
    
    string jsonData = "[{\"type\":3,\"data\":\"078,78\"},{\"type\":5,\"data\":\"500\"},{\"type\":1,\"data\":\"haridk\"},{\"type\":1,\"data\":\"\"}]";
    auto json = json::parse(jsonData);
    for (int i = 0; i < json.size(); i++)
    {
        int type = json[i]["type"];
        string data = json[i]["data"];
        cout << type << " : " << data << endl;
    }
    
    return 0;
}