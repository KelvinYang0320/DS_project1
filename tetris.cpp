#include<iostream>
#include<string>
#include <fstream>
using namespace std;
class block{
    public:
        friend class Blocks;
        friend class Map;
        block():row(0),col(0){};
        block(int i, int j):row(i),col(j){};
        void change_row(int r_change){
            row = r_change;
        }
        void change_col(int r_change){
            col = r_change;
        }
        int show_row(void){
            return row;
        }
        int show_col(void){
            return col;
        }
    private:
        int row;
        int col;
};
class Blocks{
    friend class Map;
    public:
        Blocks(){
            smArray = nullptr;
            name = "no_name";
            col_num = 0;
            col_height = nullptr;
            //row_num = 0;
        }
        Blocks(char type, int rot){
            smArray = new block [4];
            switch(type){
                case 'T':
                    switch(rot){
                        case 1:
                            smArray[0]=block(0,1);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(1,2);
                            name = "T1";
                            col_num = 3;
                            //row_num=2;
                            col_height = new int [col_num];
                            col_height[0]=1;
                            col_height[1]=0;
                            col_height[2]=1;
                            break;
                        case 2:
                            smArray[0]=block(0,1);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(2,1);
                            name = "T2";
                            col_num=2;
                            //row_num=3;
                            col_height = new int [col_num];
                            col_height[0]=1;
                            col_height[1]=0;
                            break;
                        case 3:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(0,2);
                            smArray[3]=block(1,1);
                            name = "T3";
                            col_num=3;
                            //row_num=2;
                            col_height = new int [col_num];
                            col_height[0]=0;
                            col_height[1]=0;
                            col_height[2]=0;
                            break;
                        case 4:
                            smArray[0]=block(0,0);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(2,0);
                            name = "T4";
                            col_num=2;
                            //row_num=3;
                            col_height = new int [col_num];
                            col_height[0]=0;
                            col_height[1]=1;
                            break;
                        default:
                            cout<<"[T]Unrecognized Type"<<endl;//error_msg
                            break;
                    }
                    break;
                case 'L':
                    switch(rot){
                        case 1:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(1,0);
                            smArray[3]=block(2,0);
                            name = "L1";
                            col_num=2;
                            //row_num=3;
                            col_height = new int [col_num];
                            col_height[0]=0;
                            col_height[1]=0;
                            break;
                        case 2:
                            smArray[0]=block(0,0);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(1,2);
                            name = "L2";
                            col_num=3;
                            //row_num=2;
                            col_height = new int [col_num];
                            col_height[0]=0;
                            col_height[1]=1;
                            col_height[2]=1;
                            break;
                        case 3:
                            smArray[0]=block(0,1);
                            smArray[1]=block(1,1);
                            smArray[2]=block(2,0);
                            smArray[3]=block(2,1);
                            name = "L3";
                            col_num=2;
                            //row_num=3;
                            col_height = new int [col_num];
                            col_height[0]=2;
                            col_height[1]=0;
                            break;
                        case 4:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(0,2);
                            smArray[3]=block(1,2);
                            name = "L4";
                            col_num=3;
                            //row_num=2;
                            col_height = new int [col_num];
                            col_height[0]=0;
                            col_height[1]=0;
                            col_height[2]=0;
                            break;
                        default:
                            cout<<"[L]Unrecognized Type"<<endl;//error_msg
                            break;
                    }
                    break;
                case 'J':
                    switch(rot){
                        case 1:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(1,1);
                            smArray[3]=block(2,1);
                            name = "J1";
                            col_num=2;
                            //row_num=3;
                            col_height = new int [col_num];
                            col_height[0]=0;
                            col_height[1]=0;
                            break;
                        case 2:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(0,2);
                            smArray[3]=block(1,0);
                            name = "J2";
                            col_num=3;
                            //row_num=2;
                            col_height = new int [col_num];
                            col_height[0]=0;
                            col_height[1]=0;
                            col_height[2]=0;
                            break;
                        case 3:
                            smArray[0]=block(0,0);
                            smArray[1]=block(1,0);
                            smArray[2]=block(2,0);
                            smArray[3]=block(2,1);
                            name = "J3";
                            col_num=2;
                            //row_num=3;
                            col_height = new int [col_num];
                            col_height[0]=0;
                            col_height[1]=2;
                            break;
                        case 4:
                            smArray[0]=block(0,2);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(1,2);
                            name = "J4";
                            col_num=3;
                            //row_num=2;
                            col_height = new int [col_num];
                            col_height[0]=1;
                            col_height[1]=1;
                            col_height[2]=0;
                            break;
                        default:
                            cout<<"[J]Unrecognized Type"<<endl;//error_msg
                            break;
                    }
                    break;
                case 'S':
                    switch(rot){
                        case 1:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(1,1);
                            smArray[3]=block(1,2);
                            name = "S1";
                            col_num=3;
                            //row_num=2;
                            col_height = new int [col_num];
                            col_height[0]=0;
                            col_height[1]=0;
                            col_height[2]=1;
                            break;
                        case 2:
                            smArray[0]=block(0,1);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(2,0);
                            name = "S2";
                            col_num=2;
                            //row_num=3;
                            col_height = new int [col_num];
                            col_height[0]=1;
                            col_height[1]=0;
                            break;
                        default:
                            cout<<"[S]Unrecognized Type"<<endl;//error_msg
                            break;
                    }
                    break;
                case 'Z':
                    switch(rot){
                        case 1:
                            smArray[0]=block(0,1);
                            smArray[1]=block(0,2);
                            smArray[2]=block(1,0);
                            smArray[3]=block(1,1);
                            name = "Z1";
                            col_num=3;
                            //row_num=2;
                            col_height = new int [col_num];
                            col_height[0]=1;
                            col_height[1]=0;
                            col_height[2]=0;
                            break;
                        case 2:
                            smArray[0]=block(0,0);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(2,1);
                            name = "Z2";
                            col_num=2;
                            //row_num=3;
                            col_height = new int [col_num];
                            col_height[0]=0;
                            col_height[1]=1;
                            break;
                        default:
                            cout<<"[Z]Unrecognized Type"<<endl;//error_msg
                            break;
                    }
                    break;
                case 'I':
                    switch(rot){
                        case 1:
                            smArray[0]=block(0,0);
                            smArray[1]=block(1,0);
                            smArray[2]=block(2,0);
                            smArray[3]=block(3,0);
                            name = "I1";
                            col_num=1;
                            //row_num=4;
                            col_height = new int [col_num];
                            col_height[0]=0;
                            break;
                        case 2:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(0,2);
                            smArray[3]=block(0,3);
                            name = "I2";
                            col_num=4;
                            //row_num=1;
                            col_height = new int [col_num];
                            col_height[0]=0;
                            col_height[1]=0;
                            col_height[2]=0;
                            col_height[3]=0;
                            break;
                        default:
                            cout<<"[I]Unrecognized Type"<<endl; //error_msg
                            break;
                    }
                    break;
                case 'O':
                    smArray[0]=block(0,0);
                    smArray[1]=block(0,1);
                    smArray[2]=block(1,0);
                    smArray[3]=block(1,1);
                    name = "O";
                    col_num=2;
                    //row_num=2;
                    col_height = new int [col_num];
                    col_height[0]=0;
                    col_height[1]=0;
                    break;
                default:
                    cout<<"Unrecognized Type"<<endl; //error_msg
                    break;
            }
        }
        ~Blocks(){
            delete [] smArray;
            delete [] col_height;
        }
        void show_all_pos(void){
            for(int i=0;i<4;i++){
                cout<<"r:"<<smArray[i].row<<"\tc:"<<smArray[i].col<<endl;
            }
        }
        void show_name(void){
            cout<<"name:"<<name<<endl;
        }
    private:
        block *smArray;
        string name;
        int col_num;
        //int row_num;
        int *col_height;
};
class Map{
    public:
        Map():m(nullptr),hight(0),Map_r(Map_r),Map_c(Map_c){};
        Map(int Map_r, int Map_c){
            m = new bool* [Map_r+4];
            for(int i = 0; i<(Map_r+4); i++){
                m[i] = new bool [Map_c];
                for(int j =0; j<Map_c;j++){
                    m[i][j]=0;
                }
            }
            hight = 0;
            this->Map_r=Map_r;
            this->Map_c=Map_c;
        }
        void clean_a_row(int row_pos){
            for(int i=row_pos;i<Map_r+3;i++){
                delete [] m[i];
                m[i]=m[i+1];
                m[i+1] = new bool[Map_c];
            }
            for(int i=0;i<Map_c;i++){
                m[Map_r+3][i]=0;
            }
            /*
            cout<<"["<<row_pos<<"]"<<endl;
            show_map();
            */
        };
        void check_clean(void){
            int cnt;
            for(int i = 0; i<Map_r+4; i++){
                cnt=0;
                for(int j =0; j<Map_c;j++){
                    cnt=cnt+m[i][j];
                }
                if(cnt==Map_c){
                    clean_a_row(i);
                    i=i-1;
                }
            }
        }
        //return 1 means gameover
        int block_drop(int drop_point, Blocks* b){
            int fix = drop_point-1;
            int *find_pos;
            int cmp=-1;
            int h;
            if((fix+b->col_num-1)>=Map_c||fix<0){
                cout<<b->name<<":wrong dropping point"<<endl; //erroe_msg
                return 1;//wrong drop point
            }
            find_pos=new int[b->col_num];
            for(int i=fix;i<fix+b->col_num;i++){
                for(int j=Map_r+3;j>=0;j--){
                    if(m[j][i]==1||j==0){
                        if(j==0&&m[j][i]==0)find_pos[i-fix]=0;
                        else find_pos[i-fix]=j+1;
                        break;
                    }
                }
            }
            for(int i=0;i<b->col_num;i++){
                if(cmp<(find_pos[i]-b->col_height[i])){
                    cmp=find_pos[i]-b->col_height[i];
                }
            }
            for(int i =0;i<4;i++){
                if(m[cmp+b->smArray[i].row][fix+b->smArray[i].col]==1){
                    //cout<<"There is a block here!("<<cmp+b->smArray[i].row<<","<<fix+b->smArray[i].col<<")"<<endl;//error_msg
                    return 1;
                }
                else
                    m[cmp+b->smArray[i].row][fix+b->smArray[i].col]=1;
            }
            return 0;
        }
        int check4(void){//return 1 if gameover
            for(int i=Map_r;i<Map_r+4;i++){
                for(int j=0;j<Map_c;j++){
                    if(m[i][j]){
                        //cout<<"over limited hight("<<i<<","<<j<<")"<<endl;//error_msg
                        return 1;
                    }
                }
            }
            return 0;
        }
        void show_map(void){
            cout<<"Map:"<<endl;
            for(int i =Map_r+3;i>=0;i--){
                for(int j=0;j<Map_c;j++){
                    cout<<m[i][j];
                }
                cout<<endl;
                if(i==Map_r){
                    cout<<"_________________"<<endl;
                }
            }
        }
        void showfinal_map(fstream &fout){
            for(int i =Map_r-1;i>=0;i--){
                for(int j=0;j<Map_c;j++){
                    fout<<m[i][j];
                }
                fout<<endl;
            }
        }
        void showcout_map(void){
            for(int i =Map_r-1;i>=0;i--){
                for(int j=0;j<Map_c;j++){
                    cout<<m[i][j];
                }
                cout<<endl;
            }
        }
    private:
        bool **m;
        int hight;
        int Map_r;
        int Map_c;
};
int main(void)
{
    fstream fin;
    fstream fout;
    fin.open("Tetris.data",ios::in);
    //fin.open("3.data",ios::in);
    fout.open("Tetris.output",ios::out);
    int Map_r, Map_c;
    int row, col;
    char block_type;
    int block_rot;
    int drop_point;
    Map *M;
    Blocks *tmp;
    fin>>Map_r>>Map_c;
    //cout<<"Map Size:"<<Map_r<<"*"<<Map_c<<endl;
    M=new Map(Map_r, Map_c);
    //M->show_map();
    while(1){
        fin>>block_type;
        if(block_type == 'E') break;
        else if(block_type == 'T' || block_type == 'L' ||
                block_type == 'J' || block_type == 'S' ||
                block_type == 'Z' || block_type == 'I') fin>>block_rot;
        else if(block_type != 'O'){
            //cout<<"[Error]"<<block_type<<endl;//error_msg
            break;
        }
        tmp = new Blocks(block_type, block_rot);
        fin>>drop_point;
        //cout<<block_type<<block_rot<<" "<<drop_point<<endl;
        //tmp->show_name();
        //cout<< drop_point<<endl;
        //tmp->show_all_pos();
        if(M->block_drop(drop_point, tmp))break;
        M->check_clean();
        if(M->check4())break;
        delete tmp;
    }
    M->showfinal_map(fout);
    //M->showcout_map();
    return 0;
}


