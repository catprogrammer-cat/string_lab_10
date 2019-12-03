#include <iostream>
#include <stdlib.h>     
#include <time.h>
#include <stdio.h> // for gets, puts;
#include <conio.h> // for getch();
#include <string.h> // for strlen (s); necessary in online compiler
#include <cctype>

using namespace std;

void del_word(char * s, int k, int n)
{ 
    char *s1=new char [strlen(s)+1];
    strncpy(s1, s, k); s1[k]='\0';
    strcat(s1, s+k+n+1);
    strcpy(s,s1);
    delete [] s1;
}

int main()
{
    int i, kol=0, p1=-1, p2=-1;
    char * s=new char [100];
    puts(" Enter a string:");
    gets(s);

    strcat(s," ");
    // for (i=0; s[i]!='\0'; i++){
    //     if(s[i]==' '){
    //         if(p1==-1){
    //             p1=i;
    //         }
    //         else {
    //             p2=i; break;
    //         }    
    //     }
    // }

    int counter_length = 0;
    for(int i=0; s[i]!='\0';i++){

        counter_length++;

    }
    counter_length--; // need to exclude length on -1 becouse empty space we dont need
    cout << "Counter_length: " << counter_length << endl;

    int counter_word = 0;
    for(int i=0; s[i]!='\0';i++){
        if(s[i] == ' '){
            counter_word++;
            
        }
    }
    cout << "Counter_word: " << counter_word << endl;

    //find length last word
    int counter_last_word = 0;
    for (int i=counter_length-1;s[i] != ' '; i--){
        counter_last_word++;    
    }
    cout << "Counter_last_word: " << counter_last_word << endl;


    int range_2 = counter_length - counter_last_word;
    cout << "Range_2: " << range_2 << endl;

    int counter_next_to_the_last_word = 0;
    for(int i=range_2-2; s[i] != ' '; i--){
        counter_next_to_the_last_word++;
    }
    cout << "Counter_next_to_the_last_word: " << counter_next_to_the_last_word << endl;

    int range_1 = range_2 - counter_next_to_the_last_word;
    // del_word(s, p1+1, p2-p1-1);
    
    del_word(s, range_1-1, counter_next_to_the_last_word-1);
    cout << endl;
    cout << endl;
    cout << "range_1: " << range_1 << endl;
    cout << "range_2: " << range_2 << endl;

    int next_to_the_last_word = range_2 - range_1;

    // for(int i=range_1;i<next_to_the_last_word;i++){
    //     s[i] = ' ';
    // }

    

    puts("\n The string without next to the last word");
    puts (s);
    delete [] s;
    system("pause");
    return 0;
}
