//Julie Gonzales 
//03-25-2026
// Main function for running programming

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "coordinate.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc < 2){
		cout << "Usage: ./main <number_of_points>\n" << endl;
		return 1;
		}
	int n = atoi(argv[1]);
	srand(time(NULL));
	Coordinate *head = nullptr;
	Coordinate *tail = nullptr;
// building the list here 

	for (int i = 0; i<n; i++){
		float x = (rand() % 1000) / 10.0;
		float y = (rand() % 1000) / 10.0;
		if(head == nullptr){
			head = new Coordinate{x, y, i, nullptr, nullptr};
			tail = head;
			} else {;
				Coordinate* node = new Coordinate{x, y, i, nullptr, tail};
				tail->next = node;
				tail = node;
				}
	}

	cout << "\nForward Display:\n";
	forward_display(head);
	cout<< "\nBackward Display:\n";
	backward_display(tail);
	cout<< "\nList legnth: " << list_length(head) << endl;
	cout << "\nTesting closest_to: \n";
	closest_to(head, 5.0, 5.0);
	cout <<"\nDeleting ID 0 (if exisits):\n";
	delete_coordinate(head, 0);
	cout << "\nForward display after deletion:\n";
	forward_display(head);

	return 0;
}
