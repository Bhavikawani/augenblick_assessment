#include<iostream>
#include <sstream>
#include <vector>

using namespace std;

int getHash(string& str) {
    int currentValue = 0;

    for (char ch : str) {
        int asciiCode = static_cast<int>(ch); // static cast function to get the ascii value of characters
        currentValue += asciiCode;
        currentValue *= 17;
        currentValue %= 256;
    }

    return currentValue;
}

vector<string> splitSequence(string& sequence) {
    
    vector<string> result;
    int start = 0;
    int length = sequence.length();
    char comma = ',';

    while (start < length) {
        int end = start;
        while (end < length && sequence[end] != comma) {
            ++end;
        }

        result.push_back(sequence.substr(start, end - start));

        // Move to the next non-comma character
        start = (end < length - 1) ? end + 1 : length;
    }

    return result;
}

int calculateSum(string& sequence) {
    vector<string> steps = splitSequence(sequence);

    int sum = 0;
    for (string& step : steps) {
        sum += getHash(step);
    }

    return sum;
}

int main()
{
    string initializationSequence = "rn=1,cm-,qp=3,cm=2,qp-,pc=4,ot=9,ab=5,pc-,pc=6,ot=7";

    
    int resultSum = calculateSum(initializationSequence);
    cout << "Sum of results: " << resultSum << endl;
    return 0;
}