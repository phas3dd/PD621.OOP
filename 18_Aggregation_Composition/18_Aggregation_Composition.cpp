#include <iostream>
using namespace std;

enum Headlights{ None_h, Halogen, LED, Neon, Xenon };
enum Gear_box{ None_g, Mechanic, Automatic, Robot };
enum Tire{ None_t, Summer, Winter, All_Season };
enum Type_Engine { None_e, Gasoline, Diesel, Electric, Hybrid };
enum Body { None_b, Sedan, Hatchback, Liftback, Coupe, Convertible, Universal, SUV, Crossover, Pickup, Minivan, Limousine, Van };
class Engine
{
    string name;
    float volume;
    Type_Engine type;
public:
    Engine() : name("N/A"), volume(0), type(None_e) {}
    Engine(string n, float v, Type_Engine t) : type(t), name(n), volume(v) {}
    void ShowInfo()
    {
        cout << "\t--- Engine ---" << endl;
        cout << "Engine: " << name << " " << volume << endl;
        cout << "Type: ";
        switch (type)
        {
        case None_e: cout << "None"; break;
        case Gasoline: cout << "Gasoline"; break;
        case Diesel: cout << "Diesel"; break;
        case Electric: cout << "Eletectric"; break;
        case Hybrid: cout << "Hybrid"; break;
        }
        cout << endl;
    }
};
class Wheels
{
    Tire tires_type;
    string tires_brand;
    int width;
    int height;
    int radius;
public:
    Wheels() : tires_type(None_t), tires_brand("N/A"), width(0), height(0), radius(0) {}
    Wheels(Tire ttype, string tbrand, int w, int h, int r) : tires_type(ttype), tires_brand(tbrand), width(w), height(h), radius(r) {}
    void ShowInfo()
    {
        cout << "\t--- Wheels ---" << endl;
        cout << "Size: " << width << "/" << height << "R" << radius << endl;
        cout << "Tires brand: " << tires_brand << endl;
        cout << "Tires type: ";
        switch (tires_type)
        {
        case None_t: cout << "None"; break;
        case Summer: cout << "Summer"; break;
        case Winter: cout << "Winter"; break;
        case All_Season: cout << "All-Season"; break;
        }
        cout << endl;
    }
};
class Driver
{
    string name;
    string surname;
    int age;
    int drive_exp;
public:
    Driver() : name("N/A"), surname("N/A"), age(0), drive_exp(0) {}
    Driver(string n, string s, int a, int d) : name(n), surname(s), age(a), drive_exp(d) {}
    void ShowInfo()
    {
        cout << "\t--- Driver information ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Age: " << age << endl;
        cout << "Driving experience: " << drive_exp << " years" << endl;
    }
};
class Car
{
    string mark;
    string model;
    int year;
    string color;
    Body body;
    Engine engine;
    Gear_box gear_box;
    Wheels wheels;
    Headlights headlights;
    Driver* driver;

    
public:
    Car() : mark("N/A"), model("N/A"), year(0), color("N/A"), body(None_b), gear_box(None_g), headlights(None_h), driver(nullptr) {}
    Car(string mark,
        string model,
        int y,
        string c,
        Body b,
        Engine e,
        Gear_box g,
        Wheels w,
        Headlights h,
        Driver* d = nullptr)
        :
        mark(mark),
        model(model),
        year(y),
        color(c),
        body(b),
        engine(e),
        gear_box(g),
        wheels(w),
        headlights(h),
        driver(d)   {
    }
    void ShowInfo()
    {
        cout << "\t--- " << mark << " " << model << "---" << endl;
        cout << "Mark: " << mark << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Color: " << color << endl;
        cout << "Body type: ";
        switch (body)
        {
        case None_b: cout << "None"; break;
        case Sedan: cout << "Sedan"; break;
        case Hatchback: cout << "Hatchback"; break;
        case Liftback: cout << "Liftback"; break;
        case Coupe: cout << "Coupe"; break;
        case Convertible: cout << "Convertible"; break;
        case Universal: cout << "Universal"; break;
        case SUV: cout << "SUV"; break;
        case Crossover: cout << "Crossover"; break;
        case Pickup: cout << "Pickup"; break;
        case Minivan: cout << "Minivan"; break;
        case Limousine: cout << "Limousine"; break;
        case Van: cout << "Van"; break;
        } cout << endl;
        cout << "Headlights type: ";
        switch (headlights)
        {
        case None_h: cout << "None"; break;
        case Halogen: cout << "Halogen"; break;
        case LED: cout << "LED"; break;
        case Neon: cout << "Neon"; break;
        case Xenon: cout << "Xenon"; break;
        } cout << endl;
        cout << "Gear Box: ";
        switch (gear_box)
        {
        case None_g: cout << "None"; break;
        case Mechanic: cout << "Mechanic"; break;
        case Automatic: cout << "Automatic"; break;
        case Robot: cout << "Robot"; break;
        } cout << endl;
        engine.ShowInfo();
        wheels.ShowInfo();
        if (driver != nullptr)
        {
            driver->ShowInfo();
        }
        else
        {
            cout << "\t--- Driver ---" << endl;
            cout << "No info";
        }
        cout << endl << endl;
    }
    void AddDriver(Driver* driver)
    {
        this->driver = driver;
    }
};

int main()
{
    Wheels Sprinter_wheels(Winter, "Michelin", 205, 55, 16);
    Engine Sprinter_engine("CDI", 2.7, Diesel);

    Driver Driver1("Misha", "Melynik", 35, 12);

    Car Car1("Mercedes-Benz", "Sprinter", 2015, "White", Van, Sprinter_engine, Mechanic, Sprinter_wheels, Halogen);
    Car1.AddDriver(&Driver1);
    Car1.ShowInfo();



    Wheels Audi_wheels(All_Season, "Pirelli", 185, 65, 15);
    Engine Audi_engine("C7", 4.2, Gasoline);

    Driver Driver2("Oleksandr", "Pistoletov", 42, 9);

    Car Car2("Audi", "RS6", 2016, "Grey", Universal, Audi_engine, Automatic, Audi_wheels, LED, &Driver2);
    Car2.ShowInfo();

}