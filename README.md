# Count-the-number-of-occurrences-of-each-word-in-text

Write a program in C++ (as a cpp file) to scan one text file (input.txt) and count the number of occurrences of each word in this file.
You should also print the number of distinct words. Use a binary search tree to keep track of all words.
When the input file has been scanned, print out the results to an output file (output.txt).
After reading a word from an input file, search for it in the tree and add it to the tree if it is not found. If it is found, increment the counter of the node.
Once the file has been read and closed, you must write out the words in the tree in alphabetical order, one word per line, along with the number of occurrences of that word.

Notes :
Your program should ignore the case of the words so that "This" and "this" are considered the same.
Your program should strip any non-English characters so that the words such as :
"I'","can't"," do ","This.","homework!!" will be "I","cant","do","This","homework"
Write the "strip" function using iteration by yourself. Don't use regex or in-built one-line codes.
The words spelled differently — such as "car" and "cars" — are considered different words.
!! Don't write your entire code in a file read/write loop. Use a Linklist to store lines and work over that link list.

Input File Format :
At least 20 lines without any skips(empty lines).
Each line must contain at least ten words, including articles (the, a, an, etc.).
You must separate the words with spaces.
The end of the lines must vary. They can end with a comma, dot, without any trailing character, etc.
