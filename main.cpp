#include <bits/stdc++.h>
#include<string>
#include<conio.h>
using namespace std;
//int idnumbercustomer=1;
//int idnumberowner=1;
int balance;
string idnumber,idcusnumber;
int product_id;
bool ok=false;
bool idok;
void buy(int k);

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void mainpage()
{
    int process=0;
    system("cls");
// date();
    printf("\n");
    printf("\t\t\t\t    -----------------------\n");
    printf("\t\t\t\t    |HAND TOUCH BANGLADESH|\n");
    printf("\t\t\t\t    -----------------------\n");
    printf("\n\n\n");
    printf("\t\t\t\t");
    printf("Prepared By    ");
    printf(":");
    printf("   Syed Nahin Hossain");
// printf("\n\n");
    printf("\t\t\t\t");
// printf("\n\n");
    printf("\t\t\t\t");
    printf("Roll           :   1707032\n");
// printf("\n\n");
    printf("\t\t\t\t");
    printf("Project title  ");
    printf(":");
    printf("   Company Management System");
    printf("\n\n");
    printf("\t\t\t\t");
    printf("\n\n");
    printf("\t\t\t\t    Press Enter to continue......");
    printf("\n\n");
    getchar();
    printf("\t\t\t\tLoading");

    for(process=0; process<15; process++)
    {
        delay(150);
        printf(".");
    }
    cout<<endl;
}
void exist(int k,string name)
{
    idok=false;
    int f=0;
    fstream fin;
    if(k==1)
    {
        fin.open("userid.csv", ios::in);
    }
    else if(k==2)
    {
        fin.open("admin.csv", ios::in);
    }
    else if(k==3)
    {
        fin.open("item.csv", ios::in);
    }
    vector<string> row;
    string line="", word, temp;


    while (fin >> temp)
    {

        row.clear();
        row.push_back(temp);
        getline(fin, line);
        //fin>>line;
        //cout<<line<<endl;
        stringstream s(line);
        while (getline(s,word,','))
        {
            //   cout<<endl<<"i am here"<<endl;

            row.push_back(word);
        }
        //cout<<row.size()<<endl;
        /*for(int i=0;i<row.size();i++){
            cout<<row[i];
        }*/

        row[1]=row[1].substr(1);
        //row[2]=row[2].substr(1);
        //cout<<endl<<row[1]<<endl<<name<<endl;
        if( row[1]== name)
        {
            f=1;
            //      cout<<endl<<row[1]<<endl;
            idok=true;
        }

    }
    if(f==0)
    {
        idok=false;
    }
    fin.close();
}
template<class t>///.////////////////////////////////////////template/////////////////
void Register(t k)
{
    fstream fout,it;

    if(k==1)
    {
        fout.open("userid.csv", ios::out | ios::app);
        it.open("userid.csv", ios::in);
    }
    /*else if(k==2)
    {
        fout.open("admin.csv", ios::out | ios::app);
        it.open("admin.csv", ios::in);
    }*/
    string name,pass;

    /* cout<<"How many times?";
     int qq;
     cin>>qq;
    */
    for (int i = 0; ; i++)
    {
        // system("cls");
        cout << "Enter the name (Without space) : ";
        cin>>name;
        exist(k,name);
        if(idok==true)
        {
            cout<<"Username already exist.\nPlease try a new one.\n";
            continue;
        }
        cout<<"Enter the password (Without space) : ";
        cin>>pass;

        string temp;
        product_id=0;
        while(it>>temp)
        {
            //   cout<<"pi : "<<product_id<<endl;
            product_id++;
        }
        it.close();
        //item.open("item.csv" , ios::out | ios::app);
        if(k==1)
        {
            product_id=product_id/4;//user
        }
        else if(k==2)
        {
            product_id=product_id/4;//owner
        }
        product_id++;
        if(k==1)
        {
            fout<<product_id<<", "
                <<name<<", "
                <<pass<<", "
                <<"10000"<<"\n";
            //idnumbercustomer++;
        }
        else if(k==2)
        {
            fout<<product_id<<", "
                <<name<<", "
                <<pass<<", "
                <<"0"<<"\n";
            //idnumberowner++;
        }
        break;
    }
    //cout<<"Press any key to continue...";
    //getchar();
}
void Login(int k)///./////////////////////////////////////////////////////////////////////////////////////Function overloading 01/////////////
{
    int f=0;
    fstream fin;

    fin.open("admin.csv", ios::in);

    vector<string> row;
    string line="", word, temp;
    string name;
    cout<<"Enter the user name : ";
    cin>>name;
    cout<<"Enter the password : ";

    /////////////////////////////////////password//////////////////////////////////////////////////////
    char pass[32];//to store password.
    int i = 0;
    char a;//a Temp char
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  system("cls");

    //cin>>password;
    cout<<"\nWant to show password?\n1.Yes\n2.No"<<endl;
    int sss;
    cin>>sss;
    if(sss==1)
        cout<<"\nYou entered password : "<<pass<<endl;

    while (fin >> temp)
    {

        row.clear();
        row.push_back(temp);
        getline(fin, line);
        //fin>>line;
        //cout<<line<<endl;
        stringstream s(line);
        while (getline(s,word,','))
        {
            //   cout<<endl<<"i am here"<<endl;

            row.push_back(word);
        }
        //cout<<row.size()<<endl;
        /*for(int i=0;i<row.size();i++){
            cout<<row[i];
        }*/

        row[1]=row[1].substr(1);
        row[2]=row[2].substr(1);
        //cout<<endl<<row[1]<<endl<<name<<endl;
        if( row[1]== name)
        {
            f=1;
            //      cout<<endl<<row[1]<<endl;
            if(row[2]==pass)
            {
                cout<<"Welcome\n";
                cout<<"Your balance is : "<<row[3]<<endl;
                ok=true;
                balance=stoi(row[3]);
                idcusnumber=row[0];
                idcusnumber=idcusnumber.erase(idcusnumber.size()-1);
                break;
            }
            else
            {
                cout<<"Invalid password \n";
                break;
            }
        }

    }
    if(f==0)
    {
        cout<<"ID not found.\nPlease register first :D ";
    }
    fin.close();
    // cout<<"Press any key to continue...";
    // getchar();
}

void Login(double k)///./////////////////////////////////////////////////////////////////////////////////Function overloading 02//////////////
{
    int f=0;
    fstream fin;

    fin.open("userid.csv", ios::in);
    vector<string> row;
    string line="", word, temp;
    string name;
    //  system("cls");
    cout<<"Enter the user name : ";
    cin>>name;
    cout<<"Enter the password : ";
    ////////////////////////////////////////////////////////////////////////////////

    char pass[32];//to store password.
    int i = 0;
    char a;//a Temp char
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    cout<<"\nWant to show password?\n1.Yes\n2.No"<<endl;
    int sss;
    cin>>sss;
    if(sss==1)
        cout<<"\nYou entered password: "<<pass<<endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  system("cls");

    //cin>>password;


    while (fin >> temp)
    {

        row.clear();
        row.push_back(temp);
        getline(fin, line);
        //fin>>line;
        //cout<<line<<endl;
        stringstream s(line);
        while (getline(s,word,','))
        {
            //   cout<<endl<<"i am here"<<endl;

            row.push_back(word);
        }
        //cout<<row.size()<<endl;
        /*for(int i=0;i<row.size();i++){
            cout<<row[i];
        }*/

        row[1]=row[1].substr(1);
        row[2]=row[2].substr(1);
        //cout<<endl<<row[1]<<endl<<name<<endl;
        if( row[1]== name)
        {
            f=1;
            //      cout<<endl<<row[1]<<endl;
            if(row[2]==pass)
            {
                cout<<"Welcome\n";
                cout<<"Your balance is : "<<row[3]<<endl;
                ok=true;
                balance=stoi(row[3]);
                idcusnumber=row[0];
                idcusnumber=idcusnumber.erase(idcusnumber.size()-1);
                break;
            }
            else
            {
                cout<<"Invalid password \n";
                break;
            }
        }

    }
    if(f==0)
    {
        cout<<"ID not found.\nPlease register first :D ";
    }
    fin.close();
    //  cout<<"Press any key to continue...";
    //  getchar();
}
class Update ///.////////////////////////////////////////////////////////////////////////////////////////runtime polymorphism////////////////
{
public:

    virtual void update() {};
};
class CustomerLogIn
{
    int balc=balance;
public:

    void work()
    {
        //  system("cls");
        cout<<"What do you want to do?\n1.Register\n2.Login\n3.Update Password\n";
        int n;
        cin>>n;
        system("cls");
        if(n==1)
        {
            Register<int>(1);///.//////////////////////////////////template///////////////
        }
        else if(n==2)
        {
            Login(1.1);
        }
        else if(n==3)
        {
            cout<<"In order to update you have to login first "<<endl;
            Login(1.1);
            if(ok==true)
                update();
        }
        cout<<"Press any key to continue...";
        getchar();
        getchar();

    }
    virtual void update()
    {
        fstream fin,fout;
        fin.open("userid.csv", ios::in);
        fout.open("useridnew.csv", ios::out);
        int countt=0,index,n=0;
        string item,line,word,name,pass,password;
        vector<string>row;
        // cout<<"What do you want to do?\n1.Update Username\n2.Update Password\n";
        //cin>>n;
        /*if(n==1){
            cout<<"Please enter your user name again : ";
        cin>>item;
        cout<<"Enter the new name : ";
        cin>>name;
        index=1;
        }
        elseif(n==2){*/
        // system("cls");
        cout<<"Please enter your user name again : ";
        cin>>item;
        cout<<"Enter the new password : ";
        cin>>pass;
        index=2;
        //}
        while(!fin.eof())
        {
            row.clear();
            getline(fin,line);
            stringstream s(line);
            while(getline(s,word,','))
            {
                row.push_back(word);
            }
            int rowsize;
            rowsize=row.size();
            // cout<<row[1]<<endl;
            row[1]=row[1].substr(1);
            //cout<<row[1]<<endl;
            if(row[1]==item)
            {
                countt=1;
                stringstream convert;
                /*if(n==1){
                    convert<<name;

                }
                else if(n==2){*/
                convert<<pass;

                // }
                row[index]=convert.str();
                if(!fin.eof())
                {
                    for(int i=0; i<rowsize-1; i++)
                    {
                        if(i==index)
                        {
                            fout<<row[i]<<',';
                            continue;
                        }
                        if(i>1)
                        {
                            row[i]=row[i].substr(1);
                        }
                        fout<<row[i]<<", ";
                    }
                    fout<<row[rowsize-1]<<"\n";
                }
            }
            else
            {
                if(!fin.eof())
                {
                    for(int i=0; i<rowsize-1; i++)
                    {
                        if(i>1)
                        {
                            row[i]=row[i].substr(1);
                        }
                        fout<<row[i]<<", ";
                    }
                    row[rowsize-1]=row[rowsize-1].substr(1);
                    fout<<row[rowsize-1]<<"\n";
                }
            }
            if(fin.eof())
            {
                break;

            }
        }
        if(countt==0)
        {
            cout<<"Not found\n";
        }
        fin.close();
        fout.close();
        remove("userid.csv");
        rename("useridnew.csv","userid.csv");

    }
    ~CustomerLogIn()///./////////////////////////////////////////////////////////////////////////////destructor///////////////////////
    {

    };
    friend void Register(int k);///./////////////////////////////////////////////////////////////////friend function/////////////////
    friend void Login();
};

class product:virtual public Update
{
public:
    string item_name;
    int price;
    void addproduct()
    {

        fstream item,it;
        it.open("item.csv", ios::in);
        string temp;
        product_id=0;
        while(it>>temp)
        {
            //   cout<<"pi : "<<product_id<<endl;
            product_id++;
        }
        it.close();
        item.open("item.csv", ios::out | ios::app);
        product_id=product_id/3;
        //  cout<<product_id<<endl;
        // system("cls");
        cout<<"How many product? "<<endl;
        int j;
        cin>>j;
        for(int i=0; i<j; i++)
        {
            cout<<"Enter Item name (Without space) : ";
            cin>>item_name;
            exist(3,item_name);
            if(idok==true)
            {
                cout<<"You have already register the product.\nPlease enter a new one.\nDo you want to add a new one?\n1.Yes\n2.No\n";
                int j;
                cin>>j;
                if(j==1)
                {
                    i--;
                    continue;
                }
                else if(j==2)
                {
                    continue;
                }
            }
            cout<<"Enter Item price : ";
            cin>>price;
            product_id++;
            item <<product_id<<", "
                 <<item_name<<", "
                 <<price<<"\n";
        }
    }
    void all_product()
    {
        fstream ap;
        ap.open("item.csv", ios:: in);
        vector<string>row;
        string line,word,temp;
        //  system("cls");
        cout<<"Number Tag"<<"            "<<"Number Name"<<"            "<<"Price"<<endl;
        while(ap>>temp)
        {
            row.clear();
            row.push_back(temp);
            getline(ap,line);
            stringstream s(line);
            while(getline(s,word,','))
            {
                row.push_back(word);
            }

            for(int p=0; p<row.size(); p++)
            {
                if(p==0)
                {
                    row[p]=row[p].erase(row[p].size()-1);
                }
                cout<<row[p]<<"                    ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void select_product()
    {
        int n=0;
        string number;
        // system("cls");
        cout<<"Enter the number of the product : ";
        cin>>number;
        //cout<<number<<endl;
        fstream pd;
        pd.open("item.csv", ios :: in);
        vector<string>row;
        string line,word,temp;
        while(pd>>temp)
        {
            row.clear();
            row.push_back(temp);
            getline(pd,line);
            //cout<<line<<endl;
            stringstream s(line);
            while(getline(s,word,','))
            {
                row.push_back(word);
            }
            // int num = atoi(row[0]);
            row[0]=row[0].erase(row[0].size()-1);
            // cout<<row[0]<<endl<<number<<endl;
            if( row[0] == number)
            {
                n=1;
                cout<<"Number Tag"<<"            "<<"Number Name"<<"                   "<<"Price"<<endl;
                for(int p=0; p<row.size(); p++)
                {
                    cout<<row[p]<<"                    ";
                }
                cout<<endl;
                cout<<"Do you want to buy the product?\n1.Yes\n2.No\n";
                int y;
                cin>>y;
                if(y==1)
                {
                    idnumber=row[0];
                    int kk;
                    kk=stoi(row[2]);
                    cout<<"cost is : "<<kk<<endl;
                    buy(kk);
                }
                break;
            }
        }
        if(n==0)
        {
            cout<<"Item not found"<<endl;
        }
    }
    void update()
    {
        fstream fin,fout;
        fin.open("item.csv", ios::in);
        fout.open("itemnew.csv", ios::out);
        int newprice,countt=0,index,n;
        string item,line,word,name;
        vector<string>row;
        //  system("cls");
        cout<<"What do you want to do?\n1.Update price\n2.Update Name\n";
        cin>>n;
        if(n==1)
        {
            cout<<"Enter the item number to be updated : ";
            cin>>item;
            cout<<"Enter the new price : ";
            cin>>newprice;
            index=2;
        }
        else if(n==2)
        {
            cout<<"Enter the item number to be updated : ";
            cin>>item;
            cout<<"Enter the new name (Without space) : ";
            cin>>name;
            index=1;
        }
        while(!fin.eof())
        {
            row.clear();
            getline(fin,line);
            stringstream s(line);
            while(getline(s,word,','))
            {
                row.push_back(word);
            }
            int rowsize;
            rowsize=row.size();
            if(row[0]==item)
            {
                countt=1;
                stringstream convert;
                if(n==1)
                {
                    convert<<newprice;

                }
                else if(n==2)
                {
                    convert<<name;

                }
                row[index]=convert.str();
                if(!fin.eof())
                {
                    for(int i=0; i<rowsize-1; i++)
                    {
                        if(i==index)
                        {
                            fout<<row[i]<<',';
                            continue;
                        }
                        if(i>0)
                        {
                            row[i]=row[i].substr(1);
                        }
                        fout<<row[i]<<", ";
                    }
                    fout<<row[rowsize-1]<<"\n";
                }
            }
            else
            {
                if(!fin.eof())
                {
                    for(int i=0; i<rowsize-1; i++)
                    {
                        fout<<row[i]<<',';
                    }
                    fout<<row[rowsize-1]<<"\n";
                }
            }
            if(fin.eof())
            {
                break;

            }
        }
        if(countt==0)
        {
            cout<<"Not found\n";
        }
        fin.close();
        fout.close();
        remove("item.csv");
        rename("itemnew.csv","item.csv");

    }
    int operator - (int number);///.///////////////////////////////////////////////////operator overloading///////////
};
int product::operator - (int number)///.////////////////////////////////////////////////////operator overloading////////////////////////
{

    int b=this->price-number;
    return b;
}

void buy(int k)
{

    product j;
    j.price=k;
    balance=j-balance;///operator overloading///////////////////////////////////////////////////////////////operator overloading////////////////
    balance=-balance;
    if(balance<0)
    {
        cout<<"Insufficient balance.\nPlease load first\n";
        balance=balance+k;
        cout<<endl<<"Current balance is : "<<balance<<endl;
        return;
    }
    cout<<endl<<"Current balance is : "<<balance<<endl;
    fstream fin,fout;
    fin.open("userid.csv", ios::in);
    fout.open("useridnew.csv", ios::out);
    int countt=0,index,n=0;
    string item,line,word;
    vector<string>row;
    item=idcusnumber;
    index=3;
    while(!fin.eof())
    {
        row.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,','))
        {
            row.push_back(word);

        }
        /*for(int r=0;r<row.size();r++){
                cout<<row[r]<<"     ";
            }
            cout<<endl;*/
        int rowsize;
        rowsize=row.size();
//        cout<<"rowsize : "<<rowsize<<endl;
//        cout<<row[0]<<endl;
        //row[1]=row[1].substr(1);
//        cout<<item<<endl;
        //row[0]=row[0].erase(row[0].size()-1);
//        cout<<row[0]<<endl;
        if(row[0]==item)
        {
            countt=1;
            stringstream convert;
            /*if(n==1){
                convert<<name;

            }
            else if(n==2){*/
            convert<<balance;

            // }
            row[index]=convert.str();
            if(!fin.eof())
            {
                for(int i=0; i<rowsize-1; i++)
                {
                    if(i==index)
                    {
                        fout<<row[i]<<',';
                        continue;
                    }
                    if(i>0)
                    {
                        row[i]=row[i].substr(1);
                    }
                    fout<<row[i]<<", ";
                }
                fout<<row[rowsize-1]<<"\n";
            }
        }
        else
        {
            if(!fin.eof())
            {
                for(int i=0; i<rowsize-1; i++)
                {
                    if(i>0)
                    {
                        row[i]=row[i].substr(1);
                    }
                    fout<<row[i]<<", ";
                }
                row[rowsize-1]=row[rowsize-1].substr(1);
                fout<<row[rowsize-1]<<"\n";
            }
        }
        if(fin.eof())
        {
            break;

        }
    }
    if(countt==0)
    {
        cout<<"Not found\n";
    }
    fin.close();
    fout.close();
    remove("userid.csv");
    rename("useridnew.csv","userid.csv");

}
class OwnerID:public product,virtual public Update
{
public:
    OwnerID () {}
    OwnerID (string name,string pass)///.///////////////////////////////////////////////////////////////constructor/////////////////////
    {
        fstream fout,it;
        fout.open("admin.csv", ios::out | ios::app);
        it.open("admin.csv", ios::in);
        string temp;
        product_id=0;
        while(it>>temp)
        {
            //   cout<<"pi : "<<product_id<<endl;
            product_id++;
        }
        it.close();
        //item.open("item.csv" , ios::out | ios::app);

        product_id=product_id/4;//owner

        product_id++;

        fout<<product_id<<", "
            <<name<<", "
            <<pass<<", "
            <<"100000"<<"\n";
        //idnumberowner++;

        //break;
    }

    void all_id()
    {
        fstream ap;
        ap.open("userid.csv", ios:: in);
        vector<string>row;
        string line,word,temp;
        //  system("cls");
        cout<<"Number Tag"<<"            "<<"Name"<<"                   "<<"Password"<<"               "<<"Balance"<<endl;
        while(ap>>temp)
        {
            row.clear();
            row.push_back(temp);
            getline(ap,line);
            stringstream s(line);
            while(getline(s,word,','))
            {
                row.push_back(word);
            }

            for(int p=0; p<row.size(); p++)
            {
                if(p==0)
                {
                    row[p]=row[p].erase(row[p].size()-1);
                }
                cout<<row[p]<<"                    ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void all_owid()
    {
        fstream ap;
        ap.open("admin.csv", ios:: in);
        vector<string>row;
        string line,word,temp;
        //  system("cls");
        cout<<"Number Tag"<<"            "<<"Name"<<"                   "<<"Password"<<"               "<<"Balance"<<endl;
        while(ap>>temp)
        {
            row.clear();
            row.push_back(temp);
            getline(ap,line);
            stringstream s(line);
            while(getline(s,word,','))
            {
                row.push_back(word);
            }

            for(int p=0; p<row.size(); p++)
            {
                if(p==0)
                {
                    row[p]=row[p].erase(row[p].size()-1);
                }
                cout<<row[p]<<"                    ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    virtual void update()
    {
        fstream fin,fout;
        fin.open("admin.csv", ios::in);
        fout.open("adminnew.csv", ios::out);
        int countt=0,index,n=0;
        string item,line,word,name,pass,password;
        vector<string>row;
        // cout<<"What do you want to do?\n1.Update Username\n2.Update Password\n";
        //cin>>n;
        /*if(n==1){
            cout<<"Please enter your user name again : ";
        cin>>item;
        cout<<"Enter the new name : ";
        cin>>name;
        index=1;
        }
        elseif(n==2){*/
        system("cls");
        cout<<"Please enter your user name again : ";
        cin>>item;
        cout<<"Enter the new password : ";
        cin>>pass;
        index=2;
        //}
        while(!fin.eof())
        {
            row.clear();
            getline(fin,line);
            stringstream s(line);
            while(getline(s,word,','))
            {
                row.push_back(word);
            }
            int rowsize;
            rowsize=row.size();
            // cout<<row[1]<<endl;
            row[1]=row[1].substr(1);
            //cout<<row[1]<<endl;
            if(row[1]==item)
            {
                countt=1;
                stringstream convert;
                /*if(n==1){
                    convert<<name;

                }
                else if(n==2){*/
                convert<<pass;

                // }
                row[index]=convert.str();
                if(!fin.eof())
                {
                    for(int i=0; i<rowsize-1; i++)
                    {
                        if(i==index)
                        {
                            fout<<row[i]<<',';
                            continue;
                        }
                        if(i>1)
                        {
                            row[i]=row[i].substr(1);
                        }
                        fout<<row[i]<<", ";
                    }
                    fout<<row[rowsize-1]<<"\n";
                }
            }
            else
            {
                if(!fin.eof())
                {
                    for(int i=0; i<rowsize-1; i++)
                    {
                        if(i>1)
                        {
                            row[i]=row[i].substr(1);
                        }
                        fout<<row[i]<<", ";
                    }
                    row[rowsize-1]=row[rowsize-1].substr(1);
                    fout<<row[rowsize-1]<<"\n";
                }
            }
            if(fin.eof())
            {
                break;

            }
        }
        if(countt==0)
        {
            cout<<"Not found\n";
        }
        fin.close();
        fout.close();
        remove("admin.csv");
        rename("adminnew.csv","admin.csv");

    }
    friend void Register(int k);
    friend void Login(int k);
};

int main()
{
    mainpage();
    system("cls");
    while(1)
    {
        int m;
        ok=false;
        system("cls");
        cout<<"Log in as a \n1.Owner\n2.customer\n0.Want to terminate\n";
        cin>>m;
        system("cls");
        try///.//////////////////////////////////////////////////////////////try block use////////
        {
            if(m!=1 && m!=2 && m!=0)
            {
                throw(m);
            }
            else if(m==1)
            {
                //system("cls");
                cout<<"Welcome Sir.\n";
                OwnerID id;
                //id.work();
                cout<<"What do you want to do?\n1.Register\n2.Login\n3.Update\n";
                int c;
                cin>>c;
                system("cls");
                if(c==1)
                {
                    string name,pass;
                    for (int i = 0; ; i++)
                    {

                        // system("cls");
                        cout << "Enter the name (Without space): ";
                        cin>>name;
                        exist(2,name);
                        if(idok==true)
                        {
                            cout<<"Username already exist.\nPlease try a new one.\n";
                            continue;
                        }
                        cout<<"Enter the password(Without space) : ";
                        cin>>pass;
                        OwnerID(name,pass);
                        break;
                    }

                    // cout<<"Press any key to continue...";
                    //
                    // getchar();
                    getchar();
                }
                else if(c==2)
                {
                    Login(2);
                    //cout<<"Press any key to continue...";
                    //getchar();
                    getchar();
                }
                else if(c==3)
                {
                    // system("cls");
                    cout<<"In order to update you have to login first "<<endl;
                    Login(2);
                    Update* up;
                    if(ok==true)
                    {

                        up= &id;
                    }
                    up->update();///.////////////////////////////////////////////////////////////////////////////runtime polymorphism////////////////
                    continue;
                    //cout<<"Press any key to continue...";
                    // getchar();
                }
                cout<<"Press any key to continue...";
                getchar();
                getchar();

                /*//////////////////////////////////////////////////////////////////////*/
                if(ok==true)
                {
                    while(1)
                    {
                        system("cls");
                        cout<<"What do you want?\n1.Add product\n2.View product\n3.View all product\n4.Update a product\n5.Show all user id info\n6.Show all admin user id\n0.terminate"<<endl;
                        int c;
                        cin>>c;
                        system("cls");
                        product pd;
                        if(c==1)
                        {

                            pd.addproduct();
                            cout<<"Press any key to continue...";
                            getchar();
                            getchar();

                        }
                        else if(c==2)
                        {
                            pd.select_product();
                            cout<<"Press any key to continue...";
                            getchar();
                            getchar();
                        }
                        else if(c==3)
                        {
                            pd.all_product();
                            cout<<"Press any key to continue...";
                            getchar();
                            getchar();
                        }
                        else if(c==4)
                        {
                            Update* upp;///runtime polymorphism
                            upp=&pd;
                            upp->update();
                            cout<<"Press any key to continue...";
                            getchar();
                            getchar();
                        }
                        else if(c==5)
                        {
                            id.all_id();
                            cout<<"Press any key to continue...";
                            getchar();
                            getchar();
                        }
                        else if(c==6)
                        {
                            id.all_owid();
                            cout<<"Press any key to continue...";
                            getchar();
                            getchar();
                        }
                        else if(c==0)
                        {
                            break;
                        }
                        //cout<<"Press any key to continue...";
                        //getchar();
                    }
                }
            }
            else if(m==2)
            {
                CustomerLogIn k;
                k.work();
                if(ok==true)
                {
                    product k;
                    while(1)
                    {
                        system("cls");
                        cout<<"What do you want?\n1.View product\n2.View all product\n0.terminate"<<endl;
                        int c;
                        cin>>c;
                        /*if(c==1){
                        cout<<"How many product? "<<endl;
                        int j;
                        cin>>j;
                        for(int i=0;i<j;i++){
                        k.addproduct();
                        }
                        }*/
                        if(c==1)
                        {
                            k.select_product();
                            cout<<"Press any key to continue...";
                            getchar();
                            getchar();
                        }
                        else if(c==2)
                        {
                            k.all_product();
                            cout<<"Press any key to continue...";
                            getchar();
                            getchar();
                        }
                        else if(c==0)
                        {
                            break;
                        }
                    }
                }
            }
            else if(m==0)
            {
                break;
            }


        }
        catch(int l)
        {
            cout<<"Invalid keyword!\nPlease enter the right one :D"<<endl;
            getchar();
            getchar();
        }

    }

    return 0;
}
