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
bool rakib=false,rimon=false,alvi=false,arif=false;
char nameOfCustomer[30];
char addressOfCustomer[30];
int phoneOfCustomer;
char prodType[20];
char productBrand[10];
double productPrice;
char productSize[15];
double sellsmanPrice;
double totalPrice=0,haveTopay=0;
string ret_sellsName();
string sellsmanName;

string s="----------------Welcome to CSE_16 Electronics------------------\n\n";
string s1=" \n    Brand----|----type/size-----|----- price------quantity \n\n";
string date;
int ret_day();
int ret_month();
int password();
void gotoxy(int x,int y);
void drawRectangle();
int password();
int ret_sellsman();

class sellsman{
 public:
    void show_sellsman_menu();
    void save_sellstosellsMant();
    void show_selltodaySellsM();


};
void sellsman::show_sellsman_menu()
{
    cout<<"\n01. Rakib\n";
    cout<<"\n02. Rimon\n";
    cout<<"\n03. Alvi\n";
    cout<<"\n04. Arif\n";
}

class product{
  public:
      int day;
      int month;
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
    void dateWiseSell();
    void showDateWiseSell(int d,int m);
    void showSellsManWise(int n);
    void show_oneProduct();
    void update_product(int n,int s);
    int product_upMenu();
    void save_sellsmansell(int n);
    void quantityminus(int n,int s);


    void getInvoiceProduct();
    void showtp();
     product(){
     productSerial=0;
     price=0;
     quantity=0;
     }};
void product::quantityminus(int n,int s)
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

                quantity=(quantity-1);
                a=file.tellp();
                b=sizeof(*this);

                file.seekp(a-b);
                file.write((char*)this,sizeof(*this));

            }file.read((char*)this,sizeof(*this));}
            file.close();}
    }
void product::showSellsManWise(int n)
{
    ifstream file;
    switch(n){
    case 1:
     file.open("Rakib.txt",ios::out|ios::in);
     break;
  case 2:
    file.open("Rimon.txt",ios::out|ios::in);
    break;
 case 3:
     file.open("Alvi.txt",ios::out|ios::in);
     break;
 default:
    file.open("Arif.txt",ios::out|ios::in);
    break;
    }
    file.read((char *)this,sizeof(*this));
    while(!file.eof()){
            sellsmanPrice+=price;
        cout<<brand<<setw(10)<<sizeOrType<<setw(10)<<price<<endl;
        file.read((char *)this,sizeof(*this));

    }
    cout<<"=====================TOTAL SELL :"<<sellsmanPrice<<endl;

}
void product::save_sellsmansell(int n)
{   ofstream file;
    switch (n){
 case 1:
    file.open("Rakib.txt",ios::app|ios::in);
    break;
 case 2:
    file.open("Rimon.txt",ios::app|ios::in);
    break;
 case 3:
    file.open("Alvi.txt",ios::app|ios::in);
    break;
 default:
    file.open("Arif.txt",ios::app|ios::in);
    break;
    }
 file.write((char *)this,sizeof(*this));
 file.close();
}
void product::showDateWiseSell(int n,int m)
{ ifstream file;
file.open("datewisesell.txt",ios::in|ios::out|ios::app);
if(!file.is_open()){cout<<"file is not opened";}
else {file.read((char*)this,sizeof(*this));
      while(!file.eof()){
        if(month==m&&day==n){show_oneProduct();
        file.read((char*)this,sizeof(*this));}
}}}
void product::dateWiseSell()
{
  ofstream file;
  file.open("datewisesell.txt",ios::in|ios::out|ios::app);
  if(!file.is_open()){cout<<"file is not opened";}
  else{
    file.write((char *)this,sizeof(*this));
    file.close();
  }

}
int product::search_product(int a, int b)
{
 int typ=a;
 int id=b;
    ifstream file;
    switch (a){
case 1:
    strcpy(prodType,"TV                ");
     file.open("Product_tv.txt",ios::out|ios::binary|ios::app);

     break;
     case 2:
     file.open("Product_fridge.txt",ios::out|ios::binary|ios::app);
     strcpy(prodType,"FRIDGE            ");
     break;
     case 3:
         file.open("Product_oven.txt",ios::out|ios::binary|ios::app);
         strcpy(prodType,"OVEN           ");
         break;
     case 4:
        file.open("Product_air.txt",ios::out|ios::binary|ios::app);
        strcpy(prodType,"WASHING MACHINE");
        break;
     case 5:
        file.open("Product_washing.txt",ios::out|ios::binary|ios::app);
        strcpy(prodType,"AIR CONDITIONER");
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

void product::getInvoiceProduct()
{
    strcpy(productBrand,brand);
    strcpy(productSize,sizeOrType);
    productPrice=price;
    totalPrice+=productPrice;
    ofstream file;
    file.open("maininvoice.txt",ios::out|ios::in|ios::app);
    if(!file.is_open()){cout<<"file is not opened";}
    else
    {
     file<<prodType<<setw(18)<<productBrand<<setw(20)<<productSize<<setw(20)<<productPrice<<endl;
    }
    file.close();
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
     file.open("Product_tv.txt",ios::out|ios::binary|ios::app);
     break;
     case 2:
     file.open("Product_fridge.txt",ios::out|ios::binary|ios::app);
     break;
     case 3:
         file.open("Product_oven.txt",ios::out|ios::binary|ios::app);
         break;
     case 4:
        file.open("Product_air.txt",ios::out|ios::binary|ios::app);
        break;
     case 5:
        file.open("Product_washing.txt",ios::out|ios::binary|ios::app);
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
         month=ret_month();
         day=ret_day();
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
 cout<<"1.ADD new product\n2.Update older product\n"<<endl;
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
    char customerAdress[30];
    void get_customer();
    void show_One_customer();
    void show_All_customer();
    void search_customer(int number);
    int delete_customer(int n);

    void ret_date();
    void print_invoice();
    void show_customerMmenu();
    void save_customertofile();
    void show_customerOne();
    void edit_customer(int n);
    void get_invoiceCustomer();

    };
void customer::get_invoiceCustomer()
{    int d,m;

     d=ret_day();
     m=ret_month();
    strcpy(nameOfCustomer,customerName);
    strcpy(addressOfCustomer,customerAdress);
    phoneOfCustomer=phoneNumber;
    ofstream file;
    ifstream fileread;
    string line;
    file.open("invoice.txt",ios::in|ios::app|ios::out);
    if(!file.is_open()){cout<<"not opened file";}
    else{fileread.open("maininvoice.txt",ios::in|ios::out);

        file<<"customer invoice"<<endl;
        file<<s;
        file<<endl;
        file<<"================================="<<endl;
        file<<d<<"/"<<m<<"/2017"<<endl;
        file<<"CUSTOMER INFO: "<<endl<<endl;

        file<<"PHONE NUMBER: "<<phoneOfCustomer<<endl;
        file<<"NAME        : "<<nameOfCustomer<<endl;
        file<<"ADDRESS     : "<<addressOfCustomer<<endl<<endl;

        file<<"\nType-------"<<"-------------Brand------"<<"-------size----"<<"-------price---"<<endl<<endl;
        while(!fileread.eof()){
        getline(fileread,line);
        file<<line<<endl;
        }
        file<<"TOTAL PRICE : "<<totalPrice<<"                   sign of sellsman"<<endl;
        file<<endl;file<<setw(60)<<sellsmanName<<endl;
        file<<"==================THANK YOU===============";

        }
        fileread.close();
    file.close();

}
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
{
  bool found=false;
  ifstream file;
  file.open("customerbin.txt",ios::out|ios::in|ios::binary);
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
     if(found==false){cout<<"file not found";}
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
{    gotoxy(10,20);
    cout<<"\n\n01.Register new customer\n     02.Search customer\n     03.Delete a customer\n     04.Edit a customer\n     05.View full customer list\n";}



void customer::show_customerOne()
{
    cout<<"\nPhone number: "<<phoneNumber;
    cout<<"\nCustomer Name: "<<customerName;
    cout<<"\nAddress: "<<customerAdress;
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

    cin.getline(customerAdress,30);

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

    file<<"\n---selled by "<<sellsmanName<<endl;
    file<<"-----------------------sign----"<<endl;
    file<<"-----------------Sabir Sir---"<<endl;
    file<<"-----------THANK YOU_______"<<endl;
    file.close();
    system("NOTEPAD /p CSE__16 Electronics shop");}
}





class invoice:public customer,public product{
    public:
    void save_invoice();
    void show_invoice();
};
void invoice::show_invoice()
{
    cout<<"===================CSE_16====================\n";
  ret_date();
  cout<<"\nCustomer Phone:"<<phoneNumber<<endl;
  cout<<"Cusomer Name: "<<customerName<<endl;
  cout<<"Customer Adress :"<<customerAdress<<endl;
  cout<<s1;
  cout<<brand<<setw(10)<<sizeOrType<<setw(10)<<price<<endl;
  cout<<" TOTAL PRICE: "<<totalPrice;

  cout<<"\nsell by :-----"<<sellsmanName<<endl;
  cout<<"sign\n-----\n";
  cout<<"===============thank you============";

}

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
{           cout<<s<<"\n\n      what do you want to do?\n\n      1. Sell Product\n      2. Update Product\n      3. Search Date wise sells\n      4. Show all products\n      5. Customer Management\n      7. Authority\n\n";
            cin>>choice;
            system("cls");
            cout<<s;
            return choice;
}
int main()
{   password();
    system("cls");
    gotoxy(45,2);
    sellsmanName=ret_sellsName();
    cout<<"sells Man:"<<ret_sellsName()<<endl;
    system("color FC");
    product p;
    MainMenu m;
    sellsman s;
    customer c;
    invoice i;
    gotoxy(30,1);
    i.ret_date();
    drawRectangle();
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
      p.quantityminus(choice2,choice6);
     if(choice1==1)
     { p.getInvoiceProduct();
       p.dateWiseSell();
       p.save_sellsmansell(ret_sellsman());

        cout<<"DO YOU buy More?\n1.Yes    2.No\n";
        cin>>choice5;
       switch(choice5){
        case 1:
        goto mainmenu;
        break;
        case 2:
        break;}
       cout<<"\nAre you a Registered Customer?\n\n01.Yes    02. NO\n";
       cin>>choice5;
       if(choice5==1){cout<<"Enter your Phone Number: ";
         cin>>choice6;
         system("cls");
         c.search_customer(choice6);
         totalPrice=(totalPrice-(totalPrice*(0.02)));
         c.get_invoiceCustomer();
         system("NOTEPAD /p invoice.txt");
         remove("maininvoice.txt");
         remove("Invoice.txt");
         goto mmenu;}
         else{c.get_customer();
         c.get_invoiceCustomer();
         system("NOTEPAD /p invoice.txt");
         remove("invoice.txt");
         remove("maininvoice.txt");
        }

       system("cls");
       goto mmenu;
}}

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
    cout<<"Enter the date:"<<endl;
    cout<<"DD MM\n";
    cin>>choice2;
    cin>>choice3;
    p.showDateWiseSell(choice2,choice3);

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
    cout<<"\n  Main menu? press :1\n\n";
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
        }
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
    break;
case 6:
    break;
case 7:
   s.show_sellsman_menu();
    cin>>choice6;
    p.showSellsManWise(choice6);



    }

}
COORD coord = {0,0};
void gotoxy(int x, int y){
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int ret_day()
{
 int day;
 time_t d= time(0);
 tm *dt=localtime(&d);
 day=dt->tm_mday;
 return day;
}
int ret_month()
{
    int month;
    time_t d=time(0);
    tm *dt=localtime(&d);
    month=1+dt->tm_mon;
    return month;
}
void drawRectangle(){
    int i, j;
    gotoxy(0,0);
    printf("%c",201);
    for(i = 1; i < 78; i++){
        gotoxy(i, 0);
        printf("%c",205);
    }
    gotoxy(78,0);
    printf("%c",187);
    for(i = 1; i < 25; i++){
        gotoxy(78, i);
        if(i == 6){
            printf("%c",185);
        }else{
            printf("%c",186);
        }
    }

    gotoxy(0,25);
    printf("%c",200);
    for(i = 20; i > 0; i--){
        gotoxy(0,i);
        if(i == 6){
            printf("%c",204);
        }else{
            printf("%c",186);
        }
    }

    for(i = 1; i < 78; i++){
        gotoxy(i,6);
        if(i == 35){
            printf("%c",203);
        }else{
            printf("%c",205);
        }
    }

    for(i = 7; i < 5; i++){
        gotoxy(35,i);
        printf("%c",186);
    }

} int password()
 {   agn:
     cout<<"Do you want to log in"<<endl;
     string pass ="";
    string pass1 ="";
   char ch,ch1;
    cout << "Enter name:\n";
    ch = _getch();
    while(ch != 13){//character 13 is enter
       pass.push_back(ch);
       cout << '*';
      ch = _getch();
    }
    if(pass == "Alvi"|| pass=="Rimon" || pass=="Rakib" ||pass=="Arif"){
         cout<<"\nEnter password:"<<endl;
         ch1 = _getch();
    while(ch1 != 13){
       pass1.push_back(ch1);
       cout << '*';
       ch1 = _getch();
    }
       if(pass1=="1604059" || pass1=="1604060" || pass1=="1604061"|| pass1=="1604055"){
            if(pass=="Rakib"){rakib=true;}
          else if(pass=="Rimon"){rimon=true;}
          else if(pass=="Arif"){arif=true;}
          else if(pass=="Alvi"){alvi=true;}
       cout << "\nAccess granted :P\n";
       }


       else{
       cout<<"\nAccess aborted...\n";
       goto agn;}
    }else{
       cout << "\nAccess aborted...\n";
       goto agn;
    }
 }
 int ret_sellsman(){
 if(rakib==true)
    return 1;
 else if(rimon==true)
    return 2;
 else if(alvi==true)
    return 3;
 else
    return 4;
 }
string ret_sellsName(){
    if(rakib==true)
    return "Rakib";
 else if(rimon==true)
    return "Rimon";
 else if(alvi==true)
    return "ALVI";
 else
    return "ARIF";
}


