#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// Function to read a FASTA file and store sequences in a vector of pairs
vector<pair<string, string>> readFastaFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return {};
    }

    vector<pair<string, string>> sequences;// Vector to store sequences
    string line;
    bool firstLine = true;
    pair<string, string> currentSequence;// Pair to store current sequence

    while (getline(file, line)) {
        if (firstLine) {
            if (line.empty() || line[0] != '>') {
                cerr << "Invalid FASTA format: First line must start with '>'" << endl;
                return {};
            }
            currentSequence.first = line;
            firstLine = false;
        } else {
            if (line[0] == '>') {
                sequences.push_back(currentSequence);
                currentSequence.first = line;
                currentSequence.second.clear();
            } else {
                for (size_t i = 0; i < line.length(); ++i) {
                    char c = line[i];
                    if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
                        cerr << "Invalid FASTA format: Invalid character '" << c << "' at position " << i << endl;
                        return {};
                    }
                }
                currentSequence.second += line;
            }
        }
    }

    if (!currentSequence.first.empty()) {
        sequences.push_back(currentSequence);
    }

    file.close();
    return sequences;
}

// Function to get the reverse complement of a DNA sequence
string getReverseComplement(const string& sequence) {// Function to get the reverse complement of a DNA sequence
    string reverseComplement = sequence;
    reverse(reverseComplement.begin(), reverseComplement.end());
    for (char& c : reverseComplement) {
        switch (c) {
            case 'A': c = 'T'; break;
            case 'T': c = 'A'; break;
            case 'C': c = 'G'; break;
            case 'G': c = 'C'; break;
        }
    }
    return reverseComplement;
}

// Function to extract a subsequence from a DNA sequence
string getSubsequence(const string& sequence, size_t start, size_t length) {
    if (start >= sequence.length()) {
        return "";
    }
    return sequence.substr(start, length);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <path_to_fasta_file>" << endl;
        return 1;
    }

    vector<pair<string, string>> sequences = readFastaFile(argv[1]);

    cout << "Number of sequences: " << sequences.size() << endl;

    for (const auto& seq : sequences) {
        cout << "Header: " << seq.first << endl;
        cout << "Sequence: " << seq.second << endl;
        cout << "Reverse Complement: " << getReverseComplement(seq.second) << endl;
        cout << "Subsequence (0, 10): " << getSubsequence(seq.second, 0, 10) << endl;// Extract subsequence from position 0 of length 10
    }

    return 0;
}
