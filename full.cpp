#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

string s="-------------------------Welcome to TBD Electronics-------------------------\n\n";
string s1="",s2="",s3="",s4="",s5="",st="",sf="",so="",swm="",sac="";
int choose,choose1;
double total=0, alltotal=0;
int pt1=15,pt2=15,pt3=15,pf1=15,pf2=15,pf3=15,po1=15,po2=15,pw1=15,pw2=15,pa1=15,pa2=15,pa3=15;

class mainmenu
{
    int choice;
public:
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
        {cout<<s<<"insert type:\n1. TV\n2. Fridge\n3. Oven\n4. Washing Machine\n5. Air Conditioner\n";
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
    double p1,p2,p3,p4,p5;
public:
    void showtp()
    {
        cout<<"what type of product do you want to buy?"<<endl;
        cout<<"1. TV\n2. Fridge\n3. Oven\n4. Washing Machine\n5. Air Conditioner"<<endl;
    }
    void choice(int a)
    {
        if(a==1)
        {
            st="TV                     ";
            cout<<"available products\n";
            cout<<" Brand                   Size                 Price   \n";
            cout<<"1. Sony                  52 inches            65000   \n";
            cout<<"2. LG                    42 inches            45000   \n";
            cout<<"3. Phillips              32 inches            30000   \n";
            cin>>choose;
            system("cls");
            if(choose==1)
            {
                s1="Sony                  52 inches            65000   \n";
                p1=65000;
                total+=p1;
                pt1-=1;
            }
            else if(choose==2)
            {
                s1="LG                    42 inches            45000   \n";
                p1=45000;
                total+=p1;
                pt2-=1;
            }
            else if(choose==3)
            {
                s1="Phillips              32 inches            30000   \n";
                p1=30000;
                total+=p1;
                pt3-=1;
            }
        }
        else if(a==2)
        {
            sf="Fridge                 ";
            cout<<"available products\n";
            cout<<" Brand                   Size                 Price   \n";
            cout<<"1. Samsung               360 Litre            45000   \n";
            cout<<"2. LG                    270 Litre            37000   \n";
            cout<<"3. Ariston               165 litre            28000   \n";
            cin>>choose;
            system("cls");
            if(choose==1)
            {
                s2="Samsung               360 Litre            45000   \n";
                p2=45000;
                total+=p2;
                pf1-=1;
            }
            else if(choose==2)
            {
                s2="LG                    270 Litre            37000   \n";
                p2=37000;
                total+=p2;
                pf2-=1;
            }
            else if(choose==3)
            {
                s2="Ariston               165 litre            28000   \n";
                p2=28000;
                total+=p2;
                pf3-=1;
            }
        }
        else if(a==3)
        {
            so="Oven                    ";
            cout<<"available products\n";
            cout<<" Brand                   type                 Price   \n";
            cout<<"1. Samsung               microwave            25000   \n";
            cout<<"2. Nova                  electric             15000   \n";
            cin>>choose;
            system("cls");
            if(choose==1)
            {
                s3="Samsung               microwave            25000   \n";
                p3=25000;
                total+=p3;
                po1-=1;
            }
            else if(choose==2)
            {
                s3="Nova                  electric             15000   \n";
                p3=15000;
                total+=p3;
                po2-=1;
            }
        }
        else if(a==4)
        {
            swm="Washing machine        ";
            cout<<"available products\n";
            cout<<" Brand                   Size                 Price   \n";
            cout<<"1. Whirlpool             180 Litre            50000   \n";
            cout<<"2. LG                    120 Litre            35000   \n";
            cin>>choose;
            system("cls");
            cout<<s;
            if(choose==1)
            {
                s4="Whirlpool             180 Litre            50000   \n";
                p4=50000;
                total+=p4;
                pw1-=1;
            }
            else if(choose==2)
            {
                s4="LG                    120 Litre            35000   \n";
                p4=35000;
                total+=p4;
                pw2-=1;
            }
        }
        else if(a==5)
        {
            sac="Air Conditioner        ";
            cout<<"available products\n";
            cout<<" Brand                   Size                 Price   \n";
            cout<<"1. gree                  1.5 ton              45000   \n";
            cout<<"2. hayes                 2 ton                65000   \n";
            cout<<"3. singer                1 ton                35000   \n";
            cin>>choose;
            system("cls");
            if(choose==1)
            {
                s5="gree                  1.5 ton              45000   \n";
                p5=45000;
                total+=p5;
                pa1-=1;
            }
            else if(choose==2)
            {
                s5="hayes                 2 ton                65000   \n";
                p5=65000;
                total+=p5;
                pa2-=1;
            }
            else if(choose==3)
            {
                s5="singer                1 ton                35000   \n";
                p5=35000;
                total+=p5;
                pa3-=1;
            }
        }
        else
            cout<<"insert correct number";
    }
    void showproduct(){cout<<st<<s1<<sf<<s2<<so<<s3<<swm<<s4<<sac<<s5;}
};

class date
{
  int date;
  int month;
  int year;
 public:
  void enter_date(){cout<<"enter date:\ndd mm yyyy\n";cin>>date>>month>>year;};
  void show_date(){cout<<"date:";cout<<date<<"/"<<month<<"/"<<year<<endl;};
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
        cout<<"\n\n******************************THANK YOU**************************************";
        s1="";s2="";s3="";s4="";s5="";st="";sf="";so="";swm="";sac="";
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
     ifstream f;
     string line;
     string keyword;
     f.open("customerlist.txt",ios::out);
     if(!f.is_open()){
        cout<<"file problem, call Rakib";

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
                cout<<"NO DATA FOUND !!!";
              };}


              }
              int again_search(){
                again:
               cout<<"1.Search again?\n2.Go to MainMenu\n";
              cin>>choose;
               if(choose==1){search_customer();
                             goto again;}
               else {return 1;}}

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
        d.enter_date();
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
        d.enter_date();
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
        }


    }
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
    {
        sebgn:
        sp.searc();
        cout<<"\nwant to search anything else?\n1.yes  2.no\n";
        cin>>choose;
        system("cls");
        if(choose==1)
            goto sebgn;
        else
            goto bgn;
    }



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
}



    return 0;
}
