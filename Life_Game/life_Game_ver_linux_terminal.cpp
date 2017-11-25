
using namespace std;

WINDOW *create_newwin(int height, int width, int starty, int startx){
   //윈도우 생성
   WINDOW *local_win;
   local_win=newwin(height,width,starty,startx);   
   box(local_win,0,0);
   wrefresh(local_win);   
   return local_win;
}

int main(int argc, char*argv[]){
   WINDOW *win;
   ifstream input;
   ofstream output;
   int row, col;   
   int x,y;
   char cell[100][100];
   setlocale(LC_CTYPE,"");

   initscr();
   refresh();

   win=create_newwin(row,col*2,0,0);

   input.open(argv[1]);

   if(input.fail()){
      return 0;
   }

   input>>row;
   input>>col;
   y=row;
   x=col*2-1;
   
   for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
         input>>cell[i][j];
      }
   }

   input.close();      

   keypad(stdscr,TRUE);
 
   while(true){
      for(int i=0; i<row; i++){
         for(int j=0; j<col; j++){
            if(cell[i][j]=='O')
               mvwprintw(win,i+1,(j*2)+1,"\u2B1B");
            else if(cell[i][j] =='X')
               mvwprintw(win,i+1,(j*2)+1,"\u2B1C");
            wrefresh(win);
         }
      }   
      move(y,x);
      wrefresh(win);

      int ch = getch();

      if(ch==KEY_LEFT){
         if(x-2<1)
            continue;
         x=x-2;
      }

      else if(ch==KEY_RIGHT){
         if(x+2>col*2)
            continue;
         x=x+2;
      }

      else if(ch==KEY_UP){
         if(y-1<1)
            continue;
         --y;
      }

      else if(ch==KEY_DOWN){
         if(y+1>row)
            continue;
         ++y;
      }

      else if(ch=='t'||ch=='T'){
   
         if(cell[y-1][(x)/2]=='X')
            cell[y-1][(x)/2]='O';
         else if(cell[y-1][(x)/2]=='O')
            cell[y-1][(x)/2]='X';
   

      }

      else if(ch=='s'||ch=='S'){
         char str[512];
         echo();
         clear();
         printw("Enter save filename\n : ");
         getstr(str);
         output.open(str);
         output<<row<<" "<<col<<endl;
         for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
               output<<cell[i][j];
               }
            output<<endl;
            }
         output.close();
         noecho();
         clear();
         wrefresh(win);
         refresh();         

      }

      else if(ch=='l'||ch=='L'){
         char str1[512];
         echo();
         clear();
         printw("Enter load filename\n : ");
         getstr(str1);
         input.open(str1);
         input>>row>>col;
         for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
               input>>cell[i][j];
               }
         }
         input.close();
         noecho();
         clear();
         wrefresh(win);
         refresh();
      }

      else if(ch==' '){
         int vert[]={-1,-1,0,1,1,1,0,-1};
         int horz[]={0,1,1,1,0,-1,-1,-1};
         char life[100][100];
            for (int j = 0; j < row; j++) {
               for (int k = 0; k < col; k++) {
                  life[j][k] = cell[j][k];
               }
            }
            int cnt = 0;
            for (int q = 0; q < row; q++) {
               for (int t = 0; t < col; t++) {
                  for (int j = 0; j < 8; j++) {
                     if (t + vert[j] < 0 || t + vert[j] > col - 1 || q + horz[j] < 0 || q + horz[j] > row - 1)
                        continue;
                     if (cell[q + horz[j]][t + vert[j]] == 'O') {
                        cnt++;
                     }
                  }
                  if (cnt <= 1 || cnt >= 4) {
                     life[q][t] = 'X';
                  }
                  if ((cnt == 2 || cnt == 3) && life[q][t] == 'O') {
                     life[q][t] = 'O';
                  } 
                  if (cnt == 3 && life[q][t] == 'X') {
                     life[q][t] = 'O';
                  }
                  cnt = 0;
               }
            }   
      
            for (int j = 0; j < row; j++) {
               for (int k = 0; k < col; k++) {
                  cell[j][k] = life[j][k];
               }
            }
               wrefresh(win);
               refresh();
      }

      if(ch=='q'||ch=='Q'){
         break;
      }
   }

   wrefresh(win);
   refresh();
   endwin();
}