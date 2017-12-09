class products
{
    double p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13;
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
        else
            cout<<"insert correct number";
    }
    void showproduct(){cout<<st1<<s1<<st2<<s2<<st3<<s3<<sf1<<s4<<sf2<<s5<<sf3<<s6<<so1<<s7<<so2<<s8<<swm1<<s9<<swm2<<s10<<sac1<<s11<<sac2<<s12<<sac3<<s13;}
};
