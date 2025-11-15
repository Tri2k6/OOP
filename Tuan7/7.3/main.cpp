#include <iostream>
#include <iomanip>
#include <vector>
#include "motobike.h"
#include "truck.h"

using namespace std;

int main() {

    cout << fixed << setprecision(4);

    cout << "----------------------------------Motobike---------------------------------\n";
    Motobike myBike(10, 0);
    myBike.addGoods(30);

    cout << "Khoi tao xe 10L xang va 30kg hang." << endl;

    cout << "Xang ban dau: " <<  myBike.getFuel() << " L" << endl;

    cout << "Motobike di chuyen 500km." << endl;
    if (myBike.run(500)) {
        cout << "Xang con lai: " << myBike.getFuel() << " L" << endl;
    } else {
        cout << "Luong xang hien tai cua xe khong du de di het quang duong\n";
    }

    cout << "--------------------------------Truck----------------------------------------\n";

    Truck myTruck(100, 3000);
    
    cout << "Khoi tao xe tai co 100L xang va 3000kg hang hoa." << endl;
    cout << "Xang ban dau: " << myTruck.getFuel() << " L" << endl;
    cout << "Truck di chuyen 100km." << endl;
    if (myTruck.run(100)) {
        cout << "Xang con lai: " << myTruck.getFuel() << " L" << endl;
    } else {
        cout << "Luong xang hien tai cua xe khong du de di het quang duong\n";
    }

    return 0;
}