#include<math.h>
#include<stack.h>
#include<iostream.h>
class calculator{
	public:
		calculator(int sz):s(sz);
		void run();
		void clear();
	private:
		stack<double>s;
		void addoperand(double val);
		bool get2operand(double& left,double& right);
		void dooper(char op);
};
void calculator::dooper(char op){
	double left,right,val;
	int res;
	res=get2operand(left,right);
	if(res==true){
		switch(op){
			case'+':val=left+right;s.push(val);break;
			case'-':val=left-right;s.push(val);break;
			case'*':val=left*right;s.push(val);break;
			case'/':if(right==0){
						cerr<<"divide by 0!\n";
						clear();
					}
					else {
						val=left/right;
						s.push(val);
					}
					break;
		}
		else clear();
	}
};

bool calculator::get2operand(double& l,double& r){
	if(s.isempty()==true){
		cerr<<"缺少右操作数！\n";return false;
	}
	s.pop(r);
	if(s.isempty()==true){
		cerr<<"缺少左操作数！\n";return false;
	}
	s.pop(l);
	return true;
};

void  calculator::run(){
	char ch;
	double newop;
	while(cin>>ch,ch!='#'){
		switch(ch){
			case'+':case'-':case'*':case'/':
				dooper(ch);break;
				default:cin.putback(ch);
				cin>>newop;
				addoperand(newop);
		}
	}
};

void calculator::clear(){
	s.makeempty()oppp;
};












