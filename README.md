# a-maze-d
This program moves all the robots in a maze from the entrance to the exit, getting as
many robots through as possible at the same time and in as little time as possible. To find out
about the maze, your program will receive a description of the maze on the standard input
screen.\
\
The description will contain:\
- The number of robots at the entrance to the labyrinth\
- All rooms and their positions\
- Tunnels linking each room\

\
EXAMPLE INPUT:\
./amazed < labyrinth\
#number_of_robots\
3\
#rooms\
##start\
0 1 0\
##end\
1 13 0\
2 5 0\
3 9 0\
#tunnels\
0-2\
2-3\
3-1\
\
EXAMPLE OUTPUT:\
#moves\
P1-2\
P1-3 P2-2\
P1-1 P2-3 P3-2\
P2-1 P3-3\
P3-1\
\
85% passed
