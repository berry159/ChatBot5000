//code by E. R. v.1
#include <iostream>
#include <string>
#include <cstring>
#include <time.h>
#include <fstream>

using namespace std;

void answer();
void askQuestion();
void emotions();
void randomSay();

int main()
{
    string text; // this is where your text will be stored. We overwrite it as you say something new.
    cout << "You are chatting with a bot. Say something! Don't forget to use '.', '!', '?'." << endl;

    while(1) // this chat can go on forever.
    {
        cin >> text; // you'r input
        int n = text.length(); // length of your text
        char char_array[n + 1]; // creating an array to put your text string to
        strcpy(char_array, text.c_str()); // copying string to char. We need this so we can check what is the last symbol you inputed

        // we go to function to continue our chat depending on the last symbol inputed.
        if(char_array[n-1] == '?') answer();
        else if(char_array[n-1] == '.') askQuestion();
        else if(char_array[n-1] == '!') emotions();
        else if (char_array[n-1] != '?' && char_array[n-1] != '!' && char_array[n-1] != '.')randomSay();
    }
    return 0;
}

void answer()
{
    srand(time(NULL)); // function for random numbers.
    int k = 15; // the number of lines in the txt document. It was easier for me to input them there,
                // rather than write all the questions here.
    int randIndex = rand() % (k+1); // creating a random number, we use this to choose the line from our document.
    string randomAnswers[k]; // creating an array to put lines from document
    string line; // we use this to read one line at a time
    ifstream f("answers.txt"); // opening our txt to read
    int i = 0;
  if (f.is_open()) // checks if our document has opened correctly
    {
        while (!f.eof()) // we read from our document while it is not the end of it
        {
            getline(f,line); //reading every line from f document and putting it into line
            randomAnswers[i] = line; // putting line in to our array
            i++;
        }
        f.close(); // closing our document
    }

    cout << randomAnswers[randIndex] << endl; // printing a random line from our array of lines. As we ask similar questions,
                                              // the process is repeated, thus it is not very optimal, we use space over and over again
                                              // and use code lines that we already used.
}

// we repeat this multiple times for every ending of your inputed text
void  askQuestion()
{
    srand(time(NULL));
    int k = 15;
    int randIndex = rand() % (k+1);
    string randomQuestions[k];
    string line;
    ifstream f("questions.txt");
    int i = 0;
    if (f.is_open())
    {
        while (!f.eof())
        {
            getline(f,line);
            randomQuestions[i] = line;
            i++;
        }
        f.close();
    }

    cout << randomQuestions[randIndex] << endl;
}

void emotions()
{
    srand(time(NULL));
    int k = 15;
    int randIndex = rand() % (k+1);
    string randomEmotion[k];
    string line;
    ifstream f("emotions.txt");
    int i = 0;
    if (f.is_open())
    {
        while (!f.eof())
        {
            getline(f,line);
            randomEmotion[i] = line;
            i++;
        }
        f.close();
    }

    cout << randomEmotion[randIndex] << endl;
}

void randomSay()
{
    srand(time(NULL));
    int k = 15;
    int randIndex = rand() % (k+1);
    string random[k];
    string line;
    ifstream f("randomSay.txt");
    int i = 0;
    if (f.is_open())
    {
        while (!f.eof())
        {
            getline(f,line);
            random[i] = line;
            i++;
        }
        f.close();
    }

    cout << random[randIndex] << endl;
}
