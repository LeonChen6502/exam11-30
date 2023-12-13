#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

 const int MaxM=20;
 int answer1; // Store the total number of movies listed in the RatingList.txt file.
 int answer2; // Store the total number of ratings in the RatingList.txt file.
 double answer3; // Store the highest average rating in the list.

 class Moviereview{
    private:
        string movieTitle;
        int totalScore;
        int numRating;
        double aveScore;
    public:
        void getMovieTitle(string& s );
        void getTotalScore(int& n);
        void getNumRating(int& n);
        void getAveScore(double& n);
        void setMovieTitle(string s);
        void setTotalScore(int n);
        void setNumRating(int n);
        void setAveScore(double n);
        void addscore(int n);
        double calculateAveScore();

 };
 void Moviereview::getMovieTitle(string& s){
    s = movieTitle;
 }
 void Moviereview::getTotalScore(int& n){
    n = totalScore;
 }
 void Moviereview::getNumRating(int& n){
    n = numRating;
 }
 void Moviereview::getAveScore(double& n){
    n = aveScore;
 }
 void Moviereview::setMovieTitle(string s){
    movieTitle = s;
 }
 void Moviereview::setTotalScore(int n){
    totalScore = n;
 }
 void Moviereview::setNumRating(int n){
    numRating = n;
 }
 void Moviereview::setAveScore(double n){
    aveScore = n;
 }
 void Moviereview::addscore(int n){
    totalScore += n;
 }
 double Moviereview::calculateAveScore(){
    return (double)totalScore/numRating;
 }
 bool comparestr(string a,string b){
   string newa,newb;
   for(int i=0;i<(int)a.length();i++){
      if(a[i]!=' ' and a[i]!='\n'){
         newa+=a[i];
      }
   }
   for(int i=0;i<(int)b.length();i++){
      if(b[i]!=' ' and b[i]!='\n'){
         newb+=b[i];
      }
   }
   return newa==newb;
 }
 vector<Moviereview> ratelist;
 void readdata(string s){
    ifstream infile;
    infile.open(s.c_str());
    string title;
    int score;
    int totalrate=0;
    getline(infile,title,'|');
    while(infile.good()){
        totalrate++;
        infile>>score;

        bool check=0;
        for(int i=0;i<(int)ratelist.size();i++){
            string T;
            ratelist[i].getMovieTitle(T);
            if(comparestr(T,title)){
                check=1;
                ratelist[i].addscore(score);
                int cur;
                ratelist[i].getNumRating(cur);
                ratelist[i].setNumRating(cur+1);
                break;
            }
        }
        if(!check){
            Moviereview m;
            m.setMovieTitle(title);
            m.setNumRating(1);
            m.setTotalScore(score);
            ratelist.push_back(m);
        }
        getline(infile,title,'|');
    }
    for(int i=0;i<(int)ratelist.size();i++){
        double avr=ratelist[i].calculateAveScore();
        //cout<<avr<<'\n';
        ratelist[i].setAveScore(avr);
    }
    answer2=totalrate;
    infile.close();

 }
 int main(){
    readdata("/Users/leon/Downloads/C2HW07-2023/RatingList.txt");
    answer1 = ratelist.size();

    double maxrate=0;
    for(int i=0;i<(int)ratelist.size();i++){
        double r;
        ratelist[i].getAveScore(r);
        if(r>maxrate) maxrate = r;
    }
    answer3 = maxrate;
    /*
    for(int i=0;i<ratelist.size();i++){
      string s;
      ratelist[i].getMovieTitle(s);
      cout<<s<<' ';
    }
    cout<<'\n';
    */

    cout<<answer1<<' '<<answer2<<' '<<answer3<<'\n';

    return 0;
 }
