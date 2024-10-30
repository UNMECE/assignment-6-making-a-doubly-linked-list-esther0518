#include <iostream>
#include "coordinate.h"

int main(int argc, char* argv[]){
    //check if there is more than one argument if less exit (maybe idk will check)
    if(argc < 2){
        std::cout << "insufficent agrugments, provide number of points" << std::endl;
        return 1;
    }
    
    //initialize hte head and tail of the function as null because its empty
    Coordinate *list_beginning = NULL; //pointer to the 1st node
    Coordinate *list_end = NULL; //pointer to the last node

    //take the second argument as number of points
    int num_points = std::atoi(argv[1]);

    //generate values for x and y
    for(int i=0; i<num_points; i++){
        float x = i + 1.5f;
        float y = i + 3.25f;

        //add the coordinate
        add_coordinate(list_end, x, y, i);

        //initialize the beginnging for only one point
        if(list_beginning == NULL){
            list_beginning = list_end;
        }
    }

    //display the points in forward order the backwards order
    forward_display(list_beginning);
    backward_display(list_end);

    //delete coordinate from beginning of list
    delete_coordinate(list_beginning);

    //display forwards again to check if the 1st coordinate was removed
    std::cout << "New ";
    forward_display(list_beginning);

    //display the length size of the list
    int length = list_length(list_beginning);
    std::cout << "Length of the coordinate list is: " << length << std::endl;

    return 0;
}

