# Topic description
Your boss once had got many copies of a treasure map. Unfortunately, all the copies are now broken to many rectangular pieces, and what make it worse, he has lost some of the pieces. Luckily, it is possible to figure out the position of each piece in the original map. Now the boss asks you, the talent programmer, to make a complete treasure map with these pieces. You need to make only one complete map and it is not necessary to use all the pieces. But remember, pieces are not allowed to overlap with each other (See sample 2).
# Requirement
time limitation：3000ms, memory limitation：100MB
## Input
The first line of the input contains an integer T (T <= 10), indicating the number of cases.

For each case, the first line contains three integers n m p (1 <= n, m <= 30, 1 <= p <= 100), the width and the height of the map, and the number of pieces. Then p lines follow, each consists of four integers x1 y1 x2 y2 (0 <= x1 < x2 <= n, 0 <= y1 < y2 <= m), where (x1, y1) is the coordinate of the lower-left corner of the rectangular piece, and (x2, y2) is the coordinate of the upper-right corner in the original map.

Cases are separated by one blank line.

## Output
If you can make a complete map with these pieces, output the least number of pieces you need to achieve this. If it is impossible to make one complete map, just output -1.

## Example

#### Input
```
3
5 5 1
0 0 5 5
 
5 5 2
0 0 3 5
2 0 5 5
 
30 30 5
0 0 30 10
0 10 30 20
0 20 30 30
0 0 15 30
15 0 30 30
```
#### Output
```
1
-1
2
```
