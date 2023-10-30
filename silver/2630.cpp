#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> paper;
int blue = 0;
int white = 0;
bool isFinePapper(int top, int bottom, int left, int right){
    bool firstOne = paper[top][left];
    for(int i = top; i <= bottom; i++){
        for(int j = left; j <= right; j++){
            if(paper[i][j] != firstOne) return false;
        }
    }
    return true;
}

void findNumberOfPaper(int top, int bottom, int left, int right){
    if(isFinePapper(top, bottom, left, right)){
        if(paper[top][left] == 0) white++;
        else blue++;
        return;
    }else{
        int midX = (top + bottom) / 2;
        int midY = (left + right) / 2;

        findNumberOfPaper(top, midX, left, midY);
        findNumberOfPaper(top, midX, midY + 1, right);
        findNumberOfPaper(midX + 1, bottom, left, midY);
        findNumberOfPaper(midX + 1, bottom, midY + 1, right);
    }
}

int main(){
    int n;
    cin>>n;
    paper = vector<vector<bool>>(n, vector<bool>(n, false));
    for(int i =0 ; i< n; i++){
        for(int j =0; j < n; j++){
            bool temp;
            cin>>temp;
            paper[i][j] = temp;
            //cin>>paper[i][j];
        }
    }
    int s = 0; int e = n-1;
    findNumberOfPaper(s, e, s, e);

    cout<<white<<"\n"<<blue;
return 0;
}
