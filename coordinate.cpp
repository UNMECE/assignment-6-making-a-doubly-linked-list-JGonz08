// Julie Gonzales
// 03-25-2026
// function ar
#include <iostream>
#include <cmath>
#include "coordinate.h"

using namespace std;

static int global_id = 0;

void add_coordinate(Coordinate* list_end, float x, float y){
	Coordinate* newNode = new Coordinate;
	newNode->x = x;
	newNode->y =y;
	newNode->next = nullptr;
	newNode->previous = list_end;

	if(list_end != nullptr){
		list_end->next = newNode;
		}

	list_end = newNode;
}

void forward_display(Coordinate* list_beginning){
	Coordinate* curr = list_beginning;
	while (curr != nullptr){
		cout << "ID " << curr->coord_id << ": (" << curr->x << ", " << curr->y << ")\n";
		curr = curr->next;
		}
}

void backward_display(Coordinate* list_end){
	Coordinate* curr = list_end;
	while (curr != nullptr){
		cout << "ID " << curr->coord_id << ": (" << curr->x << ", " << curr->y << ")\n";
		curr = curr->previous;
		}
}

void delete_coordinate(Coordinate* list_beginning, int coord_id_to_delete){
	Coordinate* curr = list_beginning;
	while (curr != nullptr){
		if(curr->coord_id == coord_id_to_delete)
			curr->previous->next = curr->next;
		else
			list_beginning = curr->next;
		if (curr->next != nullptr)
			curr->next->previous = curr->previous;
		delete curr;
		return;
		}
	curr = curr->next;
	}


int list_length(Coordinate* list_beginning){
	int count = 0;
	Coordinate* curr = list_beginning;
	while (curr != nullptr){
		count++;
		curr = curr->next;
		}
	return count;
}

void closest_to(Coordinate* list_beginning, float x, float y){
	if (list_beginning == nullptr) return;
	Coordinate* curr = list_beginning;
	Coordinate* closest = curr;
	float bestDist = sqrt(pow(curr->x - x, 2) + pow(curr->y - y, 2));
	curr = curr->next;
	while (curr != nullptr){
		float dist = sqrt(pow(curr->x - x, 2) + pow(curr->y -y, 2));
		if (dist < bestDist){
			bestDist = dist;
			closest = curr;
			}
		curr = curr->next;
	}
	cout << "closest coordinate to (" << x << "," << y << ") is ID "
		<< closest-> coord_id << " at (" << closest->x << "," << closest->y 
		<< ") with distance "<< bestDist << endl;
}

