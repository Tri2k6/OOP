#include "Array.h"
using namespace std;

int main() {
    try
    {
        Array<int> Arr1;
        Array<int> Arr2;
        cout << "Array 1: \n";
        cin >> Arr1;
        cout << "Array 2: \n";
        cin >> Arr2;

        cout << "Array 1 before copy Array 2: \n" << Arr1;
        Arr1 = Arr2;
        cout << "Array 1 after copy Array 2: \n" << Arr2;

        int idx;
        cout << "Nhap chi so cua phan tu can lay cua Array 1: ";
        cin >> idx;
        cout <<  "Arr1[" << idx << "] = " << Arr1[idx] << endl;

        int * ptr = (int*) Arr2;
        cout << "Thay doi phan tu Arr2[0] = 17 qua con tro: \n";
        ptr[0] = 17;
        cout << Arr2;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}