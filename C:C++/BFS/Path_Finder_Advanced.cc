#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define YES -100
#define NO -200

using namespace std;

bool in_list(vector<tuple<int, int>> start_list, tuple<int, int> find_point)
{
    vector<tuple<int, int>>::iterator it;
    it = find(start_list.begin(), start_list.end(), find_point);
    if(it != start_list.end()){
        return true;
    }else{
        return false;
    }
}

int string_to_2d_array(string maze){
    int n = 0;
    for(int i = 0; i < maze.length(); i++){
        if(maze[i] != '\n'){
            n += 1;
        }
        else{
            break;
        }
    }

    //std::cout << "n is " << n << "\n";

    char** matrix = new char*[n];
    for(int i = 0; i < n; i++){
        matrix[i] = new char[n];
    }

    int level = 0;
    for(int i = 0; i < maze.length(); i++){
        if(maze[i] == '\n'){
            level += 1;
        }
        else{
            matrix[level][i - (n + 1) * level] = maze[i];
        }
    }

    int** matrix_aid = new int*[n];

    for(int i = 0; i < n; i++){
        matrix_aid[i] = new int[n];
    }

    int label = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] != 'W'){
                matrix_aid[i][j] = label;
                label += 1;
            }else{
                matrix_aid[i][j] = -1;
            }
        }
    }

    int** matrix_aid_2 = new int*[n];

    for(int i = 0; i < n; i++){
        matrix_aid_2[i] = new int[n];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix_aid_2[i][j] = YES;
        }
    }



    queue<vector<tuple<int, int>>> q;

    tuple<int, int> start_point = std::make_tuple(0, 0);
    vector<tuple<int, int>> start_list = {start_point};



    q.push(start_list);


    int answer = -1;
    while(q.size() != 0){
        vector<tuple<int, int>> now_list = q.front();
        q.pop();
        tuple<int, int> last_point_in_list = now_list.back();
        int x = get<0>(last_point_in_list);
        int y = get<1>(last_point_in_list);

        //cout << "x is:" << x << "y is:" << y << "\n";
        if(x == n - 1 && y == n - 1){
            answer = now_list.size();
            break;
        }


        if(x + 1 == n - 1 && y == n - 1){
            return now_list.size();
        }

        if(x == n - 1 && y + 1== n - 1){
            return now_list.size();
        }

        if(x - 1 == n - 1 && y == n - 1){
            return now_list.size();
        }


        if(x == n - 1 && y - 1 == n - 1){
            return now_list.size();
        }


        if(x >= 0 && x < n - 1){
            if(matrix_aid[x + 1][y] != -1){

                if(x + 1 == n - 1 && y == n - 1){
                    return now_list.size();
                }

                if(matrix_aid_2[x + 1][y] == YES){
                    tuple<int, int> to_add_point = std::make_tuple(x + 1, y);
                    vector<tuple<int, int>> to_add_list = now_list;
                    to_add_list.push_back(to_add_point);
                    q.push(to_add_list);
                    matrix_aid_2[x + 1][y] = NO;
                }

            }
        }

        if(y >= 0 && y < n - 1){
            if(matrix_aid[x][y + 1] != -1){

                if(x == n - 1 && y + 1 == n - 1){
                    return now_list.size();
                }

                if(matrix_aid_2[x][y + 1] == YES){
                    tuple<int, int> to_add_point = std::make_tuple(x, y + 1);
                    vector<tuple<int, int>> to_add_list2 = now_list;
                    to_add_list2.push_back(to_add_point);
                    q.push(to_add_list2);
                    matrix_aid_2[x][y + 1] = NO;
                }
            }
        }

        if(x - 1 >= 0 && x < n){
            if(matrix_aid[x - 1][y] != -1){

                if(x - 1 == n - 1 && y == n - 1){
                    return now_list.size();
                }

                if(matrix_aid_2[x - 1][y] == YES){
                    tuple<int, int> to_add_point = std::make_tuple(x - 1, y);
                    vector<tuple<int, int>> to_add_list3 = now_list;
                    to_add_list3.push_back(to_add_point);
                    q.push(to_add_list3);
                    matrix_aid_2[x - 1][y] = NO;
                }
            }
        }

        if(y - 1 >= 0 && y < n){
            if(matrix_aid[x][y - 1] != -1){

                if(x == n - 1 && y - 1 == n - 1){
                    return now_list.size();
                }

                if(matrix_aid_2[x][y - 1] == YES){
                    tuple<int, int> to_add_point = std::make_tuple(x, y - 1);
                    vector<tuple<int, int>> to_add_list4 = now_list;
                    to_add_list4.push_back(to_add_point);
                    q.push(to_add_list4);
                    matrix_aid_2[x][y - 1] = NO;
                }
            }
        }
    }

    if(answer == -1){
        return -1;
    }else{
        return answer - 1;
    }

}

int main(){

    int n = string_to_2d_array(".W...W...W...\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n...W...W...W.");
    cout << "answer is:" << n << "\n";

}

