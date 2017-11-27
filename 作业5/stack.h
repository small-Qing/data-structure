const int maxsize=100;
enum bool{false,true};
template<class T>
class stack{
	public:
		stack(){};
		virtual void push(const T& x)=0;
		virtual bool pop(T& x)=0;
		virtual bool gettop(T& x)const=0;
		virtual bool isempty()const =0;
		virtual bool isfull()const=0;
		virtual int getsize()const=0;
};
