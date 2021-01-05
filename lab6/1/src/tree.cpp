#include "tree.h"
#include<iomanip>//输出美观
#define MAX_RODATA_NUM 200
#define PUSH_EAX cout<<"\tpushl\t%eax\n"
#define POP_EAX cout<<"\tpopl\t%eax\n"

/**
 * 问题思考：
    * this指针，一般是隐含的，用处是指向变量自身，
    * 啊啊啊对于指针不是很懂 用*????
    * 对于多个孩子，让孩子之间（兄弟）连起来：
            *孩子兄弟表示法：http://data.biancheng.net/view/30.html
            *遍历https://www.xuebuyuan.com/1175648.html
            * 增加孩子结点，就是让孩子之间（作为兄弟）连起来，一个结点只有一个孩子一个兄弟
            * 是不是就都转成了二叉树？？
    * 结点序号只是为了最后输出美观，所以一开始不需要初始化，最后遍历一次树就行了
    * 

 
 * */


#if 1
	/**************************************SymTable*********************************************/
	SymTable::SymTable(int scopeid)
	{
		this->scope = scopeid;
	}

	/**************************************symbol_table*********************************************/
#endif
	
#if 1

	/**********************************************tree.cpp***************************************************/
		string NODETYPE_name[20] = {"const","var","array","expr","type","stmt","prog","func","block","10"};
		string StmtType_name[30] = {"block","skip", "return","decl var","decl ptr","decl ref","decl array","assign","add_assign","sub_assign","mul_assign","div_assign",
		"self_add_assign","self_sub_assign","printf","scanf","if","if else","if else if","while","for","22"};
		string ValueType_name[20] = {"bool", "int", "char", "string","void","const int","const char","8"};
		string OperatorType_name[30] = {"reserved","+","-","*","/","%","0-","&&","||","!","<=","<",">=",">","==","!=","17"};

		int the_nodeID = 0, new0_nodeID = 0, new_nodeID = 0; //根结点
		int TreeNode::node_num = 0, TreeNode::label_seq = 0;
	#endif
	//---------------------------------------------------------
#if 1
	//增加孩子结点，就是让孩子之间依次连起来
	void TreeNode::addChild(TreeNode *the_child)
	{

		if (this->child != nullptr) //可以直接this->child->addSibling(the_child);
		{
			TreeNode *p=this->child;
			while(p->sibling!=nullptr)
			{
				p = p->sibling;
			}
			p->sibling = the_child;
			the_child->father = this;
			// TreeNode *ttt = new TreeNode();
			// ttt=the_child;
			// this->children.push_back(ttt);
			// this->childarr[this->childnum] = the_child;//this->childnum!!!!
			// this->childnum += 1;
		}
		else
		{
			this->child = the_child;
			the_child->father = this;
		}
	}
	//增加兄弟结点-----类似修改一下！！！
	void TreeNode::addSibling(TreeNode* the_sibling)
	{ //包括了this有兄弟和无兄弟的情况
		TreeNode *p=this;
		while(p->sibling!=nullptr)
		{
			p = p->sibling;
		}
		p->sibling = the_sibling;
		the_sibling->father = this->father;
		
	}
	//构造函数，初始化，序号自增
	TreeNode::TreeNode(int lineno, NodeType type) 
	{
		node_num++;
		//第一件事，序号自增,记录行号
		this->nodeID = the_nodeID;
		the_nodeID++;
		this->lineno = lineno;
		this->nodeType = type;
	}
	TreeNode::TreeNode() 
	{
		
	}
	// TreeNode TreeNode::operator=(TreeNode& t)
	// {


	// 	// return *this;
	// }
	void TreeNode::printNodeInfo() 
	{
		int setw1 = 15, setw2 = 15;//# 是AT&T汇编的注释
		cout<<"#";
		cout << std::left << setw(2) << this->lineno << "|  "
			<< "@" << std::left << setw(2) << this->nodeID << "  " << setw(7) << NODETYPE_name[this->nodeType] << "  ";

		switch (this->nodeType)
		{
		case NODE_STMT:
			cout << std::right<<setw(setw1)<< "stmt_type: " << std::left<<setw(setw2)<<StmtType_name[this->stmt_type];
			// cout<<setw(setw1+setw2)<<" ";//--------
			break;
		case NODE_CONST:
			//---------注意如果有类型转换：  3 |  node@4   const  const_type: int   const_value: a 
			cout << std::right<<setw(setw1)<< "const_type: " << std::left<<setw(setw2)<<ValueType_name[this->type->type];
			cout << std::right<<setw(setw1)<< "const_value: ";//------------
			switch (this->val_type_flag)
			{
			case 'b':
				cout << this->b_val;
				break;
			case 'i':
				cout << this->int_val;
				break;
			case 'c':
				cout << this->ch_val;
				break;
			case 's':
				cout << this->str_val;
				break;
			default:
				cout << "error!!!";
				break;
			}
			cout << "  ";
			break;
		case NODE_VAR:
			cout << std::right<<setw(setw1)<< "var_name: " << std::left<<setw(setw2)<<this->var_name;
			// cout << std::right << setw(setw1) << "var_value: "<< std::left<<setw(setw2) << this->int_val;//------------
			break;
		case NODE_ARR:
			cout << std::right<<setw(setw1)<< "array_name: " << std::left<<setw(setw2)<<this->var_name;
			// cout<<setw(setw1+setw2)<<" ";//-----------
			break;
		case NODE_TYPE:
			cout << std::right<<setw(setw1)<< "type: " << std::left<<setw(setw2)<<ValueType_name[this->type->type];
			// cout<<setw(setw1+setw2)<<" ";//-----------
			break;
		case NODE_EXPR:
			cout << std::right<<setw(setw1)<< "expr_type: " << std::left<<setw(setw2)<<OperatorType_name[this->op_type];
			// cout << std::right<<setw(setw1)<< "expr_value: "<<std::left<<setw(setw2)<< this->int_val;//------
			break;
		case NODE_PROG:
			cout<<setw(setw1+setw2)<<" ";
			// cout<<setw(setw1+setw2)<<" ";//setw1+setw2 只有root走这里吧//---------
			break;
		case NODE_FUNC:
			cout<<setw(setw1+setw2)<<" ";
			// cout<<setw(setw1+setw2)<<" ";//setw1+setw2 
			break;
		case NODE_BLOCK:
			cout<<setw(setw1+setw2)<<" ";
			// cout<<setw(setw1+setw2)<<" ";//setw1+setw2
			break;
		default:
			cout<<"error!!!";//
			break;
		}
		cout << "  ";


		//这里别忘了判断条件！！！有无孩子呀！！！
		if(this->child!=nullptr)
			this->printChildrenId();
		cout << endl;
	}

	void TreeNode::printChildrenId() 
	{
		cout << "children: @"<<this->nodeID<<" -> [ @"<<this->child->nodeID << " ";
		TreeNode *p = this->child;
		while (p->sibling != nullptr)
		{
			cout << "@" << p->sibling->nodeID << " ";
			p = p->sibling;
		}
		cout << "]"<<"  ";

	}


	//这两个函数是给root用的
	//生成结点的同时也就打印信息了！！！不行，生成不完全，打印的就有错误！
	//必须先生成一次
	void TreeNode::genNodeId()
	{
		if(this==nullptr)
			return;
		this->nodeID = new0_nodeID++;

		this->child->genNodeId();
		this->sibling->genNodeId();
		
	}

	void TreeNode::printAST() 
	{
		if(this==nullptr)
			return;
		this->nodeID = new_nodeID++;
		this->printNodeInfo();

		this->child->printAST();
		this->sibling->printAST();
	}


	int TreeNode::total_node_num()
	{
		return node_num;
	}

#endif




/*******************************lab7 final********************************************/

//汇编代码结尾部分
string _ident = ".ident\t\t\"Simple_C_Complier_ShenZhe: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609\"";
string _section = ".section\t.note.GNU-stack,\"\",@progbits";
string err_str="can't support now!\n";
void TreeNode::gen_header()
{
	cout << "# Simple C Complier created by Shen Zhe, 2021.1" << endl;
	cout << "\t.file  \"test.c\"" << endl;
}
void TreeNode::gen_tail()
{
	cout << _ident << endl
		<< _section << endl;
}
/*****************string const*******************/
// string operator + (string &content, int number) {
//     return content + to_string(number);}
// string& operator += (string &content, int number) {
// 	return content = content + to_string(number);}

//.rodata段   .data段
string rodata[MAX_RODATA_NUM];int ro_i=0;
map<string, int> strlist;static int strindex = 0;

string vardata[MAX_RODATA_NUM];int var_i=0;

static int label_index=1;
//要防止多标签混乱——子过程也用label_index， 所以分了.L  .Lw  .Lif  .Lf
//静态标签、入栈保护



/***************************get label: 为字符串和声明分配常量空间：.data  or .bss  .comm ??******************************************/

void TreeNode::stmt_get_label(TreeNode *t)//set_data_seg_AND_get_label
{
	if (t->stmt_type == STMT_DECL_V)//可能要作用域？？
	{
		
		if(t->child->type->type==VALUE_INT||t->child->type->type==VALUE_CHAR||t->child->type->type==VALUE_CONST_INT||t->child->type->type==VALUE_CONST_CHAR)
		{
			TreeNode* p=t->child->child;///int a,b,c=1;
			//cout<<".data"<<endl;	//   t     p  
			map<string,string> type_size;
			type_size["int"]="4";type_size["char"]="1";
			
			while (p!=nullptr)
			{
				// if(p->child!=nullptr)//int a=1;
				// {
					vardata[var_i]="\t.align 4\n";
					vardata[var_i]+="\t.type\t"+p->var_name+", @object\n";
					
					if(t->child->type->type==VALUE_CONST_INT||t->child->type->type==VALUE_INT)
					{
						vardata[var_i]+="\t.size\t"+p->var_name+", 4\n";
					}
					else //if(t->child->type->type==VALUE_CONST_CHAR||t->child->type->type==VALUE_CHAR)
					{
						vardata[var_i]+="\t.size\t"+p->var_name+", 1\n";
					}
					
					vardata[var_i]+=p->var_name+":\n";
					if(p->child!=nullptr)
						vardata[var_i]+="\t.long\t"+to_string(p->child->int_val)+"\n";
					else
						vardata[var_i]+="\t.long\t"+to_string(0)+"\n\n";
					var_i++;
				// }
				// else//int a; default=0
				// {
				// 	cout<<"\t.align 4\n"//int 4   char 1 
				// 	<<"\t.type\t"<<p->var_name<<", @object\n"
				// 	<<"\t.size\t"<<p->var_name<<", 4\n"
				// 	<<p->var_name<<":\n"
				// 	<<"\t.long\t"<<0<<endl
				// 	<<endl;

				// }
				p=p->sibling;

			}
		}
		// else if(t->child->type->type==VALUE_CHAR)
		// {
		// 	TreeNode* p=t->child->child;///char
		// 	cout<<".data"<<endl;	//  
		// 	while (p!=nullptr)
		// 	{
		// 		if(p->child!=nullptr)
		// 		{
		// 			cout<<"\t.align 1\n"
		// 			<<"\t.type\t"<<p->var_name<<", @object\n"
		// 			<<"\t.size\t"<<p->var_name<<", 1\n"
		// 			<<p->var_name<<":\n"
		// 			<<"\t.long\t"<<int(p->child->ch_val)<<endl
		// 			<<endl;

		// 		}
		// 		else//int a; default=0
		// 		{
		// 			cout<<"\t.align 1\n"//int 4   char 1 
		// 			<<"\t.type\t"<<p->var_name<<", @object\n"
		// 			<<"\t.size\t"<<p->var_name<<", 1\n"
		// 			<<p->var_name<<":\n"
		// 			<<"\t.long\t"<<0<<endl
		// 			<<endl;

		// 		}
		// 		p=p->sibling;
		// 		/*
		// 			movb	$97, t

		// 			movzbl	s, %eax
		// 			movsbl	%al, %eax
		// 			subl	$12, %esp
		// 			pushl	%eax
		// 			call	putchar
		// 			addl	$16, %esp
		// 			*/
		// 	}
		// }
		// else;
		
	}
	else if (t->stmt_type == STMT_PRINTF)
	{
		TreeNode *p = t->child;
		//cout << ".section	.rodata\n";
		while (p != nullptr&&p->nodeType==NODE_CONST)//printf("%d",12)
		{
			if(strlist.count(p->str_val)==0)
			{
				strlist[p->str_val] = strindex;
				// cout << ".LC"<<strindex++<<":\n\t.string\t" << 
				// p->str_val << "\n" << endl;
				rodata[ro_i++]=".LC"+to_string(strindex++)+string(":\n\t.string\t") +
				p->str_val + "\n";
				
			}
			p = p->sibling;
		}
	}
	else if (t->stmt_type == STMT_SCANF)
	{
		TreeNode *p = t->child;
		// cout << ".section	.rodata\n";
		while (p != nullptr&&p->nodeType==NODE_CONST)//printf("%d",12)
		{
			if(strlist.count(p->str_val)==0)
			{
				strlist[p->str_val] = strindex;
				rodata[ro_i++]=".LC"+to_string(strindex++)+string(":\n\t.string\t") +
				p->str_val + "\n" ;
			}
			p = p->sibling;
		}
	}
	else
	{
		;
	}
}
void TreeNode::recursive_get_label(TreeNode *t)
{
	if(t==nullptr)
		return;
	if (t->nodeType == NODE_STMT)
	{
		stmt_get_label(t);
	}
	TreeNode* p=t->child;
	while(p!=nullptr)
	{
		//if  ! stmt || ! expr
		recursive_get_label(p);
		p=p->sibling;
	}
	
}

void TreeNode::get_label()//root call it 
{
	// this->label.begin = "_start";
	TreeNode* p=this->child;
	while (p!=nullptr)
	{
		recursive_get_label(p);
		p=p->sibling;//root's children
	}

	cout << ".section	.rodata\n";
	for (int i = 0; i < ro_i; i++)
	{
		cout<<rodata[i];
	}
	
	cout << "\n.data\n";
	for (int i = 0; i < var_i; i++)
	{
		cout<<vardata[i];
	}
	cout<<endl;
	
	
}

/***********************************gen code :stmt expr ************************************************/

void TreeNode::expr_gen_code( TreeNode *t)//注意，结果存在%eax，这个原则，会使设计很方便！！！
{
	//!!!注意e1  e2 的顺序，因为subl S,D：D=D-S
	TreeNode *e1 = t->child;TreeNode *e2=nullptr;
	if(t->op_type!=OP_NEG&&t->op_type!=OP_NOT)
		e2 = t->child->sibling;
	
	
	if(t->op_type==OP_ADD||t->op_type==OP_MUL)//%eax 入栈保护
	{
		if (e1->nodeType ==NODE_EXPR)
		{
			expr_gen_code(e1);// 
			//cout << "\tmovl\t%eax"<< ", %eax\n";//movl eax eax 
		}
		else if (e1->nodeType == NODE_CONST)
			cout << "\tmovl\t$"<<e1->int_val<< ", %eax\n";
		else if(e1->nodeType == NODE_VAR)
			cout << "\tmovl\t"<<e1->var_name<< ", %eax\n";
		else
			return;//error

		PUSH_EAX;
		
		if (e2->nodeType ==NODE_EXPR)
		{
			expr_gen_code(e2);
			cout << "\tmovl\t%eax"<< ", %edx\n";
		}
		else if (e2->nodeType == NODE_CONST)
			cout << "\tmovl\t$"<<e2->int_val<< ", %edx\n";
		else if(e2->nodeType == NODE_VAR)
			cout << "\tmovl\t"<<e2->var_name<< ", %edx\n";
		else 
			return;
		POP_EAX;


		switch (t->op_type)
		{
			case OP_ADD:
				cout<<"\taddl\t%edx, %eax\n";break;
			case OP_MUL:
				cout<<"\timull\t%edx, %eax\n";break;
			default:
				break;
		}
		
	}
	else if(t->op_type==OP_SUB)//%eax 入栈保护
	{
	/*******************************************************/
		if (e1->nodeType ==NODE_EXPR)
		{
			expr_gen_code(e1);// 
			//cout << "\tmovl\t%eax"<< ", %eax\n";//movl eax eax  
		}
		else if (e1->nodeType == NODE_CONST)
			cout << "\tmovl\t$"<<e1->int_val<< ", %eax\n";
		else if(e1->nodeType == NODE_VAR)
			cout << "\tmovl\t"<<e1->var_name<< ", %eax\n";
		else
			return;//error

		PUSH_EAX;
	/*******************************************************/
		if (e2->nodeType==NODE_EXPR)
		{
			expr_gen_code(e2);
			cout << "\tmovl\t%eax"<< ", %edx\n";
		}
		else if (e2->nodeType == NODE_CONST)
			cout << "\tmovl\t$"<<e2->int_val<< ", %edx\n";
		else if(e2->nodeType == NODE_VAR)
			cout << "\tmovl\t"<<e2->var_name<< ", %edx\n";
		else 
			return;
		
		POP_EAX;
	/*******************************************************/
		cout<<"\tsubl\t%edx, %eax\n";
	/*********************************
		 *	6*2-12: 
		wrong:
		 	movl	$12, %edx---顺序提前了 是 e1  e2的问题
			movl	$6, %edx
			movl	$2, %eax
			imull	%edx, %eax
			movl	%eax, %eax
			subl	%edx, %eax
		ok:
			movl	$6, %eax
			movl	$2, %edx
			imull	%edx, %eax
			movl	$12, %edx
			movl	%eax, %eax# 此句优化掉了
			subl	%edx, %eax
			*/
		
	}
	else if(t->op_type==OP_DIV||t->op_type==OP_MOD)//%eax 入栈保护  先movl到eax ecx!
	{
		if (e1->nodeType ==NODE_EXPR)
		{
			expr_gen_code(e1);//已经在eax
		}
		else if (e1->nodeType == NODE_CONST)
			cout << "\tmovl\t$"<<e1->int_val<<", %eax\n"; 
		else if(e1->nodeType == NODE_VAR)
			cout << "\tmovl\t"<<e1->var_name<<", %eax\n";
		else
			return;//error

		PUSH_EAX;
		if (e2->nodeType ==NODE_EXPR)
		{
			expr_gen_code(e2);
			cout << "\tmovl\t%eax, %ecx\n";
		}
		else if (e2->nodeType == NODE_CONST)
			cout << "\tmovl\t$"<<e2->int_val<< ", %ecx\n";
		else if(e2->nodeType == NODE_VAR)
			cout << "\tmovl\t"<<e2->var_name<<", %ecx\n";
		else 
			return;
		POP_EAX;
		cout<<"\tcltd\n"
		<<"\tidivl\t%ecx\n";//res is in %eax
		if(t->op_type==OP_MOD)
			cout<<"\tmovl\t%edx, %eax\n";
		//-------------div-----------
		// movl	_ZL1a, %eax
		// movl	_ZL1b, %ecx
		// cltd
		// idivl	%ecx
		// movl	%eax, _ZL1c--eax存商， edx存余数
		//---------------mod---------
		// movl	_ZL1a, %eax
		// movl	_ZL1b, %ecx
		// cltd
		// idivl	%ecx

		// #movl	%edx, %eax
		// #movl	%eax, _ZL1c----使得结果存在%eax!!
		// movl	%edx, _ZL1c
		//-----------------------------------------------
		// idivl S
		// R[%edx] = R[%edx]:R[%eax] % S;
		// R[%eax] = R[%edx]:R[%eax] / S;
		// 有符号除法，保存余数和商

		//cltd S
		// R[%edx]:R[%eax] = 符号位扩展R[%eax]
		// 转换为4字节
	}
	else if(t->op_type==OP_NEG)//-a
	{
		if(e1->nodeType==NODE_CONST)
		{
			cout<<"\tmovl\t$-"<<e1->int_val<<", %eax\n";
		}
		else if(e1->nodeType==NODE_VAR)//################################可优化
		{
			cout<<"\tmovl\t"<<e1->var_name<<", %eax\n"
			<<"\tnegl\t%eax\n";
			// <<"\timull\t$-1, %eax\n";错误！！
		}
		else if(e1->nodeType==NODE_EXPR)
		{
			expr_gen_code(e1);
			cout<<"\tnegl\t%eax\n";
		}
		else;
	}
	else if(t->op_type==OP_AND)//static label
	{	//-----------------e1--------------
		if (e1->nodeType ==NODE_EXPR)
		{
			expr_gen_code(e1);//已经在eax
		}
		else if (e1->nodeType == NODE_CONST)
			cout << "\tmovl\t$"<<e1->int_val<<", %eax\n"; 
		else if(e1->nodeType == NODE_VAR)
			cout << "\tmovl\t"<<e1->var_name<<", %eax\n";
		else if(e1->nodeType == NODE_EXPR)
		{
			expr_gen_code(e1);
		}
		else;

		int static_index=label_index;
		cout<<"\ttestl\t%eax, %eax\n"
		<<"\tje\t.Land"<<static_index<<"\n";// if 0 jmp L1
		//-----------------e2-----------------------
		if (e2->nodeType ==NODE_EXPR)
		{
			expr_gen_code(e2);//已经在eax
		}
		else if (e2->nodeType == NODE_CONST)
			cout << "\tmovl\t$"<<e2->int_val<<", %eax\n"; 
		else if(e2->nodeType == NODE_VAR)
			cout << "\tmovl\t"<<e2->var_name<<", %eax\n";
		else if(e2->nodeType == NODE_EXPR)
		{
			expr_gen_code(e2);
		}
		else;
		cout<<"\ttestl\t%eax, %eax\n"
		<<"\tje\t.Land"<<static_index<<"\n";//if 0 jmp L1

		cout<<"\tmovl\t$1, %eax\n";//------------true  //jmp L2
		cout<<"\tjmp\t.Land"<<static_index+1<<"\n"
		<<".Land"<<static_index<<":\n";//-----------L1:false  
		cout<<"\tmovl\t$0, %eax\n";

		cout<<".Land"<<static_index+1<<":\n";//L2

		label_index+=2;
	}
	else if(t->op_type==OP_OR)//static label
	{	//-----------------e1--------------
		if (e1->nodeType ==NODE_EXPR)
		{
			expr_gen_code(e1);//已经在eax
		}
		else if (e1->nodeType == NODE_CONST)
			cout << "\tmovl\t$"<<e1->int_val<<", %eax\n"; 
		else if(e1->nodeType == NODE_VAR)
			cout << "\tmovl\t"<<e1->var_name<<", %eax\n";
		else;

		int static_index=label_index;
		cout<<"\ttestl\t%eax, %eax\n"
		<<"\tjne\t.Lor"<<static_index<<"\n";// if 1 jmp L1

		//-----------------e2-----------------------
		if (e2->nodeType ==NODE_EXPR)
		{
			expr_gen_code(e2);//已经在eax
		}
		else if (e2->nodeType == NODE_CONST)
			cout << "\tmovl\t$"<<e2->int_val<<", %eax\n"; 
		else if(e2->nodeType == NODE_VAR)
			cout << "\tmovl\t"<<e2->var_name<<", %eax\n";
		else;
		cout<<"\ttestl\t%eax, %eax\n"
		<<"\tjne\t.Lor"<<static_index<<"\n";//if 1 jmp L1

		cout<<"\tmovl\t$0, %eax\n";//------------false  //jmp L2
		cout<<"\tjmp\t.Lor"<<static_index+1<<"\n"
		<<".Lor"<<static_index<<":\n";//-----------L1:true 
		cout<<"\tmovl\t$1, %eax\n";

		cout<<".Lor"<<static_index+1<<":\n";//L2
		
		label_index+=2;
	}
	else if(t->op_type==OP_NOT)
	{	//-----------------e1--------------
		if (e1->nodeType ==NODE_EXPR)
		{
			expr_gen_code(e1);//已经在eax
		}
		else if (e1->nodeType == NODE_CONST)
			cout << "\tmovl\t$"<<e1->int_val<<", %eax\n"; 
		else if(e1->nodeType == NODE_VAR)
			cout << "\tmovl\t"<<e1->var_name<<", %eax\n";
		else;

		cout<<"\ttestl\t%eax, %eax\n"
		<<"\tje\t.Lnot"<<label_index<<"\n";// if 0 jmp L1 (!0 is true)

		cout<<"\tmovl\t$0, %eax\n";//------------false  //jmp L2
		cout<<"\tjmp\t.Lnot"<<label_index+1<<"\n"
		<<".Lnot"<<label_index<<":\n";//-----------L1:true  
		cout<<"\tmovl\t$1, %eax\n";

		cout<<".Lnot"<<label_index+1<<":\n";//L2
		
		label_index+=2;
	}
	else if(t->op_type>=OP_LESS_EQ&&t->op_type<=OP_NOT_EQ)
	{
		string a_op[20];
		a_op[OP_LESS_EQ]="jle";
		a_op[OP_LESS_THAN]="jl";
		a_op[OP_MORE_EQ]="jge";
		a_op[OP_MORE_THAN]="jg";
		a_op[OP_EQ]="je";
		a_op[OP_NOT_EQ]="jne";
		string l_op[20];
		l_op[OP_LESS_EQ]="le";
		l_op[OP_LESS_THAN]="l";
		l_op[OP_MORE_EQ]="ge";
		l_op[OP_MORE_THAN]="g";
		l_op[OP_EQ]="e";
		l_op[OP_NOT_EQ]="ne";
		//-----------------e1--------------
		if (e1->nodeType==NODE_EXPR)
		{
			expr_gen_code(e1);//已经在eax
		}
		else if (e1->nodeType == NODE_CONST)
			cout << "\tmovl\t$"<<e1->int_val<<", %eax\n"; 
		else if(e1->nodeType == NODE_VAR)
			cout << "\tmovl\t"<<e1->var_name<<", %eax\n";
		else;

		//-----------------e2-----------------------
		if (e2->nodeType ==NODE_EXPR)
		{
			expr_gen_code(e2);//已经在eax
			cout << "\tmovl\t%eax, %ebx\n"; 
		}
		else if (e2->nodeType == NODE_CONST)
			cout << "\tmovl\t$"<<e2->int_val<<", %ebx\n"; 
		else if(e2->nodeType == NODE_VAR)
			cout << "\tmovl\t"<<e2->var_name<<", %ebx\n";
		else;

		//这里就很安全，label_index不存在子过程调用
		cout<<"\tcmpl\t%ebx, %eax\n";//eax-ebx  cmpl  e2  e1  :e1-e2

		cout<<"\t"<<a_op[t->op_type]<<"\t.L"<<l_op[t->op_type]<<label_index<<"\n";//if 1 jmp L1


		cout<<"\tmovl\t$0, %eax\n";//------------false  //jmp L2
		cout<<"\tjmp\t.L"<<l_op[t->op_type]<<label_index+1<<"\n"
		<<".L"<<l_op[t->op_type]<<label_index<<":\n";//-----------L1:
		cout<<"\tmovl\t$1, %eax\n";//------------true 

		cout<<".L"<<l_op[t->op_type]<<label_index+1<<":\n";//L2
		
		label_index+=2;

	}
	else
	;
	
}

void TreeNode::stmt_gen_code(TreeNode *t)
{
	if(t->nodeType==NODE_BLOCK)
		t=t->child;
	else if(t->stmt_type==STMT_RETURN||t->stmt_type==STMT_SKIP)return;
	else;

	int t_type=t->stmt_type;
	TreeNode* p=t->child;

	if(t_type==STMT_PRINTF)
	{
		if(p->str_val.find("%c")<p->str_val.length())//-------------char
		{
			if(p->sibling->child->sibling==nullptr)//printf("%c",a)//注意第二个孩子是block
			{
				cout<<"\tmovzbl\t"<<p->sibling->child->var_name<<",%eax\n"
				<<"\tmovsbl\t%al, %eax\n"
				<<"\tsubl\t$12, %esp\n"
				<<"\tpushl\t%eax\n"
				<<"\tcall\tputchar\n"
				<<"\taddl\t$16, %esp\n"
				<<endl;
				/*
					movb	$97, t

					movzbl	s, %eax
					movsbl	%al, %eax
					subl	$12, %esp
					pushl	%eax
					call	putchar
					addl	$16, %esp
				*/
			}
			else
			{
				cerr<<err_str;
			}
		}
		else
		{
			if(p->sibling==nullptr)//printf("ss")
			{
				cout<<"\tsubl\t$12, %esp\n"
				<<"\tpushl\t$.LC"<<strlist[p->str_val]<<endl
				<<"\tcall\tprintf\n"
				<<"\taddl\t$16, %esp\n"
				<<endl;
				// subl	$12, %esp
				// pushl	$.LC1
				// call	printf
				// addl	$16, %esp
			}	
			else if(p->sibling->child->sibling==nullptr)//printf("%d",a)//注意第二个孩子是block
			{
				if(p->sibling->child->nodeType==NODE_EXPR)//printf(.,a+b)
				{
					expr_gen_code(p->sibling->child);//res is in %eax,don't need to movl!!!
				}
				else if(p->sibling->child->nodeType==NODE_VAR)
					cout<<"\tmovl\t"<<p->sibling->child->var_name<<",%eax\n";//p->sibling->childs is arg 2,3,4...
				else
				{
					return;//error
				}
				cout<<"\tsubl\t$8, %esp\n"
				<<"\tpushl\t%eax\n"
				<<"\tpushl\t$.LC"<<strlist[p->str_val]<<endl
				<<"\tcall\tprintf\n"
				<<"\taddl\t$16, %esp\n"
				<<endl;
				// movl	a, %eax
				// subl	$8, %esp// esp: -8-->+16
				// pushl	%eax
				// pushl	$.LC1
				// call	printf
				// addl	$16, %esp
			}
			else//注意参数压栈顺序
			{
				TreeNode* tmp,*e1,*e2,*e3,*e4,*e5,*e6;
				TreeNode* a[20];
				tmp=p->sibling->child;//e1
				int num_i=0;
				while (tmp!=nullptr)
				{
					a[++num_i]=tmp;
					tmp=tmp->sibling;
				}
				//num_i 个参数需要输出，从右往左压栈！！！
				while(num_i)
				{
					if(a[num_i]->nodeType==NODE_EXPR)//printf(.,a+b)
					{
						expr_gen_code(a[num_i]);//res is in %eax,don't need to movl!!!
					}
					else if(a[num_i]->nodeType==NODE_VAR)
						cout<<"\tmovl\t"<<a[num_i]->var_name<<",%eax\n";//a[num_i]s is arg 2,3,4...
					else
					{
						return;//error
					}
					PUSH_EAX;
					num_i--;
				}
				
				cout//<<"\tsubl\t$12, %esp\n"//前边减了多少，加上栈，现在增加多少，我几乎不用栈，只需要增加push的即可
				//参数已经压栈
				<<"\tpushl\t$.LC"<<strlist[p->str_val]<<endl
				<<"\tcall\tprintf\n"
				<<"\taddl\t$"<<num_i*4+4<<", %esp\n"
				<<endl;
			}
		}
		
		
	}
	else if(t_type==STMT_SCANF)
	{
		if(p->sibling->child->sibling==nullptr)//printf("%d",a)//注意第二个孩子是block
		{// esp: -8-->+16
			cout<<"\tsubl\t$8, %esp\n"//p->sibling->childs is arg 2,3,4...
			<<"\tpushl\t$"<<p->sibling->child->var_name<<"\n"
			<<"\tpushl\t$.LC"<<strlist[p->str_val]<<endl
			<<"\tcall\t__isoc99_scanf\n"//static int: __isoc99_scanf  int: scanf
			<<"\taddl\t$16, %esp\n"
			<<endl;
			// subl	$8, %esp
			// pushl	$a
			// pushl	$.LC0
			// call	scanf
			// addl	$16, %esp
		}
		else
		{
			cerr<<err_str;
		}
	}
	else if(t_type==STMT_ASSIGN)
	{
		if(p->sibling->nodeType==NODE_CONST)//a=1
		{
			if(p->sibling->val_type_flag=='i')
				cout<<"\tmovl\t$"<<p->sibling->int_val<<", "<<p->var_name<<endl;
			else if(p->sibling->val_type_flag=='c')//---------------movb!!!
				cout<<"\tmovb\t$"<<int(p->sibling->ch_val)<<", "<<p->var_name<<endl;
			else if(p->sibling->val_type_flag=='b')
				cout<<"\tmovl\t$"<<bool(p->sibling->int_val)<<", "<<p->var_name<<endl;
			else ;
			
		}
		else if(p->sibling->nodeType==NODE_VAR)//a=b
		{
			cout<<"\tmovl\t"<<p->sibling->var_name<<", "<<p->var_name<<endl;
		}
		else if(p->sibling->nodeType==NODE_EXPR)//a=2+1
		{
			//let expr'res be %eax
			expr_gen_code(p->sibling);
			cout<<"\tmovl\t%eax, "<<p->var_name<<endl;
		}
		else if(p->sibling->nodeType==NODE_STMT)//a=b=3;
		{
			//let expr'res be %eax
			stmt_gen_code(p->sibling);

			cout<<"\tmovl\t"<<p->sibling->child->var_name<<", %eax\n"
			<<"\tmovl\t%eax, "<<p->var_name<<endl;
		}
		else ;
	}
	else if(t_type>=STMT_ADD_ASSIGN&&t_type<=STMT_MUL_ASSIGN)
	{//8 9 10
		string a_self[20];
		a_self[STMT_ADD_ASSIGN]="addl";
		a_self[STMT_SUB_ASSIGN]="subl";
		a_self[STMT_MUL_ASSIGN]="imull";
		if(p->sibling->nodeType==NODE_CONST)//a+=1
		{
			cout<<"\t"<<a_self[t_type]<<"\t$"<<p->sibling->int_val<<", "<<p->var_name<<endl;
		}
		else if(p->sibling->nodeType==NODE_VAR)//a=b
		{
			cout<<"\t"<<a_self[t_type]<<"\t"<<p->sibling->var_name<<", "<<p->var_name<<endl;
		}
		else if(p->sibling->nodeType==NODE_EXPR)//a=2+1
		{
			expr_gen_code(p->sibling);
			cout<<"\t"<<a_self[t_type]<<"\t%eax, "<<p->var_name<<endl;
		}
		
		else;
	}
	else if(t_type==STMT_SELF_ADD_ASSIGN)
	{
		cout<<"\taddl\t$1, "<<p->var_name<<endl;
	}
	else if(t_type==STMT_SELF_SUB_ASSIGN)
	{
		cout<<"\tsubl\t$1, "<<p->var_name<<endl;
	}
	else if(t_type==STMT_DIV_ASSIGN)
	{
		cout<<"\tcltd\n";
		if(p->sibling->nodeType==NODE_CONST)//a+=1
		{
			cout<<"\tmovl\t$"<<p->sibling->int_val<<", %ecx\n";
		}
		else if(p->sibling->nodeType==NODE_VAR)//a=b
		{
			cout<<"\tmovl\t"<<p->sibling->var_name<<", %ecx\n";
		}
		else if(p->sibling->nodeType==NODE_EXPR)//a=2+1
		{
			expr_gen_code(p->sibling);
			cout<<"\tmovl\t%eax, %ecx\n";
		}
		else;

		//我这里先mov ecx 后mov eax！！！因为ecx用到eax
		cout<<"\tmovl\t"<<p->var_name<<", %eax\n"
		<<"\tidivl\t%ecx\n";//此时商就在%eax了

	}
	else if(t_type==STMT_DECL_V)//    decl int  a  1   ;四级，只声明只需要get label
	{							//对应：t   p    q  q.child
		TreeNode* q=p->child;//a
		while (q!=nullptr)
		{
			if(q->child!=nullptr)//a=b+3; int a;/int a=1;只声明只需要get label
			{
				if(q->child->nodeType==NODE_EXPR)
				{	
					expr_gen_code(q->child);
					cout<<"\tmovl\t%eax, "<<q->var_name<<endl;
				}
					
			}
			q=q->sibling;
		}
	}
	else if(t_type==STMT_IF_ELSE||t_type==STMT_IF)//if expr stmt or if expr block->(...)
	{					  //if(a>1) if(a+3>4)      t    p           t    p    
		/****************表达式,获得%eax即可,然后看是不是0***********************************/
		expr_gen_code(p);
		cout<<"\ttestl\t%eax, %eax\n"//    
		<<"\tje\t.L"<<label_index<<"\n";//   ------------if(0)  jmp L1     
		
		recursive_gen_code(p->sibling->child);
		// recursive_gen_code(p->sibling);//     -----------stmt1


		if(p->sibling->sibling!=nullptr)
			cout<<"\tjmp\t.L"<<label_index+1<<"\n";//------jmp L2
		
		cout<<".L"<<label_index<<":\n";//			-------------L1:
		if(p->sibling->sibling!=nullptr)
		{
			recursive_gen_code(p->sibling->sibling->child);

			// recursive_gen_code(p->sibling->sibling);//----stmt2

			cout<<".L"<<label_index+1<<":\n";//    ---------L2:
		}
		if(p->sibling->sibling!=nullptr)
			label_index+=2;//update by accum 2
		else
			label_index+=1;
		
	}
	else if(t_type==STMT_IF_ELSE_IF)//if e1 b1 e2 b2 e3 b3  b4
	{					  			//  
		TreeNode*e1,*e2,*e3,*b1,*b2,*b3;//...
		//至少e1 e2 e3
		e1=p;e2=e1->sibling;e3=e2->sibling;b1=e1->child;b2=e2->child;b3=e3->child;
		TreeNode* a[20]={e1,e1,e2,e3},*b[20]={b1,b1,b2,b3};
		int num_i=3;
		TreeNode* m=e3->sibling;
		while(m!=nullptr)
		{
			num_i++;
			a[num_i]=m;b[num_i]=m->child;// 4 5 6...
			m=m->sibling;
		}
		//要防止多标签混乱！！！！
		int static_index=label_index;
		for (int i = 1; i < num_i; i++)
		{
			cout<<".Lif"<<static_index+i-1<<":\n";//    ---------L0:
			expr_gen_code(a[i]);
			cout<<"\ttestl\t%eax, %eax\n"//   
			<<"\tje\t.Lif"<<static_index+i<<"\n";//   ------------if(e1==0)  jmp L1 (e2)    
			
			recursive_gen_code(b[i]);//    -----------stmt1
			cout<<"\tjmp\t.Lif"<<static_index+num_i<<endl;//jmp end:L3  假设 只有e1 e2 e3
		}
		//else:
		cout<<".Lif"<<static_index+num_i-1<<":\n";
		recursive_gen_code(b[num_i]);//    -----------

		cout<<".Lif"<<static_index+num_i<<":\n";

		label_index=label_index+num_i+1;
			#if 0
					// //******************************************
					// 		expr_gen_code(e1);
					// 		cout<<"\ttestl\t%eax, %eax\n"//   
					// 		<<"\tje\t.Lif"<<label_index+1<<"\n";//   ------------if(e1==0)  jmp L2 (e2)    
							
					// 		recursive_gen_code(b1);//    -----------stmt1
					// 		cout<<"\tjmp\t.Lif"<<num_end<<endl;//jmp end
					// //******************************************
					// 		cout<<".Lif"<<label_index+1<<":\n";//    ---------L2:
					// 		expr_gen_code(e2);
					// 		cout<<"\ttestl\t%eax, %eax\n"//   
					// 		<<"\tje\t.Lif"<<label_index+2<<"\n";// -----if e2==0 jmp L3
							
					// 		recursive_gen_code(b2);//    -----------stmt2
					// 		cout<<"\tjmp\t.Lif"<<num_end<<endl;//jmp end
					// //******************************************
					// 		cout<<".Lif"<<label_index+2<<":\n";//    ---------L2:
					// 		recursive_gen_code(b3);//    -----------stmt2
							
					// //******************************************
			#endif
		
	}
	else if(t_type==STMT_WHILE)//while expr stmt or while expr block->(...)
	{					  //       t    p            t    p    
		/****************表达式,获得%eax即可,然后看是不是0***********************************/
		
		cout<<".Lw"<<label_index<<":\n";//---------------L1
		int static_index=label_index;
		expr_gen_code(p);
		cout<<"\ttestl\t%eax, %eax\n"//    
		<<"\tje\t.Lw"<<static_index+1<<"\n";//   ------------if(0)  jmp L2     
		
		recursive_gen_code(p->sibling->child);//-----------stmt1


		cout<<"\tjmp\t.Lw"<<static_index<<"\n";//------jmp L1
		
		cout<<".Lw"<<static_index+1<<":\n";//			-------------L2:
		
		label_index+=2;
		
	}
	else if(t_type==STMT_FOR)//for e1  e2  e3 block 
	{					  //    t   p1 p2  p3          
		TreeNode* p1=p,*p2=p1->sibling,*p3=p2->sibling,*the_stmt=p3->sibling->child;

		stmt_gen_code(p1);
		int static_index=label_index;

		cout<<".Lf"<<static_index<<":\n";//---------------L1
		
		expr_gen_code(p2);
		cout<<"\ttestl\t%eax, %eax\n"//    

		<<"\tje\t.Lf"<<static_index+1<<"\n";//   ------------if(0)  jmp L2     
		
		recursive_gen_code(the_stmt);//-----------stmt1
		stmt_gen_code(p3);

		cout<<"\tjmp\t.Lf"<<static_index<<"\n";//------jmp L1
		
		cout<<".Lf"<<static_index+1<<":\n";//			-------------L2:
		
		label_index+=2;
		
	}
	else
		cout<<StmtType_name[t_type]<<endl<<"error!!"<<endl;
	
}
//先自己gen,再自己的孩子gen--比如遇到作用域很多级的(-----划掉)
//是不是block调用一次就行，自己的孩子就都执行一遍了(-----划掉)
//避免自己调用函数，但需要孩子返回结果的情况——自己用孩子的结果+孩子自己的结果，就重复了！！(------划掉)
//-----------------------------------
//直接模仿先序遍历！！！！only_once用于不递归的情况----@1
//也可修改stmt_gen_code函数！----------------------@2------->解决if else 结果返回过多问题
//	if(t->stmt_type==STMT_BLOCK||t->stmt_type==STMT_RETURN)
//		// t=t->child;
void TreeNode::recursive_gen_code(TreeNode *t,bool only_once=0)//only_once用于不递归的情况
{
	bool f=1;
	if(t->nodeType==NODE_BLOCK||t->nodeType==NODE_FUNC||t->nodeType==NODE_PROG);
	else if (t->nodeType == NODE_STMT)
	{
		stmt_gen_code(t);
		f=0;
	}
	else if(t->nodeType==NODE_EXPR)
	{
		expr_gen_code(t);
		f=0;
	}
	else return;
	if(f)//如果自己是句子或者表达式，那么就不递归到孩子
	if(t->child!=nullptr)
	recursive_gen_code(t->child);

	if(t->sibling!=nullptr)
	recursive_gen_code(t->sibling);


}

void TreeNode::gen_code()//root调用
{
	cout<<"\n.text\n"
	<<"\t.globl\tmain\n"
	<<"\t.type\tmain, @function\n"
	<<"main:\n.LFB0:\n"
	<<"\tleal\t4(%esp), %ecx\n"
	<<"\tandl\t$-16, %esp\n"
	<<"\tpushl\t-4(%ecx)\n"
	<<"\tpushl\t%ebp\n"//-----------
	<<"\tmovl\t%esp, %ebp\n"//--------此两句就够
	<<"\tpushl\t%ecx\n\n\n";

	// TreeNode *p = this->child;
	// while(p!=nullptr)
	// {
		recursive_gen_code(this);
	// 	p = p->sibling;
	// }
	// recursive_gen_code(this);


	cout<<"\n\tmovl\t$0, %eax\n"//----
	<<"\tmovl\t-4(%ebp), %ecx\n"
	<<"\tleave\n"//-----
	<<"\tleal\t-4(%ecx), %esp\n"
	<<"\tret\n"//-----
	
	<<".LFE0:\n"//-----
	<<"\t.size\tmain, .-main\n\n";//-----

}
