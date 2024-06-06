# Interpreter

### Input

```properties
1 LET A = 5
2 LET X = 10
3 IF A < B THEN 50
4 INPUT A
5 LET C = A + B
6 PRINT "The sum is ", C
7 PINRT "This is print statement:"
8 PRINT C
9 END

```

[arr] = [{{"1","LET","A","=","5"},{"2","LET","B","=","10"},{"3","IF","A","<","B","THEN","50"},{"4","GOTO","7"},{"5","LET","C","=","A","+","B"},{"6","PRINT",""The","sum","is","",","C"},{"7","END"}}]

# Compile And Run

g++ -o program Interpreter.cpp

./program git push --set-upstream origin main.txt

### 1. Example

2 LET A = 10
5 LET B = 50
1 LET C = A + B
2 PRINT "The sum is ", C
8 PRINT "This is print statement:"
7 PRINT C
3 END

### 2. Example

1 LET A = 10
2 LET B = 50
3 LET C = A + B
4 PRINT "The sum is ", C
5 PRINT "I love compiler!!"
6 PRINT C
7 GOTO 10
8 PRINT "Compiler works like magin!!"
9 PRINT "Interpreter compiles the codes line by lline."
10 PRINT "I love also programming!!"
11 END

output:
The sum is 60
I love compiler!!  
60
I love also programming!!

### 3. Example

1 LET A = 5
2 LET B = 10
3 IF A < B THEN A = 50 + 1
4 GOTO 7
5 LET C = A + B
6 PRINT "The sum is ", C
7 PRINT "This is print statement."
8 PRINT B
9 END

<!--  Problem -->

# Problem 1: Print 100 times "I love compiler!"

1 LET A = 0
2 IF A < 100 THEN A = A + 1
3 PRINT "I love compiler!!"
4 IF A < 100 THEN GOTO 2
5 END

# Problem 2: Sum of all numbers between 100 to 200

1 LET A = 100
2 LET SUM = 0
3 IF A < 201 THEN A = A + 1
4 IF A < 201 THEN SUM = SUM + A
5 IF A > 200 THEN BREAK
6 GOTO 3
7 PRINT A
8 END

# Imprementation-basic-compiler
