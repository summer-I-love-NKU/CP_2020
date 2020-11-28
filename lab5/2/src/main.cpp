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

    cout << "Hello!!!!!!!!!!" << endl;
    
    if (root != NULL)
    {
        cout << "root!=NULL" << endl;
        root->genNodeId(); 
        root->printAST();
    }
    return 0;
}
// int main(int argc, char *argv[])
// {
//     if (argc == 2)
//     {
//         cout << "OK!" << endl;
//         FILE *fin = fopen(argv[1], "r");
//         if (fin != nullptr)
//         {
//             yyin = fin;
//             cout << "OK!" << endl;
//         }
//         else
//         {
//             cerr << "failed to open file: " << argv[1] << endl;
//         }
//     }
//     yyparse();
//     // yyin = stdin;
//     // do
//     // {
//     //     yyparse();
//     // }while(!feof(yyin));
//     cout << "Hello!!!!!!!!!!" << endl;
//     if (root != NULL)
//     {
//         root->genNodeId_and_print();//重新生成吗？？使用树的先序遍历？？
//         // root->printAST();
//     }
//     return 0;
// }