vector<string>SplitString(string S, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S.find(Delim)) != std::string::npos)
    {
        sWord = S.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S.erase(0, pos + Delim.length()); /* erase() until
        positon and move to next word. */
    }
    if (S != "")
    {
        vString.push_back(S); // it adds last word of the string.
    }
    return vString;
}

vector<string> ChangWord(vector<string>vString, string Word, string WordToReplace)
{

    vector<string>::iterator iter = vString.end();

    while (iter != vString.begin())
    {
        --iter;
        if (*iter == Word)
        {
            *iter = WordToReplace;
        }
    }


    return vString;
}

string JoinString(vector<string>vString, string Delim)
{
    string S1 = "";

    for (string& Elemnet : vString)
    {
        S1 = S1 + Elemnet + Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());

}

string ReplaceWordInString(string S1, string Delim, string Word, string WordToReplace)
{
    vector<string>vS;
    vS = SplitString(S1, Delim);
    vS = ChangWord(vS, Word, WordToReplace);

    return JoinString(vS, Delim);
}