#include <iostream>
#include<conio.h>
#include<string>

using namespace std;

class atm 
{
private:
    int userID;
    string name;
    double balance;
    int pin;
    string phone;

public:
    void SetData(int muserID, string mname, double mbalance, int mpin, string mphone) {
        userID = muserID;
        balance = mbalance;
        name = mname;
        pin = mpin;
        phone = mphone;
    }
    long int getuserID() {
        return userID;
    }
    string getname() {
        return name;
    }
    double getbalance() {
        return balance;
    }
    int getpin() {
        return pin;
    }
    string getphone() {
        return phone;
    }

    //functii pentru optiuni
    void cashout(int amount) {
        if (amount > 0 && amount < balance) {
            balance = balance - amount;
            cout << endl << "Please collect your cash";
            cout << endl << "The available balance is: " << balance <<" RON.";
            _getch();
        }
        else {
            cout << endl << "Invalid input or insufficient balance";
            _getch();
        }

    }

    void setphone(string oldno, string newno) {
        if (oldno == phone) {
            phone = newno;
            cout << endl << "Your phone number was successfully updated!";
            _getch();
        }
        else {
            cout << endl << "Incorrect phone number!";
            _getch();
        }
    }
};

int main() {
    int choice, enterPIN;
    long int enterID;
    system("cls");
    atm user;
    //void SetData(int muserID, string mname, double mbalance, int mpin, string mphone)
    user.SetData(2002, "Dragos", 9000.00, 1234, "0724342192");

    cout << endl << "The user details are:";
    cout << endl << user.getuserID();
    cout << endl << user.getname();
    cout << endl << user.getphone();
    cout << endl << user.getbalance();


    do {
        system("cls");
        cout << endl << "***Welcome to the ATM ***";
        cout << endl << "Enter your ID";
        cout << endl;
        cin >> enterID;
        cout << endl << "Enter your PIN";
        cout << endl;
        cin >> enterPIN;

        if ((enterID == user.getuserID()) && (enterPIN == user.getpin())) {
            do {
                int amount = 0;
                string oldphone, newphone;
                system("cls");
                //cout << endl << "***Welcome to the ATM ***";
                cout << endl << "Please select your option:";
                cout << endl << "1. Check your balance.";
                cout << endl << "2. Cash Withdraw.";
                cout << endl << "3. See your details.";
                cout << endl << "4. Change your phone number.";
                cout << endl << "5. Exit";
                cout << endl;
                cin >> choice;

                switch (choice) {
                case 1:
                    cout << endl << "Your bank balance is: " << user.getbalance()<<" RON.";
                    _getch();
                    break;
                case 2:
                    cout << endl << "Please enter the amount you wish to withdraw:";
                    cout << endl;
                    cin >> amount;
                    user.cashout(amount);
                    break;
                case 3:
                    cout << endl << "The user details are:";
                    cout << endl << "ID: " << user.getuserID();
                    cout << endl << "Name: " << user.getname();
                    cout << endl << "Phone number: " << user.getphone();
                    cout << endl << "Balance: " << user.getbalance();
                    _getch();
                    break;
                case 4:
                    cout << endl << "Please enter your old phone number:";
                    cout << endl;
                    cin >> oldphone;
                    cout << endl << "Please enter your new phone number:";
                    cout << endl;
                    cin >> newphone;
                    user.setphone(oldphone, newphone);
                    break;
                case 5:
                    exit(0);
                default:
                    cout << endl << "Please enter valid data.";

                }
            } while (1);
        }
        else {
            cout << endl << "Invalid details.";
            _getch();
        }
    } while (1);

    return 0;
}
