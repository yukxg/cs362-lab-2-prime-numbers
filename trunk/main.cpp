#include <iostream>
#include "LList.h"
#include "llist_node.h"

using namespace std;

//Add threading later
int main() {
	//Determine if initiating or receiving node
	//Initiator will...
	int upper;

	//Ask for upper bound
	cout << "Enter the upper bound:";
	//Make sure upper is an integer
	cin >> upper;
	
	cout << "Upper = " << upper << endl;

	//Create linked list of all numbers from 2-upper bound (number list)
	LList * numbers = new LList ();
	numbers -> populate_list (upper);

	//Create two print functions - print all and print X
	cout << "Print first 10...\n";
	numbers -> printList(10);
	
	cout << "Print all...\n";
	numbers -> printList();

	//Create solutions linked list
	LList * solutions = new LList();
		
		//while(work to do)
			//Pull first prime and remove multiples from number list
			//Add prime to solutions list
			//Send number list to receiver
			//Listen for number list from receiver
	//Receiver will...
		//Create solutions list
		//while(work to do)
			//while(number list from initiator is not done)
				//Listen for number list from initiator
			//Add first number in list to solutions list
			//Filter out all multiples of prime from number list
			//Send filtered number list back to initiator
	
	return 0;
}
