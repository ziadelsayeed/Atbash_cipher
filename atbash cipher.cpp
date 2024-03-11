#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
string choose;
string word;
string version;
string version_choose(){//function to ask user about encryption and decryption version
    cout<<"please enter the number of version you want\n1-version one\n2-version two\n";
    cin>>version;
    return version;
}
string toUpper(string word){//this function convert all small alph. to capital
    int len = word.length();//take word’s length for loop
    for (int i = 0; i <= len; i++){
        if (word[i] >= 'a' && word[i] <= 'z')//check if alph. small or capital
            word[i] -= 32;
    }
    return word;}
string menu(string x){// start menu
    cout << "what do you want to do now?\n";
    cout << "1- Cipher a message\n2- Decipher a message\n3- exist\nPlease enter the selection number to be executed : ";
    cin >> choose;
    return choose;
    }
void cipher(string word1, string word2, int len, bool e)// function works on encoding and decoding words, and print output
{ 
    for (int i = 0; i < len / 2; i++){
        if (word1[i] >= 'A' && word1[i] <= 'Z'){//check if its not numbers or special characters 
            char s = word1[i];//make a copy to asci num of word1[i]
            char r = 'Z' - (s - 'A');//convert alph. using asci table
            word1[i] = r;
        }
    }
    for (int i = 0; i < len / 2; i++){
        if (word2[i] >= 'A' && word2[i] <= 'Z'){//check if its not numbers or special characters 
            char s = word2[i];
            char r = 'Z' - (s - 'A');//convert alph. using asci table
            word2[i] = r;
        }
    }
    if (choose == "1"){//for cipher
        if (e){
            version_choose();
            if(version=="1")//encrypion by version 1
            cout <<"Encryption is : "<< word1 << word2 << endl;
            else if(version=="2")//encrypion by version 1
            cout <<"Encryption is : "<< word2 << " " << word1 << endl;
            else{
                cout<<"please enter a valid choice!\n";
                version_choose();
            }
            }
        else
            cout <<"Encryption is : "<< word1 << " " << word2 << endl;
    }
    else if (choose == "2")//for decipher
    {
        if (e)
            cout <<"Decryption is : "<< word1 << word2 << endl;
        else{
            version_choose();
            if(version=="1")
            cout <<"Decryption is : "<<word1 << " " << word2 << endl;
            else if(version=="2")
            cout <<"Decryption is : "<<word2 << word1 << endl;
            else{
                cout<<"please enter a valid choice!\n";
                version_choose();

            }
    }
}
}
void encode(string word)
{//this function to divid words to 2 part for cipher version 2
    int len = word.length();
    bool z = true;
    string word1, word2;
    for (int i = 0; i < len; i++)// check if input consists of 2 word or 1 word, if 2 there space between of them
    {
        if (word[i] == ' ')
            z = false;// two words
    }
    if (z)// one word
    { 
        for (int i = 0; i < len / 2; i++)
            word1 += word[i];
        for (int t = len / 2; t < len; t++)
            word2 += word[t];
    }
    else {// if input consists of two words
        bool x = true;
        for (int i = 0; i < len; i++)
        {
            if (word[i] == ' ')
                x = false;//two words
            if (x)//one word
                word1 += word[i]; 
            else
            {
                if (word[i] == ' ')
                    i++;// To delete the space in front of the second word
                word2 += word[i];
            }
        } 
    }
    cipher(word1, word2, len, z);
}
void decode(string word)
{
    encode(word);
}
void atbash(){
    cout<<"hello to our program!\n";
    while (true){
        menu(choose);
        if (choose == "1")//cipher
        {
            cout << "Enter the word you want to encrypt it : ";
            cin.ignore(1, '\n');
            getline(cin, word);
            encode(toUpper(word));
        }
        else if (choose == "2")//decipher
        {
            cout << "Enter the word you want to decode it :";
            cin.ignore(1, '\n');
            getline(cin, word);
            decode(toUpper(word));
        }
        else if (choose == "3")
        {
            cout << "see you soon\n";
            return 0;
        }
        else
        {
            cout << "please enter a valid choice!\n";
        }
    }
}