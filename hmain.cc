//Towers of Hanoi
//Colleen Lau Lab 3
/* File:  hmain.cc
 * By:    
 * Date:  
 *
 */

#include <iostream>
#include "hanoi.h"

using namespace std;

// Test driver for Towers of Hanoi
//     DO NOT TRY 64 DISKS!!!

main()
{  int num;

	cout << "Enter number of disks: " << flush;

	while( cin >> num && num!=0)
	{   
		hanoi(num,1,3,2);
		cout << "Enter number of disks: " << flush;
	}
}


