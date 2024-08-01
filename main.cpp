#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include<windows.h>
#include <limits>
#include <vector>
#include <sstream>
using namespace std;
template <class T>
bool InputCheck(T &A){
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"                           Invalid Input Try Again ";
            cin >> A;
        }
        return true;
}
void gotoRowCol(int rpos, int cpos);
class Registration {
public:
    string Account_name;
    string name;
    string father_name;
    int age;
    unsigned long long CNIC;
    string email;
    string gender;
    string country;
    string province;
    string district;
    string tehsil;
    unsigned long long phone_num;
    string password;
    string confirm_password;
    double cash;
    string currency;
    double cash_pkr;
public:
    Registration() : cash_pkr(0) {}
    Registration( Registration &reg )
    {
        Account_name = reg.Account_name;
        name = reg.name;
        father_name = reg.father_name;
        age = reg.age;
        CNIC = reg.CNIC;
        email = reg.email;
        gender = reg.gender;
        country = reg.country;
        province = reg.province;
        district = reg.district;
        tehsil = reg.tehsil;
        phone_num = reg.phone_num;
        password = reg.password;
        confirm_password = reg.confirm_password;
        cash = reg.cash;
        currency = reg.currency;
        cash_pkr = reg.cash_pkr;
    }
    bool validaccount(string &A)
    {
        if (A== "EASYPAISA" || A == "JAZZCASH" || A== "NAYAPAY" || A== "SADAPAY" || A== "HBL" || A == "UBL"
            || A=="easypaisa" || A=="Easypaisa" || A=="Jazzcash" || A=="jazzcash" || A=="Nayapay" || A=="Sadapay" ||
            A=="nayapay" || A=="sadapay" || A=="hbl" || A=="ubl" || A=="Hbl" || A=="Ubl")
            return true;
        else
            return false;
    }
    bool validpassword() {
        return (password == confirm_password);
    }

    bool validcnic() {
        return (CNIC >= 1000000000000 && CNIC <= 9999999999999);
    }
    bool validage() {
        return (age >= 18);
    }
    bool Register() {
        gotoRowCol(13,61);
        cout << "Create Account"<<endl;
        gotoRowCol(14,61);
        cout<<"EasyPaisa  Jazzcash NayaPay SadaPay HBL UBL:";
        cin >> Account_name;
        while(validaccount(Account_name)==false)
            {
                gotoRowCol(13,61);
                cout << "Account Name not Valid Try Again: ";
                gotoRowCol(14,61);
                cout << "Choices: ";
                gotoRowCol(15,61);
                cout<< "EasyPaisa  Jazzcash  NayaPay SadaPay HBL UBL:";
                cin >> Account_name;
            }

        system("cls");
        cout<<"\n                           Create Your " << Account_name <<" Account"<<endl;
        cout<<"                           ----------------------------\n\n";
        cout << "                           Name : ";
        cin >> name;
        cout << "                           Father Name : ";
        cin>>father_name;
        ifstream regis("info.txt");
        string s;
        while(regis>>s)
        {
            if(s==name)
            {
                cout<<"                           Sorry!!! You can't Create Account You have Already Account "<<endl;
                return false;
            }
        }
        ofstream reg("info.txt");
        reg<<"Account_Name : "<<Account_name<<endl;
        reg<<"Name : "<<name<<endl;
        reg<<"Father_Name : "<<father_name<<endl;
        cout << "                           Age : ";
        cin >> age;
        InputCheck(age);
        while(validage()==false)
            {
                cout << "                           Sorry! Your Age is Less Than 18 So You can't Create Account! Try Again " << endl;
                cout << "                           Age : ";
                cin >> age;
            }
        reg<<"Age : "<<age<<endl;
        cout << "                           CNIC : ";
        cin >> CNIC;
        InputCheck(CNIC);
        while(validcnic()==false)
            {
                cout << "                              Sorry! Your CNIC is not Valid Please Enter 13 digits! Try Again: " << endl;
                cout << "                           CNIC : ";
                cin >> CNIC;
            }
        reg<<"CNIC : "<<CNIC<<endl;
        cout << "                           Email : ";
        cin >> email;
        reg<<"Email : "<<email<<endl;
        cout << "                           Gender : ( Male , Female , Transgender ) ";
        cin >> gender;
        reg<<"Gender : "<<gender<<endl;
        cout << "                           Country : ";
        cin >> country;
        reg<<"Country : "<<country<<endl;
        cout << "                           Province : ";
        cin >> province;
        reg<<"Province : "<<province<<endl;
        cout << "                           District : ";
        cin >> district;
        reg<<"District : "<<district<<endl;
        cout << "                           Tehsil : ";
        cin >> tehsil;
        reg<<"Tehsil : "<<tehsil<<endl;
        cout << "                           Phone Number : ";
        cin >> phone_num;
        InputCheck(phone_num);
        reg <<"Phone_No : "<<phone_num<<endl;
        cout << "                           Password : ";
        cin >> password;
        cout << "                           Confirm_Password : ";
        cin >> confirm_password;
        while(validpassword()==false)
            {
                cout << "                            Sorry your password and Confirm Password is not matching! Try Again " << endl;
                cout << "                           Password : ";
                cin >> password;
                cout << "                           Confirm Password : ";
                cin >> confirm_password;
            }
            reg << "Password : "<<password <<endl;
            reg << "Confirm_Password : " <<confirm_password<<endl;
        system("cls");
        cout <<endl<<endl<<endl<< "                       Congratulations!!!!!!!!\n";
        cout<<"                       Your " << Account_name << " Account has Been Created : " << endl;
        cout<<"                       ----------------------------------------\n\n\n";
        return true;
    }
};
class Login : public Registration {
    unsigned long long ph_number;
    string user_name;
    string password2;
public:
    Login(Registration& R) : Registration(R)
    {
    }
    bool loginAccount() {
        ifstream log("info.txt");
        string select_name;
        string select_password;
        gotoRowCol(12,61);
        cout << "Enter Name : ";
        gotoRowCol(13,61);
        cin >> user_name;
        gotoRowCol(14,61);
        cout << "Enter Password ";
        gotoRowCol(15,61);
        cin >> password2;
        int n=0;
        while(log >> select_name )
        {
            if(user_name == select_name)
            {
                n++;
            }
        }
        log.clear();
        log.seekg(0, ios::beg);
        while(log>>select_password)
        {
            if(password2 == select_password && n==1)
            {
                name=user_name;
                password=password2;
                system("cls");
                cout<<endl<<"\n                            Login Successful Dear :"<<name<<endl;
                cout<<"                            ------------------------------\n\n"<<endl;
                cout<<"                       Dear "<<name<<" You can Check your info : "<<endl;
                return true;
            }
        }
        gotoRowCol(16,61);
        cout << "Sorry! your Account Not Exist Try Again!\n";
        return false;
    }
    void details()
    {
        system("cls");
        cout<<"\n                       User Information \n"<<endl;
        ifstream detail("info.txt");
        detail.seekg(0, ios::beg);
        vector<string> V;
        string s;
        while(getline(detail,s))
        {
            V.push_back(s);
        }
        for(int i=0;i<V.size();i++)
        {
            cout<<"                       "<<V[i]<<endl;
        }
        cout<<"                     -------------------------------------------------\n";
    }
};
class AddCash : public Registration {
public:
    AddCash() {}
    AddCash(Registration &R ) :  Registration( R )
    {
    }
    bool Addamount( )
    {
        ofstream add("info.txt" , ios:: app);

        ifstream addm("info.txt");
        string s1,s2,s3;
        int amount;
        int cashmoney=0;
        while(addm>>s1>>s2>>s3)
        {
            if(s1=="Money" )
            {
                cashmoney=atoi(s3.c_str());
            }
        }
        addm.clear();
        addm.seekg(0,ios::beg);
        while(addm>>s1>>s2>>s3)
        {
            if(s1=="Currency" && (s3=="Euro" || s3=="euro") )
            {
                break;
            }
            else if(s1=="Currency" && (s3=="taka") || (s3=="Taka"))
            {
                break;
            }
            else if(s1=="Currency" && (s3=="Dollars") || (s3=="dollars"))
            {
                break;
            }
            else if(s1=="Currency" && (s3=="Yaun") || (s3=="yaun"))
            {
                break;
            }
            else if(s1=="Currency" && (s3=="Riyal") || (s3=="riyal"))
            {
                break;
            }
        }
        cout<<"\n                       Dear "  << name <<" AddCash : \n";
        cout<<"                       -----------------------------\n\n"<<endl;
        cout<<"                       Currencies:\n";
        cout<<"                       Dollar , Taka , Euro , Yaun , Riyal : \n" << endl;
        cout<<"                       ------------------------\n";
        cout<<"                       Currency         PKR"<<endl;
        cout<<"                        1.Dollar         285"<<endl;
        cout<<"                        1.Taka           2.65"<<endl;
        cout<<"                        1.Yaun           40.20"<<endl;
        cout<<"                        1.Riyal          76.10"<<endl;
        cout<<"                        1.Euro           312.20"<<endl;
        cout<<"                       ------------------------\n";
        if((s3!="Dollars"&&s3!="dollars"&&s3!="Dollar"&&s3!="dollar") && (s3!="taka"&&s3!="Taka") && (s3!="Yaun"&&s3!="yaun") && (s3!="euro"&&s3!="Euro") && (s3!="Riyal"||s3!="riyal"))
        {
            up:
            cout<<"\n                       Dear "<<name<<" Enter Your Wallet Curreny Type ";
            cin>>s3;
            if((s3!="Dollars"&&s3!="dollars"&&s3!="Dollar"&&s3!="dollar") && (s3!="taka"&&s3!="Taka") && (s3!="Yaun"&&s3!="yaun") && (s3!="euro"&&s3!="Euro") && (s3!="Riyal"||s3!="riyal"))
                {
                    cout<<"                        Invalid Input try Again "<<endl;
                    goto up;     }
        }
        while(true){
            cout <<endl<<"                       Currency Type(Name) :";
            cin >> currency;
            add<<endl<<"Currency : "<<currency<<endl;
            cout << "                       How Many " << currency << ":";
            cin >> cash;
            InputCheck(cash);
            if ((currency == "dollars" || currency == "Dollars" || currency=="dollar" || currency=="Dollar") && (s3=="Dollars" || s3=="dollars" || s3=="dollar" || s3=="Dollar")) {
                cash_pkr=cash*285.50;
                cash=cash+cashmoney;
                break;
            } else if ((currency == "Yaun" || currency == "yaun") && (s3=="yaun" || s3=="Yaun")) {
                cash_pkr = cash*40.20;
                cash=cash+cashmoney;
                break;
            } else if ((currency == "taka" || currency == "Taka") && (s3=="taka" || s3=="Taka")) {
                cash_pkr = cash * 2.65;
                cash=cash+cashmoney;
                break;
            } else if ((currency == "Euro" || currency == "euro") && (s3=="Euro" || s3=="euro")) {
                cash_pkr = cash * 312.20;
                cash=cash+cashmoney;
                break;
            } else if ((currency == "Riyal" || currency == "riyal") && (s3=="Riyal" || s3=="riyal")) {
                cash_pkr = cash * 76.10;
                cash=cash+cashmoney;
                break;
            }
            else
            {
                cout << "                     Invalid Input Curreny Type Must be Same: "<<endl;
                cout << "                     Your Wallet Curreny Type: "<< s3 << endl;
                continue;
            }
        }
        add<<"Money : "<<amount<<endl;
        addm.clear();
        addm.seekg(0,ios::beg);
        int rdcash=0;
        while(addm>>s1>>s2>>s3)
        {
            if(s1=="PKR")
            {
                rdcash=atoi(s3.c_str());
            }
        }
        cash_pkr+=rdcash;
        add<<"PKR : "<<cash_pkr<<endl;
        cout << "                       Cash in PKR is : " << cash_pkr << endl;
        vector<string> V;
        addm.clear();
        addm.seekg(0,ios::beg);
        while(addm>>s1>>s2>>s3)
        {
            if(s1=="Currency")
            {
                stringstream ss1;
                ss1<<s1<<" "<<s2<<" "<<currency;
                V.push_back(ss1.str());
            }
            else if(s1=="Money")
            {
                stringstream ss2;
                ss2<<s1<<" "<<s2<<" "<<cash;
                V.push_back(ss2.str());
            }
            else if(s1=="PKR")
            {
               stringstream ss3;
               ss3<<s1<<" "<<s2<<" "<<cash_pkr;
               V.push_back(ss3.str());
            }
            else
            {
               V.push_back(s1 + " " + s2 + " " + s3);
            }
        }
        ofstream outfile("info.txt");
        for (int i=0;i<V.size();i++) {
            outfile << V[i] << endl;
        }
        outfile.close();
        return true;
    }
};
class BillsAndPackages : public Registration {
public:
    BillsAndPackages(){}
    BillsAndPackages(Registration & R) : Registration( R )
    {}
    void mobileLoad() {
        unsigned long long mobileNumber;
        double amount;
        string s1,s2,s3,g1,g2,g3;
        bool found = false;
        ifstream infile("info.txt");
        ofstream load("info.txt" , ios :: app);
        vector<string> lines;
        while (infile >> s1 >> s2 >> s3)
        {
            if (s1 == "PKR") {
                cash_pkr = atof(s3.c_str());
                cout << "\n                     Enter Mobile Number: ";
                cin >> mobileNumber;
                cout << "                      Enter Amount: ";
                cin >> amount;
                if (amount <= cash_pkr) {
                    cash_pkr -= amount;
                    cout << "                      Mobile load of " << amount << " PKR has been added to " << mobileNumber << endl;
                } else {
                    cout << "                      Insufficient balance!" << endl;
                    return;
                }
                stringstream ss;
                ss << s1 << " " << s2 << " " << cash_pkr;
                lines.push_back(ss.str());
                found = true;
                g1=s1;g2=s2;g3=s3;
                updateamountload(amount,lines);
                load<<endl<<"Mobileload : "<<amount;
                s1=g1;s2=g2;s3=g3;

            } else {
                lines.push_back(s1 + " " + s2 + " " + s3);
            }
        }
        infile.close();

        if (found==false) {
            cout << "\n\n                   Please Check your Balance!!!" << endl;
        }
        ofstream outfile("info.txt");
        for (int i=0;i<lines.size();i++) {
            outfile << lines[i] << endl;
        }
        outfile.close();
    }
    void updateamountload(double &amount , vector<string> &lines)
    {
        ifstream infile("info.txt");
        string s1,s2,s3;
            while(infile>>s1>>s2>>s3)
            {
                if(s1=="Mobileload")
                {
                    int ld=atoi(s3.c_str());
                    amount=amount+ld;
                }
            }
    }
    void mobilePackages()
    {
        string Network;
        int days;
        float MB=1000;
        float sms=500;
        unsigned long long Mblnum;
        float minutes=200;
        int n;
        float activate;
        system("cls");
        cout<<"\n                      Create Your Own Package \n";
        cout<<"                      ------------------------\n\n";
        cout<<"                      Enter Mobile Number:";
        cin>>Mblnum;
        InputCheck(Mblnum);
        cout<<"                      Package Days ";
        cin>>days;
        InputCheck(days);
        cout<<"                      Press:"<<endl;
        cout<<"                      1.Telenor"<<endl;
        cout<<"                      2.Zong"<<endl;
        cout<<"                      3.Jazz "<<endl;
        cout<<"                      4.Ufone";
        first:
        cin>>n;
        InputCheck(n);
        if(n==1)
        {
            string Ntwrk="Telenor";
            packageworker(days,Network,MB,sms,minutes,activate,Ntwrk,Mblnum);
        }
        else if(n==2)
        {
            string Ntwrk="Zong";
            packageworker(days,Network,MB,sms,minutes,activate,Ntwrk,Mblnum);
        }
        else if(n==3)
        {
            string Ntwrk="Jazz";
           packageworker(days,Network,MB,sms,minutes,activate,Ntwrk,Mblnum);
        }
        else if(n==4)
        {
            string Ntwrk="Ufone";
           packageworker(days,Network,MB,sms,minutes,activate,Ntwrk,Mblnum);
        }
        else
        {
            cout<<"\n                     Invalid Input "<<endl;
            goto first;
        }
    }
    void packageworker(int &days, string &Network , float &MB , float &sms , float minutes, float &activate , string N,unsigned long long Mblnum)
    {
        ifstream infile("info.txt");
        ofstream load("info.txt" , ios:: app);
        string s1,s2,s3,g1,g2,g3;
        bool found;
        vector<string> lines;
        int n1;
            Network=N;
          cout<<"\n                 Package     Days      MB/Min/SMS per day      Bundle Cost"<<endl;
          cout<<"                 ---------------------------------------------------------\n";
           cout<<"                 Internet    "<<days<<"                "<<MB<<"MB"<<"              "<<days*(MB/100)<<endl;
           cout<<"                 Call        "<<days<<"                "<<minutes<<"Min"<<"              "<<days*(minutes/10)<<endl;
           cout<<"                 SMS         "<<days<<"                "<<sms<<"sms"<<"              "<<days*(sms/100) <<endl;
           cout<<"                 ---------------------------------------------------------\n";
           cout<<"\n                             Press:"<<endl;
           cout<<"                              1.Internet "<<endl;
           cout<<"                              2.Call "<<endl;
           cout<<"                              3.SMS ";
           do
           {
               cin>>n1;
               InputCheck(n1);
               if(n1==1)
               {
                   cout<<"                      Enter MB's per Day ";
                   cin>>MB;
                   InputCheck(MB);
                   activate=days*(MB/100);   break;
               }
               else if(n1==2)
               {
                   cout<<"                      Enter Minutes per Day ";
                   cin>>minutes;
                   InputCheck(minutes);
                   activate=days*(minutes/10);   break;
               }
               else if(n1==3)
               {
                   cout<<"                      Enter SMS per Day ";
                   cin>>sms;
                   InputCheck(sms);
                   activate=days*(sms/100);      break;
               }
               else
               {
                   cout<<"                     Invalid Input try Again!!!"<<endl;
                   continue;
               }
           }while(true);
         while (infile >> s1 >> s2 >> s3)
        {
            if(s1=="PKR")
            {

                cash_pkr = atof(s3.c_str());
                if (activate <= cash_pkr)
                    {
                        while(activate <= cash_pkr)
                        {
                            cout<<"                      Do want to Activate PKG or Not in "<<activate<<" PKR "<<endl;
                            cout<<"                      Press:     1.Activate     2. Skip ";
                            cin>>n1;
                            InputCheck(n1);
                            if(n1==1)
                            {
                               cash_pkr -= activate;
                               cout <<endl<<endl;
                               cout<<"                      "<< Network <<" Package of " <<activate<<" PKR with "<<days<<" Days has been activated." << endl;
                               break;
                            }
                            else if(n1==2)
                            {
                                cout<<"\n\n                      No Activation "<<endl;
                                return;
                            }
                            else
                            {
                                continue;
                            }
                        }
                }
                else
                {
                    cout << "                     Insufficient balance!" << endl;
                    return;
                }
               stringstream ss;
                ss << s1 << " " << s2 << " " << cash_pkr;
                lines.push_back(ss.str());
                found = true;
             load<<endl<<"Package : "<<Network;
             load<<endl<<"MobileNumber : "<<Mblnum;
             load<<endl<<"Days : "<<days;
             load<<endl<<"Amount : "<<activate;
            }
           else {
                lines.push_back(s1 + " " + s2 + " " + s3);
            }
        }
    infile.close();
        ofstream outfile("info.txt");
        for (int i=0;i<lines.size();i++) {
            outfile << lines[i] << endl;
        }
        outfile.close();
    }
    void billPayment() {
        string billType;
        ifstream infile("info.txt");
        ofstream load("info.txt",ios::app);
        string s1,s2,s3,g1,g2,g3;
        bool found;
        double amount;
        vector<string> lines;
        while (infile >> s1 >> s2 >> s3)
        {
            if(s1=="PKR")
            {
                cash_pkr=atof(s3.c_str());
                cout<<"\n                         ELECTRICITY GAS WATER BILLS\n";
                cout<<"                         ---------------------------\n\n";
                cout << "                     Enter Bill Type (Electricity, Gas, Water): ";
                cin >> billType;
                cout << "                     Enter Amount: ";
                cin >> amount;
                if (amount <= cash_pkr) {
                    cash_pkr -= amount;
                    cout <<"                     "<< billType << " bill of " << amount << " PKR has been paid." << endl;
                } else {
                    cout << "                     Insufficient balance!" << endl;
                    return;
                }
               stringstream ss;
                ss << s1 << " " << s2 << " " << cash_pkr;
                lines.push_back(ss.str());
                found = true;
                g1=s1;g2=s2;g3=s3;
             updateamountbill(amount,lines);
             load<<endl<<"Bill : "<<amount;
             s1=g1;s2=g2;s3=g3;
            }
           else {
                lines.push_back(s1 + " " + s2 + " " + s3);
            }
        }
    infile.close();
            if (found==false) {
            cout << "\n\n                   Please Check your Balance!!!" << endl;
            }
        ofstream outfile("info.txt");
        for (int i=0;i<lines.size();i++) {
            outfile << lines[i] << endl;
        }
        outfile.close();
    }
    void updateamountbill(double &amount , vector< string> &lines)
    {
        ifstream infile("info.txt");
        string s1,s2,s3;
            while(infile>>s1>>s2>>s3)
            {
                if(s1=="Bill")
                {
                    int B=atoi(s3.c_str());
                    amount=amount+B;
                    stringstream ss3;
                    ss3<<s1<<" "<<s2<<" "<<amount;
                    lines.push_back(ss3.str());
                }
            }
    }
};
class MoneyTransfer : public Registration {
public:
    MoneyTransfer() {}
    MoneyTransfer(Registration &R):
     Registration(R){}
          string s1,s2,s3;
          vector<string> lines;

    void Transfermoney_SameWallet() {
        unsigned long long recipientPhone;
        double amount;

        cout<<"\n                         Transaction (Same Wallet)\n";
        cout<<"                         -------------------------\n\n";
        cout<<"                     Enter recipient's phone number: ";
        cin >> recipientPhone;
        cout << "                     Enter amount to transfer: ";
        cin >> amount;
        ifstream infile("info.txt");
        ofstream load("info.txt" , ios::app);

        while (infile >> s1 >> s2 >> s3)
        {
            if(s1=="PKR")
            {
                cash_pkr = atof(s3.c_str());
               // double charges = (5/cash_pkr)*amount;
                if (amount <= cash_pkr)
                    {    int n1;
                        while(amount <= cash_pkr)
                        {
                            cout<<"                     Do want to Transfer or Not  "<<amount<<" PKR "<<endl;
                            cout<<"                     Press:     1.Transfer     2. Skip ";
                            cin>>n1;
                            InputCheck(n1);
                            if(n1==1)
                            {
                               cash_pkr -= amount;
                               cout<<"\n                     Transaction Successful: " << endl;
                               break;
                            }
                            else if(n1==2)
                            {
                                cout<<"\n                      No Activation "<<endl;
                                return;
                            }
                            else
                            {
                                continue;
                            }
                        }
                }
                else
                {
                    cout << "                     Insufficient balance!" << endl;
                    return;
                }
               stringstream ss;
                ss << s1 << " " << s2 << " " << cash_pkr;
                lines.push_back(ss.str());
             load<<endl<<"Transaction : "<<"SameWallet";
             load<<endl<<"RepientPhone_Number : "<<recipientPhone;
             load<<endl<<"AMOUNT : "<<amount;
            }
           else {
                lines.push_back(s1 + " " + s2 + " " + s3);
            }
        }
    infile.close();
        ofstream outfile("info.txt");
        for (int i=0;i<lines.size();i++) {
            outfile << lines[i] << endl;
        }
        outfile.close();
    }

    void Transfermoney_DifferentWallet() {
        string recipientWallet;
        unsigned long long recipientPhone;
        double amount;
        cout<<"\n                         Transaction (Different Wallet)\n";
        cout<<"                         ------------------------------\n\n";
        cout << "                     Enter recipient's wallet type: ";
        cin >> recipientWallet;
        cout << "                     Enter recipient's phone number: ";
        cin >> recipientPhone;
        cout << "                     Enter amount to transfer: ";
        cin >> amount;
        ifstream infile("info.txt");
        ofstream load("info.txt" , ios::app);

        while (infile >> s1 >> s2 >> s3)
        {
            if(s1=="PKR")
            {
                cash_pkr = atof(s3.c_str());
                double charges = (2/cash_pkr) * amount;
                if (amount+charges <= cash_pkr)
                    {    int n1;
                        while(amount+charges <= cash_pkr)
                        {
                            cout<<"                     Do want to Transfer or Not  "<<amount<<" PKR with"<<charges<<"(2%) Charges"<<endl;
                            cout<<"                     Press:     1.Transfer     2. Skip ";
                            cin>>n1;
                            InputCheck(n1);
                            if(n1==1)
                            {
                               cash_pkr -= (amount+charges);
                               cout<<"\n                     Transaction Successful: " << endl;
                               break;
                            }
                            else if(n1==2)
                            {
                                cout<<"\n                      No Activation "<<endl;
                                return;
                            }
                            else
                            {
                               cout<<"                     Invalid Input Try Again: \n";
                                continue;
                            }
                        }
                }
                else
                {
                    cout << "                     Insufficient balance!" << endl;
                    return;
                }
               stringstream ss;
                ss << s1 << " " << s2 << " " << cash_pkr;
                lines.push_back(ss.str());
             load<<endl<<"Transaction : "<<"DifferentWallet";
             load<<endl<<"Wallet_Type : "<<recipientWallet;
             load<<endl<<"RepientPhone_Number : "<<recipientPhone;
             load<<endl<<"AMOUNT : "<<amount;
            }
           else {
                lines.push_back(s1 + " " + s2 + " " + s3);
            }
        }
    infile.close();
        ofstream outfile("info.txt");
        for (int i=0;i<lines.size();i++) {
            outfile << lines[i] << endl;
        }
        outfile.close();
    }
    void moneyTransferToCNIC() {
        unsigned long long recipientCNIC;
        double amount;
        cout<<"\n                         Transaction ( Using CNIC )\n";
        cout<<"                         ------------------------------\n\n";
        cout << "                     Enter recipient's CNIC number: ";
        cin >> recipientCNIC;
        cout << "                     Enter amount to transfer: ";
        cin >> amount;
        ifstream infile("info.txt");
        ofstream load("info.txt" , ios::app);

        while (infile >> s1 >> s2 >> s3)
        {
            if(s1=="PKR")
            {

                cash_pkr = atof(s3.c_str());
                double charges = (5/cash_pkr)*amount;
                if (amount+charges <= cash_pkr)
                    {    int n1;
                        while(amount+charges <= cash_pkr)
                        {
                            cout<<"                     Do want to Transfer or Not  "<<amount<<" PKR with"<<charges<<" (5%) Charges"<<endl;
                            cout<<"                     Press:     1.Transfer     2. Skip ";
                            cin>>n1;
                            InputCheck(n1);
                            if(n1==1)
                            {
                               cash_pkr -= (amount+charges);
                               cout<<"\n                     Transaction Successful: " << endl;
                               break;
                            }
                            else if(n1==2)
                            {
                                cout<<"\n                      No Activation "<<endl;
                                return;
                            }
                            else
                            {
                               cout<<"                     Invalid Input Try Again: \n";
                                continue;
                            }
                        }
                }
                else
                {
                    cout << "                     Insufficient balance!" << endl;
                    return;
                }
               stringstream ss;
                ss << s1 << " " << s2 << " " << cash_pkr;
                lines.push_back(ss.str());
             load<<endl<<"Transaction : "<<"ViaCNIC";
             load<<endl<<"RepientPhone_Number : "<<recipientCNIC;
             load<<endl<<"AMOUNT : "<<(amount+charges);
            }
           else {
                lines.push_back(s1 + " " + s2 + " " + s3);
            }
        }
    infile.close();
        ofstream outfile("info.txt");
        for (int i=0;i<lines.size();i++) {
            outfile << lines[i] << endl;
        }
        outfile.close();

    }
};
void gotoRowCol(int rpos, int cpos){
int xpos=cpos, ypos = rpos;
COORD scrn;
HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
scrn.X = cpos;
scrn.Y = rpos;
SetConsoleCursorPosition(hOuput, scrn);
}
void sleep(int m){
        for(int j=0;j<m*21000;j++)
        {}
}
void drawshap(){
    char ch=219;
    for(int j=0;j<40;j++)
    {   gotoRowCol(j,60);
              cout<<ch;   }
    for(int i=60;i<110;i++)
    {        gotoRowCol(40,i);
        cout<<ch;
    }
    for(int j=40;j>=0;j--)
    {       gotoRowCol(j,110);
              cout<<ch;
    }
    for(int i=110;i>=60;i--)
    {   gotoRowCol(0,i);
        cout<<ch;
    }
    for(int i=60;i<110;i++)
    {   gotoRowCol(5,i);
        cout<<ch;
    }
}
void NextMenu(BillsAndPackages &B , AddCash &A, MoneyTransfer &M , Login &L){
    int serviceChoice;
                    do
                        {
                            cout <<"\n\n                    Select Service: " << endl;
                            cout << "                   _________\n\n";
                            cout << "                   1. Mobile Load" << endl;
                            cout << "                   2. Mobile Packages" << endl;
                            cout << "                   3. AddCash " <<endl;
                            cout << "                   4. Bill Payment" << endl;
                            cout << "                   5. Transaction (Same Wallet)"<<endl;
                            cout << "                   6. Transaction (Diff Wallet)"<<endl;
                            cout << "                   7. Transaction via CNIC"<<endl;
                            cout << "                   8. Information Account "<<endl;
                            cout << "                   9. Exit" << endl;
                            cout << "                   Enter your choice: ";
                            cin >> serviceChoice;
                            InputCheck(serviceChoice);
                            switch (serviceChoice)
                            {
                                case 1:
                                    {
                                        system("cls");
                                        B=A;
                                        B.mobileLoad();
                                        break;
                                    }
                                case 2:
                                    {
                                        B=A;
                                        B.mobilePackages();
                                        break;
                                    }
                                case 3:
                                    {
                                        system("cls");
                                        A=L;
                                        A.Addamount();
                                        break;
                                    }
                                case 4:
                                    {
                                        system("cls");
                                        B=A;
                                        B.billPayment();
                                        break;
                                    }
                                case 5:
                                    {
                                        system("cls");
                                        M=A;
                                        M.Transfermoney_SameWallet();
                                        break;
                                    }
                                case 6:
                                    {
                                        system("cls");
                                        M=A;
                                        M.Transfermoney_DifferentWallet();
                                        break;
                                    }
                                case 7:
                                    {
                                        system("cls");
                                        M=A;
                                        M.moneyTransferToCNIC();
                                        break;
                                    }
                                case 8:
                                    {
                                        system("cls");
                                        L.details();
                                    }
                                case 9:
                                    {
                                        B=A;
                                        cout << "                   Exiting..." << endl;
                                        break;
                                    }
                                default:
                                    cout << "                   Invalid choice! Try again." << endl;
                            }
                        } while (serviceChoice != 9);
};
bool Menuselector(AddCash &A, BillsAndPackages &B , Login &L , MoneyTransfer &M , Registration &R , int &c){
                cout<<"                           Press 1: For Main Menu "<<endl;
                cout<<"                           Press 2: For Next Menu ";
                cin>>c;
                InputCheck(c);
                if(c==1)
                {
                    system("cls");
                    return true;
                }
                else if(c==2)
                {
                    system("cls");
                    NextMenu(B,A,M,L);
                }
                else
                {
                    cout<<"                           Invalid Input"<<endl;
                }
}
int main()
{
    Registration reg;
    Login L(reg);
    AddCash A(reg);
    BillsAndPackages B(reg);
    MoneyTransfer M(reg);
    bool b;
    Position2:
    position3:
    do
        {
            int choice;
            drawshap();
            gotoRowCol(1,65);
            cout<<"Wellcome in The World of MM-Wallet "<<endl;
            gotoRowCol(3,70);
            cout<<"Loading.............."<<endl;
            sleep(10000);
            gotoRowCol(7,66);
            cout << "You Want to create new Account or Login " << endl;
            gotoRowCol(8,70);
            cout << "Press: " << endl;
            gotoRowCol(9,70);
            cout << "1. Register " << endl;
            gotoRowCol(10,70);
            cout << "2. Login " << endl;
            gotoRowCol(11,70);
            cout<< "3. Exit "<<endl;
            gotoRowCol(12,61);
            cout<<"_________________";
            gotoRowCol(13,70);
            cin >> choice;
            gotoRowCol(14,45);
            InputCheck(choice);
            if (choice == 1)
                {
                    b = reg.Register();
                    L=reg;
                    A=reg;
                    B=reg;
                    if(Menuselector(A,B,L,M,reg,choice))
                    {
                        goto Position2;
                    }
                }
            else if (choice == 2)
            {
                    b = L.loginAccount();
                    if(b==false)
                        continue;

                    if(Menuselector(A,B,L,M,reg,choice))
                    {
                        goto position3;
                    }
            }
        else
        {
            system("cls");
            continue;
        }
    }
    while (b == false);
    return 0;
}
