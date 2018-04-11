#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>


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



//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            cout << matrix[i][j] << " ";
//        }
//        cout << "\n";
//    }
//
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            cout << matrix_aid[i][j] << " ";
//        }
//        cout << "\n";
//    }

    queue<vector<tuple<int, int>>> q;

    tuple<int, int> start_point = std::make_tuple(0, 0);
    vector<tuple<int, int>> start_list = {start_point};

    //cout << get<0>(start_list[0]) << "\n";

    //q = {vector<tuple<int, int>> = {{0, 0}}}

    q.push(start_list);
    //cout << q.size() << "\n";

    //vector<tuple<int, int>> a= q.front();

    //cout << get<1>(a[0]) << "\n";

    //cout << q.pop() << "\n";


    //vector<tuple<int, int>> a = q.pop();

    //cout << a << "\n";

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


                tuple<int, int> to_add_point = std::make_tuple(x + 1, y);
                vector<tuple<int, int>> to_add_list = now_list;
                if(!in_list(to_add_list, to_add_point)){
                    to_add_list.push_back(to_add_point);
                    q.push(to_add_list);
                }
            }
        }

        if(y >= 0 && y < n - 1){
            if(matrix_aid[x][y + 1] != -1){

                if(x == n - 1 && y + 1 == n - 1){
                    return now_list.size();
                }


                tuple<int, int> to_add_point = std::make_tuple(x, y + 1);
                vector<tuple<int, int>> to_add_list2 = now_list;
                if(!in_list(to_add_list2, to_add_point)){
                    to_add_list2.push_back(to_add_point);
                    q.push(to_add_list2);
                }
            }
        }

        if(x - 1 >= 0 && x < n){
            if(matrix_aid[x - 1][y] != -1){

                if(x - 1 == n - 1 && y == n - 1){
                    return now_list.size();
                }

                tuple<int, int> to_add_point = std::make_tuple(x - 1, y);
                vector<tuple<int, int>> to_add_list3 = now_list;
                if(!in_list(to_add_list3, to_add_point)){
                    to_add_list3.push_back(to_add_point);
                    q.push(to_add_list3);
                }
            }
        }

        if(y - 1 >= 0 && y < n){
            if(matrix_aid[x][y - 1] != -1){

                if(x == n - 1 && y - 1 == n - 1){
                    return now_list.size();
                }

                tuple<int, int> to_add_point = std::make_tuple(x, y - 1);
                vector<tuple<int, int>> to_add_list4 = now_list;
                if(!in_list(to_add_list4, to_add_point)){
                    to_add_list4.push_back(to_add_point);
                    q.push(to_add_list4);
                }

            }
        }
    }

    if(answer == -1){
        return -1;
    }else{
        return answer - 1;
    }
    //cout << "here is answer:"<< answer - 1 << "\n";
}

int main(){


    //string_to_2d_array(".W.\n.W.\nW..");
    //string_to_2d_array(".W.\n.W.\n...");
    //string_to_2d_array(".W.\n.W.\nW..");
    //int n = string_to_2d_array("......\n......\n......\n......\n......\n......");
    int n = string_to_2d_array(".W...W...W...\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n...W...W...W.");
    cout << "answer is:" << n << "\n";
//    vector<int> a = {1,2,3};
//    a.push_back(5);
//    vector<int> b = a;
//    cout << b[3] << "\n";
//    b[3] = 6;
//    cout << b[3] << "\n";
//    cout << a[3] << "\n";

//    tuple<int, int> start_point = std::make_tuple(0, 0);
//    tuple<int, int> one_point = std::make_tuple(0, 1);
//    vector<tuple<int, int>> start_list = {start_point};
//    start_list.push_back(one_point);
//    cout << start_list.size() << "\n";
//
//    tuple<int, int> find_point = make_tuple(0, 0);
//    vector<tuple<int, int>>::iterator it;
//    it = find(start_list.begin(), start_list.end(), find_point);
//
////    if(std::find(start_list.begin(), start_list.end(), find_point) != start_list.end()){
////        cout << "Find you\n";
////    }
//    if(it != start_list.end()){
//        cout << "find\n";
//    }else{
//        cout << "not find\n";


//    if(!in_list(start_list, find_point)){
//        cout << "not found\n";
//    }
//    cout << in_list(start_list, find_point) << "\n";

}

