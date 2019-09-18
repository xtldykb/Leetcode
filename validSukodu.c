#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

int main(){
	bool b;
	int * boardColSize;
	//char ** board;
	char *board[] = {"53..77...","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
	extern bool isValidSudoku(char** board, int boardSize, int* boardColSize);
	boardColSize = (int*)malloc(sizeof(int));
	* boardColSize = 9;
	
	b = isValidSudoku(board, 9, boardColSize);
	return 0;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    char col[9][9], row[9][9], box[9][9];
    int i, j, index, value;
    for(i=0;i<9;i++){
        memset(col[i], 0, 9);
        memset(row[i], 0, 9);
        memset(box[i], 0, 9);
    }
    for(i=0;i<boardSize;i++){
        for(j=0;j<*boardColSize;j++){
			if(board[i][j]!='.'){
				value = board[i][j] - '0';
            //判断列；
                if(col[j][value-1]=='1'){
                    return false;
                }
                else{
                    col[j][value-1]='1';
                }
            //判断行；
                if(row[i][value-1]=='1'){
                    return false;
                }
                else{
                    row[i][value-1]='1';
                }            
            //判断方格；
                index = (i/3)*3 + j/3;
                if(box[index][value-1]=='1'){
                    return false;
                }
                else{
                    box[index][value-1]='1';
                } 

            }
        }
    }
    return true;
}