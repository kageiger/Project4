/**
* harmony.cpp
*
* Katherine Geiger, Keyaria Walker
* kageiger, keyariaw
*
* EECS 183: Project 4
*
* A program to match users based on answers to a personality quiz
*/

#include "harmony.h"


int main() {
    printOpeningMessage();

    //declare a variable of datatype Personality
    Personality k;

    string allnames[MAX_QUIZZES];
    int numQuizzes = 0;
    //     declare variables to keep track of:
    //     all the filenames of the quizzes that have been taken
    //     and the number of quizzes that have been taken


    bool done = false;

    while (!done) {

        printMenu();

       int userInput = 5;
       getNumberInRange(1, 5);
        

        // TODO: read which menu choice the user wants from the keyboard
        //       make sure it's within range


        if (userInput == 1) {
            // TODO: if user has taken all the quizzes, print message,
            //       repeat while loop
            while (numQuizzes == MAX_QUIZZES) {

                cout << "You have already taken the maximum number of quizzes!"
                    << endl;
                printMenu();
                cin >> userInput;
                getNumberInRange(1, 5);

            }
            if (numQuizzes != MAX_QUIZZES) {
                ifstream theFile;
                string fileName = openFile(theFile);
                

                if (quizHasBeenTaken(fileName, allnames, numQuizzes)) {
                    cout << "You've already taken that quiz!" << endl;
                } else{
                    allnames[numQuizzes] = fileName;
                    takeQuiz(theFile, k);
                    numQuizzes++;
                }
               
            }

            // TODO: else, create an input stream instance, ask user for
            //       name of file to open and
            //       then open the file for reading
            //       (you have a function that does most of this)

            //       TODO: check if quiz has been taken,
            //             print message if it has


            //       TODO: make sure to save the new file name to keep track
            //             which quizzes have been taken before you take the quiz

            //       TODO: Take the quiz!
            //             and update how many quizzes you have taken

        }
        else if (userInput == 2) {
            k.write(cout);

        }
        else if (userInput == 3) {
            // TODO: save personality profile to file
            saveProfile(k);

        }
        else if (userInput == 4) {
            k.reset();

        }
        else if (userInput == 5) {
            // time to end the loop!
            done = true;
            cout << endl;
        }
    }

    printClosingMessage();
    return 0;
}


/**
* You must implement the following functions.
*/


int getNumberInRange(int min, int max) {
    // TODO: Read choice from user
    int userChoice = 0;
    cin >> userChoice;
    // TODO: if user does not cooperate, read everything remaining on the line
    //       into a temp variable and keep asking
    while (cin.fail() || userChoice < min || userChoice > max ) {
        if (cin.fail()) {

            cin.clear();
            string str;
            getline(cin, str);
        }
        cout << "Invalid response! Please enter a number between ";
        cout << min << " and " << max << ": " << endl;
        cin >> userChoice;
        cout << endl;
    }
    // DELETE THIS: returning an int to prevent compile error
    return userChoice;
}


bool quizHasBeenTaken(string fileName, string takenQuizFileNames[MAX_QUIZZES],
    int numberOfQuizzesTaken) {
    // TODO: see if fileName is in the takenQuizFileNames array
    for (int i = 0; i < MAX_QUIZZES; i++) {
        if (takenQuizFileNames[i] == fileName) {
            return true;
        }
    }
    // TODO: if yes, return true;

    // TODO: return false if not in the array

    // DELETE THIS: returning true to prevent compile error
    return false;
}


void takeQuiz(ifstream &quizFile, Personality &personality) {
    // You are provided most cout statements for this function.
    // Hint: they are logically ordered according to how you must check
    // for errors and how the quiz is to be printed out.
    // Make sure to refer to the web spec. for the quiz file format
    string quizTitle;
    int numQuestions;
    // TODO: get quiz title from the file
    getline(quizFile, quizTitle);
    // TODO: print out a blank line, the name of the quiz, and a newline
    cout << endl << quizTitle << endl;
    // TODO: read the number of questions from the file
    quizFile >> numQuestions;
    // TODO: loop through all the questions

    // TODO: declare a variable of datatype Question
    //       use this instance to read the next question from the file
    //       (you have a member function that does this)
    //       think about what datatype you have and that you are asked
    //       to read from a file.  What does this get you?
    for (int i = 0; i < numQuestions; i++) {
        Question getIt;
        getIt.read(quizFile);


        cout << endl << "Question ";
        cout << i + 1; // TODO: Put the question number here
        cout << " out of ";
        cout << numQuestions << endl; // TODO: Put your variable name here that tracks
                              //       the number of questions
        cout << endl << endl;
        getIt.write(cout);
        cout << endl;
        // TODO: Print the question to cout

        cout << endl << "Enter your answer: ";
        int userPick;
        cin >> userPick;
        Attribute theAttribute = getIt.getAttributeOfAnswer(userPick);

     
        personality.adjustPersonality(theAttribute);

    }
    // TODO: Read the answer from the keyboard, making sure that is within
    //       range.  You have a function to assist with this

    // TODO: get the attribute of the answer chosen by user
    //       (you have a member function in Question to assist with this)

    // TODO:  apply that attribute to the personality instance
    //       (you have a member function in Personality to assist with this)


    cout << endl << "Congratulations, you've finished the quiz!" << endl
        << "Be sure to take a look at your updated"
        << " EECS Harmony Personality Profile!"
        << endl;
    quizFile.close();
    // TODO: Close the file
}


/**
* Do NOT change implementations of the following functions.
*/

string openFile(ifstream &inFile) {

    // get file name from user
    cout << endl << "Enter the quiz input file name: ";
    string quizFileName;
    cin >> quizFileName;

    // attempt to open file
    inFile.open(quizFileName.c_str());

    // keep asking until file is open
    while (!inFile) {
        inFile.clear();
        cout << "Couldn't open quiz input file!" << endl;
        cout << "Enter the quiz input file name: ";
        cin >> quizFileName;
        inFile.open(quizFileName.c_str());
    }

    return quizFileName;
}

void printOpeningMessage() {
    cout << "*************************************************" << endl
        << "*****             Welcome to the            *****" << endl
        << "*****    EECS Harmony Friendship Machine    *****" << endl
        << "*************************************************" << endl;
}

void printMenu() {
    cout << endl
        << "1) Take the Quiz" << endl
        << "2) Print Your Personality Profile" << endl
        << "3) Save Personality Profile to File" << endl
        << "4) Reset Personality Profile" << endl
        << "5) Quit" << endl << endl
        << "Enter command: ";
}

void printClosingMessage() {
    cout << "*************************************************" << endl
        << "*****        Thank you for using the        *****" << endl
        << "*****    EECS Harmony Friendship Machine    *****" << endl
        << "*************************************************" << endl;
}

void saveProfile(Personality &p) {
    // uncomment once you have written all the functions for Personality.cpp
    /*
    stringstream whatIsThis;p.write(whatIsThis);int $;string soComplex;
    whatIsThis>>soComplex;int onbegrijpelijkharibo = 0;int $$$ = 2;int ___ =
    static_cast<int>(soComplex.length())+whatIsThis.good();
    ofstream xyz(OUTPUT_FILE_NAME);for(unsigned int x=xyz.good();x<___;x++)
    {whatIsThis>>soComplex;$$$ += 1;}for (unsigned int __=0;
    $$$*=8,$=71, __<___; onbegrijpelijkharibo+=1){for(;___>__;--___)
    {whatIsThis>>soComplex;onbegrijpelijkharibo = 10*isdigit(soComplex[
    soComplex.length() - 2*whatIsThis.good()]);onbegrijpelijkharibo +=
    soComplex[soComplex.length() - whatIsThis.good()] - $$$;
    xyz<<static_cast<char>(onbegrijpelijkharibo*___+$)<<'|';}}xyz.close();
    */

}
