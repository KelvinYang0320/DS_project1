#include<iostream>
#include<string>
#include <fstream> 
using namespace std;
class block{
    public:
        friend class Blocks;
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
    public:
        Blocks(){
            smArray = nullptr;
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
                            break;
                        case 2:
                            smArray[0]=block(0,1);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(2,1);
                            break;
                        case 3:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(0,2);
                            smArray[3]=block(1,1);
                            break;
                        case 4:
                            smArray[0]=block(0,0);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(2,0);
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
                            break;
                        case 2:
                            smArray[0]=block(0,0);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(1,2);
                            break;
                        case 3:
                            smArray[0]=block(0,1);
                            smArray[1]=block(1,1);
                            smArray[2]=block(2,0);
                            smArray[3]=block(2,1);
                            break;
                        case 4:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(0,2);
                            smArray[3]=block(1,2);
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
                            break;
                        case 2:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(0,2);
                            smArray[3]=block(1,0);
                            break;
                        case 3:
                            smArray[0]=block(0,0);
                            smArray[1]=block(1,0);
                            smArray[2]=block(2,0);
                            smArray[3]=block(2,1);
                            break;
                        case 4:
                            smArray[0]=block(0,2);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(1,2);
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
                            break;
                        case 2:
                            smArray[0]=block(0,1);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(2,0);
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
                            break;
                        case 2:
                            smArray[0]=block(0,0);
                            smArray[1]=block(1,0);
                            smArray[2]=block(1,1);
                            smArray[3]=block(2,1);
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
                            break;
                        case 2:
                            smArray[0]=block(0,0);
                            smArray[1]=block(0,1);
                            smArray[2]=block(0,2);
                            smArray[3]=block(0,3);
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
    private:
        block *smArray;
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
    Blocks *tmp;
    fin>>Map_r>>Map_c;
    cout<<"Map Size:"<<Map_r<<"*"<<Map_c<<endl;
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
        cout<<block_type<<block_rot<<" "<<drop_point<<endl;
        tmp->show_all_pos();
    }
    return 0;
}