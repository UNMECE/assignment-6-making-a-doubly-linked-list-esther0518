#ifndef COORDINATE_H
#define COORDINATE_H

#include <cmath>
#include <cstdlib>

struct _coordinate
{
  float x; 
  float y;
  int coord_id;
  struct _coordinate *next;
  struct _coordinate *previous;
};
typedef struct _coordinate Coordinate;

void add_coordinate(Coordinate*& list_end, float x, float y, int id);
void forward_display(Coordinate* list_beginning);
void backward_display(Coordinate* list_end);
void delete_coordinate(Coordinate*& list_beginning);
int list_length(Coordinate* list_beginning);


#endif 