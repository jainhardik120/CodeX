#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fin;
    fin.open("keymap.txt");
    string line;
    while(getline(fin, line)){
        cout << "map[\"";
        for (int i = 5; i < line.length(); i++)
        {
            cout << line[i];
        }
        
        cout << "\"] = ";
        cout << line[0] << line[1] << line[2] << line[3] << endl;
    }
    fin.close();
    return 0;
}