bool dfs(char** board,int i,int j,int col,int row,int index,char *word ){
    if(word[index]=='\0')
    return true;
    else if(i<0 ||  j<0|| i>=row ||j>=col ||board[i][j]!=word[index])
    return false;
    char temp;
    temp=board[i][j];//(keeping currentin temp so to move further )
    board[i][j]='#';
     bool found=  
    dfs(board,i-1,j,col,row,index+1,word)||
    dfs(board,i+1,j,col,row,index+1,word)||
    dfs(board,i,j-1,col,row,index+1,word)||
    dfs(board,i,j+1,col,row,index+1,word);
    
    board[i][j] = temp;//backtrack(temp is holding the current thing)(eita na pele ase noile eikane ase na karon call mane abar first theke suru)
    return found;


}
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int row = boardSize;
    int col = boardColSize[0]; 
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
           if( dfs(board,i,j,col,row,0,word))
           return true;
        }
     }
     return false;
}

}