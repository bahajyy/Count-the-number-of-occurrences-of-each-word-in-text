// Baha Jiyan Yılmaz 19070006010
#include "binary_tree.h"
#include "linklist.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include<ctype.h>

using namespace std;

string stripAndNormalize(string in)   //This function deletes the irregular chars from words.
{
    string final;
    for(int i = 0; i < in.length(); i++)
    {
        if(isalpha(in[i]))
        {
            in[i]=tolower(in[i]);
            final += in[i];
        }
    }
    return final;
}

bool isEnglish(char letter) //Checks is given char in english alphabet
{
    if (isalpha(letter)==0)
        return false;
    else
        return true;
}

bool isUpperCase(char letter) //Checks is given word's chars is upper letter
{
    if (isupper(letter)==0)
        return false;
    else
        return true;
}

LinkList<string> readFile(string path)
{
    path="../example_text.txt";
    ifstream read_file;
    read_file.open(path);
    if (!read_file.is_open())
    {
        cerr << "File  could not be opened" << endl;
        exit(1);
    }
    string sentences[1000]; //Keep every sentence in text line by line in this string
    string line;
    int lineNo=0;

    while (getline(read_file, line))
    {
        sentences[lineNo]=line;
        lineNo++;
    }
    read_file.close();

    string words[10000]; // Keep every words in text sentences in this string

    int count=0; //counter of number of words in text
    for (int i = 0; i < sentences->length(); ++i)
    {
        string temp=sentences[i];
        string newWord="";
        for (auto x:temp) 
        {
            if (x == ' '){
                words[count]= stripAndNormalize(newWord);
                newWord="";
                count++;
            } else{
                newWord+=x;
            }
        }
        words[count]= stripAndNormalize(newWord);
        count++;
    }

    LinkList<string> listOfWords = LinkList<string>(); //Create a link list to add words.

    listOfWords.head->data=words[0]; // Head of link list is the first word in text.
    for (int i = 1; i <count ; ++i) {
        listOfWords.head->next->data=words[i]; //Add words to next node every time.
    }

    return listOfWords;
}

BinaryTree<string> insertWords(LinkList<string> lines) // Adding elements in link list to binary tree
{
    BinaryTree<string> wordsTree =BinaryTree<string>();

    while (lines.head->next != NULL) //While link list is not empty.
    {
        if (wordsTree.search(lines.head->data) == NULL) // It checks if this word is added already or not.
        {
            wordsTree.root->data=lines.head->data;
            wordsTree.iterativeInsert(wordsTree.root);
        }
        else
        {
            wordsTree.root->counter++; // I added binary_tree.h counter for counting word occurences.
        }
    }
    return wordsTree;
}

void writeFile(BinaryTree<string> text) // Write the file from binary tree
{
    string outlinePath="../output.txt";

    ofstream fout;
    fout.open(outlinePath);

    if (text.root==NULL) // If tree is empty it returns.
        return;
    else
    {
        while (text.root->left != NULL) // for alphabatical order it first writes the left nodes.
        {
            fout<< text.root->left->counter << " " << text.root->left->data <<endl;
        }
        fout<< text.root->counter << " " << text.root->data <<endl; //Root is on the middle
        while (text.root->right != NULL) // If there is no left node, it start writing right nodes
        {
            fout<< text.root->right->counter << " " << text.root->right->data <<endl;
        }
    }
    fout.close();
}

/*void traverseTree(BinaryTree<string> wordsTree)
{
    while(wordsTree.root!=NULL)
    {
        string min= wordsTree.minData();
        writeFile(wordsTree);
        wordsTree.deleteNode(min);
    }
}*/

int main()
{
    string path;
    writeFile(insertWords(readFile(path)));
    return 0;
}
