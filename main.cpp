#include<iostream>

using namespace std;

//Add threading later
int main() {
	//Determine if initiating or receiving node
	//Initiator will...
		//Ask for upper bound
		//Create linked list of all numbers from 2-upper bound (number list)
		//Create solutions linked list
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
}
