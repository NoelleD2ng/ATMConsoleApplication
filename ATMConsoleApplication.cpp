

#include <iostream>
using namespace std;

// Global Variables
double balance = 500;
bool UserSuccessLogin = false;


//functions
void deposit() {
    double depositAmount;
    cout << "How much money would you like to deposit from your balance? ";
    cin >> depositAmount;
    
    if (depositAmount <= balance) {
        int selection;
        cout << "Okay, you are depositing this amount of money:" << depositAmount << ". Is that correct? (enter 1 if yes, enter 2 if no): ";
        cin >> selection;
            if (selection == 1) {
                balance = balance - depositAmount;
                cout << "Okay I have deposited: " << depositAmount << endl;
                cout << "Your current balance is now:" << balance;
            }
            else if (selection == 2) {
                system("clr");
                deposit();
            }
            else {
                system("cls");
                cout << "Please try again, that is not an option. Now you have to start over hahaha.";
                deposit();         
            }
    }
    else if (depositAmount > balance){
        cout << "Please enter in a valid deposit amount. You do not have that much money to deposit." << endl;
        deposit();
    }
    else {
        cout << "Please enter in a valid deposit amount." << endl;
        deposit();
    }
 
}

void withdraw() {

}



void showMenu() {
    int selection;
    cout << "************* Welcome to Noelle's ATM **************" << endl;
    cout << "Your available Balance is:" << balance << endl;
    cout << "Please input a number for the action you would like to do. " << endl;
    cout << "1. Withdraw money" << endl;
    cout << "2. Deposit money" << endl;
    cout << "Enter your selection here: ";
    cin >> selection;

    //call the specific function for which action the user wants to perform
    if (selection == 1) {
        cout << "You have selected the withdraw money option." << endl;
        withdraw();
    }
    else if (selection == 2) {
        cout << "you have selected the deposit money option." << endl;
        deposit();
    }
    else {
        cout << "That is not a valid option, please try again" << endl;
        system("cls");
        showMenu();
    }
    
}


void userVerification() {
    int userPin = 1234, pin, countError = 0;
    do {
        cout << "Enter your userPin to Login: ";
        cin >> pin;
        if (pin != userPin) {
            countError++;
        }
    } while (userPin != pin && countError < 4);

    if (countError < 4) {
 
        UserSuccessLogin = true;
        system("cls");
        cout << "Succesfully entered UserPin. Now loading Menu. . ." << endl;
        showMenu();
  
      
    }
    else {
        cout << "You have failed 4 attempts. Please try to remember your pin in order to proceed." << endl;
    }

    system("pause > 0");
}

//main
int main()
{
    /************* ATM Program **********
    * make a program where when you intially enter into the application, you are asked for a verification of a pin
    * after you enter the correct pin, you are shown a menu where it gives you information about your balance in your account
    * After being shown the menu, you are then going to input if you want to draw money or deposit
    * - make a function that draws money out of your balance
    * - make a function that deposits money out of your balance
    * after those actions are completed, make sure you show the balance at the end again
    * 
    * and finally, ask if you want to log out and then start the whole application back over again
    
    */
    
    // start the application by asking for a userPin to login
    while (UserSuccessLogin == false) {
        userVerification();
    }
    //after User is logged in show menu


}
