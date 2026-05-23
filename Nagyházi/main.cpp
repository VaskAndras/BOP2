#include <iostream>
#include <string>
#include <vector>

#include "converter.h"
#include "Marker.h"
/*
The core idea is to create a markdown html coverter with 2 type of classes,
one is for keeping the type for the markdown element and the other is for the convertion.
The goal is to create a map of a given text and making a vector with elements of the special markers. 
We make it when firstly we go through the text.
After the map is complete we can write out the text from the fist file to the second one, 
but when we meet with a special marker we write the html tag instead of the marker. 
this gives us a m*n time complexity,
 where n is the number of characters in the text and m is the number of special markers.
*/ 


