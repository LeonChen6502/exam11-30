//=============================================================================
//     PROGRAMMER : B12611009
//     DATE       : 2023-10-10
//     FIELNAME   : HW04DB12611009.CPP
//     DESCRIPTION: This is a program that find words
//=============================================================================
 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer1;        // Store the total number of movies listed in the RatingList.txt file.
int answer2;        // Store the total number of ratings in the RatingList.txt file.
double answer3;     // Store the highest average rating in the list.

class review{
    private:
        string movie_title;
        int total_score;
        int num_rating;
        double ave_score;
    public:
        string getMovieTitle();
        int getTotalScore();
        int getNumRating();
        double getAveScore();
        void setMovieTitle(string s);
        void setTotalScore(int n);
        void setNumRating(int n);
        void setAveScore(double n);
        void addscore(int n);
        double calculateAveScore();

 };
 string review::getMovieTitle(){
    return movie_title;
 }
 int review::getTotalScore(){
    return total_score;
 }
 int review::getNumRating(){
    return num_rating;
 }
 double review::getAveScore(){
     return ave_score;
 }
 void review::setMovieTitle(string s){
    movie_title = s;
 }
 void review::setTotalScore(int n){
    total_score = n;
 }
 void review::setNumRating(int n){
    num_rating = n;
 }
 void review::setAveScore(double n){
    ave_score = n;
 }
 void review::addscore(int n){
    total_score += n;
 }
 double review::calculateAveScore(){
    return double(total_score)/num_rating;
 }

 bool comparestr(string a,string b){
   string a1,b1;
   for(int i=0;i<int(a.length());i++){
      if(a[i]!=' ' and a[i]!='\n'){
         a1+=a[i];
      }
   }
   for(int i=0;i<int(b.length());i++){
      if(b[i]!=' ' and b[i]!='\n'){
         b1+=b[i];
      }
   }
   return a1==b1;
 }
vector<review> ratelist;

void readdata(string filename){
    ifstream infile;
    infile.open(filename.c_str());
    string title;
    int score;
    int total_rate=0;
    getline(infile,title,'|');
    while(infile.good()){
        infile>>score;
        total_rate++;
        bool check=0;
        for(int i=0;i<int(ratelist.size());i++){
            string T = ratelist[i].getMovieTitle();
            if(comparestr(T,title)){
                check=1;
                ratelist[i].addscore(score);
                ratelist[i].setNumRating(ratelist[i].getNumRating()+1);
                break;
            }
        }
        if(!check){
            review m;
            m.setMovieTitle(title);
            m.setNumRating(1);
            m.setTotalScore(score);
            ratelist.push_back(m);
        }
        getline(infile,title,'|');
    }
    for(int i=0;i<(int)ratelist.size();i++){
        double avg=ratelist[i].calculateAveScore();
        //cout<<avr<<'\n';
        ratelist[i].setAveScore(avg);
    }
    answer2=total_rate;
    infile.close();

 }
 int main(){
    readdata("/Users/leon/Downloads/C2HW07-2023/RatingList.txt");
    answer1 = int(ratelist.size());

    double maxrate=0;
     for(int i=0;i<(int)ratelist.size();i++){
        if(ratelist[i].getAveScore() > maxrate) maxrate = ratelist[i].getAveScore();
     }
    answer3 = maxrate;

    cout<<answer1<<' '<<answer2<<' '<<answer3<<'\n';

    return 0;
 }
