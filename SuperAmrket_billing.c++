#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Shopping
{
    private:
    int pcode;
    float price,dis;
    string pname;

    public:
        void menu();
        void adminstrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
 };


 void Shopping::menu()
 {
    int choice;
    string email,password;
    cout<<"\t\t\t\t__________________________\n";
    cout<<"\t\t\t\t                          \n";
    cout<<"\t\t\t\t     SuperMarket Menu     \n";
    cout<<"\t\t\t\t                          \n";
    cout<<"\t\t\t\t__________________________\n";
    cout<<"\t\t\t\t|     1)Adminstrator     |\n";
    cout<<"\t\t\t\t|                        |\n";
    cout<<"\t\t\t\t|     2)Buyer            |\n";
    cout<<"\t\t\t\t|                        |\n";
    cout<<"\t\t\t\t|     3)Exit             |\n";
    cout<<"\n\t\t\t\t/ Please Select\n";
        cin>>choice;
    
    

    
    switch(choice)
    {
        case 1:
            cout<<"\t\t\t\t Please login\n";
            cout<<"\t\t\t\t Enter Email \n";
            cin>>email;
            cout<<"\t\t\t\t Enter Password \n";
            cin>>password;

            if(email=="AbdoAmry@gmail.com" && password=="12345")
            {
                adminstrator();
            }
            else
            {
                cout<<"\t\t\t\t Invalid Email or Password\n";
            }
        break;
    case 2:
    {
        buyer();
        break;
    }
    
    case 3:
    {
        cout<<"\t\t\t\t Thank you for using our system\n";
        break;
    }

    default:
    {
        cout<<"\t\t\t\t Invalid Choice\n";
        break;
    }
    }

    cout << "\t\t\t\t Product code already exists. Please try again.\n";
    menu();

    }

 void Shopping::adminstrator()
 {
    int choice;
    cout<<"\t\t\t\t__________________________\n";
    cout<<"\t\t\t\t____1) add the product____\n";
    cout<<"\t\t\t\t|                        |\n";
    cout<<"\t\t\t\t____2) Modify the product____\n";
    cout<<"\t\t\t\t|                        |\n";
    cout<<"\t\t\t\t____3) Delete the product_____\n";
    cout<<"\t\t\t\t|                        |\n";
    cout<<"\t\t\t\t____4) Back To Main Menu_____\n";

    cout<<"\n\n\t Please Enter Your Choice\n";
    cin>>choice;
    switch(choice)
    
    {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"\t\t\t\t Invalid Choice\n";
            break;
    }
    
}

void Shopping::buyer()
{
    int choice;
    cout<<"\t\t\t\t__________________________\n";
    cout<<"\t\t\t\t____ buyer ____\n";
    cout<<"\t\t\t\t|                        |\n";
    cout<<"\t\t\t\t____1) buy product____\n";
    cout<<"\t\t\t\t|                        |\n";
    cout<<"\t\t\t\t____2) go back_____\n";

    cout<<"\n\n\t Please Enter Your Choice\n";
    cin>>choice;
    switch(choice)
    
    {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout<<"\t\t\t\t Invalid Choice\n";
            break;
    }

}


void Shopping::add()
{
    fstream data;
    int c;
    int token =0;
    float p,d;
    string n;

    cout<<"\n\n\t\t\t Add New Product\n"; 
    cout<<"\t\t\t Enter Product Code : ";
    cin>>pcode;
    cout<<"\t\t\t Enter Product Name : ";
    cin>>pname;
    cout<<"\t\t\t Enter Product Price : ";
    cin>>price;
    cout<<"\t\t\t Enter Product Discount : ";
    cin>>dis;

    data.open("database.txt",ios::in);
    if(!data)
    {
        data.open("database.txt",ios::out|ios::app);
        data<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<dis<<"\n";
        data.close();
        cout<<"\t\t\t Product Added Successfully\n";
    }
    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                token =1;
                break;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    if(token==1)
    {
        cout<<"\t\t\t Product code already exists. Please try again.\n";
        adminstrator();
    }
    else
    {
        data.open("database.txt",ios::out|ios::app);
        data<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<dis<<"\n";
        data.close();
        cout<<"\t\t\t Product Added Successfully\n";
    }   
    
}

void Shopping::edit()
{
    fstream data,data1;
    int pkey;
    int token;
    int c;
    float p,d;
    string n;
    
    cout<<"\n\n\t\t\t Modify Product\n";
    cout<<"\t\t\t Enter Product Code to Modify : ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\t\t\t File not found\n";
        
    }
    else
    {
        data1.open("temp.txt",ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\t\t\t Enter New Product Code : ";
                cin>>pcode;
                cout<<"\t\t\t Enter New Product Name : ";
                cin>>pname;
                cout<<"\t\t\t Enter New Product Price : ";
                cin>>price;
                cout<<"\t\t\t Enter New Product Discount : ";
                cin>>dis;
                data1<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<dis<<"\n";
                token =1;
            }
            else
            {
                data1<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("temp.txt","database.txt");
        if(token==0)
        {
            cout<<"\t\t\t Product not found\n";
        }
    }
}


void Shopping::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p,d;
    string n;
    
    cout<<"\n\n\t\t\t Delete Product\n";
    cout<<"\t\t\t Enter Product Code to Delete : ";
    cin>>pkey;
    
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\t\t\t File not found\n";
    }
    else
    {
        data1.open("temp.txt",ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\t\t\t Product Deleted\n";
                token =1;
            }
            else{

                data>>pcode>>pname>>price>>dis;
            }
            data1<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<dis<<"\n";
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("temp.txt","database.txt");
        if (token==0)
        {
            cout<<"\t\t\t Product not found\n";
        }
        
    }
}


void Shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n\t\t\t Product List\n";
    cout<<"\t\t\t Code\tName\tPrice\tDiscount\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<"\t\t\t "<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<dis<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();

}

void Shopping::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount =0;
    float discount=0;
    float total=0;


    list();
    cout<<"\n____________________________________________________\n";
    cout<<"|                                                     \n";
    cout<<"\n           please place the order                   \n";
    cout<<"|                                                     \n";
    cout<<"\n____________________________________________________\n";

    do{
        cout<<"\n\tEnter Product Code : ";
        cin>>arrc[c];
        cout<<"\tEnter Quantity : ";
        cin>>arrq[c];
        
        for(int i=0;i<c;i++)
        {
            if(arrc[c]==arrc[i])
            {
                cout<<"\t\tDuplicate product code .please try again\n";
                
                
            }
            c++;
            cout<<"\t\tDo you want to buy another product (y/n) : ";
            cin>>choice;

        }
        while(choice=='y' || choice=='Y')
        {
            cout<<"\n\n\n\t___________________Reciept____________________\n";
            cout<<"\nproduct no\tproduct name\tproduct quantity\tprice\ttotal\n";

            for(int i=0; i<c;i++)
            {
                data.open("database.txt",ios::in);
                data>>pcode>>pname>>price>>dis;
                while(!data.eof())
                {
                    if(arrc[i]==pcode)
                    {
                        amount=arrq[i]*price;
                        discount=amount-(amount*dis)/100;
                        total=total+dis;
                        cout<<"\t"<<i+1<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<amount<<"\t\t"<<amount*arrq[i]<<"\n";
                    }
                    data>>pcode>>pname>>price>>dis;
                }
            }
            data.close();

        }
        cout<<"\n\n_______________________\n";
        cout<<"\n Total amount \n";
    } while (choice=='y' || choice=='Y');
}


int main()
{
    Shopping s;
    s.menu();
    return 0;
}