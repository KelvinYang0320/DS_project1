#include<iostream>
using namespace std;
class block{
    public:
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
int main(void)
{
    int row, col;
    cin>>row>>col;
    block B(row, col);
    cout<<B.show_row()<<B.show_col();
}