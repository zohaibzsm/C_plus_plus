#include <iostream>
#include <fstream>
#include <String>
using namespace std;

/*
                                 CC Project Urdu++
*/

void filing(string a[]);			//filing
bool checkassign(string a);			//check assign op
bool checkrel(string a);
int array1[1000],array2[1000];		//array 1 for line number
int arr_index=0,arr2_index=0;		
int str_siz=0;
int cnt=0,tmp=0;
int counter=1;
ofstream tokf("File4.txt");			//save in file var
string assgn_op[5] = {"+=","-=","*=","/=","%="};
string rel_op[6] = {"<",">","<=",">=","!=", "=="};
string key[21] = { "Agar", "Nhetou","Yatou","Jabtak", "Karo","Chakkar","Wapis","Sahi","Galat","Chalo","Tooto","Mamla","Tabdeel","Tehshuda","Markazi","Kirdar"
						,"Shuru","Akhir","struct","cin","cout"};
//keyword
// if=Agar else if=Nhetou else=Yatou while= Jabtak do=Karo for=Chakkar return=Wapis "Alif=variable" true=Sahi false=Galat continue=Chalo break=Tooto case=Mamla
//switch=Tabdeel Tehshuda=Default Markazi= main void=kirdar Shuru=start Akhir=end 


bool keywords(string input){
	bool l = false;
	for (int i = 0; i <= 20; i++){
		if (input == key[i]){
			l = true;
		}
	}
	return l;
}

//Check assign_operators
bool checkassign(string a){
	int c;
	for(c=0;c<5;c++)
		if(assgn_op[c] == a)
			return true;
	return false;	
}

//Check rel_operators
bool checkrel(string a){
	int c;
	for(c=0;c<6;c++)
		if(rel_op[c] == a)
			return true;
	return false;
}

//PTRidentifier tt
int ptridd(int CT, char ch, int arr[3][3])
{
	if (ch == '*')
	{
		return arr[CT][0];
	}
	else if ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
	{
		return arr[CT][1];
	}else if((ch >= '0' && ch <= '9')){
		return arr[CT][2];
	}
	else {
		return arr[CT][3];
	}
}

//PTRID func
bool ptrid(string input){
	bool l=false;
	int TT[3][3] = {{ 1, 3, 3}, {1, 2, 3}, {3, 2, 2}};
	int initial = 0;
	int final = 3;
	int CT = initial;
	int i = 0;
	while (input[i] != NULL)
	{
		CT = ptridd(CT, input[i], TT);
		i++;
	}
	if (CT == final)
	{
		l=true;
	}
	return l;
}

//DataType
bool dt(string input){
	bool l = false;
	string key="Alif";
		if (input == key){
			l = true;
		}
	return l;
}


//identifier tt
int idd(int CT, char ch, int arr[4][2])
{
	if (ch == '|')
	{
		return arr[CT][0];
	}
	else if ((ch >= '0' && ch <= '9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
	{
		return arr[CT][1];
	}
	else {
		return arr[CT][2];
	}
}

//ID func
bool id(string input){
	bool l=false;
	int TT[4][2] = {{ 1, 4}, { 4, 2 }, {3, 2 }, { 4, 4 }};
	int initial = 0;
	int final = 3;
	int CT = initial;
	int i = 0;
	while (input[i] != NULL)
	{
		CT = idd(CT, input[i], TT);
		i++;
	}
	if (CT == final)
	{
		l=true;
	}
	return l;
}
/*bool id(string input){
	bool l=false;
	int TT[5][3] = {{ 1, 4, 4}, { 4, 2, 4 }, {3, 2, 4 }, { 4, 4, 4 },{ 4, 4, 4 }};
	int initial = 0;
	int final = 3;
	int CT = initial;
	int i = 0;
	while (input[i] != NULL)
	{
		CT = idd(CT, input[i], TT);
		i++;
	}
	if (CT == final)
	{
		l=true;
	}
	return l;
}*/

//Character tt
int char_tt[6][5] = { { 1, 5, 5, 5, 5 }, { 5, 2, 5, 4, 2 }, { 3, 5, 5, 5, 5 }, { 5, 5, 5, 5, 5 }, { 2, 2, 2, 2, 5 }, { 5, 5, 5, 5, 5 } };
int char_func(int cstate, char c, int tt[6][5])
{
	char sp[2] = { '\?', '\"' };
	char es[5] = { 'n', 't', 'r', 'b', 'f' };
	bool  e_s = false;

	if (c == '\'')
	{
		return tt[cstate][0];
	}

	else if (c == '\\')
	{
		return tt[cstate][3];
	}

	else if (c == sp[0] || c == sp[1])
	{
		return tt[cstate][2];
	}
	else
	{

		for (int i = 0; i<sizeof(es); i++)
		{
			if (c == es[i])
			{
				e_s = true;
				break;
			}
		}
	}

	if (e_s == true)
	{
		return tt[cstate][1];
	}
	else
	{
		return tt[cstate][4];
	}
}
//Char func
bool charr(string input){
	bool l = false;
	int initial = 0;
	int final = 3;
	int cstate = initial;
	int i = 0;
	while (input[i] != NULL){
		cstate = char_func(cstate, input[i], char_tt);
		i++;
	}
	if (cstate == final){
		l = true;
	}
	return l;
}
//String tt
int string_func(int cstate, char c, int tt[6][4]){
	char sp[3] = { '\'', '\\', '\"' };
	char es[5] = { 'n', 't', 'r', 'b', 'f' };

	/*if (cstate == 0)
	{
		if (c == '\"')
			return tt[cstate][0];
	}
	if (cstate == 1)
	{
		if (c == '\"'){
			return tt[cstate][0];
		}
		if (c != sp[0] || c != sp[1] || c != sp[2]){

			return tt[cstate][1];
		}
		else if (c == sp[1])
		{
			return tt[cstate][3];
		}

	}
	if (cstate == 2)
	{
		if (c == '\"'){
			return tt[cstate][0];
		}
		if (c != sp[0] || c != sp[1] || c != sp[2]){
			return tt[cstate][1];
		}
		if (c == sp[1]){
			return tt[cstate][3];
		}
	}


	if (cstate == 4)
	{

		if (c == sp[1] || c == sp[2] || c == es[0] || c == es[1] || c == es[2] || c == es[3] || c == es[4] || c == es[5])
		{

			return tt[cstate][2];
		}
		else if (c == '\"'){
			return tt[cstate][0];
		}
		else if (c == sp[1]){
			return tt[cstate][3];
		}
		else if(c != sp[1] || c != sp[2] || c != es[0] || c != es[1] || c != es[2] || c != es[3] || c != es[4] || c != es[5])
		{
		return tt[cstate][1];	
		}
	}*/
	if(cstate==0)
	{
	if(c=='\"')
		{
			return tt[cstate][0];
		}
		else if(c!='\"')
		{
			return tt[cstate][1];
		}
	}
	if(cstate==1)
	{
		if(c=='\"')
		{
			return tt[cstate][0];
		}
		
		else if(c==sp[1])
		{
		return tt[cstate][3];	
		}
		else if(c!=sp[0]||c!=sp[1]||c!=sp[2])
		{
			
			return tt[cstate][1];
		}
	}
	if(cstate==2)
	{
			if(c=='\"')
		{
			return tt[cstate][0];
		}
		else if(c==sp[0]||c==sp[2])
		{
			return tt[cstate][2];
		}
		else if(c==sp[1])
		{
		return tt[cstate][3];	
		}
		else if(c!=sp[0]||c!=sp[1]||c!=sp[2])
		{
			
			return tt[cstate][1];
		}
	}
	if(cstate==3)
	{
		return tt[cstate][0];	
	}
	if(cstate==4)
	{
		if(c=='\"')
		{
			return tt[cstate][0];
		}
		else if(c==sp[0]||c==es[2]||c==es[0]||c==es[1]||c==es[2]||c==es[3]||c==es[4])
		{
			return tt[cstate][2];
		}
		else if(c==sp[1])
		{
			return tt[cstate][3];
		}
		
			else if(c!=sp[0]||c!=sp[1]||c!=sp[2]||c!=es[0]||c!=es[1]||c!=es[2]||c!=es[3]||c!=es[4])
		{
			
			return tt[cstate][1];
		}		
	}
	if(cstate==5)
	{
	return tt[cstate][0];	
	}

}
//Sting func
bool stringgg(string input){
	int tt[6][4] = { { 1, 5, 5, 5 }, { 3, 2, 5, 4 }, { 3, 1, 5, 4 }, { 5, 5, 5, 5 }, { 2, 5, 2, 2 }, { 5, 5, 5, 5 } };
	bool l = false;
	int initial = 0;
	int final = 3;
	int cstate = initial;
	int i = 0;
	while (input[i] != NULL){
		cstate = string_func(cstate, input[i], tt);
		i++;
	}
	if (cstate == final){
		l = true;
	}
	return l;

}
//punctuators	
bool punc(string input){
	bool l = false;
	string pun[12] = { "(", ")", "[", "]", "{", "}", ",", ":", ".",";"};
	for (int i = 0; i <= 11; i++){
		if (input == pun[i]){
			l = true;
		}
	}
	return l;

}
//Integer tt
int int_func(int cstate, char c, int tt[4][3]){

	if (c == '+' || c == '-')
	{
		return tt[cstate][0];
	}
	else if (c >= '0' && c <= '9')
	{
		return tt[cstate][1];
	}
	else
	{
		return tt[cstate][2];
	}

}

//Integer func
bool integer(string input){
	bool l = false;
	int tt[4][3] = { { 1, 2, 3 }, { 3, 2, 3 }, { 3, 2, 3 }, { 3, 3, 3 } };
	int initial = 0;
	int final = 2;
	int cstate = initial;
	int i = 0;
	while (input[i] != NULL){
		cstate = int_func(cstate, input[i], tt);
		i++;
	}
	if (cstate == final){
		l = true;
	}
	return l;
}
//float tt
int float_func(int cstate, char c, int tt[5][4]){

	if (c == '+' || c == '-')
	{
		return tt[cstate][0];
	}
	else if (c >= '0' && c <= '9')
	{
		return tt[cstate][1];
	}
	else if (c == '.')
	{

		return tt[cstate][2];
	}
	else if (c >= '0' && c <= '9')
	{

		return tt[cstate][3];
	}
	else{
		return tt[cstate][4];
	}

}
//float func
bool floatt(string input){
	bool l = false;
	int tt[5][4] = { { 1, 1, 2, 4 }, { 4, 1, 2, 4 }, { 4, 3, 4, 4 }, { 4, 3, 4, 4 }, { 4, 4, 4, 4 } };
	int initial = 0;
	int final = 3;
	int cstate = initial;
	int i = 0;
	while (input[i] != NULL){
		cstate = float_func(cstate, input[i], tt);
		i++;
	}
	if (cstate == final){
		l = true;
	}
	return l;

}
//Arithmatic
//+ and - not included due to unary and assign opt
bool arith(string input){
	bool l = false;
	string ar[3] = { "*","/","%" };
	for (int i = 0; i <= 2; i++){
		if (input == ar[i])
			l = true;
	}
	return l;
}

//Token Generation

void tokens(string arra[1000])
{
	
	cout<<"                                           CC Project Urdu ++\n";
	cout<<":::::::::::::::::::::::::::::::::::::::::::::. LEXICAL .::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout<<endl;
	cout<<":::::::::::::::::::::::::::::::::::::::::::::. TOKENS .:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	string arr[1000];
	int n=0, j = 0;
	int i = 0, count = 0, w=0;
	string temp,last;
	temp.clear();	
	string input;
	bool check = false, comment = true, sngl = false;
	while(n<str_siz){
		input = arra[n];
	i=0;

	while (i<input.length())
	{
		check = false;
		if(!comment){
			while(((input[i] != '^' && input[i+1] != '^') || (input[i] == '^' && input[i+1] != '^') || (input[i] != '^' && input[i+1] == '^')) && input[i] != '\0' && i < input.length()){
					i++;
			}
			if(input[i] == '^' && input[i+1] == '^'){
				i++;
				i++;
				comment = true;
			}
			else if(((input[i] != '^' && input[i+1] != '^') || (input[i] == '^' && input[i+1] != '^') || (input[i] != '^' && input[i+1] == '^')) && (i == input.length() || input[i] == '\0')){
				comment = false;
				i++;
				break;
			}
		}
		if (i == input.length()){
				break;
		}

		while (input[i] != ' ' && input[i] != '(' && input[i] != ')' && input[i] != '[' && input[i] != ']' && input[i] != '{' && input[i] != '}' &&
			   input[i] != ',' && input[i] != ';' && input[i] != ':' && input[i] != '`' && input[i] != '#' && input[i] != '~' && input[i] != '@' && 
			   input[i] != '$' && input[i] != '\\' && input[i] != '?' && input[i] != '\t')
		{
			if (i == input.length()){
				if(!(temp.empty())){
					arr[j] = temp;
					array2[arr2_index] = n+1;
					arr2_index++;
					temp.clear();
					j++;
				}
				break;
			}
//			if(input[i] == '*'){
//				last = input[i-1];
//				if(!(temp.empty())){
//						arr[j] = temp;
//						array2[arr2_index] = n+1;
//						arr2_index++;
//						temp.clear();
//						j++;
//				}
//				if(input[i+1] == '='){
//						temp += input[i];
//						temp += input[i+1];
//						i++;			
//						arr[j] = temp;
//						array2[arr2_index] = n+1;
//						arr2_index++;
//						temp.clear();
//						i++;
//						j++;
//				}else if(((isdigit(last[0])) || (last[0] == '|' && input[i-1] == '|'))){
//						temp = input[i];
//						sngl = true;					
////					while(input[i] == '*'){
////						temp += input[i];
////						i++;
////					}
//				}else if((!(isdigit(last[0]))) && (last[0] != '|' && input[i-1] != '|') && ((input[i+1] == '*') || isalpha(input[i+1]))){
//						temp = input[i];
//						i++;
//					while(input[i] == '*'){
//						temp += input[i];
//						i++;
//					}
//					if(isalpha(input[i])){
//						temp += input[i];
//						i++;
//						while(isalpha(input[i]) || isdigit(input[i])){
//							temp += input[i];
//							i++;
//							if(input[i] == ' ')
//								break;
//						}
//					}	
//				}else if(input[i+1] != '='){
//						temp = input[i];
//						i++;
//						arr[j] = temp;
//						array2[arr2_index] = n+1;		
//						arr2_index++;
//						temp.clear();
//						j++;
//				}
//			}
			if(input[i] == '|'){
				if(!(temp.empty())){
					arr[j] = temp;
					array2[arr2_index] = n+1;
					arr2_index++;
					temp.clear();
					j++;
				}
				temp = input[i];
				i++;
				while(input[i] != '|' && input[i+1] != '\0' && i <= input.length()){
					temp +=input[i];
					i++;
				}
				if(input[i] == '|'){
					if(temp.size()>1){
						temp += input[i];
						sngl = true;
					}else{
						if(!(temp.empty())){
							arr[j] = temp;
							temp.clear();
							array2[arr2_index] = n+1;
							arr2_index++;
							j++;
						}
						i--;
						sngl = true;
					}
				}else if(i <= input.length()){
						sngl = false;
				}else if(i > input.length() || input[i] == '\0' || input[i] == NULL){
					sngl = false;
				}
			}
			if(input[i]=='\"'){
				if(!(temp.empty())){
					arr[j] = temp;
					temp.clear();
					array2[arr2_index] = n+1;
					arr2_index++;
					j++;
				}
				temp = input[i];
				i++;
				while(input[i] != '\"' && input[i] != '\0' && i <= input.length()){
				//	char i2=input[i];
				//	temp+=i2;
				//	i2=NULL;
					temp += input[i];
					i++;
					if(input[i] == NULL || input[i] == '\0')
						break;
				}
				if (i > input.length() || input[i] == '\0' || input[i] == NULL){
					if(!(temp.empty())){
						arr[j] = temp;
						temp.clear();
						array2[arr2_index] = n+1;
						arr2_index++;
						j++;
					}
					break;
				}else if(input[i] == '\"'){
					temp += input[i];
					arr[j] = temp;
					temp.clear();
					array2[arr2_index] = n+1;
					arr2_index++;
					j++;
					sngl = true;
				}else{
					sngl = true;
				}
			}
		
		
											
		//char constant
		
		if(input[i] == '\''){
			if(!(temp.empty())){
				arr[j] = temp;
				temp.clear();
				array2[arr2_index] = n+1;
				arr2_index++;
				j++;
			}
			temp = input[i];
			i++;
			w=0;
			if(i <= input.length() && input[i] != '\0'){
				if(input[i] == '\\'){
				sngl = true;	
				temp += input[i];
				i++;
				while(w<2 && i <= input.length() && input[i] != '\0'){
						temp += input[i];
						i++;
						w++;
				}
				if(w == 2){
					arr[j] = temp;
					temp.clear();
					array2[arr2_index] = n+1;
					arr2_index++;
					j++;
					i--;
				}
				else if((i > input.length() || input[i] == '\0') && w != 2)
					sngl = false;
			}else{
					while(w<2 && i <= input.length() && input[i] != '\0'){
						temp += input[i];
						i++;
						w++;	
					}
					if(w == 2){
						arr[j] = temp;
						temp.clear();
						array2[arr2_index] = n+1;
						arr2_index++;
						j++;
						i--;
						sngl = true;
					}
					else if((i > input.length() || input[i] == '\0') && w != 2)
						sngl = false;
				}	
			}else{
				sngl = false;
			}
			if(!sngl){
				if(!(temp.empty())){
							arr[j] = temp;
							temp.clear();
							array2[arr2_index] = n+1;
							arr2_index++;
							j++;
							i--;
							sngl = true;
				}
			}else if (i > input.length() || input[i] == '\0'){
						if(!(temp.empty())){
							arr[j] = temp;
							temp.clear();
							array2[arr2_index] = n+1;
							arr2_index++;
							j++;
						}
				break;
			}	
		}
			
		// dot
		if(input[i] == '.')
		{
			if(isalpha(temp[0]) || temp[0] == '|')
			{
					arr[j] = temp;
					array2[arr2_index] = n+1;
					arr2_index++;
					temp.clear();
					j++;
					//temp = input[i];
			}
			else if(isdigit(temp[0]) && !isdigit(input[i+1]))
			{
					arr[j] = temp;
					array2[arr2_index] = n+1;
					arr2_index++;
					temp.clear();
					j++;
			}else if(!(isdigit(temp[0])) && !isdigit(input[i+1])){
				
				if(!(temp.empty())){
					arr[j] = temp;
					array2[arr2_index] = n+1;
					arr2_index++;
					temp.clear();
					j++;
				}
				//temp = input[i];
			}
			//	temp += input[i];
			
			
		}else if((isalpha(input[i]) || temp[0] == '|' || input[i] == '|') && input[i-1] == '.')
		{
			arr[j] = temp;
			array2[arr2_index] = n+1;
			arr2_index++;
			temp.clear();
			j++;
		}
		
		
		
		 if((input[i] == '+' && input[i+1] == '+') || (input[i] == '-' && input[i+1] == '-') || (input[i] == '=' && input[i+1] == '=') 
		 || (input[i] == '+' && input[i+1] == '=') || (input[i] == '-' && input[i+1] == '=') || (input[i] == '!' && input[i+1] == '=')
		 || (input[i] == '/' && input[i+1] == '=') || (input[i] == '%' && input[i+1] == '=') || (input[i] == '>' && input[i+1] == '=') 
		 || (input[i] == '<' && input[i+1] == '=') || (input[i] == '>' && input[i+1] == '>') || (input[i] == '<' && input[i+1] == '<')
		 || (input[i] == '*' && input[i+1] == '=')){
					if(!(temp.empty())){
						arr[j] = temp;
						array2[arr2_index] = n+1;
						arr2_index++;
						temp.clear();
						j++;
					}
				temp += input[i];
				temp += input[i+1];
				i++;			
				arr[j] = temp;
				array2[arr2_index] = n+1;
				arr2_index++;
				temp.clear();
				i++;
				j++;
		}else
			
		if((input[i] == '+' && input[i+1] != '+') || (input[i] == '-' && input[i+1] != '-') || (input[i] == '=' && input[i+1] != '=') 
		|| (input[i] == '+' && input[i+1] != '=') || (input[i] == '-' && input[i+1] != '=') || (input[i] == '!' && input[i+1] != '=')
		|| (input[i] == '/' && input[i+1] != '=') || (input[i] == '%' && input[i+1] != '=') || (input[i] == '>' && input[i+1] != '=') 
		|| (input[i] == '<' && input[i+1] != '=') || (input[i] == '>' && input[i+1] != '>') || (input[i] == '<' && input[i+1] != '<')
		|| (input[i] == '*' && input[i+1] != '=') )
		{
			if(!(temp.empty())){
				arr[j] = temp;
				array2[arr2_index] = n+1;
				arr2_index++;
				temp.clear();
				j++;
			}
			temp = input[i];
			i++;
			arr[j] = temp;
			array2[arr2_index] = n+1;		
			arr2_index++;
			temp.clear();
			j++;
		}else
		
		
			//Single line
			

			if(input[i] == '^' && input[i+1] != '^'){
				check = true;
				if(!(temp.empty())){
					arr[j] = temp;
					array2[arr2_index] = n+1;
					arr2_index++;
					temp.clear();
					j++;
				}
				i++;
				while(i < input.length()){
					i++;
				}
				if(i == input.length())
					break;
			}else
			
			//Multi line
			
			if(input[i] == '^' && input[i+1] == '^'){
				if(!(temp.empty())){
					arr[j] = temp;
					array2[arr2_index] = n+1;
					arr2_index++;
					temp.clear();
					j++;
				}
				i++;
				i++;
				while(((input[i] != '^' && input[i+1] != '^') || (input[i] == '^' && input[i+1] != '^') || (input[i] != '^' && input[i+1] == '^')) && input[i] != '\0' && i < input.length()){
					i++;
				}
				if(input[i] == '^' && input[i+1] == '^'){
					i++;
					i++;
					comment = true;
				}else if(((input[i] != '^' && input[i+1] != '^') || (input[i] == '^' && input[i+1] != '^') || (input[i] != '^' && input[i+1] == '^')) && (i == input.length() || input[i] == '\0')){
					comment = false;
					i++;
					break;
				}
			}
			
			else{
				if(sngl){
					i++;
					sngl = false;
				}else{
					temp += input[i];
					i++;
				}
			}
		}
		if((i == input.length() && check) || (i >= input.length()))	
			break;
			else
		
		if (!(temp.empty()))
		{
			arr[j] = temp;
			//cout<<"\nN is "<<n;
			array2[arr2_index] = n+1;
			arr2_index++;
			temp.clear();
			j++;
			count++;
		}

		if(input[i] != ' ')
		{
			arr[j] = input[i];
			array2[arr2_index] = n+1;
			arr2_index++;
			temp.clear();	
			i++;
			j++;
			count++;
		}
		else
		{
			i++;
		}	
		
	}
	n++;	
	}
	
/*	
	for(int a=0;a<arr2_index;a++){
			cout <<"\nValue at index " <<a<<" is "<<array2[a]<<endl;
		}
*/
	int indx=0;
	//testing
	
	for (int f = 0; f<j; f++)
	{
	
		cout<<"  "<<arr[f]+"\n";	
	}

	////////////////////////// displaying and writing token in file.  //////////////////////////
	
	for (int f = 0; f<j; f++){
		if (keywords(arr[f]) == true){
			cout << " " << arr[f] << " \t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf <<"("<< arr[f] << ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if( dt(arr[f])==true){
			cout << " DT\t\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(DT"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if (id(arr[f]) == true /*|| ptrid(arr[f]) == true*/){
			cout << " ID\t\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(ID"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if (charr(arr[f]) == true){
			cout << " char_const\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(char_const"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if (stringgg(arr[f]) == true){
			cout << " string_const\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(string_const"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if (punc(arr[f]) == true){
			cout << " " << arr[f]<<"\t\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf <<"("<< arr[f]<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if (integer(arr[f]) == true && floatt(arr[f]) == false){
			cout << " int_const\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(int_const"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if (integer(arr[f]) == false && floatt(arr[f]) == true){
			cout << " float_const\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(float_const"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if(checkassign(arr[f])){	
			cout << " ASSGN_OP\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(ASSGN_OP"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if(checkrel(arr[f])){
			cout << " REL_OP\t\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(REL_OP"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if((arr[f]=="Or") || (arr[f]=="Ya")){
			cout << " LOG_OP\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(LOG_OP"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if(arr[f]=="!"){
			cout << " !\t\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(!"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if(arr[f]=="++" || arr[f]=="--"){
			cout << " INCDEC\t\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(INCDEC"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if(arr[f]=="+" || arr[f]=="-"){
			cout << " ADDSUB\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(ADDSUB"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if(arr[f]=="/" ||arr[f]=="%"){
			cout << " DIVMUL\t\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(DIVMUL"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if(arr[f]=="*"){
			cout << " *\t\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(*"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if(arr[f]=="="){
			cout << " =\t\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(="<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if(arr[f]=="&"){
			cout << " &\t\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(&"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if(arr[f]=="<<"){	
			cout << " Extraction\t\t\t"<< arr[f]<<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(Extraction"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else if(arr[f]==">>"){	
			cout << " Insertion\t\t\t"<< arr[f]<<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(Insertion"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}else{
			cout << " Lexical Error\t\t\t"<< arr[f] <<"\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "(Lexical Error"<< ","<< arr[f] <<","<<array2[indx]<<")"<<"\n";
			indx++;
		}
	}
			cout << " $\t\t\t\t"<<"$\t\t\t\t"<<array2[indx]<<"\n";
			tokf << "$"<< ","<< "$" <<","<<array2[indx]<<"\n";
			indx++;
}

////////////////////////// FILING  //////////////////////////

void filing(string arry[1000]){
	
	ifstream input("File6.txt");
	if(!(input.is_open())){
		cout<<"Error opening in file.\n\n";
		exit(0);
	}else{
		
		string temp,temp1;
		while(getline (input,temp)){
			if(!input){
				break;
			}else{
				arry[str_siz] = temp;
				array1[arr_index] = counter;
				str_siz++;
				arr_index++;
				counter++;
				temp.clear();
			}
		}
		cout << "Countera value is " << counter;
		system("Pause");
	}
//	for (int i = 0;i < str_siz;i++){	cout <<"Index "<< i <<" is : "<<arry[i]<<endl;	cout <<"Line number of index "<< i <<" is : "<<array1[i]<<endl;	}
//	cout<<"Total Lines in files : "<<cnt<<endl;	
		tokens(arry);	
}


/// MAIN  ////////


int main()
{
	string arr[1000];
	filing(arr);
	//getdatafromfile();
	//if(start())
	//	cout<<"\n\nCorrect CFG. true";
	//else
	//	cout<<"\n\nInCorrect CFG. false";
}


