#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Fonction pour lire un fichier FASTA et stocker les séquences dans un vecteur
vector<string> lireFasta(const string& cheminFichier) {
    ifstream fichier(cheminFichier);
    vector<string> sequences;
    string ligne, sequence;
    
    if (!fichier) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << endl;
        return sequences;
    }
    
    while (getline(fichier, ligne)) {
        if (ligne.empty()) continue;
        if (ligne[0] == '>') { // Identificateur d'une nouvelle séquence
            if (!sequence.empty()) {
                sequences.push_back(sequence);
                sequence.clear();
            }
        } else {
            sequence += ligne; // Concaténer les lignes de la séquence
        }
    }
    if (!sequence.empty()) {
        sequences.push_back(sequence);
    }
    
    return sequences;
}

// Fonction pour indexer les k-mers dans une structure de données
unordered_map<string, vector<int>> indexerKmers(const string& sequence, int k) {
    unordered_map<string, vector<int>> indexKmers;
    for (size_t i = 0; i <= sequence.size() - k; ++i) {
        string kmer = sequence.substr(i, k);
        indexKmers[kmer].push_back(i);
    }
    return indexKmers;
}

int main() {
    string cheminFichier = "genome.fasta"; // À remplacer par votre fichier
    vector<string> sequences = lireFasta(cheminFichier);
    
    cout << "Nombre de séquences lues : " << sequences.size() << endl;
    if (!sequences.empty()) {
        int k = 10; // Taille des k-mers
        unordered_map<string, vector<int>> indexKmers = indexerKmers(sequences[0], k);
        
        cout << "Indexation des " << k << "-mers terminée. Nombre total de k-mers uniques : " << indexKmers.size() << endl;
    }
    
    return 0;
}
