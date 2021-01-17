#include "common.h"
#include <fstream>

extern TreeNode *root;
extern FILE *yyin;
extern int yyparse();

using namespace std;


int main()
{
   
    yyin = stdin;
    do
    {
        yyparse();
    }while(!feof(yyin));
    
    // cout << "Hello!!!" << endl;

    if (root != NULL)
    {
        root->genNodeId(); 
        root->printAST();
    }
    
    
    
    // 分号也算结点
    // cout << "total:"<<root->total_node_num()<< "!!!???" << endl;
    return 0;
}
