#include<iostream>
#include<vector>
using namespace std;

class Vehicle {
    public:
        // Class Data Members
        string vehicleID;       // Unique identifier for the vehicle
    	string make;            // Manufacturer of the vehicle
    	string model;           // Model of the vehicle
    	int year;               // Year of manufacture
    	bool isRented;          // Indicates whether the vehicle is currently rented
    	double dailyRentalRate; // The daily rental rate for the vehicle
    
        // Class Member Functions
        // Constructor 
        Vehicle(){
            vehicleID = ' ';
            make = ' ';
            model = ' ';
            year = 0; 
            isRented = false;
            dailyRentalRate = 0.00;
        }

        void getData(){
            char choice ;
            cout << "Vehicle Id: ";
            cin >> vehicleID ;
            cin.ignore();  // ignore the newline charactre left by cin
            cout << "Manufacturer: ";
            getline(cin, make);
            cout << "Model: ";
            cin >> model ;
            cout << "Year: " ;
            cin >> year ; 
            cout << "Is Rented(y/n): " ;
            cin >> choice ;
            (choice == 'y' || choice == 'Y') ? isRented = true : isRented = false ;
            cout << "Daily Rntel Rate: " ;
            cin >> dailyRentalRate ;
        }

        // pure virtual function
        virtual double calculateRentalCost(int days) = 0 ;

        virtual void displayDetails(){
            cout<<"Vehicle Id: "<<vehicleID<<endl
                <<"Manufacturer: "<<make<<endl
                <<"Model: "<<model<<endl
                <<"Year: "<<year<<endl;
            if(isRented){
                cout<<"Is Rented: Yes"<<endl;
            }else{
                cout<<"Is Rented: No"<<endl;
            }
            cout<<"Daily Rental Rate: "<<dailyRentalRate<<endl; 
        }

        void rentVehicle(){
            isRented = true; 
        }

        void returnVehicle(){
            isRented = false;
        }
};

class Car : public Vehicle {
    public :
        int numberOfDoors ;
        string fuleType ;

        // constructor for Car 
        Car (string vehicleID,string make ,string model ,int year ,bool isRented ,double dailyRentalRate,int numberOfDoors, string fuleType){
            this->vehicleID = vehicleID ;
            this->make = make ;
            this->model = model ;
            this->year = year ;
            this->isRented = isRented ;
            this->dailyRentalRate = dailyRentalRate ;
            this->numberOfDoors = numberOfDoors;
            this->fuleType = fuleType;
        }
        
        double calculateRentalCost(int days){      // Base cost * days
            return dailyRentalRate * days ;
        }

        void displayDetails(){
            Vehicle::displayDetails();
            // display Car data
            cout<<"Number of Doors: "<<numberOfDoors<<endl
                <<"Fule Type: "<<fuleType<<endl<<endl;
        }
};

class Motorcycle : public Vehicle{
    public:
        string engineType ;      // "Inline-4", "V-Twin"
        bool hasSidecar ;

        Motorcycle (string vehicleID,string make ,string model ,int year ,bool isRented ,double dailyRentalRate, string engineType ,bool hasSidecar){
            this->vehicleID = vehicleID ;
            this->make = make ;
            this->model = model ;
            this->year = year ;
            this->isRented = isRented ;
            this->dailyRentalRate = dailyRentalRate ;
            this->engineType = engineType ;
            this->hasSidecar = hasSidecar ;
        }

        double calculateRentalCost(int days){      // Base cost * days + (hasSidecar ? 20 * days : 0)
            // if(hasSidecar)
            //     return (dailyRentalRate * days) + (20 * days);
            // else
            //     return dailyRentalRate * days ;

            return dailyRentalRate * days + (hasSidecar ? (20 * days) : 0 ) ;
        }

        void displayDetails(){
            // display Vehicle data
            Vehicle :: displayDetails();
            // Morotcycle Data
            cout<<"Engine Type: "<<engineType<<endl ;
            if(hasSidecar){
                cout<<"Sidecar : Yes"<<endl;
            }else{
                cout<<"Sidecar : No"<<endl;
            }
        }
};

class Truck : public Vehicle{
    public:

        double cargoCapacity ;       // in cubic meters
        int numberOfAxles ;

        double calculateRentalCost(int days){          // Base cost * days + (cargoCapacity * 10 * days)
           return dailyRentalRate * days + (cargoCapacity * 10 * days) ;     
        }

        Truck (string vehicleID,string make ,string model ,int year ,bool isRented ,double dailyRentalRate, double cargoCapacity,int numberOfAxels){
            this->vehicleID = vehicleID ;
            this->make = make ;
            this->model = model ;
            this->year = year ;
            this->isRented = isRented ;
            this->dailyRentalRate = dailyRentalRate ;
            this->cargoCapacity = cargoCapacity ;
            this->numberOfAxles = numberOfAxels ;
        }

        void displayDetails(){
            // display Vehicle data
            Vehicle :: displayDetails();

            // Truck Details
            cout<<"Cargo Capacity: "<<cargoCapacity<<endl
                <<"Number of Axles: "<<numberOfAxles<<endl<<endl;
        }
};

class RentalSystem {
    public:
        vector<Vehicle*> vehicles ;

        ~RentalSystem(){
            for(auto vehicle : vehicles)
                delete vehicle ;
            cout<<"Deleted All Dynamic Memory";
        }

        void addVehicle(Vehicle* vehicle){       // Adds a vehicle to the system.
            vehicles.push_back(vehicle);
        }
        
        void displayAvailableVehicles(){         // Displays the details of all available (not rented) vehicles.
            for(auto vehicle : vehicles){
                if(vehicle->isRented != true){
                    vehicle->displayDetails();
                }
            }
        }
        
        void findVehicle(string vehicleID){  // Finds and returns a vehicle pointer based on its ID. Returns nullptr if not found.
            bool foundFlag = false ;
            for(auto vehicle : vehicles){
                if(vehicle->vehicleID == vehicleID){
                    vehicle->displayDetails();
                    foundFlag = true ;
                }
            }
            (foundFlag != true)?cout<<"Vehicle Not Found"<<endl : cout<<endl;
        }

        void rentVehicle(string vehicleID, int days){  // Rents a vehicle for a given number of days. Displays the rental cost.
            for(auto vehicle : vehicles){
                if(vehicle->vehicleID == vehicleID){
                    vehicle->rentVehicle();
                    cout<<"Rentel Cost: "<< vehicle->calculateRentalCost(days)<<endl<<endl;
                }
            }
        }

        void returnVehicle(string vehicleID) {       //Returns a rented vehicle.
        for(auto vehicle : vehicles){
                if(vehicle->vehicleID == vehicleID){
                    vehicle->returnVehicle();
                    vehicle->displayDetails();
                }
            }
        }
};

int main(){
    //  car1("car1234","Tata","CBR",2015,0,1500,4,"Disel");
    // Motorcycle* m1("motor1212","Yamaha","XSR 155",2025,0,1000,"Petrol",0);
    // Truck* t1("truck123","Tata","LPA",2013,1,8000,18,2);

    RentalSystem rentalSystem ;
    rentalSystem.addVehicle(new Car("car1234","Tata","CBR",2015,0,1500,4,"Disel"));
    rentalSystem.addVehicle(new Motorcycle ("motor1212","Yamaha","XSR 155",2025,0,1000,"Petrol",0));
    rentalSystem.addVehicle(new Truck ("truck123","Tata","LPA",2013,1,8000,18,2));


    do{
        short choice, days ;
        string vehicleID ;
        cout<<"1. Display available vehicles" <<endl
    	    <<"2. Rent a vehicle" <<endl
    	    <<"3. Return a vehicle" <<endl
    	    <<"4. Find Vehicle and Display details" <<endl
    	    <<"5. Exit " <<endl;
        cin>>choice ;
        switch(choice){
            case 1 :  
                rentalSystem.displayAvailableVehicles();
                break;
            case 2 :
                cout<<"Enter Vehicle ID: ";
                cin>>vehicleID;
                cout<<"Days: ";
                cin>>days;
                rentalSystem.rentVehicle(vehicleID, days); 
                break;
            case 3 :
                cout<<"Enter Vehicle ID: ";
                cin>>vehicleID;
                rentalSystem.returnVehicle(vehicleID);
                break; 
            case 4 : 
                cout<<"Enter Vehicle ID: ";
                cin>>vehicleID;
                rentalSystem.findVehicle(vehicleID);
                break;
            case 5 : 
                return 0 ;
            default : cout<<"Error : Please Enter a Valid Option"<<endl<<endl;
        }
    }while(true);
    return 0;
}