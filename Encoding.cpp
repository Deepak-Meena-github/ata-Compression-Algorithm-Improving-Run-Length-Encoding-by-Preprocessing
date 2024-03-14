#include <bits/stdc++.h>
using namespace std;
void file_io()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

struct rotation
{
    int index;
    char *suffix;
};

int cmpfunc(const void *x, const void *y)
{
    struct rotation *rx = (struct rotation *)x;
    struct rotation *ry = (struct rotation *)y;
    return strcmp(rx->suffix, ry->suffix);
}

int *computeSuffixArray(char *input_text, int len_text)
{
    struct rotation *suff = new struct rotation[len_text];

    for (int i = 0; i < len_text; i++)
    {
        suff[i].index = i;
        suff[i].suffix = (input_text + i);
    }

    qsort(suff, len_text, sizeof(struct rotation), cmpfunc);

    int *suffix_arr = new int[len_text];
    for (int i = 0; i < len_text; i++)
        suffix_arr[i] = suff[i].index;
         
         delete[] suff;
    return suffix_arr;
}

char *findLastChar(char *input_text, int *suffix_arr, int n)
{
    char *bwt_arr = new char[n];
    int i;
    for (i = 0; i < n; i++)
    {
        int j = suffix_arr[i] - 1;
        if (j < 0)
            j = j + n;

        bwt_arr[i] = input_text[j];
    }

    bwt_arr[i] = '\0';

    return bwt_arr;
}

unordered_map<char, int> frequencyCount(char *bwt_arr)
{
    unordered_map<char, int> frequencyMap;
    for (int i = 0; bwt_arr[i] != '\0'; ++i)
    {
        char currentChar = bwt_arr[i];

        if (frequencyMap.find(currentChar) == frequencyMap.end())
        {
            frequencyMap[currentChar] = 1;
        }
        else
        {
            frequencyMap[currentChar]++;
        }
    }

    return frequencyMap;
}
bool sortByFrequency(const pair<char, int> &a, const pair<char, int> &b)
{
    return a.second > b.second ? true : (a < b) ? true
                                                : false;
}

string intTo_8Bit_Binary(int n)
{
    std::string binNumber;
    for (int i = 7; i >= 0; --i)
    {
        binNumber += ((n & (1 << i)) ? '1' : '0');
    }
    return binNumber;
}

vector<pair<char, string>> dynamicByteRemaping(vector<pair<char, int>> frequencyVector)
{
    vector<pair<char, int>> remapMap;
    int remapValue = 0;
    for (const auto &entry : frequencyVector)
    {
        remapMap.push_back({entry.first, remapValue});
        remapValue++;
    }

    vector<pair<char, string>> remapInt8Map;

    for (auto remapVal : remapMap)
    {
        remapInt8Map.push_back({remapVal.first, intTo_8Bit_Binary(remapVal.second)});
    }

    return remapInt8Map;
}

string verticleByteReadings(vector<string> dynBit)
{
    string verticleByte;
    for (int i = 0; i < 8; i++)
    {
        for (const auto &entry : dynBit)
        {
            verticleByte += entry[i];
        }
        // verticleByte += "\n";
    }
    // cout << verticleByte;
    return verticleByte;
}

string charToBinary(char c)
{
    string binary;
    for (int i = 7; i >= 0; --i)
    {
        binary += ((c & (1 << i)) ? '1' : '0');
    }
    return binary;
}

vector<pair<char, int>> runLengthEncoding(string vBTOutput)
{
    int n = vBTOutput.length();
    vector<pair<char, int>> ans;
    vector<int> rleString;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (i < n - 1 && vBTOutput[i] == vBTOutput[i + 1])
        {
            count++;
            i++;
        }
        ans.push_back({vBTOutput[i], count});
    }
    return ans;
}
vector<string> Remapping(map<char, string> RemapeByteArray, char *bwt_arr)
{
    vector<string> RemapedByteArray;
    for (int i = 0; bwt_arr[i] != '\0'; ++i)
    {
        char currentChar = bwt_arr[i];
        RemapedByteArray.push_back(RemapeByteArray[currentChar]);
    }
    return RemapedByteArray;
}
int main()

{
    file_io();
    ifstream inputFile("your_input_file.txt"); // Replace "your_input_file.txt" with your actual file name
    if (!inputFile.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string str, str1;
    while (getline(inputFile, str))
    {
        str1 += str;
    }
    str1 = str1 + "$";
    str = str1;
    int len = str.length();
    char *forBWST = new char[len];
    for (int i = 0; i < len; i++)
    {
        forBWST[i] = str[i];
    }

    int *suffix_arr = computeSuffixArray(forBWST, len);
    // for(int i=0; i<len; i++){
    //     cout << suffix_arr[i] << " ";
    // }
    char *bwt_arr = findLastChar(forBWST, suffix_arr, len);
    // for(int i=0; i<len; i++){
    //     cout << charToBinary(bwt_arr[i]) << " ";
    // }

    unordered_map<char, int> frequencyMap = frequencyCount(bwt_arr);
    vector<pair<char, int>> frequencyVector(frequencyMap.begin(), frequencyMap.end());
    sort(frequencyVector.begin(), frequencyVector.end(), sortByFrequency);
    // for (const auto &entry : frequencyVector)
    // {
    //     cout << "Character: " << entry.first << ", Frequency: " << entry.second << endl;
    // }
    // cout << endl;
    // Dynamic Byte Remaping
    vector<pair<char, string>> dynBit = dynamicByteRemaping(frequencyVector);

    string saveMapAsString = "";

    for (const auto &entry : dynBit)
    {
        string s(1, entry.first);
        saveMapAsString += entry.second + s + "\n";
    }

    ofstream myfile;
    myfile.open("remapStore.txt");
    myfile << saveMapAsString;
    myfile.close();

    vector<char> dynBitChar;
    map<char, string> RemapeByteArray;
    for (const auto &entry : dynBit)
    {

        RemapeByteArray[entry.first] = entry.second;
    }
    vector<string> RemapedByteArray = Remapping(RemapeByteArray, bwt_arr);
    // for(auto i:RemapedByteArray){
    //     cout << i << " ";
    // }

    string vBTOutput = verticleByteReadings(RemapedByteArray);

    vector<pair<char, int>> RleOutput = runLengthEncoding(vBTOutput);

    for (const auto &entry : RleOutput)
    {
        cout << entry.second << " ";
    }
    delete[] forBWST;
     
    delete[] suffix_arr;
  
    delete[] bwt_arr;
    
    return 0;
}
