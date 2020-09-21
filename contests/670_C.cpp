#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

void printVec(vector<int> &v){
    for(int i=0; i < (int) v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

int dfs_leaf( unordered_map<int, vector<int>> &relateds, unordered_map<int, int> &degrees, int root, unordered_set<int> &visited){
    if(degrees[root] == 1){
        return root;
    }

    visited.emplace(root);

    for(int i=0; i<(int)relateds[root].size(); i++){
        if(visited.find(relateds[root][i]) == visited.end()){
            return dfs_leaf(relateds, degrees, relateds[root][i], visited);       
        }
    }
    return -1;
}

int main(){
    int t, n, x, y;

    cin >> t;
    while(t){
        cin >> n;
        unordered_map<int, vector<int>> tree;
        unordered_map<int, vector<int>> centroids_candidates;
        unordered_map<int, vector<int>> relateds;
        unordered_map<int, int> degrees;

        //Initialize maps
        for(int i=1; i<=n; i++){
            tree[i] = {};
            centroids_candidates[i] = {};
            degrees[i] = 0;
        }

        //Read input
        for(int i=0; i<n-1; i++){
            cin >> x >> y;
            tree[x].push_back(y);
            relateds[x].push_back(y);
            relateds[y].push_back(x);
            degrees[x]++;
            degrees[y]++;
        }

        //Add leafs to centroids_candidates
        int count_edges = 0;
        for(int i=0; i<(int) degrees.size(); i++){
            if(degrees[i] == 1){ //Leaf
                int parent = relateds[i][0];
                centroids_candidates[i].push_back(n-1);
                centroids_candidates[parent].push_back(1);
                count_edges++;
            }
        }

        //Complete the centroids_candidates
        while(count_edges != n-1){
            for(int i=1; i<=n; i++){
                if((int) centroids_candidates[i].size() == degrees[i]-1){
                    int sum = 0;
                    for(int j=0; j < (int) centroids_candidates[i].size(); j++){
                        sum += centroids_candidates[i][j];
                    }

                    //The sum in an vertex is n-1
                    int complete = n - 1 - sum;
                    centroids_candidates[i].push_back(complete);
                    
                    //Paired with who?
                    int pair = -1;
                    for(int j=0; j<(int)relateds[i].size(); j++){
                        if((int) centroids_candidates[relateds[i][j]].size() != degrees[relateds[i][j]]){
                            pair = relateds[i][j];
                            break;
                        }
                    }
                    //The sum in an edge is n
                    centroids_candidates[pair].push_back(n-complete);
                    count_edges++;
                }
            }
        }

        //Sorting
        int mi = INT_MAX;
        for(int i=1; i<=n; i++){
            sort(centroids_candidates[i].begin(), centroids_candidates[i].end(), greater<int>());
            if((int) centroids_candidates[i].size() > 0){
                mi = min(mi, centroids_candidates[i][0]);
            }
        }

        //Separating the centroids
        vector<int> centroids;
        for(int i=1; i<=n; i++){
            if((int) centroids_candidates[i][0] == mi){
                centroids.push_back(i);
            }
        }

        if((int) centroids.size() == 1){
            cout << 1 << " " << relateds[1][0] << endl;
            cout << 1 << " " << relateds[1][0] << endl;
        } else{
            //We disconnect the two centroid to fint a leaf
            for(int i=0; i<(int)relateds[centroids[0]].size(); i++){
                if(relateds[centroids[0]][i] == centroids[1]){
                    relateds[centroids[0]].erase(relateds[centroids[0]].begin() + i);
                    break;
                }
            }
            for(int i=0; i<(int)relateds[centroids[1]].size(); i++){
                if(relateds[centroids[1]][i] == centroids[0]){
                    relateds[centroids[1]].erase(relateds[centroids[1]].begin() + i);
                    break;
                }
            }

            //We need the leaf of one centroid to transfer to the other one
            int leaf, parent;
            
            unordered_set<int> visited;
            leaf = dfs_leaf(relateds, degrees, centroids[0], visited);
            visited.clear();

            bool inverted = false;
            if(leaf == -1){
                inverted = true;
                leaf = dfs_leaf(relateds, degrees, centroids[1], visited);
            } 

            parent = relateds[leaf][0];

            //Prints the answer
            cout << parent << " " << leaf << endl;
            if(inverted == false){
                cout << centroids[1] << " " << leaf << endl;             
            }
            else{
                cout << centroids[0] << " " << leaf << endl;             
            }
        }

        tree.clear();
        centroids_candidates.clear();
        t--;
    }


    return 0;
}