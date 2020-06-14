#include <iostream>
#include<string>
using namespace std;
 
int main() {
    int nums[5] = {1, 2, 3, 4, 5};
    int* x = nums;
    for(int i=0; i<5; i++) {
        cout << *x++ << endl;
    }
    return 0;
}