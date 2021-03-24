
#include <iostream>
#include <string>

using namespace std;

class Tutu{
private:
    string train_name;
    int number;
    string departure;
    string arrival;
    int departure_hours;
    int departure_min;
    int arrival_hours;
    int arrival_min;
public:
    Tutu();
    Tutu(string train_name, int number, string departure, string arrival,
         int departure_hours, int departure_min, int arrival_hours, int arrival_min);
    ~Tutu();
    void print();
    void set();
    void random_route();

};
int main(){
    int c;
    Tutu a;
    Tutu b("asd", 412, "MOSCOW", "London", 12, 25, 15, 55);
    b.print();
    do
    {
        cout << "Enter 0, if you want print regular timetable, enter 1, if you want to fill in the timetable, enter 2, if you want to see an arbitraty (random) timetable \n" ;
        cin >> c;
    } while (c != 0 && c != 1 && c != 2 );

    switch (c)
    {
        case 0:
            a.print();
            do
            {
                cout << "Enter 3, if you want to fill in the timetable or if you want to close the prog, just enter 4 \n";
                cin >> c;
            } while (c != 3 && c != 4);
            switch (c)
            {
                case 3:
                    a.set();
                    a.print();
                    break;
                case 4:
                    return 0;
            }
        case 1:
            a.set();
            a.print();
            break;

        case 2:
            a.random_route();
            a.print();
            do
            {
                cout << "Enter 3, if you want to fill in the timetable, or if you want to close the prog, just enter 4 \n";
                cin >> c;
            } while (c != 3 && c != 4);
            switch (c){
                case 3:
                    a.set();
                    a.print();
                    break;
                case 4:
                    break;
            }
    }

    return 0;
}


void Tutu::print(){
    cout << "Train #" << number << " named " << train_name << endl;
    cout << "Depart from " << departure << " arrive to " << arrival << endl;
    cout << "Departure time " << departure_hours << ":" << departure_min << endl;
    cout << "Arrival time " << arrival_hours << ":" << arrival_min  << endl;
}

void Tutu::set(){
    cout << "Please enter train number(int) and name(string)";
    cin >> number >> train_name;
    cout << "Please enter departure(string) and arrival(string)";
    cin >> departure >> arrival;
    cout << "Please enter departure time(two int values)";
    cin >> departure_hours >> departure_min;
    cout << "Please enter arrival time(two int values)";
    cin >> arrival_hours >> arrival_min;
}

void Tutu::random_route(){
    int i, j, k;
    do{
        i = rand()%10;
        j = rand()%10;
        k = rand()%3;
    }while(i == j);
    string city_array[10] = {"Moscow", "Kiev", "Orel", "Leningrad", "Novosibirsk", "Kalinigrad", "Ryazan", "Samara", "Volgograd", "Ekaterininburg"};
    string nom[3] = {"Sapsan", "Firmenniy", "Skoriy"};
    train_name = nom[k];
    number = rand()%500  + 500;
    departure = city_array[i];
    arrival = city_array[j];
    departure_hours = rand()%23;
    departure_min = rand()%60;
    arrival_hours = rand()%23;
    arrival_min = rand()%60;
    
}
Tutu::Tutu(){
    random_route();
    print();
}

Tutu::Tutu(string train_name_, int number_, string departure_, string arrival_,
           int departure_hours_, int departure_min_, int arrival_hours_, int arrival_min_){
    train_name = train_name_;
    number = number_;
    departure = departure_;
    arrival = arrival_;
    departure_hours = departure_hours_;
    departure_min = departure_min_;
    arrival_hours = arrival_hours_;
    arrival_min = arrival_min_;
}

Tutu::~Tutu(){
    cout << "Number delete";
    cout << number << endl;
    
}
