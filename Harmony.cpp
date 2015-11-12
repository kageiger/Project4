int getNumberInRange(int min, int max) {
    // TODO: Read choice from user

    int userChoice;
    cin >> userChoice;
    cout << endl;
    // TODO: if user does not cooperate, read everything remaining on the line
    //       into a temp variable and keep asking
    while(userChoice < min || userChoice > max){
        if(cin.fail()){
            cin.clear();
            string str;
            getline(cin, str);
        }
        cout << "Invalid response! Please enter a number between ";
        cout << min << " and " << max << ": " << endl;
        
    }
    // DELETE THIS: returning an int to prevent compile error
    return userChoice;
}


bool quizHasBeenTaken(string fileName, string takenQuizFileNames[MAX_QUIZZES],
                      int numberOfQuizzesTaken) {
    // TODO: see if fileName is in the takenQuizFileNames array
    for(int i = 0; i < MAX_QUIZZES; i++){
        if(takenQuizFileNames[i] == fileName){
            ++numberOfQuizzesTaken;
            return true;
        }
    }
        // TODO: if yes, return true;

    // TODO: return false if not in the array

    // DELETE THIS: returning true to prevent compile error
    return false;
}
