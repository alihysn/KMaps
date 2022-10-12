//
//  main.cpp
//  DigitaProj1Final
//
// By Amena Hassan and Ali Yassine.
//

#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <set>
#include <map>
using namespace std;

struct minterm {
    int decimal;
    string  binary;
    bool tick;
    int instances;
    int value;
};

struct pairs {
    vector<int>decimal;
    string binary;
    bool tick = false;
};

struct pairs2 {
    vector<int>decimal;
    string binary;
    bool tick;
};


vector<minterm>minterms;
int nummin;
int  num2;
void input2()
{
    cout << "Enter the number of minterms:";
    cin >> num2;
    while (num2 < -1 || num2>5)
    {
        cout << "Invalid Input" << endl;
        cout << "Enter the number of minterms (From 0 to ): " << endl;
        cin >> num2;
    }
    if (num2 == 0)
    {
        cout << "F=0" << endl;
    }

    if (num2 == 4)
    {
        cout << "F=1" << endl;
    }

    else
    {
        int temp;
        minterms.resize(num2);
        cout << "Enter the minterms:" << endl;

        for (int i = 0; i < minterms.size(); i++)
        {
            cin >> temp;
            if (temp > -1 && temp < 4)
            {
                minterms[i].decimal = temp;
                minterms[i].binary = bitset<2>(temp).to_string();
                minterms[i].tick = false;
            }

            else
            {
                cout << "Enter a valid input (From 0 to 3 only)." << endl;
            }
        }
        


    }
}
vector<vector<int>>kmap(2, vector <int>(4));
vector<vector<int>>kmap2(2, vector<int>(2));

void Kmap2()
{
    if (num2 == 4)
    {
        kmap2[0][0] = 1;
        kmap2[0][1] = 1;
        kmap2[1][0] = 1;
        kmap2[1][1] = 1;
    }
    else if (num2 == 0)
    {
        kmap2[0][0] = 0;
        kmap2[0][1] = 0;
        kmap2[1][0] = 0;
        kmap2[1][1] = 0;
    }
    for (int i = 0; i < minterms.size(); i++) {

        if (minterms[i].decimal == 0) { kmap2[0][0] = 1; }
        if (minterms[i].decimal == 1) { kmap2[1][0] = 1; }
        if (minterms[i].decimal == 2) { kmap2[0][1] = 1; }
        if (minterms[i].decimal == 3) { kmap2[1][1] = 1; }
    }

    cout << "The corressponding Kmap is:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 ;j++)
        {
            cout << kmap2[i][j] << " ";
        }
        cout << endl;
    }


}

void Expression2()
{
    if(kmap2[0][0] == 1 && kmap2[0][1] ==0 && kmap2[1][0] == 0 && kmap2[1][1] == 0)
    {
        cout << "F=A'B'";
    }
    else if (kmap2[0][0] == 0 && kmap2[0][1] == 0 && kmap2[1][0] == 1 && kmap2[1][1] == 0)
    {
        cout << "F=A'B";
    }
    else if (kmap2[0][0] == 0 && kmap2[0][1] == 1 && kmap2[1][0] == 0 && kmap2[1][1] == 0)
    {
        cout << "F=AB'";
    }
    else if (kmap2[0][0] == 0 && kmap2[0][1] == 0 && kmap2[1][0] == 0 && kmap2[1][1] == 1)
    {
        cout << "F=AB";
    }

    else  if (kmap2[0][0] == 1 && kmap2[0][1] == 1 && kmap2[1][0] == 0 && kmap2[1][1] == 0)
    {
        cout << "F=B'";
    }
    else if (kmap2[0][0] == 1 && kmap2[0][1] == 0 && kmap2[1][0] == 1 && kmap2[1][1] == 0)
    {
        cout << "F=A'";
    }
    else if (kmap2[0][0] == 0 && kmap2[0][1] == 1 && kmap2[1][0] == 0 && kmap2[1][1] == 1)
    {
        cout << "F=A";
    }
    else if (kmap2[0][0] == 0 && kmap2[0][1] == 0 && kmap2[1][0] == 1 && kmap2[1][1] == 1)
    {
        cout << "F=B";
    }
    else if (kmap2[0][0] == 1 && kmap2[0][1] == 1 && kmap2[1][0] == 1 && kmap2[1][1] == 0)
    {
        cout << "F=AB'+A'B";
    }
    else if (kmap2[0][0] == 1 && kmap2[0][1] == 0 && kmap2[1][0] == 0 && kmap2[1][1] == 1)
    {
        cout << "F=A'B'+AB";
    }
    //10 TILL NOW
    else if (kmap2[0][0] == 1 && kmap2[0][1] == 1 && kmap2[1][0] == 1 && kmap2[1][1] == 0)
    {
        cout << "F=A'+B'";
    }

    else if (kmap2[0][0] == 1 && kmap2[0][1] == 1 && kmap2[1][0] == 0 && kmap2[1][1] == 1)
    {
        cout << "F=A+B'";
    }
    else if (kmap2[0][0] == 1 && kmap2[0][1] == 0 && kmap2[1][0] == 1 && kmap2[1][1] == 1)
    {
        cout << "F=A'+B";
    }
    else if (kmap2[0][0] == 0 && kmap2[0][1] == 1 && kmap2[1][0] == 1 && kmap2[1][1] == 1)
    {
        cout << "F=A+B";
    }
      
}

void input()
{
    cout << "Enter number of minterms:";
    cin >> nummin;
    while (nummin < -1 || nummin > 9)
    {
        cout << "invalid input" << endl;
        cout << "Enter the number of minterms (From 0 to 8): " << endl;
        cin >> nummin;
    }

    if (nummin == 0)
    {
        cout << "F=0"<<endl;
    }

    else if (nummin == 8)
    {
        cout << "F=1" << endl;
    }
    else
    {
        int temp;
        minterms.resize(nummin);
        cout << "Enter the minterms:" << endl;

        for (int i = 0; i < minterms.size(); i++)
        {
            cin >> temp;
            if (temp > -1 && temp < 8) 
            {
                minterms[i].decimal = temp;
                minterms[i].binary = bitset<3>(temp).to_string();
                minterms[i].tick = false;
            }

            else
            {
                cout << "Enter a valid input (From 0 to 7 only)." << endl;
            }
        }
    }
}


void Kmap3()
{
    if (nummin == 8)
    {
        kmap[0][0] = 1;
        kmap[1][0] = 1;
        kmap[0][1] = 1;
        kmap[1][1] = 1;
        kmap[0][3] = 1;
        kmap[1][3] = 1;
        kmap[0][2] = 1;
        kmap[1][2] = 1;

    }
    else if (nummin == 0)
    {
        kmap[0][0] = 0;
        kmap[1][0] = 0;
        kmap[0][1] = 0;
        kmap[1][1] = 0;
        kmap[0][3] = 0;
        kmap[1][3] = 0;
        kmap[0][2] = 0;
        kmap[1][2] = 0;

    }
    for (int i = 0; i < minterms.size(); i++) {

        if (minterms[i].decimal == 0) { kmap[0][0] = 1; }
        if (minterms[i].decimal == 1) { kmap[1][0] = 1; }
        if (minterms[i].decimal == 2) { kmap[0][1] = 1; }
        if (minterms[i].decimal == 3) { kmap[1][1] = 1; }
        if (minterms[i].decimal == 4) { kmap[0][3] = 1; }
        if (minterms[i].decimal == 5) { kmap[1][3] = 1; }
        if (minterms[i].decimal == 6) { kmap[0][2] = 1; }
        if (minterms[i].decimal == 7) { kmap[1][2] = 1; }
    }

    cout << "The corressponding Kmap is:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++)
        {
            cout << kmap[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<minterm>> group(4);

void groupingOnes() {
    if (nummin == 0 || nummin == 8)
    {
        return;
    }
    int count = 0;
    for (int i = 0; i < nummin; i++) {
        for (int j = 0; j < 3; j++) {
            if (minterms[i].binary[j] == '1') {
                count++;
            }
        }
        group[count].push_back(minterms[i]);
        count = 0;
    }
}

vector<vector<pairs>> matching_pairs(3);
vector<minterm> primeImps;
map<string, vector<int>> EPIs;
vector<vector<pairs2>> matching4s(2);

void grouping() {
    if (nummin == 0 || nummin == 8)
    {
        return;
    }
    int counterTick = 0;
    int index, counter = 0;

    for (int i = 0; i < group.size() - 1; i++) {
        for (int j = 0; j < group[i].size(); j++) {
            for (int k = 0; k < group[i + 1].size(); k++) {
                for (int l = 0; l < 3; l++) {
                    if (group[i][j].binary[l] != group[i + 1][k].binary[l]) {
                        counter++;
                        index = l;
                    }
                }
                if (counter == 1) {
                    pairs temp;
                    temp.decimal.push_back(group[i][j].decimal);
                    temp.decimal.push_back(group[i + 1][k].decimal);
                    temp.binary = group[i][j].binary;
                    temp.binary[index] = '-';
                    temp.tick = false;
                    matching_pairs[i].push_back(temp);
                    group[i][j].tick = true;
                    group[i + 1][k].tick = true;
                }
                counter = 0;
            }
        }
    }
    for (int i = 0; i < group.size(); i++) {
        for (int j = 0; j < group[i].size(); j++) {
            if (group[i][j].tick == false) {
                primeImps.push_back(group[i][j]);
                vector<int> temp;
                temp.push_back(group[i][j].decimal);
                EPIs.insert(make_pair(group[i][j].binary, temp));
            }
            else {
                counterTick++;
            }
        }
    }
    if (counterTick == 0) {
        for (auto const i : matching_pairs)
            for (auto const k : i) {
                EPIs.insert(make_pair(k.binary, k.decimal));
            }
        return;
    }
    counterTick = 0;
    index = 0;
    counter = 0;

    for (int i = 0; i < matching_pairs.size() - 1; i++) {
        for (int j = 0; j < matching_pairs[i].size(); j++) {
            for (int k = 0; k < matching_pairs[i + 1].size(); k++) {
                for (int l = 0; l < 3; l++) {
                    if (matching_pairs[i][j].binary[l] != matching_pairs[i + 1][k].binary[l]) {
                        counter++;
                        index = l;
                    }
                }
                if (counter == 1) {
                    pairs2 temp;
                    temp.decimal.insert(temp.decimal.end(), matching_pairs[i][j].decimal.begin(), matching_pairs[i][j].decimal.end());
                    temp.decimal.insert(temp.decimal.end(), matching_pairs[i + 1][k].decimal.begin(), matching_pairs[i + 1][k].decimal.end());;
                    temp.binary = matching_pairs[i][j].binary;
                    temp.binary[index] = '-';
                    temp.tick = false;
                    matching4s[i].push_back(temp);
                    matching_pairs[i][j].tick = true;
                    matching_pairs[i + 1][k].tick = true;
                }
                counter = 0;
            }
        }
    }
    for (auto const i : matching_pairs) {
        for (auto const k : i) {
            if (k.tick == false) {

                EPIs.insert(make_pair(k.binary, k.decimal));
            }
            else {
                counterTick++;
            }
        }
    }
    if (counterTick == 0) {
        for (const auto i : matching4s) {
            for (const auto j : i) {
                EPIs.insert(make_pair(j.binary, j.decimal));
            }
        }
        return;
    }

    counterTick = 0;
    index = 0;
    counter = 0;
    for (const auto i : matching4s)
        for (const auto j : i)
            EPIs.insert(make_pair(j.binary, j.decimal));
}

vector<string> Essential;

void expression() {
    if (nummin == 0 || nummin == 8)
        return;
    for (int j = 0; j < nummin; j++) {
        for (const auto i : EPIs)
            for (const auto k : i.second) {
                if (minterms[j].decimal == k)
                    minterms[j].instances++;
            }
        if (minterms[j].instances == 1) {
            for (const auto m : EPIs)
                for (const auto n : m.second) {
                    if (minterms[j].decimal == n) {
                        if (find(Essential.begin(), Essential.end(), m.first) == Essential.end()) {
                            Essential.push_back(m.first);
                        }
                    }
                }
        }
    }
    int e = Essential.size();
    cout << endl << "Minimized f= ";
    for (const auto i : Essential)
    {
        for (int j = 0; j < i.size(); j++)
        {
            if (j == 0)
            {
                if (i[j] == '0')
                    cout << "A'";
                else if (i[j] == '1')
                    cout << "A";
            }
            if (j == 1)
            {
                if (i[j] == '0')
                    cout << "B'";
                else if (i[j] == '1')
                    cout << "B";
            }
            if (j == 2)
            {
                if (i[j] == '0')
                    cout << "C'";
                else if (i[j] == '1')
                    cout << "C";
            }
        }
        if (e - 1 > 0)
        {
            cout << " + ";
            e--;
        }
    }
}


int main()
{
    int vars;
    cout << "Enter number of variables: " << endl;
    cin >> vars;

    while (vars != 2 && vars != 3)
    {
        cout << "Enter a valid number (either 2 or 3)." << endl;
        cin >> vars;
    }
    if (vars == 3) {
        input();
        Kmap3();
        groupingOnes();
        grouping();
        expression();
    }

    else if (vars == 2)
    {
        input2();
        Kmap2();
        Expression2();
    }
}
