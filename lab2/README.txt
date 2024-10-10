In the following lab everything that the lab required was achieved. The towersMain was updated for user input and figures out how many lines it takes for to solve the Towers of Hanoi.

Question Part 1: 

1) if you input towers(5,2,3) it will revursively call towers (4,2,1) because of the methods 

spare = 6 - from - dest
towers(n-1, spare, dest)

2) the towers() method will be called 5 times before returning to the intial invocation 

3) once we call towers (5,2,3) the first move that will be called will be "From tower 2 to tower 3"

4) the second recursive call would be towers(0,3,2)

Question Part 2:

1) The output of line would be 255 lines.
