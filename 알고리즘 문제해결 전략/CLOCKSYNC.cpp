#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
int m;

vector<vector<int> > button({
    vector<int>( { 0, 1, 2 }),
    vector<int>( { 3, 7, 9, 11 }),
    vector<int>( { 4, 10, 14, 15 }),
    vector<int>( { 0, 4, 5, 6, 7 }),
    vector<int>( { 6, 7, 8, 10, 12 }),
    vector<int>( { 0, 2, 14, 15 }),
    vector<int>( { 3, 14, 15 }),
    vector<int>( { 4, 5, 7, 14, 15 }),
    vector<int>( { 1, 2, 3, 4, 5 }),
    vector<int>( { 3, 4, 5, 9, 13 })
});

/*vector<vector<int> > button({
    vector<int>( { 0,3,5 }),
    vector<int>( { 0,8 }),
    vector<int>( { 0,5,8 }),
    vector<int>( { 1,6,8,9 }),
    vector<int>( { 2,3,7,8,9 }),
    vector<int>( { 3,7,8,9 }),
    vector<int>( { 3,4 }),
    vector<int>( { 1,3,4,7 }),
    vector<int>( { 4 }),
    vector<int>( { 1,9 }),
    vector<int>( { 2,4 }),
    vector<int>( { 1 }),
    vector<int>( { 4 }),
    vector<int>( { 9 }),
    vector<int>( { 2,5,6,7 }),
    vector<int>( { 2,5,6,7 })
});*/

/*void SYNC(int *arr, int count){
    bool check=true;
    for(int i=0; i<16; ++i){
        if(arr[i]!=12){
            check=false;
            break;
        }
    }
    if(check) ans.pushback(count);
    
    for(int i=0; i<10; ++i){
        
        arr[i]
        SYNC(arr,count);
    }


}*/

void push_button(int* arr, int nth_button, int push_num){
    for(int j=0; j<push_num; ++j){
        for(int i=0; i<button[nth_button].size(); ++i){
            arr[button[nth_button][i]]+=3;
            if(arr[button[nth_button][i]]==15) arr[button[nth_button][i]]=3;
        }
    }
}

int main(){
    int C;
    int arr[16];
    int arr2[16];
    int count=0;
    cin>>C;
    for(int t=0; t<C; ++t){
        /*for(int i=0; i<16; ++i){
            cin>>arr[i];
            if(i==8||i==11||i==12||i==13){
                //count=count+(4-(arr[i]/3));
                arr[i]=12;
                if(i==8) a[1]++;
                else if(i==11) a[0]++;
                else if(i==12) a[1]++;
                else a[2]++;
            }
        }*/

        for(int i=0; i<16; ++i){
            cin>>arr[i];
        }
        m=41;
        for(int z=0; z<4; z++){
            for(int o=0; o<4; ++o){
                for(int tw=0; tw<4;++tw){
                    for(int th=0; th<4; ++th){
                        for(int f=0; f<4;++f){
                            for(int fi=0; fi<4; ++fi){
                                for(int s=0; s<4; ++s){
                                    for(int se=0; se<4; ++se){
                                        for(int e=0; e<4; ++e){
                                            for(int n=0; n<4; ++n){
                                                for(int dfd=0; dfd<16;++dfd){
                                                    arr2[dfd]=arr[dfd];
                                                }
                                                push_button(arr2,0,z);
                                                push_button(arr2,1,o);
                                                push_button(arr2,2,tw);
                                                push_button(arr2,3,th);
                                                push_button(arr2,4,f);
                                                push_button(arr2,5,fi);
                                                push_button(arr2,6,s);
                                                push_button(arr2,7,se);
                                                push_button(arr2,8,e);
                                                push_button(arr2,9,n);
                                                bool check=true;
                                                for(int bc=0; bc<16; ++bc){
                                                    if(arr2[bc]!=12){
                                                        check=false;
                                                        break;
                                                    }
                                                }
                                                if(check){ 
                                                    count=z+o+tw+th+f+fi+s+se+e+n;
                                                    if(m>=count){
                                                        m=count;
                                                    }
                                                }
                                                
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(m==41) m=-1;
        ans.push_back(m);
    }
    for(int i=0; i<ans.size(); ++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}