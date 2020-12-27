#include <iostream>
#include <fstream>
#include "user.h"
#include <vector>

using namespace std;

User users[] = {};

int regInSys(string loginReg, string passReg){
    ofstream Reg;
    Reg.open("D:\\C++Text\\Text.txt", ios::app);
    if(Reg.is_open()){
        Reg << loginReg << endl;
        Reg << passReg << endl;
        Reg.close();
        return 1;
    }else{
        Reg.close();
        cout << "Error 1";
        return 0;
    }
}

int checkLogin(string login){
    string Buffer;
    ifstream checkerLog;
    checkerLog.open("D:\\C++Text\\Text.txt");
    if(checkerLog.is_open()){
        getline(checkerLog, Buffer);
        while(login != Buffer) {
            getline(checkerLog, Buffer);
            getline(checkerLog, Buffer);
            if (checkerLog.eof()) {
                checkerLog.close();
                return 3;
            }
        }
        return 2;
    }else{
        checkerLog.close();
        return 4;
    }
}

int checkLogAndPass(string pass, string login){
    string passBuffer;
    string loginBuffer;
    ifstream checker;
    checker.open("D:\\C++Text\\Text.txt");
    if(checker.is_open()){
        getline(checker, loginBuffer);
        while(login != loginBuffer){
            getline(checker, loginBuffer);
            getline(checker, loginBuffer);
            if(checker.eof()) {
                checker.close();
                return 2;
            }
        }
        getline(checker, passBuffer);
        checker.close();
        if(pass == passBuffer){
            return 1;
        }else{
            return 3;
        }
    }else{
        checker.close();
        return 4;
    }
}

int registration(int Suc){
    string passReg;
    string loginReg;
    while(Suc != 3){
        cout << "Login: ";
        cin >> loginReg;
        Suc = checkLogin(loginReg);
        if(Suc != 3){
            cout << "Incorrect Login" << endl;
        }
    }
    cout << "Password: ";
    cin >> passReg;
    return regInSys(loginReg, passReg);
}

int login(){
    string pass;
    string login;
    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> pass;
    return checkLogAndPass(pass, login);
}

int main(){
    char RegOrLog;
    cout << "   Hello!" << endl << "Login: L/l" << endl << "Registration: R/r" << endl << "Input: ";
    cin >> RegOrLog;
    if(RegOrLog == 'L' || RegOrLog == 'l'){
        int Auth;
        Auth = login();
        switch(Auth){
            case 1:
                cout << "Welcome!";
                break;
            case 2:
                cout << "Incorrect Login!";
                break;
            case 3:
                cout << "Incorrect Password!";
                break;
            case 4:
                cout << "File Error!";
                break;
            default:
                cout << "Critical Error!";
        }
    }else if(RegOrLog == 'R' || RegOrLog == 'r'){
        int Suc = 0;
        int RegSuc;
        RegSuc = registration(Suc);
        if(RegSuc == 1){
            cout << "Registration Success!" << endl;
            main();
        }else{
            cout << "Critical Error" << endl;
        }
    }
}
