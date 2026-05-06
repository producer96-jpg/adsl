#include<iostream>
using namespace std;
#define MAX 5
struct client{
    long long phone;
    string name;
};
class tel{
    private:
        client linear[MAX];
        client quadratic[MAX];
    public:
    tel(){
        for(int i=0;i<MAX;i++){
            linear[i].phone=-1;
           quadratic[i].phone=-1;

        }
    }

client getdata(){
    client c;
    cout<<"Enter number"<<endl;
    cin>>c.phone;
    cout<<"Enter Name"<<endl;
    cin>>c.name;
    return c;
}
void insertL(){
    client c=getdata();
    int index=c.phone%MAX;

    for(int i=0;i<MAX;i++){
        int pos=(index+i)%MAX;

        if(linear[pos].phone==-1){
           linear[pos]=c;
           cout<<"inserted////"<<endl;
           return; 
        }
    }
    cout<<"hasg table full"<<endl;
}
void searchL(long long key){
    int count=0;
    int index=key%MAX;
    for(int i=0;i<MAX;i++){
        count++;
        int pos=(index+i)%MAX;
        if(linear[pos].phone==key){
            cout<<"FOUND::"<<linear[pos].name;
            cout<<"COMPARISONS::"<<count;
            return;
        }
        if(linear[pos].phone==-1)
        break;
}
cout<<"NOT FOUND::"<<"comparisons"<<count;
}

void displayL(){
    cout<<"Displaying linear::"<<endl;
    for(int i=0;i<MAX;i++){
        cout<<i<<"->"<<linear[i].phone<<" "<<linear[i].name<<endl;
    }
}
//qqqqqq//
void insertQ(){
    client c=getdata();
    int index=c.phone%MAX;

    for(int i=0;i<MAX;i++){
        int pos=(index+i*i)%MAX;

        if(quadratic[pos].phone==-1){
           quadratic[pos]=c;
           cout<<"inserted////"<<endl;
           return; 
        }
    }
    cout<<"hasg table full"<<endl;
}
void searchQ(long long key){
    int count=0;
    int index=key%MAX;
    for(int i=0;i<MAX;i++){
        count++;
        int pos=(index+i*i)%MAX;
        if(quadratic[pos].phone==key){
            cout<<"FOUND::"<<quadratic[pos].name;
            cout<<"COMPARISONS::"<<count;
            return;
        }
        if(quadratic[pos].phone==-1)
        break;
}
cout<<"NOT FOUND::"<<"comparisons"<<count;
}

void displayQ(){
    cout<<"Displaying quadratic::"<<endl;
    for(int i=0;i<MAX;i++){
        cout<<i<<"->"<<quadratic[i].phone<<" "<<quadratic[i].name<<endl;
    }
}
};
int main(){
    tel t;
    int choice,type;
    long long key;
     while (true) {
        cout << "\n--- TELEPHONE DIRECTORY ---\n";
        cout << "1. Insert\n2. Display\n3. Search\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            cout<<"enter 1 for linear 2 for quadratic"<<endl;
            cin>>type;
            if(type==1){
                t.insertL();
            }
            else{
                t.insertQ();
            }
            break;
            case 2:
            cout<<"enter 1 for linear 2 for quadratic"<<endl;
            cin>>type;
            if(type==1){
                t.displayL();
            }
            else{
                t.displayQ();
            }
            break;
            case 3:
            cout<<"enter phn no."<<endl;
            cin>>key;
            cout<<"enter 1 for linear 2 for quadratic"<<endl;
            cin>>type;
            if(type==1){
                t.searchL(key);
            }
            else{
                t.searchQ(key);
            }
            break;
            case 4:
             cout << "exiting..." << endl;
                return 0;
            default:
            cout<<"invalid choice";
        }

    }

return 0;
}
