#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <cstdio>
#include <time.h>
#include <string.h>
#include <iomanip>

using namespace std;

// Global Variable
float amount = 0; //To calculate the total amount
int size = 0; // Total Items Added to Order
const float serviceChargeRate = 0.20; // 20% service charge
const float TAX_RATE = 0.08;


// Structure to store the ordered items & generate bill
struct Items{
    int id;
    char item[1000];
    int qty;
    float price;
    float amt;
}I[1000];

// Function Prototyping
void drawLine(); // 1. Function to Drawlines for presentation
void Header(); // 2. Display Heading in Invoice
void menu(); // 3. Display Menu of Items
void Bill(); // 4. Displaying Invoice
bool LogginIn(); // 5. User Login

// Login Boolean For Employee
bool LogginIn(string &first_name, string &last_name){
    string username, password, user, pass;
    cout << "Enter Username: "; cin >> username;
    cout << "Enter Password: "; cin >> password;

    ifstream read(username + ".txt"); //store every user's name
    getline(read, user); // username
    getline(read, pass); // password
    getline(read, first_name); //first name
    getline(read, last_name); // last name


    if(user == username && pass == password){
        return true;
    }
    else{
        return false;
    }
}



// 1. Drawline function
void drawLine(){
    for(int line = 1; line < 70; line++ ){
        cout << "=" ;
    }

    cout << endl;
}

void drawLine1(){
    for(int line = 1; line < 70; line++ ){
        cout << "-" ;
    }

    cout << endl;
}


// 2. Display Header Function
void Header(){
    cout << setw(10) << "I.D."
         << setw(20) << "Item Name"
         << setw(10) << "Qty."
         << setw(10) << "Price"
         << setw(10) << "Amount" << endl;
}

// 3. Display Menu Function
void menu() {

    cout <<"\n";
    drawLine();
   // animateCafeName();
    cout <<"\t\t\t--Yamin's Cafe--"<< endl;
    drawLine();
    cout <<"\t\t\t [Beverages] " << endl;
    drawLine();
    cout << "Menu\t\t\tPrice\n";
    drawLine1();
    cout << "0. Exit \n";
    cout << "1. Drip Coffee\t\t$3.00\n";
    cout << "2. Tea    \t\t$2.00\n";
    cout << "3. Hot Chocolate\t$2.00\n";
    cout << "4. Chai    \t\t$4.00\n";
    cout << "5. Expresso Shot\t$0.50\n";
    drawLine();
    cout << "\t\t\t[Sandwiches]\n";
    drawLine();
    cout << "Menu\t\t\t\tPrice\n";
    drawLine1();
    cout << "6. Egg & Potato Burrito\t\t$10.00\n";
    cout << "7. English Muffin Sandwich\t$8.00\n";
    cout << "8. Everything Bagel Sandwich\t$8.50\n";
    drawLine();
    cout << "Enter your choice: ";

}

// 4. Function to Display Bill
void Bill(){
    system("cls");
    cout<<("\n");
    drawLine();
    cout << "\t\t\t\tITEMIZED INVOICE\n";
    drawLine();
    Header();
    drawLine();
    for(int i=0; i<size; i++){
        cout << setw(10)<< I[i].id
             << setw(20)<< I[i].item
             << setw(10)<< I[i].qty
             << setw(10)<< I[i].price
             << setw(10)<< I[i].amt << endl;
    }

    float subtotal = amount;
    float serviceCharge = subtotal * serviceChargeRate;
    float tax = subtotal * TAX_RATE;
    float totalAmount = subtotal + serviceCharge + tax;

    cout << endl;
    drawLine1();
    cout << "\nSubtotal: $" << fixed << setprecision(2)<< subtotal << endl;
    cout << "Service Charge (20%): $" << fixed << setprecision(2)<< serviceCharge << endl;
    cout << "Tax (8%): $" << fixed << setprecision(2)<< tax << endl;
    cout << "\nTotal Amount: $" << fixed << setprecision(2)<< totalAmount << endl;
    drawLine();
    exit(0);
}


// Main function
int main(){

    time_t rawtime;
    struct tm* timeinfo;
    char buffer [80];
    string first_name, last_name;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int log_employee; // user log in

    drawLine1();
    cout << "====================Welcome Yamin's Cafe!====================\n";
    cout << "Please Log in as following for employee!\n";
    drawLine1();
    cout << "Select a choice!\n1: Register\n2: Login\n Your choice: ";
    cin >> log_employee;
    if(log_employee == 1){
        string username, password, first_name, last_name;

        cout << "Select a username: "; cin >> username;
        cout << "Select a password: "; cin >> password;
        cout << "First name: "; cin >> first_name;
        cout << "Last name: "; cin >> last_name;

        ofstream file; // creating the new text file
        file.open(username + ".txt"); // store the username to project folder
        file << username << endl << password <<endl << first_name << endl << last_name;
        file.close();

        main();

    }
    else if( log_employee == 2){
        bool status = LogginIn( first_name, last_name); // if we haven't successfully log in yet
        if (!status){
            cout << "Incorrect Information. Try Again!"<< endl;
            system("PAUSE");
            return 0;
        }
        else{
            strftime(buffer, 80, "Employee's Log in Time: %Y-%m-%d %I:%M:%S %p", timeinfo);
            cout << "Login Successful!\n" << endl;
            puts(buffer);
        }
        cout << "Employee: " << last_name << "," << first_name<<endl;
        strftime(buffer, 80, "Employee's Log in Time: %I:%M%p", timeinfo);
        cout << "Login Successful!\n" << endl;
    }


    int ch_num; // number of choice
    int i =0;
    char choice = 'n' ;
    start:
    do{
        system("cls");
        menu(); //Display menu function
        cin >> ch_num;
        switch(ch_num)
        {
            case 0: break; // 0 - Exit
                /*--------------------------*/
            case 1: // 1. Coffee
                cout << "How many Coffees?";
                cin  >> I[i].qty; // user enter the quantity
                I[i].id = i + 1;
                strcpy(I[i].item, "Coffee");
                I[i].price = 3; // Price of Coffee
                I[i].amt = I[i].qty * I[i].price;
                amount += I[i].amt;
                i++;
                size++;
                break;
                /*--------------------------*/
            case 2: // 2. Tea
                cout << "How many Tea?";
                cin  >> I[i].qty; // user enter the quantity
                I[i].id = i + 1;
                strcpy(I[i].item, "Tea");
                I[i].price = 2; // Price of Tea
                I[i].amt = I[i].qty * I[i].price;
                amount += I[i].amt;
                i++;
                size++;
                break;
                /*--------------------------*/
            case 3: // 3. Hot Chocolate
                cout << "How many Hot Chocolate?";
                cin  >> I[i].qty; // user enter the quantity
                I[i].id = i + 1;
                strcpy(I[i].item, "Hot Chocolate");
                I[i].price = 2; // Price of Hot Chocolate
                I[i].amt = I[i].qty * I[i].price;
                amount += I[i].amt;
                i++;
                size++;
                break;

            case 4: // 4. Chai
                cout << "How many Chai?";
                cin  >> I[i].qty; // user enter the quantity
                I[i].id = i + 1;
                strcpy(I[i].item, "Chai");
                I[i].price = 2; // Price of Chai
                I[i].amt = I[i].qty * I[i].price;
                amount += I[i].amt;
                i++;
                size++;
                break;

            case 5: // Expresso Shot
                cout << "How many Expresso Shot ?";
                cin  >> I[i].qty; // user enter the quantity
                I[i].id = i + 1;
                strcpy(I[i].item, "Expresso Shot");
                I[i].price = 0.50; // Price of Expresso Shot
                I[i].amt = I[i].qty * I[i].price;
                amount += I[i].amt;
                i++;
                size++;
                break;

            case 6: // 6. Egg & Potato Burrito
                cout << "How many Egg & Potato Burrito?";
                cin  >> I[i].qty; // user enter the quantity
                I[i].id = i + 1;
                strcpy(I[i].item, "Egg & Potato Burr");
                I[i].price = 10; // Price of Egg & Potato Burrito
                I[i].amt = I[i].qty * I[i].price;
                amount += I[i].amt;
                i++;
                size++;
                break;

            case 7: // 7. English Muffin Sandwich
                cout << "How many English Muffin Sandwich?";
                cin  >> I[i].qty; // user enter the quantity
                I[i].id = i + 1;
                strcpy(I[i].item, "Engl Muffin San");
                I[i].price = 8; // Price of English Muffin Sandwich
                I[i].amt = I[i].qty * I[i].price;
                amount += I[i].amt;
                i++;
                size++;
                break;

            case 8: // 8. Everything Bagel Sandwich
                cout << "How many Everything Bagel Sandwich?";
                cin  >> I[i].qty; // user enter the quantity
                I[i].id = i + 1;
                strcpy(I[i].item, "Every Bagel San");
                I[i].price = 8.50; // Price of Everything Bagel Sandwich
                I[i].amt = I[i].qty * I[i].price;
                amount += I[i].amt;
                i++;
                size++;
                break;
        }

        cout<<"\n Is that be all for you?(Y/N): ";
        cin >> choice;

        if(choice == 'N' || choice == 'n')
            goto start;
        else if(choice != 'N' || choice != 'n')
            ch_num = 0;
    } while(ch_num!=0);

    if((choice == 'Y' || choice == 'y') && amount > 0)
        Bill();
    else
        cout<< "\n You haven't ordered yet ...\n";
    system("pause");
}