#include <iostream>
#include "coordinate.h"

//add cordinates to the list
void add_coordinate(Coordinate*& list_end, float x, float y, int id){ 

    //allocate memory for a new coordinate point
    Coordinate* new_point = new Coordinate;

    //if the allocation fail quit program
    if(new_point == NULL){
        return;
    }
     
    //assign the values respectively
    new_point -> x = x;
    new_point -> y = y;
    new_point -> coord_id = id;

    //update nodes
    new_point -> next = NULL;
    new_point -> previous = list_end;

    //update the next point to the last point if it exsits
    if(list_end != NULL){
        list_end -> next = new_point;
    }

    //update the end of the list to the new point
    list_end = new_point;
}

void forward_display(Coordinate* list_beginning){
    //check to see if the Coordinate list is empty
    if(list_beginning == NULL){
        std::cout << "Coordinate list is empty." << std::endl;
        return;
    }

    std::cout << "List from the beginnging is:" << std::endl;

    //print the values of the list from beginning to end
    Coordinate *current = list_beginning;
    while(current != NULL){
        //print the current points x and y values
        std::cout << " " << current -> x << ", " << current -> y << std::endl;

        //move to the next point
        current = current -> next;
    }
}

void backward_display(Coordinate* list_end){
    //check to see if the Coordinate list is empty
    if(list_end == NULL){
        std::cout << "Coordinate list is empty" << std::endl;
        return;
    }

    std::cout << "List from the end to beginning is:" << std::endl;
    Coordinate *current = list_end;
    while(current != NULL){
        //print the current points x and y values
        std::cout << " " << current -> x << ", " << current -> y << std::endl;

        //move to the previous point
        current = current -> previous;
    }

}


void delete_coordinate(Coordinate*& list_beginning){
    //check to see if the Coordinate list is empty
    if(list_beginning == NULL){
        std::cout << "Coordinate list is empty." << std::endl;
        return;
    }

    Coordinate* coord_id_to_delete = list_beginning; //points to the point that will be deleted
    list_beginning = list_beginning -> next; //updates list to next point

    //if new point at the front is not NULL update the pointer
    if(list_beginning != NULL){
        list_beginning -> previous = NULL;
    }

    //free the memory
    delete coord_id_to_delete;
    std::cout << "First point deleted." << std::endl;
    
}

int list_length(Coordinate *list_beginning){
    //check to see if the Coordinate list is empty
    if(list_beginning == NULL){
        std::cout << "Coordinate list is empty." << std::endl;
        return 1;
    }
    
    int count = 0;
    Coordinate* current = list_beginning;
    //count the number of coordinates
    while(current != NULL){
        count ++;
        current = current -> next;
    }

    return count;
}
