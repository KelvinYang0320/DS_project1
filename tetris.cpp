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
            row_num = 0;
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
                            row_num=2;
                            col_hight = new int [col_num];
                            col_hight[0]=1;
                            col_hight[1]=0;
                            col_hight[2]=1;
                            break;
                        case 2:
                            smArray[0]=block(0,1);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(2,1);
                            name = "T2";
                            col_num=2;
                            row_num=3;
                            col_hight = new int [col_num];
                            col_hight[0]=1;
                            col_hight[1]=0; 
                            break;
                        case 3:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(0,2);
                            smArray[3]=block(1,1);
                            name = "T3";
                            col_num=3;
                            row_num=2;
                            col_hight = new int [col_num];
                            col_hight[0]=0;
                            col_hight[1]=0;
                            col_hight[2]=0;
                            break;
                        case 4:
                            smArray[0]=block(0,0);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(2,0);
                            name = "T4";
                            col_num=2;
                            row_num=3;
                            col_hight = new int [col_num];
                            col_hight[0]=0;
                            col_hight[1]=1;
                            break;
                        default:
                            cout<<"[T]Unrecognized Type"<<endl;
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
                            row_num=3;
                            col_hight = new int [col_num];
                            col_hight[0]=0;
                            col_hight[1]=0;
                            break;
                        case 2:
                            smArray[0]=block(0,0);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(1,2);
                            name = "L2";
                            col_num=3;
                            row_num=2;
                            col_hight = new int [col_num];
                            col_hight[0]=0;
                            col_hight[1]=1;
                            col_hight[2]=1;
                            break;
                        case 3:
                            smArray[0]=block(0,1);
                            smArray[1]=block(1,1);
                            smArray[2]=block(2,0);
                            smArray[3]=block(2,1);
                            name = "L3";
                            col_num=2;
                            row_num=3;
                            col_hight = new int [col_num];
                            col_hight[0]=2;
                            col_hight[1]=0;
                            break;
                        case 4:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(0,2);
                            smArray[3]=block(1,2);
                            name = "L4";
                            col_num=3;
                            row_num=2;
                            col_hight = new int [col_num];
                            col_hight[0]=0;
                            col_hight[1]=0;
                            col_hight[2]=0;
                            break;
                        default:
                            cout<<"[L]Unrecognized Type"<<endl;
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
                            row_num=3;
                            col_hight = new int [col_num];
                            col_hight[0]=0;
                            col_hight[1]=0;
                            break;
                        case 2:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(0,2);
                            smArray[3]=block(1,0);
                            name = "J2";
                            col_num=3;
                            row_num=2;
                            col_hight = new int [col_num];
                            col_hight[0]=0;
                            col_hight[1]=0;
                            col_hight[2]=0;
                            break;
                        case 3:
                            smArray[0]=block(0,0);
                            smArray[1]=block(1,0);
                            smArray[2]=block(2,0);
                            smArray[3]=block(2,1);
                            name = "J3";
                            col_num=2;
                            row_num=3;
                            col_hight = new int [col_num];
                            col_hight[0]=0;
                            col_hight[1]=2;
                            break;
                        case 4:
                            smArray[0]=block(0,2);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(1,2);
                            name = "J4";
                            col_num=3;
                            row_num=2;
                            col_hight = new int [col_num];
                            col_hight[0]=1;
                            col_hight[1]=1;
                            col_hight[2]=0;
                            break;
                        default:
                            cout<<"[J]Unrecognized Type"<<endl;
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
                            row_num=2;
                            col_hight = new int [col_num];
                            col_hight[0]=0;
                            col_hight[1]=0;
                            col_hight[2]=1;
                            break;
                        case 2:
                            smArray[0]=block(0,1);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(2,0);
                            name = "S2";
                            col_num=2;
                            row_num=3;
                            col_hight = new int [col_num];
                            col_hight[0]=1;
                            col_hight[1]=0;
                            break;
                        default:
                            cout<<"[S]Unrecognized Type"<<endl;
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
                            row_num=2;
                            col_hight = new int [col_num];
                            col_hight[0]=1;
                            col_hight[1]=0;
                            col_hight[2]=0;
                            break;
                        case 2:
                            smArray[0]=block(0,0);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(2,1);
                            name = "Z2";
                            col_num=2;
                            row_num=3;
                            col_hight = new int [col_num];
                            col_hight[0]=0;
                            col_hight[1]=1;
                            break;
                        default:
                            cout<<"[Z]Unrecognized Type"<<endl;
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
                            row_num=4;
                            col_hight = new int [col_num];
                            col_hight[0]=0;
                            break;
                        case 2:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(0,2);
                            smArray[3]=block(0,3);
                            name = "I2";
                            col_num=4;
                            row_num=1;
                            col_hight = new int [col_num];
                            col_hight[0]=0;
                            col_hight[1]=0;
                            col_hight[2]=0;
                            col_hight[3]=0;
                            break;
                        default:
                            cout<<"[I]Unrecognized Type"<<endl;
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
                    row_num=2;
                    col_hight = new int [col_num];
                    col_hight[0]=0;
                    col_hight[1]=0;
                    break;
                default:
                    cout<<"Unrecognized Type"<<endl;
                    break;
            }
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
        int row_num;
        int *col_hight;
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
            delete [] m[row_pos];
            m[row_pos] = new bool[Map_c];
            for(int i=row_pos;i<Map_r-1;i++){
                m[i]=m[i+1];
                delete []m[i+1];
                m[i+1] = new bool[Map_c];
            }
        };
        //return 1 means gameover 
        int block_drop(int drop_point, Blocks* b){
            int fix = drop_point-1;
            int *find_pos;
            int cmp=-1;
            int h;
            if((fix+b->col_num-1)>=Map_c||fix<0){
                cout<<b->name<<":wrong dropping point"<<endl;
                return 1;//wrong drop point
            }
            find_pos=new int[b->col_num];
            for(int i=fix;i<fix+b->col_num;i++){
                for(int j=Map_r+3;j>=0;j--){
                    if(m[j][i]==1||j==0){
                        if(j==0)find_pos[i-fix]=0;
                        else find_pos[i-fix]=j+1;
                        break;
                    }
                }
            }
            for(int i=0;i<b->col_num;i++){
                if(cmp<(find_pos[i]-b->col_hight[i])){
                    cmp=find_pos[i]-b->col_hight[i];
                }
            }
            for(int i =0;i<4;i++){
                if(m[cmp+b->smArray[i].row][fix+b->smArray[i].col]==1){
                    cout<<"There is another block here!("<<cmp+b->smArray[i].row<<","<<fix+b->smArray[i].col<<")"<<endl;
                    cout<<"cmp="<<cmp<<endl;
                    for(int i=0;i<3;i++){
                        cout<<find_pos[i]<<endl;
                    }
                    return 1;
                }
                else
                    m[cmp+b->smArray[i].row][fix+b->smArray[i].col]=1;
            }
            return 0;
        }
        int check4(void){//return 1 if gameover
            for(int i=Map_c;i<Map_c+4;i++){
                for(int j=0;j<Map_c;j++){
                    if(m[i][j])
                        return 1;
                }
            }
            cout<<"over limited hight"<<endl;
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
    private:
        bool **m;
        int hight;
        int Map_r;
        int Map_c;
};
int main(void)
{
    fstream fin;
    fin.open("test.data",ios::in);
    int Map_r, Map_c;
    int row, col;
    char block_type;
    int block_rot;
    int drop_point;
    Map *M;
    Blocks *tmp;
    fin>>Map_r>>Map_c;
    cout<<"Map Size:"<<Map_r<<"*"<<Map_c<<endl;
    M=new Map(Map_r, Map_c);
    M->show_map();
    while(1){
        fin>>block_type;
        if(block_type == 'E') break;
        else if(block_type == 'T' || block_type == 'L' ||
                block_type == 'J' || block_type == 'S' || 
                block_type == 'Z' || block_type == 'I') fin>>block_rot;
        else if(block_type != 'O'){
            cout<<"[Error]"<<block_type<<endl;
            break;
        }
        tmp = new Blocks(block_type, block_rot);
        fin>>drop_point;
        //cout<<block_type<<block_rot<<" "<<drop_point<<endl;
        tmp->show_name();
        //tmp->show_all_pos();
        if(M->block_drop(drop_point, tmp))break;
        M->show_map();
    }
    return 0;
}
