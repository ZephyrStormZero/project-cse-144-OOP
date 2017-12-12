#include <iostream>
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
using namespace std;

string s="-------------------------Welcome to CSE_16 Electronics-------------------------\n\n";
string s1="",s2="",s3="",s4="",s5="",s6="",s7="",s8="",s9="",s10="",s11="",s12="",s13="",st1="",st2="",st3="",sf1="",sf2="",sf3="",so1="",so2="",swm1="",swm2="",sac1="",sac2="",sac3="";
int choose,choose1;
bool regularCustomer=false;
double total=0, alltotal=0,haveToPay=0;
int pt1=15,pt2=15,pt3=15,pf1=15,pf2=15,pf3=15,po1=15,po2=15,pw1=15,pw2=15,pa1=15,pa2=15,pa3=15;

class mainmenu
{
    int choice;
public:
   int password()
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
   if(pass == "Alvi"|| pass=="Rimon" || pass=="Rakib" ||pass=="Sabir"){
        cout<<"\nEnter password:"<<endl;
        ch1 = _getch();
   while(ch1 != 13){
      pass1.push_back(ch1);
      cout << '*';
      ch1 = _getch();
   }
      if(pass1=="1604059" || pass1=="1604060" || pass1=="1604061"|| pass1=="1604055")
      cout << "\nAccess granted :P\n";
      else{
      cout<<"\nAccess aborted...\n";
      goto agn;}
   }else{
      cout << "\nAccess aborted...\n";
      goto agn;
   }
}

    int dispmm()
    {
            cout<<s<<"what do you want to do?\n1. Sell Product\n2. Update Product\n3. total sales today\n4. search product\n5.Customer Management\n";
            cin>>choice;
            system("cls");
            cout<<s;
            return choice;
    }
    void totalsales(){cout<<"TOTAL SALE TODAY: "<<alltotal<<endl;}
};

class update
{
public:
    int ch(){cout<<"1.check stock  2.add stock\n";
    cin>>choose;
    system("cls");
    return choose;}

    void showallpro()
    {cout<<"product type            Brand               type/size               price       \n";
    cout<<"1.TV                     Sony                  52 inches            65000   \n";
    cout<<"2.TV                     LG                    42 inches            45000   \n";
    cout<<"3.TV                     Phillips              32 inches            30000   \n";
    cout<<"4.Fridge                 Samsung               360 Litre            45000   \n";
    cout<<"5.Fridge                 LG                    270 Litre            37000   \n";
    cout<<"6.Fridge                 Ariston               165 litre            28000   \n";
    cout<<"7.Oven                   Samsung               microwave            25000   \n";
    cout<<"8.Oven                   Nova                  electric             15000   \n";
    cout<<"9.Washing Machine        Whirlpool             180 Litre            50000   \n";
    cout<<"10.Washing Machine       LG                    120 Litre            35000   \n";
    cout<<"11.Air Conditioner       gree                  1.5 ton              45000   \n";
    cout<<"12.Air Conditioner       hayes                 2 ton                65000   \n";
    cout<<"13.Air Conditioner       singer                1 ton                35000   \n";
    }

    void showstock(int y)
    {
        if(y==1)
            cout<<"stock: "<<pt1;
        else if(y==2)
            cout<<"stock: "<<pt2;
        else if(y==3)
            cout<<"stock: "<<pt3;
        else if(y==4)
            cout<<"stock: "<<pf1;
        else if(y==5)
            cout<<"stock: "<<pf2;
        else if(y==6)
            cout<<"stock: "<<pf3;
        else if(y==7)
            cout<<"stock: "<<po1;
        else if(y==8)
            cout<<"stock: "<<po2;
        else if(y==9)
            cout<<"stock: "<<pw1;
        else if(y==10)
            cout<<"stock: "<<pw2;
        else if(y==11)
            cout<<"stock: "<<pa1;
        else if(y==12)
            cout<<"stock: "<<pa2;
        else if(y==13)
            cout<<"stock: "<<pa3;
        else
            cout<<"insert correct number";
    }

    void addstock(int z)
    {
        int x;
        cout<<"how many?\n";
        cin>>x;
        if(z==1){pt1+=x;cout<<"done!!\n";}
        else if(z==2){pt2+=x;cout<<"done!!\n";}
        else if(z==3){pt3+=x;cout<<"done!!\n";}
        else if(z==4){pf1+=x;cout<<"done!!\n";}
        else if(z==5){pf2+=x;cout<<"done!!\n";}
        else if(z==6){pf3+=x;cout<<"done!!\n";}
        else if(z==7){po1+=x;cout<<"done!!\n";}
        else if(z==8){po2+=x;cout<<"done!!\n";}
        else if(z==9){pw1+=x;cout<<"done!!\n";}
        else if(z==10){pw2+=x;cout<<"done!!\n";}
        else if(z==11){pa1+=x;cout<<"done!!\n";}
        else if(z==12){pa2+=x;cout<<"done!!\n";}
        else if(z==13){pa3+=x;cout<<"done!!\n";}
        else
            cout<<"insert correct number";
    }
};

class searchpr{
    int c1,c2,c3;
public:
    void searc()
    {
        cout<<"1.search by type  2.search by brand\n";
        cin>>c1; system("cls");
        if(c1==1)
        {cout<<s<<"insert type:\n1. TV\n2. Fridge\n3. Oven\n4. Washing Machine\n5. Air Conditioner\n6. Back\n";
            cin>>c2;
            system("cls");
            if(c2==1){
                cout<<s;
                cout<<" Brand                   Size                 Price   \n";
                cout<<"1. Sony                  52 inches            65000   \n";
                cout<<"2. LG                    42 inches            45000   \n";
                cout<<"3. Phillips              32 inches            30000   \n";}
            else if(c2==2){
                cout<<s;
                cout<<" Brand                   Size                 Price   \n";
                cout<<"1. Samsung               360 Litre            45000   \n";
                cout<<"2. LG                    270 Litre            37000   \n";
                cout<<"3. Ariston               165 litre            28000   \n";}
            else if(c2==3){
                cout<<s;
                cout<<" Brand                   type                 Price   \n";
                cout<<"1. Samsung               microwave            25000   \n";
                cout<<"2. Nova                  electric             15000   \n";}
            else if(c2==4){
                cout<<s;
                cout<<"available products";
                cout<<" Brand                   Size                 Price   \n";
                cout<<"1. Whirlpool             180 Litre            50000   \n";
                cout<<"2. LG                    120 Litre            35000   \n";}
            else if(c2==5){
                cout<<s;
                cout<<" Brand                   Size                 Price   \n";
                cout<<"1. gree                  1.5 ton              45000   \n";
                cout<<"2. hayes                 2 ton                65000   \n";
                cout<<"3. singer                1 ton                35000   \n";}
            else
                cout<<"insert correct number";
        }
        else if(c1==2)
        {
            cout<<s<<"insert brand\n1.Sony  2.LG  3.Phillips  4.Samsung  5.Ariston  6.Nova  7.Whirlpool  8.gree  9.hayes  10.singer\n";
            cin>>c3;
            system("cls");
            if(c3==1){
                cout<<s;
                cout<<" product type            Brand               type/size              price       \n";
                cout<<"1.TV                     Sony                  52 inches            65000    \n";}
            else if(c3==2){
                cout<<s;
                cout<<" product type            Brand               type/size              price       \n";
                cout<<"1.TV                     LG                    42 inches            45000   \n";
                cout<<"2.Fridge                 LG                    270 Litre            37000   \n";
                cout<<"3.Washing Machine        LG                    120 Litre            35000   \n";}
            else if(c3==3){
                cout<<s;
                cout<<" product type            Brand               type/size              price       \n";
                cout<<" TV                      Phillips              32 inches            30000   \n";}
            else if(c3==4){
                cout<<s;
                cout<<" product type            Brand               type/size              price       \n";
                cout<<"1.Fridge                 Samsung               360 Litre            45000   \n";
                cout<<"2.Oven                   Samsung               microwave            25000   \n";}
            else if(c3==5){
                cout<<s;
                cout<<" product type            Brand               type/size              price       \n";
                cout<<"1.Fridge                 Ariston               165 litre            28000   \n";}
            else if(c3==6){
                cout<<s;
                cout<<" product type            Brand               type/size              price       \n";
                cout<<"1.Oven                   Nova                  electric             15000   \n";}
            else if(c3==7){
                cout<<s;
                cout<<" product type            Brand               type/size              price       \n";
                cout<<"1. Washing Machine       Whirlpool             180 Litre            50000   \n";}
            else if(c3==8){
                cout<<s;
                cout<<" product type            Brand               type/size              price       \n";
                cout<<"1.Air Conditioner        gree                  1.5 ton              45000   \n";}
            else if(c3==9){
                cout<<s;
                cout<<" product type            Brand               type/size              price       \n";
                cout<<"1.Air Conditioner        hayes                 2 ton                65000   \n";}
            else if(c3==10){
                cout<<s;
                cout<<" product type            Brand               type/size               price       \n";
                cout<<"1.Air Conditioner        singer                1 ton                35000   \n";}
            else
                cout<<"insert correct number";
        }

    }
};

class products
{
    double p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13;
public:
    void showtp()
    {
        cout<<"what type of product do you want to buy?"<<endl;
        cout<<"1. TV\n2. Fridge\n3. Oven\n4. Washing Machine\n5. Air Conditioner\n6.Back"<<endl;
    }
    void choice(int a)
    {

        if(a==1)
        {

            cout<<"available products\n";
            cout<<" Brand                   Size                 Price   \n";
            cout<<"1. Sony                  52 inches            65000   \n";
            cout<<"2. LG                    42 inches            45000   \n";
            cout<<"3. Phillips              32 inches            30000   \n";
            cin>>choose;
            system("cls");
            if(choose==1)
            {
                st1="TV                     ";
                s1="Sony                  52 inches            65000   \n";
                p1=65000;
                total+=p1;
                pt1-=1;
            }
            else if(choose==2)
            {
                st2="TV                     ";
                s2="LG                    42 inches            45000   \n";
                p2=45000;
                total+=p2;
                pt2-=1;
            }
            else if(choose==3)
            {
                st3="TV                     ";
                s3="Phillips              32 inches            30000   \n";
                p3=30000;
                total+=p3;
                pt3-=1;
            }
        }
        else if(a==2)
        {

            cout<<"available products\n";
            cout<<" Brand                   Size                 Price   \n";
            cout<<"1. Samsung               360 Litre            45000   \n";
            cout<<"2. LG                    270 Litre            37000   \n";
            cout<<"3. Ariston               165 litre            28000   \n";
            cin>>choose;
            system("cls");
            if(choose==1)
            {
                sf1="Fridge                 ";
                s4="Samsung               360 Litre            45000   \n";
                p4=45000;
                total+=p4;
                pf1-=1;
            }
            else if(choose==2)
            {
                sf2="Fridge                 ";
                s5="LG                    270 Litre            37000   \n";
                p5=37000;
                total+=p5;
                pf2-=1;
            }
            else if(choose==3)
            {
                sf3="Fridge                 ";
                s6="Ariston               165 litre            28000   \n";
                p6=28000;
                total+=p6;
                pf3-=1;
            }
        }
        else if(a==3)
        {

            cout<<"available products\n";
            cout<<" Brand                   type                 Price   \n";
            cout<<"1. Samsung               microwave            25000   \n";
            cout<<"2. Nova                  electric             15000   \n";
            cin>>choose;
            system("cls");
            if(choose==1)
            {
                so1="Oven                   ";
                s7="Samsung               microwave            25000   \n";
                p7=25000;
                total+=p7;
                po1-=1;
            }
            else if(choose==2)
            {
                so2="Oven                   ";
                s8="Nova                  electric             15000   \n";
                p8=15000;
                total+=p8;
                po2-=1;
            }
        }
        else if(a==4)
        {

            cout<<"available products\n";
            cout<<" Brand                   Size                 Price   \n";
            cout<<"1. Whirlpool             180 Litre            50000   \n";
            cout<<"2. LG                    120 Litre            35000   \n";
            cin>>choose;
            system("cls");
            cout<<s;
            if(choose==1)
            {
                swm1="Washing machine        ";
                s9="Whirlpool             180 Litre            50000   \n";
                p9=50000;
                total+=p9;
                pw1-=1;
            }
            else if(choose==2)
            {
                swm2="Washing machine        ";
                s10="LG                    120 Litre            35000   \n";
                p10=35000;
                total+=p10;
                pw2-=1;
            }
        }
        else if(a==5)
        {

            cout<<"available products\n";
            cout<<" Brand                   Size                 Price   \n";
            cout<<"1. gree                  1.5 ton              45000   \n";
            cout<<"2. hayes                 2 ton                65000   \n";
            cout<<"3. singer                1 ton                35000   \n";
            cin>>choose;
            system("cls");
            if(choose==1)
            {
                sac1="Air Conditioner        ";
                s11="gree                  1.5 ton              45000   \n";
                p11=45000;
                total+=p11;
                pa1-=1;
            }
            else if(choose==2)
            {
                sac2="Air Conditioner        ";
                s12="hayes                 2 ton                65000   \n";
                p12=65000;
                total+=p12;
                pa2-=1;
            }
            else if(choose==3)
            {
                sac3="Air Conditioner        ";
                s13="singer                1 ton                35000   \n";
                p13=35000;
                total+=p13;
                pa3-=1;
            }
        }
        else if(a==6)
        {
        cout<<"what do you want to do?\n1. Sell Product\n2. Update Product\n3. total sales today\n4. search product\n5.Customer Management\n";
        }
        else
            cout<<"insert correct number";
    }
    void showproduct(){cout<<st1<<s1<<st2<<s2<<st3<<s3<<sf1<<s4<<sf2<<s5<<sf3<<s6<<so1<<s7<<so2<<s8<<swm1<<s9<<swm2<<s10<<sac1<<s11<<sac2<<s12<<sac3<<s13;}
};


class date
{

  int date;
  int month;
  int year;
 public:


  void show_date(){time_t now = time(0);
   char* dt = ctime(&now);
   cout<<dt<<endl;};
};

class invoice:public products
{
    public:
    void disphead(){cout<<"******************************INVOICE**************************************\n";}
    void dispinv()
    {

        cout<<"product type            Brand               type/size              price       \n";
        showproduct();
        cout<<"\nTOTAL PRICE="<<total;
        if(regularCustomer==true){haveToPay=(total-(total*2)/100);
                                   cout<<"\nHave to pay: "<<haveToPay;}
         else{haveToPay=total;}

        cout<<"\n\n******************************THANK YOU**************************************";
        s1="";s2="";s3="";s4="";s5="";s6="";s7="";s8="";s9="";s10="";s11="";s12="";s13="";st1="";st2="";st3="";sf1="";sf2="";sf3="";so1="";so2="";swm1="";swm2="";sac1="";sac2="";sac3="";
    }
};

class customer
{
    string name;
    string adress;
    int customerID;
    int contact;
public:
    void get_name(){cout<<"customer name: ";cin>>name;}
    void set_name(){cout<<"customer name: "<<name<<"\n";}
    void get_adress(){cout<<"customer address: ";cin>>adress;}
    void set_adress(){cout<<"customer address: "<<adress<<"\n";}
    void get_contact(){cout<<"contact no.: ";cin>>contact;}
    void set_contact(){cout<<"contact no.: "<<contact<<"\n\n";}
    void show_CustomerMenu()
     {cout<<"1.Register New\n2.search Customer\n3.Delete All customers\n";}
     int customerManagement(){
         again:
         ofstream file;
         string line;
         file.open("customerlist.txt",ios::app);
         if(!file.is_open()){
            cout<<"FIle problem,Rakib can handle";
         }else{
             cout<<"Enter phone no:\n";
         cin>>line;
         file<<line<<endl;
         cout<<"Enter Name: \n";
         cin>>line;
         file<<line<<endl;
         cout<<"Enter Adress: \n";
         cin>>line;
         file<<line<<endl;
         cout<<"CUSTOMER ADDED SUCCESSFULLY!!\n";
         file.close();
         cout<<"1.Add more\n2.go Main Menu\n";
         cin>>choose1;
         if(choose1==1){
           goto again;
         }
         else if(choose1==2){
                return 1;

         }

         }

     }
    void search_customer(){
         again:
         bool found=false;
     fstream f;
     string line;
     string keyword;
     f.open("customerlist.txt",ios::in);
     if(!f.is_open()){
        cout<<"No customer file found.Register first\n";

     }else {
         cout<<"Customer Phone Number:";
        cin>>keyword;
     while(!f.eof()){

        getline(f,line);
        if(line==keyword){
            found=true;
                  getline(f,line);
                 cout<<"Customer Name :"<<line<<endl;
                  getline(f,line);
              cout<<"Customer Address :"<<line<<endl;
              cout<<endl;

              }}
              if(found==false){
                cout<<"NO DATA FOUND !!!\n";
              };}


              }
              int again_search(){
                again:
               cout<<"1.Search again?\n2.Go to MainMenu\n";
              cin>>choose;
               if(choose==1){search_customer();
                              system("cls");
                             goto again;
                             }
               else {system("cls");
                      return 1;}}
    int delete_customer(){
    const int result = remove("customerlist.txt");

    cout<<"successfully delelted file all entry!!!"<<endl;
    return 1;
    }

};


int main()
{
    mainmenu m;
    products p;
    date d;
    invoice i;
    customer c;
    update up;
    searchpr sp;
    bgn:
    m.password();
    int n=m.dispmm();
    if(n==1)
    {
        again:
        p.showtp();
        cin>>n;
        system("cls");
        cout<<s;
        p.choice(n);

        cout<<"do you want to buy anything else?\n1. YES    2.NO\n";
        cin>>n;
        system("cls");
        cout<<s;
        if(n==1)
            goto again;
        else
            cout<<"Are you a register customer?\n1.Yes\n2.No\n";
            cin>>choose1;
            if(choose1==2){
            c.get_name();
            c.get_adress();
            c.get_contact();
            system("cls");
            cout<<s;

        system("cls");
        cout<<s<<endl;
        i.disphead();
        d.show_date();
        c.set_name();
        c.set_adress();
        c.set_contact();
        }
      else if(choose1==1){

            system("cls");
            cout<<s;
            regularCustomer=true;

        system("cls");
        cout<<s<<endl;
        i.disphead();
        d.show_date();
        c.search_customer();

      }

        i.dispinv();
        alltotal+=total;
        cout<<"\n\ncreate another invoice?\n1.yes   2.no\n";
        cin>>n;
        system("cls");
        if(n==1)
        {
            total=0;
            goto again;
        }
        else if(n==2){
            total=0;
            goto bgn;
        }
    }
    else if(n==2)
    {
        int p;
        p=up.ch();
        if(p==1)
        {
            upbgn:
            cout<<s<<"which product do you want to check stock of?\n\n";
            up.showallpro();
            cin>>choose;
            system("cls");
            up.showstock(choose);
            cout<<"\n\ndo you want to check any other product stock?\n1.yes  2.no\n";
            cin>>choose;
            system("cls");
            if(choose==1)
                goto upbgn;
            else
                goto bgn;
        }
        else if(p==2)
        {
            upbgn2:
            cout<<s<<"which product do you want to add stock?\n";
            up.showallpro();
            cin>>choose;
            system("cls");
            up.addstock(choose);
            cout<<"\ndo you want to add stock to any other product?\n1.yes  2.no\n";
            cin>>choose;
            system("cls");
            if(choose==1)
                goto upbgn2;
            else
                goto bgn;
        }}
    else if(n==3)
    {
        char a[2]="";
        m.totalsales();
        cout<<"press any key to continue...";
        cin>>a;
        system("cls");
        if(a!=NULL)
            goto bgn;
    }
    else if(n==4)
    {  sebgn:
        sp.searc();
        cout<<"\nwant to search anything else?\n1.yes  2.no\n";
        cin>>choose;
        system("cls");
        if(choose==1)
            goto sebgn;
        else
            goto bgn;}
  else if(n==5){
            c.show_CustomerMenu();
            cin>>choose;
            if(choose==1){
                    choose1=c.customerManagement();
                    if(choose1==1){
                            goto bgn;
                         }
}
       else if (choose==2)
    {
      c.search_customer();
      choose1=c.again_search();
      if(choose1==1){goto bgn;}

    }
    else if(choose==3){
        choose1=c.delete_customer();
        goto bgn;
    }
}

 return 0;
}
