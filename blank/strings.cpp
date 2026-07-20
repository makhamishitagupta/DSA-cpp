#include <iostream>
#include <string>
#include <algorithm> // reverse, transform
using namespace std;

int main()
{
    string s = "Hello123World";

    cout << "🔹 BASIC STRING OPERATIONS\n";

    // Length
    cout << "Length: " << s.length() << endl;

    // Access
    cout << "First char: " << s[0] << ", Last char: " << s[s.length() - 1] << endl;
    cout << "Character at (safe): " << s.at(1) << endl;

    // Substring
    cout << "Substring (0 to 4): " << s.substr(0, 5) << endl;

    // Append
    string a = "Hi", b = "There";
    a.append(b);
    cout << "Appended: " << a << endl;

    // Insert
    string ins = "Hello";
    ins.insert(2, "!!");
    cout << "Inserted: " << ins << endl;

    // Erase
    string er = "abcdef";
    er.erase(2, 2);
    cout << "Erased: " << er << endl;

    // Replace
    string rep = "GoodNight";
    rep.replace(4, 5, "Morning");
    cout << "Replaced: " << rep << endl;

    // Compare
    string x = "abc", y = "abd";
    cout << "Comparison result: " << x.compare(y) << " (0: equal, <0: less, >0: greater)" << endl;

    // Push and Pop
    string p = "Hello";
    p.push_back('!');
    cout << "After push_back: " << p << endl;
    p.pop_back();
    cout << "After pop_back: " << p << endl;

    // Swap
    string str1 = "ABC", str2 = "XYZ";
    str1.swap(str2);
    cout << "Swapped: str1=" << str1 << ", str2=" << str2 << endl;

    // Empty check
    string emptyStr = "";
    if (emptyStr.empty())
        cout << "String is empty!\n";

    cout << "\n🔹 SEARCHING AND FINDING\n";

    // Find
    cout << "Index of '123': " << s.find("123") << endl;

    // rfind (last occurrence)
    cout << "Last index of 'l': " << s.rfind("l") << endl;

    // find_first_of
    cout << "First vowel in '" << s << "': " << s.find_first_of("aeiouAEIOU") << endl;

    // find_last_of
    cout << "Last vowel in '" << s << "': " << s.find_last_of("aeiouAEIOU") << endl;

    // find_first_not_of
    string spaceStr = "    hello";
    cout << "First non-space index: " << spaceStr.find_first_not_of(" ") << endl;

    // Not found case
    if (s.find("zzz") == string::npos)
    {
        cout << "'zzz' not found in string\n";
    }

    cout << "\n🔹 CASE CONVERSION\n";

    // To upper and lower
    string up = s, low = s;
    transform(up.begin(), up.end(), up.begin(), ::toupper);
    transform(low.begin(), low.end(), low.begin(), ::tolower);
    cout << "Upper: " << up << "\nLower: " << low << endl;

    cout << "\n🔹 INPUT / OUTPUT & CONVERSIONS\n";

    // getline
    string fullLine;
    cout << "Enter a full line: ";
    getline(cin, fullLine);
    cout << "You entered: " << fullLine << endl;

    // stoi, to_string
    string numStr = "456";
    int number = stoi(numStr);
    cout << "String to int: " << number << ", Int to string: " << to_string(number + 10) << endl;

    cout << "\n🔹 MEMORY MANAGEMENT\n";

    // capacity, resize, shrink_to_fit
    string mem = "abc";
    cout << "Initial: " << mem << " (length: " << mem.length() << ", capacity: " << mem.capacity() << ")\n";
    mem.resize(10, '*');
    cout << "Resized: " << mem << endl;
    mem.shrink_to_fit(); // reduce capacity
    cout << "After shrink_to_fit (capacity might reduce): " << mem.capacity() << endl;

    return 0;
}
