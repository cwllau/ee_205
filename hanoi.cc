//Towers of Hanoi
//Colleen Lau Lab 3
//hanoi.cc

#include <iostream>
#include "hanoi.h"

using namespace std;

void hanoi(int num, int from, int to, int temp) {
    
    int A = from;  //from A
    int B = to;    //to B
    int C = temp;  //place stuff on C as holder
    
    if (num==1) {
        //only 1 disk = move from A to B
        cout << "Moving disk from " << A << " to " <<B<< endl;
    }
    else { //more than one_num # of disks
        //move n-1 disks from A to C using B as a temporary
        hanoi(num - 1, A,C,B);
        //move last disk from A to B
        cout << "Moving disk from " << A << " to " << B << endl;
        //move n-1 disks from C to B using A as temporary
        hanoi(num - 1, C,B,A);
    }
}