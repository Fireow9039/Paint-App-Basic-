/******************************************************************************

//paint_draw.cpp

*******************************************************************************/
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;


const int ROWS=20;
const int COLS = 40;
vector<vector<char>> canvas(ROWS, vector<char> (COLS,' '));

void displayCanvas(){
    for(int i=0; i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            cout<<canvas[i][j];
            
        }
        cout<<"\n";
        
    }
}

void drawLine(int x1, int y1, int x2, int y2, char ch){
    if(x1==x2){
        for(int y=min(y1,y2); y<= max(y1,y2); ++y){
            canvas[y][x1]=ch;
        }
    }
    else if(y1==y2){
        for(int x=min(x1,x2); x<=max(x1,x2); ++x){
            canvas[y1][x]=ch;
        }
    }
    else{
        cout<<"Only hosizontal or Vertical Line Supported \n";
    }
}

void drawRectangle(int x1, int y1, int x2, int y2, char ch){
    drawLine(x1, y1, x2, y1, ch);
    drawLine(x1, y1, x1, y2, ch);
    drawLine(x1, y2, x2, y2, ch);
    drawLine(x2, y1, x2, y2, ch);
}

void eraseAt(int x, int y){
    if(x>=0 && x< COLS && y>= 0 && y<ROWS){
        canvas[y][x] = ' ';
    }
}

void clearCanvas(){
    for(auto &row : canvas){
        fill(row.begin(), row.end(), ' ');
    }
}

void saveTofile(const string& filename){
    ofstream out(filename);
    for(auto &row: canvas){
        for(char ch:row){
            out<<ch;
        }
        out<<"\n";
    }
    out.close();
    cout<<"Canvas saved to"<<filename<<endl;
}





int main(){
    int choice;
    while(true){
        cout << "\n=== CLI Paint ===\n";
        cout << "1. Draw Line\n";
        cout << "2. Draw Rectangle\n";
        cout << "3. Erase\n";
        cout << "4. Clear Canvas\n";
        cout << "5. Display Canvas\n";
        cout << "6. Save to File\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice){
            case 1: {
                int x1,y1,x2,y2;
                char ch;
                cout<<"start (x1,y1): "; cin>>x1>>y1;
                cout<<"end (x2,y2): "; cin>>x2>>y2;
                cout<<"char: "; cin>>ch;
                drawLine(x1,y1,x2,y2,ch);
                break;
            }
            
            case 2:{
                int x1, y1, x2, y2;
                char ch;
                cout<<"Top-left(x1 y1): "; cin>>x1>>y1;
                cout<<"Bottom-right (x2,y2): "; cin>>x2>>y2;
                cout<<"char: "; cin>>ch;
                drawRectangle(x1,y1,x2,y2,ch);
                break;
            }
            
            case 3: {
                int x,y;
                cout<<"Erase at(x,y): ";cin>>x,y;
                eraseAt(x,y);
                break;
            }
            
            case 4: {
                clearCanvas();
                break;
            }
            case 5: {
                displayCanvas();
                break;
            }
            case 6: {
                string filename;
                cout<<"Filename: ";
                cin>>filename;
                saveTofile(filename);
                break;
            }
            case 0:{
                return 0;
                
            }
            default: 
                cout<<"Invalid choice.\n";
        }
    }
}