//  Problem 2, Lab 1, Programming Languages
//  Tom Budny
//
//  This program will read the CSV file of Spotify's top 200 tracks,
//  store the titles and artists in an array,
//  and then search for the artists who appear most often in the list.
//  It's output will be a new top 5, ranking the artists who appear most 
//  often in the top 200 along with the names and positions of their tracks.

#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <array>

using namespace std;

struct Track {
    string title;
    string artist;    
};

void readFile(fstream& input, Track& list) {
    
}


int main() {

    ifstream is{"regional-global-daily-latest-short.csv"};
    ofstream os{"mostAppearingArtists.txt"};

//set<string> b {istream_iterator<Line>{is}, istream_iterator<Line>{}}; // Line instead of string
//copy(b.begin(), b.end(), ostream_iterator<string>{os, "\n"});
//return !is.eof() || !os;
    
    array<Track,201> top200;  // to hold the top 200 tracks from file
    string line;  //  to hold each line from file

    //  Consume file header: first two lines
    for (int i = 1; i < 3; i++) getline(is, line);
    
    //  Read each line from file and store title and artist in array
    while (getline(is, line)) {
        
        istringstream iss(line);  //  convert string to input stream
        
        string field;
        int token = 0;
        int num =0;
        while (getline(iss, field, ',')){
            //int num = 0;
            switch (token) {
                case 0:
                    cout << field << endl;
                    num = std::stoi(field);                    
                    break;
                case 1:
                    cout << field << endl;
                    top200[num].title = field;
                    break;
                case 2:
                    cout << field << endl;
                    top200[num].artist = field;
                    break;
                default:  //  All fields after the first three are skipped.
                    break;
            }
            ++token;
        }

    }
    
    cout << line;
    cout << top200[1].artist << endl;

    //cout << "And file.open status is " << is.is_open() << endl;
    is.close();
    os.close();
    
    cout << "And if my ....\n";
    //return 0;
    exit(0);
}