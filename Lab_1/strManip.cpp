#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string word;
    vector<string>vec;
    getline(cin,word);

    while(word.compare("quit") != 0){
        if(word.size()==1){
            for(std::size_t i = 0; i<vec.size(); ++i){
               if(vec[i].substr(0, 1)==word){
                   vec.push_back(vec[i]);
                   break;
               }
            }
        }else{
            vec.push_back(word);
        }
        getline(cin,word);
    }

    for(std::size_t i = 0 ;i<vec.size();++i){
        cout<<vec[i]<<endl;
    }
   return 0;
}