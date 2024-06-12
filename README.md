# Interpreter

Tokens: [{{"1","LET","A","=","5"},{"2","LET","B","=","10"},{"3","IF","A","<","B","THEN","50"},{"4","GOTO","7"},{"5","LET","C","=","A","+","B"},{"6","PRINT",""The","sum","is","",","C"},{"7","END"}}]

# Compile And Run

```properties
g++ -o program Interpreter.cpp

./program
```


# Input And Output

### 1. Example

```properties
Input:

1 LET A = 5
2 LET X = 10
3 IF A < B THEN 50
5 LET C = A + B
6 PRINT "The sum is ", C
7 PINRT "This is print statement."
8 PRINT C
9 END

Output:

The sum is 15
This is print statement.
15
```

### 2. Example

```properties
Input:

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

Output:

The sum is 60
I love compiler!!  
60
I love also programming!!
```

### 3. Example

```properties
Input:

1 LET A = 5
2 LET B = 10
3 IF A < B THEN A = 50 + 1
4 GOTO 7
5 LET C = A + B
6 PRINT "The sum is ", C
7 PRINT "This is print statement."
8 PRINT B
9 END

Output:

This sum is 61
This This is print statement.
10
```