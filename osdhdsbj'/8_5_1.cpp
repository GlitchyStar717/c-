#include<iostream>//or
#include<fstream>
#include<iomanip>
using namespace std;
class transaction
{
public:
    long int account_number;
    char lastname[20],firstname[20];
    float total_balance;
    void getdata()
    {
        cout<<endl<<"Enter the following details:"<<endl;
        cout<<"Account number:";
        cin>>account_number;
        cout<<"First name:";
        cin>>firstname;
        cout<<"Last name:";
        cin>>lastname;
        cout<<"Total balance:";
        cin>>total_balance;
    }
    void display()
    {        cout<<left<<setw(15)<<account_number<<setw(15)
            <<firstname<<setw(15)<<lastname<<right<<setw(5)<<total_balance<<endl;
    }
};
int main()
{
    transaction tr;
    fstream file;
    int choice;
    while(1){
    cout<<"\n\nEnter your choice:"<<endl;
    cout<<"1) Add account\n";
    cout<<"2) Update account\n";
    cout<<"3) Delete account\n";
    cout<<"4) Display all accounts\n";
    cout<<"5) Exit\n";
    cout<<"Enter your choice:";
    cin>>choice;
    int record_pos,location;
    char ch;
    switch(choice)
    {
    
    case 1:{
        file.open("transaction.txt",ios::out|ios::app|ios::binary);

        tr.getdata();
        file.write(reinterpret_cast<char*>(&tr),sizeof(tr));
      
        file.close();
        break;
    }
    case 2:{
        file.open("transaction.txt",ios::out|ios::in|ios::binary);
        cout<<"Enter acc number to be updated:";
        long int accn;
        float nbal;
        cin>>accn;
        cout<<"Enter new balance:";
        cin>>nbal;
        transaction t;
    std::fstream tempFile("temp.txt", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);

    // Find the account with the matching account number and update it
    while (file.read(reinterpret_cast<char*>(&t), sizeof(transaction))) {
        if (t.account_number == accn) {
            t.total_balance = nbal;
        }
        tempFile.write(reinterpret_cast<const char*>(&t),sizeof(transaction));
    }

    // Close the original file and rename the temporary file
    file.close();
    tempFile.close();
    std::remove("transaction.txt");
    std::rename("temp.txt", "transaction.txt");
       break;
   }
    case 3:{
        file.open("transaction.txt",ios::in|ios::binary);
        ofstream tempFile("temp.txt",ios::out|ios::binary);
        long int accn;
        cout<<"Enter acc number to be deleted:";
        cin>>accn;

        transaction t;
        while (file.read(reinterpret_cast<char*>(&t), sizeof(transaction))) {
        if (t.account_number != accn) {
        tempFile.write(reinterpret_cast<const char*>(&t),sizeof(transaction));
        }
    }
        file.close();
        tempFile.close();
        remove("transaction.txt");
        rename("temp.txt","transaction.txt");
        break;
    }
    case 4:{
        file.open("transaction.txt",ios::in|ios::binary);
        cout<<endl<<setiosflags(ios::left)<<setfill('*')<<setw(58)<<'*'<<endl;
        cout<<setfill(' ')<<setw(15)<<"Acc number"<<setw(15)<<"First name"<<setw(15)<<"Last name"<<setw(15)<<"Total balance"<<endl;
        cout<<setiosflags(ios::left)<<setfill('*')<<setw(58)<<'*'<<setfill(' ')<<endl;
        while(file.read(reinterpret_cast<char*>(&tr),sizeof(tr)))
        {
            tr.display();
        }
        file.close();
        break;
    default:
        exit(0);
    }
    }
    }
}

