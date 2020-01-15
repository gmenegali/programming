#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef struct Step {
  int disk;
  int orig;
  int dest;
} step; 

step step_create(int disk, int orig, int dest){
  step p;  
  p.disk = disk;
  p.orig = orig;
  p.dest = dest;
  return p;
}

void walk(stack<int> &orig, stack<int> &dest){
  int target = orig.top();
  orig.pop();
  dest.push(target);  
}

step step_walker(stack<int> &tower_1, stack<int> &tower_2, stack<int> &tower_3, int orig, int dest){
  // Step
  step p;
  if(orig == 1) p = step_create(tower_1.top(), orig, dest);
  else if(orig == 2) p = step_create(tower_2.top(), orig, dest);
  else p = step_create(tower_3.top(), orig, dest);  

  // Walk
  if(orig == 1 and dest == 2)      walk(tower_1, tower_2);
  else if(orig == 1 and dest == 3) walk(tower_1, tower_3);
  else if(orig == 2 and dest == 1) walk(tower_2, tower_1);
  else if(orig == 2 and dest == 3) walk(tower_2, tower_3);
  else if(orig == 3 and dest == 1) walk(tower_3, tower_1);
  else if(orig == 3 and dest == 2) walk(tower_3, tower_2);

  return p;
}

void hanoi_explorer(stack<int> &tower_1, stack<int> &tower_2, stack<int> &tower_3, int N, int orig, int dest, int buffer, vector<step> &steps){
  if(N==1){ //In case of just having one disk at all
    step p = step_walker(tower_1,tower_2,tower_3,orig,dest);
    steps.push_back(p);
  }
  else if(N==2){ // Base Case
    //Origin to buffer
    step p1 = step_walker(tower_1,tower_2,tower_3,orig,buffer);
    steps.push_back(p1);
    
    //Origin to destination
    step p2 = step_walker(tower_1,tower_2,tower_3,orig,dest);
    steps.push_back(p2);
    
    //Buffer to destination
    step p3 = step_walker(tower_1,tower_2,tower_3,buffer,dest);
    steps.push_back(p3);
  }
  else{
    //Origin to buffer
    hanoi_explorer(tower_1,tower_2,tower_3,N-1,orig,buffer,dest,steps);
    
    //Origin to destination
    step p = step_walker(tower_1,tower_2,tower_3,orig,dest);
    steps.push_back(p);
    
    //Buffer to destination
    hanoi_explorer(tower_1,tower_2,tower_3,N-1,buffer,dest,orig,steps);
  }
}

vector<step> hanoi(int N){
  vector<step> steps;
  stack<int> tower_1, tower_2, tower_3;

  for(int i=N; i>0; i--) tower_1.push(i);
  
  hanoi_explorer(tower_1, tower_2, tower_3, N, 1, 3, 2, steps);

  cout << "Number of steps: " << steps.size() << endl;
  return steps;
}

int main(){
  vector<step> steps;
  steps = hanoi(3);

  for(int i=0; i<(int)steps.size(); i++){
    cout << "(Disk: " << steps[i].disk << ", Origin: " << steps[i].orig << ", Dest: " << steps[i].dest << ")" << endl;
  }

  return 0;
}