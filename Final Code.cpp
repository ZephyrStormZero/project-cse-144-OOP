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
#include<stdio.h>
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
bool registered=false;
string s="---------------Welcome to CSE_16 Electronics----------------\n\n";
string s1=" \n    Brand-----|-----type/size-----|------price------quantity \n\n";
string date;
//
//global functions to perform specific tasks
int ret_day();
int ret_month();
int password();
void SetColor(int n);
void gotoxy(int x,int y);
void drawRectangle();
int password();
int ret_sellsman();

class sellsman  //class for salesman
{
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

class product //class for products and related functions
{
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
    product()
    {   day=ret_day();
        month=ret_month();
        productSerial=0;
        price=0;
        quantity=0;
    }
};
void product::quantityminus(int n,int s) //function to reduce quantity of products
{
    int num=n;
    int serial=s;
    int a,b;
    fstream file;
    switch (num)
    {
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
    if(!file.is_open())
    {
        cout<<"file is not open \n";
    }
    else
    {
        file.read((char*)this,sizeof(*this));
        while(!file.eof())
        {
            if(productSerial==serial)
            {
                quantity=(quantity-1);
                if(quantity<=0){cout<<"NO stock of this product\nupdate please\n\n";
                }
                a=file.tellp();
                b=sizeof(*this);
                file.seekp(a-b);
                file.write((char*)this,sizeof(*this));
            }
            file.read((char*)this,sizeof(*this));
        }
        file.close();
    }
}
void product::showSellsManWise(int n) //function to show which salesman sold how many products
{
    ifstream file;
    switch(n)
    {
    case 1:
        file.open("Rakib.txt",ios::out|ios::app|ios::in);
        break;
    case 2:
        file.open("Rimon.txt",ios::out|ios::app|ios::in);
        break;
    case 3:
        file.open("Alvi.txt",ios::out|ios::app|ios::in);
        break;
    default:
        file.open("Arif.txt",ios::out|ios::app|ios::in);
        break;
    }
    file.read((char *)this,sizeof(*this));
    while(!file.eof())
    {
        sellsmanPrice+=price;
        cout<<prodType<<setw(10)<<brand<<setw(10)<<sizeOrType<<setw(10)<<price<<endl;
        file.read((char *)this,sizeof(*this));
    }
    cout<<"=====================TOTAL SELL :"<<sellsmanPrice<<endl;
}
void product::save_sellsmansell(int n)
{
    ofstream file;
    switch (n)
    {
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
void product::showDateWiseSell(int n,int m) //function to show the dates on which the products were sold
{
    ifstream file;
    file.open("datewisesell.txt",ios::in|ios::out|ios::app);
    if(!file.is_open())
    {
        cout<<"file is not opened";
    }
    else
    {
        file.read((char*)this,sizeof(*this));
        while(!file.eof())
        {
            if(month==m&&day==n)
            {
                show_oneProduct();
                file.read((char*)this,sizeof(*this));
            }
        }
    }
}
void product::dateWiseSell() //file to write date of products sell
{
    ofstream file;
    file.open("datewisesell.txt",ios::in|ios::out|ios::app);
    if(!file.is_open())
    {
        cout<<"file is not opened";
    }
    else
    {
        file.write((char *)this,sizeof(*this));
        file.close();
    }
}
int product::search_product(int a, int b) //function to search product
{
    int typ=a;
    int id=b;
    ifstream file;
    switch (a)
    {
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
        break;
    }
    if(!file.is_open())
    {
        cout<<"FILE NOT OPENED";
    }
    else
    {
        file.read((char*)this,sizeof(*this));
        while(!file.eof())
        {
            if(productSerial==b)
            {
                return 1;
            }
            file.read((char*)this,sizeof(*this));
        }
    }
}
void product::getInvoiceProduct() //function to get invoice
{
    strcpy(productBrand,brand);
    strcpy(productSize,sizeOrType);
    productPrice=price;
    totalPrice+=productPrice;
    ofstream file;
    file.open("maininvoice.txt",ios::out|ios::in|ios::app);
    if(!file.is_open())
    {
        cout<<"file is not opened";
    }
    else
    {
        file<<prodType<<setw(18)<<productBrand<<setw(20)<<productSize<<setw(20)<<productPrice<<endl;
    }
    file.close();
}

void product::showtp() //show product type
{
    cout<<"1. Tv"<<endl;
    cout<<"2. Fridge"<<endl;
    cout<<"3. Oven"<<endl;
    cout<<"4. Washing Machine"<<endl;
    cout<<"5. Air Conditioner\n"<<endl;
}

void product::get_Product() //get new product
{
    cout<<"Enter these fields\n\n";
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

int product::show_ALLproducts(int n) //show all products together
{
    ifstream file;
    switch (n)
    {
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
    if(!file.is_open())
    {
        cout<<"NO PRODUCTS FILE FOUND!\n";
    }
    while(!file.eof())
    {
        show_oneProduct();
        file.read((char *)this,sizeof(*this));
    }
    return 0;
}

void product::show_oneProduct() //show serial wise product
{
    cout<<productSerial<<"."<<brand<<setw(8)<<"|"<<setw(9)<<sizeOrType<<setw(9)<<"|"<<setw(9)<<price<<"$"<<setw(7)<<"|"<<quantity<<endl;
}

void product::save_productTofile(int n)//to save a product data to file.
{
    ofstream fil;
    switch(n)
    {
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
    }
    if(!fil.is_open())
    {
        cout<<"product file is not opend"<<endl;
    }
    else
    {
        get_Product();
        month=ret_month();
        day=ret_day();
        if(productSerial==0&&price==0&&quantity==0)
        {
            cout<<"no file Added ,put a real product values!!!"<<endl;
        }
        else
        {
            fil.write((char*)this,sizeof(*this));
            cout<<"NEW prodcut ADDED!"<<endl;
            fil.close();
            system("cls");
        }
    }
}

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
    switch (num)
    {
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
    if(!file.is_open())
    {
        cout<<"file is not open \n";
    }
    else
    {
        file.read((char*)this,sizeof(*this));
        while(!file.eof())
        {
            if(productSerial==serial)
            {
                get_Product();
                a=file.tellp();
                b=sizeof(*this);
                file.seekp(a-b);
                file.write((char*)this,sizeof(*this));
            }
            file.read((char*)this,sizeof(*this));
        }
        file.close();
    }
}
class customer //class to keep customer records
{
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

void customer::get_invoiceCustomer() //function to get invoice
{
    int d,m;
    d=ret_day();
    m=ret_month();
    strcpy(nameOfCustomer,customerName);
    strcpy(addressOfCustomer,customerAdress);
    phoneOfCustomer=phoneNumber;
    ofstream file;
    ifstream fileread;
    string line;
    file.open("invoice.txt",ios::in|ios::app|ios::out);
    if(!file.is_open())
    {
        cout<<"not opened file";
    }
    else
    {
        fileread.open("maininvoice.txt",ios::in|ios::out);
        file<<"customer invoice"<<endl;
        file<<s;
        file<<endl;
        file<<"================================="<<endl;
        file<<d<<"/"<<m<<"/2017"<<endl;
        file<<"CUSTOMER INFO: "<<endl<<endl;
        if(registered==true)
            {
                file<<"Registered Customer\n";
            }
        file<<"PHONE NUMBER: +880"<<phoneOfCustomer<<endl;
        file<<"NAME        : "<<nameOfCustomer<<endl;
        file<<"ADDRESS     : "<<addressOfCustomer<<endl<<endl;
        file<<"\nType-------"<<"-------------Brand------"<<"-------size----"<<"-------price---"<<endl<<endl;
        while(!fileread.eof())
        {
            getline(fileread,line);
            file<<line<<endl;
        }
        file<<"TOTAL PRICE : "<<totalPrice<<endl;
        if(registered==true)
            {
                file<<"discout= 2%\n";
                file<<"To Pay= "<<haveTopay<<endl;
            }
        file<<"                                             sign of sellsman"<<endl;
        file<<setw(55)<<sellsmanName<<endl;
        file<<"==================THANK YOU===============";
    }
    fileread.close();
    file.close();
}
void customer::edit_customer(int n) //function to edit customer
{
    int a;
    int b;
    fstream file;
    file.open("customerbin.txt",ios::in|ios::binary|ios::out|ios::ate);
    file.seekg(0);
    if(!file.is_open())
    {
        cout<<"file is not open \n";
    }
    else
    {
        file.read((char*)this,sizeof(*this));
        while(!file.eof())
        {
            if(phoneNumber==n)
            {
                get_customer();
                a=file.tellp();
                b=sizeof(*this);
                file.seekp(a-b);
                file.write((char*)this,sizeof(*this));
            }
            file.read((char*)this,sizeof(*this));
        }
        file.close();
    }
}
void customer::show_All_customer() //function to show all customer
{
    ifstream file;
    file.open("customerbin.txt",ios::out|ios::binary|ios::app);
    if(!file.is_open())
    {
        cout<<"FILE IS NOT OPEND!!\n";
    }
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
        show_customerOne();
        cout<<endl<<endl;
        file.read((char *)this,sizeof(*this));
    }
    file.close();
    cout<<"\nthats all;;\n";
}
int customer::delete_customer(int n)
{
    ifstream fin;
    ofstream fout;
    fin.open("customerbin.txt",ios::in|ios::binary|ios::app);
    if(!fin.is_open())
    {
        cout<<"file is not opened ";
        return 0;
    }
    else
    {
        fout.open("customertemp.txt",ios::out|ios::binary);
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(phoneNumber!=n)
            {
                fout.write((char *)this,sizeof(*this));
            }
            fin.read((char *)this,sizeof(*this));
        }
    }
    fin.close();
    fout.close();
    remove("customerbin.txt");
    rename("customertemp.txt","customerbin.txt");
    cout<<"deleted!!!"<<endl;
}

void customer::search_customer(int number) //search customer function
{
    bool found=false;
    ifstream file;
    file.open("customerbin.txt",ios::out|ios::in|ios::binary);
    if(!file.is_open())
    {
        cout<<"file not opened";
    }
    else
    {
        file.read((char*)this,sizeof(*this));
        while(!file.eof())
        {
            if(phoneNumber==number)
            {
                show_customerOne();
                found=true;
            }
            file.read((char*)this,sizeof(*this));
        }
        if(found==false)
        {
            cout<<"file not found";
        }
    }
}

void customer::save_customertofile()
{
    ofstream file;
    file.open("customerbin.txt",ios::app);
    if(!file.is_open())
    {
        "customer file not opened";
    }
    else
    {
        get_customer();
        file.write((char *)this,sizeof(*this));
        cout<<"New customer added!!!\n";
        file.close();
    }
}
void customer::show_customerMmenu()
{
    cout<<"\n\n     01.Register new customer\n     02.Search customer\n     03.Delete a customer\n     04.Edit a customer\n     05.View full customer list\n";
}

void customer::show_customerOne()
{
    cout<<"\nPhone number: "<<phoneNumber;
    cout<<"\nCustomer Name: "<<customerName;
    cout<<"\nAddress: "<<customerAdress;
}
void customer::get_customer() //function to get info of customer
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
void customer::print_invoice() //function to print invoice
{
    string line;
    fstream file;
    file.open("CSE__16.txt",ios::in|ios::out|ios::trunc);
    if(!file.is_open())
    {
        cout<<" not inovoicE open";
    }
    else
    {
        getline(file,line);
        cout<<line;
        file<<s1;
        file<<"\n---selled by "<<sellsmanName<<endl;
        file<<"-----------------------sign----"<<endl;
        file<<"-----------------Sabir Sir---"<<endl;
        file<<"-----------THANK YOU_______"<<endl;
        file.close();
        system("NOTEPAD /p CSE__16 Electronics shop");
    }
}
void customer::ret_date() //function for date
{
    int year,month,day;
    time_t d= time(0);
    tm *dt=localtime(&d);
    year=1900+dt->tm_year;
    month=1+dt->tm_mon;
    day=dt->tm_mday;
    cout<<day<<"/"<<month<<"/"<<year;
}

class MainMenu //class for main menu screen
{
public:
    int dispmm();
};
int MainMenu::dispmm()
{
    gotoxy(8,8);
    cout<<"what do you want to do?";
    gotoxy(8,11);
    cout<<"01. Sell Product";
    gotoxy(8,12);
    cout<<"02. Update Product";
    gotoxy(8,13);
    cout<<"03. Sales Today";
    gotoxy(8,14);
    cout<<"04. Show all products";
    gotoxy(8,15);
    cout<<"05. Customer Management";
    gotoxy(8,16);
    cout<<"06. Sellsman Sells";
    gotoxy(8,17);
    cout<<"07. Logout";
    gotoxy(8,18);
    cin>>choice;
    system("cls");
    return choice;
}

COORD coord = {0,0}; //set coordinate of main screen
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int ret_day() //get day from system
{
    int day;
    time_t d= time(0);
    tm *dt=localtime(&d);
    day=dt->tm_mday;
    return day;
}
int ret_month() //get month from system
{
    int month;
    time_t d=time(0);
    tm *dt=localtime(&d);
    month=1+dt->tm_mon;
    return month;
}
void drawRectangle() //design main menu screen
{
    int i, j;
    gotoxy(20,2);
    cout<<"---WELCOME TO CSE_16 ELECTRONICS---";
    gotoxy(16,3);
    cout<<"CHITTAGONG UNIVERSITY OF ENGINEERING & TECHNOLOGY";
    gotoxy(16,5);
    SetColor(35);
    cout<<"Developed by :RIMON,RAKIB,ALVI,ARIF ";
    gotoxy(0,0);
    printf("%c",201);
    for(i = 1; i < 78; i++)
    {
        gotoxy(i, 0);
        printf("%c",205);
    }
    gotoxy(78,0);
    printf("%c",187);
    for(i = 1; i <=22; i++)
    {
        gotoxy(78, i);
        if(i==5) {}
        else if(i == 6)
        {
            printf("%c",185);
        }
        if(i==22)
            printf("%c",188);
        else
        {
            printf("%c",186);
        }
    }
    gotoxy(0,22);
    printf("%c",200);
    for(i = 21; i > 0; i--)
    {
        gotoxy(0,i);
        if(i == 6)
        {
            printf("%c",204);
        }
        else
        {
            printf("%c",186);
        }
    }
    for(i = 1; i < 78; i++)
    {
        gotoxy(i,6);
        printf("%c",205);
    }
    for(i=1; i<78; i++)
    {
        gotoxy(i,22);
        printf("%c",205);
    }
}

int password() //function for password
{
agn:
    cout<<"Do you want to log in"<<endl;
    string pass ="";
    string pass1 ="";
    char ch,ch1;
    cout<<"Enter name:\n";
    ch=_getch();
    while(ch!=13) //character 13 is enter
    {
        pass.push_back(ch);
        cout<<ch;
        ch=_getch();
    }
    if(pass=="Alvi"||pass=="Rimon"||pass=="Rakib"||pass=="Arif")
    {
        cout<<"\nEnter password:"<<endl;
        ch1=_getch();
        while(ch1!=13)
        {
            pass1.push_back(ch1);
            cout<<'*';
            ch1=_getch();
        }
        if(pass1=="1604059"||pass1=="1604060"||pass1=="1604061"||pass1=="1604055")
        {
            if(pass=="Rakib")
            {
                rakib=true;
            }
            else if(pass=="Rimon")
            {
                rimon=true;
            }
            else if(pass=="Arif")
            {
                arif=true;
            }
            else if(pass=="Alvi")
            {
                alvi=true;
            }
            cout << "\nAccess granted :P\n";
        }
        else
        {
            cout<<"\nAccess aborted...\n";
            goto agn;
        }
    }
    else
    {
        cout << "\nAccess aborted...\n";
        goto agn;
    }
}

int ret_sellsman() //get name of salesman
{
    if(rakib==true)
        return 1;
    else if(rimon==true)
        return 2;
    else if(alvi==true)
        return 3;
    else
        return 4;
}

string ret_sellsName()
{
    if(rakib==true)
        return "Rakib";
    else if(rimon==true)
        return "Rimon";
    else if(alvi==true)
        return "ALVI";
    else
        return "ARIF";
}

void SetColor(int n) //function for colors of console
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (n& 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

int main()
{
    system("color FC"); //change console color
    password();         //get password
    system("cls");
    sellsmanName=ret_sellsName();
    product p;          //creating object for all classes
    MainMenu m;
    sellsman s;
    customer c;
    gotoxy(30,1);
    mmenu:
    gotoxy(50,7);
    cout<<"sells Man: MR, "<<ret_sellsName()<<endl;
    drawRectangle();    //design main menu
    choice=m.dispmm();  //Main Menu choice list
    switch(choice)
    {
    case 1:
    mainmenu:
        remove("maininvioce.txt");//to remove any incomplete invoice
        p.showtp();//to show the type of available products
        cin>>choice2;
        cout<<s1;
        choice3=p.show_ALLproducts(choice2); //to show all available products under a type
        if(choice3==1)
        {
            goto mainmenu;
        }
        else if(choice3==0)
        {
            cin>>choice6;//select perticular product
            choice1=p.search_product(choice2,choice6);//to read the object of product
            p.quantityminus(choice2,choice6);
            if(choice1==1)
            {
                p.getInvoiceProduct();  //get product to print invoice, temporary file.
                p.dateWiseSell();
                p.save_sellsmansell(ret_sellsman());
                cout<<"Do you want to buy More?\n1.Yes    2.No\n";
                cin>>choice5;
                system("cls");
                switch(choice5)
                {
                case 1:
                    goto mainmenu;
                    break;
                case 2:
                    break;
                }
                system("cls");
                cout<<"\nAre you a Registered Customer?\n\n01.Yes    02. NO\n";
                cin>>choice5;
                if(choice5==1)
                {
                    cout<<"Enter your Phone Number: ";
                    cin>>choice6;
                    system("cls");
                    c.search_customer(choice6);
                    haveTopay=(totalPrice-(totalPrice*(0.02)));
                    registered=true;
                    c.get_invoiceCustomer();
                    system("NOTEPAD /p invoice.txt");
                    remove("maininvoice.txt");
                    remove("Invoice.txt");
                    goto mmenu;
                }
                else
                {
                    c.get_customer();
                    c.get_invoiceCustomer();//save customer data to invoice
                    system("NOTEPAD /p invoice.txt");//print  a text file
                    remove("invoice.txt");
                    remove("maininvoice.txt");
                }
                system("cls");
                goto mmenu;
            }
        }
        break;

    case 2:
        p.product_upMenu();
        cin>>choice1;
        if(choice1==1)
        {
            cout<<"Which type of Product YOU want to add?\n\n";
            p.showtp();
            cin>>choice2;
            system("cls");
            p.save_productTofile(choice2);
            system("cls");
            goto mmenu;
        }
        else if(choice==2)
        {
            cout<<"which product you want to update?\n";
            p.showtp();
            cin>>choice2;
            system("cls");
            choice4=p.show_ALLproducts(choice2);//show all products under a catagory
            if(choice4==1)
            {
                goto mainmenu;
            }
            cout<<"ENTER serial no to update:"<<endl;
            cin>>choice5;
            p.update_product(choice2,choice5);
        }
        break;

    case 3:
        p.showDateWiseSell(ret_day(),ret_month());//show all products under date
        cout<<"\n1.mainmenu";
        cin>>choice5;
        system("cls");
        if(choice5==1)
            goto mmenu;
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
        switch(choice3)
        {
        case 1:
            system("cls");
            goto mmenu;
            break;
        default:
            break;
        }
        break;
    case 5:
        c.show_customerMmenu();
        cin>>choice4;
        if(choice4==1)
        {
            reg:
            system("cls");
            c.save_customertofile();
            cout<<"\n1.register more  2.mainmenu\n";
            cin>>choice5;
            system("cls");
            if(choice5==1)
                goto reg;
            else
                goto mmenu;
        }
        else if (choice4==2)
        {
            sear:
            system("cls");
            cout<<"\nENTER PHONE NUMBER TO SEARCH\n";
            cout<<"PHONE NUMBER: \n";
            cin>>choice5;
            system("cls");
            c.search_customer(choice5);
            cout<<"\n1.search again  2.mainmenu\n";
            cin>>choice5;
            system("cls");
            if(choice5==1)
                goto sear;
            else
                goto mmenu;
        }
        else if(choice4==3)
        {
            del:
            system("cls");
            cout<<"enter phone number:\n";
            cin>>choice3;
            choice5=c.delete_customer(choice3);
            if(choice5==0)
            {
                goto mmenu;
            }
            cout<<"1.delete more  2.mainmenu\n";
            cin>>choice5;
            system("cls");
            if(choice5==1)
                goto del;
            else
                goto mmenu;
        }
        else if(choice4==5)
        {
            c.show_All_customer();
            cout<<"1.mainmemu";
            cin>>choice5;
            system("cls");
            if(choice5==1)
                goto mmenu;
        }
        else if(choice4==4)
        {
            edit:
            system("cls");
            cout<<"ENTER PHONE NUMBER TO EDIT CUSTOMER:\n";
            cin>>choice5;
            c.edit_customer(choice5);
            cout<<"successfully edited!! :D\n";
            cout<<"\n 1.edit more  2. mainmenu\n";
            cin>>choice5;
            system("cls");
            if(choice5==1)
                goto edit;
            if(choice5==2)
                goto mmenu;
        }
        break;

    case 6:
        {
        sells:
        s.show_sellsman_menu();
        cin>>choice6;
        p.showSellsManWise(choice6);
        cout<<"\n1.check more 2.mainmenu\n";
        cin>>choice5;
        system("cls");
        if(choice5==1)
            goto sells;
        else
            goto mmenu;
        }
        break;
    case 7:
        {
            password();
            system("cls");
            goto mmenu;
        }
        break;
    }
    return 0;
}

