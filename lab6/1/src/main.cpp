#include "common.h"
#include <fstream>

#define PRINT_AST 1
// ofstream outfile;

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


    if (root != NULL)
    {
        #if PRINT_AST
        // outfile.open("../tests/AST",ios::in);
            root->genNodeId();
            cout << "#          Node"
                << "         Node Type"
                << "                   Children" << endl;
            root->printAST();
            cout << "\n\n#***********************asm code***********************\n\n"<<endl;
        #endif
        root->gen_header();
        root->get_label();//get label and set the： .data,  .section .rodata,
        root->gen_code();//main: .FLB0  .FLE0 ...
        root->gen_tail();
    }

    // 分号也算结点
    // cout << "total:"<<root->total_node_num()<< "!!!???" << endl;
    return 0;
}
