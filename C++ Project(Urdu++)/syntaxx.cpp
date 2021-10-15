#include <iostream>
#include <fstream>
#include <String>
using namespace std;


//************************Global Declarations for Syntax Analyzer*************************/


int struct_index = 0, i = 0;
string arrayfile[1000];


bool A();
bool A1();
bool AgarYatou();
bool argscall();
bool argsdef();
bool argsdecl();
bool argsdef1();
bool assign();
bool assign1();
bool assign2();
bool argsdef2();
bool ASSIGN2();
bool Alifptr();
bool Alifarrg();
bool Alifg();
bool Alif1();
bool Alifvar();
bool Alifstr();
bool B();
bool B1();
bool body();
bool bodyif();
bool cinp();
bool coutp();
bool Chakkar();
bool Chalo();
bool constant();
bool casename();
bool casebody();
bool C();
bool C1();
bool decl();
bool decl1();
bool decl2();
bool decl3();
bool E();
bool E1();
bool funcinstr();
bool func_def();
bool func_decl();
bool F();
bool F1();
bool F2();
bool F3();
void getdatafromfile();
bool ifbody();
bool init();
bool init1();
bool INdecl3();
bool INC();
bool INC1();
bool ID1();
bool input();
bool inp1();
bool inp2();
bool inp3();
bool Jabtak();
bool KaroJabtak();
bool kirdar1();
bool L1();
bool L2();
bool L3();
bool L4();
bool L5();
bool list();
bool MainAlif();
bool mstrobj();
bool margsdef();
bool members();
bool m_ast();
bool m_dim();
bool mstrobj1();
bool m_id();
bool m_st();
bool m_value();
bool margscall();
bool Mamla();
bool m_obj();
bool mobj1();
bool m_st_obj();
bool m_inp();
bool m_out();
bool NOT();
bool objst();
bool obj1();
bool O_Nhetou();
bool O_Yatou();
bool O_id();
bool Op_br();
bool Op_br1();
bool ptrinc();
void saveinstruct(string arr[1000]);
bool structobj();
bool start();
bool struct_body();
bool switch_body();
bool s_st();
bool strobj1();
bool strobj2();
bool S1();
bool S2();
bool S3();
bool struct_st();
bool Tehshuda();
bool Tabdeel();
bool Tooto();
bool T();
bool T1();
bool type();
bool value();
bool voidg();
bool voidgfunc();
bool Wapis();
bool X();
bool Y();
bool Z();
bool Z1();
bool Z2();
bool Z3();


//************************Global Declarations for Semantic Analyzer*************************/


int sem_index=0;
int scopee=-1;
int starr[50];
int top=-1;
string id;
string typee;
string tempid;
int look;
string t1;
string t2;
bool next = true;
string op;


void insert(string namee, string typ, int scop);
bool lookup(string, int);
bool lookupdec(string, int);
string comp(string, string, string);


/*keyword
if=Agar else if=Nhetou else=Yatou while= Jabtak do=Karo for=Chakkar return=Wapis "Alif=variable" true=Sahi false=Galat continue=Chalo break=Tooto case=Mamla
switch=Tabdeel Tehshuda=Default Markazi= main void=kirdar Shuru=start Akhir=end
*/


struct tokenstruct
{
	string cp;
	string vp;
	string line;
}obj[1000];


struct tokenSemantic
{
	string name;
	string type;
	int scope;
}objs[1000];

//********************Main********************/

int main()
{
//	cout<<"\n\nChal gya :))\n\n";
//	string arr[1000];
//	filing(arr);
	getdatafromfile();
	cout<<"\n\n Saved in structure;\n\n";
	system("Pause");
	if(start())
		cout<<"\n\n Correct CFG. true\n";
	else
		cout<<"\n\n InCorrect CFG. false\n";
	cout<<"\n    Name\tType\t\tScope\t\n\n";
	for(int i=0;i<sem_index;i++)
		cout<<"\n "<<i+1<<") "<<objs[i].name<<"\t"<<objs[i].type<<"\t"<<objs[i].scope;
}


bool s_st() {
		next = true;
			if (AgarYatou()){
				return true;
			}else if (Chakkar()){
				return true;
			}else if (Jabtak()){
				return true;
			}else if (KaroJabtak()){
				return true;
			}else if (Tabdeel()){
				return true;
			}else if (decl()){
				return true;
			}else if (Tooto()){
				return true;
			}else if (Chalo()){
				return true;
			}else if (Wapis()){
				return true;
			}else if (structobj()){
				return true;
			}else if (cinp()){
				return true;
			}else if (coutp()){
				return true;
			}
		else if (obj[struct_index].cp == "ID") {
			struct_index++;
			if(lookup(obj[struct_index-1].vp, scopee)){
				if (L1())
					return true;
			}else{
				cout<<"\n\n Variable ("<<obj[struct_index-1].vp<<") NOT Defined.\n\n";
				if (L1())
					return true;
			}
		}
		else if (obj[struct_index].cp == "INCDEC") {
			struct_index++;
			if (L2())
				return true;
		}
		else if (obj[struct_index].cp == "*") {
			struct_index++;
			if (m_ast()) {
				if (obj[struct_index].cp == "ID") {
					struct_index++;
					if (L3())
						return true;
				}
			}
		}
	return false;
}


bool m_st() {
	if(s_st()){
		if (m_st())
			return true;
	}	
	else if (obj[struct_index].cp == "}")
		return true;
	return false;
}


bool start() {
	scopee++;
	top++;
	starr[top] = scopee;
	struct_index = 0;
	if (S1()) {
		if (obj[struct_index].cp == "Shuru") {
			struct_index++;
			if (obj[struct_index].cp == "{") {
				scopee++;
				top++;
				starr[top] = scopee;
				struct_index++;
				if (m_st()) {
					if (obj[struct_index].cp == "}") {
						top--;
						struct_index++;
						if (obj[struct_index].cp == "Akhir") {
							struct_index++;
							if (S2())
								return true;
						}
					}
				}
			}
		}
	}
	return false;
}


bool S1() {
	next = true;
	if (obj[struct_index].cp == "struct" || obj[struct_index].cp == "Kirdar" || obj[struct_index].cp == "DT" || obj[struct_index].cp == "ID" 
	|| obj[struct_index].cp == "*") {
		if (obj[struct_index].cp == "struct") {
			struct_index++;
			if (obj[struct_index].cp == "ID") {
				struct_index++;
				if (S3()){
					if (S1())
					return true;
				}
			}
		}
		else if (obj[struct_index].cp == "Kirdar") {
			struct_index++;
			if(voidg()){
				if (S1())
					return true;
			}
		}
		else if (obj[struct_index].cp == "DT") {
			struct_index++;
			if (MainAlif()) {
				if (S1())
					return true;
			}
		}else if(obj[struct_index].cp == "ID" || obj[struct_index].cp == "*"){
			if(assign()){
				if(S1())
					return true;
			}
		}
	}
	else if (obj[struct_index].cp == "Shuru")
		return true;
	return false;
}


bool voidg(){
	if (obj[struct_index].cp == "ID" || obj[struct_index].cp == "*") {
		if(obj[struct_index].cp == "*"){
			struct_index++;
			if(m_ast()){
				if(voidgfunc())
					return true;
			}
		}else if(obj[struct_index].cp == "ID"){
			if(voidgfunc())
				return true;
		}
	}
	return false;
}


bool voidgfunc(){
	if(obj[struct_index].cp == "ID"){
		struct_index++;
		if(obj[struct_index].cp == "("){
			struct_index++;
			if (argsdecl()) {
				if (obj[struct_index].cp == ")") {
					struct_index++;
					if (obj[struct_index].cp == ";") {
						struct_index++;
						return true;
					}
				}
			}
		}
	}
	return false;
}


bool MainAlif() {
	if (obj[struct_index].cp == "ID") {
		id=obj[struct_index].vp;
		struct_index++;
		if (Alifg())
			return true;
	}else if(obj[struct_index].cp == "*"){
		struct_index++;
		if(m_ast()){
			if(obj[struct_index].cp == "ID"){
				struct_index++;
				if (Alifptr())
					return true;
			}
		}
	}
	return false;
}


bool Alifptr() {
	if (obj[struct_index].cp == "(" || obj[struct_index].cp == "=" || obj[struct_index].cp == "," || obj[struct_index].cp == ";") {
		if(obj[struct_index].cp == "("){
			struct_index++;
			if (argsdecl()) {
				if (obj[struct_index].cp == ")") {
					struct_index++;
					if (obj[struct_index].cp == ";") {
						struct_index++;
						return true;
					}
				}
			}
		}else if(init()){
			if(list())
				return true;
		}

	}
	return false;
}


bool Alifg() {
	if (Alifptr()){
			return true;
	}
	else if (obj[struct_index].cp == "[") {
		struct_index++;
		if (Alifarrg())
			return true;
	}
	return false;
}


bool Alifarrg() {
	if (obj[struct_index].cp == "]") {
		struct_index++;
		if (m_dim()) {
			if (obj[struct_index].cp == "=" || obj[struct_index].cp == "," || obj[struct_index].cp == ";") {
				if (init()) {
					if (list())
						return true;
				}
			}
		}
	}
	else if (A()) {
		if (obj[struct_index].cp == "]") {
			struct_index++;
			if (m_dim()) {
				if (init()) {
					if (list())
						return true;
				}
			}
		}
	}
	return false;
}


bool S2() {
	next = true;
	if (obj[struct_index].cp == "Kirdar" || obj[struct_index].cp == "DT") {
		if (func_def()){
			if(S2())
				return true;
		}
	}
	else if (obj[struct_index].cp == "$")
		return true;
	return false;
}


bool S3(){
	if(obj[struct_index].cp == "{" || obj[struct_index].cp == "ID"){
		if(obj[struct_index].cp == "{"){
			struct_index++;
			if(members()){
				if(obj[struct_index].cp == "}"){
					struct_index++;
					if(objst()){
						if(obj[struct_index].cp == ";"){
							struct_index++;
							return true;
						}
					}	
				}
			}
		}else if(obj[struct_index].cp == "ID"){
			if(strobj1())
				return true;
		}
	}
	return false;
}


bool mstrobj(){
	if(obj[struct_index].cp == "[" || obj[struct_index].cp == "," || obj[struct_index].cp == ";"){
		if(obj[struct_index].cp == ";"){
			struct_index++;
			return true;
		}else if(obj[struct_index].cp == ","){
			struct_index++;
			if(obj[struct_index].cp == "ID"){
				struct_index++;
				if(mstrobj())
				return true;
			}
		}
		else if(obj[struct_index].cp == "["){
			struct_index++;
			if(A()){
				if(obj[struct_index].cp == "]"){
					struct_index++;
					if(mstrobj())
						return true;
				}
			}
		}	
	}
	return false;
}


bool coutp(){
	if(obj[struct_index].cp == "cout"){
		struct_index++;
		if(obj[struct_index].cp == "Extraction"){
			struct_index++;
			if(A()){
				if(m_out())
					return true;
			}
		}
	}
	return false;
}


bool m_out(){
	if(obj[struct_index].cp == "Extraction"){
		struct_index++;
		if(A()){
			if(m_out())
				return true;
		}
	}else if(obj[struct_index].cp == ";"){
		struct_index++;
		return true;
	}	
	return false;
}


bool cinp(){
	if(obj[struct_index].cp == "cin"){
		struct_index++;
		if(obj[struct_index].cp == "Insertion"){
			struct_index++;
			if(input()){
				if(m_inp())
					return true;
			}
		}
	}
	return false;
}


bool input(){
	if(obj[struct_index].cp == "ID" || obj[struct_index].cp == "*"){
		if(obj[struct_index].cp == "ID"){
			struct_index++;
			if(inp1())
				return true;
		}else if(obj[struct_index].cp == "*"){
			struct_index++;
			if(m_ast()){
				if(obj[struct_index].cp == "ID"){
					struct_index++;
					return true;
				}
			}else if(obj[struct_index].cp == "ID"){
				struct_index++;
				return true;
			}
		}
	}
	return false;
}


bool inp1(){
	if(obj[struct_index].cp == "["){
		struct_index++;
		if(A()){
			if(obj[struct_index].cp == "]"){
				struct_index++;
				if(m_dim()){
					if(inp2())
						return true;
				}
			}
		}
	}else if(obj[struct_index].cp == "."){
		struct_index++;
		if(obj[struct_index].cp == "ID"){
			struct_index++;
			if(inp3())
				return true;
		}
	}else if(obj[struct_index].cp == "Insertion" || obj[struct_index].cp == ";"){
		return true;		
	}
	return false;
}


bool inp2(){
	if(obj[struct_index].cp == "."){
		struct_index++;
		if(obj[struct_index].cp == "ID"){
			struct_index++;
			if(inp3())
				return true;
		}
	}else if(obj[struct_index].cp == "Insertion" || obj[struct_index].cp == ";"){
		return true;		
	}
	return false;
}


bool inp3(){
	if(obj[struct_index].cp == "["){
		struct_index++;
		if(A()){
			if(obj[struct_index].cp == "]"){
				struct_index++;
				if(m_dim())
						return true;
			}
		}
	}else if(obj[struct_index].cp == "Insertion" || obj[struct_index].cp == ";"){
		return true;		
	}	
	return false;
}


bool m_inp(){
	if(obj[struct_index].cp == "Insertion"){
		struct_index++;
		if(input()){
			if(m_inp())
				return true;
		}
	}else if(obj[struct_index].cp == ";"){
		struct_index++;
		return true;
	}	
	return false;
}


bool m_ast() {
	if (obj[struct_index].cp == "*") {
		struct_index++;
		if (m_ast())
			return true;
	}
	else if (obj[struct_index].cp == "ID") 
		return true;
	return false;
}


bool L1() {
	if (obj[struct_index].cp == "(" || obj[struct_index].cp == "INCDEC" || obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "=" ||
		obj[struct_index].cp == "[") {

		if (obj[struct_index].cp == "(") {
			struct_index++;
			if (argscall()) {
				if (obj[struct_index].cp == ")") {
					struct_index++;
					if (obj[struct_index].cp == ";") {
						struct_index++;
						return true;
					}
				}
			}
		}
		else if (obj[struct_index].cp == "INCDEC") {
			struct_index++;
			if (obj[struct_index].cp == ";") {
				struct_index++;
				return true;
			}
		}
		else if (obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "=") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == ";") {
					struct_index++;
					return true;
				}
			}
		}
		else if (obj[struct_index].cp == "[") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == "]") {
					struct_index++;
					if(m_dim()){
						if (L4())
							return true;
					}
					
				}
			}
		}
	}
	return false;
}


bool L2() {
	if (obj[struct_index].cp == "ID" || obj[struct_index].cp == "*") {
		if (obj[struct_index].cp == "*") {
			struct_index++;
			if (m_ast()) {
				if (obj[struct_index].cp == "ID") {
					struct_index++;
					if (obj[struct_index].cp == ";") {
						struct_index++;
						return true;
					}
				}
			}
		}else if(obj[struct_index].cp == "ID"){
			struct_index++;
			if (L5())
				return true;
		}
	}
	return false;
}


bool L3() {
	if (obj[struct_index].cp == "INCDEC" || obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "=") {
		if (obj[struct_index].cp == "INCDEC") {
			struct_index++;
			if (obj[struct_index].cp == ";") {
				struct_index++;
				return true;
			}
		}
		else if (obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "=") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == ";") {
					struct_index++;
					return true;
				}
			}
		}
	}
	return false;
}


bool L4() {
	if (obj[struct_index].cp == "INCDEC" || obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "=") {
		if (obj[struct_index].cp == "INCDEC") {
			struct_index++;
			if (obj[struct_index].cp == ";") {
				struct_index++;
				return true;
			}
		}
		else if (obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "=") {
			struct_index++;
			if (ASSIGN2())
				return true;
		}
	}
	return false;
}


bool L5() {
	if (obj[struct_index].cp == "[" || obj[struct_index].cp == ";") {
		if (obj[struct_index].cp == "[") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == "]") {
					struct_index++;
					if(m_dim()){
						if (obj[struct_index].cp == ";") {
							struct_index++;
							return true;
						}
					}
				}
			}
		}
		else if (obj[struct_index].cp == ";") {
			struct_index++;
			return true;
		}
	}
	return false;
}


bool Wapis() {
	if (obj[struct_index].cp == "Wapis") {
		struct_index++;
		if (obj[struct_index].cp == ";") {
			struct_index++;
			return true;
		}
		else if (A()){
			if (obj[struct_index].cp == ";") {
				struct_index++;
				return true;
			}
		}
	}
	return false;
}


bool Tooto() {
	if (obj[struct_index].cp == "Tooto") {
		struct_index++;
		if (obj[struct_index].cp == ";") {
			struct_index++;
			return true;
		}
	}
	return false;
}


bool Chalo() {
	if (obj[struct_index].cp == "Chalo") {
		struct_index++;
		if (obj[struct_index].cp == ";") {
			struct_index++;
			return true;
		}
	}
	return false;
}


bool structobj() {
	if (obj[struct_index].cp == "struct") {
		struct_index++;
		if (obj[struct_index].cp == "ID") {
			struct_index++;
			if (strobj1())
				return true;
		}
	}
	return false;
}


bool strobj1() {
	if (obj[struct_index].cp == "*") {
		struct_index++;
		if (m_ast()) {
			if (obj[struct_index].cp == "ID") {
			struct_index++;
				if (strobj2())
					return true;
			}
		}
	}else if (obj[struct_index].cp == "ID") {
		struct_index++;
		if (strobj2())
			return true;
	}
	return false;
}


//bool mstrobj1() {
//	if (obj[struct_index].cp == "," || obj[struct_index].cp == ";") {
//		if (obj[struct_index].cp == ";") {
//			struct_index++;
//			return true;
//		}
//		else if (obj[struct_index].cp == ",") {
//			struct_index++;
//			if (mstrobj1())
//				return true;
//			else
//				return false;
//		}
//		else
//			return false;
//	}
//	else
//		return false;
//}


bool strobj2() {
	if (obj[struct_index].cp == "[" || obj[struct_index].cp == "," || obj[struct_index].cp == ";") {
		if (obj[struct_index].cp == "[") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == "]") {
					struct_index++;
					if (strobj2())
						return true;
				}
			}
		}
		else if (obj[struct_index].cp == ","){
			struct_index++;
			if(strobj1())
				return true;
		}else if (obj[struct_index].cp == ";"){
			struct_index++;
			return true;
		}
	}
	return false;
}


bool decl() {
	if (obj[struct_index].cp == "DT") {
		struct_index++;
		if (decl1())
			return true;
	}
	return false;
}


bool decl1() {
	if (obj[struct_index].cp == "ID") {
		id=obj[struct_index].vp;
		struct_index++;
			if (decl2())
				return true;
	}else if(obj[struct_index].cp == "*") {
		struct_index++;
		if(m_ast()){
			if(obj[struct_index].cp == "ID") {
				struct_index++;
				if(init()){
					if(list())
						return true;
				}
			}
		}
	}
	return false;
}


bool decl2() {
	if (obj[struct_index].cp == "[" || obj[struct_index].cp == "=" || obj[struct_index].cp == "," || obj[struct_index].cp == ";") {
		if (obj[struct_index].cp == "[") {
			struct_index++;
			if (decl3())
				return true;
		}
		else if (init()) {
			if (list())
				return true;
		}
	}
	return false;
}


bool decl3() {
	if (obj[struct_index].cp == "ID" || obj[struct_index].cp == "*" || obj[struct_index].cp == "&" || obj[struct_index].cp == "!" || obj[struct_index].cp == "(" ||
		obj[struct_index].cp == "INCDEC" || obj[struct_index].cp == "Sahi" || obj[struct_index].cp == "Galat" || obj[struct_index].cp == "int_const" || 
		obj[struct_index].cp == "float_const" || obj[struct_index].cp == "char_const" || obj[struct_index].cp == "string_const"){
			if (A()) {
				if (INdecl3())
					return true;
			}
	}if(obj[struct_index].cp == "]"){
			if (INdecl3())
				return true;
	}
	return false;
}


bool INdecl3() {
	if (obj[struct_index].cp == "]") {
		struct_index++;
		if (m_dim()) {
			if (init()) {
				if (list())
					return true;
			}
		}
	}
	return false;
}


bool list() {
	if (obj[struct_index].cp == "," || obj[struct_index].cp == ";") {
		if (obj[struct_index].cp == ",") {
			struct_index++;
			if (decl1())
				return true;
		}
		else if (obj[struct_index].cp == ";") {
			struct_index++;
			return true;
		}
	}
	return false;
}


bool init() {
	if (obj[struct_index].cp == "," || obj[struct_index].cp == "=" || obj[struct_index].cp == ";") {
		if (obj[struct_index].cp == "=") {
			struct_index++;
			if (init1())
				return true;
		}
		else if (obj[struct_index].cp == "," || obj[struct_index].cp == ";")
			return true;
	}
	return false;
}


bool init1() {
	if (A()) {
		if(typee == "Data Type MisMatch."){
			return false;
		}else{
			insert(id, typee, scopee);
			return true;
		}
		
	}
	else if (obj[struct_index].cp == "{") {
		struct_index++;
		if (value()) {
			if (obj[struct_index].cp == "}") {
				struct_index++;
				return true;
			}
		}
	}
	return false;
}


bool value() {
	if (A()) {
		if (m_value()) {
			return true;
		}
	}	
	else if (Op_br())
		return true;
	return false;
}


bool m_value() {
	if (obj[struct_index].cp == "," || obj[struct_index].cp == "}") {
		if (obj[struct_index].cp == ",") {
			struct_index++;
			if (value())
				return true;
		}
		else if (obj[struct_index].cp == "}")
			return true;
		else
			return false;
	}
	return false;
}


bool Op_br() {
	if (obj[struct_index].cp == "{") {
		struct_index++;
		if (A()) {
			if (m_value()) {
				if (obj[struct_index].cp == "}") {
					struct_index++;
					if (m_value())
						return true;
				}
			}
		}
	}
	return false;
}


//bool Op_br1() {
//	if (obj[struct_index].cp == "," || obj[struct_index].cp == "}") {
//		if (obj[struct_index].cp == ",") {
//			struct_index++;
//			if (Op_br())
//				return true;
//			else
//				return false;
//		}
//		else if (obj[struct_index].cp == "}")
//			return true;
//		else
//			return false;
//	}
//	else
//		return false;
//}


bool m_dim() {
	if (obj[struct_index].cp == "[") {
		struct_index++;
		if (A()) {
			if (obj[struct_index].cp == "]") {
				struct_index++;
				if (m_dim())
					return true;
			}
		}
	}
	else if (obj[struct_index].cp == "," || obj[struct_index].cp == ")" || obj[struct_index].cp == ";" || obj[struct_index].cp == "=" ||
		obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "INCDEC" || obj[struct_index].cp == "." || obj[struct_index].cp == "Insertion" 
		|| obj[struct_index].cp == "Extraction") {
		return true;
	}
	return false;
}

//cout<<"\n\nAgya\n\n";
bool AgarYatou() {		
	if (obj[struct_index].cp == "Agar") {
		struct_index++;
		if (obj[struct_index].cp == "(") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == ")") {
					struct_index++;
					if (obj[struct_index].cp == "{") {
						scopee++;
						top++;
						starr[top] = scopee;
						struct_index++;
						if (m_st()) {
							if (obj[struct_index].cp == "}") {
								top--;
								struct_index++;
								if (O_Nhetou()) {
									if (O_Yatou())
										return true;
								}
							}	
						}
					}
				}
			}
		}
	}
	return false;
}

//cout<<"\n\nAgyaa\n\nNext Indexz is "<<obj[struct_index].cp;system("Pause");



bool O_Nhetou() {
	if (obj[struct_index].cp == "Nhetou") {
		struct_index++;
		if (obj[struct_index].cp == "(") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == ")") {
					struct_index++;
					if (obj[struct_index].cp == "{") {
						scopee++;
						top++;
						starr[top] = scopee;
						struct_index++;
						if (m_st()) {
							if (obj[struct_index].cp == "}") {
								top--;
								struct_index++;
								if(O_Nhetou())
									return true;
							}
						}
					}
				}
			}
		}
	}
	else if (obj[struct_index].cp == "Yatou" || obj[struct_index].cp == "Agar" || obj[struct_index].cp == "Chakkar" || obj[struct_index].cp == "Jabtak" ||
		obj[struct_index].cp == "Karo" || obj[struct_index].cp == "Tabdeel" || obj[struct_index].cp == "Alif" || obj[struct_index].cp == "Tooto" ||
		obj[struct_index].cp == "Chalo" || obj[struct_index].cp == "Wapis" || obj[struct_index].cp == "struct" || obj[struct_index].cp == "ID" ||
		obj[struct_index].cp == "INCDEC" || obj[struct_index].cp == "*" || obj[struct_index].cp == "}")
		return true;
	return false;
}


bool O_Yatou() {
	if (obj[struct_index].cp == "Yatou") {
		struct_index++;
		if (obj[struct_index].cp == "{") {
			scopee++;
			top++;
			starr[top] = scopee;
			struct_index++;
			if (m_st()) {
				if (obj[struct_index].cp == "}") {
					top--;
					struct_index++;
					return true;
				}
			}
		}
	}
	else if (obj[struct_index].cp == "Agar" || obj[struct_index].cp == "Chakkar" || obj[struct_index].cp == "Jabtak" || obj[struct_index].cp == "Karo" ||
		obj[struct_index].cp == "Tabdeel" || obj[struct_index].cp == "Alif" || obj[struct_index].cp == "Tooto" || obj[struct_index].cp == "Chalo" ||
		obj[struct_index].cp == "Wapis" || obj[struct_index].cp == "struct" || obj[struct_index].cp == "ID" || obj[struct_index].cp == "INCDEC" ||
		obj[struct_index].cp == "*" || obj[struct_index].cp == "}")
		return true;
	return false;
}


bool Chakkar() {
	if (obj[struct_index].cp == "Chakkar") {
		struct_index++;
		if (obj[struct_index].cp == "(") {
			struct_index++;
			if (X()) {
				if (Y()) {
					if (obj[struct_index].cp == ";") {
						struct_index++;
						if (Z()) {
							if (obj[struct_index].cp == ")") {
								struct_index++;
								if (body())
									return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}


bool X() {
	if (decl()) {
		return true;
	}
	else if (assign()) {
		return true;
	}
	else if (obj[struct_index].cp == ";") {
		struct_index++;
		return true;
	}
	return false;
}


bool Y() {
	if (A()) {
		return true;
	}
	else if (obj[struct_index].cp == ";") {
		return true;
	}
	return false;
}


bool Z() {
	if (obj[struct_index].cp == "ID" || obj[struct_index].cp == "INCDEC" || obj[struct_index].cp == "*") {
		if (obj[struct_index].cp == "ID") {
			struct_index++;
			if (Z1())
				return true;
			if (Z3())
				return true;
		}
		else if (obj[struct_index].cp == "INCDEC") {
			struct_index++;
			if (Z2())
				return true;
		}else if(obj[struct_index].cp == "*"){
			struct_index++;
			if(m_ast()){
				if(obj[struct_index].cp == "ID"){
					struct_index++;
					if(Z3())
						return true;
				}
			}
		}
	}
	else if (obj[struct_index].cp == ")")
		return true;
	return false;
}


bool Z1() {
	if (obj[struct_index].cp == "INCDEC" || obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "=" || obj[struct_index].cp == "[") {
		if (obj[struct_index].cp == "INCDEC") {
			struct_index++;
			return true;
		}
		else if (obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "=") {
			struct_index++;
			if (A())
				return true;
		}
		else if (obj[struct_index].cp == "[") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == "]") {
					struct_index++;
					if (m_dim()) {
						if (obj[struct_index].cp == "=" || obj[struct_index].cp == "ASSGN-OP") {
							struct_index++;
							if (A())
								return true;
						}
					}
				}
			}
		}
	}
	return false;
}


bool Z2() {
	if (ID1())
		return true;
	return false;
}


bool Z3() {
	if (obj[struct_index].cp == "INCDEC" || obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "=") {
		if (obj[struct_index].cp == "INCDEC") {
			struct_index++;
			return true;
		}
		else if (obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "=") {
			struct_index++;
			if (A())
				return true;
		}
	}
	return false;
}


bool assign() {
	if (obj[struct_index].cp == "*" || obj[struct_index].cp == "ID") {
		if (obj[struct_index].cp == "ID") {
			id=obj[struct_index].vp;
			struct_index++;
			if(lookup(id, scopee)){
				if (assign1())
					return true;
			}else{
				cout<<"\n\n Variable ("<<id<<") NOT Defined.\n\n";
				if (assign1())
					return true;
			}
		}
		else if (obj[struct_index].cp == "*") {
			struct_index++;
			if (m_ast()) {
				if (obj[struct_index].cp == "ID") {
					struct_index++;
					if (obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "=") {
						struct_index++;
						if (A()) {
							if (obj[struct_index].cp == ";") {
								struct_index++;
								return true;
							}
						}
					}
				}
			}
//			else if (obj[struct_index].cp == "ID") {
//				struct_index++;
//				if (obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "=") {
//					struct_index++;
//					if (A()) {
//						if (obj[struct_index].cp == ";") {
//							struct_index++;
//							return true;
//						}
//					}
//				}
//			}
		}
	}
	return false;
}


bool assign1() {
	if (obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "=" || obj[struct_index].cp == "[") {
		if (obj[struct_index].cp == "ASSGN_OP" || obj[struct_index].cp == "=") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == ";") {
					struct_index++;
					return true;
				}
			}
		}
		else if (obj[struct_index].cp == "[") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == "]") {
					struct_index++;
					if (m_dim()) {
						if (obj[struct_index].cp == "=" || obj[struct_index].cp == "ASSGN_OP") {
							struct_index++;
							if (assign2())
								return true;
						}
					}
				}
			}
		}
	}
	return false;
}


bool assign2() {
	if (A()) {
		if (obj[struct_index].cp == ";") {
			struct_index++;
			return true;
		}
	}
	return false;
}


bool ASSIGN2() {
	if (assign2()) {
		return true;
	}
	else if (obj[struct_index].cp == "{") {
		struct_index++;
		if (value()) {
			if (obj[struct_index].cp == "}") {
				struct_index++;
				if (obj[struct_index].cp == ";") {
					struct_index++;
					return true;
				}
			}
		}
	}
	return false;
}


bool Tabdeel() {
	if (obj[struct_index].cp == "Tabdeel") {
		struct_index++;
		if (obj[struct_index].cp == "(") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == ")") {
					struct_index++;
					if (switch_body())
						return true;
				}
			}
		}
	}
	return false;
}


bool switch_body() {
	if (obj[struct_index].cp == "{") {
		scopee++;
		top++;
		starr[top] = scopee;
		struct_index++;
		if (Mamla()) {
			if (Tehshuda()) {
				if (Mamla()) {
					if (obj[struct_index].cp == "}") {
						top--;
						struct_index++;
						return true;
					}
				}
			}
		}
	}
	return false;
}


bool Mamla() {
	if (obj[struct_index].cp == "Mamla") {
		struct_index++;
		if (casename()) {
			if (obj[struct_index].cp == ":") {
				struct_index++;
				if (casebody()) {
					if (Mamla())
						return true;
				}
			}
		}
	}
	else if (obj[struct_index].cp == "}" || obj[struct_index].cp == "Tehshuda") {
		return true;
	}
	return false;
}

//	cout<<"\n\nAgyaa\n\n"<<obj[struct_index].cp<<"\n\n";system("Pause");
bool Tehshuda() {
	if (obj[struct_index].cp == "Tehshuda") {
		struct_index++;
		if (obj[struct_index].cp == ":") {
			struct_index++;
			if (casebody())
				return true;
		}
	}
	return false;
}


bool casename() {
	if (obj[struct_index].cp == "ID" || obj[struct_index].cp == "int_const" || obj[struct_index].cp == "char_const") {
		struct_index++;
		return true;
	}
	return false;
}


bool casebody() {
	if (obj[struct_index].cp == "{") {
		scopee++;
		top++;
		starr[top] = scopee;
		struct_index++;
		if (m_st()) {
			if (obj[struct_index].cp == "}") {
				top--;
				struct_index++;
				return true;
			}
		}
	}
	return false;
}


bool Jabtak() {
	if (obj[struct_index].cp == "Jabtak") {
		struct_index++;
		if (obj[struct_index].cp == "(") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == ")") {
					struct_index++;
					if (body())
						return true;
				}
			}
		}

	}
	return false;
}


bool KaroJabtak() {
	if (obj[struct_index].cp == "Karo") {
		struct_index++;
		if (body()) {
			if (obj[struct_index].cp == "Jabtak") {
				struct_index++;
				if (obj[struct_index].cp == "(") {
					struct_index++;
					if (A()) {
						if (obj[struct_index].cp == ")") {
							struct_index++;
							if (obj[struct_index].cp == ";") {
								struct_index++;
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}


bool body() {
	if (obj[struct_index].cp == "{") {
		scopee++;
		top++;
		starr[top]=scopee;
		struct_index++;
		if (m_st()) {
			if (obj[struct_index].cp == "}") {
				top--;
				struct_index++;
				return true;
			}
		}
	}
	else if (obj[struct_index].cp == "Agar" || obj[struct_index].cp == "Chakkar" || obj[struct_index].cp == "Jabtak" || obj[struct_index].cp == "Karo" ||
		obj[struct_index].cp == "Tabdeel" || obj[struct_index].cp == "Alif" || obj[struct_index].cp == "Tooto" || obj[struct_index].cp == "Chalo" ||
		obj[struct_index].cp == "Wapis" || obj[struct_index].cp == "struct" || obj[struct_index].cp == "ID" || obj[struct_index].cp == "INCDEC" ||
		obj[struct_index].cp == "*" || obj[struct_index].cp == "}")
		return true;
	return false;
}


//********************Saving Tokens in Structure********************/


void saveinstruct(string arr[1000]) {
	int t = 0, j = 0, a = 0;
	bool check = false;
	string input, temp = "";
	while (t < i) {
		input = arr[t];
		j = 0;
		while (j < input.size()) {

			if (check) {
				if (obj[struct_index].cp.empty()) {
					obj[struct_index].cp = temp;
					temp.clear();
				}
				else if (obj[struct_index].vp.empty() && !(obj[struct_index].cp.empty())) {
					obj[struct_index].vp = temp;
					temp.clear();
				}
				else if (obj[struct_index].line.empty() && !(obj[struct_index].cp.empty()) && !(obj[struct_index].vp.empty())) {
					obj[struct_index].line = temp;
					temp.clear();
					struct_index++;
				}
				check = false;
			}
			if (input[j] == '(') {
				if (input[j - 1] != '(') {
					if (input[j - 1] == ',' && input[j + 1] == ',') {
						temp += input[j];
						check = true;
						j++;
					}
					else {
						check = false;
						j++;
					}
				}
				else {
					temp += input[j];
					check = true;
					j++;
				}
			}
			else
				if (input[j] == ')') {
					if (input[j + 1] != ')') {
						if (input[j - 1] == '(' || input[j - 1] == ',') {
							temp += input[j];
							check = true;
							j++;
						}
						else {
							check = false;
							j++;
						}
					}
					else {
						temp += input[j];
						check = true;
						j++;
					}
				}
				else
					if (isalpha(input[j]) || isdigit(input[j]) || input[j] == '_') {
						temp += input[j];
						if (input[j + 1] == ',' || input[j + 1] == ')') {
							check = true;
						}
						else {
							check = false;
						}
						j++;
					}
					else
						if (input[j] == ',') {
							if (input[j - 1] != ',' && input[j + 1] != ',') {
								check = false;
								j++;
							}
							else if (input[j - 1] == ',' && input[j + 1] == ',') {
								if (input[j + 2] == ',') {
									check = false;
									j++;
								}
								else {
									temp += input[j];
									check = true;
									j++;
								}
							}
							else {
								if (!(obj[struct_index].vp.empty())) {
									check = false;
									j++;
								}
								else {
									temp += input[j];
									check = true;
									j++;
								}
							}
						}
						else {
							if(input[j] == '|'){
//								if(!(temp.empty())){
//									arr[j] = temp;
//									array2[arr2_index] = n+1;
//									arr2_index++;
//									temp.clear();
//									j++;
//								}
								temp = input[j];
								j++;
								while(input[j] != '|'){
									temp +=input[j];
									j++;
								}
								if(input[j] == '|'){
									if(temp.size()>1){
										temp += input[j];
										j++;
										check = true;
									}
								}
//										if(!(temp.empty())){
//											arr[j] = temp;
//											temp.clear();
//											array2[arr2_index] = n+1;
//											arr2_index++;
//											j++;
//										}
							}else

							if ((input[j] == '+' && input[j + 1] == '+') || (input[j] == '-' && input[j + 1] == '-') || (input[j] == '&' && input[j + 1] == '&')
								/*|| (input[j] == '|' && input[j + 1] == '|')*/ || (input[j] == '=' && input[j + 1] == '=') || (input[j] == '+' && input[j + 1] == '=')
								|| (input[j] == '-' && input[j + 1] == '=') || (input[j] == '*' && input[j + 1] == '=') || (input[j] == '/' && input[j + 1] == '=')
								|| (input[j] == '%' && input[j + 1] == '=') || (input[j] == '>' && input[j + 1] == '=') || (input[j] == '<' && input[j + 1] == '=')
								|| (input[j] == '>' && input[j + 1] == '>') || (input[j] == '<' && input[j + 1] == '<') || (input[j] == '!' && input[j + 1] == '=')) {
								temp += input[j];
								j++;
								temp += input[j];
								j++;
								check = true;
							}
							else if ((input[j] == '+' && input[j + 1] != '+') || (input[j] == '-' && input[j + 1] != '-') || (input[j] == '&' && input[j + 1] != '&')
								|| (input[j] == '=' && input[j + 1] != '=') || (input[j] == '+' && input[j + 1] != '=')
								|| (input[j] == '-' && input[j + 1] != '=') || (input[j] == '*' && input[j + 1] != '=') || (input[j] == '/' && input[j + 1] != '=')
								|| (input[j] == '%' && input[j + 1] != '=') || (input[j] == '>' && input[j + 1] != '=') || (input[j] == '<' && input[j + 1] != '=')
								|| (input[j] == '>' && input[j + 1] != '>') || (input[j] == '<' && input[j + 1] != '<') || (input[j] == '!' && input[j + 1] != '=')) {
								temp += input[j];
								j++;
								check = true;
							}
							else if (input[j] == '\"') {
								temp = input[j];
								j++;
								while (input[j] != '\"') {
									temp += input[j];
									j++;
								}
								temp += input[j];
								j++;
								check = true;
							}
							else if (input[j] == '\'') {
								temp = input[j];
								j++;
								a = 0;
								if (input[j] == '\\') {
									temp = input[j];
									j++;
									while (a < 2) {
										temp += input[j];
										j++;
										a++;
									}
									check = true;
								}
								else {
									while (a < 2) {
										temp += input[j];
										j++;
										a++;
									}
									check = true;
								}
							}
							else {
								temp += input[j];
								j++;
								check = true;
							}
						}
		}
		t++;
	}
	cout << "\n\n Size of Struct is " << struct_index << endl;
//	for (int i = 0; i < struct_index; i++)
//		cout << " \n\t " << obj[i].cp << "\t" << obj[i].vp << "\t" << obj[i].line;
}


//********************Get data from file********************/


void getdatafromfile() {
	ifstream file("File4.txt");
	string temp;
	if (file.is_open()) {
		cout << " File is open.\n";
		while (getline(file, temp)) {
			if (!file)
				break;
			arrayfile[i] = temp;
			i++;
		}
		for (int f = 0; f < i; f++)
			cout << " " << arrayfile[f] << "\n";
		cout << "\n\n";
		saveinstruct(arrayfile);
	}
	else {
		cout << " File NOT open.\n";
	}
}


/********************Expression********************/


bool A() {
	if (B()) {
		if (A1())
			return true;			
	}
	return false;
}


bool A1() {
	if (obj[struct_index].cp == "LOG_OP") {
		struct_index++;
		if (B()) {
			if (A1())
				return true;
		}
	}
	else if (obj[struct_index].cp == "]" || obj[struct_index].cp == "," || obj[struct_index].cp == ";" || obj[struct_index].cp == "}" 
	|| obj[struct_index].cp == ")" || obj[struct_index].cp == "Extraction")
		return true;
	return false;
}


bool B() {
	if (C()) {
		if (B1())
			return true;
	}
	return false;
}


bool B1() {
	if (obj[struct_index].cp == "LOG_OP") {
		struct_index++;
		if (C()) {
			if (B1())
				return true;
		}
	}
	else if (obj[struct_index].cp == "LOG_OP" || obj[struct_index].cp == "]" || obj[struct_index].cp == "," || obj[struct_index].cp == ";" 
	|| obj[struct_index].cp == "}" || obj[struct_index].cp == ")" || obj[struct_index].cp == "Extraction")
		return true;
	return false;
}


bool C() {
	if (E()) {
		if (C1())
			return true;
	}
	return false;
}


bool C1() {
	if (obj[struct_index].cp == "REL_OP") {
		struct_index++;
		if (E()) {
			if (C1())
				return true;
		}
	}
	else if (obj[struct_index].cp == "LOG_OP" || obj[struct_index].cp == "]" || obj[struct_index].cp == "," || obj[struct_index].cp == ";" 
	|| obj[struct_index].cp == "}" || obj[struct_index].cp == ")" || obj[struct_index].cp == "Extraction")
		return true;
	return false;
}


bool E() {
	if (T()) {
		if (E1())
			return true;
	}
	return false;
}


bool E1() {
	if (obj[struct_index].cp == "ADDSUB") {
		struct_index++;
		op = obj[struct_index-1].vp;
		if (T()) {
			
			typee = comp(typee, t2, op);
			cout<<"AGYAAAAAAAAAAAAaa\n\n"<<typee<<"\n\n"<<t2;
			if(typee == "Data Type MisMatch."){
				cout << "\n\nData Type MisMatch.\n\n";
				return false;
			}else{
				if (E1())
				return true;
			}
		}
	}
	else if (obj[struct_index].cp == "REL_OP" || obj[struct_index].cp == "LOG_OP" || obj[struct_index].cp == "]" || obj[struct_index].cp == "," 
	|| obj[struct_index].cp == ";" || obj[struct_index].cp == "}" || obj[struct_index].cp == ")" || obj[struct_index].cp == "Extraction")
		return true;
	return false;
}


bool T() {
	if (F()) {
//		t1=typee;
		if(next){
			typee = t1;
			next = false;
		}else{
			t2 = t1;
		}
		if (T1()){
			return true;
		}
	}
	return false;
}


bool T1() {
	if (obj[struct_index].cp == "DIVMUL" || obj[struct_index].cp == "*") {
		struct_index++;
		op = obj[struct_index-1].vp;
		if (F()) {
			
				cout<<"AGYAAAAAAAAAAfdgdfAAaa\n\n"<<typee<<"\n\n";
			if(next){
				typee = t1;
				next = false;
				
			}else{
				t2 = t1;
				typee = comp(typee, t2, op);
				if(typee == "Data Type MisMatch."){
					cout << "\n\nData Type MisMatch.\n\n";
					return false;
				}
			}
//			t2 = typee;
			if (T1())
				return true;
		}
	}
	else if (obj[struct_index].cp == "ADDSUB" || obj[struct_index].cp == "REL_OP" || obj[struct_index].cp == "LOG_OP" || obj[struct_index].cp == "]" 
	|| obj[struct_index].cp == "," || obj[struct_index].cp == ";" || obj[struct_index].cp == "}" || obj[struct_index].cp == ")" 
	|| obj[struct_index].cp == "Extraction"){
		return true;
	}
	return false;
}


bool F() {
	if (obj[struct_index].cp == "ID" || obj[struct_index].cp == "*" || obj[struct_index].cp == "&" || obj[struct_index].cp == "!" || obj[struct_index].cp == "(" ||
		obj[struct_index].cp == "INCDEC" || obj[struct_index].cp == "Sahi" || obj[struct_index].cp == "Galat" || obj[struct_index].cp == "int_const" || 
		obj[struct_index].cp == "float_const" || obj[struct_index].cp == "char_const" || obj[struct_index].cp == "string_const") {

		if (obj[struct_index].cp == "ID") {
			//id=obj[struct_index].vp;
			struct_index++;
			if(lookup(obj[struct_index-1].vp,scopee)){
				t1 = objs[look].type;
				if (F1())
					return true;
			}else{
				cout<<"\n\n UnDeclared ID\n\n";
				if (F1())
					return true;
			}
		}
		else if (obj[struct_index].cp == "*") {
			struct_index++;
			if (m_ast()) {
				if (obj[struct_index].cp == "ID") {
					struct_index++;
					if (ptrinc())
						return true;
				}
			}
		}
		else if (obj[struct_index].cp == "&") {
			struct_index++;
			if (obj[struct_index].cp == "ID") {
				struct_index++;
				return true;
			}
		}
		else if (obj[struct_index].cp == "!") {
			struct_index++;
			if (NOT())
				return true;
		}
		else if (obj[struct_index].cp == "(") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == ")") {
					struct_index++;
					return true;
				}
			}
		}
		else if (obj[struct_index].cp == "INCDEC") {
			struct_index++;
			if (INC())
				return true;
		}
		else if (obj[struct_index].cp == "Sahi" || obj[struct_index].cp == "Galat") {
			struct_index++;
			typee = "bool_const";
			return true;
		}else if (constant()) {
			cout<<"\n "<<t1<<" "<<obj[struct_index-1].vp<<endl;
			return true;
		}
	}
	return false;
}


bool constant() {
	if (obj[struct_index].cp == "int_const" || obj[struct_index].cp == "float_const" || obj[struct_index].cp == "char_const" 
	|| obj[struct_index].cp == "string_const") {
		t1 = obj[struct_index].cp;
		struct_index++;
		return true;
	}
	return false;
}


bool NOT() {
	if (obj[struct_index].cp == "ID") {
		struct_index++;
		return true;
	}
	else if (obj[struct_index].cp == "(") {
		struct_index++;
		if (A()) {
			if (obj[struct_index].cp == ")") {
				struct_index++;
				return true;
			}
		}
	}
	return false;
}


bool F1() {
	if (obj[struct_index].cp == "(" || obj[struct_index].cp == "[" || obj[struct_index].cp == "." || obj[struct_index].cp == "INCDEC") {
		if (obj[struct_index].cp == "(") {
			struct_index++;
			if (argscall()) {
				if (obj[struct_index].cp == ")") {
					struct_index++;
					return true;
				}
			}
		}
		else if (obj[struct_index].cp == "[") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == "]") {
					struct_index++;
					if(m_dim()){
						if (F2())
							return true;
					}
				}
			}
		}
		else if (obj[struct_index].cp == ".") {
			struct_index++;
			if (obj[struct_index].cp == "ID") {
				struct_index++;
				if (F3())
					return true;
			}
		}
		else if (obj[struct_index].cp == "INCDEC") {
			struct_index++;
			return true;
		}
	}
	else if (obj[struct_index].cp == "DIVMUL" || obj[struct_index].cp == "*" || obj[struct_index].cp == "ADDSUB" || obj[struct_index].cp == "REL_OP" ||
		obj[struct_index].cp == "LOG_OP" || obj[struct_index].cp == "]" || obj[struct_index].cp == "," || obj[struct_index].cp == ";" ||
		obj[struct_index].cp == ")" || obj[struct_index].cp == "}" || obj[struct_index].cp == "Extraction") {
		return true;
	}
	return false;
}


bool ptrinc() {
	if (obj[struct_index].cp == "INCDEC") {
		struct_index++;
		return true;
	}
	else if (obj[struct_index].cp == "DIVMUL" || obj[struct_index].cp == "*" || obj[struct_index].cp == "ADDSUB" || obj[struct_index].cp == "REL_OP" ||
		obj[struct_index].cp == "LOG_OP" || obj[struct_index].cp == "]" || obj[struct_index].cp == "," || obj[struct_index].cp == ";" ||
		obj[struct_index].cp == ")" || obj[struct_index].cp == "}" || obj[struct_index].cp == "Extraction") {
		return true;
	}
	return false;
}


bool INC() {
	if (obj[struct_index].cp == "*") {
		struct_index++;
		if (m_ast()) {
			if (obj[struct_index].cp == "ID") {
				struct_index++;
				return true;
			}
		}
	}
	else if (obj[struct_index].cp == "ID") {
		struct_index++;
		if (INC1())
			return true;
	}
	return false;
}


bool INC1() {
	if (obj[struct_index].cp == "[") {
		struct_index++;
		if (A()) {
			if (obj[struct_index].cp == "]") {
				struct_index++;
				if (m_dim())
					return true;
			}
		}
	}
	else if (obj[struct_index].cp == "DIVMUL" || obj[struct_index].cp == "*" || obj[struct_index].cp == "ADDSUB" || obj[struct_index].cp == "REL_OP" ||
		obj[struct_index].cp == "LOG_OP" || obj[struct_index].cp == "]" || obj[struct_index].cp == "," || obj[struct_index].cp == ";" ||
		obj[struct_index].cp == ")" || obj[struct_index].cp == "}" || obj[struct_index].cp == "Extraction") {
		return true;
	}
	return false;
}


bool F2() {
	if (obj[struct_index].cp == "INCDEC" || obj[struct_index].cp == ".") {
		if (obj[struct_index].cp == "INCDEC") {
			struct_index++;
			return true;
		}
		else if (obj[struct_index].cp == ".") {
			struct_index++;
			if (obj[struct_index].cp == "ID") {
				struct_index++;
				if (F3())
					return true;
			}
		}
	}
	else if (obj[struct_index].cp == "DIVMUL" || obj[struct_index].cp == "*" || obj[struct_index].cp == "ADDSUB" || obj[struct_index].cp == "REL_OP" ||
		obj[struct_index].cp == "LOG_OP" || obj[struct_index].cp == "]" || obj[struct_index].cp == "," || obj[struct_index].cp == ";" ||
		obj[struct_index].cp == ")" || obj[struct_index].cp == "}" || obj[struct_index].cp == "Extraction") {
		return true;
	}
	return false;
}


bool F3() {
	if (obj[struct_index].cp == "(" || obj[struct_index].cp == "[") {
		if (obj[struct_index].cp == "[") {
			struct_index++;
			if (A()) {
				if (obj[struct_index].cp == "]") {
					struct_index++;
					if (m_dim())
						return true;
				}
			}
		}
		else if (obj[struct_index].cp == "(") {
			struct_index++;
			if (argscall()) {
				if (obj[struct_index].cp == ")") {
					struct_index++;
					return true;
				}
			}
		}
	}
	else if (obj[struct_index].cp == "DIVMUL" || obj[struct_index].cp == "*" || obj[struct_index].cp == "ADDSUB" || obj[struct_index].cp == "REL_OP" ||
		obj[struct_index].cp == "LOG_OP" || obj[struct_index].cp == "]" || obj[struct_index].cp == "," || obj[struct_index].cp == ";" ||
		obj[struct_index].cp == ")" || obj[struct_index].cp == "}" || obj[struct_index].cp == "Extraction") {
		return true;
	}
	return false;
}


/********************End of Expression********************/


bool argscall() {
	if (A()) {
		if (margscall())
			return true;
	}
	else if (obj[struct_index].cp == ")")
		return true;
	return false;
}


bool margscall() {
	if (obj[struct_index].cp == ",") {
		struct_index++;
		if (A()) {
			if (margscall())
				return true;
		}
	}
	else if (obj[struct_index].cp == ")")
		return true;
	return false;
}


bool func_def() {
	if (type()) {
		if (ID1()) {
			if (obj[struct_index].cp == "(") {
				struct_index++;
				if (argsdef()) {
					if (obj[struct_index].cp == ")") {
						struct_index++;
						if (obj[struct_index].cp == "{") {
							struct_index++;
							if (m_st()) {
								if (obj[struct_index].cp == "}") {
										struct_index++;
										return true;
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}


bool argsdef() {				//Arg1
	if (obj[struct_index].cp == "Kirdar" || obj[struct_index].cp == "DT") {
		if (obj[struct_index].cp == "DT") {
			struct_index++;
			if (argsdef1())
				return true;
		}
		else if (obj[struct_index].cp == "Kirdar") {
			struct_index++;
			return true;
		}
	}
	else if (obj[struct_index].cp == ")")
		return true;
	return false;
}


bool argsdef1() {			//Arg2
	if(obj[struct_index].cp == "*") {
		struct_index++;
		if(m_ast()){
			if (obj[struct_index].cp == "ID") {
				struct_index++;
				if (margsdef())
					return true;
			}
		}
	}else if (obj[struct_index].cp == "ID") {
			struct_index++;
			if (argsdef2()) {
				if (margsdef())
					return true;
			}else if (margsdef())
				return true;
	}
	else if (obj[struct_index].cp == ")")
		return true;
	return false;
}


bool argsdef2() {			//Arg3
	if (obj[struct_index].cp == "[") {
		struct_index++;
		if (A()) {
			if (obj[struct_index].cp == "]") {
				struct_index++;
				if (m_dim())
					return true;
			}
		}
	}
	else if (obj[struct_index].cp == "," || obj[struct_index].cp == ")")
		return true;
	return false;
}


bool margsdef() {			//multiple arguments
	if (obj[struct_index].cp == ",") {
		struct_index++;
		if (obj[struct_index].cp == "DT") {
			struct_index++;
			if (argsdef1())
				return true;
		}
	}
	else if (obj[struct_index].cp == ")")
		return true;
	return false;
}


bool func_decl() {
	if (type()) {
		if (ID1()) {
			if (obj[struct_index].cp == "(") {
				struct_index++;
				if (argsdecl()) {
					if (obj[struct_index].cp == ")") {
						struct_index++;
						if (obj[struct_index].cp == ";") {
							struct_index++;
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}


bool type() {
	if (obj[struct_index].cp == "Kirdar" || obj[struct_index].cp == "DT") {
		struct_index++;
		return true;
	}
	return false;
}


bool ID1() {
	if (obj[struct_index].cp == "ID") {
			struct_index++;
			return true;
	}else if(obj[struct_index].cp == "*") {
		struct_index++;
		if(m_ast()){
			if(obj[struct_index].cp == "ID") {
				struct_index++;
				return true;
			}
		}
	}
	return false;
}


bool argsdecl() {
	if (obj[struct_index].cp == "Kirdar" || obj[struct_index].cp == "DT") {
		if (obj[struct_index].cp == "DT") {
			struct_index++;
			if (O_id()){
				if(m_id())
				return true;
			}
		}
		else if (obj[struct_index].cp == "Kirdar") {
			struct_index++;
			return true;
		}
	}
	else if (obj[struct_index].cp == ")")
		return true;
	return false;
}


bool O_id() {
	if (obj[struct_index].cp == "ID") {
			struct_index++;
			if (argsdef2())
				return true;
	}
	else if(obj[struct_index].cp == "*") {
		struct_index++;
		if(m_ast()){
			if(obj[struct_index].cp == "ID") {
				struct_index++;
				return true;
			}
		}
	}
	else if (obj[struct_index].cp == "," || obj[struct_index].cp == ")")
		return true;
	return false;
}


bool m_id() {
	if (obj[struct_index].cp == ",") {
		struct_index++;
		if (obj[struct_index].cp == "DT") {
			struct_index++;
			if (O_id()) {
				if (m_id())
					return true;
			}
		}
	}
	else if (obj[struct_index].cp == ")")
		return true;
	return false;
}


//bool struct_st() {
//	if (obj[struct_index].cp == "struct") {
//		struct_index++;
//		if (obj[struct_index].cp == "ID") {
//			struct_index++;
//			if (struct_body()) {
//				if (objst()) {
//					if (obj[struct_index].cp == ";") {
//						struct_index++;
//						return true;
//					}
//				}
//			}
//		}
//	}
//	return false;
//}
//
//
//bool struct_body() {
//	if (obj[struct_index].cp == "{") {
//		struct_index++;
//		if (members()) {
//			if (obj[struct_index].cp == "}") {
//				struct_index++;
//				return true;
//			}
//		}
//	}
//	return false;
//}


bool members() {
	if (obj[struct_index].cp == "struct" || obj[struct_index].cp == "DT" || obj[struct_index].cp == "Kirdar") {
		if (obj[struct_index].cp == "struct") {
			struct_index++;
			if (obj[struct_index].cp == "ID") {
				struct_index++;
				if(obj[struct_index].cp == "*"){
					struct_index++;
					if (m_ast()) {
						if (obj[struct_index].cp == "ID") {
							struct_index++;
							if (init()) {
								if (m_st_obj()) {
									if (members())
										return true;
								}
							}
						}
					}
				}
			}
		}
		else if (obj[struct_index].cp == "DT") {
			struct_index++;
			if (Alif1())
				return true;
		}
		else if (obj[struct_index].cp == "Kirdar") {
			struct_index++;
			if (kirdar1())
				return true;
		}
	}
	else if (obj[struct_index].cp == "}")
		return true;
	return false;
}


bool kirdar1() {
	if (obj[struct_index].cp == "ID" || obj[struct_index].cp == "*") {
		if (obj[struct_index].cp == "ID") {
			struct_index++;
			if (funcinstr())
				return true;
		}
		else if (obj[struct_index].cp == "*") {
			struct_index++;
			if (m_ast()) {
				if (obj[struct_index].cp == "ID") {
					struct_index++;
					if (funcinstr())
						return true;
				}
			}
		}
	}
	return false;
}


bool funcinstr() {
	if (obj[struct_index].cp == "(") {
		struct_index++;
		if (argsdef()) {
			if (obj[struct_index].cp == ")") {
				struct_index++;
				if (obj[struct_index].cp == "{") {
					struct_index++;
					if (m_st()) {
						if (obj[struct_index].cp == "}") {
								struct_index++;
								if (members())
									return true;
						}
					}
				}
			}
		}
	}
	return false;
}


bool Alif1() {
	if (obj[struct_index].cp == "ID" || obj[struct_index].cp == "*") {
		if (obj[struct_index].cp == "ID") {
			struct_index++;
			if (Alifvar())
				return true;
		}
		else if (obj[struct_index].cp == "*") {
			struct_index++;
			if (m_ast()) {
				if (obj[struct_index].cp == "ID") {
					struct_index++;
					if (Alifstr())
						return true;
				}
			}
		}
	}
	return false;
}


bool Alifstr() {
	if (obj[struct_index].cp == "(" || obj[struct_index].cp == "=" || obj[struct_index].cp == "," || obj[struct_index].cp == ";") {
		if (funcinstr()) {
			return true;
		}
		else if (init()) {
			if (list()) {
				if (members())
					return true;
			}
		}
	}
	return false;
}


bool Alifvar() {
	if (obj[struct_index].cp == "(" || obj[struct_index].cp == "[" || obj[struct_index].cp == "=" || obj[struct_index].cp == "," || obj[struct_index].cp == ";") {
		if (funcinstr()) {
			return true;
		}
		else if (init()) {
			if (list()) {
				if (members())
					return true;
			}
		}
		else if (obj[struct_index].cp == "[") {
			struct_index++;
			if (decl3()) {
				if (members())
					return true;
			}
		}
	}
	return false;
}


bool m_st_obj() {
	if (obj[struct_index].cp == "," || obj[struct_index].cp == ";") {
		if (obj[struct_index].cp == ",") {
			struct_index++;
			if (obj[struct_index].cp == "*") {
				struct_index++;
				if (m_ast()) {
					if (obj[struct_index].cp == "ID") {
						struct_index++;
						if (init()) {
							if (m_st_obj())
								return true;
						}
					}
				}
			}
		}
		else if (obj[struct_index].cp == ";") {
			struct_index++;
			return true;
		}
	}
	return false;
}


bool objst() {
	if (obj[struct_index].cp == "ID") {
		if (obj[struct_index].cp == "ID") {
			struct_index++;
			if (obj1())
				return true;
		}
	}else if(obj[struct_index].cp == "*"){
		struct_index++;
		if(m_ast()){
			if (m_obj())
				return true;
		}
	}
	else if (obj[struct_index].cp == ";")
		return true;
	return false;
}


bool obj1() {
	if (obj[struct_index].cp == "[") {
		struct_index++;
		if (A()) {
			if (obj[struct_index].cp == "]") {
				struct_index++;
				if (m_dim()) {
					if (m_obj())
						return true;
				}
			}
		}
	}
	else if (obj[struct_index].cp == "," || obj[struct_index].cp == ";") {
		if (m_obj())
			return true;
	}
	return false;
}


bool m_obj() {
	if (obj[struct_index].cp == ",") {
		struct_index++;
		if (mobj1())
			return true;
	}
	else if (obj[struct_index].cp == ";")
		return true;
	return false;
}


bool mobj1() {
	if (obj[struct_index].cp == "ID" || obj[struct_index].cp == "*") {
		if (obj[struct_index].cp == "ID") {
			struct_index++;
			if (obj1())
				return true;
		}
		else if (obj[struct_index].cp == "*") {
			struct_index++;
			if (m_ast()) {
				if (obj[struct_index].cp == "ID") {
					struct_index++;
					if (m_obj())
						return true;
				}
			}
		}
	}
	return false;
}


string comp(string type1, string type2, string o){
	if(type1=="float_const"){			//FLOAT
		if(type2=="float_const")
			return "float_const";
		else if(type2=="int_const")
			return "float_const";
		else if(type2=="bool_const")
			return "float_const";
		else if(type2=="char_const")
			return "float_const";
	}else if(type1=="int_const"){		//INT
		if(type2=="float_const")
			return "float_const";
		else if(type2=="int_const")
			return "int_const";
		else if(type2=="char_const")
			return "int_const";
		else if(type2=="bool_const")
			return "int_const";
	}else if(type1=="char_const"){		//CHAR
		if(type2=="float_const")
			return "float_const";
		else if(type2=="int_const")
			return "int_const";
		else if(type2=="char_const")
			return "int_const";
		else if(type2=="bool_const")
			return "int_const";
	}else if(type1=="string_const"){	//STRING
		if(type2=="string_const")
			return "string_const";
	}else if(type1=="bool_const"){		//BOOL
		if(type2=="float_const")
			return "float_const";
		else if(type2=="int_const")
			return "int_const";
		else if(type2=="char_const")
			return "int_const";
		else if(type2=="bool_const")
			return "int_const";
	}
	return "Data Type MisMatch.";
}


//cout<<"\n\nagya\n\nNEXT INDEX IS "<<obj[struct_index].cp;system("Pause");


bool lookup(string nam, int sc){
	for(look=0;look<sem_index;look++){ 
		if(nam == objs[look].name){
			for(int j=top;j>=0;j--){
				if(objs[look].scope == starr[j])
					return true;
			}
		}
	}
	return false;
}


bool lookupdec(string nam, int sc){
	for(int i=0;i<=sem_index;i++)
		if(nam == objs[i].name && sc == objs[i].scope)
			return true;
	return false;
}


void insert(string namee, string typ, int scop){
	if(!(lookupdec(namee, scop))){
		objs[sem_index].name=namee;
		objs[sem_index].type=typ;
		objs[sem_index].scope=scop;
		sem_index++;
		cout<<"\n\n Variable "<<namee<<" Inserted in Scope "<<scop<<"\n\n";
	}else{
		cout<<"\n\n Variable ("<<namee<<") Already Declared in Scope "<<scop<<"\n\n";
	}
}


/*

void saveinstruct(string arr[1000]) {
	int t = 0, j = 0, a = 0;
	bool check = false;
	string input, temp = "";
	while (t < i) {
		input = arr[t];
		j = 0;
		while (j < input.size()) {

			if (check) {
				if (obj[struct_index].cp.empty()) {
					obj[struct_index].cp = temp;
					temp.clear();
				}
				else if (obj[struct_index].vp.empty() && !(obj[struct_index].cp.empty())) {
					obj[struct_index].vp = temp;
					temp.clear();
				}
				else if (obj[struct_index].line.empty() && !(obj[struct_index].cp.empty()) && !(obj[struct_index].vp.empty())) {
					obj[struct_index].line = temp;
					temp.clear();
					struct_index++;
				}
				check = false;
			}
			if (input[j] == '(') {
				if (input[j - 1] != '(') {
					if (input[j - 1] == ',' && input[j + 1] == ',') {
						temp += input[j];
						check = true;
						j++;
					}
					else {
						check = false;
						j++;
					}
				}
				else {
					temp += input[j];
					check = true;
					j++;
				}
			}
			else
				if (input[j] == ')') {
					if (input[j + 1] != ')') {
						if (input[j - 1] == '(' || input[j - 1] == ',') {
							temp += input[j];
							check = true;
							j++;
						}
						else {
							check = false;
							j++;
						}
					}
					else {
						temp += input[j];
						check = true;
						j++;
					}
				}
				else
					if (isalpha(input[j]) || isdigit(input[j]) || input[j] == '_') {
						temp += input[j];
						if (input[j + 1] == ',' || input[j + 1] == ')') {
							check = true;
						}
						else {
							check = false;
						}
						j++;
					}
					else
						if (input[j] == ',') {
							if (input[j - 1] != ',' && input[j + 1] != ',') {
								check = false;
								j++;
							}
							else if (input[j - 1] == ',' && input[j + 1] == ',') {
								if (input[j + 2] == ',') {
									check = false;
									j++;
								}
								else {
									temp += input[j];
									check = true;
									j++;
								}
							}
							else {
								if (!(obj[struct_index].vp.empty())) {
									check = false;
									j++;
								}
								else {
									temp += input[j];
									check = true;
									j++;
								}
							}
						}
						else {
							if(input[j] == '|'){
//								if(!(temp.empty())){
//									arr[j] = temp;
//									array2[arr2_index] = n+1;
//									arr2_index++;
//									temp.clear();
//									j++;
//								}
								temp = input[j];
								j++;
								while(input[j] != '|'){
									temp +=input[j];
									j++;
								}
								if(input[j] == '|'){
									if(temp.size()>1){
										temp += input[j];
										j++;
										check = true;
									}
								}
//										if(!(temp.empty())){
//											arr[j] = temp;
//											temp.clear();
//											array2[arr2_index] = n+1;
//											arr2_index++;
//											j++;
//										}
							}else

							if ((input[j] == '+' && input[j + 1] == '+') || (input[j] == '-' && input[j + 1] == '-') || (input[j] == '&' && input[j + 1] == '&')
								/*|| (input[j] == '|' && input[j + 1] == '|')/ || (input[j] == '=' && input[j + 1] == '=') || (input[j] == '+' && input[j + 1] == '=')
								|| (input[j] == '-' && input[j + 1] == '=') || (input[j] == '*' && input[j + 1] == '=') || (input[j] == '/' && input[j + 1] == '=')
								|| (input[j] == '%' && input[j + 1] == '=') || (input[j] == '>' && input[j + 1] == '=') || (input[j] == '<' && input[j + 1] == '=')
								|| (input[j] == '>' && input[j + 1] == '>') || (input[j] == '<' && input[j + 1] == '<') || (input[j] == '!' && input[j + 1] == '=')) {
								temp += input[j];
								j++;
								temp += input[j];
								j++;
								check = true;
							}
							else if ((input[j] == '+' && input[j + 1] != '+') || (input[j] == '-' && input[j + 1] != '-') || (input[j] == '&' && input[j + 1] != '&')
								|| (input[j] == '=' && input[j + 1] != '=') || (input[j] == '+' && input[j + 1] != '=')
								|| (input[j] == '-' && input[j + 1] != '=') || (input[j] == '*' && input[j + 1] != '=') || (input[j] == '/' && input[j + 1] != '=')
								|| (input[j] == '%' && input[j + 1] != '=') || (input[j] == '>' && input[j + 1] != '=') || (input[j] == '<' && input[j + 1] != '=')
								|| (input[j] == '>' && input[j + 1] != '>') || (input[j] == '<' && input[j + 1] != '<') || (input[j] == '!' && input[j + 1] != '=')) {
								temp += input[j];
								j++;
								check = true;
							}
							else if (input[j] == '\"') {
								temp = input[j];
								j++;
								while (input[j] != '\"') {
									temp += input[j];
									j++;
								}
								temp += input[j];
								j++;
								check = true;
							}
							else if (input[j] == '\'') {
								temp = input[j];
								j++;
								a = 0;
								if (input[j] == '\\') {
									temp = input[j];
									j++;
									while (a < 2) {
										temp += input[j];
										j++;
										a++;
									}
									check = true;
								}
								else {
									while (a < 2) {
										temp += input[j];
										j++;
										a++;
									}
									check = true;
								}
							}
							else {
								temp += input[j];
								j++;
								check = true;
							}
						}
		}
		t++;
	}
	cout << "\n\nsize of struct is " << struct_index << endl;
//	for (int i = 0; i < struct_index; i++)
//		cout << " \n\t " << obj[i].cp << "\t" << obj[i].vp << "\t" << obj[i].line;
}

*/

