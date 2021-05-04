#include <iostream>
#include<string>
#include<fstream>
using namespace std;
class Password {
private:
    string pw = "123456", username="booksy_anu",cuser,cpw;
    int recovery = 2;
public:
    int login() {
        string passw, uname;
        int tries = 0,x;
        do {
            cout << "Enter username: ";
            cin >> uname;
            cout << "\nEnter password: ";
            cin >> passw;
            if (passw == pw && uname == username) {
                x = 1;
                break;
            }
            else if(passw != pw || uname != username) {
                cout << "password or username wrong" << endl;
                tries++;
                x = 0;
            }
        } while (tries != 3);
        if (x == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int recover() {
        int year=0,x=0;
        cout << "You only get one chance. 1+1 is?" << endl;
        cin >> year;
        if (year == recovery) {
            x = 1;
        }
        if (x == 1) {
            return 1;
        }
        else {
            return 0;
        }

    }
    int createacc() {
        ofstream fout;
        cout << "Enter username: " << endl;
        cin >> cuser;
        cout << "Enter password: " << endl;
        cin >> cpw;
        fout.open("password.txt", ios::app | ios::binary);
        fout << cuser << "\t" << cpw;
        fout.close();
    }
};
int main()
{
    Password p;
    int flag=0,x;
    cout << "Enter choice.\n1.Login\n2.Forgot password or username\n";
    cin >> x;
    do {
        switch (x) {
        case 1:
            flag = p.login();
            if (flag == 1) {
                cout << "function" << endl;
                break;
            }
            else {
                cout << "wrong!!!! try again" << endl;
                exit(0);
            }
            break;
        case 2: flag = p.recover();
            if (flag == 1) {
                cout << "Your password and username are respectively 123456 and booksy_anu" << endl;
            }
            else {
                cout << "wrong again. create a new account." << endl;
                exit(0);
            }
            break;
        }
    } while (x != 3);
}


