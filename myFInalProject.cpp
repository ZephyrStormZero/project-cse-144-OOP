#include<iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include<ctype.h>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include<ctime>
#include<windows.h>

using namespace std;
//global variables
int choice,choice1,choice2,choice3,choice4,choice5,choice6;
bool rakib,rimon,alvi,arif;

char ch[2];
string s="-------------------------Welcome to CSE_16 Electronics-------------------------\n\n";
string s1=" \n    Brand----|----type/size-----|----- price------quantity \n\n";
void gotoxy(int x,int y);
class product{
  public:
    char type[20];
    char brand[15];
    char sizeOrType[30];
    double price;
    int quantity;
    int productSerial;
    void get_Product();
    int show_ALLproducts(int n);
    void save_productTofile(int n);
    void selled_product();
    int search_product(int a,int b);

    void show_oneProduct();
    void update_product(int n,int s);
    int product_upMenu();
    void showtp();
     product(){
     productSerial=0;
     price=0;
     quantity=0;
     }};
int product::search_product(int a, int b)
{
 int typ=a;
 int id=b;
    ifstream file;
    switch (a){
case 1:
     file.open("Product_tv.txt",ios::out|ios::binary);
     break;
     case 2:
     file.open("Product_fridge.txt",ios::out|ios::binary);
     break;
     case 3:
         file.open("Product_oven.txt",ios::out|ios::binary);
         break;
     case 4:
        file.open("Product_air.txt",ios::out|ios::binary);
        break;
     case 5:
        file.open("Product_washing.txt",ios::out|ios::binary);
        break;
     default :
        break;}

    if(!file.is_open())
    {
        cout<<"FILE NOT OPENED";
    }
    else
    {file.read((char*)this,sizeof(*this));
     while(!file.eof()){
        if(productSerial==b)
        {
         return 1;
        }file.read((char*)this,sizeof(*this));
     }
    }
}



void product::showtp()
    {

        cout<<"1. TV\n2. Fridge\n3. Oven\n4. Washing Machine\n5. Air Conditioner\n6.Back"<<endl;
    }


void product::get_Product()//get new product
    {   cout<<"Enter these fields\n\n";
        cout<<"product serial: "<<endl;
        cin>>productSerial;
        cout<<"Product BRAND: "<<endl;
        cin.ignore();
        cin.getline(brand,15);
        cout<<"product Size OR Type: "<<endl;
        cin.getline(sizeOrType,30);
        cout<<"Product price(taka):"<<endl;
        cin>>price;
        cout<<"Quantity of product:"<<endl;
        cin>>quantity;
        cin.ignore();
    }


int product::show_ALLproducts(int n)
{   ifstream file;
     switch (n){
     case 1:
     file.open("Product_tv.txt",ios::out|ios::binary);
     break;
     case 2:
     file.open("Product_fridge.txt",ios::out|ios::binary);
     break;
     case 3:
         file.open("Product_oven.txt",ios::out|ios::binary);
         break;
     case 4:
        file.open("Product_air.txt",ios::out|ios::binary);
        break;
     case 5:
        file.open("Product_washing.txt",ios::out|ios::binary);
        break;
     case 6:
        return 1;
     default:
        cout<<"input a valid value";
        }

    file.read((char*)this,sizeof(*this));
    if(!file.is_open()){cout<<"NO PRODUCTS FILE FOUND!\n";}
    while(!file.eof()){
        show_oneProduct();
        file.read((char *)this,sizeof(*this));
        }
        return 0;}


void product::show_oneProduct()
{
    cout<<productSerial<<"."<<brand<<setw(8)<<"|"<<setw(9)<<sizeOrType<<setw(9)<<"|"<<setw(9)<<price<<"$"<<setw(7)<<"|"<<quantity<<endl;
}



void product::save_productTofile(int n)//to save a product data to file.
{
    ofstream fil;
    switch(n){
case 1:
    fil.open("Product_tv.txt",ios::app|ios::binary);
    break;
case 2:
    fil.open("Product_fridge.txt",ios::app|ios::binary);
    break;
case 3:
    fil.open("Product_oven.txt",ios::app|ios::binary);
    break;
case 4:
    fil.open("Product_air.txt",ios::app|ios::binary);
    break;
case 5:
    fil.open("Product_washing.txt",ios::app|ios::binary);
    break;


default:
    cout<<"Enter a valid input\n";
    break;

}  if(!fil.is_open()){cout<<"product file is not opend"<<endl;}
    else{
          get_Product();
        if(productSerial==0&&price==0&&quantity==0)
        {
          cout<<"no file Added ,put a real product values!!!"<<endl;
        }
        else{

    fil.write((char*)this,sizeof(*this));
    cout<<"NEW prodcut ADDED!"<<endl;

    fil.close();
    system("cls");

            }}}


int product::product_upMenu()
{
 cout<<"1.ADD new product\n2.Update older product"<<endl;
}

void product::update_product(int n,int s)
{
    int num=n;
    int serial=s;
    int a,b;

    fstream file;
    switch (num){
    case 1:
         file.open("Product_tv.txt",ios::in|ios::binary|ios::out|ios::ate);
       break;
    case 2:
         file.open("Product_fridge.txt",ios::in|ios::binary|ios::out|ios::ate);
         break;
    case 3:
        file.open("Product_oven.txt",ios::in|ios::binary|ios::out|ios::ate);
        break;
    case 4:
        file.open("Product_air.txt",ios::in|ios::binary|ios::out|ios::ate);
        break;
    case 5:
        file.open("Product_washing.txt",ios::in|ios::binary|ios::out|ios::ate);
        break;
    default:
        break;
    }

    file.seekg(0);
    if(!file.is_open()){cout<<"file is not open \n";}
    else{
        file.read((char*)this,sizeof(*this));
        while(!file.eof()){
            if(productSerial==serial){

                get_Product();
                a=file.tellp();
                b=sizeof(*this);

                file.seekp(a-b);
                file.write((char*)this,sizeof(*this));

            }file.read((char*)this,sizeof(*this));}
            file.close();}
    }
class customer{
    public:
    int phoneNumber;
    char customerName[25];
    char customerAdress[20];
    void get_customer();
    void show_One_customer();
    void show_All_customer();
    void search_customer(int number);
    int delete_customer(int n);
    void show_invoice();
    void ret_date();
    void print_invoice();
    void show_customerMmenu();
    void save_customertofile();
    void show_customerOne();
    void edit_customer(int n);

    };
void customer::edit_customer(int n)
{   int a;int b;
   fstream file;
    file.open("customerbin.txt",ios::in|ios::binary|ios::out|ios::ate);
    file.seekg(0);
    if(!file.is_open()){cout<<"file is not open \n";}
    else{
        file.read((char*)this,sizeof(*this));
         while(!file.eof()){
            if(phoneNumber==n){

                get_customer();
                a=file.tellp();
                b=sizeof(*this);

                file.seekp(a-b);
                file.write((char*)this,sizeof(*this));

            }file.read((char*)this,sizeof(*this));}
            file.close();}
   }
void customer::show_All_customer()
{
    ifstream file;
    file.open("customerbin.txt",ios::out|ios::binary);
    if(!file.is_open()){cout<<"FILE IS NOT OPEND!!\n";}
    file.read((char*)this,sizeof(*this));

    while(!file.eof()){
        show_customerOne();
        file.read((char *)this,sizeof(*this));


    }

    file.close();
    cout<<"thats all;;\n";
}
int customer::delete_customer(int n)
{   ifstream fin;
    ofstream fout;
    fin.open("customerbin.txt",ios::in|ios::binary);
    if(!fin.is_open()){cout<<"file is not opened ";
       return 0;}
    else{
        fout.open("customertemp.txt",ios::out|ios::binary);
        fin.read((char*)this,sizeof(*this));
    while(!fin.eof()){
            if(phoneNumber==n)
            {fout.write((char *)this,sizeof(*this));
            }fin.read((char *)this,sizeof(*this));
        }
    }
         fin.close();
         fout.close();
        remove("customerbin.txt");
        rename("customertemp.txt","customerbin.txt");
        cout<<"deleted!!!"<<endl;}

void customer::search_customer(int number)
{   bool found;
   found=false;
  ifstream file;
  file.open("customerbin.txt",ios::out|ios::in);
  if(!file.is_open()){cout<<"file not opened";}
    else
    {file.read((char*)this,sizeof(*this));
     while(!file.eof()){
        if(phoneNumber==number)
        {
            show_customerOne();
            found=true;
        }file.read((char*)this,sizeof(*this));
     }
     if(found==false){cout<<"CUSTOMER NOT FOUND!!! \n";}
    }
}


void customer::save_customertofile()
{
    ofstream file;
    file.open("customerbin.txt",ios::app);
    if(!file.is_open()){"customer file not opened";}
    else {get_customer();
    file.write((char *)this,sizeof(*this));
    cout<<"New customer added!!!\n";
    file.close();


    }


}
void customer::show_customerMmenu()
{
    cout<<"\n\n     01.Register new customer\n     02.Search customer\n     03.Delete a customer\n     04.Edit a customer\n     05.View full customer list\n";}


void customer::show_invoice()
{ cout<<"==============cse_16==============\n";
   ret_date();
  cout<<"\ncustomer Phone:"<<phoneNumber<<endl;
  cout<<"Name: "<<customerName<<endl;
  cout<<"adress :"<<customerAdress;
  cout<<"\nsell by :-----Rakib"<<endl;
  cout<<"sign\n-----\n";
  cout<<"===============thank you============";

}
void customer::show_customerOne()
{
    cout<<"\nPhone number: "<<phoneNumber;
    cout<<"\nCustomer Name: "<<customerName;
    cout<<"\n Address: "<<customerAdress;
}
void customer::get_customer()
{
    cout<<"\nEnter customer's info:"<<endl;
    cout<<"\nEnter Phone Number: ";

    cin>>phoneNumber;

    cout<<"\nCustomer Name: ";
    cin.ignore();

    cin.getline(customerName,25);
    cout<<"\nCustomer Address: "<<endl;

    cin.getline(customerAdress,20);

}
void customer::show_One_customer()
{
    cout<<"Phone Number: "<<phoneNumber<<endl;
    cout<<"NAME : "<<customerName<<endl;
    cout<<"Address: "<<customerAdress<<endl;
}
void customer::print_invoice()
{  string line;

    fstream file;
    file.open("CSE__16.txt",ios::in|ios::out|ios::trunc);
    if(!file.is_open()){cout<<" not inovoicE open";}

    else {
        getline(file,line);
       cout<<line;

    file<<s1;

    file<<"\n---selled by Rakib---"<<endl;
    file<<"-----------------------sign----"<<endl;
    file<<"-----------------Sabir Sir---"<<endl;
    file<<"-----------THANK YOU_______"<<endl;
    file.close();
    system("NOTEPAD /p CSE__16 Electronics shop");}



}





class invoice:public customer,public product{
    public:
    void save_invoice();
};
void customer::ret_date()
{
  int year,month,day;
 time_t d= time(0);
 tm *dt=localtime(&d);
 year=1900+dt->tm_year;
 month=1+dt->tm_mon;
 day=dt->tm_mday;
 cout<<day<<"/"<<month<<"/"<<year;
}




class MainMenu{
public:
    int dispmm();

};
int MainMenu::dispmm()
{           cout<<s<<"\n\n      what do you want to do?\n\n      1. Sell Product\n      2. Update Product\n      3. Search Date wise sells\n      4. Show all products\n      5. Customer Management\n      6. Search invoice\n      7. Authority\n\n";
            cin>>choice;
            system("cls");
            cout<<s;
            return choice;
}
int main()
{   system("color FC");
    product p;
    MainMenu m;
    customer c;
    invoice i;
    i.ret_date();
    mmenu:
        gotoxy(4,4);
    choice=m.dispmm();

    switch(choice){
case 1:
    mainmenu:
    p.showtp();
    cin>>choice2;
    system("cls");
    cout<<s1;
    choice3=p.show_ALLproducts(choice2);
    if(choice3==1){goto mainmenu;}
    else if(choice3==0){
            cin>>choice6;
     choice1=p.search_product(choice2,choice6);
     if(choice1==1)
        system("cls");
     {c.get_customer();
     system("cls");
       //i.print_invoice();
       c.show_invoice();
       c.print_invoice();
       return 0;



     }
    }

        break;
case 2:
    p.product_upMenu();
    cin>>choice1;
    if(choice1==1){cout<<"Which type of Product YOU want to add?\n\n";
                   p.showtp();
                   cin>>choice2;
                   system("cls");
                   p.save_productTofile(choice2);
                   system("cls");
                   goto mmenu;

                   }
    else if(choice==2){
        cout<<"which product you want to update?\n";
        p.showtp();
        cin>>choice2;
        system("cls");
        choice4=p.show_ALLproducts(choice2);
        if(choice4==1){goto mainmenu;}
        cout<<"ENTER serial no to update:"<<endl;
        cin>>choice5;

        p.update_product(choice2,choice5);
    }
    break;
case 3:
    break;

case 4:
    cout<<s1;
    cout<<"\nTYPE: TV\n";

    p.show_ALLproducts(1);
    cout<<"\nTYPE: FRIDGE\n";

    p.show_ALLproducts(2);
    cout<<"\nTYPE: OVEN\n";

    p.show_ALLproducts(3);
    cout<<"\nTYPE: WASHING MACHINE\n";

    p.show_ALLproducts(4);
    cout<<"\nTYPE: AIR CONDITIONER\n";

    p.show_ALLproducts(5);
    cout<<"\n goto main menu? press :1\n\n";
    cin>>choice3;
     switch(choice3){case 1:system("cls");goto mmenu;break;
  default:
    break;}
    break;
case 5:
    c.show_customerMmenu();
    cin>>choice4;
    if(choice4==1){system("cls");
                c.save_customertofile();
     }
    else if (choice4==2){system("cls");
    cout<<"\nENTER PHONE NUMBER TO SEARCH\n";
        cout<<"PHONE NUMBER: ";
        cin>>choice5;
        c.search_customer(choice5);
        goto mmenu;}
    else if(choice4==3){system("cls");
      cin>>choice3;
      choice5=c.delete_customer(choice3);
       if(choice5==0){goto mmenu;}
      }
    else if(choice4==5){
        c.show_All_customer();
    }
    else if(choice4==4){
            system("cls");
            cout<<"ENTER PHONE NUMBER TO EDIT CUSTOMER:\n";
            cin>>choice5;
            c.edit_customer(choice5);}

    }

}
COORD coord = {0,0};
void gotoxy(int x, int y){
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


