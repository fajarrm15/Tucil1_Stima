#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

string removeSpace(string input) {
    string str = "";
    for(int i = 0; i < input.length(); i++) {
        if (input[i]!=' ')
        {
            str += input[i];
        }
    }
    return str;
}

bool searchRight(string soal, string pattern, int j, int* sum) {
    bool flag = false;
    if(soal.length()-j>=pattern.length()){
        int i = j;
        int count = 0;
        while (!flag && i < soal.length())
        {
            if (soal[i]==pattern[count])
            {
                count++;
                i++;
                (*sum)++;
            }else{
                (*sum)++;
                flag = true;
            }
        }
        if(count==pattern.length()){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool searchDown(vector<string> soal, string pattern, int i, int j,int *sum){
    bool flag = false;
    if(soal.size()-i>=pattern.length()){
        int a = i;
        int count = 0;
        while (!flag && a < soal.size())
        {
            if (soal[a][j]==pattern[count])
            {
                count++;
                a++;
                (*sum)++;
            }else{
                (*sum)++;
                flag = true;
            }
        }
        if(count==pattern.length()){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool searchLeft(string soal, string pattern, int j,int *sum){
    bool flag = false;
    if(j+1>=pattern.length()){
        int i = j;
        int count = 0;
        while (!flag && i >= 0)
        {
            if (soal[i]==pattern[count])
            {
                count++;
                i--;
                (*sum)++;
            }else{
                (*sum)++;
                flag = true;
            }
        }
        if(count==pattern.length()){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool searchUp(vector<string> soal, string pattern, int i,int j,int *sum){
    bool flag = false;
    if(i+1>=pattern.length()){
        int a = i;
        int count = 0;
        while (!flag && a >= 0)
        {
            if (soal[a][j]==pattern[count])
            {
                count++;
                a--;
                (*sum)++;
            }else{
                (*sum)++;
                flag = true;
            }
        }
        if(count==pattern.length()){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool searchDownRight(vector<string> soal, string pattern, int i,int j,int *sum){
    bool flag = false;
    if(soal.size()-i>=pattern.length()){
        int a = i;
        int b = j;
        int count = 0;
        while (!flag && a < soal.size() && b < soal[0].size())
        {
            if (soal[a][b]==pattern[count])
            {
                count++;
                a++;
                b++;
                (*sum)++;
            }else{
                (*sum)++;
                flag = true;
            }
        }
        if(count==pattern.length()){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool searchDownLeft(vector<string> soal, string pattern, int i,int j,int *sum){
    bool flag = false;
    if(soal.size()-i>=pattern.length()){
        int a = i;
        int b = j;
        int count = 0;
        while (!flag && a < soal.size() && b >= 0)
        {
            if (soal[a][b]==pattern[count])
            {
                count++;
                a++;
                b--;
                (*sum)++;
            }else{
                (*sum)++;
                flag = true;
            }
        }
        if(count==pattern.length()){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool searchUpLeft(vector<string> soal, string pattern, int i,int j,int *sum){
    bool flag = false;
    if(i+1>=pattern.length()){
        int a = i;
        int b = j;
        int count = 0;
        while (!flag && a >= 0 && b>=0)
        {
            if (soal[a][b]==pattern[count])
            {
                count++;
                a--;
                b--;
                (*sum)++;
            }else{
                (*sum)++;
                flag = true;
            }
        }
        if(count==pattern.length()){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool searchUpRight(vector<string> soal, string pattern, int i,int j,int *sum){
    bool flag = false;
    if(i+1>=pattern.length()){
        int a = i;
        int b = j;
        int count = 0;
        while (!flag && a >= 0 && b < soal[0].size())
        {
            if (soal[a][b]==pattern[count])
            {
                count++;
                a--;
                b++;
                (*sum)++;
            }else{
                (*sum)++;
                flag = true;
            }
        }
        if(count==pattern.length()){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool sameKoor(int x, int y, vector<vector<int>> listKoor){
    bool flag = false;
    int a = 0;
    while(!flag && a<listKoor.size()){
        if(x==listKoor[a][0] && y==listKoor[a][1]){
            flag = true;
        }else{
            a++;
        }
    }
    return flag;
}

void DisplayAnswer(vector<string> soal, vector<vector<int>> listKoor, string jawab,int count){
    cout << "\nPattern : " << jawab << endl; 
    for(int i=0; i<soal.size(); i++){
        for(int j=0; j<soal[0].size(); j++){
            if(sameKoor(i,j, listKoor)){
                cout << soal[i][j] << " ";
            }else{
                cout << "- ";
            }
        }
        cout << endl;
    }
    cout << "Jumlah perbandingan huruf: " << count << endl; 
}


int main(){
    string filename;
    string str;

    vector<string> soal;
    vector<string> pattern;

    vector<int> koor;
    vector<int> jmlPerbandingan;
    vector<vector<int>> answ;
    vector<vector<vector<int>>> answers;

    bool readPattern = false;

    cout << "Masukkan nama file input (file sudah diletakkan di folder test)" << endl;
    cout << "ex: puzzle.txt" << endl;
    cin >> filename;

    ifstream fileInput ("../test/"+filename);
    if(!fileInput.is_open()){
        cout << "Cannot open file\n";
        return 0;
    }else{
        while (getline(fileInput, str))
        {
            if(str.size()<=0){
                readPattern = true;
            }
            if(!readPattern){
                soal.push_back(str);
            }else{
                pattern.push_back(str);
            }
        }
        fileInput.close();
    }
    

    pattern.erase(pattern.begin());
    
    for (int i = 0; i < soal.size(); i++){
        string str = soal[i];
        soal[i] = removeSpace(str);
    }
    auto start = std::chrono::high_resolution_clock::now();
    bool sameWord = false;
    for (int i = 0; i < pattern.size(); i++){
        sameWord = false;
        string jawab = pattern[i];
        int Count = 0;
        while (!sameWord)
        {
            int a = 0;
            while(!sameWord && a<soal.size()){
                int b = 0;
                while (!sameWord && b<soal[0].size())
                {
                    if(soal[a][b]==jawab[0]){
                        if(searchRight(soal[a],jawab,b,&Count)){
                            int y = b;
                            for (int c = 0; c < jawab.length(); c++)
                            {
                                koor.clear();
                                koor.push_back(a);
                                koor.push_back(y);
                                answ.push_back(koor);
                                y++;
                            }
                            answers.push_back(answ);
                            answ.clear();
                            sameWord = true;
                        }else if(searchDown(soal,jawab,a,b,&Count)){
                            int x = a;
                            for (int c = 0; c < jawab.length(); c++)
                            {
                                koor.clear();
                                koor.push_back(x);
                                koor.push_back(b);
                                answ.push_back(koor);
                                x++;
                                
                            }
                            answers.push_back(answ);
                            answ.clear();
                            sameWord = true;
                        }
                        else if(searchLeft(soal[a],jawab,b,&Count)){
                            int y = b;
                            for (int c = 0; c <jawab.length(); c++)
                            {
                                koor.clear();
                                koor.push_back(a);
                                koor.push_back(y);
                                answ.push_back(koor);
                                y--;
                            }
                            answers.push_back(answ);
                            answ.clear();
                            sameWord = true;
                        }else if(searchUp(soal,jawab,a,b,&Count)){
                            int x = a;
                            for (int c = 0; c < jawab.length(); c++)
                            {
                                koor.clear();
                                koor.push_back(x);
                                koor.push_back(b);
                                answ.push_back(koor);
                                x--;  
                            }
                            answers.push_back(answ);
                            answ.clear();
                            sameWord = true;
                        }else if(searchDownRight(soal,jawab,a,b,&Count)){
                            int x = a;
                            int y = b;
                            for (int c = 0; c < jawab.length(); c++)
                            {
                                koor.clear();
                                koor.push_back(x);
                                koor.push_back(y);
                                answ.push_back(koor);
                                x++;
                                y++;  
                            }
                            answers.push_back(answ);
                            answ.clear();
                            sameWord = true;
                        }
                        else if(searchDownLeft(soal,jawab,a,b,&Count)){
                            int x = a;
                            int y = b;
                            for (int c = 0; c < jawab.length(); c++)
                            {
                                koor.clear();
                                koor.push_back(x);
                                koor.push_back(y);
                                answ.push_back(koor);
                                x++;
                                y--;  
                            }
                            answers.push_back(answ);
                            answ.clear();
                            sameWord = true;
                        }
                        else if(searchUpLeft(soal,jawab,a,b,&Count)){
                            int x = a;
                            int y = b;
                            for (int c = 0; c < jawab.length(); c++)
                            {
                                koor.clear();
                                koor.push_back(x);
                                koor.push_back(y);
                                answ.push_back(koor);
                                x--;
                                y--;  
                            }
                            answers.push_back(answ);
                            answ.clear();
                            sameWord = true;
                        }
                        else if(searchUpRight(soal,jawab,a,b,&Count)){
                            int x = a;
                            int y = b;
                            for (int c = 0; c < jawab.length(); c++)
                            {
                                koor.clear();
                                koor.push_back(x);
                                koor.push_back(y);
                                answ.push_back(koor);
                                x--;
                                y++;  
                            }
                            answers.push_back(answ);
                            answ.clear();
                            sameWord = true;
                        }
                        else{
                            b++;
                            Count++;
                        }
                    }else{
                        Count++;
                        b++;
                    }
                }
                a++;
            }
            
        }
        jmlPerbandingan.push_back(Count);
    }
    auto finish = std::chrono::high_resolution_clock::now();

    for(int i = 0; i <pattern.size(); i++){
        DisplayAnswer(soal,answers[i],pattern[i],jmlPerbandingan[i]);
    }

    
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Lama waktu mengeksekusi program (algoritma string matching) : " << elapsed.count()*1000 << " ms\n";

    
    return 0;
}        