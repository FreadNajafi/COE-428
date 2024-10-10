In this lab all of the functions and requirements worked. A brief summary of what has been accomplished is that I had wrote a very simple insertion sort algorithim for the mySort function. When testing the hardcoded data for sortMain function everything was sorted perfectly. I had also understood what the given commandline function that was provided had done. For the sortMain2 function simply adding a few lines of code had fixed the problem if we wanted to give an user input function. 

Answer for Question:

you could simply write a mySort() function that takes an array, "data", and its size as parameters. This would sort the entire array using the efficient sorting function in the object module.

example of mysort/

void mySort(int data[], int size) {
    betterSort(data, 0, size - 1);
}
