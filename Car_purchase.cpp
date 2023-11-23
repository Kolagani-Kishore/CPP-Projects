#include<iostream>


int Choose_Brand();                                                //Function decalration
int Choose_Model(int Car_Brand);
int Choose_Colour();
int Choose_Engine();
int Choose_Features();
int Exshowroom_Price(std::string Model, int Features);


long int Car_Prices[] = {1000000, 1500000, 1100000, 1700000};          // Array decalration

enum Feature_Prices                                                    // enum for giving names values
{
    Sunroof_price = 50000,
    Both_price = 80000
};

struct Onroad_Price                                                    //Structure is a user defined data type                                                            
{                                                                      //which is a collection of different data types
    int ExshowroomPrice;
    int Tax;
    int Insurance;
};

class features                                                        //Parent class 
{
    protected:                                                        //Protected access specifier(Encapsulation) whose attributes/data members can be accessed
        bool Sunroof;                                                 //through methods/member functions of inherited classes.
        bool RearAC;

    public:
        virtual void Car_features()                                  //a virtual class which needs to be redefined in child class (Method/function overriding in polymorphism)
        {

        }

};

class Car : public features                                          // A child/sub class which inherites attributes and methods of parent/super class 'features' (Inheritence)
{                                                                    //Multilevel inheritence uses 2 or more parent classes with ',' between them
    private:                                                         //Private access specifier(Abstarction and Encapsulation) (default) whose attributes
        std::string Engine;                                          //can only be accessed using methods in public (getter and setter)
                                                                     
    public:                                                          //Public access specifier whose attributes and methods can be accessed
        std::string Brand;                                           //through objects
        std::string Model;                                           //namespace std(can also use 'using namespace std' at the start of program)
        std::string Colour;                                          //:: is a scope resolution operator which reads definition from namespace or classes
        

        Car(std::string Brand, std::string Model, std::string x)    //constructor (should have same name as class) for the class with same argument names
        {
            this->Brand = Brand;                                    //'this->' keyword is used when argument in constructor has same name as class attribute
            this->Model = Model;
            Colour = x;
        }

        void Set_Engine(std::string engine_type)                   //Using setter to set(modify private data) the data in encapsulated data (also abstracted data)
        {
            Engine  = engine_type;
        }

        std::string Get_Engine()                                   //Using getter to get(access private data) the data from encapsulated data (also abstracted data)
        {
            return Engine;
        }

        void Car_features(bool x)                                 //public method in class
        {
            Sunroof  = x;
        }

        void Car_features(bool x, bool y)                         //Method overloading with different input argument type/numbers (Polymorphism) but same method name
        {                                                         //Can also be used in function overloading 
            Sunroof  = x;                                         //Overriding is also polymorphism but with definition in both parent class and child class
            RearAC = y;
        }

        int Selected_features()
        {
            if((Sunroof == true)&&(RearAC ==true))
            {
                return 2;
            }
            else if(Sunroof == true)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        
};

int main()
{
    int a, b, c, e;
    char d;
    int MyCar_Exshowroom_Price;
    int MyCar_Onroad_Price;
    std::string Car_Brand, Car_Model, Car_Colour, Car_Engine;
    bool Car_Autogear;
    a = Choose_Brand();
    a ==1? Car_Brand = "TATA" : Car_Brand = "KIA";                                 //Iternary operator (shortcut for simple if-else condition)

    b = Choose_Model(a);

    switch(b)
    {
        case 1: Car_Model = "Nexon";
                break;
        case 2: Car_Model = "Harrier";
                break;
        case 3: Car_Model = "Sonet";
                break;
        case 4: Car_Model = "Carrens";
                break;
        default: break;
    }

    c = Choose_Colour();
    if(c == 1)
    {
        Car_Colour = "Black";
    }
    else
    {
        Car_Colour = "White";
    }

    Car MyCar(Car_Brand, Car_Model, Car_Colour);                                //Creating object for class Car(Instance of class which takes memory)
                                                                                
    e = Choose_Engine();
    if(e == 1)
    {
        Car_Engine = "Petrol";
    }
    else
    {
        Car_Engine = "Diesel";
    }

    MyCar.Set_Engine(Car_Engine);

    int f = 0;

    d = 'd';    
    while (f == 0)
    {
        std::cout<<"Do you want to choose additional features: Y/N \n";
        std::cin>>d;
        if((d == 'Y')||(d == 'N')||(d == 'y')||(d == 'n'))
        {
            f = 1;
            break;
        }
        std::cout<<"Please choose yes or no! \n";
    }

    if((d == 'Y')||(d == 'y'))
    {
        f = Choose_Features();
    

        if(f == 1)
        {
            MyCar.Car_features(true);
        }

        else
        {
            MyCar.Car_features(true, true);
        }

    }

    MyCar_Exshowroom_Price = Exshowroom_Price(MyCar.Model, MyCar.Selected_features());

    std::cout<<"Your Car Exhowroom price for "<<MyCar.Brand<<" "<<MyCar.Model<<" "<<MyCar.Colour<<" colour is: Rs."<<MyCar_Exshowroom_Price<<'\n';

   

    return 0;
}

int Choose_Brand()                                                           //Function definition
{
    char e;
    std::cout<<"Welocme to Pandu Automobiles! \n";
    std::cout<<"Choose a Brand: \n"<<"1.TATA \n"<<"2.KIA \n";
    std::cin>>e;
    if((e == '1')||(e == '2'))
    {
        if(e == '1')
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        std::cout<<"Please choose either option 1 or 2 \n";
        Choose_Brand();                                                      //Recursive function call
    }
    return 0;
}

int Choose_Model(int Car_Brand)
{
    int e = 0;
    int f = 0;
    if(Car_Brand == 1)
    {
        while(f == 0)
        {
            std::cout<<"Choose a Model: \n"<<"1.Nexon \n"<<"2.Harrier \n";
            std::cin>>e;
            if((e == 1)||(e == 2))
            {
                f = 1;
                return e;
            }
            else
            {
                std::cout<<"Wrong input \n";   
            }

        }
    }

    else if(Car_Brand == 2)
    {
        while(f == 0)
        {
            std::cout<<"Choose a Model: \n"<<"1.Sonet \n"<<"2.Carrens \n";
            std::cin>>e;
            if((e != 1)||(e != 2))
            {
                f = 1;
                return e + 2;
            }
            else
            {
                std::cout<<"Wrong input \n";
            }

        }

    }
    return 0;
    
}

int Choose_Colour()
{
    int a = 0;
    std::cout<<"Choose a colour: \n"<<"1.Black \n"<<"2.White \n";
    std::cin>>a;
    
    if ((a == 1)||(a == 2))
    {
        return a;
    }
    else
    {
        std::cout<<"Please choose one of two available colours! \n";
        Choose_Colour();
    }
    return 0;
}

int Choose_Engine()
{
    int a = 0;
    std::cout<<"Choose Engine type: \n"<<"1.Petrol \n"<<"2.Diesel \n";
    std::cin>>a;
    
    if ((a == 1)||(a == 2))
    {
        return a;
    }
    else
    {
        std::cout<<"Please choose one of two available engine types! \n";
        Choose_Colour();
    }
    return 0;
}

int Choose_Features()
{
    int a = 0;
    std::cout<<"Choose options: \n1.Sunroof \n2.Sunroof & RearAC \n";
    std::cin>>a;
    if((a > 0)&&(a < 3))
    {
        return a;
    }
    else
    {
        std::cout<<"Please choose correct options! \n";
        Choose_Features();
    }

    return 0;
}

int Exshowroom_Price(std::string Model, int sr)
{
    int Base_Price;
    int ExshowroomPrice;
    try
    {
    if(Model == "Nexon")
    {
        Base_Price = Car_Prices[0];
    }

    else if(Model == "Harrier")
    {
        Base_Price = Car_Prices[1];
    }

    else if(Model == "Sonet")
    {
        Base_Price = Car_Prices[2];
    }

    else if(Model == "Carrens")
    {
        Base_Price = Car_Prices[3];
    }
    else
    {
        throw Model;    
    }

    if(sr == 1)
    {
        ExshowroomPrice = Base_Price + Sunroof_price;
    }
    else if(sr == 2)
    {
        ExshowroomPrice = Base_Price + Both_price;
    }
    else
    {
        ExshowroomPrice = Base_Price;
    }
    }

    catch(std::string Model)
    {
        std::cout<<"Exception caught";
    }
    

    return ExshowroomPrice; 
    }