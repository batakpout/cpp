#include<iostream>

using namespace std;



/*
Initial Call: permute("abc", 0)
String: "abc" (original)

Iteration 1 (j=0):
        Swap str[0] ('a') --> str[0] ('a')-->"abc" (no change)

        Recursive call permute("abc", 1)

        Inside permute("abc", 1):
        String: "abc"

        Iteration 1 (j=1):
        Swap str[1] ('b') --> str[1] ('b')-->"abc" (no change)

        Recursive call permute("abc", 2)-->BASE CASE

        Prints "abc" (first permutation)

        Swap back str[1] ('b') --> str[1] ('b')-->"abc"

        Iteration 2 (j=2):-->
        Swap str[1] ('b') --> str[2] ('c')-->"acb"

        Recursive call permute("acb", 2)-->BASE CASE

        Prints "acb" (second permutation)

        Swap back str[1] ('c') --> str[2] ('b')-->"abc"

        Swap back str[0] ('a') --> str[0] ('a')-->"abc"

Iteration 2 (j=1):
        Swap str[0] ('a') --> str[1] ('b')-->"bac"

        Recursive call permute("bac", 1)

        Inside permute("bac", 1):
        String: "bac"

        Iteration 1 (j=1):
        Swap str[1] ('a') --> str[1] ('a')-->"bac" (no change)

        Recursive call permute("bac", 2)-->BASE CASE

        Prints "bac" (third permutation)

        Swap back str[1] ('a') --> str[1] ('a')-->"bac"

        Iteration 2 (j=2):
        Swap str[1] ('a') --> str[2] ('c')-->"bca"

        Recursive call permute("bca", 2)-->BASE CASE

        Prints "bca" (fourth permutation)

        Swap back str[1] ('c') --> str[2] ('a')-->"bac"

        Swap back str[0] ('b') --> str[1] ('a')-->"abc"

Iteration 3 (j=2):
        Swap str[0] ('a') --> str[2] ('c')-->"cba"

        Recursive call permute("cba", 1)

        Inside permute("cba", 1):
        String: "cba"

        Iteration 1 (j=1):
        Swap str[1] ('b') --> str[1] ('b')-->"cba" (no change)

        Recursive call permute("cba", 2)-->BASE CASE

        Prints "cba" (fifth permutation)

        Swap back str[1] ('b') --> str[1] ('b')-->"cba"

        Iteration 2 (j=2):
        Swap str[1] ('b') --> str[2] ('a')-->"cab"

        Recursive call permute("cab", 2)-->BASE CASE

        Prints "cab" (sixth permutation)

        Swap back str[1] ('a') --> str[2] ('b')-->"cba"

        Swap back str[0] ('c') --> str[2] ('a')-->"abc"

Final State:
String restored to original: "abc"
 */