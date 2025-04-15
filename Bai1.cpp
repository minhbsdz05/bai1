#include <iostream>
#include <map>
#include <cmath>
#include <string>
using namespace std;

double calculate_entropy(const string& text) {
    map<char, int> freq;
    for (char c : text) freq[c]++;
    double entropy = 0.0;
    for (auto& pair : freq) {
        double p = (double)pair.second / text.size();
        entropy -= p * log2(p);
    }
    return entropy;
}

int main() {
    string input;
    cout << "Enter a string of characters: ";
    getline(cin, input);

    double H = calculate_entropy(input);
    cout << "Entropy: " << H << " bits/character" << endl;

    const int N = 256; // Số ký tự trong bảng mã ASCII
    double max_entropy = log2(N);
    double redundancy = max_entropy - H;

    cout << "Redundancy: " << redundancy << " bits/character" << endl;

    return 0;
}
// Giả sử bạn nhập chuỗi:
// aaaaabbbbcc
// Kết quả có thể là:
// Entropy: 1.48548 bits/character
// Redundancy: 6.51452 bits/character