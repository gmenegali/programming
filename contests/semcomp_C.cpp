#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
 
using namespace std;
 
void printVec(vector<tuple<string, int, int>> &v){
    for(int i=0; i < (int) v.size(); i++){
        cout << get<0>(v[i]) << ' ' << get<1>(v[i]) << ' '  << get<2>(v[i]) << endl;
    }
}
 
bool maior_p(tuple<string, int, int> a, tuple<string, int, int> b){
    return get<1>(a) > get<1>(b); 
}
 
bool menor_p(tuple<string, int, int> a, tuple<string, int, int> b){
    return get<1>(a) < get<1>(b); 
}
 
bool relevancia(tuple<string, int, int> a, tuple<string, int, int> b){
    return get<2>(a) > get<2>(b); 
}
 
int main(){
    int n, q, p, r, x;
    string s;
 
    cin >> n >> q;
    vector<tuple<string, int, int>> data;
    for(int i=0; i<n; i++){
        cin >> s >> p >> r;
        data.push_back(make_tuple(s, p, r));
    }
 
    vector<tuple<string, int, int>> data_original = data;
    sort(data.begin(), data.end(), menor_p);
    vector<tuple<string, int, int>> data_menor_p = data;
    sort(data.begin(), data.end(), relevancia);
    vector<tuple<string, int, int>> data_relevancia = data;
    sort(data.begin(), data.end(), maior_p);
 
    string last = "";
    for(int i=0; i<q; i++){
        cin >> s;
        if(s == "imprimir"){
            cin >> x;
            if(last == "menor"){
                cout << get<0>(data_menor_p[x-1]) << endl;
            }
            else if(last == "maior"){
                cout << get<0>(data[x-1]) << endl;
            } 
            else if(last == "relevancia"){
                cout << get<0>(data_relevancia[x-1]) << endl;
            }
            else{
                cout << get<0>(data_original[x-1]) << endl;
            }
        }
        else if(s == "ordenar_menor_preco"){
            last = "menor";
        }
        else if(s == "ordenar_maior_preco"){
            last = "maior";
        }
        else if(s == "ordenar_relevancia"){
            last = "relevancia";
        }
    }
 
 
 
    return 0;
}