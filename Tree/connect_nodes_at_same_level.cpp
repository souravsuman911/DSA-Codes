// using nextRight -> 
/*
{
  int data;
  Node *left,  *right;
  Node *nextRight; 
}; 
*/


void connect(Node *root)
{
    queue<Node*> q1;
    queue<Node*> q2;
    q1.push(root);
    
    
    while(!q1.empty() || !q2.empty()){

        while(!q1.empty()){
            if(q1.front() -> left != NULL)
                q2.push(q1.front() -> left);
                
            if(q1.front() -> right != NULL)
                q2.push(q1.front() -> right);
                
            if(q1.size() == 1){
                q1.front() -> nextRight = NULL;
                q1.pop();
            }
            else{
                Node *temp = q1.front();
                q1.pop();
                temp -> nextRight = q1.front();
            }
        }
        
        while(!q2.empty()){
            if(q2.front() -> left != NULL)
                q1.push(q2.front() -> left);
                
            if(q2.front() -> right != NULL)
                q1.push(q2.front() -> right);
                
                
            if(q2.size() == 1){
                q2.front() -> nextRight = NULL;
                q2.pop();
            }
            else{
                Node *temp = q2.front();
                q2.pop();
                temp -> nextRight = q2.front();
            }
        }
    }
    
    
}  